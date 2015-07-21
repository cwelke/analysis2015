#! /bin/bash

source ../settings.sh

# analysis_version=V07-04-02

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_2jets_inclusive\", 0.057 )"

lumi=0.0358

root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mt3\", \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mt3\", \"passtrig\" )" &
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mt3\", \"passtrig\" )" &

root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\", \"passtrig\" )" 
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met\", \"passtrig\" )"	&
root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met_raw\", \"passtrig\" )"	&

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"met\", \"passtrig\" )"	
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"met_raw\", \"passtrig\" )"	&

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\", \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphi\", \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphir\", \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphi20\", \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphi40\", \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"metphi60\", \"passtrig\" )" &

# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nVert\", \"passtrig\" )" 
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"nVert\", \"passtrig\" )" &
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"nVert\", \"passtrig\" )" &

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"mll\", \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"em\", \"mll\", \"passtrig\" )" & 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"mll\", \"passtrig\" )" &	
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"mll\", \"passtrig\" )" &	

# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0180, \"_inclusive\", \"ll\", \"mll\", \"inclusive\" )"  
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0180, \"_inclusive\", \"ee\", \"mll\", \"inclusive\" )"	&
# # root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0180, \"_inclusive\", \"mm\", \"mll\", \"inclusive\" )"	&

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met\", \"passtrig\" )"	
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"met\", \"passtrig\" )"	&
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met\", \"passtrig\" )"	&
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"met_raw\", \"passtrig\" )"	&
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"met_raw\", \"passtrig\" )"	&
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"met_raw\", \"passtrig\" )"	&
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"nVert\", \"passtrig\" )" 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"nVert\", \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"nVert\", \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"njets\", \"passtrig\" )" &  
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"njets\", \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"njets\", \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ht\",    \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ht\",    \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ht\",    \"passtrig\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptl1\",    \"passtrig\" )" 	 
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptl1\",    \"passtrig\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptl1\",    \"passtrig\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptl2\",    \"passtrig\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptl2\",    \"passtrig\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptl2\",    \"passtrig\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ll\", \"ptdil\",   \"passtrig\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"ee\", \"ptdil\",   \"passtrig\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", $lumi, \"_inclusive\", \"mm\", \"ptdil\",   \"passtrig\" )" 	 &

# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0030, \"_inclusive\", \"ll\", \"mll\", \"inclusive\" )"   &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0030, \"_inclusive\", \"ee\", \"mll\", \"inclusive\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0030, \"_inclusive\", \"mm\", \"mll\", \"inclusive\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0030, \"_inclusive\", \"ll\", \"met\", \"inclusive\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0030, \"_inclusive\", \"ee\", \"met\", \"inclusive\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0030, \"_inclusive\", \"mm\", \"met\", \"inclusive\" )" 	 &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0030, \"_inclusive\", \"ll\", \"nVert\", \"inclusive\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0030, \"_inclusive\", \"ee\", \"nVert\", \"inclusive\" )" &
# root -b -q "drawDatavsMC.cc+( \"$analysis_version\", 0.0030, \"_inclusive\", \"mm\", \"nVert\", \"inclusive\" )" &



# root -b -q "drawRatio.cc+( \"$analysis_version\", 10.0 )"

# root -b -q "FS_closure.cc+( \"$analysis_version\", 10.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", 10.0 )"

# root -b -q "compareMET.cc+( \"$analysis_version\", 10.0 )"

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_2jets_edgef\", 4.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_2jets_edgec\", 4.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_3jets_edgef\", 4.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_3jets_edgec\", 4.0 )"

# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_2jets_edgec\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_2jets_edgef\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_3jets_edgec\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_3jets_edgef\" )"

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_twojets\", 10.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_2jets_inclusive\", 4.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_3jets_inclusive\", 10.0 )"

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_SRA_bveto\", 10.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_SRA_withb\", 10.0 )"


# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_2jets\" )"

# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_twojets\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_2jets_inclusive\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_3jets_inclusive\" )"

# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_inclusive\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRA_bveto\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRA_withb\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRB_bveto\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRB_withb\" )"
