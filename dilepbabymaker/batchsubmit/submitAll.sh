#!/bin/bash
voms-proxy-init -voms cms -valid 240:00
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_dyjetsll_ht100to200.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_dyjetsll_ht200to400.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_dyjetsll_ht400to600.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_dyjetsll_ht600toinf.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_dyjetsll_m50inc.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_t_bartw.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_t_toptw.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_ttall_msdecays.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_tth.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_ttw.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_ttz.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_wz_3lnu.cmd
condor_submit configs_V00-00-16_zmet_noiso/condor_V00-00-16_zmet_noiso_zz_4l.cmd
