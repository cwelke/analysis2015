
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
arguments=merged_ntuple_1 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_1.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_10 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_10.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_11 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_11.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_12 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_12.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_13 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_13.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_2 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_2.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_3 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_3.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_4 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_4.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_5 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_5.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_6 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_6.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_7 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_7.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_8 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_8.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_9 /hadoop/cms/store/group/snt/phys14_old/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2/CMS3_V07-02-02//merged_ntuple_9.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_ht250to500
queue

