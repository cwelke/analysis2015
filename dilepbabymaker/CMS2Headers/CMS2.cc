#include "CMS2.h"
CMS2 cms2;
namespace tas {
	TBits &hlt_bits() { return cms2.hlt_bits(); }
	vector<TString> &evt_CMS2tag() { return cms2.evt_CMS2tag(); }
	vector<TString> &evt_dataset() { return cms2.evt_dataset(); }
	vector<TString> &hlt_trigNames() { return cms2.hlt_trigNames(); }
	vector<TString> &sparm_comment() { return cms2.sparm_comment(); }
	vector<TString> &sparm_names() { return cms2.sparm_names(); }
	bool &hcalnoise_HasBadRBXTS4TS5() { return cms2.hcalnoise_HasBadRBXTS4TS5(); }
	bool &evt_cscTightHaloId() { return cms2.evt_cscTightHaloId(); }
	bool &evt_hbheFilter() { return cms2.evt_hbheFilter(); }
	bool &filt_cscBeamHalo() { return cms2.filt_cscBeamHalo(); }
	bool &filt_ecalLaser() { return cms2.filt_ecalLaser(); }
	bool &filt_ecalTP() { return cms2.filt_ecalTP(); }
	bool &filt_eeBadSc() { return cms2.filt_eeBadSc(); }
	bool &filt_goodVertices() { return cms2.filt_goodVertices(); }
	bool &filt_hbheNoise() { return cms2.filt_hbheNoise(); }
	bool &filt_hcalLaser() { return cms2.filt_hcalLaser(); }
	bool &filt_metfilter() { return cms2.filt_metfilter(); }
	bool &filt_trackingFailure() { return cms2.filt_trackingFailure(); }
	bool &filt_trkPOGFilters() { return cms2.filt_trkPOGFilters(); }
	bool &filt_trkPOG_logErrorTooManyClusters() { return cms2.filt_trkPOG_logErrorTooManyClusters(); }
	bool &filt_trkPOG_manystripclus53X() { return cms2.filt_trkPOG_manystripclus53X(); }
	bool &filt_trkPOG_toomanystripclus53X() { return cms2.filt_trkPOG_toomanystripclus53X(); }
	vector<bool> &els_conv_vtx_flag() { return cms2.els_conv_vtx_flag(); }
	vector<bool> &els_isGsfCtfScPixChargeConsistent() { return cms2.els_isGsfCtfScPixChargeConsistent(); }
	vector<bool> &els_passingMvaPreselection() { return cms2.els_passingMvaPreselection(); }
	vector<bool> &els_passingPflowPreselection() { return cms2.els_passingPflowPreselection(); }
	vector<bool> &mus_isRPCMuon() { return cms2.mus_isRPCMuon(); }
	vector<bool> &mus_tightMatch() { return cms2.mus_tightMatch(); }
	vector<bool> &mus_updatedSta() { return cms2.mus_updatedSta(); }
	vector<bool> &photons_haspixelSeed() { return cms2.photons_haspixelSeed(); }
	float &evt_bs_Xwidth() { return cms2.evt_bs_Xwidth(); }
	float &evt_bs_XwidthErr() { return cms2.evt_bs_XwidthErr(); }
	float &evt_bs_Ywidth() { return cms2.evt_bs_Ywidth(); }
	float &evt_bs_YwidthErr() { return cms2.evt_bs_YwidthErr(); }
	float &evt_bs_dxdz() { return cms2.evt_bs_dxdz(); }
	float &evt_bs_dxdzErr() { return cms2.evt_bs_dxdzErr(); }
	float &evt_bs_dydz() { return cms2.evt_bs_dydz(); }
	float &evt_bs_dydzErr() { return cms2.evt_bs_dydzErr(); }
	float &evt_bs_sigmaZ() { return cms2.evt_bs_sigmaZ(); }
	float &evt_bs_sigmaZErr() { return cms2.evt_bs_sigmaZErr(); }
	float &evt_bs_xErr() { return cms2.evt_bs_xErr(); }
	float &evt_bs_yErr() { return cms2.evt_bs_yErr(); }
	float &evt_bs_zErr() { return cms2.evt_bs_zErr(); }
	float &evt_bField() { return cms2.evt_bField(); }
	float &evt_fixgrid_all_rho() { return cms2.evt_fixgrid_all_rho(); }
	float &evt_fixgridfastjet_allcalo_rho() { return cms2.evt_fixgridfastjet_allcalo_rho(); }
	float &evt_fixgridfastjet_all_rho() { return cms2.evt_fixgridfastjet_all_rho(); }
	float &evt_fixgridfastjet_centralcalo_rho() { return cms2.evt_fixgridfastjet_centralcalo_rho(); }
	float &evt_fixgridfastjet_centralchargedpileup_rho() { return cms2.evt_fixgridfastjet_centralchargedpileup_rho(); }
	float &evt_fixgridfastjet_centralneutral_rho() { return cms2.evt_fixgridfastjet_centralneutral_rho(); }
	float &evt_kfactor() { return cms2.evt_kfactor(); }
	float &evt_scale1fb() { return cms2.evt_scale1fb(); }
	float &evt_xsec_excl() { return cms2.evt_xsec_excl(); }
	float &evt_xsec_incl() { return cms2.evt_xsec_incl(); }
	float &genps_alphaQCD() { return cms2.genps_alphaQCD(); }
	float &genps_pthat() { return cms2.genps_pthat(); }
	float &genps_qScale() { return cms2.genps_qScale(); }
	float &genps_weight() { return cms2.genps_weight(); }
	float &gen_sumEt() { return cms2.gen_sumEt(); }
	float &hcalnoise_GetRecHitEnergy() { return cms2.hcalnoise_GetRecHitEnergy(); }
	float &hcalnoise_GetRecHitEnergy15() { return cms2.hcalnoise_GetRecHitEnergy15(); }
	float &hcalnoise_GetTotalCalibCharge() { return cms2.hcalnoise_GetTotalCalibCharge(); }
	float &hcalnoise_TS4TS5NoiseSumE() { return cms2.hcalnoise_TS4TS5NoiseSumE(); }
	float &hcalnoise_TS4TS5NoiseSumEt() { return cms2.hcalnoise_TS4TS5NoiseSumEt(); }
	float &hcalnoise_eventChargeFraction() { return cms2.hcalnoise_eventChargeFraction(); }
	float &hcalnoise_eventEMEnergy() { return cms2.hcalnoise_eventEMEnergy(); }
	float &hcalnoise_eventEMFraction() { return cms2.hcalnoise_eventEMFraction(); }
	float &hcalnoise_eventHadEnergy() { return cms2.hcalnoise_eventHadEnergy(); }
	float &hcalnoise_eventTrackEnergy() { return cms2.hcalnoise_eventTrackEnergy(); }
	float &hcalnoise_flatNoiseSumE() { return cms2.hcalnoise_flatNoiseSumE(); }
	float &hcalnoise_flatNoiseSumEt() { return cms2.hcalnoise_flatNoiseSumEt(); }
	float &hcalnoise_isolatedNoiseSumE() { return cms2.hcalnoise_isolatedNoiseSumE(); }
	float &hcalnoise_isolatedNoiseSumEt() { return cms2.hcalnoise_isolatedNoiseSumEt(); }
	float &hcalnoise_max10GeVHitTime() { return cms2.hcalnoise_max10GeVHitTime(); }
	float &hcalnoise_max25GeVHitTime() { return cms2.hcalnoise_max25GeVHitTime(); }
	float &hcalnoise_maxE10TS() { return cms2.hcalnoise_maxE10TS(); }
	float &hcalnoise_maxE2Over10TS() { return cms2.hcalnoise_maxE2Over10TS(); }
	float &hcalnoise_maxE2TS() { return cms2.hcalnoise_maxE2TS(); }
	float &hcalnoise_min10GeVHitTime() { return cms2.hcalnoise_min10GeVHitTime(); }
	float &hcalnoise_min25GeVHitTime() { return cms2.hcalnoise_min25GeVHitTime(); }
	float &hcalnoise_minE10TS() { return cms2.hcalnoise_minE10TS(); }
	float &hcalnoise_minE2Over10TS() { return cms2.hcalnoise_minE2Over10TS(); }
	float &hcalnoise_minE2TS() { return cms2.hcalnoise_minE2TS(); }
	float &hcalnoise_minHPDEMF() { return cms2.hcalnoise_minHPDEMF(); }
	float &hcalnoise_minRBXEMF() { return cms2.hcalnoise_minRBXEMF(); }
	float &hcalnoise_rms10GeVHitTime() { return cms2.hcalnoise_rms10GeVHitTime(); }
	float &hcalnoise_rms25GeVHitTime() { return cms2.hcalnoise_rms25GeVHitTime(); }
	float &hcalnoise_spikeNoiseSumE() { return cms2.hcalnoise_spikeNoiseSumE(); }
	float &hcalnoise_spikeNoiseSumEt() { return cms2.hcalnoise_spikeNoiseSumEt(); }
	float &hcalnoise_triangleNoiseSumE() { return cms2.hcalnoise_triangleNoiseSumE(); }
	float &hcalnoise_triangleNoiseSumEt() { return cms2.hcalnoise_triangleNoiseSumEt(); }
	float &pdfinfo_pdf1() { return cms2.pdfinfo_pdf1(); }
	float &pdfinfo_pdf2() { return cms2.pdfinfo_pdf2(); }
	float &pdfinfo_scale() { return cms2.pdfinfo_scale(); }
	float &pdfinfo_x1() { return cms2.pdfinfo_x1(); }
	float &pdfinfo_x2() { return cms2.pdfinfo_x2(); }
	float &evt_fixgrid_rho_all() { return cms2.evt_fixgrid_rho_all(); }
	float &evt_fixgrid_rho_ctr() { return cms2.evt_fixgrid_rho_ctr(); }
	float &evt_fixgrid_rho_fwd() { return cms2.evt_fixgrid_rho_fwd(); }
	float &evt_pfmet() { return cms2.evt_pfmet(); }
	float &evt_pfmetPhi() { return cms2.evt_pfmetPhi(); }
	float &evt_pfmetPhi_raw() { return cms2.evt_pfmetPhi_raw(); }
	float &evt_pfmetSig() { return cms2.evt_pfmetSig(); }
	float &evt_pfmetSignificance() { return cms2.evt_pfmetSignificance(); }
	float &evt_pfmet_raw() { return cms2.evt_pfmet_raw(); }
	float &evt_pfsumet() { return cms2.evt_pfsumet(); }
	float &evt_pfsumet_raw() { return cms2.evt_pfsumet_raw(); }
	float &gen_met() { return cms2.gen_met(); }
	float &gen_metPhi() { return cms2.gen_metPhi(); }
	float &sparm_filterEfficiency() { return cms2.sparm_filterEfficiency(); }
	float &sparm_pdfScale() { return cms2.sparm_pdfScale(); }
	float &sparm_pdfWeight1() { return cms2.sparm_pdfWeight1(); }
	float &sparm_pdfWeight2() { return cms2.sparm_pdfWeight2(); }
	float &sparm_weight() { return cms2.sparm_weight(); }
	float &sparm_xsec() { return cms2.sparm_xsec(); }
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >  &evt_bsp4() { return cms2.evt_bsp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_motherp4() { return cms2.els_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_p4() { return cms2.els_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_motherp4() { return cms2.mus_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_p4() { return cms2.mus_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_gp_p4() { return cms2.pfjets_mc_gp_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_motherp4() { return cms2.pfjets_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_p4() { return cms2.pfjets_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_mc_motherp4() { return cms2.photons_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_mc_p4() { return cms2.photons_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_inner_position() { return cms2.els_inner_position(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_patMatch_p4() { return cms2.els_mc_patMatch_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_outer_position() { return cms2.els_outer_position(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4() { return cms2.els_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4In() { return cms2.els_p4In(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4Out() { return cms2.els_p4Out(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_trk_p4() { return cms2.els_trk_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_trk_vertex_p4() { return cms2.els_trk_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_vertex_p4() { return cms2.els_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genjets_p4NoMuNoNu() { return cms2.genjets_p4NoMuNoNu(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4() { return cms2.genps_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_prod_vtx() { return cms2.genps_prod_vtx(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_ll_p4() { return cms2.hyp_ll_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_lt_p4() { return cms2.hyp_lt_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_p4() { return cms2.hyp_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_gfit_p4() { return cms2.mus_gfit_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_gfit_vertex_p4() { return cms2.mus_gfit_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_patMatch_p4() { return cms2.mus_mc_patMatch_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_p4() { return cms2.mus_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_pfp4() { return cms2.mus_pfp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_sta_p4() { return cms2.mus_sta_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_sta_vertex_p4() { return cms2.mus_sta_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_trk_p4() { return cms2.mus_trk_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_vertex_p4() { return cms2.mus_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfcands_p4() { return cms2.pfcands_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_p4() { return cms2.pfjets_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &taus_pf_lead_chargecand_p4() { return cms2.taus_pf_lead_chargecand_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &taus_pf_lead_neutrcand_p4() { return cms2.taus_pf_lead_neutrcand_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &taus_pf_p4() { return cms2.taus_pf_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_p4() { return cms2.photons_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_p4() { return cms2.svs_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_position() { return cms2.svs_position(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak8jets_p4() { return cms2.ak8jets_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &vtxs_position() { return cms2.vtxs_position(); }
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &genps_lepdaughter_p4() { return cms2.genps_lepdaughter_p4(); }
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &hlt_trigObjs_p4() { return cms2.hlt_trigObjs_p4(); }
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &taus_pf_isocands_p4() { return cms2.taus_pf_isocands_p4(); }
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &taus_pf_signalcands_p4() { return cms2.taus_pf_signalcands_p4(); }
	vector<float> &evt_bs_covMatrix() { return cms2.evt_bs_covMatrix(); }
	vector<float> &els_mc3dr() { return cms2.els_mc3dr(); }
	vector<float> &els_mcdr() { return cms2.els_mcdr(); }
	vector<float> &mus_mc3dr() { return cms2.mus_mc3dr(); }
	vector<float> &mus_mcdr() { return cms2.mus_mcdr(); }
	vector<float> &pfjets_mc3dr() { return cms2.pfjets_mc3dr(); }
	vector<float> &pfjets_mcdr() { return cms2.pfjets_mcdr(); }
	vector<float> &pfjets_mc_emEnergy() { return cms2.pfjets_mc_emEnergy(); }
	vector<float> &pfjets_mc_gpdr() { return cms2.pfjets_mc_gpdr(); }
	vector<float> &pfjets_mc_hadEnergy() { return cms2.pfjets_mc_hadEnergy(); }
	vector<float> &pfjets_mc_invEnergy() { return cms2.pfjets_mc_invEnergy(); }
	vector<float> &pfjets_mc_otherEnergy() { return cms2.pfjets_mc_otherEnergy(); }
	vector<float> &photons_mc3dr() { return cms2.photons_mc3dr(); }
	vector<float> &photons_mcdr() { return cms2.photons_mcdr(); }
	vector<float> &els_bs2d() { return cms2.els_bs2d(); }
	vector<float> &els_bs2derr() { return cms2.els_bs2derr(); }
	vector<float> &els_bs3d() { return cms2.els_bs3d(); }
	vector<float> &els_bs3derr() { return cms2.els_bs3derr(); }
	vector<float> &els_chi2() { return cms2.els_chi2(); }
	vector<float> &els_ckf_chi2() { return cms2.els_ckf_chi2(); }
	vector<float> &els_ckf_ndof() { return cms2.els_ckf_ndof(); }
	vector<float> &els_d0() { return cms2.els_d0(); }
	vector<float> &els_d0Err() { return cms2.els_d0Err(); }
	vector<float> &els_d0corr() { return cms2.els_d0corr(); }
	vector<float> &els_d0corrPhi() { return cms2.els_d0corrPhi(); }
	vector<float> &els_d0phiCov() { return cms2.els_d0phiCov(); }
	vector<float> &els_dEtaIn() { return cms2.els_dEtaIn(); }
	vector<float> &els_dEtaOut() { return cms2.els_dEtaOut(); }
	vector<float> &els_dPhiIn() { return cms2.els_dPhiIn(); }
	vector<float> &els_dPhiInPhiOut() { return cms2.els_dPhiInPhiOut(); }
	vector<float> &els_dPhiOut() { return cms2.els_dPhiOut(); }
	vector<float> &els_deltaEtaEleClusterTrackAtCalo() { return cms2.els_deltaEtaEleClusterTrackAtCalo(); }
	vector<float> &els_deltaPhiEleClusterTrackAtCalo() { return cms2.els_deltaPhiEleClusterTrackAtCalo(); }
	vector<float> &els_dxyPV() { return cms2.els_dxyPV(); }
	vector<float> &els_dzPV() { return cms2.els_dzPV(); }
	vector<float> &els_e1x5() { return cms2.els_e1x5(); }
	vector<float> &els_e1x5_full5x5() { return cms2.els_e1x5_full5x5(); }
	vector<float> &els_e2x5Max() { return cms2.els_e2x5Max(); }
	vector<float> &els_e2x5Max_full5x5() { return cms2.els_e2x5Max_full5x5(); }
	vector<float> &els_e3x3() { return cms2.els_e3x3(); }
	vector<float> &els_e5x5() { return cms2.els_e5x5(); }
	vector<float> &els_e5x5_full5x5() { return cms2.els_e5x5_full5x5(); }
	vector<float> &els_eMax() { return cms2.els_eMax(); }
	vector<float> &els_eOverPIn() { return cms2.els_eOverPIn(); }
	vector<float> &els_eOverPOut() { return cms2.els_eOverPOut(); }
	vector<float> &els_eSC() { return cms2.els_eSC(); }
	vector<float> &els_eSCPresh() { return cms2.els_eSCPresh(); }
	vector<float> &els_eSCRaw() { return cms2.els_eSCRaw(); }
	vector<float> &els_eSeed() { return cms2.els_eSeed(); }
	vector<float> &els_eSeedOverPIn() { return cms2.els_eSeedOverPIn(); }
	vector<float> &els_eSeedOverPOut() { return cms2.els_eSeedOverPOut(); }
	vector<float> &els_ecalEnergy() { return cms2.els_ecalEnergy(); }
	vector<float> &els_ecalEnergyError() { return cms2.els_ecalEnergyError(); }
	vector<float> &els_ecalIso() { return cms2.els_ecalIso(); }
	vector<float> &els_ecalIso04() { return cms2.els_ecalIso04(); }
	vector<float> &els_etaErr() { return cms2.els_etaErr(); }
	vector<float> &els_etaSC() { return cms2.els_etaSC(); }
	vector<float> &els_etaSCwidth() { return cms2.els_etaSCwidth(); }
	vector<float> &els_fbrem() { return cms2.els_fbrem(); }
	vector<float> &els_hOverE() { return cms2.els_hOverE(); }
	vector<float> &els_hOverEBC() { return cms2.els_hOverEBC(); }
	vector<float> &els_hcalDepth1OverEcal() { return cms2.els_hcalDepth1OverEcal(); }
	vector<float> &els_hcalDepth1TowerSumEt() { return cms2.els_hcalDepth1TowerSumEt(); }
	vector<float> &els_hcalDepth1TowerSumEt04() { return cms2.els_hcalDepth1TowerSumEt04(); }
	vector<float> &els_hcalDepth2OverEcal() { return cms2.els_hcalDepth2OverEcal(); }
	vector<float> &els_hcalDepth2TowerSumEt() { return cms2.els_hcalDepth2TowerSumEt(); }
	vector<float> &els_hcalDepth2TowerSumEt04() { return cms2.els_hcalDepth2TowerSumEt04(); }
	vector<float> &els_hcalIso() { return cms2.els_hcalIso(); }
	vector<float> &els_hcalIso04() { return cms2.els_hcalIso04(); }
	vector<float> &els_ip2d() { return cms2.els_ip2d(); }
	vector<float> &els_ip2derr() { return cms2.els_ip2derr(); }
	vector<float> &els_ip3d() { return cms2.els_ip3d(); }
	vector<float> &els_ip3derr() { return cms2.els_ip3derr(); }
	vector<float> &els_iso03_pf() { return cms2.els_iso03_pf(); }
	vector<float> &els_iso03_pf2012_ch() { return cms2.els_iso03_pf2012_ch(); }
	vector<float> &els_iso03_pf2012_em() { return cms2.els_iso03_pf2012_em(); }
	vector<float> &els_iso03_pf2012ext_ch() { return cms2.els_iso03_pf2012ext_ch(); }
	vector<float> &els_iso03_pf2012ext_em() { return cms2.els_iso03_pf2012ext_em(); }
	vector<float> &els_iso03_pf2012ext_nh() { return cms2.els_iso03_pf2012ext_nh(); }
	vector<float> &els_iso03_pf2012_nh() { return cms2.els_iso03_pf2012_nh(); }
	vector<float> &els_iso03_pf_ch() { return cms2.els_iso03_pf_ch(); }
	vector<float> &els_iso03_pf_gamma05() { return cms2.els_iso03_pf_gamma05(); }
	vector<float> &els_iso03_pf_nhad05() { return cms2.els_iso03_pf_nhad05(); }
	vector<float> &els_iso04_pf() { return cms2.els_iso04_pf(); }
	vector<float> &els_iso04_pf2012_ch() { return cms2.els_iso04_pf2012_ch(); }
	vector<float> &els_iso04_pf2012_em() { return cms2.els_iso04_pf2012_em(); }
	vector<float> &els_iso04_pf2012ext_ch() { return cms2.els_iso04_pf2012ext_ch(); }
	vector<float> &els_iso04_pf2012ext_em() { return cms2.els_iso04_pf2012ext_em(); }
	vector<float> &els_iso04_pf2012ext_nh() { return cms2.els_iso04_pf2012ext_nh(); }
	vector<float> &els_iso04_pf2012_nh() { return cms2.els_iso04_pf2012_nh(); }
	vector<float> &els_iso04_pf_ch() { return cms2.els_iso04_pf_ch(); }
	vector<float> &els_iso04_pf_gamma05() { return cms2.els_iso04_pf_gamma05(); }
	vector<float> &els_iso04_pf_nhad05() { return cms2.els_iso04_pf_nhad05(); }
	vector<float> &els_layer1_charge() { return cms2.els_layer1_charge(); }
	vector<float> &els_mass() { return cms2.els_mass(); }
	vector<float> &els_mc_patMatch_dr() { return cms2.els_mc_patMatch_dr(); }
	vector<float> &els_mva() { return cms2.els_mva(); }
	vector<float> &els_ndof() { return cms2.els_ndof(); }
	vector<float> &els_pfChargedHadronIso() { return cms2.els_pfChargedHadronIso(); }
	vector<float> &els_pfNeutralHadronIso() { return cms2.els_pfNeutralHadronIso(); }
	vector<float> &els_pfPUIso() { return cms2.els_pfPUIso(); }
	vector<float> &els_pfPhotonIso() { return cms2.els_pfPhotonIso(); }
	vector<float> &els_phiErr() { return cms2.els_phiErr(); }
	vector<float> &els_phiSC() { return cms2.els_phiSC(); }
	vector<float> &els_phiSCwidth() { return cms2.els_phiSCwidth(); }
	vector<float> &els_ptErr() { return cms2.els_ptErr(); }
	vector<float> &els_ptErrGsf() { return cms2.els_ptErrGsf(); }
	vector<float> &els_r9() { return cms2.els_r9(); }
	vector<float> &els_r9_full5x5() { return cms2.els_r9_full5x5(); }
	vector<float> &els_sigmaEtaEta() { return cms2.els_sigmaEtaEta(); }
	vector<float> &els_sigmaEtaEta_full5x5() { return cms2.els_sigmaEtaEta_full5x5(); }
	vector<float> &els_sigmaIEtaIEta() { return cms2.els_sigmaIEtaIEta(); }
	vector<float> &els_sigmaIEtaIEta_full5x5() { return cms2.els_sigmaIEtaIEta_full5x5(); }
	vector<float> &els_sigmaIEtaIPhi() { return cms2.els_sigmaIEtaIPhi(); }
	vector<float> &els_sigmaIPhiIPhi() { return cms2.els_sigmaIPhiIPhi(); }
	vector<float> &els_sigmaIPhiIPhi_full5x5() { return cms2.els_sigmaIPhiIPhi_full5x5(); }
	vector<float> &els_sigmaIphiIphi() { return cms2.els_sigmaIphiIphi(); }
	vector<float> &els_tkIso() { return cms2.els_tkIso(); }
	vector<float> &els_tkIso04() { return cms2.els_tkIso04(); }
	vector<float> &els_trackMomentumError() { return cms2.els_trackMomentumError(); }
	vector<float> &els_trkdr() { return cms2.els_trkdr(); }
	vector<float> &els_trkshFrac() { return cms2.els_trkshFrac(); }
	vector<float> &els_z0() { return cms2.els_z0(); }
	vector<float> &els_z0Err() { return cms2.els_z0Err(); }
	vector<float> &els_z0corr() { return cms2.els_z0corr(); }
	vector<float> &genps_charge() { return cms2.genps_charge(); }
	vector<float> &genps_iso() { return cms2.genps_iso(); }
	vector<float> &genps_mass() { return cms2.genps_mass(); }
	vector<float> &mus_backToBackCompat() { return cms2.mus_backToBackCompat(); }
	vector<float> &mus_best_dxyPV() { return cms2.mus_best_dxyPV(); }
	vector<float> &mus_best_dzPV() { return cms2.mus_best_dzPV(); }
	vector<float> &mus_bs2d() { return cms2.mus_bs2d(); }
	vector<float> &mus_bs2derr() { return cms2.mus_bs2derr(); }
	vector<float> &mus_bs3d() { return cms2.mus_bs3d(); }
	vector<float> &mus_bs3derr() { return cms2.mus_bs3derr(); }
	vector<float> &mus_caloCompatibility() { return cms2.mus_caloCompatibility(); }
	vector<float> &mus_chi2() { return cms2.mus_chi2(); }
	vector<float> &mus_chi2LocalMomentum() { return cms2.mus_chi2LocalMomentum(); }
	vector<float> &mus_chi2LocalPosition() { return cms2.mus_chi2LocalPosition(); }
	vector<float> &mus_cosmicCompat() { return cms2.mus_cosmicCompat(); }
	vector<float> &mus_d0() { return cms2.mus_d0(); }
	vector<float> &mus_d0Err() { return cms2.mus_d0Err(); }
	vector<float> &mus_d0corr() { return cms2.mus_d0corr(); }
	vector<float> &mus_d0corrPhi() { return cms2.mus_d0corrPhi(); }
	vector<float> &mus_d0phiCov() { return cms2.mus_d0phiCov(); }
	vector<float> &mus_dxyPV() { return cms2.mus_dxyPV(); }
	vector<float> &mus_dzPV() { return cms2.mus_dzPV(); }
	vector<float> &mus_ecal_time() { return cms2.mus_ecal_time(); }
	vector<float> &mus_ecal_timeError() { return cms2.mus_ecal_timeError(); }
	vector<float> &mus_e_em() { return cms2.mus_e_em(); }
	vector<float> &mus_e_emS9() { return cms2.mus_e_emS9(); }
	vector<float> &mus_e_had() { return cms2.mus_e_had(); }
	vector<float> &mus_e_hadS9() { return cms2.mus_e_hadS9(); }
	vector<float> &mus_e_ho() { return cms2.mus_e_ho(); }
	vector<float> &mus_e_hoS9() { return cms2.mus_e_hoS9(); }
	vector<float> &mus_emMax() { return cms2.mus_emMax(); }
	vector<float> &mus_emS25() { return cms2.mus_emS25(); }
	vector<float> &mus_etaErr() { return cms2.mus_etaErr(); }
	vector<float> &mus_gfit_chi2() { return cms2.mus_gfit_chi2(); }
	vector<float> &mus_gfit_d0() { return cms2.mus_gfit_d0(); }
	vector<float> &mus_gfit_d0Err() { return cms2.mus_gfit_d0Err(); }
	vector<float> &mus_gfit_d0corr() { return cms2.mus_gfit_d0corr(); }
	vector<float> &mus_gfit_d0corrPhi() { return cms2.mus_gfit_d0corrPhi(); }
	vector<float> &mus_gfit_d0phiCov() { return cms2.mus_gfit_d0phiCov(); }
	vector<float> &mus_gfit_ndof() { return cms2.mus_gfit_ndof(); }
	vector<float> &mus_gfit_qoverp() { return cms2.mus_gfit_qoverp(); }
	vector<float> &mus_gfit_qoverpError() { return cms2.mus_gfit_qoverpError(); }
	vector<float> &mus_gfit_z0() { return cms2.mus_gfit_z0(); }
	vector<float> &mus_gfit_z0Err() { return cms2.mus_gfit_z0Err(); }
	vector<float> &mus_gfit_z0corr() { return cms2.mus_gfit_z0corr(); }
	vector<float> &mus_glbKink() { return cms2.mus_glbKink(); }
	vector<float> &mus_glbTrackProbability() { return cms2.mus_glbTrackProbability(); }
	vector<float> &mus_globalDeltaEtaPhi() { return cms2.mus_globalDeltaEtaPhi(); }
	vector<float> &mus_hadMax() { return cms2.mus_hadMax(); }
	vector<float> &mus_hcal_time() { return cms2.mus_hcal_time(); }
	vector<float> &mus_hcal_timeError() { return cms2.mus_hcal_timeError(); }
	vector<float> &mus_ip2d() { return cms2.mus_ip2d(); }
	vector<float> &mus_ip2derr() { return cms2.mus_ip2derr(); }
	vector<float> &mus_ip3d() { return cms2.mus_ip3d(); }
	vector<float> &mus_ip3derr() { return cms2.mus_ip3derr(); }
	vector<float> &mus_iso03_emEt() { return cms2.mus_iso03_emEt(); }
	vector<float> &mus_iso03_hadEt() { return cms2.mus_iso03_hadEt(); }
	vector<float> &mus_iso03_hoEt() { return cms2.mus_iso03_hoEt(); }
	vector<float> &mus_iso03_sumPt() { return cms2.mus_iso03_sumPt(); }
	vector<float> &mus_iso05_emEt() { return cms2.mus_iso05_emEt(); }
	vector<float> &mus_iso05_hadEt() { return cms2.mus_iso05_hadEt(); }
	vector<float> &mus_iso05_hoEt() { return cms2.mus_iso05_hoEt(); }
	vector<float> &mus_iso05_sumPt() { return cms2.mus_iso05_sumPt(); }
	vector<float> &mus_isoMeanDRR03_pf_ChargedHadronPt() { return cms2.mus_isoMeanDRR03_pf_ChargedHadronPt(); }
	vector<float> &mus_isoMeanDRR03_pf_ChargedParticlePt() { return cms2.mus_isoMeanDRR03_pf_ChargedParticlePt(); }
	vector<float> &mus_isoMeanDRR03_pf_NeutralHadronEt() { return cms2.mus_isoMeanDRR03_pf_NeutralHadronEt(); }
	vector<float> &mus_isoMeanDRR03_pf_NeutralHadronEtHighThreshold() { return cms2.mus_isoMeanDRR03_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoMeanDRR03_pf_PUPt() { return cms2.mus_isoMeanDRR03_pf_PUPt(); }
	vector<float> &mus_isoMeanDRR03_pf_PhotonEt() { return cms2.mus_isoMeanDRR03_pf_PhotonEt(); }
	vector<float> &mus_isoMeanDRR03_pf_PhotonEtHighThreshold() { return cms2.mus_isoMeanDRR03_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoMeanDRR04_pf_ChargedHadronPt() { return cms2.mus_isoMeanDRR04_pf_ChargedHadronPt(); }
	vector<float> &mus_isoMeanDRR04_pf_ChargedParticlePt() { return cms2.mus_isoMeanDRR04_pf_ChargedParticlePt(); }
	vector<float> &mus_isoMeanDRR04_pf_NeutralHadronEt() { return cms2.mus_isoMeanDRR04_pf_NeutralHadronEt(); }
	vector<float> &mus_isoMeanDRR04_pf_NeutralHadronEtHighThreshold() { return cms2.mus_isoMeanDRR04_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoMeanDRR04_pf_PUPt() { return cms2.mus_isoMeanDRR04_pf_PUPt(); }
	vector<float> &mus_isoMeanDRR04_pf_PhotonEt() { return cms2.mus_isoMeanDRR04_pf_PhotonEt(); }
	vector<float> &mus_isoMeanDRR04_pf_PhotonEtHighThreshold() { return cms2.mus_isoMeanDRR04_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoR03_pf_ChargedHadronPt() { return cms2.mus_isoR03_pf_ChargedHadronPt(); }
	vector<float> &mus_isoR03_pf_ChargedParticlePt() { return cms2.mus_isoR03_pf_ChargedParticlePt(); }
	vector<float> &mus_isoR03_pf_NeutralHadronEt() { return cms2.mus_isoR03_pf_NeutralHadronEt(); }
	vector<float> &mus_isoR03_pf_NeutralHadronEtHighThreshold() { return cms2.mus_isoR03_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoR03_pf_PUPt() { return cms2.mus_isoR03_pf_PUPt(); }
	vector<float> &mus_isoR03_pf_PhotonEt() { return cms2.mus_isoR03_pf_PhotonEt(); }
	vector<float> &mus_isoR03_pf_PhotonEtHighThreshold() { return cms2.mus_isoR03_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoR04_pf_ChargedHadronPt() { return cms2.mus_isoR04_pf_ChargedHadronPt(); }
	vector<float> &mus_isoR04_pf_ChargedParticlePt() { return cms2.mus_isoR04_pf_ChargedParticlePt(); }
	vector<float> &mus_isoR04_pf_NeutralHadronEt() { return cms2.mus_isoR04_pf_NeutralHadronEt(); }
	vector<float> &mus_isoR04_pf_NeutralHadronEtHighThreshold() { return cms2.mus_isoR04_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoR04_pf_PUPt() { return cms2.mus_isoR04_pf_PUPt(); }
	vector<float> &mus_isoR04_pf_PhotonEt() { return cms2.mus_isoR04_pf_PhotonEt(); }
	vector<float> &mus_isoR04_pf_PhotonEtHighThreshold() { return cms2.mus_isoR04_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoSumDRR03_pf_ChargedHadronPt() { return cms2.mus_isoSumDRR03_pf_ChargedHadronPt(); }
	vector<float> &mus_isoSumDRR03_pf_ChargedParticlePt() { return cms2.mus_isoSumDRR03_pf_ChargedParticlePt(); }
	vector<float> &mus_isoSumDRR03_pf_NeutralHadronEt() { return cms2.mus_isoSumDRR03_pf_NeutralHadronEt(); }
	vector<float> &mus_isoSumDRR03_pf_NeutralHadronEtHighThreshold() { return cms2.mus_isoSumDRR03_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoSumDRR03_pf_PUPt() { return cms2.mus_isoSumDRR03_pf_PUPt(); }
	vector<float> &mus_isoSumDRR03_pf_PhotonEt() { return cms2.mus_isoSumDRR03_pf_PhotonEt(); }
	vector<float> &mus_isoSumDRR03_pf_PhotonEtHighThreshold() { return cms2.mus_isoSumDRR03_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoSumDRR04_pf_ChargedHadronPt() { return cms2.mus_isoSumDRR04_pf_ChargedHadronPt(); }
	vector<float> &mus_isoSumDRR04_pf_ChargedParticlePt() { return cms2.mus_isoSumDRR04_pf_ChargedParticlePt(); }
	vector<float> &mus_isoSumDRR04_pf_NeutralHadronEt() { return cms2.mus_isoSumDRR04_pf_NeutralHadronEt(); }
	vector<float> &mus_isoSumDRR04_pf_NeutralHadronEtHighThreshold() { return cms2.mus_isoSumDRR04_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoSumDRR04_pf_PUPt() { return cms2.mus_isoSumDRR04_pf_PUPt(); }
	vector<float> &mus_isoSumDRR04_pf_PhotonEt() { return cms2.mus_isoSumDRR04_pf_PhotonEt(); }
	vector<float> &mus_isoSumDRR04_pf_PhotonEtHighThreshold() { return cms2.mus_isoSumDRR04_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_iso_ecalvetoDep() { return cms2.mus_iso_ecalvetoDep(); }
	vector<float> &mus_iso_hcalvetoDep() { return cms2.mus_iso_hcalvetoDep(); }
	vector<float> &mus_iso_hovetoDep() { return cms2.mus_iso_hovetoDep(); }
	vector<float> &mus_iso_trckvetoDep() { return cms2.mus_iso_trckvetoDep(); }
	vector<float> &mus_localDistance() { return cms2.mus_localDistance(); }
	vector<float> &mus_mass() { return cms2.mus_mass(); }
	vector<float> &mus_mc_patMatch_dr() { return cms2.mus_mc_patMatch_dr(); }
	vector<float> &mus_ndof() { return cms2.mus_ndof(); }
	vector<float> &mus_overlapCompat() { return cms2.mus_overlapCompat(); }
	vector<float> &mus_phiErr() { return cms2.mus_phiErr(); }
	vector<float> &mus_ptErr() { return cms2.mus_ptErr(); }
	vector<float> &mus_qoverp() { return cms2.mus_qoverp(); }
	vector<float> &mus_qoverpError() { return cms2.mus_qoverpError(); }
	vector<float> &mus_segmCompatibility() { return cms2.mus_segmCompatibility(); }
	vector<float> &mus_staRelChi2() { return cms2.mus_staRelChi2(); }
	vector<float> &mus_sta_chi2() { return cms2.mus_sta_chi2(); }
	vector<float> &mus_sta_d0() { return cms2.mus_sta_d0(); }
	vector<float> &mus_sta_d0Err() { return cms2.mus_sta_d0Err(); }
	vector<float> &mus_sta_d0corr() { return cms2.mus_sta_d0corr(); }
	vector<float> &mus_sta_d0corrPhi() { return cms2.mus_sta_d0corrPhi(); }
	vector<float> &mus_sta_d0phiCov() { return cms2.mus_sta_d0phiCov(); }
	vector<float> &mus_sta_ndof() { return cms2.mus_sta_ndof(); }
	vector<float> &mus_sta_qoverp() { return cms2.mus_sta_qoverp(); }
	vector<float> &mus_sta_qoverpError() { return cms2.mus_sta_qoverpError(); }
	vector<float> &mus_sta_z0() { return cms2.mus_sta_z0(); }
	vector<float> &mus_sta_z0Err() { return cms2.mus_sta_z0Err(); }
	vector<float> &mus_sta_z0corr() { return cms2.mus_sta_z0corr(); }
	vector<float> &mus_timeAtIpInOut() { return cms2.mus_timeAtIpInOut(); }
	vector<float> &mus_timeAtIpInOutErr() { return cms2.mus_timeAtIpInOutErr(); }
	vector<float> &mus_timeAtIpOutIn() { return cms2.mus_timeAtIpOutIn(); }
	vector<float> &mus_timeAtIpOutInErr() { return cms2.mus_timeAtIpOutInErr(); }
	vector<float> &mus_timeCompat() { return cms2.mus_timeCompat(); }
	vector<float> &mus_tower() { return cms2.mus_tower(); }
	vector<float> &mus_towerS9() { return cms2.mus_towerS9(); }
	vector<float> &mus_trkKink() { return cms2.mus_trkKink(); }
	vector<float> &mus_trkRelChi2() { return cms2.mus_trkRelChi2(); }
	vector<float> &mus_vertexCompat() { return cms2.mus_vertexCompat(); }
	vector<float> &mus_vertexphi() { return cms2.mus_vertexphi(); }
	vector<float> &mus_z0() { return cms2.mus_z0(); }
	vector<float> &mus_z0Err() { return cms2.mus_z0Err(); }
	vector<float> &mus_z0corr() { return cms2.mus_z0corr(); }
	vector<float> &pfcands_dz() { return cms2.pfcands_dz(); }
	vector<float> &pfcands_mass() { return cms2.pfcands_mass(); }
	vector<float> &pfjets_area() { return cms2.pfjets_area(); }
	vector<float> &pfjets_chargedEmE() { return cms2.pfjets_chargedEmE(); }
	vector<float> &pfjets_chargedHadronE() { return cms2.pfjets_chargedHadronE(); }
	vector<float> &pfjets_combinedInclusiveSecondaryVertexV2BJetTag() { return cms2.pfjets_combinedInclusiveSecondaryVertexV2BJetTag(); }
	vector<float> &pfjets_combinedMVABJetTag() { return cms2.pfjets_combinedMVABJetTag(); }
	vector<float> &pfjets_corL1Fast() { return cms2.pfjets_corL1Fast(); }
	vector<float> &pfjets_corL1FastL2L3() { return cms2.pfjets_corL1FastL2L3(); }
	vector<float> &pfjets_corL2L3() { return cms2.pfjets_corL2L3(); }
	vector<float> &pfjets_electronE() { return cms2.pfjets_electronE(); }
	vector<float> &pfjets_hfEmE() { return cms2.pfjets_hfEmE(); }
	vector<float> &pfjets_hfHadronE() { return cms2.pfjets_hfHadronE(); }
	vector<float> &pfjets_jetBProbabilityBJetTag() { return cms2.pfjets_jetBProbabilityBJetTag(); }
	vector<float> &pfjets_jetProbabilityBJetTag() { return cms2.pfjets_jetProbabilityBJetTag(); }
	vector<float> &pfjets_mass() { return cms2.pfjets_mass(); }
	vector<float> &pfjets_muonE() { return cms2.pfjets_muonE(); }
	vector<float> &pfjets_neutralEmE() { return cms2.pfjets_neutralEmE(); }
	vector<float> &pfjets_neutralHadronE() { return cms2.pfjets_neutralHadronE(); }
	vector<float> &pfjets_pfCombinedSecondaryVertexBJetTag() { return cms2.pfjets_pfCombinedSecondaryVertexBJetTag(); }
	vector<float> &pfjets_photonE() { return cms2.pfjets_photonE(); }
	vector<float> &pfjets_pileupJetId() { return cms2.pfjets_pileupJetId(); }
	vector<float> &pfjets_simpleSecondaryVertexHighEffBJetTag() { return cms2.pfjets_simpleSecondaryVertexHighEffBJetTag(); }
	vector<float> &pfjets_simpleSecondaryVertexHighPurBJetTags() { return cms2.pfjets_simpleSecondaryVertexHighPurBJetTags(); }
	vector<float> &pfjets_trackCountingHighEffBJetTag() { return cms2.pfjets_trackCountingHighEffBJetTag(); }
	vector<float> &pfjets_trackCountingHighPurBJetTag() { return cms2.pfjets_trackCountingHighPurBJetTag(); }
	vector<float> &pfjets_undoJEC() { return cms2.pfjets_undoJEC(); }
	vector<float> &taus_pf_againstElectronDeadECAL() { return cms2.taus_pf_againstElectronDeadECAL(); }
	vector<float> &taus_pf_againstElectronLoose() { return cms2.taus_pf_againstElectronLoose(); }
	vector<float> &taus_pf_againstElectronMedium() { return cms2.taus_pf_againstElectronMedium(); }
	vector<float> &taus_pf_againstElectronTight() { return cms2.taus_pf_againstElectronTight(); }
	vector<float> &taus_pf_againstMuonLoose() { return cms2.taus_pf_againstMuonLoose(); }
	vector<float> &taus_pf_againstMuonLoose2() { return cms2.taus_pf_againstMuonLoose2(); }
	vector<float> &taus_pf_againstMuonLoose3() { return cms2.taus_pf_againstMuonLoose3(); }
	vector<float> &taus_pf_againstMuonMedium() { return cms2.taus_pf_againstMuonMedium(); }
	vector<float> &taus_pf_againstMuonMedium2() { return cms2.taus_pf_againstMuonMedium2(); }
	vector<float> &taus_pf_againstMuonTight() { return cms2.taus_pf_againstMuonTight(); }
	vector<float> &taus_pf_againstMuonTight2() { return cms2.taus_pf_againstMuonTight2(); }
	vector<float> &taus_pf_againstMuonTight3() { return cms2.taus_pf_againstMuonTight3(); }
	vector<float> &taus_pf_byCombinedIsolationDeltaBetaCorrRaw() { return cms2.taus_pf_byCombinedIsolationDeltaBetaCorrRaw(); }
	vector<float> &taus_pf_byCombinedIsolationDeltaBetaCorrRaw3Hits() { return cms2.taus_pf_byCombinedIsolationDeltaBetaCorrRaw3Hits(); }
	vector<float> &taus_pf_byDecayModeFinding() { return cms2.taus_pf_byDecayModeFinding(); }
	vector<float> &taus_pf_byLooseCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byLooseCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits() { return cms2.taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits(); }
	vector<float> &taus_pf_byMediumCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byMediumCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_byMediumCombinedIsolationDeltaBetaCorr3Hits() { return cms2.taus_pf_byMediumCombinedIsolationDeltaBetaCorr3Hits(); }
	vector<float> &taus_pf_byTightCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byTightCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_byTightCombinedIsolationDeltaBetaCorr3Hits() { return cms2.taus_pf_byTightCombinedIsolationDeltaBetaCorr3Hits(); }
	vector<float> &taus_pf_byVLooseCombinedIsolationDeltaBetaCorr() { return cms2.taus_pf_byVLooseCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_mass() { return cms2.taus_pf_mass(); }
	vector<float> &photons_chargedHadronIso() { return cms2.photons_chargedHadronIso(); }
	vector<float> &photons_e1x5() { return cms2.photons_e1x5(); }
	vector<float> &photons_e2x5Max() { return cms2.photons_e2x5Max(); }
	vector<float> &photons_e3x3() { return cms2.photons_e3x3(); }
	vector<float> &photons_e5x5() { return cms2.photons_e5x5(); }
	vector<float> &photons_ecalIso03() { return cms2.photons_ecalIso03(); }
	vector<float> &photons_ecalIso04() { return cms2.photons_ecalIso04(); }
	vector<float> &photons_full3x3_e3x3() { return cms2.photons_full3x3_e3x3(); }
	vector<float> &photons_full5x5_e1x5() { return cms2.photons_full5x5_e1x5(); }
	vector<float> &photons_full5x5_e2x5Max() { return cms2.photons_full5x5_e2x5Max(); }
	vector<float> &photons_full5x5_e5x5() { return cms2.photons_full5x5_e5x5(); }
	vector<float> &photons_full5x5_hOverE() { return cms2.photons_full5x5_hOverE(); }
	vector<float> &photons_full5x5_hOverEtowBC() { return cms2.photons_full5x5_hOverEtowBC(); }
	vector<float> &photons_full5x5_r9() { return cms2.photons_full5x5_r9(); }
	vector<float> &photons_full5x5_sigmaEtaEta() { return cms2.photons_full5x5_sigmaEtaEta(); }
	vector<float> &photons_full5x5_sigmaIEtaIEta() { return cms2.photons_full5x5_sigmaIEtaIEta(); }
	vector<float> &photons_hOverE() { return cms2.photons_hOverE(); }
	vector<float> &photons_hcalDepth1TowerSumEtBcConeDR03() { return cms2.photons_hcalDepth1TowerSumEtBcConeDR03(); }
	vector<float> &photons_hcalDepth1TowerSumEtBcConeDR04() { return cms2.photons_hcalDepth1TowerSumEtBcConeDR04(); }
	vector<float> &photons_hcalDepth2TowerSumEtBcConeDR03() { return cms2.photons_hcalDepth2TowerSumEtBcConeDR03(); }
	vector<float> &photons_hcalDepth2TowerSumEtBcConeDR04() { return cms2.photons_hcalDepth2TowerSumEtBcConeDR04(); }
	vector<float> &photons_hcalIso03() { return cms2.photons_hcalIso03(); }
	vector<float> &photons_hcalIso04() { return cms2.photons_hcalIso04(); }
	vector<float> &photons_hcalTowerSumEtBcConeDR03() { return cms2.photons_hcalTowerSumEtBcConeDR03(); }
	vector<float> &photons_hcalTowerSumEtBcConeDR04() { return cms2.photons_hcalTowerSumEtBcConeDR04(); }
	vector<float> &photons_mass() { return cms2.photons_mass(); }
	vector<float> &photons_neutralHadronIso() { return cms2.photons_neutralHadronIso(); }
	vector<float> &photons_ntkIsoHollow03() { return cms2.photons_ntkIsoHollow03(); }
	vector<float> &photons_ntkIsoHollow04() { return cms2.photons_ntkIsoHollow04(); }
	vector<float> &photons_ntkIsoSolid03() { return cms2.photons_ntkIsoSolid03(); }
	vector<float> &photons_ntkIsoSolid04() { return cms2.photons_ntkIsoSolid04(); }
	vector<float> &photons_photonIso() { return cms2.photons_photonIso(); }
	vector<float> &photons_recoChargedHadronIso() { return cms2.photons_recoChargedHadronIso(); }
	vector<float> &photons_recoNeutralHadronIso() { return cms2.photons_recoNeutralHadronIso(); }
	vector<float> &photons_recoPhotonIso() { return cms2.photons_recoPhotonIso(); }
	vector<float> &photons_sigmaEtaEta() { return cms2.photons_sigmaEtaEta(); }
	vector<float> &photons_sigmaIEtaIEta() { return cms2.photons_sigmaIEtaIEta(); }
	vector<float> &photons_tkIsoHollow03() { return cms2.photons_tkIsoHollow03(); }
	vector<float> &photons_tkIsoHollow04() { return cms2.photons_tkIsoHollow04(); }
	vector<float> &photons_tkIsoSolid03() { return cms2.photons_tkIsoSolid03(); }
	vector<float> &photons_tkIsoSolid04() { return cms2.photons_tkIsoSolid04(); }
	vector<float> &puInfo_trueNumInteractions() { return cms2.puInfo_trueNumInteractions(); }
	vector<float> &convs_chi2() { return cms2.convs_chi2(); }
	vector<float> &convs_dl() { return cms2.convs_dl(); }
	vector<float> &convs_ndof() { return cms2.convs_ndof(); }
	vector<float> &sparm_values() { return cms2.sparm_values(); }
	vector<float> &svs_anglePV() { return cms2.svs_anglePV(); }
	vector<float> &svs_chi2() { return cms2.svs_chi2(); }
	vector<float> &svs_dist3Dsig() { return cms2.svs_dist3Dsig(); }
	vector<float> &svs_dist3Dval() { return cms2.svs_dist3Dval(); }
	vector<float> &svs_distXYsig() { return cms2.svs_distXYsig(); }
	vector<float> &svs_distXYval() { return cms2.svs_distXYval(); }
	vector<float> &svs_ndof() { return cms2.svs_ndof(); }
	vector<float> &svs_prob() { return cms2.svs_prob(); }
	vector<float> &svs_xError() { return cms2.svs_xError(); }
	vector<float> &svs_yError() { return cms2.svs_yError(); }
	vector<float> &svs_zError() { return cms2.svs_zError(); }
	vector<float> &ak8jets_area() { return cms2.ak8jets_area(); }
	vector<float> &ak8jets_chargedEmE() { return cms2.ak8jets_chargedEmE(); }
	vector<float> &ak8jets_chargedHadronE() { return cms2.ak8jets_chargedHadronE(); }
	vector<float> &ak8jets_combinedSecondaryVertexBJetTag() { return cms2.ak8jets_combinedSecondaryVertexBJetTag(); }
	vector<float> &ak8jets_electronE() { return cms2.ak8jets_electronE(); }
	vector<float> &ak8jets_filteredMass() { return cms2.ak8jets_filteredMass(); }
	vector<float> &ak8jets_hfEmE() { return cms2.ak8jets_hfEmE(); }
	vector<float> &ak8jets_hfHadronE() { return cms2.ak8jets_hfHadronE(); }
	vector<float> &ak8jets_jetBProbabilityBJetTag() { return cms2.ak8jets_jetBProbabilityBJetTag(); }
	vector<float> &ak8jets_jetProbabilityBJetTag() { return cms2.ak8jets_jetProbabilityBJetTag(); }
	vector<float> &ak8jets_mass() { return cms2.ak8jets_mass(); }
	vector<float> &ak8jets_muonE() { return cms2.ak8jets_muonE(); }
	vector<float> &ak8jets_nJettinessTau1() { return cms2.ak8jets_nJettinessTau1(); }
	vector<float> &ak8jets_nJettinessTau2() { return cms2.ak8jets_nJettinessTau2(); }
	vector<float> &ak8jets_nJettinessTau3() { return cms2.ak8jets_nJettinessTau3(); }
	vector<float> &ak8jets_neutralEmE() { return cms2.ak8jets_neutralEmE(); }
	vector<float> &ak8jets_neutralHadronE() { return cms2.ak8jets_neutralHadronE(); }
	vector<float> &ak8jets_photonE() { return cms2.ak8jets_photonE(); }
	vector<float> &ak8jets_pileupJetId() { return cms2.ak8jets_pileupJetId(); }
	vector<float> &ak8jets_prunedMass() { return cms2.ak8jets_prunedMass(); }
	vector<float> &ak8jets_qJetsVolatility() { return cms2.ak8jets_qJetsVolatility(); }
	vector<float> &ak8jets_simpleSecondaryVertexHighEffBJetTag() { return cms2.ak8jets_simpleSecondaryVertexHighEffBJetTag(); }
	vector<float> &ak8jets_simpleSecondaryVertexHighPurBJetTags() { return cms2.ak8jets_simpleSecondaryVertexHighPurBJetTags(); }
	vector<float> &ak8jets_topJetMass() { return cms2.ak8jets_topJetMass(); }
	vector<float> &ak8jets_trackCountingHighEffBJetTag() { return cms2.ak8jets_trackCountingHighEffBJetTag(); }
	vector<float> &ak8jets_trackCountingHighPurBJetTag() { return cms2.ak8jets_trackCountingHighPurBJetTag(); }
	vector<float> &ak8jets_trimmedMass() { return cms2.ak8jets_trimmedMass(); }
	vector<float> &ak8jets_undoJEC() { return cms2.ak8jets_undoJEC(); }
	vector<float> &vtxs_chi2() { return cms2.vtxs_chi2(); }
	vector<float> &vtxs_ndof() { return cms2.vtxs_ndof(); }
	vector<float> &vtxs_sumpt() { return cms2.vtxs_sumpt(); }
	vector<float> &vtxs_xError() { return cms2.vtxs_xError(); }
	vector<float> &vtxs_yError() { return cms2.vtxs_yError(); }
	vector<float> &vtxs_zError() { return cms2.vtxs_zError(); }
	vector<vector<float> > &mus_stationShowerDeltaR() { return cms2.mus_stationShowerDeltaR(); }
	vector<vector<float> > &mus_stationShowerSizeT() { return cms2.mus_stationShowerSizeT(); }
	vector<vector<float> > &puInfo_instLumi() { return cms2.puInfo_instLumi(); }
	vector<vector<float> > &vtxs_covMatrix() { return cms2.vtxs_covMatrix(); }
	int &evt_bsType() { return cms2.evt_bsType(); }
	int &evt_bunchCrossing() { return cms2.evt_bunchCrossing(); }
	int &evt_experimentType() { return cms2.evt_experimentType(); }
	int &evt_isRealData() { return cms2.evt_isRealData(); }
	int &evt_orbitNumber() { return cms2.evt_orbitNumber(); }
	int &evt_storeNumber() { return cms2.evt_storeNumber(); }
	int &hcalnoise_GetRecHitCount() { return cms2.hcalnoise_GetRecHitCount(); }
	int &hcalnoise_GetRecHitCount15() { return cms2.hcalnoise_GetRecHitCount15(); }
	int &hcalnoise_maxHPDHits() { return cms2.hcalnoise_maxHPDHits(); }
	int &hcalnoise_maxHPDNoOtherHits() { return cms2.hcalnoise_maxHPDNoOtherHits(); }
	int &hcalnoise_maxRBXHits() { return cms2.hcalnoise_maxRBXHits(); }
	int &hcalnoise_maxZeros() { return cms2.hcalnoise_maxZeros(); }
	int &hcalnoise_noiseFilterStatus() { return cms2.hcalnoise_noiseFilterStatus(); }
	int &hcalnoise_noiseType() { return cms2.hcalnoise_noiseType(); }
	int &hcalnoise_num10GeVHits() { return cms2.hcalnoise_num10GeVHits(); }
	int &hcalnoise_num25GeVHits() { return cms2.hcalnoise_num25GeVHits(); }
	int &hcalnoise_numFlatNoiseChannels() { return cms2.hcalnoise_numFlatNoiseChannels(); }
	int &hcalnoise_numIsolatedNoiseChannels() { return cms2.hcalnoise_numIsolatedNoiseChannels(); }
	int &hcalnoise_numProblematicRBXs() { return cms2.hcalnoise_numProblematicRBXs(); }
	int &hcalnoise_numSpikeNoiseChannels() { return cms2.hcalnoise_numSpikeNoiseChannels(); }
	int &hcalnoise_numTS4TS5NoiseChannels() { return cms2.hcalnoise_numTS4TS5NoiseChannels(); }
	int &hcalnoise_numTriangleNoiseChannels() { return cms2.hcalnoise_numTriangleNoiseChannels(); }
	int &hcalnoise_passHighLevelNoiseFilter() { return cms2.hcalnoise_passHighLevelNoiseFilter(); }
	int &hcalnoise_passLooseNoiseFilter() { return cms2.hcalnoise_passLooseNoiseFilter(); }
	int &hcalnoise_passTightNoiseFilter() { return cms2.hcalnoise_passTightNoiseFilter(); }
	int &pdfinfo_id1() { return cms2.pdfinfo_id1(); }
	int &pdfinfo_id2() { return cms2.pdfinfo_id2(); }
	int &sparm_subProcessId() { return cms2.sparm_subProcessId(); }
	vector<int> &els_mc3_id() { return cms2.els_mc3_id(); }
	vector<int> &els_mc3idx() { return cms2.els_mc3idx(); }
	vector<int> &els_mc3_motherid() { return cms2.els_mc3_motherid(); }
	vector<int> &els_mc3_motheridx() { return cms2.els_mc3_motheridx(); }
	vector<int> &els_mc_id() { return cms2.els_mc_id(); }
	vector<int> &els_mcidx() { return cms2.els_mcidx(); }
	vector<int> &els_mc_motherid() { return cms2.els_mc_motherid(); }
	vector<int> &mus_mc3_id() { return cms2.mus_mc3_id(); }
	vector<int> &mus_mc3idx() { return cms2.mus_mc3idx(); }
	vector<int> &mus_mc3_motherid() { return cms2.mus_mc3_motherid(); }
	vector<int> &mus_mc3_motheridx() { return cms2.mus_mc3_motheridx(); }
	vector<int> &mus_mc_id() { return cms2.mus_mc_id(); }
	vector<int> &mus_mcidx() { return cms2.mus_mcidx(); }
	vector<int> &mus_mc_motherid() { return cms2.mus_mc_motherid(); }
	vector<int> &pfjets_mc3_id() { return cms2.pfjets_mc3_id(); }
	vector<int> &pfjets_mc3idx() { return cms2.pfjets_mc3idx(); }
	vector<int> &pfjets_mc_gpidx() { return cms2.pfjets_mc_gpidx(); }
	vector<int> &pfjets_mc_id() { return cms2.pfjets_mc_id(); }
	vector<int> &pfjets_mcidx() { return cms2.pfjets_mcidx(); }
	vector<int> &pfjets_mc_motherid() { return cms2.pfjets_mc_motherid(); }
	vector<int> &photons_mc3_id() { return cms2.photons_mc3_id(); }
	vector<int> &photons_mc3idx() { return cms2.photons_mc3idx(); }
	vector<int> &photons_mc3_motherid() { return cms2.photons_mc3_motherid(); }
	vector<int> &photons_mc3_motheridx() { return cms2.photons_mc3_motheridx(); }
	vector<int> &photons_mc_id() { return cms2.photons_mc_id(); }
	vector<int> &photons_mcidx() { return cms2.photons_mcidx(); }
	vector<int> &photons_mc_motherid() { return cms2.photons_mc_motherid(); }
	vector<int> &els_category() { return cms2.els_category(); }
	vector<int> &els_charge() { return cms2.els_charge(); }
	vector<int> &els_ckf_charge() { return cms2.els_ckf_charge(); }
	vector<int> &els_ckf_laywithmeas() { return cms2.els_ckf_laywithmeas(); }
	vector<int> &els_class() { return cms2.els_class(); }
	vector<int> &els_exp_innerlayers() { return cms2.els_exp_innerlayers(); }
	vector<int> &els_exp_outerlayers() { return cms2.els_exp_outerlayers(); }
	vector<int> &els_fiduciality() { return cms2.els_fiduciality(); }
	vector<int> &els_gsftrkidx() { return cms2.els_gsftrkidx(); }
	vector<int> &els_layer1_det() { return cms2.els_layer1_det(); }
	vector<int> &els_layer1_layer() { return cms2.els_layer1_layer(); }
	vector<int> &els_layer1_sizerphi() { return cms2.els_layer1_sizerphi(); }
	vector<int> &els_layer1_sizerz() { return cms2.els_layer1_sizerz(); }
	vector<int> &els_lostHits() { return cms2.els_lostHits(); }
	vector<int> &els_lost_pixelhits() { return cms2.els_lost_pixelhits(); }
	vector<int> &els_mc_patMatch_id() { return cms2.els_mc_patMatch_id(); }
	vector<int> &els_nSeed() { return cms2.els_nSeed(); }
	vector<int> &els_nlayers() { return cms2.els_nlayers(); }
	vector<int> &els_nlayers3D() { return cms2.els_nlayers3D(); }
	vector<int> &els_nlayersLost() { return cms2.els_nlayersLost(); }
	vector<int> &els_sccharge() { return cms2.els_sccharge(); }
	vector<int> &els_scindex() { return cms2.els_scindex(); }
	vector<int> &els_trk_charge() { return cms2.els_trk_charge(); }
	vector<int> &els_trkidx() { return cms2.els_trkidx(); }
	vector<int> &els_type() { return cms2.els_type(); }
	vector<int> &els_validHits() { return cms2.els_validHits(); }
	vector<int> &els_valid_pixelhits() { return cms2.els_valid_pixelhits(); }
	vector<int> &els_passLooseId() { return cms2.els_passLooseId(); }
	vector<int> &els_passMediumId() { return cms2.els_passMediumId(); }
	vector<int> &els_passTightId() { return cms2.els_passTightId(); }
	vector<int> &els_passVetoId() { return cms2.els_passVetoId(); }
	vector<int> &genps_id() { return cms2.genps_id(); }
	vector<int> &genps_id_mother() { return cms2.genps_id_mother(); }
	vector<int> &genps_id_simplegrandma() { return cms2.genps_id_simplegrandma(); }
	vector<int> &genps_id_simplemother() { return cms2.genps_id_simplemother(); }
	vector<int> &genps_idx_mother() { return cms2.genps_idx_mother(); }
	vector<int> &genps_idx_simplemother() { return cms2.genps_idx_simplemother(); }
	vector<int> &genps_status() { return cms2.genps_status(); }
	vector<int> &hyp_ll_charge() { return cms2.hyp_ll_charge(); }
	vector<int> &hyp_ll_id() { return cms2.hyp_ll_id(); }
	vector<int> &hyp_ll_index() { return cms2.hyp_ll_index(); }
	vector<int> &hyp_lt_charge() { return cms2.hyp_lt_charge(); }
	vector<int> &hyp_lt_id() { return cms2.hyp_lt_id(); }
	vector<int> &hyp_lt_index() { return cms2.hyp_lt_index(); }
	vector<int> &hyp_type() { return cms2.hyp_type(); }
	vector<int> &mus_algo() { return cms2.mus_algo(); }
	vector<int> &mus_charge() { return cms2.mus_charge(); }
	vector<int> &mus_ecal_rawId() { return cms2.mus_ecal_rawId(); }
	vector<int> &mus_exp_innerlayers() { return cms2.mus_exp_innerlayers(); }
	vector<int> &mus_exp_outerlayers() { return cms2.mus_exp_outerlayers(); }
	vector<int> &mus_gfit_algo() { return cms2.mus_gfit_algo(); }
	vector<int> &mus_gfit_etaErr() { return cms2.mus_gfit_etaErr(); }
	vector<int> &mus_gfit_exp_innerlayer() { return cms2.mus_gfit_exp_innerlayer(); }
	vector<int> &mus_gfit_exp_outerlayer() { return cms2.mus_gfit_exp_outerlayer(); }
	vector<int> &mus_gfit_lostHits() { return cms2.mus_gfit_lostHits(); }
	vector<int> &mus_gfit_lostPixelHits() { return cms2.mus_gfit_lostPixelHits(); }
	vector<int> &mus_gfit_nlayers() { return cms2.mus_gfit_nlayers(); }
	vector<int> &mus_gfit_nlayers3D() { return cms2.mus_gfit_nlayers3D(); }
	vector<int> &mus_gfit_nlayersLost() { return cms2.mus_gfit_nlayersLost(); }
	vector<int> &mus_gfit_phiErr() { return cms2.mus_gfit_phiErr(); }
	vector<int> &mus_gfit_ptErr() { return cms2.mus_gfit_ptErr(); }
	vector<int> &mus_gfit_qualityMask() { return cms2.mus_gfit_qualityMask(); }
	vector<int> &mus_gfit_trk_charge() { return cms2.mus_gfit_trk_charge(); }
	vector<int> &mus_gfit_validHits() { return cms2.mus_gfit_validHits(); }
	vector<int> &mus_gfit_validPixelHits() { return cms2.mus_gfit_validPixelHits(); }
	vector<int> &mus_gfit_validSTAHits() { return cms2.mus_gfit_validSTAHits(); }
	vector<int> &mus_gfit_validSiHits() { return cms2.mus_gfit_validSiHits(); }
	vector<int> &mus_goodmask() { return cms2.mus_goodmask(); }
	vector<int> &mus_hcal_rawId() { return cms2.mus_hcal_rawId(); }
	vector<int> &mus_iso03_njets() { return cms2.mus_iso03_njets(); }
	vector<int> &mus_iso03_ntrk() { return cms2.mus_iso03_ntrk(); }
	vector<int> &mus_iso05_ntrk() { return cms2.mus_iso05_ntrk(); }
	vector<int> &mus_lostHits() { return cms2.mus_lostHits(); }
	vector<int> &mus_lostPixelHits() { return cms2.mus_lostPixelHits(); }
	vector<int> &mus_mc_patMatch_id() { return cms2.mus_mc_patMatch_id(); }
	vector<int> &mus_muonBestTrackType() { return cms2.mus_muonBestTrackType(); }
	vector<int> &mus_nOverlaps() { return cms2.mus_nOverlaps(); }
	vector<int> &mus_nlayers() { return cms2.mus_nlayers(); }
	vector<int> &mus_nlayers3D() { return cms2.mus_nlayers3D(); }
	vector<int> &mus_nlayersLost() { return cms2.mus_nlayersLost(); }
	vector<int> &mus_nmatches() { return cms2.mus_nmatches(); }
	vector<int> &mus_numberOfMatchedStations() { return cms2.mus_numberOfMatchedStations(); }
	vector<int> &mus_overlap0() { return cms2.mus_overlap0(); }
	vector<int> &mus_overlap1() { return cms2.mus_overlap1(); }
	vector<int> &mus_pfcharge() { return cms2.mus_pfcharge(); }
	vector<int> &mus_pfidx() { return cms2.mus_pfidx(); }
	vector<int> &mus_pfparticleId() { return cms2.mus_pfparticleId(); }
	vector<int> &mus_pid_PFMuon() { return cms2.mus_pid_PFMuon(); }
	vector<int> &mus_pid_TM2DCompatibilityLoose() { return cms2.mus_pid_TM2DCompatibilityLoose(); }
	vector<int> &mus_pid_TM2DCompatibilityTight() { return cms2.mus_pid_TM2DCompatibilityTight(); }
	vector<int> &mus_pid_TMLastStationLoose() { return cms2.mus_pid_TMLastStationLoose(); }
	vector<int> &mus_pid_TMLastStationTight() { return cms2.mus_pid_TMLastStationTight(); }
	vector<int> &mus_qualityMask() { return cms2.mus_qualityMask(); }
	vector<int> &mus_sta_algo() { return cms2.mus_sta_algo(); }
	vector<int> &mus_sta_etaErr() { return cms2.mus_sta_etaErr(); }
	vector<int> &mus_sta_exp_innerlayer() { return cms2.mus_sta_exp_innerlayer(); }
	vector<int> &mus_sta_exp_outerlayer() { return cms2.mus_sta_exp_outerlayer(); }
	vector<int> &mus_sta_lostHits() { return cms2.mus_sta_lostHits(); }
	vector<int> &mus_sta_lostPixelHits() { return cms2.mus_sta_lostPixelHits(); }
	vector<int> &mus_sta_nlayers() { return cms2.mus_sta_nlayers(); }
	vector<int> &mus_sta_nlayers3D() { return cms2.mus_sta_nlayers3D(); }
	vector<int> &mus_sta_nlayersLost() { return cms2.mus_sta_nlayersLost(); }
	vector<int> &mus_sta_phiErr() { return cms2.mus_sta_phiErr(); }
	vector<int> &mus_sta_ptErr() { return cms2.mus_sta_ptErr(); }
	vector<int> &mus_sta_qualityMask() { return cms2.mus_sta_qualityMask(); }
	vector<int> &mus_sta_trk_charge() { return cms2.mus_sta_trk_charge(); }
	vector<int> &mus_sta_validHits() { return cms2.mus_sta_validHits(); }
	vector<int> &mus_sta_validPixelHits() { return cms2.mus_sta_validPixelHits(); }
	vector<int> &mus_timeDirection() { return cms2.mus_timeDirection(); }
	vector<int> &mus_timeNumStationsUsed() { return cms2.mus_timeNumStationsUsed(); }
	vector<int> &mus_trk_charge() { return cms2.mus_trk_charge(); }
	vector<int> &mus_trkidx() { return cms2.mus_trkidx(); }
	vector<int> &mus_type() { return cms2.mus_type(); }
	vector<int> &mus_validHits() { return cms2.mus_validHits(); }
	vector<int> &mus_validPixelHits() { return cms2.mus_validPixelHits(); }
	vector<int> &pfcands_charge() { return cms2.pfcands_charge(); }
	vector<int> &pfcands_particleId() { return cms2.pfcands_particleId(); }
	vector<int> &pfjets_chargedHadronMultiplicity() { return cms2.pfjets_chargedHadronMultiplicity(); }
	vector<int> &pfjets_chargedMultiplicity() { return cms2.pfjets_chargedMultiplicity(); }
	vector<int> &pfjets_electronMultiplicity() { return cms2.pfjets_electronMultiplicity(); }
	vector<int> &pfjets_hfEmMultiplicity() { return cms2.pfjets_hfEmMultiplicity(); }
	vector<int> &pfjets_hfHadronMultiplicity() { return cms2.pfjets_hfHadronMultiplicity(); }
	vector<int> &pfjets_muonMultiplicity() { return cms2.pfjets_muonMultiplicity(); }
	vector<int> &pfjets_neutralHadronMultiplicity() { return cms2.pfjets_neutralHadronMultiplicity(); }
	vector<int> &pfjets_neutralMultiplicity() { return cms2.pfjets_neutralMultiplicity(); }
	vector<int> &pfjets_partonFlavour() { return cms2.pfjets_partonFlavour(); }
	vector<int> &pfjets_photonMultiplicity() { return cms2.pfjets_photonMultiplicity(); }
	vector<int> &taus_pf_charge() { return cms2.taus_pf_charge(); }
	vector<int> &photons_fiduciality() { return cms2.photons_fiduciality(); }
	vector<int> &photons_photonID_loose() { return cms2.photons_photonID_loose(); }
	vector<int> &photons_photonID_tight() { return cms2.photons_photonID_tight(); }
	vector<int> &puInfo_bunchCrossing() { return cms2.puInfo_bunchCrossing(); }
	vector<int> &puInfo_nPUvertices() { return cms2.puInfo_nPUvertices(); }
	vector<int> &convs_algo() { return cms2.convs_algo(); }
	vector<int> &convs_isConverted() { return cms2.convs_isConverted(); }
	vector<int> &convs_quality() { return cms2.convs_quality(); }
	vector<int> &svs_nTrks() { return cms2.svs_nTrks(); }
	vector<int> &ak8jets_chargedHadronMultiplicity() { return cms2.ak8jets_chargedHadronMultiplicity(); }
	vector<int> &ak8jets_chargedMultiplicity() { return cms2.ak8jets_chargedMultiplicity(); }
	vector<int> &ak8jets_electronMultiplicity() { return cms2.ak8jets_electronMultiplicity(); }
	vector<int> &ak8jets_hfEmMultiplicity() { return cms2.ak8jets_hfEmMultiplicity(); }
	vector<int> &ak8jets_hfHadronMultiplicity() { return cms2.ak8jets_hfHadronMultiplicity(); }
	vector<int> &ak8jets_muonMultiplicity() { return cms2.ak8jets_muonMultiplicity(); }
	vector<int> &ak8jets_neutralHadronMultiplicity() { return cms2.ak8jets_neutralHadronMultiplicity(); }
	vector<int> &ak8jets_neutralMultiplicity() { return cms2.ak8jets_neutralMultiplicity(); }
	vector<int> &ak8jets_partonFlavour() { return cms2.ak8jets_partonFlavour(); }
	vector<int> &ak8jets_photonMultiplicity() { return cms2.ak8jets_photonMultiplicity(); }
	vector<int> &vtxs_isFake() { return cms2.vtxs_isFake(); }
	vector<int> &vtxs_isValid() { return cms2.vtxs_isValid(); }
	vector<int> &vtxs_tracksSize() { return cms2.vtxs_tracksSize(); }
	vector<vector<int> > &els_PFCand_idx() { return cms2.els_PFCand_idx(); }
	vector<vector<int> > &genps_lepdaughter_id() { return cms2.genps_lepdaughter_id(); }
	vector<vector<int> > &genps_lepdaughter_idx() { return cms2.genps_lepdaughter_idx(); }
	vector<vector<int> > &hlt_trigObjs_id() { return cms2.hlt_trigObjs_id(); }
	vector<vector<int> > &mus_nStationCorrelatedHits() { return cms2.mus_nStationCorrelatedHits(); }
	vector<vector<int> > &mus_nStationHits() { return cms2.mus_nStationHits(); }
	vector<vector<int> > &pfjets_pfcandIndicies() { return cms2.pfjets_pfcandIndicies(); }
	vector<vector<int> > &photons_PFCand_idx() { return cms2.photons_PFCand_idx(); }
	vector<vector<int> > &convs_nHitsBeforeVtx() { return cms2.convs_nHitsBeforeVtx(); }
	vector<vector<int> > &convs_tkalgo() { return cms2.convs_tkalgo(); }
	vector<vector<int> > &convs_tkidx() { return cms2.convs_tkidx(); }
	vector<vector<int> > &ak8jets_pfcandIndicies() { return cms2.ak8jets_pfcandIndicies(); }
	vector<unsigned char> &pfcands_fromPV() { return cms2.pfcands_fromPV(); }
	unsigned int &els_HLT_Ele17_Ele8_L1sL1DoubleEG137_version() { return cms2.els_HLT_Ele17_Ele8_L1sL1DoubleEG137_version(); }
	unsigned int &els_HLT_Ele17_Ele8_LeadingLeg_version() { return cms2.els_HLT_Ele17_Ele8_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_Mass50_LeadingLeg_version() { return cms2.els_HLT_Ele17_Ele8_Mass50_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_Mass50_TrailingLeg_version() { return cms2.els_HLT_Ele17_Ele8_Mass50_TrailingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_TrailingLeg_version() { return cms2.els_HLT_Ele17_Ele8_TrailingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_version() { return cms2.els_HLT_Ele17_Ele8_version(); }
	unsigned int &els_HLT_Ele20_SC4_Mass50_LeadingLeg_version() { return cms2.els_HLT_Ele20_SC4_Mass50_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele20_SC4_Mass50_TrailingLeg_version() { return cms2.els_HLT_Ele20_SC4_Mass50_TrailingLeg_version(); }
	unsigned int &els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22_version() { return cms2.els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22_version(); }
	unsigned int &els_HLT_Ele27_WP80_version() { return cms2.els_HLT_Ele27_WP80_version(); }
	unsigned int &els_HLT_Ele32_SC17_Mass50_LeadingLeg_version() { return cms2.els_HLT_Ele32_SC17_Mass50_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele32_SC17_Mass50_TrailingLeg_version() { return cms2.els_HLT_Ele32_SC17_Mass50_TrailingLeg_version(); }
	unsigned int &els_HLT_Mu17_Ele8_TrailingLeg_version() { return cms2.els_HLT_Mu17_Ele8_TrailingLeg_version(); }
	unsigned int &els_HLT_Mu17_Ele8_version() { return cms2.els_HLT_Mu17_Ele8_version(); }
	unsigned int &els_HLT_Mu8_Ele17_version() { return cms2.els_HLT_Mu8_Ele17_version(); }
	unsigned int &evt_nels() { return cms2.evt_nels(); }
	unsigned int &evt_detectorStatus() { return cms2.evt_detectorStatus(); }
	unsigned int &evt_event() { return cms2.evt_event(); }
	unsigned int &evt_lumiBlock() { return cms2.evt_lumiBlock(); }
	unsigned int &evt_run() { return cms2.evt_run(); }
	unsigned int &evt_ngenjetsNoMuNoNu() { return cms2.evt_ngenjetsNoMuNoNu(); }
	unsigned int &genps_signalProcessID() { return cms2.genps_signalProcessID(); }
	unsigned int &mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1_version() { return cms2.mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1_version(); }
	unsigned int &mus_HLT_IsoMu24_eta2p1_version() { return cms2.mus_HLT_IsoMu24_eta2p1_version(); }
	unsigned int &mus_HLT_Mu17_Ele8_LeadingLeg_version() { return cms2.mus_HLT_Mu17_Ele8_LeadingLeg_version(); }
	unsigned int &mus_HLT_Mu17_Ele8_version() { return cms2.mus_HLT_Mu17_Ele8_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen_version() { return cms2.mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_LeadingLeg_version() { return cms2.mus_HLT_Mu17_Mu8_LeadingLeg_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_TrailingLeg_version() { return cms2.mus_HLT_Mu17_Mu8_TrailingLeg_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_version() { return cms2.mus_HLT_Mu17_Mu8_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_LeadingLeg_version() { return cms2.mus_HLT_Mu17_TkMu8_LeadingLeg_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered_version() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_TrailingLeg_version() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLeg_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_version() { return cms2.mus_HLT_Mu17_TkMu8_version(); }
	unsigned int &mus_HLT_Mu8_Ele17_TrailingLeg_version() { return cms2.mus_HLT_Mu8_Ele17_TrailingLeg_version(); }
	unsigned int &mus_HLT_Mu8_Ele17_version() { return cms2.mus_HLT_Mu8_Ele17_version(); }
	unsigned int &evt_nphotons() { return cms2.evt_nphotons(); }
	unsigned int &evt_nvtxs() { return cms2.evt_nvtxs(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8() { return cms2.els_HLT_Ele17_Ele8(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_L1sL1DoubleEG137() { return cms2.els_HLT_Ele17_Ele8_L1sL1DoubleEG137(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_LeadingLeg() { return cms2.els_HLT_Ele17_Ele8_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_Mass50_LeadingLeg() { return cms2.els_HLT_Ele17_Ele8_Mass50_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_Mass50_TrailingLeg() { return cms2.els_HLT_Ele17_Ele8_Mass50_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_TrailingLeg() { return cms2.els_HLT_Ele17_Ele8_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Ele20_SC4_Mass50_LeadingLeg() { return cms2.els_HLT_Ele20_SC4_Mass50_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele20_SC4_Mass50_TrailingLeg() { return cms2.els_HLT_Ele20_SC4_Mass50_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Ele27_WP80() { return cms2.els_HLT_Ele27_WP80(); }
	vector<unsigned int> &els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22() { return cms2.els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22(); }
	vector<unsigned int> &els_HLT_Ele32_SC17_Mass50_LeadingLeg() { return cms2.els_HLT_Ele32_SC17_Mass50_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele32_SC17_Mass50_TrailingLeg() { return cms2.els_HLT_Ele32_SC17_Mass50_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Mu17_Ele8() { return cms2.els_HLT_Mu17_Ele8(); }
	vector<unsigned int> &els_HLT_Mu17_Ele8_TrailingLeg() { return cms2.els_HLT_Mu17_Ele8_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Mu8_Ele17() { return cms2.els_HLT_Mu8_Ele17(); }
	vector<unsigned int> &hlt_prescales() { return cms2.hlt_prescales(); }
	vector<unsigned int> &mus_HLT_IsoMu24_eta2p1() { return cms2.mus_HLT_IsoMu24_eta2p1(); }
	vector<unsigned int> &mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1() { return cms2.mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1(); }
	vector<unsigned int> &mus_HLT_Mu17_Ele8() { return cms2.mus_HLT_Mu17_Ele8(); }
	vector<unsigned int> &mus_HLT_Mu17_Ele8_LeadingLeg() { return cms2.mus_HLT_Mu17_Ele8_LeadingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8() { return cms2.mus_HLT_Mu17_Mu8(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen() { return cms2.mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8_LeadingLeg() { return cms2.mus_HLT_Mu17_Mu8_LeadingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8_TrailingLeg() { return cms2.mus_HLT_Mu17_Mu8_TrailingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8() { return cms2.mus_HLT_Mu17_TkMu8(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8_LeadingLeg() { return cms2.mus_HLT_Mu17_TkMu8_LeadingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8_TrailingLeg() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered() { return cms2.mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered(); }
	vector<unsigned int> &mus_HLT_Mu8_Ele17() { return cms2.mus_HLT_Mu8_Ele17(); }
	vector<unsigned int> &mus_HLT_Mu8_Ele17_TrailingLeg() { return cms2.mus_HLT_Mu8_Ele17_TrailingLeg(); }
	int &evt_nEvts() { return cms2.evt_nEvts(); }
	float &evt_filt_eff() { return cms2.evt_filt_eff(); }
	bool passHLTTrigger(TString trigName) { return cms2.passHLTTrigger(trigName); }
}
