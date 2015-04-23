#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V00-00-12/condor_V00-00-12_ttall_msdecays.cmd
