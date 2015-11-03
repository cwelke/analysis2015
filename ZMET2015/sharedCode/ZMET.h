// -*- C++ -*-
#ifndef ZMET_H
#define ZMET_H
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
#include <unistd.h> 
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

// Generated with the command
// makeCMS3ClassFiles("chain files", "t", "ZMET", "ZMet", "zmet")

using namespace std; 
class ZMET {
private: 
protected: 
	unsigned int index;
	int	run_;
	TBranch *run_branch;
	bool run_isLoaded;
	int	lumi_;
	TBranch *lumi_branch;
	bool lumi_isLoaded;
	unsigned long long	evt_;
	TBranch *evt_branch;
	bool evt_isLoaded;
	int	isData_;
	TBranch *isData_branch;
	bool isData_isLoaded;
	bool	evt_passgoodrunlist_;
	TBranch *evt_passgoodrunlist_branch;
	bool evt_passgoodrunlist_isLoaded;
	float	evt_scale1fb_;
	TBranch *evt_scale1fb_branch;
	bool evt_scale1fb_isLoaded;
	float	evt_xsec_;
	TBranch *evt_xsec_branch;
	bool evt_xsec_isLoaded;
	float	evt_kfactor_;
	TBranch *evt_kfactor_branch;
	bool evt_kfactor_isLoaded;
	float	evt_filter_;
	TBranch *evt_filter_branch;
	bool evt_filter_isLoaded;
	int	evt_nEvts_;
	TBranch *evt_nEvts_branch;
	bool evt_nEvts_isLoaded;
	float	puWeight_;
	TBranch *puWeight_branch;
	bool puWeight_isLoaded;
	int	nVert_;
	TBranch *nVert_branch;
	bool nVert_isLoaded;
	int	nTrueInt_;
	TBranch *nTrueInt_branch;
	bool nTrueInt_isLoaded;
	float	rho_;
	TBranch *rho_branch;
	bool rho_isLoaded;
	float	rho25_;
	TBranch *rho25_branch;
	bool rho25_isLoaded;
	int	njets_;
	TBranch *njets_branch;
	bool njets_isLoaded;
	float	ht_;
	TBranch *ht_branch;
	bool ht_isLoaded;
	float	gen_ht_;
	TBranch *gen_ht_branch;
	bool gen_ht_isLoaded;
	int	njets_eta30_;
	TBranch *njets_eta30_branch;
	bool njets_eta30_isLoaded;
	float	ht_eta30_;
	TBranch *ht_eta30_branch;
	bool ht_eta30_isLoaded;
	float	mt2_;
	TBranch *mt2_branch;
	bool mt2_isLoaded;
	float	mt2j_;
	TBranch *mt2j_branch;
	bool mt2j_isLoaded;
	float	mt2j_eta30_;
	TBranch *mt2j_eta30_branch;
	bool mt2j_eta30_isLoaded;
	int	nJet40_;
	TBranch *nJet40_branch;
	bool nJet40_isLoaded;
	int	nBJet40_;
	TBranch *nBJet40_branch;
	bool nBJet40_isLoaded;
	int	nBJetTight_;
	TBranch *nBJetTight_branch;
	bool nBJetTight_isLoaded;
	int	nBJetMedium_;
	TBranch *nBJetMedium_branch;
	bool nBJetMedium_isLoaded;
	int	nBJetLoose_;
	TBranch *nBJetLoose_branch;
	bool nBJetLoose_isLoaded;
	int	nMuons10_;
	TBranch *nMuons10_branch;
	bool nMuons10_isLoaded;
	int	nElectrons10_;
	TBranch *nElectrons10_branch;
	bool nElectrons10_isLoaded;
	int	nGammas20_;
	TBranch *nGammas20_branch;
	bool nGammas20_isLoaded;
	float	met_pt_;
	TBranch *met_pt_branch;
	bool met_pt_isLoaded;
	float	met_phi_;
	TBranch *met_phi_branch;
	bool met_phi_isLoaded;
	float	met_rawPt_;
	TBranch *met_rawPt_branch;
	bool met_rawPt_isLoaded;
	float	met_rawPhi_;
	TBranch *met_rawPhi_branch;
	bool met_rawPhi_isLoaded;
	float	met_caloPt_;
	TBranch *met_caloPt_branch;
	bool met_caloPt_isLoaded;
	float	met_caloPhi_;
	TBranch *met_caloPhi_branch;
	bool met_caloPhi_isLoaded;
	float	met_genPt_;
	TBranch *met_genPt_branch;
	bool met_genPt_isLoaded;
	float	met_genPhi_;
	TBranch *met_genPhi_branch;
	bool met_genPhi_isLoaded;
	float	sumet_raw_;
	TBranch *sumet_raw_branch;
	bool sumet_raw_isLoaded;
	float	jzb_raw_;
	TBranch *jzb_raw_branch;
	bool jzb_raw_isLoaded;
	float	jzb_T1_;
	TBranch *jzb_T1_branch;
	bool jzb_T1_isLoaded;
	float	jgb_raw_;
	TBranch *jgb_raw_branch;
	bool jgb_raw_isLoaded;
	float	jgb_T1_;
	TBranch *jgb_T1_branch;
	bool jgb_T1_isLoaded;
	int	Flag_EcalDeadCellTriggerPrimitiveFilter_;
	TBranch *Flag_EcalDeadCellTriggerPrimitiveFilter_branch;
	bool Flag_EcalDeadCellTriggerPrimitiveFilter_isLoaded;
	int	Flag_trkPOG_manystripclus53X_;
	TBranch *Flag_trkPOG_manystripclus53X_branch;
	bool Flag_trkPOG_manystripclus53X_isLoaded;
	int	Flag_ecalLaserCorrFilter_;
	TBranch *Flag_ecalLaserCorrFilter_branch;
	bool Flag_ecalLaserCorrFilter_isLoaded;
	int	Flag_trkPOG_toomanystripclus53X_;
	TBranch *Flag_trkPOG_toomanystripclus53X_branch;
	bool Flag_trkPOG_toomanystripclus53X_isLoaded;
	int	Flag_hcalLaserEventFilter_;
	TBranch *Flag_hcalLaserEventFilter_branch;
	bool Flag_hcalLaserEventFilter_isLoaded;
	int	Flag_trkPOG_logErrorTooManyClusters_;
	TBranch *Flag_trkPOG_logErrorTooManyClusters_branch;
	bool Flag_trkPOG_logErrorTooManyClusters_isLoaded;
	int	Flag_trkPOGFilters_;
	TBranch *Flag_trkPOGFilters_branch;
	bool Flag_trkPOGFilters_isLoaded;
	int	Flag_trackingFailureFilter_;
	TBranch *Flag_trackingFailureFilter_branch;
	bool Flag_trackingFailureFilter_isLoaded;
	int	Flag_CSCTightHaloFilter_;
	TBranch *Flag_CSCTightHaloFilter_branch;
	bool Flag_CSCTightHaloFilter_isLoaded;
	int	Flag_HBHENoiseFilter_;
	TBranch *Flag_HBHENoiseFilter_branch;
	bool Flag_HBHENoiseFilter_isLoaded;
	int	Flag_HBHEIsoNoiseFilter_;
	TBranch *Flag_HBHEIsoNoiseFilter_branch;
	bool Flag_HBHEIsoNoiseFilter_isLoaded;
	int	Flag_goodVertices_;
	TBranch *Flag_goodVertices_branch;
	bool Flag_goodVertices_isLoaded;
	int	Flag_eeBadScFilter_;
	TBranch *Flag_eeBadScFilter_branch;
	bool Flag_eeBadScFilter_isLoaded;
	int	Flag_METFilters_;
	TBranch *Flag_METFilters_branch;
	bool Flag_METFilters_isLoaded;
	int	HLT_DoubleEl_;
	TBranch *HLT_DoubleEl_branch;
	bool HLT_DoubleEl_isLoaded;
	int	HLT_DoubleEl_DZ_;
	TBranch *HLT_DoubleEl_DZ_branch;
	bool HLT_DoubleEl_DZ_isLoaded;
	int	HLT_DoubleEl_noiso_;
	TBranch *HLT_DoubleEl_noiso_branch;
	bool HLT_DoubleEl_noiso_isLoaded;
	int	HLT_MuEG_;
	TBranch *HLT_MuEG_branch;
	bool HLT_MuEG_isLoaded;
	int	HLT_MuEG_noiso_;
	TBranch *HLT_MuEG_noiso_branch;
	bool HLT_MuEG_noiso_isLoaded;
	int	HLT_MuEG_2_;
	TBranch *HLT_MuEG_2_branch;
	bool HLT_MuEG_2_isLoaded;
	int	HLT_DoubleMu_;
	TBranch *HLT_DoubleMu_branch;
	bool HLT_DoubleMu_isLoaded;
	int	HLT_DoubleMu_noiso_;
	TBranch *HLT_DoubleMu_noiso_branch;
	bool HLT_DoubleMu_noiso_isLoaded;
	int	HLT_DoubleMu_tk_;
	TBranch *HLT_DoubleMu_tk_branch;
	bool HLT_DoubleMu_tk_isLoaded;
	int	HLT_DoubleMu_nonDZ_;
	TBranch *HLT_DoubleMu_nonDZ_branch;
	bool HLT_DoubleMu_nonDZ_isLoaded;
	int	HLT_Photon22_R9Id90_HE10_IsoM_;
	TBranch *HLT_Photon22_R9Id90_HE10_IsoM_branch;
	bool HLT_Photon22_R9Id90_HE10_IsoM_isLoaded;
	int	HLT_Photon30_R9Id90_HE10_IsoM_;
	TBranch *HLT_Photon30_R9Id90_HE10_IsoM_branch;
	bool HLT_Photon30_R9Id90_HE10_IsoM_isLoaded;
	int	HLT_Photon36_R9Id90_HE10_IsoM_;
	TBranch *HLT_Photon36_R9Id90_HE10_IsoM_branch;
	bool HLT_Photon36_R9Id90_HE10_IsoM_isLoaded;
	int	HLT_Photon50_R9Id90_HE10_IsoM_;
	TBranch *HLT_Photon50_R9Id90_HE10_IsoM_branch;
	bool HLT_Photon50_R9Id90_HE10_IsoM_isLoaded;
	int	HLT_Photon75_R9Id90_HE10_IsoM_;
	TBranch *HLT_Photon75_R9Id90_HE10_IsoM_branch;
	bool HLT_Photon75_R9Id90_HE10_IsoM_isLoaded;
	int	HLT_Photon90_R9Id90_HE10_IsoM_;
	TBranch *HLT_Photon90_R9Id90_HE10_IsoM_branch;
	bool HLT_Photon90_R9Id90_HE10_IsoM_isLoaded;
	int	HLT_Photon120_R9Id90_HE10_IsoM_;
	TBranch *HLT_Photon120_R9Id90_HE10_IsoM_branch;
	bool HLT_Photon120_R9Id90_HE10_IsoM_isLoaded;
	int	HLT_Photon165_R9Id90_HE10_IsoM_;
	TBranch *HLT_Photon165_R9Id90_HE10_IsoM_branch;
	bool HLT_Photon165_R9Id90_HE10_IsoM_isLoaded;
	float	dilmass_;
	TBranch *dilmass_branch;
	bool dilmass_isLoaded;
	float	dilpt_;
	TBranch *dilpt_branch;
	bool dilpt_isLoaded;
	float	dRll_;
	TBranch *dRll_branch;
	bool dRll_isLoaded;
	float	matched_neutralemf_;
	TBranch *matched_neutralemf_branch;
	bool matched_neutralemf_isLoaded;
	float	matched_emf_;
	TBranch *matched_emf_branch;
	bool matched_emf_isLoaded;
	bool	elveto_;
	TBranch *elveto_branch;
	bool elveto_isLoaded;
	int	nlep_;
	TBranch *nlep_branch;
	bool nlep_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *lep_p4_;
	TBranch *lep_p4_branch;
	bool lep_p4_isLoaded;
	vector<float> *lep_pt_;
	TBranch *lep_pt_branch;
	bool lep_pt_isLoaded;
	vector<float> *lep_eta_;
	TBranch *lep_eta_branch;
	bool lep_eta_isLoaded;
	vector<float> *lep_phi_;
	TBranch *lep_phi_branch;
	bool lep_phi_isLoaded;
	vector<float> *lep_mass_;
	TBranch *lep_mass_branch;
	bool lep_mass_isLoaded;
	vector<int> *lep_charge_;
	TBranch *lep_charge_branch;
	bool lep_charge_isLoaded;
	vector<int> *lep_pdgId_;
	TBranch *lep_pdgId_branch;
	bool lep_pdgId_isLoaded;
	vector<float> *lep_dxy_;
	TBranch *lep_dxy_branch;
	bool lep_dxy_isLoaded;
	vector<float> *lep_etaSC_;
	TBranch *lep_etaSC_branch;
	bool lep_etaSC_isLoaded;
	vector<float> *lep_dz_;
	TBranch *lep_dz_branch;
	bool lep_dz_isLoaded;
	vector<int> *lep_tightId_;
	TBranch *lep_tightId_branch;
	bool lep_tightId_isLoaded;
	vector<float> *lep_relIso03_;
	TBranch *lep_relIso03_branch;
	bool lep_relIso03_isLoaded;
	vector<float> *lep_relIso03MREA_;
	TBranch *lep_relIso03MREA_branch;
	bool lep_relIso03MREA_isLoaded;
	vector<float> *lep_relIso03MRDB_;
	TBranch *lep_relIso03MRDB_branch;
	bool lep_relIso03MRDB_isLoaded;
	vector<float> *lep_relIso03MRNC_;
	TBranch *lep_relIso03MRNC_branch;
	bool lep_relIso03MRNC_isLoaded;
	vector<float> *lep_relIso04_;
	TBranch *lep_relIso04_branch;
	bool lep_relIso04_isLoaded;
	vector<int> *lep_mcMatchId_;
	TBranch *lep_mcMatchId_branch;
	bool lep_mcMatchId_isLoaded;
	vector<int> *lep_lostHits_;
	TBranch *lep_lostHits_branch;
	bool lep_lostHits_isLoaded;
	vector<int> *lep_convVeto_;
	TBranch *lep_convVeto_branch;
	bool lep_convVeto_isLoaded;
	vector<int> *lep_tightCharge_;
	TBranch *lep_tightCharge_branch;
	bool lep_tightCharge_isLoaded;
	vector<float> *lep_MVA_;
	TBranch *lep_MVA_branch;
	bool lep_MVA_isLoaded;
	vector<int> *lep_islead_;
	TBranch *lep_islead_branch;
	bool lep_islead_isLoaded;
	vector<int> *lep_istail_;
	TBranch *lep_istail_branch;
	bool lep_istail_isLoaded;
	int	ngamma_;
	TBranch *ngamma_branch;
	bool ngamma_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *gamma_p4_;
	TBranch *gamma_p4_branch;
	bool gamma_p4_isLoaded;
	vector<float> *gamma_pt_;
	TBranch *gamma_pt_branch;
	bool gamma_pt_isLoaded;
	vector<float> *gamma_eta_;
	TBranch *gamma_eta_branch;
	bool gamma_eta_isLoaded;
	vector<float> *gamma_phi_;
	TBranch *gamma_phi_branch;
	bool gamma_phi_isLoaded;
	vector<float> *gamma_mass_;
	TBranch *gamma_mass_branch;
	bool gamma_mass_isLoaded;
	vector<int> *gamma_mcMatchId_;
	TBranch *gamma_mcMatchId_branch;
	bool gamma_mcMatchId_isLoaded;
	vector<float> *gamma_genIso_;
	TBranch *gamma_genIso_branch;
	bool gamma_genIso_isLoaded;
	vector<float> *gamma_chHadIso_;
	TBranch *gamma_chHadIso_branch;
	bool gamma_chHadIso_isLoaded;
	vector<float> *gamma_neuHadIso_;
	TBranch *gamma_neuHadIso_branch;
	bool gamma_neuHadIso_isLoaded;
	vector<float> *gamma_phIso_;
	TBranch *gamma_phIso_branch;
	bool gamma_phIso_isLoaded;
	vector<float> *gamma_sigmaIetaIeta_;
	TBranch *gamma_sigmaIetaIeta_branch;
	bool gamma_sigmaIetaIeta_isLoaded;
	vector<float> *gamma_r9_;
	TBranch *gamma_r9_branch;
	bool gamma_r9_isLoaded;
	vector<float> *gamma_hOverE_;
	TBranch *gamma_hOverE_branch;
	bool gamma_hOverE_isLoaded;
	vector<int> *gamma_idCutBased_;
	TBranch *gamma_idCutBased_branch;
	bool gamma_idCutBased_isLoaded;
	int	ngenPart_;
	TBranch *ngenPart_branch;
	bool ngenPart_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genPart_p4_;
	TBranch *genPart_p4_branch;
	bool genPart_p4_isLoaded;
	vector<float> *genPart_pt_;
	TBranch *genPart_pt_branch;
	bool genPart_pt_isLoaded;
	vector<float> *genPart_eta_;
	TBranch *genPart_eta_branch;
	bool genPart_eta_isLoaded;
	vector<float> *genPart_phi_;
	TBranch *genPart_phi_branch;
	bool genPart_phi_isLoaded;
	vector<float> *genPart_mass_;
	TBranch *genPart_mass_branch;
	bool genPart_mass_isLoaded;
	vector<int> *genPart_pdgId_;
	TBranch *genPart_pdgId_branch;
	bool genPart_pdgId_isLoaded;
	vector<int> *genPart_status_;
	TBranch *genPart_status_branch;
	bool genPart_status_isLoaded;
	vector<float> *genPart_charge_;
	TBranch *genPart_charge_branch;
	bool genPart_charge_isLoaded;
	vector<int> *genPart_motherId_;
	TBranch *genPart_motherId_branch;
	bool genPart_motherId_isLoaded;
	vector<int> *genPart_grandmaId_;
	TBranch *genPart_grandmaId_branch;
	bool genPart_grandmaId_isLoaded;
	vector<bool> *genPart_isp6status3_;
	TBranch *genPart_isp6status3_branch;
	bool genPart_isp6status3_isLoaded;
	int	ngenLep_;
	TBranch *ngenLep_branch;
	bool ngenLep_isLoaded;
	vector<float> *genLep_pt_;
	TBranch *genLep_pt_branch;
	bool genLep_pt_isLoaded;
	vector<float> *genLep_eta_;
	TBranch *genLep_eta_branch;
	bool genLep_eta_isLoaded;
	vector<float> *genLep_phi_;
	TBranch *genLep_phi_branch;
	bool genLep_phi_isLoaded;
	vector<float> *genLep_mass_;
	TBranch *genLep_mass_branch;
	bool genLep_mass_isLoaded;
	vector<int> *genLep_pdgId_;
	TBranch *genLep_pdgId_branch;
	bool genLep_pdgId_isLoaded;
	vector<int> *genLep_status_;
	TBranch *genLep_status_branch;
	bool genLep_status_isLoaded;
	vector<float> *genLep_charge_;
	TBranch *genLep_charge_branch;
	bool genLep_charge_isLoaded;
	vector<int> *genLep_sourceId_;
	TBranch *genLep_sourceId_branch;
	bool genLep_sourceId_isLoaded;
	vector<bool> *genLep_isp6status3_;
	TBranch *genLep_isp6status3_branch;
	bool genLep_isp6status3_isLoaded;
	int	ngenTau_;
	TBranch *ngenTau_branch;
	bool ngenTau_isLoaded;
	vector<float> *genTau_pt_;
	TBranch *genTau_pt_branch;
	bool genTau_pt_isLoaded;
	vector<float> *genTau_eta_;
	TBranch *genTau_eta_branch;
	bool genTau_eta_isLoaded;
	vector<float> *genTau_phi_;
	TBranch *genTau_phi_branch;
	bool genTau_phi_isLoaded;
	vector<float> *genTau_mass_;
	TBranch *genTau_mass_branch;
	bool genTau_mass_isLoaded;
	vector<int> *genTau_pdgId_;
	TBranch *genTau_pdgId_branch;
	bool genTau_pdgId_isLoaded;
	vector<int> *genTau_status_;
	TBranch *genTau_status_branch;
	bool genTau_status_isLoaded;
	vector<float> *genTau_charge_;
	TBranch *genTau_charge_branch;
	bool genTau_charge_isLoaded;
	vector<int> *genTau_sourceId_;
	TBranch *genTau_sourceId_branch;
	bool genTau_sourceId_isLoaded;
	int	ngenLepFromTau_;
	TBranch *ngenLepFromTau_branch;
	bool ngenLepFromTau_isLoaded;
	vector<float> *genLepFromTau_pt_;
	TBranch *genLepFromTau_pt_branch;
	bool genLepFromTau_pt_isLoaded;
	vector<float> *genLepFromTau_eta_;
	TBranch *genLepFromTau_eta_branch;
	bool genLepFromTau_eta_isLoaded;
	vector<float> *genLepFromTau_phi_;
	TBranch *genLepFromTau_phi_branch;
	bool genLepFromTau_phi_isLoaded;
	vector<float> *genLepFromTau_mass_;
	TBranch *genLepFromTau_mass_branch;
	bool genLepFromTau_mass_isLoaded;
	vector<int> *genLepFromTau_pdgId_;
	TBranch *genLepFromTau_pdgId_branch;
	bool genLepFromTau_pdgId_isLoaded;
	vector<int> *genLepFromTau_status_;
	TBranch *genLepFromTau_status_branch;
	bool genLepFromTau_status_isLoaded;
	vector<float> *genLepFromTau_charge_;
	TBranch *genLepFromTau_charge_branch;
	bool genLepFromTau_charge_isLoaded;
	vector<int> *genLepFromTau_sourceId_;
	TBranch *genLepFromTau_sourceId_branch;
	bool genLepFromTau_sourceId_isLoaded;
	int	njet_;
	TBranch *njet_branch;
	bool njet_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *jet_p4_;
	TBranch *jet_p4_branch;
	bool jet_p4_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *jets_p4_;
	TBranch *jets_p4_branch;
	bool jets_p4_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *jets_eta30_p4_;
	TBranch *jets_eta30_p4_branch;
	bool jets_eta30_p4_isLoaded;
	vector<float> *jet_pt_;
	TBranch *jet_pt_branch;
	bool jet_pt_isLoaded;
	vector<float> *jet_eta_;
	TBranch *jet_eta_branch;
	bool jet_eta_isLoaded;
	vector<float> *jet_phi_;
	TBranch *jet_phi_branch;
	bool jet_phi_isLoaded;
	vector<float> *jet_mass_;
	TBranch *jet_mass_branch;
	bool jet_mass_isLoaded;
	vector<float> *jet_btagCSV_;
	TBranch *jet_btagCSV_branch;
	bool jet_btagCSV_isLoaded;
	vector<float> *jet_rawPt_;
	TBranch *jet_rawPt_branch;
	bool jet_rawPt_isLoaded;
	vector<float> *jet_mcPt_;
	TBranch *jet_mcPt_branch;
	bool jet_mcPt_isLoaded;
	vector<int> *jet_mcFlavour_;
	TBranch *jet_mcFlavour_branch;
	bool jet_mcFlavour_isLoaded;
	vector<float> *jet_quarkGluonID_;
	TBranch *jet_quarkGluonID_branch;
	bool jet_quarkGluonID_isLoaded;
	vector<float> *jet_area_;
	TBranch *jet_area_branch;
	bool jet_area_isLoaded;
	vector<int> *jet_id_;
	TBranch *jet_id_branch;
	bool jet_id_isLoaded;
	vector<int> *jet_puId_;
	TBranch *jet_puId_branch;
	bool jet_puId_isLoaded;
	float	met_T1CHS_pt_;
	TBranch *met_T1CHS_pt_branch;
	bool met_T1CHS_pt_isLoaded;
	float	met_T1CHS_phi_;
	TBranch *met_T1CHS_phi_branch;
	bool met_T1CHS_phi_isLoaded;
	float	met_T1CHS_fromCORE_pt_;
	TBranch *met_T1CHS_fromCORE_pt_branch;
	bool met_T1CHS_fromCORE_pt_isLoaded;
	float	met_T1CHS_fromCORE_phi_;
	TBranch *met_T1CHS_fromCORE_phi_branch;
	bool met_T1CHS_fromCORE_phi_isLoaded;
	float	met_T1CHSNoHF_pt_;
	TBranch *met_T1CHSNoHF_pt_branch;
	bool met_T1CHSNoHF_pt_isLoaded;
	float	met_T1CHSNoHF_phi_;
	TBranch *met_T1CHSNoHF_phi_branch;
	bool met_T1CHSNoHF_phi_isLoaded;
	float	met_rawNoHF_pt_;
	TBranch *met_rawNoHF_pt_branch;
	bool met_rawNoHF_pt_isLoaded;
	float	met_rawNoHF_phi_;
	TBranch *met_rawNoHF_phi_branch;
	bool met_rawNoHF_phi_isLoaded;
	float	met_T1CHSNoHF_fromCORE_pt_;
	TBranch *met_T1CHSNoHF_fromCORE_pt_branch;
	bool met_T1CHSNoHF_fromCORE_pt_isLoaded;
	float	met_T1CHSNoHF_fromCORE_phi_;
	TBranch *met_T1CHSNoHF_fromCORE_phi_branch;
	bool met_T1CHSNoHF_fromCORE_phi_isLoaded;
	int	hyp_type_;
	TBranch *hyp_type_branch;
	bool hyp_type_isLoaded;
	int	evt_type_;
	TBranch *evt_type_branch;
	bool evt_type_isLoaded;
public: 
void Init(TTree *tree);
void GetEntry(unsigned int idx); 
void LoadAllBranches(); 
	const int &run();
	const int &lumi();
	const unsigned long long &evt();
	const int &isData();
	const bool &	evt_passgoodrunlist();
	const float &evt_scale1fb();
	const float &evt_xsec();
	const float &evt_kfactor();
	const float &evt_filter();
	const int &evt_nEvts();
	const float &puWeight();
	const int &nVert();
	const int &nTrueInt();
	const float &rho();
	const float &rho25();
	const int &njets();
	const float &ht();
	const float &gen_ht();
	const int &njets_eta30();
	const float &ht_eta30();
	const float &mt2();
	const float &mt2j();
	const float &mt2j_eta30();
	const int &nJet40();
	const int &nBJet40();
	const int &nBJetTight();
	const int &nBJetMedium();
	const int &nBJetLoose();
	const int &nMuons10();
	const int &nElectrons10();
	const int &nGammas20();
	const float &met_pt();
	const float &met_phi();
	const float &met_rawPt();
	const float &met_rawPhi();
	const float &met_caloPt();
	const float &met_caloPhi();
	const float &met_genPt();
	const float &met_genPhi();
	const float &sumet_raw();
	const float &jzb_raw();
	const float &jzb_T1();
	const float &jgb_raw();
	const float &jgb_T1();
	const int &Flag_EcalDeadCellTriggerPrimitiveFilter();
	const int &Flag_trkPOG_manystripclus53X();
	const int &Flag_ecalLaserCorrFilter();
	const int &Flag_trkPOG_toomanystripclus53X();
	const int &Flag_hcalLaserEventFilter();
	const int &Flag_trkPOG_logErrorTooManyClusters();
	const int &Flag_trkPOGFilters();
	const int &Flag_trackingFailureFilter();
	const int &Flag_CSCTightHaloFilter();
	const int &Flag_HBHENoiseFilter();
	const int &Flag_HBHEIsoNoiseFilter();
	const int &Flag_goodVertices();
	const int &Flag_eeBadScFilter();
	const int &Flag_METFilters();
	const int &HLT_DoubleEl();
	const int &HLT_DoubleEl_DZ();
	const int &HLT_DoubleEl_noiso();
	const int &HLT_MuEG();
	const int &HLT_MuEG_noiso();
	const int &HLT_MuEG_2();
	const int &HLT_DoubleMu();
	const int &HLT_DoubleMu_noiso();
	const int &HLT_DoubleMu_tk();
	const int &HLT_DoubleMu_nonDZ();
	const int &HLT_Photon22_R9Id90_HE10_IsoM();
	const int &HLT_Photon30_R9Id90_HE10_IsoM();
	const int &HLT_Photon36_R9Id90_HE10_IsoM();
	const int &HLT_Photon50_R9Id90_HE10_IsoM();
	const int &HLT_Photon75_R9Id90_HE10_IsoM();
	const int &HLT_Photon90_R9Id90_HE10_IsoM();
	const int &HLT_Photon120_R9Id90_HE10_IsoM();
	const int &HLT_Photon165_R9Id90_HE10_IsoM();
	const float &dilmass();
	const float &dilpt();
	const float &dRll();
	const float &matched_neutralemf();
	const float &matched_emf();
	const bool &	elveto();
	const int &nlep();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &lep_p4();
	const vector<float> &lep_pt();
	const vector<float> &lep_eta();
	const vector<float> &lep_phi();
	const vector<float> &lep_mass();
	const vector<int> &lep_charge();
	const vector<int> &lep_pdgId();
	const vector<float> &lep_dxy();
	const vector<float> &lep_etaSC();
	const vector<float> &lep_dz();
	const vector<int> &lep_tightId();
	const vector<float> &lep_relIso03();
	const vector<float> &lep_relIso03MREA();
	const vector<float> &lep_relIso03MRDB();
	const vector<float> &lep_relIso03MRNC();
	const vector<float> &lep_relIso04();
	const vector<int> &lep_mcMatchId();
	const vector<int> &lep_lostHits();
	const vector<int> &lep_convVeto();
	const vector<int> &lep_tightCharge();
	const vector<float> &lep_MVA();
	const vector<int> &lep_islead();
	const vector<int> &lep_istail();
	const int &ngamma();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gamma_p4();
	const vector<float> &gamma_pt();
	const vector<float> &gamma_eta();
	const vector<float> &gamma_phi();
	const vector<float> &gamma_mass();
	const vector<int> &gamma_mcMatchId();
	const vector<float> &gamma_genIso();
	const vector<float> &gamma_chHadIso();
	const vector<float> &gamma_neuHadIso();
	const vector<float> &gamma_phIso();
	const vector<float> &gamma_sigmaIetaIeta();
	const vector<float> &gamma_r9();
	const vector<float> &gamma_hOverE();
	const vector<int> &gamma_idCutBased();
	const int &ngenPart();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genPart_p4();
	const vector<float> &genPart_pt();
	const vector<float> &genPart_eta();
	const vector<float> &genPart_phi();
	const vector<float> &genPart_mass();
	const vector<int> &genPart_pdgId();
	const vector<int> &genPart_status();
	const vector<float> &genPart_charge();
	const vector<int> &genPart_motherId();
	const vector<int> &genPart_grandmaId();
	const vector<bool> &genPart_isp6status3();
	const int &ngenLep();
	const vector<float> &genLep_pt();
	const vector<float> &genLep_eta();
	const vector<float> &genLep_phi();
	const vector<float> &genLep_mass();
	const vector<int> &genLep_pdgId();
	const vector<int> &genLep_status();
	const vector<float> &genLep_charge();
	const vector<int> &genLep_sourceId();
	const vector<bool> &genLep_isp6status3();
	const int &ngenTau();
	const vector<float> &genTau_pt();
	const vector<float> &genTau_eta();
	const vector<float> &genTau_phi();
	const vector<float> &genTau_mass();
	const vector<int> &genTau_pdgId();
	const vector<int> &genTau_status();
	const vector<float> &genTau_charge();
	const vector<int> &genTau_sourceId();
	const int &ngenLepFromTau();
	const vector<float> &genLepFromTau_pt();
	const vector<float> &genLepFromTau_eta();
	const vector<float> &genLepFromTau_phi();
	const vector<float> &genLepFromTau_mass();
	const vector<int> &genLepFromTau_pdgId();
	const vector<int> &genLepFromTau_status();
	const vector<float> &genLepFromTau_charge();
	const vector<int> &genLepFromTau_sourceId();
	const int &njet();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jet_p4();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_p4();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_eta30_p4();
	const vector<float> &jet_pt();
	const vector<float> &jet_eta();
	const vector<float> &jet_phi();
	const vector<float> &jet_mass();
	const vector<float> &jet_btagCSV();
	const vector<float> &jet_rawPt();
	const vector<float> &jet_mcPt();
	const vector<int> &jet_mcFlavour();
	const vector<float> &jet_quarkGluonID();
	const vector<float> &jet_area();
	const vector<int> &jet_id();
	const vector<int> &jet_puId();
	const float &met_T1CHS_pt();
	const float &met_T1CHS_phi();
	const float &met_T1CHS_fromCORE_pt();
	const float &met_T1CHS_fromCORE_phi();
	const float &met_T1CHSNoHF_pt();
	const float &met_T1CHSNoHF_phi();
	const float &met_rawNoHF_pt();
	const float &met_rawNoHF_phi();
	const float &met_T1CHSNoHF_fromCORE_pt();
	const float &met_T1CHSNoHF_fromCORE_phi();
	const int &hyp_type();
	const int &evt_type();

