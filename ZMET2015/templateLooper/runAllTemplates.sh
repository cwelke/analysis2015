#! /bin/bash


source ../settings.sh

compile_looper
# create_analysis_output

# # For Closure tests
# selection="_2btag_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_inclusive_medium"
# make_gtemplates $selection &

# SR + CRS
selection="_inclusive"
sample="All_MC"
run_template_looper $selection $sample

# # SR + CRS
# selection="_inclusive"
# make_gtemplates $selection "zjets"
# make_gtemplates $selection "ttbar"
# make_gtemplates $selection "top"
# make_gtemplates $selection "vv"
# make_gtemplates $selection "ttv"

