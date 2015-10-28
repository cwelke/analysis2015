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

#include "makePhotonTemplates.h"

#include "../sharedCode/histTools.h"
#include "../sharedCode/ZMET.h"
#include "../sharedCode/METTemplateSelections.h"
#include "../sharedCode/AnalysisSelections.h"

#include "../../CORE/Tools/dorky/dorky.h"
#include "../../CORE/Tools/goodrun.h"

using namespace std;
using namespace duplicate_removal;

const bool debug = false;
const bool usejson = true;
bool dovtxreweighting = false;

makePhotonTemplates::makePhotonTemplates()
{
  dohtreweighting = false;
};

makePhotonTemplates::makePhotonTemplates( bool htreweighting )
{
  dohtreweighting = htreweighting;
};

makePhotonTemplates::~makePhotonTemplates()
{
};

void makePhotonTemplates::ScanChain ( TChain * chain , const string iter , const string sample, const string selection ){

  // if( zmet.isData() )        cout << "Running on Data."        << endl;
  // else                       cout << "Running on MC.  "        << endl;
  

  cout<<selection<<endl;
  
  double npass = 0;
  METTemplates mettemplates( selection );
  mettemplates.setBins( selection );
  mettemplates.bookMETHists(mettemplate_hists);  
  bookHistos();

  // do this once per job
  // const char* json_file = "../../json/json_golden_168pb_290915_sntformat.txt"; // 116 pb
  // const char* json_file = "../../json/json_225pb_091015_sntformat.txt"; // 225 pb with bad data

  // const char* json_file = "/home/users/cwelke/analysis2015/CMSSW_7_4_7_patch2_dilepbabymaker/V07-04-10_datadriven/CORE/Tools/json_600pb_131015_sntformat.txt"; // updated, need more cms3

  // const char* json_file = "/home/users/cwelke/analysis2015/CMSSW_7_4_7_patch2_dilepbabymaker/V07-04-10/json/json_150pb_141015_sntformat.txt";

  const char* json_file = "/home/users/olivito/mt2_74x_dev/MT2Analysis/babymaker/jsons/Cert_246908-258750_13TeV_PromptReco_Collisions15_25ns_JSON_snt.txt"; // 1.3 fb
  
  set_goodrun_file(json_file);

  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");

  TH1F * h_vtxweight_22  = NULL;
  TH1F * h_vtxweight_30  = NULL;
  TH1F * h_vtxweight_36  = NULL;
  TH1F * h_vtxweight_50  = NULL;
  TH1F * h_vtxweight_75  = NULL;
  TH1F * h_vtxweight_90  = NULL;
  TH1F * h_vtxweight_120 = NULL;
  TH1F * h_vtxweight_165 = NULL;
  TFile * f_vtx = NULL;
  if( dovtxreweighting ){
	f_vtx = TFile::Open("../vtxreweighting/nvtx_ratio_data.root","READ");
	h_vtxweight_22  = (TH1F*)f_vtx->Get("h_vtx_ratio_22") ->Clone( "h_vtxweight_22" );
	h_vtxweight_30  = (TH1F*)f_vtx->Get("h_vtx_ratio_30") ->Clone( "h_vtxweight_30" );
	h_vtxweight_36  = (TH1F*)f_vtx->Get("h_vtx_ratio_36") ->Clone( "h_vtxweight_36" );
	h_vtxweight_50  = (TH1F*)f_vtx->Get("h_vtx_ratio_50") ->Clone( "h_vtxweight_50" );
	h_vtxweight_75  = (TH1F*)f_vtx->Get("h_vtx_ratio_75") ->Clone( "h_vtxweight_75" );
	h_vtxweight_90  = (TH1F*)f_vtx->Get("h_vtx_ratio_90") ->Clone( "h_vtxweight_90" );
	h_vtxweight_120 = (TH1F*)f_vtx->Get("h_vtx_ratio_120")->Clone( "h_vtxweight_120");
	h_vtxweight_165 = (TH1F*)f_vtx->Get("h_vtx_ratio_165")->Clone( "h_vtxweight_165");
	h_vtxweight_22 ->SetDirectory(rootdir);
	h_vtxweight_30 ->SetDirectory(rootdir);
	h_vtxweight_36 ->SetDirectory(rootdir);
	h_vtxweight_50 ->SetDirectory(rootdir);
	h_vtxweight_75 ->SetDirectory(rootdir);
	h_vtxweight_90 ->SetDirectory(rootdir);
	h_vtxweight_120->SetDirectory(rootdir);
	h_vtxweight_165->SetDirectory(rootdir);
	f_vtx->Close();
  }
  
  // TH1F * h_htweight_22  = NULL;
  // TH1F * h_htweight_30  = NULL;
  // TH1F * h_htweight_36  = NULL;
  // TH1F * h_htweight_50  = NULL;
  // TH1F * h_htweight_75  = NULL;
  // TH1F * h_htweight_90  = NULL;
  // TH1F * h_htweight_120 = NULL;
  // TH1F * h_htweight_165 = NULL;
  // TFile * f_ht = NULL;
  // if( dohtreweighting ){
  // 	f_ht = TFile::Open(Form("../vtxreweighting/ht_ratio_data_novtx_nohtweight%s.root", selection.c_str()),"READ");
  // 	h_htweight_22  = (TH1F*)f_ht->Get("h_ht_ratio_22") ->Clone( "h_htweight_22" );
  // 	h_htweight_30  = (TH1F*)f_ht->Get("h_ht_ratio_30") ->Clone( "h_htweight_30" );
  // 	h_htweight_36  = (TH1F*)f_ht->Get("h_ht_ratio_36") ->Clone( "h_htweight_36" );
  // 	h_htweight_50  = (TH1F*)f_ht->Get("h_ht_ratio_50") ->Clone( "h_htweight_50" );
  // 	h_htweight_75  = (TH1F*)f_ht->Get("h_ht_ratio_75") ->Clone( "h_htweight_75" );
  // 	h_htweight_90  = (TH1F*)f_ht->Get("h_ht_ratio_90") ->Clone( "h_htweight_90" );
  // 	h_htweight_120 = (TH1F*)f_ht->Get("h_ht_ratio_120")->Clone( "h_htweight_120");
  // 	h_htweight_165 = (TH1F*)f_ht->Get("h_ht_ratio_165")->Clone( "h_htweight_165");
  // 	h_htweight_22 ->SetDirectory(rootdir);
  // 	h_htweight_30 ->SetDirectory(rootdir);
  // 	h_htweight_36 ->SetDirectory(rootdir);
  // 	h_htweight_50 ->SetDirectory(rootdir);
  // 	h_htweight_75 ->SetDirectory(rootdir);
  // 	h_htweight_90 ->SetDirectory(rootdir);
  // 	h_htweight_120->SetDirectory(rootdir);
  // 	h_htweight_165->SetDirectory(rootdir);
  // 	f_ht->Close();
  // }

  TH1F * h_htweight = NULL;
  TFile * f_ht = NULL;
  if( dohtreweighting ){
  	f_ht = TFile::Open(Form("../vtxreweighting/ht_ratio_data_novtx_nohtweight%s.root", selection.c_str()),"READ");
  	h_htweight = (TH1F*)f_ht->Get("h_ht_ratio")->Clone("h_htweight");
  	h_htweight->SetDirectory(rootdir);
  	f_ht->Close();
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
	  
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  //Deal with event weights//
	  //-~-~-~-~-~-~-~-~-~-~-~-//
	  float weight = 1.0;
	  if( zmet.isData() ){
		weight = 1.0;
	  }else if( !zmet.isData() ){
		weight *= zmet.evt_scale1fb();
	  }

	  // define "global" event variables
	  float event_met_pt = zmet.met_pt();
	  float event_met_ph = zmet.met_phi();
	  event_met_pt = zmet.met_rawPt();
	  event_met_ph = zmet.met_rawPhi();	  
	  event_met_pt = zmet.met_T1CHSNoHF_fromCORE_pt(); // use miniAOD jets with 15 GeV
	  event_met_ph = zmet.met_T1CHSNoHF_fromCORE_phi();

	  float evt_ht    = zmet.ht();

	  float evt_njets = zmet.njets();
	  
	  if( evt_njets < 2 ) continue;	  

	  //~-~-~-~-~-~-~-~-//
      // event selection// 
	  //~-~-~-~-~-~-~-~-//
	  if( !eventHasGoodPhoton()                                    ) continue; // event selection
      if( !usejson && zmet.isData() && !zmet.evt_passgoodrunlist() ) continue; // use json applied at babymaking
      if( zmet.isData() && zmet.nVert() == 0                       ) continue; // special selection for now
	  // if( zmet.isData() && !passPhotonTrigger()                    ) continue; // pass trigger for data
	  if( zmet.isData() && getPrescaleNoBins() <= 0                ) continue; // pass trigger for data

	  // if( zmet.isData() && zmet.met_rawPt() < 0.1 ) continue;
	  
	  // everything after this is template specific
	  if( evt_njets < 2 ) continue;	  	  
	  if( !passSignalRegionSelection(selection) ) continue;
	  if( !passMETFilters() ) continue;

	  // cout<<getPrescaleNoBins()<<endl;
	  // cout<<"165 pscale: "<<zmet.HLT_Photon165_R9Id90_HE10_IsoM()<<endl;
	  // cout<<"30 pscale:  "<<zmet.HLT_Photon30_R9Id90_HE10_IsoM()<<endl;
	  if( zmet.isData() ){  
	  	// weight *= (float) getPrescale();
	  	weight *= (float) getPrescaleNoBins();
	  }
	  
	  // if( TString(selection).Contains("SR_ATLAS") ) evt_ht += zmet.gamma_pt().at(0);

	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//	  
	  fillHist( "event", "njets"  , "passtrig", evt_njets         , weight );
	  fillHist( "event", "met"    , "passtrig", event_met_pt         , weight );
	  fillHist( "event", "met_raw", "passtrig", zmet.met_rawPt()     , weight );
	  fillHist( "event", "ht"     , "passtrig", evt_ht            , weight );
	  if( evt_njets > 0 ) 	  fillHist( "event", "htgt0jets"     , "passtrig", evt_ht            , weight );
	  fillHist( "event", "ptg"    , "passtrig", zmet.gamma_pt().at(0), weight );	  
	  fillHist( "event", "nVert"  , "passtrig", zmet.nVert()         , weight );	  
	  fillHist( "event", "metphi" , "passtrig", event_met_ph         , weight );	  
	  fillHist( "event", "metphir", "passtrig", zmet.met_rawPhi()    , weight );	  
	  if( evt_njets == 0 ) fillHist( "event", "met0jet"   , "passtrig", event_met_pt        , weight );
	  if( evt_njets == 1 ) fillHist( "event", "met1jet"   , "passtrig", event_met_pt        , weight );
	  if( evt_njets >= 2 ) fillHist( "event", "metgt1jet" , "passtrig", event_met_pt        , weight );
	  


	  if( dovtxreweighting ){
	    if(      zmet.gamma_pt().at(0) > 165 ) weight *= h_vtxweight_165 ->GetBinContent(h_vtxweight_165 ->FindBin(zmet.nVert()));
	  	else if( zmet.gamma_pt().at(0) > 120 ) weight *= h_vtxweight_120 ->GetBinContent(h_vtxweight_120 ->FindBin(zmet.nVert()));
	  	else if( zmet.gamma_pt().at(0) > 90  ) weight *= h_vtxweight_90  ->GetBinContent(h_vtxweight_90  ->FindBin(zmet.nVert()));
	  	else if( zmet.gamma_pt().at(0) > 75  ) weight *= h_vtxweight_75  ->GetBinContent(h_vtxweight_75  ->FindBin(zmet.nVert()));
	  	else if( zmet.gamma_pt().at(0) > 50  ) weight *= h_vtxweight_50  ->GetBinContent(h_vtxweight_50  ->FindBin(zmet.nVert()));
	  	else if( zmet.gamma_pt().at(0) > 36  ) weight *= h_vtxweight_36  ->GetBinContent(h_vtxweight_36  ->FindBin(zmet.nVert()));
	  	else if( zmet.gamma_pt().at(0) > 33  ) weight *= h_vtxweight_30  ->GetBinContent(h_vtxweight_30  ->FindBin(zmet.nVert()));
	  	else if( zmet.gamma_pt().at(0) > 22  ) weight *= h_vtxweight_22  ->GetBinContent(h_vtxweight_22  ->FindBin(zmet.nVert()));
	    // if(      ( !zmet.isData() && zmet.gamma_pt().at(0) > 170 ) || passPhotonTrigger165() ) weight *= h_vtxweight_165 ->GetBinContent(h_vtxweight_165 ->FindBin(zmet.nVert()));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 125 ) || passPhotonTrigger120() ) weight *= h_vtxweight_120 ->GetBinContent(h_vtxweight_120 ->FindBin(zmet.nVert()));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 100 ) || passPhotonTrigger90()  ) weight *= h_vtxweight_90  ->GetBinContent(h_vtxweight_90  ->FindBin(zmet.nVert()));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 80  ) || passPhotonTrigger75()  ) weight *= h_vtxweight_75  ->GetBinContent(h_vtxweight_75  ->FindBin(zmet.nVert()));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 60  ) || passPhotonTrigger50()  ) weight *= h_vtxweight_50  ->GetBinContent(h_vtxweight_50  ->FindBin(zmet.nVert()));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 40  ) || passPhotonTrigger36()  ) weight *= h_vtxweight_36  ->GetBinContent(h_vtxweight_36  ->FindBin(zmet.nVert()));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 35  ) || passPhotonTrigger30()  ) weight *= h_vtxweight_30  ->GetBinContent(h_vtxweight_30  ->FindBin(zmet.nVert()));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 25  ) || passPhotonTrigger22()  ) weight *= h_vtxweight_22  ->GetBinContent(h_vtxweight_22  ->FindBin(zmet.nVert()));
	  }

	  // if( TString(selection).Contains("SR_ATLAS") ) fillHist( "event", "htgt1jets", "passtrig", zmet.gamma_pt().at(0) + evt_ht, weight ); // this is for HT reweighting
	  // else                                          fillHist( "event", "htgt1jets", "passtrig", zmet.gamma_pt().at(0)         , weight ); // this is for HT reweighting

	  fillHist( "event", "htgt1jets", "passtrig", zmet.gamma_pt().at(0)         , weight ); // this is for HT reweighting
												
	  if( dohtreweighting ){
	  	weight *= h_htweight->GetBinContent(h_htweight->FindBin(zmet.gamma_pt().at(0)));		
	  }

	  // if( dohtreweighting ){
	  // 	float evt_pt = zmet.gamma_pt().at(0);
	  //   if(      ( zmet.gamma_pt().at(0) > 165 ) weight *= h_htweight_165 ->GetBinContent(h_htweight_165 ->FindBin(evt_pt));
	  // 	else if( ( zmet.gamma_pt().at(0) > 120 ) weight *= h_htweight_120 ->GetBinContent(h_htweight_120 ->FindBin(evt_pt));
	  // 	else if( ( zmet.gamma_pt().at(0) > 90  ) weight *= h_htweight_90  ->GetBinContent(h_htweight_90  ->FindBin(evt_pt));
	  // 	else if( ( zmet.gamma_pt().at(0) > 75  ) weight *= h_htweight_75  ->GetBinContent(h_htweight_75  ->FindBin(evt_pt));
	  // 	else if( ( zmet.gamma_pt().at(0) > 50  ) weight *= h_htweight_50  ->GetBinContent(h_htweight_50  ->FindBin(evt_pt));
	  // 	else if( ( zmet.gamma_pt().at(0) > 36  ) weight *= h_htweight_36  ->GetBinContent(h_htweight_36  ->FindBin(evt_pt));
	  // 	else if( ( zmet.gamma_pt().at(0) > 33  ) weight *= h_htweight_30  ->GetBinContent(h_htweight_30  ->FindBin(evt_pt));
	  // 	else if( ( zmet.gamma_pt().at(0) > 22  ) weight *= h_htweight_22  ->GetBinContent(h_htweight_22  ->FindBin(evt_pt));
	    // if(      ( !zmet.isData() && zmet.gamma_pt().at(0) > 170 ) || passPhotonTrigger165() ) weight *= h_htweight_165 ->GetBinContent(h_htweight_165 ->FindBin(evt_ht));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 125 ) || passPhotonTrigger120() ) weight *= h_htweight_120 ->GetBinContent(h_htweight_120 ->FindBin(evt_ht));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 100 ) || passPhotonTrigger90()  ) weight *= h_htweight_90  ->GetBinContent(h_htweight_90  ->FindBin(evt_ht));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 80  ) || passPhotonTrigger75()  ) weight *= h_htweight_75  ->GetBinContent(h_htweight_75  ->FindBin(evt_ht));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 60  ) || passPhotonTrigger50()  ) weight *= h_htweight_50  ->GetBinContent(h_htweight_50  ->FindBin(evt_ht));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 40  ) || passPhotonTrigger36()  ) weight *= h_htweight_36  ->GetBinContent(h_htweight_36  ->FindBin(evt_ht));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 35  ) || passPhotonTrigger30()  ) weight *= h_htweight_30  ->GetBinContent(h_htweight_30  ->FindBin(evt_ht));
	  	// else if( ( !zmet.isData() && zmet.gamma_pt().at(0) > 25  ) || passPhotonTrigger22()  ) weight *= h_htweight_22  ->GetBinContent(h_htweight_22  ->FindBin(evt_ht));
	  // }
	  
	  //-~-~-~-~-~-~-~-~-~-//
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  
      npass += weight;
	  // mettemplates.FillTemplate(mettemplate_hists, evt_njets, zmet.ht(), zmet.gamma_pt().at(0), event_met_pt, weight );
	  mettemplates.FillTemplate(mettemplate_hists, evt_njets, evt_ht, zmet.gamma_pt().at(0), event_met_pt, weight );

    } // end loop over events
  } // end loop over files



  cout << npass       << " events passing selection" << endl;
  cout << nDuplicates << " duplicate events in data" << endl;
  // cout << "em events at low MET : "     << nem_2jets*10 << endl;
  
  mettemplates.NormalizeTemplates(mettemplate_hists);

  
  if (nEventsChain != nEventsTotal)
    std::cout << "ERROR: number of events from files is not equal to total number of events" << std::endl;

  string str_vtxweight = "";
  
  if( !dovtxreweighting ) str_vtxweight+= "_novtxweight";
  if( !dohtreweighting ) str_vtxweight+= "_nohtweight";

  // make histos rootfile
  string outputfilename = 	Form("../output/%s/%s%s%s_templates.root",
								 iter.c_str(),
								 sample.c_str(),
								 selection.c_str(),
								 str_vtxweight.c_str()
								 );

  cout << "Writing output to " << outputfilename << endl;
  saveHist(outputfilename.c_str(),"*");
  
  // deleteHistos();
  
} // end ScanChain


