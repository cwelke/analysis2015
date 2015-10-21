#! /bin/bash

source ../settings.sh

# analysis_version=V07-04-03_goodtrigs

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

# lumi=0.540 # golden json
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",     \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_CORE\",    \"passtrig\" )" &    


# root -b -q "compareMET.cc+( \"$analysis_version\", \"_inclusive\", 2.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMETNoHF\", 2.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_T1MET\", 2.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_METNoHF\", 2.0 )"

root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_twojets_novtxweight\", 1.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_withb_twojets_novtxweight\", 1.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_with2_twojets_novtxweight\", 1.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_3jets_inclusive_novtxweight\", 1.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_withb_3jets_inclusive_novtxweight\", 1.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", \"_central_with2_3jets_inclusive_novtxweight\", 1.0 )"

root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_twojets_novtxweight\", 1.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_withb_twojets_novtxweight\", 1.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_with2_twojets_novtxweight\", 1.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_3jets_inclusive_novtxweight\", 1.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_withb_3jets_inclusive_novtxweight\", 1.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", \"_forward_with2_3jets_inclusive_novtxweight\", 1.0 )"

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_inclusive_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_3jets_inclusive_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMET_bveto_SRB_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMET_withb_SRB_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMET_bveto_SRA_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMET_withb_SRA_novtxweight\", 1.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_rawMET_SR_ATLAS_novtxweight\" , 1.0 )"

# lumi=0.116 # golden json
# lumi=0.209 # golden json

# lumi=0.540 # golden json
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\",       \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll\",       \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll\",       \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll\",       \"passtrig\" )"     
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",       \"passtrig\" )"     


# # lumi=0.480 # golden json
# lumi=0.540 # golden json
# # # lumi=2. # golden json
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_3jets_inclusive\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_bveto_SRB\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_bveto_SRA\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_withb_SRB\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_withb_SRA\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_SR_ATLAS\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  

lumi=0.134 # golden json
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\",       \"passtrig\" )"  
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll\",       \"passtrig\" )"  

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metRaw_TopDiscovery\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metT-1_TopDiscovery\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_3jets_inclusive\", \"ll\", \"metRaw_TopDiscovery\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_3jets_inclusive\", \"ll\", \"metT-1_TopDiscovery\",       \"passtrig\" )"  

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"metRaw_TopDiscovery\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"metT-1_TopDiscovery\",       \"passtrig\" )"  

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_bveto_SRB\", \"em\", \"mll\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_bveto_SRA\", \"em\", \"mll\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_withb_SRB\", \"em\", \"mll\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_withb_SRA\", \"em\", \"mll\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_SR_ATLAS\",  \"em\", \"mll\",       \"passtrig\" )"  

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_bveto_SRB\", \"em\", \"mll\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_bveto_SRA\", \"em\", \"mll\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_withb_SRB\", \"em\", \"mll\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_withb_SRA\", \"em\", \"mll\",       \"passtrig\" )"  


# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET\", \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_T1MET\",  \"ll\", \"met_rawgt1jet\",       \"passtrig\" )"  &

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_bveto_SRB\", \"em\", \"mll\",       \"passtrig\" )" 	   
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_bveto_SRA\", \"em\", \"mll\",       \"passtrig\" )" 	   
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_withb_SRB\", \"em\", \"mll\",       \"passtrig\" )" 	   
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_withb_SRA\", \"em\", \"mll\",       \"passtrig\" )" 	   
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_rawMET_SR_ATLAS\", \"em\", \"mll\",       \"passtrig\" )" 	   

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"nVert\",       \"passtrig\" )" 	   
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"nVert\",       \"passtrig\" )" 	   

# # lumi=0.225 # golden json
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\",       \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll\",       \"passtrig\" )" 	   
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll\",       \"passtrig\" )" 	   
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll\",       \"passtrig\" )" 	   

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"njets\",       \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\",       \"passtrig\" )" &    
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nbjets\",      \"passtrig\" )" &    
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",          \"passtrig\" )" &    
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met\",            \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_mettoolbox\", \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",     \"passtrig\" )" &    
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_CORE\",    \"passtrig\" )" &    

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptl1\",       \"passtrig\" )"     
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptl2\",       \"passtrig\" )" &    
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptl1\",       \"passtrig\" )" &    
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptl2\",       \"passtrig\" )" &    
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptl1\",       \"passtrig\" )" &    
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptl2\",       \"passtrig\" )" &

# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nbjets\",       \"passtrig\" )"  &
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\",       \"passtrig\" )"   &
																													   
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",       \"passtrig\" )" 	   &
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",       \"passtrig\" )" &

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptl1\",       \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptl2\",       \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptl1\",       \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptl2\",       \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptl1\",       \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptl2\",       \"passtrig\" )" &

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll_metrawgt50\",       \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll_metrawgt100\",       \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll_metrawgt150\",       \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll_metrawgt225\",       \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll_metrawgt300\",       \"passtrig\" )" &

# lumi=0.0204 # golden json
# # lumi=0.001

lumi=0.0403 # golden json

# lumi=0.150 # golden json
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ll\", \"mll\",       \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ee\", \"mll\",       \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"mm\", \"mll\",       \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"em\", \"mll\",       \"passtrig\" )" 

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ll\", \"met\",         \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ll\", \"met_raw\",     \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ll\", \"met_CORE\",    \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive_novtxweight\", \"ll\", \"nVert\",    \"passtrig\" )"  &

# lumi=0.510 # golden json
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\",       \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll\",       \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll\",       \"passtrig\" )" 
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nbjets\",          \"passtrig\" )"  &

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

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",        \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met\",            \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_mettoolbox\", \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",        \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_CORE\",       \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nVert\",          \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptdil\",          \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",             \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\",          \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",        \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir\",        \"threelep\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mt3\",            \"threelep\" )"  &

lumi=0.1544 # mumu
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll_metlt1\",       \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll_metgt1\",       \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll_metlt1\",       \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll_metgt1\",       \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll_metlt1\",       \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll_metgt1\",       \"passtrig\" )" 

lumi=0.1478 # ee
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met\",         \"passtrig\" )"  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_CORE\",    \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met3p0_CORE\", \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphi\",      \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",     \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir\",     \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metx\",       \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mety\",       \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptdil\",     \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",        \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\",     \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met3p0_raw\",     \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met3p0_raw_phi\",     \"passtrig\" )"  &

lumi=0.1517 # ll
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met3p5_pt\",     \"passtrig\" )"  &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met3p5_phi\",     \"passtrig\" )"  &

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nVert\",       \"passtrig\" )" 

# lumi=0.0148 # electrons
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"nVert\",       \"passtrig\" )" &

# lumi=0.0155 # muons
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"nVert\",       \"passtrig\" )" &

# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_ptlt1\", \"passtrig\" )"  &
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",       \"passtrig\" )"  &

# # # lumi=0.0148 # golden json
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptdil\",    \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ht\",       \"passtrig\" )"  &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"njets\",    \"passtrig\" )"  &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll\",      \"passtrig\" )"  &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"met_raw\",  \"passtrig\" )"  &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"metphir\",  \"passtrig\" )"  &

# # # lumi=0.0155 # golden json
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptdil\",     \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ht\",        \"passtrig\" )"  &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"njets\",     \"passtrig\" )"  &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll\",       \"passtrig\" )"  &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met_raw\",   \"passtrig\" )"  &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"metphir\",   \"passtrig\" )"  &

# # lumi=0.042 # golden json
# # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"ll\", \"ptdil\",       \"passtrig\" )" 
# # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"ll\", \"ht\",       \"passtrig\" )" &
# # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"ll\", \"njets\",       \"passtrig\" )" &
# # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"ll\", \"mll\",       \"passtrig\" )" &
# # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",       \"passtrig\" )" &
# # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"ll\", \"metphir\",       \"passtrig\" )" &

# # # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"mm\", \"ptdil\",       \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"mm\", \"ht\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"mm\", \"njets\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"mm\", \"mll\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"mm\", \"met_raw\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"V07-04-07\", $lumi, \"_inclusive\", \"mm\", \"metphir\",       \"passtrig\" )" &

# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\",       \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll\",       \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll\",       \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll\",       \"passtrig\" )" 


# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",              \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ht\",              \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ht\",              \"passtrig\" )" &

# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\",              \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"njets\",              \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"njets\",              \"passtrig\" )" &

# # # lumi=0.0173
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\",           \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met\",               \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphi\",            \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir\",           \"passtrig\" )" &

# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_pt0\",       \"passtrig\" )" &
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_pt0\",       \"passtrig\" )" &
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_pt1\",       \"passtrig\" )" &
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_pt1\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_pt2\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_pt2\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_pt3\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_pt3\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_pt4\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_pt4\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_pt5\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_pt5\",       \"passtrig\" )" &

# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_ptlt1\",       \"passtrig\" )" 
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_ptlt1\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_ptlt2\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_ptlt2\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_ptlt3\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_ptlt3\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_ptlt4\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_ptlt4\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw_ptlt5\",       \"passtrig\" )" &
# # # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir_ptlt5\",       \"passtrig\" )" &
