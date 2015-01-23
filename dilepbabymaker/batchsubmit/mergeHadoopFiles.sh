#!/bin/bash

function run () {
    echo root -b -q mergeHadoopFiles.C\(\"${HADOOPDIR}/${TAG}_$1/\",\"${OUTPUTDIR}/$1.root\"\)
    nohup nice -n 19 root -b -q mergeHadoopFiles.C\(\"${HADOOPDIR}/${TAG}_$1/\",\"${OUTPUTDIR}/$1.root\"\) >& log_merge_${TAG}_$1.txt &
}

TAG=V00-00-08

HADOOPDIR=/hadoop/cms/store/user/${USER}/mt2babies/
OUTPUTDIR=/nfs-6/userdata/mt2/$TAG/

mkdir -p $OUTPUTDIR
chmod -R a+wrx $OUTPUTDIR

#
# TTBAR
#

run ttall_msdecays

#
# ALTERNATIVE TTBAR
#

#
# W+JETS
#

run wjets_ht100to200
run wjets_ht200to400
run wjets_ht400to600
run wjets_ht600toInf

#
# SINGLE TOP
#

#
# DY+JETS
#

run dyjetsll_ht100to200
run dyjetsll_ht200to400
run dyjetsll_ht400to600
run dyjetsll_ht600toInf


#
# GAMMA + JETS
#

#run gjet_pt15to3000
run gjet_ht100to200
run gjet_ht200to400
run gjet_ht400to600
run gjet_ht600toInf

#
# Z INVISIBLE
#

run zinv_ht100to200
run zinv_ht200to400
run zinv_ht400to600
run zinv_ht600toInf

#
# DIBOSON
#

#
# TRIBOSON
#

#
# TTV
#

run ttw
run ttz

#
# QCD
#

run qcd_pt30to50
run qcd_pt50to80
run qcd_pt80to120
run qcd_pt120to170
run qcd_pt170to300
run qcd_pt300to470
run qcd_pt470to600
run qcd_pt600to800
run qcd_pt800to1000
run qcd_pt1000to1400
run qcd_pt1400to1800
run qcd_pt1800to2400
run qcd_pt2400to3200
run qcd_pt3200

run qcd_ht100to250
run qcd_ht250to500
run qcd_ht500to1000
run qcd_ht1000

#
# SIGNAL
#

run T1tttt_1500_100
run T1tttt_1200_800
run T1qqqq_1400_100
run T1qqqq_1000_800
run T1bbbb_1000_900
run T1bbbb_1500_100
run T2tt_425_325
run T2tt_500_325
run T2tt_650_325
run T2tt_850_100
run T2bb_900_100
run T2bb_600_580
run T2qq_1200_100
run T2qq_600_550





