#! /bin/bash

source ../settings.sh

root -b -q "compareMET.cc+( \"$analysis_version\" )"
