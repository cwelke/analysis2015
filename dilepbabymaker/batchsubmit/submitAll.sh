#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V00-00-13/condor_V00-00-13_dyjetsll_ht100to200.cmd
condor_submit configs_V00-00-13/condor_V00-00-13_dyjetsll_ht200to400.cmd
condor_submit configs_V00-00-13/condor_V00-00-13_dyjetsll_ht400to600.cmd
condor_submit configs_V00-00-13/condor_V00-00-13_dyjetsll_ht600toinf.cmd
condor_submit configs_V00-00-13/condor_V00-00-13_dyjetsll_m50inc.cmd
condor_submit configs_V00-00-13/condor_V00-00-13_t_bartw.cmd
condor_submit configs_V00-00-13/condor_V00-00-13_t_toptw.cmd
condor_submit configs_V00-00-13/condor_V00-00-13_ttall_msdecays.cmd
