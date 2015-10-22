#! /bin/bash


source ../settings.sh

compile_looper
# create_analysis_output

if [ ! -d "../output/$analysis_version/" ]; then
	mkdir -p ../output/$analysis_version/
fi

#################
## for studies ##
#################

# selection="_inclusive"
# ./runTemplateLooper $selection $analysis_version data  &
# ./runTemplateLooper $selection $analysis_version zjets &
# ./runTemplateLooper $selection $analysis_version ttbar &
# ./runTemplateLooper $selection $analysis_version st &
# ./runTemplateLooper $selection $analysis_version ww &
# ./runTemplateLooper $selection $analysis_version wz &
# ./runTemplateLooper $selection $analysis_version zz &
# ./runTemplateLooper $selection $analysis_version ttv &
# ./runTemplateLooper $selection $analysis_version vvv &

#################
## for closure ##
#################

# selection="_central_twojets"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_central_withb_twojets"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_central_with2_twojets"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_central_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_central_withb_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_central_with2_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &

# selection="_forward_twojets"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_forward_withb_twojets"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_forward_with2_twojets"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_forward_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_forward_withb_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_forward_with2_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &

# selection="_rawMET_bveto_SRB"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_rawMET_withb_SRB"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_rawMET_bveto_SRA"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_rawMET_withb_SRA"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &
# selection="_rawMET_SR_ATLAS"
# ./runTemplateLooper $selection $analysis_version zjetsmlm &

##################
## for SR preds ##
##################

# selection="_central_twojets"
# ./runTemplateLooper $selection $analysis_version data &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_central_withb_twojets"
# ./runTemplateLooper $selection $analysis_version data &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_central_with2_twojets"
# ./runTemplateLooper $selection $analysis_version data &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_central_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version data &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_central_withb_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version data &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_central_with2_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version data &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &



selection="_forward_twojets"
./runTemplateLooper $selection $analysis_version data &
# ./runTemplateLooper $selection $analysis_version zjets &
# ./runTemplateLooper $selection $analysis_version ttbar &
# ./runTemplateLooper $selection $analysis_version st &
# ./runTemplateLooper $selection $analysis_version ww &
# ./runTemplateLooper $selection $analysis_version wz &
# ./runTemplateLooper $selection $analysis_version zz &
# ./runTemplateLooper $selection $analysis_version ttv &
# ./runTemplateLooper $selection $analysis_version vvv &

# selection="_forward_withb_twojets"
# ./runTemplateLooper $selection $analysis_version data &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_forward_with2_twojets"
# ./runTemplateLooper $selection $analysis_version data &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

selection="_forward_3jets_inclusive"
./runTemplateLooper $selection $analysis_version data &
# ./runTemplateLooper $selection $analysis_version zjets &
# ./runTemplateLooper $selection $analysis_version ttbar &
# ./runTemplateLooper $selection $analysis_version st &
# ./runTemplateLooper $selection $analysis_version ww &
# ./runTemplateLooper $selection $analysis_version wz &
# ./runTemplateLooper $selection $analysis_version zz &
# ./runTemplateLooper $selection $analysis_version ttv &
# ./runTemplateLooper $selection $analysis_version vvv &

# selection="_forward_withb_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version data &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_forward_with2_3jets_inclusive"
# ./runTemplateLooper $selection $analysis_version data &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &





# selection="_rawMET_SRB"
# ./runTemplateLooper $selection $analysis_version data  &

# selection="_rawMET_SRA"
# ./runTemplateLooper $selection $analysis_version data  &

# selection="_rawMET_bveto_SRB"
# ./runTemplateLooper $selection $analysis_version data  &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_rawMET_withb_SRB"
# ./runTemplateLooper $selection $analysis_version data  &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_rawMET_bveto_SRA"
# ./runTemplateLooper $selection $analysis_version data  &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_rawMET_withb_SRA"
# ./runTemplateLooper $selection $analysis_version data  &
# # ./runTemplateLooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &

# selection="_rawMET_SR_ATLAS"
# ./runTemplateLooper $selection $analysis_version data  &
# # ./runtemplatelooper $selection $analysis_version zjets &
# # ./runTemplateLooper $selection $analysis_version ttbar &
# # ./runTemplateLooper $selection $analysis_version st &
# # ./runTemplateLooper $selection $analysis_version ww &
# # ./runTemplateLooper $selection $analysis_version wz &
# # ./runTemplateLooper $selection $analysis_version zz &
# # ./runTemplateLooper $selection $analysis_version ttv &
# # ./runTemplateLooper $selection $analysis_version vvv &
