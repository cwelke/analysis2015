#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>

#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TH1F.h"
#include "TMath.h"

#include "Math/VectorUtil.h"

#include "templateLooper.h"

#include "../sharedCode/histTools.h"
#include "../sharedCode/ZMET.h"
#include "../sharedCode/METTemplateSelections.h"
#include "../sharedCode/AnalysisSelections.h"

#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"

using namespace std;
using namespace duplicate_removal;

const bool debug = false;

const bool usejson              = true;
const bool dovtxreweighting     = false;
const bool dotemplateprediction = false;
const bool dotemplatepredictionmc = true;

templateLooper::templateLooper()
{
};

templateLooper::~templateLooper()
{
};

void templateLooper::ScanChain ( TChain * chain , const string iter , const string sample, const string selection ){

  // if( zmet.isData() )        cout << "Running on Data."        << endl;
  // else                       cout << "Running on MC.  "        << endl;

  double nee = 0;
  double nmm = 0;
  double nll = 0;
  double nem = 0;

  double nem_2jets = 0;
  double nem_2jets_mll = 0;

  cout<<selection<<endl;
  
  bookHistos();

  double npass = 0;

  METTemplates mettemplates( selection );
  TH1F* currentMETTemplate = NULL;
  if( dotemplateprediction ){
	// mettemplates.loadTemplatesFromFile( Form("../output/%s/data_inclusive_templates.root", iter.c_str(), selection.c_str()), mettemplate_hists );
	mettemplates.loadTemplatesFromFile( Form("../output/%s/data%s_templates.root", iter.c_str(), selection.c_str()), mettemplate_hists );
	mettemplates.setBins( selection );
  }
  if( dotemplatepredictionmc ){
	// mettemplates.loadTemplatesFromFile( Form("../output/%s/data_inclusive_templates.root", iter.c_str(), selection.c_str()), mettemplate_hists );
	mettemplates.loadTemplatesFromFile( Form("../output/%s/All_MC%s_novtxweight_templates.root", iter.c_str(), selection.c_str()), mettemplate_hists );
	mettemplates.setBins( selection );
  }
  
  // do this once per job
  // const char* json_file = "../../json/json_270715_golden.txt";

  // const char* json_file = "json_25ns.txt";
  // const char* json_file = "json_25ns_remove.txt";
  const char* json_file = "../../json/json_golden_168pb_290915_sntformat.txt";
  // const char* json_file = "../../json/json_240915_DCSONLY_sntformat.txt";
		set_goodrun_file(json_file);

  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  TH1F * h_vtxweight = NULL;
  TFile * f_vtx = NULL;
  if( dovtxreweighting ){
	f_vtx = TFile::Open("nvtx_ratio.root","READ");
	h_vtxweight = (TH1F*)f_vtx->Get("h_vtx_ratio")->Clone("h_vtxweight");
	h_vtxweight->SetDirectory(rootdir);
	f_vtx->Close();
  }
  
  TObjArray *listOfFiles = chain->GetListOfFiles();
  unsigned int nEventsChain = 0;
  unsigned int nEvents = chain->GetEntries();
  nEventsChain = nEvents;
  unsigned int nEventsTotal = 0;
  unsigned int nDuplicates = 0;

  if(debug) cout << "Begin file loop" << endl;

  // file loop
  TIter fileIter(listOfFiles);
  TFile* currentFile = 0;
  while ( (currentFile = (TFile*) fileIter.Next()) ){

	TFile f(currentFile->GetTitle());
    TTree *tree = dynamic_cast<TTree*>(f.Get("t"));
    zmet.Init(tree);

    // event loop
    //unsigned int nEvents = tree->GetEntries();
    nEvents = tree->GetEntries();	
	cout<<"Processing File: "<<TString(currentFile->GetTitle())<<endl;

    for (unsigned int event = 0 ; event < nEvents; ++event){
   
	  zmet.GetEntry(event);
      ++nEventsTotal;

	  if (nEventsTotal % 1000 == 0){ // progress feedback to user
		if (isatty(1)){ // xterm magic from L. Vacavant and A. Cerri               
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", (float)nEventsTotal/(nEventsChain*0.01));
          fflush(stdout);
        }
      }

	  //~-~-~-~-~-~-~-~~-//
	  //Stitch DY samples//
	  //~-~-~-~-~-~-~-~-~//

	  
	  if( sample == "zjetsmlm" ){
	  	if( !TString(currentFile->GetTitle()).Contains("llht") ){
	  	  if( zmet.gen_ht()    > 100 ) continue;
	  	  // if( zmet.met_rawPt() > 100 ) continue;
	  	  // }else if( TString(currentFile->GetTitle()).Contains("dyjetsll") ){
	  	//   if( zmet.gen_ht() < 100 ) continue;
	  	}
	  }	

	  // if( zmet.isData() && !(zmet.run() == 251244 ||
	  // 						 zmet.run() == 251252 ||
	  // 						 zmet.run() == 251251) ) continue;

	  if ( zmet.isData() && usejson && !goodrun(zmet.run(), zmet.lumi()) ) continue;

	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//
	  //Deal with duplicates in data//
	  //-~-~-~-~-~-~-~-~-~-~-~-~-~-~//
	  if( zmet.isData() ) {
		DorkyEventIdentifier id(zmet.run(), zmet.evt(), zmet.lumi());
		if (is_duplicate(id) ){
		  ++nDuplicates;
		  continue;
		}
      }
	  
	  //~-~-~-~-~-~-~-~~-//
	  //trigger variables//
	  //~-~-~-~-~-~-~-~-~//

	  
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //Deal with event weights//
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  float weight = 1.0;
	  if( zmet.isData() ){
		weight = 1.0;
	  }else if( !zmet.isData() ){
		weight *= zmet.evt_scale1fb();
	  }
	  
	  if( !zmet.isData() && dovtxreweighting ){
		// cout<<h_vtxweight->GetBinContent(h_vtxweight->FindBin(zmet.nVert()));
		weight *= h_vtxweight->GetBinContent(h_vtxweight->FindBin(zmet.nVert()));		
		// weight *= h_vtxweight->GetBinContent(zmet.nVert());		
	  }

	  float event_met_pt = zmet.met_pt();
	  float event_met_ph = zmet.met_phi();


	  // if( selection == "_rawMET" ){
		event_met_pt = zmet.met_rawPt();
		event_met_ph = zmet.met_rawPhi();	  
	  // }
	  // else if( selection == "_rawMETNoHF" ){
	  // 	event_met_pt = zmet.met_rawNoHF_pt();
	  // 	event_met_ph = zmet.met_rawNoHF_phi();	  
	  // }
	  // else if( selection == "_T1MET" ){
	  // 	event_met_pt = zmet.met_T1CHS_fromCORE_pt();
	  // 	event_met_ph = zmet.met_T1CHS_fromCORE_phi();	  
	  // }
	  // else if( selection == "_METNoHF" ){
	  // 	event_met_pt = zmet.met_T1CHSNoHF_fromCORE_pt();
	  // 	event_met_ph = zmet.met_T1CHSNoHF_fromCORE_phi();	  
	  // }
	  // else{
	  // 	event_met_pt = zmet.met_pt();
	  // 	event_met_ph = zmet.met_phi();	  
	  // }

	  //~-~-~-~-~-~-~-~-//
      // event selection// 
	  //~-~-~-~-~-~-~-~-//
	  if( zmet.nlep()                        < 2         ) continue; // require at least 2 good leptons
	  if( zmet.lep_pt().at(0)                < 20        ) continue; // leading lep pT > 25 GeV
	  if( zmet.lep_pt().at(1)                < 20        ) continue; // tailing lep pT > 20 GeV

	  if( abs(zmet.lep_p4().at(0).eta())     > 2.4       ) continue; // eta < 2.4
	  if( abs(zmet.lep_p4().at(1).eta())     > 2.4       ) continue; // eta < 2.4
	  if( abs(zmet.lep_p4().at(0).eta())     > 1.4 &&
	  	  abs(zmet.lep_p4().at(0).eta())     < 1.6       ) continue; 
	  if( abs(zmet.lep_p4().at(1).eta())     > 1.4 &&
	  	  abs(zmet.lep_p4().at(1).eta())     < 1.6       ) continue; // veto xition region
	  if( zmet.dRll() < 0.1 ) continue;
	  // if( zmet.dilpt() < 25 ) continue;

	  // // for closure only
	  // if( zmet.njets() < 2   ) continue; // require at least 2 good leptons
      if( zmet.ht()    < 100 ) continue; // special selection for now
	  if( !passSignalRegionSelection(selection) ) continue;
	  
	  //~-~-~-~-~-~-~-~-//
      // event selection// 
	  //~-~-~-~-~-~-~-~-//
	  if( !(zmet.hyp_type() == 0 ||					     
			zmet.hyp_type() == 1 ||					     
			zmet.hyp_type() == 2 )                       ) continue; // require explicit dilepton event
	  if( !(zmet.evt_type() == 0 )                       ) continue; // require opposite sign
      if( !usejson && zmet.isData() && !zmet.evt_passgoodrunlist()   ) continue;
	  fillHist( "event", "mll"  , "inclusive", zmet.dilmass()  , weight );

	  if( (zmet.dilmass() > 81 && zmet.dilmass() < 101) ){ // HT > 100
		fillHist( "event", "nVert", "inclusive", zmet.nVert()  , weight );	  
	  }

      // if( isdata && !(templates.csc()==0 && 
	  // 				  templates.hbhe()==1 && 
	  // 				  templates.hcallaser()==1 && 
	  // 				  templates.ecallaser()==1 && 
	  // 				  templates.ecaltp()==1 && 
	  // 				  templates.trkfail()==1 && 
	  // 				  templates.eebadsc()==1 && 
	  // 				  templates.hbhenew()==1) )                             continue; // MET filters

	  // Flag_CSCTightHaloFilter
	  // Flag_HBHENoiseFilter

	  // if( zmet.isData() && !(zmet.HLT_DoubleMu() ||
	  // 						 zmet.HLT_DoubleEl() ||
	  // 						 zmet.HLT_DoubleEl_noiso() ||
	  // 						 zmet.HLT_MuEG())           ) continue;

	  if( !((( zmet.HLT_DoubleMu()    || zmet.HLT_DoubleMu_tk()   ) && zmet.hyp_type() == 1 )  ||
			(( zmet.HLT_DoubleEl_DZ() || zmet.HLT_DoubleEl_noiso()) && zmet.hyp_type() == 0 )  ||
			( zmet.HLT_MuEG() && zmet.hyp_type() == 2 )
			)           ) continue;

	  float rawmet_pt = zmet.met_rawPt();
	  // float rawmet_phi = zmet.met_rawPhi();

	  fillHist( "event", "mll"    , "passtrig" , zmet.dilmass()  , weight );
	  if( zmet.njets() > 1 ){
		if( zmet.hyp_type() == 2 ) nem_2jets += weight;	  
		fillHist( "event", "metgt1jet" , "inclusive", event_met_pt        , weight );
	  }

	  if( rawmet_pt > 50.0  ) fillHist( "event", "mll_metrawgt50"  , "passtrig", zmet.dilmass() , weight );
	  if( rawmet_pt > 100.0 ) fillHist( "event", "mll_metrawgt100" , "passtrig", zmet.dilmass() , weight );
	  if( rawmet_pt > 150.0 ) fillHist( "event", "mll_metrawgt150" , "passtrig", zmet.dilmass() , weight );
	  if( rawmet_pt > 225.0 ) fillHist( "event", "mll_metrawgt225" , "passtrig", zmet.dilmass() , weight );
	  if( rawmet_pt > 300.0 ) fillHist( "event", "mll_metrawgt300" , "passtrig", zmet.dilmass() , weight );
	  
	  if( !(zmet.dilmass() > 81 && zmet.dilmass() < 101) ) continue; // HT > 100
	  if( zmet.njets() > 1 ){
		if( zmet.hyp_type() == 2 ) nem_2jets_mll += weight;	  
	  }
	  
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//	  
	  fillHist( "event", "njets"  , "passtrig", zmet.njets()        , weight );
	  fillHist( "event", "nbjets" , "passtrig", zmet.nBJetMedium()  , weight );
	  fillHist( "event", "met"    , "passtrig", event_met_pt        , weight );
	  fillHist( "event", "met_raw", "passtrig", zmet.met_rawPt()    , weight );
	  fillHist( "event", "ht"     , "passtrig", zmet.ht()           , weight );
	  fillHist( "event", "ptl1"   , "passtrig", zmet.lep_pt().at(0) , weight );	  
	  fillHist( "event", "ptl2"   , "passtrig", zmet.lep_pt().at(1) , weight );	  
	  fillHist( "event", "nVert"  , "passtrig", zmet.nVert()        , weight );	  
	  fillHist( "event", "ptdil"  , "passtrig", zmet.dilpt()        , weight );	  
	  fillHist( "event", "metphi" , "passtrig", event_met_ph        , weight );	  
	  fillHist( "event", "metphir", "passtrig", zmet.met_rawPhi()   , weight );	  


	  fillHist( "event", "met_mettoolbox"        , "passtrig", zmet.met_T1CHS_pt()          , weight );	  
	  fillHist( "event", "met_mettoolboxNoHF"    , "passtrig", zmet.met_T1CHSNoHF_pt()      , weight );	  
	  fillHist( "event", "met_mettoolboxNoHFraw" , "passtrig", zmet.met_rawNoHF_pt()        , weight );	  
	  
	  fillHist( "event", "met_CORE"      , "passtrig", zmet.met_T1CHS_fromCORE_pt()     , weight );	  
	  fillHist( "event", "met3p0_CORE"   , "passtrig", zmet.met_T1CHSNoHF_fromCORE_pt() , weight );	  
	  fillHist( "event", "met3p0_raw"    , "passtrig", zmet.met_rawNoHF_pt()            , weight );	  
	  fillHist( "event", "met3p0_raw_phi", "passtrig", zmet.met_rawNoHF_phi()           , weight );	  

	  float dphi = acos(cos(zmet.lep_p4()[2].phi()-event_met_ph));
	  float mt = sqrt(2*event_met_pt*zmet.lep_pt()[2]*cos(dphi));
	  
	  fillHist( "event", "mt3", "passtrig", mt, weight );	  
	  
	  if( zmet.nlep() > 2 ){
	  	fillHist( "event", "mt3", "threelep", mt, weight );	  

		fillHist( "event", "njets"                 , "threelep", zmet.njets()        , weight );
		fillHist( "event", "nbjets"                , "threelep", zmet.nBJetMedium()  , weight );
		fillHist( "event", "met"                   , "threelep", event_met_pt        , weight );
		fillHist( "event", "met_raw"               , "threelep", zmet.met_rawPt()    , weight );
		fillHist( "event", "ht"                    , "threelep", zmet.ht()           , weight );
		fillHist( "event", "ptl1"                  , "threelep", zmet.lep_pt().at(0) , weight );	  
		fillHist( "event", "ptl2"                  , "threelep", zmet.lep_pt().at(1) , weight );	  
		fillHist( "event", "nVert"                 , "threelep", zmet.nVert()        , weight );	  
		fillHist( "event", "ptdil"                 , "threelep", zmet.dilpt()        , weight );	  
		fillHist( "event", "metphi"                , "threelep", event_met_ph        , weight );	  
		fillHist( "event", "metphir"               , "threelep", zmet.met_rawPhi()   , weight );	  
		fillHist( "event", "met_mettoolbox"        , "threelep", zmet.met_T1CHS_pt()          , weight );	  
		fillHist( "event", "met_mettoolboxNoHF"    , "threelep", zmet.met_T1CHSNoHF_pt()      , weight );	  
		fillHist( "event", "met_mettoolboxNoHFraw" , "threelep", zmet.met_rawNoHF_pt()        , weight );	  	  
		fillHist( "event", "met_CORE"              , "threelep", zmet.met_T1CHS_fromCORE_pt()     , weight );	  
		fillHist( "event", "met3p0_CORE"           , "threelep", zmet.met_T1CHSNoHF_fromCORE_pt() , weight );	  
		fillHist( "event", "met3p0_raw"            , "threelep", zmet.met_rawNoHF_pt()            , weight );	  
		fillHist( "event", "met3p0_raw_phi"        , "threelep", zmet.met_rawNoHF_phi()           , weight );	  

	  }
	  
	  if( event_met_pt < 50 && zmet.hyp_type() == 2 ) nem_2jets += weight;
		  
	  if( zmet.hyp_type() == 0 ) nee += weight;
	  if( zmet.hyp_type() == 1 ) nmm += weight;
	  if( zmet.hyp_type() == 2 ) nem += weight;	  
	  if( zmet.hyp_type() == 0 || zmet.hyp_type() == 1 ) nll += weight;

	  // if( zmet.phpfcands_30in_pt() > 0 ){	 
  	  // fillHist( "event", "phpfcands_30in_pt"  , "passtrig", zmet.phpfcands_30in_pt() , weight );	  
  	  // fillHist( "event", "phpfcands_30in_phi" , "passtrig", zmet.phpfcands_30in_phi(), weight );	  
	  // }
	  // if( zmet.nupfcands_30in_pt() > 0 ){	 
  	  // fillHist( "event", "nupfcands_30in_pt"  , "passtrig", zmet.nupfcands_30in_pt() , weight );	  
  	  // fillHist( "event", "nupfcands_30in_phi" , "passtrig", zmet.nupfcands_30in_phi(), weight );	  
	  // }

	  // if( zmet.njets() > 1 ) {
	  // 	fillHist( "event", "met_COREgt1jet"              , "passtrig", zmet.met_T1CHS_fromCORE_pt() , weight );	  
	  // 	fillHist( "event", "met_mettoolboxgt1jet"        , "passtrig", zmet.met_T1CHS_pt()          , weight );	  
	  // 	fillHist( "event", "met_mettoolboxNoHFgt1jet"    , "passtrig", zmet.met_T1CHSNoHF_pt()      , weight );	  
	  // 	fillHist( "event", "met_mettoolboxNoHFrawgt1jet" , "passtrig", zmet.met_rawNoHF_pt()        , weight );	  
	  // }
	  
	  
	  //-~-~-~-~-~-~-~-~-~-//
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  
	  if( zmet.njets()                        < 2         ) continue; // require at least 2 good jets
      npass += weight;

	  fillHist( "event", "ht_gt1j"       , "passtrig", zmet.ht()           , weight );
	  fillHist( "event", "met_rawgt1jet" , "passtrig", event_met_pt        , weight );	  

	  if( dotemplateprediction || dotemplatepredictionmc ){
		if( (zmet.hyp_type() == 0 || zmet.hyp_type() == 1 ) ){
		  currentMETTemplate = mettemplates.pickTemplate( mettemplate_hists, zmet.njets(), zmet.ht(), zmet.dilpt() );
		  mettemplates.countTemplate( zmet.njets(), zmet.ht(), zmet.dilpt(), weight );
		  try
			{
			  event_hists.at( "h_templ_met" ) -> Add( currentMETTemplate, weight );		
			}
		  catch(exception &e)
			{
			  cout<<"Hist: h_templ_met Does not exist!"<<endl;
			  exit(1);
			}
		}
	  }

    } // end loop over events
  } // end loop over files



  cout << npass       << " events passing selection" << endl;
  cout << nDuplicates << " duplicate events in data" << endl;
  cout << nee         << " ee events passing selection" << endl;
  cout << nmm         << " mm events passing selection" << endl;
  cout << nll         << " ll events passing selection" << endl;
  cout << nem         << " em events passing selection" << endl;

  cout<<"nemu 2 jets    : "<<nem_2jets<<endl;
  cout<<"nemu 2 jets mll: "<<nem_2jets_mll<<endl;
  cout<<"emu scale factor: "<<nem_2jets_mll/nem_2jets<<endl;

  // cout << "em events at low MET : "     << nem_2jets*10 << endl;
  
  // mettemplates.NormalizeTemplates(mettemplate_hists);
  mettemplates.correctBinUncertainty( mettemplate_hists, event_hists.at("h_templ_met") );

  
  if (nEventsChain != nEventsTotal)
    std::cout << "ERROR: number of events from files is not equal to total number of events" << std::endl;

  string vtxstring = "";
  if( !dovtxreweighting ) vtxstring = "_novtxweight";
  
  // make histos rootfile
  string outputfilename = 	Form("../output/%s/%s%s%s_hists.root",
								 iter.c_str(),
								 sample.c_str(),
								 selection.c_str(),
								 vtxstring.c_str()
								 );

  cout << "Writing output to " << outputfilename << endl;
  saveHist(outputfilename.c_str(),"*");
  
  // deleteHistos();
  
} // end ScanChain


