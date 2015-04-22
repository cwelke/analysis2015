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

using namespace std;

const bool debug = false;

templateLooper::templateLooper()
{
};

templateLooper::~templateLooper()
{
};

void templateLooper::ScanChain ( TChain * chain , const string iter , const string sample ){

  // if( zmet.isData() )        cout << "Running on Data."        << endl;
  // else                       cout << "Running on MC.  "        << endl;

  unsigned int nee = 0;
  unsigned int nmm = 0;
  unsigned int nem = 0;
  
  int npass = 0;
  METTemplates mettemplates;
  mettemplates.loadTemplatesFromFile( Form("../output/photon/%s/All_MC_photon_templates.root", iter.c_str()), mettemplate_hists );
  mettemplates.setBins();
  TH1F* currentMETTemplate = NULL;

  bookHistos();

  TObjArray *listOfFiles = chain->GetListOfFiles();
  unsigned int nEventsChain = 0;
  unsigned int nEvents = chain->GetEntries();
  nEventsChain = nEvents;
  unsigned int nEventsTotal = 0;

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

	  if( TString(currentFile->GetTitle()).Contains("m50inc") ){
	  	if( zmet.gen_ht() > 100 ) continue;
	  }else if( TString(currentFile->GetTitle()).Contains("dyjetsll") ){
	  	if( zmet.gen_ht() < 100 ) continue;
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

	  //~-~-~-~-~-~-~-~-//
      // event selection// 
	  //~-~-~-~-~-~-~-~-//

	  if( zmet.nlep()                        < 2         ) continue; // require at least 2 good leptons
	  if( zmet.lep_pt().at(0)                < 25        ) continue; // leading lep pT > 25 GeV
	  if( zmet.lep_pt().at(1)                < 20        ) continue; // tailing lep pT > 20 GeV

	  if( abs(zmet.lep_p4().at(0).eta())     > 2.4       ) continue; // eta < 2.4
	  if( abs(zmet.lep_p4().at(1).eta())     > 2.4       ) continue; // eta < 2.4

	  if( abs(zmet.lep_p4().at(0).eta())     > 1.4 &&
		  abs(zmet.lep_p4().at(0).eta())     < 1.6       ) continue; 
	  if( abs(zmet.lep_p4().at(1).eta())     > 1.4 &&
		  abs(zmet.lep_p4().at(1).eta())     < 1.6       ) continue; // veto xition region


	  if( zmet.dRll() < 0.3 ) continue;
	  
	  // if( (zmet.hyp_type() == 0 ||					     
	  // 	   zmet.hyp_type() == 1 ) &&
	  // 	  (zmet.dilmass() > 81 && zmet.dilmass() < 101) ) n2525pass += weight;

	  if( !(zmet.hyp_type() == 0 ||					     
			zmet.hyp_type() == 1 ||					     
			zmet.hyp_type() == 2 )                       ) continue; // require explicit dilepton event
	  // if( zmet.ht()                          < 240       ) continue; // HT > 100

	  if( zmet.hyp_type() == 0 ) nee++;
	  if( zmet.hyp_type() == 1 ) nmm++;
	  if( zmet.hyp_type() == 2 ) nem++;
	  
	  if( zmet.njets()                       < 2         ) continue; // >=2 jets
	  fillHist( "event", "mll"  , "2jets", zmet.dilmass()  , weight );

	  if( !(zmet.dilmass() > 81 && zmet.dilmass() < 101) ) continue; // HT > 100
	  // if( zmet.dilpt()                       < 50   ) continue; // for now, require 50 GeV dil Z pT cut

      // if( isdata && !(templates.csc()==0 && 
	  // 				  templates.hbhe()==1 && 
	  // 				  templates.hcallaser()==1 && 
	  // 				  templates.ecallaser()==1 && 
	  // 				  templates.ecaltp()==1 && 
	  // 				  templates.trkfail()==1 && 
	  // 				  templates.eebadsc()==1 && 
	  // 				  templates.hbhenew()==1) )                             continue; // MET filters
	  // // if( isdata && (h20 < 1 && h30 < 1 && h50 < 1 && h75 < 1 && h90 < 1 )) continue; // require trig
	  // if( isdata && (h20 < 1 && h50 < 1 && h75 < 1 && h90 < 1 )) continue; // require trig
	  
      ++npass;

	  //-~-~-~-~-~-~-~-~-~-//
	  //Fill Template hists//
	  //-~-~-~-~-~-~-~-~-~-//	  

	  if( zmet.hyp_type() == 0 || zmet.hyp_type() == 1 ){
		currentMETTemplate = mettemplates.pickTemplate( mettemplate_hists, zmet.njets(), zmet.ht(), zmet.dilpt() );
		mettemplates.countTemplate( zmet.njets(), zmet.ht(), zmet.dilpt(), weight );
		// currentMETTemplate->Scale(weight);
		try
		  {
			event_hists.at( "h_templ_met" ) -> Add( currentMETTemplate, weight );		
		  }
		catch(exception &e)
		  {
			cout<<"Hist: h_templ_met Does not exist!"<<endl;
			exit(1);
		  }
		// mettemplates.normalizeTemplate(currentMETTemplate);
	  }
	  
	  //-~-~-~-~-~-~-~-~-//
	  //Fill event  hists//
	  //-~-~-~-~-~-~-~-~-//	  

	  fillHist( "event", "njets", "2jets", zmet.njets()    , weight );
	  fillHist( "event", "met"  , "2jets", zmet.met_rawPt(), weight );
	  fillHist( "event", "ht"   , "2jets", zmet.ht()       , weight );

	  // }else{
	  // 	  cout << "NO TRIGGERS PASS!!!" << endl;
	  // 	  exit(0);
	  // 	}

    } // end loop over events
  } // end loop over files



  cout << npass << " events passing selection" << endl;
  cout << nee << " ee events passing selection" << endl;
  cout << nmm << " mm events passing selection" << endl;
  cout << nem << " em events passing selection" << endl;

  mettemplates.NormalizeTemplates(mettemplate_hists);
  mettemplates.correctBinUncertainty( mettemplate_hists, event_hists.at("h_templ_met") );

  
  if (nEventsChain != nEventsTotal)
    std::cout << "ERROR: number of events from files is not equal to total number of events" << std::endl;
  

  // make histos rootfile
  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  rootdir->cd();


  string outputfilename = 	Form("../output/%s/%s_hists.root",
								 iter.c_str(),
								 sample.c_str()
								 );

  cout << "Writing output to " << outputfilename << endl;
  saveHist(outputfilename.c_str(),"*");
  
  // deleteHistos();
  
} // end ScanChain


