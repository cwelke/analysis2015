
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

