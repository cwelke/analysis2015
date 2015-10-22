#! /bin/bash


source ../settings.sh

compile_looper
# create_analysis_output

if [ ! -d "../output/$analysis_version/" ]; then
	mkdir -p ../output/$analysis_version/
fi

# selection="_central_twojets"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_central_withb_twojets"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_central_with2_twojets"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_central_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_central_withb_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_central_with2_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &

# selection="_forward_twojets"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_forward_withb_twojets"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_forward_with2_twojets"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_forward_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_forward_withb_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_forward_with2_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &

# selection="_rawMET_bveto_SRB"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_rawMET_withb_SRB"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_rawMET_bveto_SRA"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_rawMET_withb_SRA"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_rawMET_SR_ATLAS"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &

# selection="_central_twojets"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &
# selection="_central_withb_twojets"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &
# selection="_central_with2_twojets"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &
# selection="_central_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &
# selection="_central_withb_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &
# selection="_central_with2_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &

selection="_forward_twojets"
./makePhotonTemplates $selection $analysis_version data dohtreweighting &
selection="_forward_withb_twojets"
./makePhotonTemplates $selection $analysis_version data dohtreweighting &
selection="_forward_with2_twojets"
./makePhotonTemplates $selection $analysis_version data dohtreweighting &
selection="_forward_3jets_inclusive"
./makePhotonTemplates $selection $analysis_version data dohtreweighting &
selection="_forward_withb_3jets_inclusive"
./makePhotonTemplates $selection $analysis_version data dohtreweighting &
selection="_forward_with2_3jets_inclusive"
./makePhotonTemplates $selection $analysis_version data dohtreweighting &


# selection="_rawMET_SRB"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &
# selection="_rawMET_SRA"
# ./makePhotonTemplates $selection $analysis_version data dontdohtreweighting &

# selection="_rawMET_bveto_SRB"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &
# selection="_rawMET_withb_SRB"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &
# selection="_rawMET_bveto_SRA"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &
# selection="_rawMET_withb_SRA"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &
# selection="_rawMET_SR_ATLAS"
# ./makePhotonTemplates $selection $analysis_version data dohtreweighting &

# selection="_central_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_central_withb_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_central_with2_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_central_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_central_withb_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_central_with2_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &

# selection="_forward_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_forward_withb_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_forward_with2_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_forward_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_forward_withb_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_forward_with2_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &

# selection="_rawMET_bveto_SRB"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_rawMET_withb_SRB"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_rawMET_bveto_SRA"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_rawMET_withb_SRA"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &
# selection="_rawMET_SR_ATLAS"
# ./makePhotonTemplates $selection $analysis_version All_MC dontdohtreweighting &

# selection="_central_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_central_withb_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_central_with2_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_central_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_central_withb_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_central_with2_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &

# selection="_forward_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_forward_withb_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_forward_with2_twojets"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_forward_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_forward_withb_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_forward_with2_3jets_inclusive"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &

# selection="_rawMET_bveto_SRB"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_rawMET_withb_SRB"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_rawMET_bveto_SRA"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_rawMET_withb_SRA"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
# selection="_rawMET_SR_ATLAS"
# ./makePhotonTemplates $selection $analysis_version All_MC dohtreweighting &
