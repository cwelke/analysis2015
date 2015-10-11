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


# run zjetsll_25ns_m50mlm  
# run zjetsllht100_25ns_m50mlm  
# run zjetsllht200_25ns_m50mlm  
# run zjetsllht400_25ns_m50mlm  
# run zjetsllht600_25ns_m50mlm  
# run gjets_25ns_ht40mlm  
# run gjets_25ns_ht100mlm  
# run gjets_25ns_ht200mlm  
# run gjets_25ns_ht400mlm  
# run gjets_25ns_ht600mlm  

run data_2015D25nsPrompt_ee
run data_2015D25nsPrompt_ph
run data_2015D25nsPrompt_mm
run data_2015D25nsPrompt_em

# run wz2l2q_25ns_nlo  
# run zz2l2q_25ns_nlo  
# run zz4l_25ns_php8  

# run wwz_25ns_nlo  
# run zzz_25ns_nlo  

# run data_25nsPrompt_ee
# run data_25nsPrompt_ph
# run data_25nsPrompt_mm
# run data_25nsPrompt_em

# run data_2015D25nsPrompt_ee
# run data_2015D25nsPrompt_ph
# run data_2015D25nsPrompt_mm
# run data_2015D25nsPrompt_em

# run dyjetsll_25ns_m1050nlo
# run dyjetsll_25ns_m50nlo	 
# run tt2lnu_25ns_php8

# run wz3lnu_25ns_powp8  	 
# run ww2l2nu_25ns_powp8   
# run sttwtop_25ns_powp8   
# run sttwatop_25ns_powp8  

# run ttwlnu_25ns_nlo 
# run ttw2q_25ns_nlo 
# run wzz_25ns_nlo  
# run ttg_25ns_nlo  
# run ttzqq_25ns_nlo  
# run ttzllnunu_25ns_nlo  

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

