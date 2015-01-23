
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
arguments=merged_ntuple_1 /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8/V07-02-02//merged_ntuple_1.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_pt1400to1800
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_2 /hadoop/cms/store/group/snt/phys14_old/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8/V07-02-02//merged_ntuple_2.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_qcd_pt1400to1800
queue

