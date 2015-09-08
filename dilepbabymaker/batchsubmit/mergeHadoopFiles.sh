#!/bin/bash

function run () {
    echo root -b -q mergeHadoopFiles.C\(\"${HADOOPDIR}/${TAG}_$1/\",\"${OUTPUTDIR}/$1.root\"\)
    nohup nice -n 19 root -b -q mergeHadoopFiles.C\(\"${HADOOPDIR}/${TAG}_$1/\",\"${OUTPUTDIR}/$1.root\"\) >& merge_logs_${TAG}/log_merge_$1.txt &
}

source ../../ZMET2015/settings.sh 

TAG=${analysis_version}

HADOOPDIR=/hadoop/cms/store/user/${USER}/dilepbabies/
OUTPUTDIR=/nfs-6/userdata/cwelke/ZMETbabies/$TAG/

mkdir -p $OUTPUTDIR
chmod -R a+wrx $OUTPUTDIR

if [ ! -d "merge_logs_${TAG}" ]; then
  mkdir merge_logs_${TAG}
fi


run data_25nsPrompt_ee
run data_25nsPrompt_ph
run data_25nsPrompt_mm
run data_25nsPrompt_em

run dyjetsll_25ns_m1050nlo
run dyjetsll_25ns_m50nlo	 
run tt2lnu_25ns_php8
run zjetsll_25ns_m50mlm  
run gjets_25ns_ht40mlm  
run gjets_25ns_ht100mlm  
run gjets_25ns_ht200mlm  
run gjets_25ns_ht400mlm  
run gjets_25ns_ht600mlm  

# # done
# run data_50nsPrompt_ee
# run data_50nsPrompt_ph
# run data_50nsPrompt_mm
# run data_50nsPrompt_em

# run data_50ns17Jul_ee
# run data_50ns17Jul_ph
# run data_50ns17Jul_mm
# run data_50ns17Jul_em

# run tt2lnu_50ns_php8		 
# run dyjetsll_50ns_m1050nlo
# run dyjetsll_50ns_m50nlo	 

# run wz_50ns_incl			 

#to do
# run dyjetsll_50ns_m50mlm  
# run dyjetsll_50ns_m50mlmht100200
# run dyjetsll_50ns_m50mlmht200400
# run dyjetsll_50ns_m50mlmht400600
# run dyjetsll_50ns_m50mlmht600inf

# #
# # TTBAR
# #

# run ttall_msdecays

# # # #
# # # # DY+JETS
# # # #

# run dyjetsll_m50inc
# run dyjetsll_ht100to200
# run dyjetsll_ht200to400
# run dyjetsll_ht400to600
# run dyjetsll_ht600toinf
# # # run dyjetsmm_ptz180

# # #
# # # SINGLE TOP
# # #

# # run t_bars
# # run t_bart
# # run t_tops
# # run t_topt
# run t_toptw
# run t_bartw


# #
# # GAMMA + JETS
# #

# # run gjet_pt40_doubleEM
# run gjet_ht100to200
# run gjet_ht200to400
# run gjet_ht400to600
# run gjet_ht600toinf

# # #
# # # ALTERNATIVE TTBAR
# # #

# # #
# # # W+JETS
# # #

# # # run wjets_lnu
# # # run wjets_ht100to200
# # # run wjets_ht200to400
# # # run wjets_ht400to600
# # # run wjets_ht600toinf
# # # run wjets_enu
# # # run wjets_mnu

# # # #
# # # # Z INVISIBLE
# # # #

# # # run zinv_ht100to200
# # # run zinv_ht200to400
# # # run zinv_ht400to600
# # # run zinv_ht600toinf

# #
# # DIBOSON
# #

# run wz_3lnu
# run zz_4l

# # #
# # # TRIBOSON
# # #

# # #
# # # TTV
# # #

# run ttw
# run ttz
# run tth
