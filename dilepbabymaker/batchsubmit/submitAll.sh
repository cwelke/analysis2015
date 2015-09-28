#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V07-04-09/condor_V07-04-09_sttwatop_25ns_powp8.cmd
condor_submit configs_V07-04-09/condor_V07-04-09_sttwtop_25ns_powp8.cmd
condor_submit configs_V07-04-09/condor_V07-04-09_ww2l2nu_25ns_powp8.cmd
condor_submit configs_V07-04-09/condor_V07-04-09_wz3lnu_25ns_powp8.cmd
