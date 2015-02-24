// #include <string>

// // #include "makePhotonTemplates.C"

// #include "makePhotonTemplates.h"

// #include "TChain.h"
// #include "TSystem.h"
// #include "TROOT.h"
// #include "TStyle.h"


// using namespace std;

void runTemplateLooper( std::string selection = "" ){

  string iter = "V00-00-00";

  string sample = "All_MC"; 

  gSystem->Load("libTemplateLooper.so");
  gROOT ->SetStyle("Plain");
  gStyle->SetOptStat(111111);

  TChain* ch = new TChain("t");

  if ( sample == "All_MC" ){

	ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_m50inc*.root");
	ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht100to200*.root");
	ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht200to400*.root");
	ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht400to600*.root");
	ch->Add("/nfs-7/userdata/cwelke/ZMETbabies/V00-00-07/dyjetsll_ht600toinf*.root");
	
  }

  templateLooper* myLooper = new templateLooper();
  myLooper->ScanChain( ch , iter , sample );

  
  // makePhotonTemplates myLooper(selection);
  // myLooper.ScanChain( ch , iter , sample );

}

