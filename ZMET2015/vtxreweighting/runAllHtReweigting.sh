#! /bin/bash

# root -b -q "getReweightHTHist.cc+(\"rawMET\")"

root -b -q "getReweightHTHist.cc+(\"rawMET_bveto_SRB\")"
root -b -q "getReweightHTHist.cc+(\"rawMET_withb_SRB\")"
