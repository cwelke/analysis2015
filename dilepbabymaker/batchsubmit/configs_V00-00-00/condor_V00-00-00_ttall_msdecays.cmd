
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
arguments=merged_ntuple_1 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_1.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_10 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_10.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_100 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_100.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_101 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_101.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_102 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_102.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_103 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_103.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_104 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_104.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_105 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_105.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_106 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_106.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_107 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_107.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_108 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_108.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_109 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_109.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_11 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_11.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_110 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_110.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_111 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_111.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_112 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_112.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_113 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_113.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_114 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_114.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_115 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_115.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_116 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_116.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_117 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_117.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_118 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_118.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_119 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_119.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_12 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_12.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_120 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_120.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_121 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_121.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_122 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_122.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_123 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_123.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_124 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_124.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_125 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_125.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_126 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_126.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_127 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_127.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_128 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_128.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_129 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_129.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_13 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_13.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_130 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_130.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_131 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_131.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_132 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_132.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_133 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_133.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_134 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_134.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_135 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_135.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_136 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_136.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_137 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_137.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_138 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_138.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_139 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_139.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_14 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_14.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_140 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_140.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_141 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_141.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_142 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_142.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_143 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_143.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_144 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_144.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_145 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_145.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_146 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_146.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_147 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_147.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_148 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_148.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_149 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_149.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_15 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_15.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_150 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_150.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_151 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_151.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_152 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_152.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_153 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_153.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_154 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_154.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_155 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_155.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_156 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_156.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_157 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_157.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_158 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_158.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_159 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_159.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_16 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_16.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_160 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_160.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_161 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_161.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_162 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_162.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_163 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_163.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_164 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_164.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_165 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_165.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_166 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_166.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_167 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_167.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_168 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_168.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_169 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_169.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_17 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_17.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_170 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_170.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_171 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_171.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_172 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_172.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_173 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_173.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_174 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_174.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_175 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_175.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_176 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_176.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_177 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_177.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_178 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_178.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_179 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_179.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_18 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_18.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_180 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_180.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_181 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_181.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_182 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_182.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_183 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_183.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_184 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_184.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_185 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_185.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_186 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_186.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_187 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_187.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_188 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_188.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_189 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_189.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_19 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_19.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_190 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_190.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_191 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_191.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_192 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_192.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_193 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_193.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_194 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_194.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_195 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_195.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_196 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_196.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_197 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_197.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_198 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_198.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_2 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_2.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_20 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_20.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_21 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_21.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_22 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_22.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_23 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_23.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_24 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_24.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_25 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_25.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_26 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_26.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_27 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_27.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_28 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_28.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_29 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_29.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_3 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_3.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_30 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_30.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_31 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_31.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_32 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_32.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_33 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_33.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_34 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_34.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_35 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_35.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_36 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_36.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_37 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_37.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_38 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_38.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_39 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_39.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_4 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_4.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_40 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_40.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_41 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_41.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_42 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_42.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_43 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_43.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_44 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_44.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_45 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_45.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_46 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_46.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_47 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_47.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_48 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_48.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_49 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_49.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_5 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_5.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_50 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_50.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_51 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_51.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_52 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_52.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_53 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_53.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_54 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_54.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_55 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_55.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_56 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_56.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_57 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_57.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_58 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_58.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_59 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_59.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_6 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_6.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_60 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_60.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_61 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_61.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_62 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_62.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_63 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_63.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_64 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_64.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_65 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_65.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_66 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_66.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_67 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_67.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_68 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_68.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_69 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_69.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_7 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_7.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_70 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_70.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_71 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_71.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_72 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_72.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_73 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_73.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_74 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_74.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_75 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_75.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_76 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_76.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_77 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_77.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_78 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_78.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_79 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_79.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_8 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_8.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_80 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_80.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_81 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_81.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_82 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_82.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_83 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_83.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_84 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_84.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_85 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_85.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_86 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_86.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_87 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_87.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_88 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_88.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_89 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_89.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_9 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_9.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_90 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_90.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_91 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_91.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_92 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_92.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_93 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_93.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_94 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_94.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_95 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_95.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_96 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_96.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_97 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_97.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_98 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_98.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue


executable=wrapper.sh
transfer_executable=True
arguments=merged_ntuple_99 /hadoop/cms/store/group/snt/phys14_old/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola/V07-02-02//merged_ntuple_99.root /hadoop/cms/store/user/cwelke/dilepbabies/V00-00-00_ttall_msdecays
queue

