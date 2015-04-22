#! /bin/bash


source ../settings.sh

compile_looper
# create_analysis_output

# # For Closure tests
# selection="_2btag_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_inclusive_medium"
# make_gtemplates $selection &

# # SR + CRS
selection="_inclusive"

# sample="All_MC"
# run_template_looper $selection $sample &

# # SR + CRS
selection="_inclusive"
run_template_looper $selection "zjets"
# run_template_looper $selection "ttbar"
# run_template_looper $selection "top"
# run_template_looper $selection "vv"
# run_template_looper $selection "ttv"
# run_template_looper $selection "FS_BG"
