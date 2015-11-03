#include <iostream>

#include "TChain.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStyle.h"

#include "makePhotonTemplates.h"

using namespace std;

void runPhotonTemplates( std::string selection = "", std::string iter = "", std::string sample = "", bool dohtreweighting = false ){

  gSystem->Load("libmakePhotonTemplates.so");
  gROOT ->SetStyle("Plain");
  gStyle->SetOptStat(111111);

  TChain* ch = new TChain("t");

  if ( sample == "data" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015C25ns05Oct2015_ph*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015D25ns05Oct2015_ph*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015D25nsPromptv4_ph*.root"  , iter.c_str() ));
  }

  else if ( sample == "All_MC" ){
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_pt40_doubleEM.root");

	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjets_25ns_ht40mlm*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjets_25ns_ht100mlm*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjets_25ns_ht200mlm*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjets_25ns_ht400mlm*.root", iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/gjets_25ns_ht600mlm*.root", iter.c_str() ));

	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht100to200.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht200to400.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht200to400_1.root" );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht400to600.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht400to600_1.root" );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht600toinf.root"   );
	// ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-01/gjet_ht600toinf_1.root" );

  }

  makePhotonTemplates* myLooper = new makePhotonTemplates(dohtreweighting);
  myLooper->ScanChain( ch , iter , sample, selection );

  
  // makePhotonTemplates myLooper(selection);
  // myLooper.ScanChain( ch , iter , sample );

}

int main(int argc, char **argv)
{

  if (argc < 5) {
    std::cout << "USAGE: runTemplateLooper <selection> <iter> <sample> <htreweighting>" << std::endl;
    return 1;
  }
  
  string selection(argv[1]); 
  string iter(argv[2]); 
  string sample(argv[3]); 
  string dohtreweighting(argv[4]); 

  bool doreweighting = false;
  if( dohtreweighting == "dohtreweighting" )  doreweighting = true;
  
  runPhotonTemplates( selection, iter, sample, doreweighting );
  return 0;
}
