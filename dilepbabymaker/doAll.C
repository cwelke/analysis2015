{

  gSystem->Load("libMiniFWLite.so");
  gSystem->Load("libBabymakerCORE.so");
  gSystem->Load("libBabymakerTools.so");
  gSystem->Load("libScanChain.so");


  TChain *ch = new TChain("Events"); 
   
  // ch->Add("/nfs-7/userdata/cwelke/CMS3_testing/phys14/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_1.root");
  // ch->Add("/hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_1.root");
  ch->Add("/hadoop/cms/store/group/snt/phys14/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_1.root");
  // ch->Add("/hadoop/cms/store/group/snt/phys14/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08/merged_ntuple_2.root");
   
  babyMaker *looper = new babyMaker();
  looper->ScanChain(ch, "StopBaby_ttbar_test_noiso"); 
}
