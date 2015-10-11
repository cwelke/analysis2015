#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V07-04-10/condor_V07-04-10_data_2015D25nsPrompt_ee.cmd
condor_submit configs_V07-04-10/condor_V07-04-10_data_2015D25nsPrompt_em.cmd
condor_submit configs_V07-04-10/condor_V07-04-10_data_2015D25nsPrompt_mm.cmd
condor_submit configs_V07-04-10/condor_V07-04-10_data_2015D25nsPrompt_ph.cmd