void templateLooper::bookHistos(){

  // hist naming convention: "h_<leptype>_<object>_<variable>_<selection>"
  vector <string> leptype;
  leptype.push_back("ee");
  leptype.push_back("mm");
  leptype.push_back("em");
  leptype.push_back("ll");
  vector <string> object;
  object.push_back("event");
  // object.push_back("templ");
  // object.push_back("lep1");
  // object.push_back("lep2");
  // object.push_back("dilep");
  vector <string> selection;
  selection.push_back("inclusive");
  selection.push_back("passtrig");
  selection.push_back("threelep");

  vector <string> variable;      vector <float> variable_bins;

  variable.push_back("ptl1");    variable_bins.push_back(1000);  
  variable.push_back("ptl2");    variable_bins.push_back(1000);  
  variable.push_back("ptdil");   variable_bins.push_back(1000);  
  variable.push_back("met");     variable_bins.push_back(500 );  
  // variable.push_back("met_phi"); variable_bins.push_back(500 );  
  // variable.push_back("met_phir");variable_bins.push_back(500 );  
  variable.push_back("met_raw"); variable_bins.push_back(500 );  
  variable.push_back("met3p0_raw"); variable_bins.push_back(500 );  
  variable.push_back("met_rawgt1jet"); variable_bins.push_back(500 );  
  variable.push_back("met_raw_vince"); variable_bins.push_back(500 );  
  variable.push_back("ht");	     variable_bins.push_back(1000);  
  variable.push_back("ht_gt1j");	     variable_bins.push_back(3000);  
  variable.push_back("mt3");     variable_bins.push_back(500);  
  variable.push_back("njets");   variable_bins.push_back(20  );  
  variable.push_back("nbjets");   variable_bins.push_back(20  );  
  variable.push_back("mll");     variable_bins.push_back(300 );  
  variable.push_back("nVert");   variable_bins.push_back(50 );  
  variable.push_back("MHTFW");   variable_bins.push_back(1000 );  
  variable.push_back("MHTBA");   variable_bins.push_back(1000 );  
  variable.push_back("MHTFB");   variable_bins.push_back(1000 );  
  variable.push_back("MHTFBgt1jet");   variable_bins.push_back(1000 );

  variable.push_back("mll_metrawgt50"); variable_bins.push_back(500 );  
  variable.push_back("mll_metrawgt100"); variable_bins.push_back(500 );  
  variable.push_back("mll_metrawgt150"); variable_bins.push_back(500 );  
  variable.push_back("mll_metrawgt225"); variable_bins.push_back(500 );  
  variable.push_back("mll_metrawgt300"); variable_bins.push_back(500 );  
  
  variable.push_back("met_CORE"); variable_bins.push_back(500 );  
  variable.push_back("met_COREgt1jet"); variable_bins.push_back(500 );  

  variable.push_back("met3p0_CORE"); variable_bins.push_back(500 );  
  variable.push_back("met3p0_COREgt1jet"); variable_bins.push_back(500 );  

  variable.push_back("met3p5_pt");  variable_bins.push_back(500 );  

  variable.push_back("met_mettoolbox"); variable_bins.push_back(500 );  
  variable.push_back("met_mettoolboxgt1jet"); variable_bins.push_back(500 );  
  
  variable.push_back("met_mettoolboxNoHF"); variable_bins.push_back(500 );  
  variable.push_back("met_mettoolboxNoHFgt1jet"); variable_bins.push_back(500 );  
  
  variable.push_back("met_mettoolboxNoHFraw"); variable_bins.push_back(500 );  
  variable.push_back("met_mettoolboxNoHFrawgt1jet"); variable_bins.push_back(500 );  
  
  variable.push_back("met0jet");  variable_bins.push_back(500 );  
  variable.push_back("met1jet");  variable_bins.push_back(500 );  
  variable.push_back("metgt1jet");variable_bins.push_back(500 );  

  
  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
	for( unsigned int objind = 0; objind < object.size(); objind++ ){
	  for( unsigned int varind = 0; varind < variable.size(); varind++ ){
		for( unsigned int selind = 0; selind < selection.size(); selind++ ){
		  bookHist(Form("h_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						object   .at(objind).c_str(),
					    variable .at(varind).c_str(),
					    selection.at(selind).c_str()
						),
				   Form("h_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						object   .at(objind).c_str(),
					    variable .at(varind).c_str(),
					    selection.at(selind).c_str()
						),
				   static_cast<int>(variable_bins.at(varind)),
				   0.0,
				   variable_bins.at(varind));
		}
	  }
	}
  }

  // random extra hists here
  bookHist("h_templ_met", "h_templ_met", 500,0,500);

  vector <string> phivars;
  vector <float> axislimits;

  phivars.push_back("metphi");               axislimits.push_back(3.2);
  phivars.push_back("metphir");				 axislimits.push_back(3.2);
  phivars.push_back("metphi20");			 axislimits.push_back(3.2);
  phivars.push_back("metphi40");			 axislimits.push_back(3.2);
  phivars.push_back("metphi60");			 axislimits.push_back(3.2);
  phivars.push_back("mhtphi");               axislimits.push_back(3.2);

  phivars.push_back( "met3p0_raw_phi"      );axislimits.push_back(3.2); 
  phivars.push_back( "met3p5_phi"          );axislimits.push_back(3.2);  

  phivars.push_back("metx");axislimits.push_back(250);
  phivars.push_back("mety");axislimits.push_back(250);

  for( unsigned int lepind = 0; lepind < leptype.size(); lepind++ ){
	for( unsigned int objind = 0; objind < object.size(); objind++ ){
	  for( unsigned int varind = 0; varind < phivars.size(); varind++ ){
		for( unsigned int selind = 0; selind < selection.size(); selind++ ){
		  bookHist(Form("h_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						object   .at(objind).c_str(),
					    phivars  .at(varind).c_str(),
					    selection.at(selind).c_str()
						),
				   Form("h_%s_%s_%s_%s",
						leptype  .at(lepind).c_str(),
						object   .at(objind).c_str(),
					    phivars  .at(varind).c_str(),
					    selection.at(selind).c_str()
						),
				   200   ,
				   -axislimits.at(varind) ,
				    axislimits.at(varind)  );
		}
	  }
	}
  }

  bookHist("h_ll_event_drll_2jets", "h_ll_event_drll_2jets", 500,0,5);
  bookHist("h_ee_event_drll_2jets", "h_ee_event_drll_2jets", 500,0,5);
  bookHist("h_mm_event_drll_2jets", "h_mm_event_drll_2jets", 500,0,5);
  bookHist("h_em_event_drll_2jets", "h_em_event_drll_2jets", 500,0,5);
  // need to add hists for calculating FS BG


}

void templateLooper::bookHist( string name, string title, int nbins, float xmin, float xmax ){
  // cout<<"Booking hist: "<<name<<endl;
  TH1F * hist = new TH1F( name.c_str(), title.c_str(), nbins, xmin, xmax );
  hist->Sumw2();
  event_hists.insert ( pair<std::string,TH1F*>( name, hist ) );		
  return;
}  


void templateLooper::fillHist( string obj, string var, string sel, float value, float weight ){
  // cout<<"Booking hist: "<<name<<endl;
  // TH1F * hist = new TH1F( name, title, nbins, xmin, xmax );
  string hist = "h_";
  try
	{
	  if( zmet.hyp_type() == 0 ){
		hist = Form("h_ee_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( zmet.hyp_type() == 1 ){
		hist = Form("h_mm_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( zmet.hyp_type() == 2 ){
		hist = Form("h_em_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	  if( zmet.hyp_type() == 0 || zmet.hyp_type() == 1 ){
		hist = Form("h_ll_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);
	  }
	}
  catch(exception &e)
	{
	  cout<<"Hist: "<<hist<<" Does not exist!"<<endl;
	  exit(1);
	}
 
	return;
}  

