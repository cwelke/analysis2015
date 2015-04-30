#! /bin/bash

source ../settings.sh

root -b -q "FS_closure.cc+( \"$analysis_version\" )"
root -b -q "compareMET.cc+( \"$analysis_version\" )"
