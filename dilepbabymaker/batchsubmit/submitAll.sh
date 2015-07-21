#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V07-04-03_goodtrigs/condor_V07-04-03_goodtrigs_data_50ns_ee.cmd
condor_submit configs_V07-04-03_goodtrigs/condor_V07-04-03_goodtrigs_data_50ns_em.cmd
condor_submit configs_V07-04-03_goodtrigs/condor_V07-04-03_goodtrigs_data_50ns_mm.cmd
condor_submit configs_V07-04-03_goodtrigs/condor_V07-04-03_goodtrigs_data_50ns_ph.cmd
condor_submit configs_V07-04-03_goodtrigs/condor_V07-04-03_goodtrigs_data_50ns_se.cmd
condor_submit configs_V07-04-03_goodtrigs/condor_V07-04-03_goodtrigs_data_50ns_sm.cmd
condor_submit configs_V07-04-03_goodtrigs/condor_V07-04-03_goodtrigs_wz_50ns_incl.cmd
