#!/bin/bash

#
# All MT2 related datasets available on hadoop
#

# compile files
cd ..
make -j25
cd -

# copy compiled files
cp -r ../*.so ../jetCorrections ../processBaby.C job_input/

source ../../ZMET2015/settings.sh 

# update tag
TAG=${analysis_version}

#
# DATA
#

#
# TTBAR
#

# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TT_Tune4C_13TeV-pythia8-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-03                      ${TAG}_ttall
./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_ttall_msdecays

# #
# # DY+JETS
# #

./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_13TeV-madgraph-pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08                   ${TAG}_dyjetsll_m50inc
./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht100to200
./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht200to400
./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht400to600
./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_dyjetsll_ht600toinf
# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/DYJetsToMuMu_PtZ-180_M-50_13TeV-madgraph_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v3/V07-02-08             ${TAG}_dyjetsmm_ptz180

# #
# # SINGLE TOP
# #

# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TBarToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_t_bars
# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TBarToLeptons_t-channel_Tune4C_CSA14_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_t_bart
# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08    ${TAG}_t_tops
# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TToLeptons_t-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08    ${TAG}_t_topt
./writeConfig.sh /hadoop/cms/store/group/snt/phys14/T_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08           ${TAG}_t_toptw
./writeConfig.sh /hadoop/cms/store/group/snt/phys14/Tbar_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08        ${TAG}_t_bartw

# # #
# # # GAMMA + JETS
# # #

# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/GJet_Pt40_doubleEMEnriched_TuneZ2star_13TeV-pythia6_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_gjet_pt40_doubleEM
# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/GJets_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08      ${TAG}_gjet_ht100to200
# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/GJets_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08      ${TAG}_gjet_ht200to400
# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/GJets_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08      ${TAG}_gjet_ht400to600
# ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/GJets_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08      ${TAG}_gjet_ht600toinf

# #
# # ALTERNATIVE TTBAR
# #

# #
# # W+JETS
# #

# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/WJetsToLNu_13TeV-madgraph-pythia8-tauola/V07-02-05                                              ${TAG}_wjets_lnu
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/WJetsToLNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-03 ${TAG}_wjets_ht100to200
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/WJetsToLNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-03 ${TAG}_wjets_ht200to400
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/WJetsToLNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-03 ${TAG}_wjets_ht400to600
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/WJetsToLNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-03 ${TAG}_wjets_ht600toinf
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/WToENu_Tune4C_13TeV-pythia8_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-03                     ${TAG}_wjets_enu
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/WToMuNu_Tune4C_13TeV-pythia8_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/CMS3_v07-02-03               ${TAG}_wjets_mnu

# # #
# # # Z INVISIBLE
# # #

# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/ZJetsToNuNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-05 ${TAG}_zinv_ht100to200
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/ZJetsToNuNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-03 ${TAG}_zinv_ht200to400
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/ZJetsToNuNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v2/V07-02-03 ${TAG}_zinv_ht400to600
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/ZJetsToNuNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-03 ${TAG}_zinv_ht600toinf

# #
# # DIBOSON
# #

./writeConfig.sh /hadoop/cms/store/group/snt/phys14/WZJetsTo3LNu_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08 ${TAG}_wz_3lnu
./writeConfig.sh /hadoop/cms/store/group/snt/phys14/ZZTo4L_Tune4C_13TeV-powheg-pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08        ${TAG}_zz_4l

# #
# # TRIBOSON
# #

# #
# # TTV
# #

./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TTWJets_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08           ${TAG}_ttw
./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TTZJets_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-08           ${TAG}_ttz
./writeConfig.sh /hadoop/cms/store/group/snt/phys14/TTbarH_M-125_13TeV_amcatnlo-pythia8-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v2/V07-02-08 ${TAG}_tth

# #
# # QCD
# #

# # /hadoop/cms/store/group/snt/phys14/QCD_HT-100To250_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_HT-500To1000_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_HT-500To1000_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_HT_1000ToInf_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_HT_1000ToInf_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-1000to1400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-10to20_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-120to170_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-15to3000_Tune4C_Flat_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-15to30_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-1800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-1800to2400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v2
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-20to30_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v2
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-2400to3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-300to470_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-30to50_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-30to80_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-470to600_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-50to80_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-5to10_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-600to800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-800to1000_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-80to120_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt-80to170_EMEnriched_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_castor_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt_170toInf_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt_30to80_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/QCD_Pt_80to170_bcToE_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_PHYS14_25_V1-v2

# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-30to50_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/CMS3_V07-02-02/ ${TAG}_qcd_pt30to50
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-50to80_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/CMS3_V07-02-02/ ${TAG}_qcd_pt50to80
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-80to120_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2/CMS3_V07-02-02/ ${TAG}_qcd_pt80to120
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-120to170_Tune4C_13TeV_pythia8/V07-02-02/ ${TAG}_qcd_pt120to170
# # #./writeConfig.sh /hadoop/cms/store/group/snt/ ${TAG}_qcd_pt170to300
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-300to470_Tune4C_13TeV_pythia8/V07-02-02/ ${TAG}_qcd_pt300to470
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-470to600_Tune4C_13TeV_pythia8/V07-02-02/ ${TAG}_qcd_pt470to600
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-600to800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1/CMS3_V07-02-02/ ${TAG}_qcd_pt600to800
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-800to1000_Tune4C_13TeV_pythia8/V07-02-02/ ${TAG}_qcd_pt800to1000
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-1000to1400_Tune4C_13TeV_pythia8/V07-02-02/ ${TAG}_qcd_pt1000to1400
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8/V07-02-02/ ${TAG}_qcd_pt1400to1800
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-1800to2400_Tune4C_13TeV_pythia8/V07-02-02/ ${TAG}_qcd_pt1800to2400
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-2400to3200_Tune4C_13TeV_pythia8/V07-02-02/ ${TAG}_qcd_pt2400to3200
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-3200_Tune4C_13TeV_pythia8/V07-02-02/ ${TAG}_qcd_pt3200

# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_HT-100To250_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_qcd_ht100to250
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02/ ${TAG}_qcd_ht250to500
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_HT-500To1000_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1/CMS3_V07-02-02/ ${TAG}_qcd_ht500to1000
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/QCD_HT_1000ToInf_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1/CMS3_V07-02-02/ ${TAG}_qcd_ht1000

# #
# # VH
# #

# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14/WH_HToBB_WToLNu_M-125_13TeV_powheg-herwigpp_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-03 ${TAG}_wh_lnubb

# #
# # SIGNAL
# #

# # /hadoop/cms/store/group/snt/phys14/SMS-T1bbbb_2J_mGl-1000_mLSP-900_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T1bbbb_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T1qqqq_2J_mGl-1000_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T1qqqq_2J_mGl-1400_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T2bb_2J_mStop-600_mLSP-580_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T2bb_2J_mStop-900_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T2qq_2J_mStop-1200_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T2qq_2J_mStop-600_mLSP-550_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T2tt_2J_mStop-425_mLSP-325_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T2tt_2J_mStop-500_mLSP-325_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T2tt_2J_mStop-650_mLSP-325_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1
# # /hadoop/cms/store/group/snt/phys14/SMS-T2tt_2J_mStop-850_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1

# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T1tttt_1500_100
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T1tttt_1200_800
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T1qqqq_2J_mGl-1400_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T1qqqq_1400_100
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T1qqqq_2J_mGl-1000_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T1qqqq_1000_800
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T1bbbb_2J_mGl-1000_mLSP-900_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T1bbbb_1000_900
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T1bbbb_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T1bbbb_1500_100
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T2tt_2J_mStop-425_mLSP-325_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T2tt_425_325
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T2tt_2J_mStop-500_mLSP-325_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T2tt_500_325
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T2tt_2J_mStop-650_mLSP-325_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T2tt_650_325
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T2tt_2J_mStop-850_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T2tt_850_100
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T2bb_2J_mStop-900_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T2bb_900_100
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T2bb_2J_mStop-600_mLSP-580_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1/V07-02-02/ ${TAG}_T2bb_600_580
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T2qq_2J_mStop-1200_mLSP-100_Tune4C_13TeV-madgraph-tauola/V07-02-02/ ${TAG}_T2qq_1200_100
# # ./writeConfig.sh /hadoop/cms/store/group/snt/phys14_old/SMS-T2qq_2J_mStop-600_mLSP-550_Tune4C_13TeV-madgraph-tauola/V07-02-02/ ${TAG}_T2qq_600_550


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
