#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V00-00-17/condor_V00-00-17_dyjetsll_ht100to200.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_dyjetsll_ht200to400.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_dyjetsll_ht400to600.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_dyjetsll_ht600toinf.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_dyjetsll_m50inc.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_gjet_ht100to200.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_gjet_ht200to400.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_gjet_ht400to600.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_gjet_ht600toinf.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_gjet_pt40_doubleEM.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_t_bartw.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_t_toptw.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_ttall_msdecays.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_tth.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_ttw.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_ttz.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_wz_3lnu.cmd
condor_submit configs_V00-00-17/condor_V00-00-17_zz_4l.cmd
