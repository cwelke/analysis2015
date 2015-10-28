#! /bin/bash

source ../settings.sh

# analysis_version=V07-04-03_goodtrigs

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_twojets_novtxweight\"              , 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_withb_twojets_novtxweight\"        , 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_with2_twojets_novtxweight\"        , 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_3jets_inclusive_novtxweight\"      , 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_withb_3jets_inclusive_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_with2_3jets_inclusive_novtxweight\", 1.0 )"

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_twojets_novtxweight\"              , 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_withb_twojets_novtxweight\"        , 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_with2_twojets_novtxweight\"        , 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_3jets_inclusive_novtxweight\"      , 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_withb_3jets_inclusive_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_with2_3jets_inclusive_novtxweight\", 1.0 )"

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMET_bveto_SRB_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMET_withb_SRB_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMET_bveto_SRA_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMET_withb_SRA_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMET_SR_ATLAS_novtxweight\" , 1.0 )"



lumi=1.264 # golden json
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"em\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ll\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"mm\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ee\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"em\", \"njets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ll\", \"njets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"mm\", \"njets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ee\", \"njets\",\"passtrig\" )"
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"em\", \"ptdil\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ll\", \"ptdil\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"mm\", \"ptdil\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ee\", \"ptdil\",\"passtrig\" )"

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR4lep\", \"em\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR4lep\", \"ll\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR4lep\", \"mm\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR4lep\", \"ee\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR4lep\", \"em\", \"njets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR4lep\", \"ll\", \"njets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR4lep\", \"mm\", \"njets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR4lep\", \"ee\", \"njets\",\"passtrig\" )"

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR4lep\", \"ll\", \"njtall\",\"passtrig\" )"
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR4lep\", \"ll\", \"metall\",\"passtrig\" )"

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ll\", \"njtall\",\"passtrig\" )"
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ll\", \"njtm50\",\"passtrig\" )"
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ll\", \"metall\",\"passtrig\" )"

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"em\", \"ht\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ll\", \"ht\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"mm\", \"ht\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ee\", \"ht\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"em\", \"ptdil\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ll\", \"ptdil\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"mm\", \"ptdil\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_CR3lep\", \"ee\", \"ptdil\",\"passtrig\" )"     


lumi=1.264 # golden json
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ll\", \"mll\",    \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ee\", \"mll\",    \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"mm\", \"mll\",    \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"em\", \"mll\",    \"passtrig\" )" 

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ll\", \"nVert\",    \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nVert\",    \"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ll\", \"met_raw\",    \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ll\", \"met_CORE\",    \"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",  \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_CORE\", \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\",      \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ll\", \"ht\",       \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\",    \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nbjets\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptdil\",    \"passtrig\" )"     

## PLOTS START HERE
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptdil\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\",     \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nbjets\",  \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",      \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mt3\",     \"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptdil\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll\",     \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"njets\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"nbjets\",  \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ht\",      \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mt3\",     \"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptdil\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll\",     \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"njets\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"nbjets\",  \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ht\",      \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mt3\",     \"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"mm\", \"met\",   \"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\"            , \"mm\", \"met_CORE\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"mm\", \"met_CORE\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\"            , \"mm\", \"met3p0_CORE\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"mm\", \"met3p0_CORE\",   \"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"ptl1\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"ptl2\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptl1\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptl2\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptl1\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptl2\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptl1\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptl2\",   \"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"ptdil\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll\",     \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"njets\",   \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"nbjets\",  \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"ht\",      \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mt3\",     \"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"met_CORE\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"met_raw\", \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_CORE\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\", \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met_CORE\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met_raw\", \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"met_CORE\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"met_raw\", \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"met\",\"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ht\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ht\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"njets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"njets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nbjets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"nbjets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"nbjets\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll\",\"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll\",\"passtrig\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\",     \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\",   \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nbjets\",  \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",      \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_CORE\",\"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\", \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mt3\",     \"threelep\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll\",     \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"njets\",   \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"nbjets\",  \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ht\",      \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met_CORE\",\"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met_raw\", \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mt3\",     \"threelep\" )"     

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll\",     \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"njets\",   \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"nbjets\",  \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ht\",      \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"met_CORE\",\"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"met_raw\", \"threelep\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mt3\",     \"threelep\" )"     

lumi=1.264 # golden json
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_central_twojets\"              , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_central_withb_twojets\"        , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_central_with2_twojets\"        , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_central_3jets_inclusive\"      , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_central_withb_3jets_inclusive\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_central_with2_3jets_inclusive\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_forward_twojets\"              , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_forward_withb_twojets\"        , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_forward_with2_twojets\"        , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_forward_3jets_inclusive\"      , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_forward_withb_3jets_inclusive\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_forward_with2_3jets_inclusive\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_bveto_SRA\"             , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_withb_SRA\"             , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_bveto_SRB\"             , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_withb_SRB\"             , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_SR_ATLAS\"              , \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"


# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",        \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met\",            \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_mettoolbox\", \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",        \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_CORE\",       \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nVert\",          \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptdil\",          \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",             \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\",          \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",        \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir\",        \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mt3\",            \"passtrig\" )"  &

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\",       \"threelep\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll\",       \"threelep\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll\",       \"threelep\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll\",       \"threelep\" )" 