void templateLooper::bookHistos(){

  TDirectory *rootdir = gDirectory->GetDirectory("Rint:");
  rootdir->cd();

  // hist naming convention: "h_<leptype>_<object>_<variable>_<selection>"
  vector <string> leptype;
  leptype.push_back("ee");
  leptype.push_back("mm");
  leptype.push_back("em");
  leptype.push_back("ll");
  vector <string> object;
  object.push_back("event");
  // object.push_back("templ");
  object.push_back("lep1");
  object.push_back("lep2");
  object.push_back("dilep");
  vector <string> selection;
  selection.push_back("2jets");
  vector <string> variable;
  variable.push_back("pt");
  variable.push_back("met");
  variable.push_back("ht");
  variable.push_back("mt2");
  variable.push_back("mt2j");
  variable.push_back("njets");
  variable.push_back("mll");
  vector <float> variable_bins;
  variable_bins.push_back(500 );
  variable_bins.push_back(500 );
  variable_bins.push_back(1000);
  variable_bins.push_back(500 );
  variable_bins.push_back(500 );
  variable_bins.push_back(20  );  
  variable_bins.push_back(300 );  

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

  // need to add hists for calculating FS BG


}

void templateLooper::bookHist( string name, string title, int nbins, float xmin, float xmax ){
  cout<<"Booking hist: "<<name<<endl;
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

