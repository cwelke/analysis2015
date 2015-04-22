#!/bin/bash

function run () {
    echo root -b -q mergeHadoopFiles.C\(\"${HADOOPDIR}/${TAG}_$1/\",\"${OUTPUTDIR}/$1.root\"\)
    nohup nice -n 19 root -b -q mergeHadoopFiles.C\(\"${HADOOPDIR}/${TAG}_$1/\",\"${OUTPUTDIR}/$1.root\"\) >& log_merge_${TAG}_$1.txt &
}

TAG=V00-00-11

HADOOPDIR=/hadoop/cms/store/user/${USER}/dilepbabies/
OUTPUTDIR=/nfs-7/userdata/cwelke/ZMETbabies/$TAG/

mkdir -p $OUTPUTDIR
chmod -R a+wrx $OUTPUTDIR

#
# TTBAR
#

# run ttall_msdecays

#
# DY+JETS
#

# run dyjetsll_m50inc
# run dyjetsll_ht100to200
# run dyjetsll_ht200to400
# run dyjetsll_ht400to600
# run dyjetsll_ht600toinf
# run dyjetsmm_ptz180

#
# SINGLE TOP
#

run t_bars
run t_bart
run t_tops
run t_topt
run t_toptw
run t_bartw


#
# GAMMA + JETS
#

# run gjet_pt40_doubleEM
# run gjet_ht100to200
# run gjet_ht200to400
# run gjet_ht400to600
# run gjet_ht600toinf

#
# ALTERNATIVE TTBAR
#

#
# W+JETS
#

# run wjets_lnu
# run wjets_ht100to200
# run wjets_ht200to400
# run wjets_ht400to600
# run wjets_ht600toinf
# run wjets_enu
# run wjets_mnu

# #
# # Z INVISIBLE
# #

# run zinv_ht100to200
# run zinv_ht200to400
# run zinv_ht400to600
# run zinv_ht600toinf

#
# DIBOSON
#

run wz_3lnu
run zz_4l

#
# TRIBOSON
#

#
# TTV
#

run ttw
run ttz
run tth
