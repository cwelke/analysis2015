#!/bin/bash

#
# All MT2 related datasets available on hadoop
#

# compile files
cd ..
make -j25
cd -

# copy compiled files
cp -r ../*.so ../jetCorrections ../processBaby ../MVAinput ../../json/*.txt job_input/ 

source ../../ZMET2015/settings.sh 

# update tag
TAG=${analysis_version}

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_data/Run2015C_DoubleEG_MINIAOD_PromptReco-v1/merged/V07-04-08/     ${TAG}_data_25nsPrompt_ee
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_data/Run2015C_SinglePhoton_MINIAOD_PromptReco-v1/merged/V07-04-08/ ${TAG}_data_25nsPrompt_ph
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_data/Run2015C_DoubleMuon_MINIAOD_PromptReco-v1/merged/V07-04-08/   ${TAG}_data_25nsPrompt_mm
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_data/Run2015C_MuonEG_MINIAOD_PromptReco-v1/merged/V07-04-08/       ${TAG}_data_25nsPrompt_em

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_data/Run2015D_DoubleEG_MINIAOD_PromptReco-v3/merged/V07-04-09/     ${TAG}_data_2015D25nsPrompt_ee
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_data/Run2015D_SinglePhoton_MINIAOD_PromptReco-v3/merged/V07-04-09/ ${TAG}_data_2015D25nsPrompt_ph
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_data/Run2015D_DoubleMuon_MINIAOD_PromptReco-v3/merged/V07-04-09/   ${TAG}_data_2015D25nsPrompt_mm
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_data/Run2015D_MuonEG_MINIAOD_PromptReco-v3/merged/V07-04-09/       ${TAG}_data_2015D25nsPrompt_em

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-08/ ${TAG}_dyjetsll_25ns_m1050nlo
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3/V07-04-08/     ${TAG}_dyjetsll_25ns_m50nlo	 
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/TTTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-08/                                      ${TAG}_tt2lnu_25ns_php8

# # for closure studies
# # ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-07/      ${TAG}_zjetsll_25ns_m50mlm  
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/GJets_HT-40To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-04-08/     ${TAG}_gjets_25ns_ht40mlm  
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/GJets_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-04-08/    ${TAG}_gjets_25ns_ht100mlm  
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-04-08/    ${TAG}_gjets_25ns_ht200mlm  
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-08/    ${TAG}_gjets_25ns_ht400mlm  
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-08/    ${TAG}_gjets_25ns_ht600mlm  

# # ./writeConfig.sh /hadoop/cms/store/user/cwelke/run2_25ns/GJets_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-04-08/   ${TAG}_gjets_25ns_ht200mlm  
# ./writeConfig.sh /hadoop/cms/store/user/cwelke/run2_25ns/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-08/    ${TAG}_zjetsll_25ns_m50mlm  

./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-08/                        ${TAG}_wz3lnu_25ns_powp8  	 
./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/WWTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-08/                                            ${TAG}_ww2l2nu_25ns_powp8   
./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-08	 ${TAG}_sttwtop_25ns_powp8   
./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-08 ${TAG}_sttwatop_25ns_powp8  

# #
# # DATA
# #
# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/DoubleEG_Run2015B-PromptReco-v1/merged/     ${TAG}_data_50nsPrompt_ee
# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/SinglePhoton_Run2015B-PromptReco-v1/merged/ ${TAG}_data_50nsPrompt_ph
# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/DoubleMuon_Run2015B-PromptReco-v1/merged/   ${TAG}_data_50nsPrompt_mm
# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/MuonEG_Run2015B-PromptReco-v1/merged/       ${TAG}_data_50nsPrompt_em

# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/DoubleEG_Run2015B-17Jul2015-v1/merged/     ${TAG}_data_50ns17Jul_ee
# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/SinglePhoton_Run2015B-17Jul2015-v1/merged/ ${TAG}_data_50ns17Jul_ph
# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/DoubleMuon_Run2015B-17Jul2015-v1/merged/   ${TAG}_data_50ns17Jul_mm
# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/MuonEG_Run2015B-17Jul2015-v1/merged/       ${TAG}_data_50ns17Jul_em

# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/merged/ ${TAG}_dyjetsll_50ns_m1050nlo
# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/merged/     ${TAG}_dyjetsll_50ns_m50nlo	 
# ./writeConfig.sh /hadoop/cms/store/user/cwelke/CMS3_V07-04-07_updatestomettools/TTTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/merged/                                      ${TAG}_tt2lnu_50ns_php8


# # ./writeConfig.sh /hadoop/cms/store/group/snt/run2_data/Run2015B_SingleElectron_MINIAOD_PromptReco-v1/merged/V07-04-04/ ${TAG}_data_50ns_se
# # ./writeConfig.sh /hadoop/cms/store/group/snt/run2_data/Run2015B_SingleMuon_MINIAOD_PromptReco-v1/merged/V07-04-04/	   ${TAG}_data_50ns_sm

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/WZ_TuneCUETP8M1_13TeV-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/V07-04-03/                               ${TAG}_wz_50ns_incl			 
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/TTTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/V07-04-03/                                      ${TAG}_tt2lnu_50ns_php8		 
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-03/ ${TAG}_dyjetsll_50ns_m1050nlo
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/V07-04-03/     ${TAG}_dyjetsll_50ns_m50nlo	 
																																												                         
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-07/      ${TAG}_dyjetsll_50ns_m50mlm  
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-07/ ${TAG}_dyjetsll_50ns_m50mlmht100200
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-07/ ${TAG}_dyjetsll_50ns_m50mlmht200400
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-07/ ${TAG}_dyjetsll_50ns_m50mlmht400600  
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-07/ ${TAG}_dyjetsll_50ns_m50mlmht600inf  

# # ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-03/ ${TAG}_ttall_50ns_mgp8
# # ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-03/ ${TAG}_ttall_50ns_nlo
# # ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/TT_TuneCUETP8M1_13TeV-powheg-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v4/V07-04-03/ ${TAG}_ttall_50ns_php8


# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/  ${TAG}_dyjetsll_25ns_m1050nlo
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3/V07-04-03/      ${TAG}_dyjetsll_25ns_m50nlo

# # 50 ns samples
# ################################################

# #
# # TTBAR
# #

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-03/ ${TAG}_ttall_50ns_mgp8
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-03/ ${TAG}_ttall_50ns_nlo
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/TTTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/V07-04-03/ ${TAG}_tt2lnu_50ns_php8
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/TT_TuneCUETP8M1_13TeV-powheg-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v4/V07-04-03/ ${TAG}_ttall_50ns_php8

# #
# # SINGLE TOP
# #

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/V07-04-03/ ${TAG}_t_50ns_bartw
# # ./writeConfig.sh         ${TAG}_t_50ns_toptw

# #
# # DY+JETS
# #

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1/V07-04-03/ ${TAG}_dyjetsll_50ns_m1050nlo
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_13TeV-madgraph-pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08                   ${TAG}_dyjetsll_m50inc
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht100to200
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht200to400
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht400to600
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht600toinf
# # # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToMuMu_PtZ-180_M-50_13TeV-madgraph_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v3/V07-02-08             ${TAG}_dyjetsmm_ptz180


# #
# # DIBOSON
# #

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/WZ_TuneCUETP8M1_13TeV-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/V07-04-03/ ${TAG}_wzincl_50ns
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/WWTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/V07-04-03/        ${TAG}_ww2l2nu_50ns_php8
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_50ns/ZZ_TuneCUETP8M1_13TeV-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2/V07-04-03/ ${TAG}_zzincl_50ns_php8

# # #
# # # GAMMA + JETS
# # #

# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/GJet_Pt40_doubleEMEnriched_TuneZ2star_13TeV-pythia6_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_gjet_pt40_doubleEM
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/GJets_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08      ${TAG}_gjet_ht100to200
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/GJets_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08      ${TAG}_gjet_ht200to400
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/GJets_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08      ${TAG}_gjet_ht400to600
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/GJets_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08      ${TAG}_gjet_ht600toinf

# # #
# # # TTV
# # #

# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TTWJets_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08           ${TAG}_ttw
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TTZJets_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08           ${TAG}_ttz
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TTbarH_M-125_13TeV_amcatnlo-pythia8-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v2/V07-02-08 ${TAG}_tth

# # 25 ns samples
# ################################################

# #
# # TTBAR
# #

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-04-03/  ${TAG}_ttall_25ns_mgp8
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/ ${TAG}_ttall_25ns_nlo
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/TTTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/                         ${TAG}_tt2lnu_25ns_php8
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/TT_TuneCUETP8M1_13TeV-powheg-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/V07-04-03/           ${TAG}_ttall_25ns_php8
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/TT_TuneZ2star_13TeV-powheg-pythia6-tauola_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/      ${TAG}_ttall_25ns_php6tauola

# #
# # SINGLE TOP
# #

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/ ${TAG}_tincl_25ns_bartw_php8
# # ./writeConfig.sh         ${TAG}_t_50ns_toptw

# #
# # DY+JETS
# #

# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_13TeV-madgraph-pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08                   ${TAG}_dyjetsll_m50inc
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht100to200
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht200to400
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht400to600
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht600toinf
# # # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToMuMu_PtZ-180_M-50_13TeV-madgraph_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v3/V07-02-08             ${TAG}_dyjetsmm_ptz180


# #
# # DIBOSON
# #

# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/WZ_TuneCUETP8M1_13TeV-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/ ${TAG}_wzincl_25ns
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/WWTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/V07-04-03/         ${TAG}_ww2l2nu_25ns_php8
# ./writeConfig.sh /hadoop/cms/store/group/snt/run2_25ns/ZZ_TuneCUETP8M1_13TeV-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3/V07-04-03/  ${TAG}_zzincl_25ns_php8

# # #
# # # VH
# # #

# # # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/WH_HToBB_WToLNu_M-125_13TeV_powheg-herwigpp_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-03 ${TAG}_wh_lnubb

# # #
# # # SIGNAL
# # #

# # # /hadoop/cms/store/group/snt/phys14/SMS-T1bbbb_2J_mGl-1000_mLSP-900_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T1bbbb_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T1qqqq_2J_mGl-1000_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T1qqqq_2J_mGl-1400_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T2bb_2J_mStop-600_mLSP-580_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T2bb_2J_mStop-900_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T2qq_2J_mStop-1200_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T2qq_2J_mStop-600_mLSP-550_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T2tt_2J_mStop-425_mLSP-325_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T2tt_2J_mStop-500_mLSP-325_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T2tt_2J_mStop-650_mLSP-325_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # # /hadoop/cms/store/group/snt/phys14/SMS-T2tt_2J_mStop-850_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1


# --- write submit script ---
mkdir -p configs_${TAG}

mv condor_${TAG}*.cmd configs_${TAG}
echo "#!/bin/bash" > submitAll.sh
echo "voms-proxy-init -voms cms -valid 240:00" >> submitAll.sh
for file in configs_${TAG}/*.cmd
do 
    echo "condor_submit ${file}" >> submitAll.sh
done
chmod +x submitAll.sh
echo "[writeAllConfig] wrote submit script submitAll.sh"
