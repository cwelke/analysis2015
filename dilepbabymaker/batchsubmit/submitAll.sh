#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V00-00-07/condor_V00-00-07_dyjetsll_ht100to200.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_dyjetsll_ht200to400.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_dyjetsll_ht400to600.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_dyjetsll_ht600toinf.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_dyjetsll_m50inc.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_dyjetsmm_ptz180.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_gjet_ht100to200.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_gjet_ht200to400.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_gjet_ht400to600.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_gjet_ht600toinf.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_gjet_pt40_doubleEM.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_t_bars.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_t_bart.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_t_bartw.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_t_tops.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_t_topt.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_t_toptw.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_ttall_msdecays.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_tth.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_ttw.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_ttz.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_wz_3lnu.cmd
condor_submit configs_V00-00-07/condor_V00-00-07_zz_4l.cmd
