// #include <string>

// // #include "makePhotonTemplates.C"

// #include "makePhotonTemplates.h"

// #include "TChain.h"
// #include "TSystem.h"
// #include "TROOT.h"
// #include "TStyle.h"


// using namespace std;

void runTemplateLooper( std::string selection = "", std::string iter = "", std::string sample = "All_MC" ){

  gSystem->Load("libTemplateLooper.so");
  gROOT ->SetStyle("Plain");
  gStyle->SetOptStat(111111);

  TChain* ch = new TChain("t");

  if ( sample == "All_MC" ){

	ch->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/dyjetsll_m50inc*.root"    , iter.c_str() ));
	ch->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht100to200*.root", iter.c_str() ));
	ch->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht200to400*.root", iter.c_str() ));
	ch->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht400to600*.root", iter.c_str() ));
	ch->Add(Form("/nfs-7/userdata/cwelke/ZMETbabies/%s/dyjetsll_ht600toinf*.root", iter.c_str() ));
	
  }

  templateLooper* myLooper = new templateLooper();
  myLooper->ScanChain( ch , iter , sample );

  
  // makePhotonTemplates myLooper(selection);
  // myLooper.ScanChain( ch , iter , sample );

}