  static void progress( int nEventsTotal, int nEventsChain );
};

#ifndef __CINT__
extern ZMET zmet;
#endif

namespace ZMet {
	const int &run();
	const int &lumi();
	const unsigned long long &evt();
	const int &isData();
	const bool &evt_passgoodrunlist();
	const float &evt_scale1fb();
	const float &evt_xsec();
	const float &evt_kfactor();
	const float &evt_filter();
	const int &evt_nEvts();
	const float &puWeight();
	const int &nVert();
	const int &nTrueInt();
	const float &rho();
	const float &rho25();
	const int &njets();
	const float &ht();
	const float &gen_ht();
	const int &njets_eta30();
	const float &ht_eta30();
	const float &mt2();
	const float &mt2j();
	const float &mt2j_eta30();
	const int &nJet40();
	const int &nBJet40();
	const int &nBJetTight();
	const int &nBJetMedium();
	const int &nBJetLoose();
	const int &nMuons10();
	const int &nElectrons10();
	const int &nGammas20();
	const float &met_pt();
	const float &met_phi();
	const float &met_rawPt();
	const float &met_rawPhi();
	const float &met_caloPt();
	const float &met_caloPhi();
	const float &met_genPt();
	const float &met_genPhi();
	const float &sumet_raw();
	const float &jzb_raw();
	const float &jzb_T1();
	const float &jgb_raw();
	const float &jgb_T1();
	const int &Flag_EcalDeadCellTriggerPrimitiveFilter();
	const int &Flag_trkPOG_manystripclus53X();
	const int &Flag_ecalLaserCorrFilter();
	const int &Flag_trkPOG_toomanystripclus53X();
	const int &Flag_hcalLaserEventFilter();
	const int &Flag_trkPOG_logErrorTooManyClusters();
	const int &Flag_trkPOGFilters();
	const int &Flag_trackingFailureFilter();
	const int &Flag_CSCTightHaloFilter();
	const int &Flag_HBHENoiseFilter();
	const int &Flag_HBHEIsoNoiseFilter();
	const int &Flag_goodVertices();
	const int &Flag_eeBadScFilter();
	const int &Flag_METFilters();
	const int &HLT_DoubleEl();
	const int &HLT_DoubleEl_DZ();
	const int &HLT_DoubleEl_noiso();
	const int &HLT_MuEG();
	const int &HLT_MuEG_noiso();
	const int &HLT_MuEG_2();
	const int &HLT_DoubleMu();
	const int &HLT_DoubleMu_noiso();
	const int &HLT_DoubleMu_tk();
	const int &HLT_DoubleMu_nonDZ();
	const int &HLT_Photon22_R9Id90_HE10_IsoM();
	const int &HLT_Photon30_R9Id90_HE10_IsoM();
	const int &HLT_Photon36_R9Id90_HE10_IsoM();
	const int &HLT_Photon50_R9Id90_HE10_IsoM();
	const int &HLT_Photon75_R9Id90_HE10_IsoM();
	const int &HLT_Photon90_R9Id90_HE10_IsoM();
	const int &HLT_Photon120_R9Id90_HE10_IsoM();
	const int &HLT_Photon165_R9Id90_HE10_IsoM();
	const float &dilmass();
	const float &dilpt();
	const float &dRll();
	const float &matched_neutralemf();
	const float &matched_emf();
	const bool &elveto();
	const int &nlep();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &lep_p4();
	const vector<float> &lep_pt();
	const vector<float> &lep_eta();
	const vector<float> &lep_phi();
	const vector<float> &lep_mass();
	const vector<int> &lep_charge();
	const vector<int> &lep_pdgId();
	const vector<float> &lep_dxy();
	const vector<float> &lep_etaSC();
	const vector<float> &lep_dz();
	const vector<int> &lep_tightId();
	const vector<float> &lep_relIso03();
	const vector<float> &lep_relIso03MREA();
	const vector<float> &lep_relIso03MRDB();
	const vector<float> &lep_relIso03MRNC();
	const vector<float> &lep_relIso04();
	const vector<int> &lep_mcMatchId();
	const vector<int> &lep_lostHits();
	const vector<int> &lep_convVeto();
	const vector<int> &lep_tightCharge();
	const vector<float> &lep_MVA();
	const vector<int> &lep_islead();
	const vector<int> &lep_istail();
	const int &ngamma();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &gamma_p4();
	const vector<float> &gamma_pt();
	const vector<float> &gamma_eta();
	const vector<float> &gamma_phi();
	const vector<float> &gamma_mass();
	const vector<int> &gamma_mcMatchId();
	const vector<float> &gamma_genIso();
	const vector<float> &gamma_chHadIso();
	const vector<float> &gamma_neuHadIso();
	const vector<float> &gamma_phIso();
	const vector<float> &gamma_sigmaIetaIeta();
	const vector<float> &gamma_r9();
	const vector<float> &gamma_hOverE();
	const vector<int> &gamma_idCutBased();
	const int &ngenPart();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genPart_p4();
	const vector<float> &genPart_pt();
	const vector<float> &genPart_eta();
	const vector<float> &genPart_phi();
	const vector<float> &genPart_mass();
	const vector<int> &genPart_pdgId();
	const vector<int> &genPart_status();
	const vector<float> &genPart_charge();
	const vector<int> &genPart_motherId();
	const vector<int> &genPart_grandmaId();
	const vector<bool> &genPart_isp6status3();
	const int &ngenLep();
	const vector<float> &genLep_pt();
	const vector<float> &genLep_eta();
	const vector<float> &genLep_phi();
	const vector<float> &genLep_mass();
	const vector<int> &genLep_pdgId();
	const vector<int> &genLep_status();
	const vector<float> &genLep_charge();
	const vector<int> &genLep_sourceId();
	const vector<bool> &genLep_isp6status3();
	const int &ngenTau();
	const vector<float> &genTau_pt();
	const vector<float> &genTau_eta();
	const vector<float> &genTau_phi();
	const vector<float> &genTau_mass();
	const vector<int> &genTau_pdgId();
	const vector<int> &genTau_status();
	const vector<float> &genTau_charge();
	const vector<int> &genTau_sourceId();
	const int &ngenLepFromTau();
	const vector<float> &genLepFromTau_pt();
	const vector<float> &genLepFromTau_eta();
	const vector<float> &genLepFromTau_phi();
	const vector<float> &genLepFromTau_mass();
	const vector<int> &genLepFromTau_pdgId();
	const vector<int> &genLepFromTau_status();
	const vector<float> &genLepFromTau_charge();
	const vector<int> &genLepFromTau_sourceId();
	const int &njet();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jet_p4();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_p4();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets_eta30_p4();
	const vector<float> &jet_pt();
	const vector<float> &jet_eta();
	const vector<float> &jet_phi();
	const vector<float> &jet_mass();
	const vector<float> &jet_btagCSV();
	const vector<float> &jet_rawPt();
	const vector<float> &jet_mcPt();
	const vector<int> &jet_mcFlavour();
	const vector<float> &jet_quarkGluonID();
	const vector<float> &jet_area();
	const vector<int> &jet_id();
	const vector<int> &jet_puId();
	const float &met_T1CHS_pt();
	const float &met_T1CHS_phi();
	const float &met_T1CHS_fromCORE_pt();
	const float &met_T1CHS_fromCORE_phi();
	const float &met_T1CHSNoHF_pt();
	const float &met_T1CHSNoHF_phi();
	const float &met_rawNoHF_pt();
	const float &met_rawNoHF_phi();
	const float &met_T1CHSNoHF_fromCORE_pt();
	const float &met_T1CHSNoHF_fromCORE_phi();
	const int &hyp_type();
	const int &evt_type();
}
#endif