void makePhotonTemplates::bookHistos(){

  // hist naming convention: "h_<leptype>_<object>_<variable>_<selection>"
  vector <string> leptype;
  // leptype.push_back("ee");
  // leptype.push_back("mm");
  // leptype.push_back("em");
  // leptype.push_back("ll");
  leptype.push_back("ph");
  vector <string> object;
  object.push_back("event");
  // object.push_back("templ");
  // object.push_back("lep1");
  // object.push_back("lep2");
  // object.push_back("dilep");
  vector <string> selection;
  selection.push_back("inclusive");
  selection.push_back("passtrig");
  selection.push_back("passtrig165");
  selection.push_back("passtrig120");
  selection.push_back("passtrig90");
  selection.push_back("passtrig75");
  selection.push_back("passtrig50");
  selection.push_back("passtrig36");
  selection.push_back("passtrig30");
  selection.push_back("passtrig22");

  vector <string> variable;      vector <float> variable_bins;

  variable.push_back("ptg");       variable_bins.push_back(1000);  
  variable.push_back("met");       variable_bins.push_back(500 );  
  variable.push_back("metphi");    variable_bins.push_back(500 );  
  variable.push_back("metphir");   variable_bins.push_back(500 );  
  variable.push_back("met_raw");   variable_bins.push_back(500 );  
  variable.push_back("ht");	       variable_bins.push_back(1000);  
  variable.push_back("htgt0jets"); variable_bins.push_back(1000);  
  variable.push_back("htgt1jets"); variable_bins.push_back(3000);  
  variable.push_back("njets");     variable_bins.push_back(20  );  
  variable.push_back("nVert");     variable_bins.push_back(50 );  
  variable.push_back("met0jet");   variable_bins.push_back(500 );  
  variable.push_back("met1jet");   variable_bins.push_back(500 );  
  variable.push_back("metgt1jet"); variable_bins.push_back(500 );  

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
  // need to add hists for calculating FS BG


}

