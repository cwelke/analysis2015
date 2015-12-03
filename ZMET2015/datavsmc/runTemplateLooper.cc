 #include <iostream>

#include "TChain.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStyle.h"

#include "templateLooper.h"

using namespace std;

void runTemplateLooper( std::string selection = "", std::string iter = "", std::string sample = "All_MC" ){

  gSystem->Load("libTemplateLooper.so");
  gROOT ->SetStyle("Plain");
  gStyle->SetOptStat(111111);

  TChain* ch = new TChain("t");
  if ( sample == "data" ){

	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13_metstudies/data_2015D25ns05Oct2015_ee*.root" , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13_metstudies/data_2015D25ns05Oct2015_em*.root" , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13_metstudies/data_2015D25ns05Oct2015_mm*.root" , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13_metstudies/data_2015C25ns05Oct2015_ee*.root" , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13_metstudies/data_2015C25ns05Oct2015_em*.root" , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13_metstudies/data_2015C25ns05Oct2015_mm*.root" , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13_metstudies/data_2015D25nsPromptv4_ee*.root" , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13_metstudies/data_2015D25nsPromptv4_em*.root" , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13_metstudies/data_2015D25nsPromptv4_mm*.root" , iter.c_str() ));

	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015D25ns05Oct2015_ee*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015D25ns05Oct2015_em*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015D25ns05Oct2015_mm*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015C25ns05Oct2015_ee*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015C25ns05Oct2015_em*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015C25ns05Oct2015_mm*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015D25nsPromptv4_ee*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015D25nsPromptv4_em*.root" , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/data_2015D25nsPromptv4_mm*.root" , iter.c_str() ));

	if( TString(selection).Contains("signalcontamination") ){
	  ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/t5zz_mgl*_mlm.root" , iter.c_str() ));
	}
	
  }

  if ( sample == "fullscan" || sample == "signal1100200" || sample == "signal900" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/t5zz_mgl*_mlm*.root" , iter.c_str() ));
  }

  else if ( sample == "All_MC" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_50ns_m1050nlo*.root"  , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_50ns_m50nlo*.root"    , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/tt2lnu_50ns_php8*.root"         , iter.c_str() ));	
  }

  else if( sample == "zjets" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_25ns_m1050nlo*.root"  , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_25ns_m50nlo*.root"    , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zjetsll_25ns_m50mlm*.root"  , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zjetsllht100_25ns_m50mlm*.root"  , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zjetsllht200_25ns_m50mlm*.root"  , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zjetsllht400_25ns_m50mlm*.root"  , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zjetsllht600_25ns_m50mlm*.root"  , iter.c_str() ));
  }

  else if( sample == "zjetsmlm" ){

	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zjetsll_25ns_m50mlm*.root"  , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zjetsllht100_25ns_m50mlm*.root"  , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zjetsllht200_25ns_m50mlm*.root"  , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zjetsllht400_25ns_m50mlm*.root"  , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zjetsllht600_25ns_m50mlm*.root"  , iter.c_str() ));

	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13/zjetsll_25ns_m50mlm*.root"  , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13/zjetsllht100_25ns_m50mlm*.root"  , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13/zjetsllht200_25ns_m50mlm*.root"  , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13/zjetsllht400_25ns_m50mlm*.root"  , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/V07-04-13/zjetsllht600_25ns_m50mlm*.root"  , iter.c_str() ));
  }

  else if( sample == "zjinc" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/dyjetsll_m50inc*.root"    , iter.c_str() ));
  }

  else if( sample == "ttbar" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/tt2lnu_25ns_php8*.root"      , iter.c_str() ));
  }

  else if( sample == "st" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/sttwatop_25ns_powp8*.root"   , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/sttwtop_25ns_powp8*.root"    , iter.c_str() ));
  }

  else if( sample == "ww" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ww2l2nu_25ns_powp8*.root"    , iter.c_str() ));
  }

  else if( sample == "wz_inc" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/wz3lnu_25ns_powp8*.root"     , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/wz2l2q_25ns_nlo*.root"       , iter.c_str() ));
  }

  else if( sample == "zz_inc" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zz2l2q_25ns_nlo*.root"       , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zz4l_25ns_php8*.root"        , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zz2l2nu_25ns_powp8*.root"        , iter.c_str() ));
  }

  else if( sample == "wz" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/wz3lnu_25ns_powp8*.root"     , iter.c_str() ));
  }

  else if( sample == "zz" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zz2l2nu_25ns_powp8*.root"        , iter.c_str() ));
  }

  else if( sample == "vvv" ){
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/wzz_25ns_nlo*.root"         , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/wwz_25ns_nlo*.root"         , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/zzz_25ns_nlo*.root"         , iter.c_str() ));
  }

  else if( sample == "ttv" ){
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttw2q_25ns_nlo*.root"       , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttwlnu_25ns_nlo*.root"      , iter.c_str() ));
	ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttzllnunu_25ns_nlo*.root"   , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttzqq_25ns_nlo*.root"       , iter.c_str() ));
	// ch->Add(Form("/nfs-6/userdata/cwelke/ZMETbabies/%s/ttg_25ns_nlo*.root"         , iter.c_str() ));
  }
  
  templateLooper* myLooper = new templateLooper();
  myLooper->ScanChain( ch , iter , sample, selection );

}

int main(int argc, char **argv)
{

  if (argc < 4) {
    std::cout << "USAGE: runTemplateLooper <selection> <iter> <sample>" << std::endl;
    return 1;
  }
  
  string selection(argv[1]); 
  string iter(argv[2]); 
  string sample(argv[3]); 
  
  runTemplateLooper( selection, iter, sample );
  return 0;
}
