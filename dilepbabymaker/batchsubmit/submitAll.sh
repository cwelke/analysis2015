#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_data_25nsPrompt_ee.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_data_25nsPrompt_em.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_data_25nsPrompt_mm.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_data_25nsPrompt_ph.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_dyjetsll_25ns_m1050nlo.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_dyjetsll_25ns_m50nlo.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_gjets_25ns_ht100mlm.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_gjets_25ns_ht200mlm.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_gjets_25ns_ht400mlm.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_gjets_25ns_ht40mlm.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_gjets_25ns_ht600mlm.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_tt2lnu_25ns_php8.cmd
condor_submit configs_V07-04-08_25ns/condor_V07-04-08_25ns_zjetsll_25ns_m50mlm.cmd
