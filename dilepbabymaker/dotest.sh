#!/bin/bash

make -j5
didcompile=$?

if [ ! $didcompile == "0" ]; then
	echo "did not compile. exiting."
	exit $didcompile
fi

# ./processBaby test  /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-03/merged_ntuple_1.root
# ./processBaby test_mc  /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/V07-04-03/merged_ntuple_1.root
# ./processBaby test_validate_T1  /hadoop/cms/store/group/snt/run2_50ns/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-03/merged_ntuple_1.root 
./processBaby test_validate_T1 /nfs-6/userdata/cwelke/data/2015B/ttbar_mc/merged_ntuple_1.root 

# ./processBaby test_data /hadoop/cms/store/user/cwelke/run2_data/SinglePhoton_Run2015B-PromptReco-v1/V07-04-06/merged_ntuple_1.root 
# ./processBaby test_mumu_1 /hadoop/cms/store/group/snt/run2_data/Run2015B_DoubleMuon_MINIAOD_PromptReco-v1/merged/V07-04-06/merged_ntuple_1.root
# ./processBaby test_mumu_2 /hadoop/cms/store/group/snt/run2_data/Run2015B_DoubleMuon_MINIAOD_PromptReco-v1/merged/V07-04-06/merged_ntuple_2.root
# ./processBaby test_mumu_3 /hadoop/cms/store/group/snt/run2_data/Run2015B_DoubleMuon_MINIAOD_PromptReco-v1/merged/V07-04-06/merged_ntuple_3.root

#./processBaby data_json_fixrho  /home/users/jgran/temp/electronID/CMSSW_7_4_1_patch1/src/CMS3/NtupleMaker/ntuple_rereco.root
#./processBaby qcd_CMS3-07-04-03_test  /hadoop/cms/store/group/snt/run2_25ns/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/merged_ntuple_31.root
#./processBaby qcd_test_noJEC_fixjetID ./ntuple_QCD.root
#./processBaby qcd_test_noJEC_fixjetID_fixgamma /home/users/gzevi/ntupling/CMSSW_7_4_1_patch1/src/CMS3/NtupleMaker/ntupleQCD_Pt_1000to1400_10000.root
