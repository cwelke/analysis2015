#!/bin/bash

make -j5
didcompile=$?

if [ ! $didcompile == "0" ]; then
	echo "did not compile. exiting."
	exit $didcompile
fi

cp ../json/json_270715_golden.txt .

# ./processBaby test  /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-03/merged_ntuple_1.root
# ./processBaby test_mc /hadoop/cms/store/group/snt/run2_25ns/TTTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-08///merged_ntuple_1.root

# ./processBaby test_mc_old /hadoop/cms/store/group/snt/run2_25ns/GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-04-07/merged_ntuple_1.root

# ./processBaby test_data /hadoop/cms/store/group/snt/run2_data/Run2015C_DoubleEG_MINIAOD_PromptReco-v1/merged/V07-04-08/merged_ntuple_1.root

./processBaby data_ee_missing /hadoop/cms/store/group/snt/run2_data/Run2015C_DoubleEG_MINIAOD_PromptReco-v1/merged/V07-04-08/merged_ntuple_88.root 

# ./processBaby test_withnewrho /home/users/cwelke/MCNtupling/CMSSW_7_4_7_patch2_V07-04-08_dev/src/ntuple_postp.root

