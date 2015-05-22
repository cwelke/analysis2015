#! /bin/bash

source ../settings.sh

root -b -q "FS_closure.cc+( \"$analysis_version\", 10.0 )"
root -b -q "compareMET.cc+( \"$analysis_version\", 10.0 )"

root -b -q "drawMoneyPlot.cc+( \"$analysis_version\", 10.0 )"
