#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V07-04-05/condor_V07-04-05_data_50ns_ee.cmd
condor_submit configs_V07-04-05/condor_V07-04-05_data_50ns_em.cmd
condor_submit configs_V07-04-05/condor_V07-04-05_data_50ns_mm.cmd
condor_submit configs_V07-04-05/condor_V07-04-05_data_50ns_ph.cmd
condor_submit configs_V07-04-05/condor_V07-04-05_dyjetsll_50ns_m1050nlo.cmd
condor_submit configs_V07-04-05/condor_V07-04-05_dyjetsll_50ns_m50nlo.cmd
condor_submit configs_V07-04-05/condor_V07-04-05_tt2lnu_50ns_php8.cmd
condor_submit configs_V07-04-05/condor_V07-04-05_wz_50ns_incl.cmd
