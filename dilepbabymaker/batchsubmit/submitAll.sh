#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V07-04-07/condor_V07-04-07_data_50ns17Jul_ee.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_data_50ns17Jul_em.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_data_50ns17Jul_mm.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_data_50ns17Jul_ph.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_data_50nsPrompt_ee.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_data_50nsPrompt_em.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_data_50nsPrompt_mm.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_data_50nsPrompt_ph.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_dyjetsll_50ns_m1050nlo.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_dyjetsll_50ns_m50mlm.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_dyjetsll_50ns_m50nlo.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_tt2lnu_50ns_php8.cmd
condor_submit configs_V07-04-07/condor_V07-04-07_wz_50ns_incl.cmd