void makePhotonTemplates::bookHist( string name, string title, int nbins, float xmin, float xmax ){
  // cout<<"Booking hist: "<<name<<endl;
  TH1F * hist = new TH1F( name.c_str(), title.c_str(), nbins, xmin, xmax );
  hist->Sumw2();
  event_hists.insert ( pair<std::string,TH1F*>( name, hist ) );		
  return;
}  


void makePhotonTemplates::fillHist( string obj, string var, string sel, float value, float weight ){
  // cout<<"Booking hist: "<<name<<endl;
  // TH1F * hist = new TH1F( name, title, nbins, xmin, xmax );
  string hist = "h_";
  try
	{
	  if( zmet.evt_type() == 2 ){
		hist = Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), sel.c_str());
		fillUnderOverFlow(event_hists.at( hist ), value, weight);		
		// if( passPhotonTrigger165() ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig165") ), value, weight);
		// if( passPhotonTrigger120() ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig120") ), value, weight);
		// if( passPhotonTrigger90()  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig90" ) ), value, weight);
		// if( passPhotonTrigger75()  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig75" ) ), value, weight);
		// if( passPhotonTrigger50()  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig50" ) ), value, weight);
		// if( passPhotonTrigger36()  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig36" ) ), value, weight);
		// if( passPhotonTrigger30()  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig30" ) ), value, weight);
		// if( passPhotonTrigger22()  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig22" ) ), value, weight);

		if(      zmet.gamma_pt().at(0) > 165 ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig165") ), value, weight);
		else if( zmet.gamma_pt().at(0) > 120 ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig120") ), value, weight);
		else if( zmet.gamma_pt().at(0) > 90  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig90" ) ), value, weight);
		else if( zmet.gamma_pt().at(0) > 75  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig75" ) ), value, weight);
		else if( zmet.gamma_pt().at(0) > 50  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig50" ) ), value, weight);
		else if( zmet.gamma_pt().at(0) > 36  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig36" ) ), value, weight);
		else if( zmet.gamma_pt().at(0) > 33  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig30" ) ), value, weight);
		else if( zmet.gamma_pt().at(0) > 22  ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig22" ) ), value, weight);

		// if(      zmet.HLT_Photon165_R9Id90_HE10_IsoM() > 0 ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig165") ), value, weight);
		// else if( zmet.HLT_Photon120_R9Id90_HE10_IsoM() > 0 ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig120") ), value, weight);
		// else if( zmet.HLT_Photon90_R9Id90_HE10_IsoM()  > 0 ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig90" ) ), value, weight);
		// else if( zmet.HLT_Photon75_R9Id90_HE10_IsoM()  > 0 ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig75" ) ), value, weight);
		// else if( zmet.HLT_Photon50_R9Id90_HE10_IsoM()  > 0 ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig50" ) ), value, weight);
		// else if( zmet.HLT_Photon36_R9Id90_HE10_IsoM()  > 0 ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig36" ) ), value, weight);
		// else if( zmet.HLT_Photon30_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 33 ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig30" ) ), value, weight);
		// else if( zmet.HLT_Photon22_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) < 33 ) fillUnderOverFlow(event_hists.at( Form("h_ph_%s_%s_%s", obj.c_str(), var.c_str(), "passtrig22" ) ), value, weight);

	  }else if( zmet.evt_type() == 0 ){		  
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
	}
  catch(exception &e)
	{
	  cout<<"Hist: "<<hist<<" Does not exist!"<<endl;
	  exit(1);
	}
 
  return;
}  

