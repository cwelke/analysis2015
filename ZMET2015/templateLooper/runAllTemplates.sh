#! /bin/bash


source ../settings.sh

compile_looper
# create_analysis_output

if [ ! -d "../output/$analysis_version/" ]; then
	mkdir -p ../output/$analysis_version/
fi

# # For Closure tests
# selection="_2btag_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_inclusive_medium"
# make_gtemplates $selection &

# sample="All_MC"
# run_template_looper $selection $sample &

# # SR + CRS
selection="_inclusive"
run_template_looper $selection "All_MC" &
run_template_looper $selection "vv"	    &
run_template_looper $selection "ttv"    &
run_template_looper $selection "FS_BG"  &

# run_template_looper $selection "zjets"
# # run_template_looper $selection "ttbar"
# # # run_template_looper $selection "top"

selection="_SRA_bveto"
run_template_looper $selection "All_MC" &
run_template_looper $selection "vv"	    &
run_template_looper $selection "ttv"    &
run_template_looper $selection "FS_BG"  &
									    
selection="_SRA_withb"				    
run_template_looper $selection "All_MC" &
run_template_looper $selection "vv"	    &
run_template_looper $selection "ttv"    &
run_template_looper $selection "FS_BG"  &
									    
selection="_SRB_bveto"				    
run_template_looper $selection "All_MC" &
run_template_looper $selection "vv"	    &
run_template_looper $selection "ttv"    &
run_template_looper $selection "FS_BG"  &
									    
selection="_SRB_withb"				    
run_template_looper $selection "All_MC" &
run_template_looper $selection "vv"	    &
run_template_looper $selection "ttv"    &
run_template_looper $selection "FS_BG"  &
