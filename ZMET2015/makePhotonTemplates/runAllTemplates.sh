#! /bin/bash

source ../settings.sh

compile_looper
# create_photon_output

# # For Closure tests
# selection="_2btag_inclusive_medium"
# make_gtemplates $selection &
# selection="_bveto_inclusive_medium"
# make_gtemplates $selection &

# SR + CRS
selection="_inclusive"
make_gtemplates $selection "All_MC"
