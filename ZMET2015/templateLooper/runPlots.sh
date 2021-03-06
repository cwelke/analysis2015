#! /bin/bash

source ../settings.sh

if [ ! -d "../output/ZMET2015/$analysis_version/plots/Closure/" ]; then
	mkdir -p ../output/ZMET2015/$analysis_version/plots/Closure/
	cp ../index.php ../output/ZMET2015/$analysis_version/plots/Closure/
fi

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
root -b -q "compareMET.cc+( \"$analysis_version\", \"_2jets_inclusive\", 4.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_3jets_inclusive\", 10.0 )"

# root -b -q "compareMET.cc+( \"$analysis_version\", \"_SRA_bveto\", 10.0 )"
# root -b -q "compareMET.cc+( \"$analysis_version\", \"_SRA_withb\", 10.0 )"


# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_2jets\" )"

# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_twojets\" )"
root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 4.0, \"_2jets_inclusive\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_3jets_inclusive\" )"

# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_inclusive\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRA_bveto\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRA_withb\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRB_bveto\" )"
# root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0, \"_SRB_withb\" )"
