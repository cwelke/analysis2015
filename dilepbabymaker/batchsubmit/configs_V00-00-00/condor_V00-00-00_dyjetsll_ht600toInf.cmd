
universe=vanilla
when_to_transfer_output = ON_EXIT
#the actual executable to run is not transfered by its name.
#In fact, some sites may do weird things like renaming it and such.
transfer_input_files=wrapper.sh, job_input/input.tar.gz
+DESIRED_Sites="UCSD"
+Owner = undefined
log=/home/users/cwelke/analysis2015/MT2Analysis/dilepbabymaker/batchsubmit/submit_logs/condor_01_22_2015.log
output=/home/users/cwelke/analysis2015/MT2Analysis/dilepbabymaker/batchsubmit/job_logs/1e.$(Cluster).$(Process).out
error =/home/users/cwelke/analysis2015/MT2Analysis/dilepbabymaker/batchsubmit/job_logs/1e.$(Cluster).$(Process).err
notification=Never
x509userproxy=/tmp/x509up_u31113


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_1 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_1.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_10 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_10.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_11 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_11.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_12 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_12.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_13 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_13.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_14 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_14.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_15 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_15.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_16 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_16.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_17 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_17.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_18 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_18.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_19 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_19.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_2 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_2.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_20 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_20.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_21 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_21.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_22 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_22.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_23 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_23.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_24 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_24.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_25 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_25.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_26 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_26.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_27 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_27.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_28 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_28.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_29 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_29.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_3 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_3.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_30 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_30.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_31 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_31.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_32 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_32.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_33 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_33.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_4 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_4.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_5 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_5.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_6 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_6.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_7 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_7.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_8 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_8.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_9 /hadoop/cms/store/group/snt/phys14_old/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1/CMS3_V07-02-02//merged_ntuple_9.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_dyjetsll_ht600toInf
queue

