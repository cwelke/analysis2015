#ifndef ScanChain_h
#define ScanChain_h

// C++ includes
#include <string>
#include <vector>

// ROOT includes
#include "TROOT.h"
#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
//#include "TH1F.h"
#include "Math/LorentzVector.h"
#include "Math/GenVector/LorentzVector.h"

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

class babyMaker {

 public:

  babyMaker() {};
  ~babyMaker() {
    if (BabyFile_) delete BabyFile_;
    if (BabyTree_) delete BabyTree_;
  };

  void ScanChain(TChain*, std::string = "testSample");

  void MakeBabyNtuple(const char *);
  void InitBabyNtuple();
  void FillBabyNtuple();
  void CloseBabyNtuple();

 private:

  TFile *BabyFile_;
  TTree *BabyTree_;


  //baby ntuple variables

  Int_t           run;
  Int_t           lumi;
  ULong64_t       evt;
  Int_t           isData;

  Bool_t          evt_passgoodrunlist;
  Float_t         evt_scale1fb;
  Float_t         evt_xsec;
  Float_t         evt_kfactor;
  Float_t         evt_filter;
  Int_t           evt_nEvts;
  Int_t           evt_id;
  Float_t         puWeight;
  Int_t           nVert;
  Int_t           nTrueInt;
  Float_t         rho;
  Float_t         rho25;

  Int_t           nJet40;
  Int_t           nBJet40;
  Int_t           nBJetTight;
  Int_t           nBJetMedium;
  Int_t           nBJetLoose;
  Int_t           nMuons10;
  Int_t           nElectrons10;
  Int_t           nTaus20;
  Int_t           nGammas20;

  Int_t           njets;
  Float_t         ht;
  Float_t         gen_ht;
  Int_t           njets_eta30;
  Float_t         ht_eta30;

  Int_t           hyp_type; // 0 = ee; 1 = mm; 2 = em; 2 = me
  Int_t           evt_type; // 0 = OS; 1 = SS; 2 = photon+jets
  Float_t         dilmass;
  Float_t         dilpt;
  Float_t         dRll;

  Float_t         matched_neutralemf; // neutral em fraction for jet closest to photon within dR = .1
  Bool_t          elveto; // Reject photons which have electron of pT > 10 GeV within dR < 0.2

  // update
  Float_t         mt2;
  Float_t         mt2j;
  Float_t         mt2j_eta30;

  Float_t         met_pt;
  Float_t         met_phi;
  Float_t         met_rawPt;
  Float_t         met_rawPhi;
  Float_t         met_caloPt;
  Float_t         met_caloPhi;
  Float_t         met_genPt;
  Float_t         met_genPhi;

  Float_t         sumet_raw;
  Float_t         jzb_raw;
  Float_t         jzb_T1;
  Float_t         jgb_raw;
  Float_t         jgb_T1;

//----- MET FILTERS
  Int_t           Flag_EcalDeadCellTriggerPrimitiveFilter;
  Int_t           Flag_trkPOG_manystripclus53X;
  Int_t           Flag_ecalLaserCorrFilter;
  Int_t           Flag_trkPOG_toomanystripclus53X;
  Int_t           Flag_hcalLaserEventFilter;
  Int_t           Flag_trkPOG_logErrorTooManyClusters;
  Int_t           Flag_trkPOGFilters;
  Int_t           Flag_trackingFailureFilter;
  Int_t           Flag_CSCTightHaloFilter;
  Int_t           Flag_HBHENoiseFilter;
  Int_t           Flag_goodVertices;
  Int_t           Flag_eeBadScFilter;
  Int_t           Flag_METFilters;

//----- TRIGGER (to be better defined)
  Int_t           HLT_HT900;   
  Int_t           HLT_MET170;
  Int_t           HLT_ht350met120;   
  Int_t           HLT_SingleMu;   
  Int_t           HLT_DoubleEl;   
  Int_t           HLT_DoubleEl_DZ;   
  Int_t           HLT_DoubleEl_noiso;   
  Int_t           HLT_MuEG;   
  Int_t           HLT_MuEG_2;   
  Int_t           HLT_DoubleMu;   
  Int_t           HLT_DoubleMu_tk;   
  Int_t           HLT_Photons;   
  Int_t           HLT_Photon22;
  Int_t           HLT_Photon30;
  Int_t           HLT_Photon36;
  Int_t           HLT_Photon50;
  Int_t           HLT_Photon75;
  Int_t           HLT_Photon90;
  Int_t           HLT_Photon120;
  Int_t           HLT_Photon175;
  Int_t           HLT_Photon165_HE10;
  Int_t           HLT_Photon22_R9Id90_HE10_IsoM;
  Int_t           HLT_Photon30_R9Id90_HE10_IsoM;
  Int_t           HLT_Photon36_R9Id90_HE10_IsoM;
  Int_t           HLT_Photon50_R9Id90_HE10_IsoM;
  Int_t           HLT_Photon75_R9Id90_HE10_IsoM;
  Int_t           HLT_Photon90_R9Id90_HE10_IsoM;
  Int_t           HLT_Photon120_R9Id90_HE10_IsoM;
  Int_t           HLT_Photon165_R9Id90_HE10_IsoM;
  Int_t           HLT_l1prescale;   

  //----- LEPTONS
  Int_t           nlep;
  std::vector <LorentzVector> lep_p4;
  std::vector <Float_t> lep_pt         ;   //[nlep]
  std::vector <Float_t> lep_eta        ;   //[nlep]
  std::vector <Float_t> lep_phi        ;   //[nlep]
  std::vector <Float_t> lep_mass       ;   //[nlep]
  std::vector <Int_t  > lep_charge     ;   //[nlep]
  std::vector <Int_t  > lep_pdgId      ;   //[nlep]
  std::vector <Float_t> lep_dxy        ;   //[nlep]
  std::vector <Float_t> lep_etaSC      ;   //[nlep]
  std::vector <Float_t> lep_dz         ;   //[nlep]
  std::vector <Int_t  > lep_tightId    ;   //[nlep]
  std::vector <Float_t> lep_relIso03   ;   //[nlep]
  std::vector <Float_t> lep_relIso03MREA   ;   //[nlep]
  std::vector <Float_t> lep_relIso03MRDB   ;   //[nlep]
  std::vector <Float_t> lep_relIso03MRNC   ;   //[nlep]
  std::vector <Float_t> lep_relIso04   ;   //[nlep]
  std::vector <Int_t  > lep_mcMatchId  ;   //[nlep]
  std::vector <Int_t  > lep_lostHits   ;   //[nlep]
  std::vector <Int_t  > lep_convVeto   ;   //[nlep]
  std::vector <Int_t  > lep_tightCharge;   //[nlep]
  std::vector <Int_t  > lep_islead     ;   //[nlep]
  std::vector <Int_t  > lep_istail     ;   //[nlep]
  
//----- TAUS
  Int_t           ntau;
  std::vector <Float_t> tau_pt       ;   //[ntau]
  std::vector <Float_t> tau_eta      ;   //[ntau]
  std::vector <Float_t> tau_phi      ;   //[ntau]
  std::vector <Float_t> tau_mass     ;   //[ntau]
  std::vector <Int_t  > tau_charge   ;   //[ntau]
  std::vector <Float_t> tau_dxy      ;   //[ntau]
  std::vector <Float_t> tau_dz       ;   //[ntau]
  std::vector <Int_t  > tau_idCI3hit ;   //[ntau]
  std::vector <Float_t> tau_isoCI3hit;   //[ntau]
  // std::vector <Float_t> tau_isoMVA2  ;   //[ntau]
  // std::vector <Int_t  > tau_idMVA2   ;   //[ntau]
  // std::vector <Int_t  > tau_mcMatchId;   //[ntau]

//----- PHOTONS
  Int_t           ngamma;
  std::vector <LorentzVector>   gamma_p4;
  std::vector <Float_t>         gamma_pt           ;   //[ngamma]
  std::vector <Float_t>         gamma_eta          ;   //[ngamma]
  std::vector <Float_t>         gamma_phi          ;   //[ngamma]
  std::vector <Float_t>         gamma_mass         ;   //[ngamma]
  std::vector <Float_t>         gamma_sigmaIetaIeta;   //[ngamma]
  std::vector <Float_t>         gamma_chHadIso     ;   //[ngamma]
  std::vector <Float_t>         gamma_neuHadIso    ;   //[ngamma]
  std::vector <Float_t>         gamma_phIso        ;   //[ngamma]
  std::vector <Float_t>         gamma_r9           ;   //[ngamma]
  std::vector <Float_t>         gamma_hOverE       ;   //[ngamma]
  std::vector <Int_t  >         gamma_idCutBased   ;   //[ngamma]
  std::vector <Int_t  >         gamma_mcMatchId    ;   //[ngamma]
  std::vector <Float_t>         gamma_genIso       ;   //[ngamma]

  // event level vars recalculated for photon+jets control region
  Int_t           gamma_nJet40;
  Int_t           gamma_nBJet40;

//----- GEN PARTICLES
  Int_t           ngenPart;
  Int_t           ngen_p6s3Part;
  std::vector <LorentzVector>   genPart_p4         ;
  std::vector <Float_t>         genPart_pt         ;   //[ngenPart]
  std::vector <Float_t>         genPart_eta        ;   //[ngenPart]
  std::vector <Float_t>         genPart_phi        ;   //[ngenPart]
  std::vector <Float_t>         genPart_mass       ;   //[ngenPart]
  std::vector <Int_t  >         genPart_pdgId      ;   //[ngenPart]
  std::vector <Int_t  >         genPart_status     ;   //[ngenPart]
  std::vector <Bool_t >         genPart_isp6status3;   //[ngenPart]
  std::vector <Float_t>         genPart_charge     ;   //[ngenPart]
  std::vector <Int_t  >         genPart_motherId   ;   //[ngenPart]
  std::vector <Int_t  >         genPart_grandmaId  ;   //[ngenPart]

//----- GEN LEPTONS (ELECTRONS/MUONS)
  Int_t           ngenLep;
  Int_t           ngen_p6s3Lep;
  std::vector <Float_t>         genLep_pt         ;   //[ngenLep]
  std::vector <Float_t>         genLep_eta        ;   //[ngenLep]
  std::vector <Float_t>         genLep_phi        ;   //[ngenLep]
  std::vector <Float_t>         genLep_mass       ;   //[ngenLep]
  std::vector <Int_t  >         genLep_pdgId      ;   //[ngenLep]
  std::vector <Int_t  >         genLep_status     ;   //[ngenLep]
  std::vector <Bool_t >         genLep_isp6status3;   //[ngenLep]
  std::vector <Float_t>         genLep_charge     ;   //[ngenLep]
  std::vector <Int_t  >         genLep_sourceId   ;   //[ngenLep]

//----- GEN TAUS
  Int_t           ngenTau;
  std::vector <Float_t>         genTau_pt      ;   //[ngenTau]
  std::vector <Float_t>         genTau_eta     ;   //[ngenTau]
  std::vector <Float_t>         genTau_phi     ;   //[ngenTau]
  std::vector <Float_t>         genTau_mass    ;   //[ngenTau]
  std::vector <Int_t  >         genTau_pdgId   ;   //[ngenTau]
  std::vector <Int_t  >         genTau_status  ;   //[ngenTau]
  std::vector <Float_t>         genTau_charge  ;   //[ngenTau]
  std::vector <Int_t  >         genTau_sourceId;   //[ngenTau]

//----- GEN LEPTONS FROM TAUS
  Int_t           ngenLepFromTau;
  std::vector <Float_t>         genLepFromTau_pt      ;   //[ngenLepFromTau]
  std::vector <Float_t>         genLepFromTau_eta     ;   //[ngenLepFromTau]
  std::vector <Float_t>         genLepFromTau_phi     ;   //[ngenLepFromTau]
  std::vector <Float_t>         genLepFromTau_mass    ;   //[ngenLepFromTau]
  std::vector <Int_t  >         genLepFromTau_pdgId   ;   //[ngenLepFromTau]
  std::vector <Int_t  >         genLepFromTau_status  ;   //[ngenLepFromTau]
  std::vector <Float_t>         genLepFromTau_charge  ;   //[ngenLepFromTau]
  std::vector <Int_t  >         genLepFromTau_sourceId;   //[ngenLepFromTau]

//----- JETS
  Int_t           njet;
  std::vector <LorentzVector>   jet_p4;
  std::vector <LorentzVector>   jets_p4;
  std::vector <LorentzVector>   jets_eta30_p4;
  std::vector <Float_t>         jet_pt          ;   //[njet]
  std::vector <Float_t>         jet_eta         ;   //[njet]
  std::vector <Float_t>         jet_phi         ;   //[njet]
  std::vector <Float_t>         jet_mass        ;   //[njet]
  std::vector <Float_t>         jet_btagCSV     ;   //[njet]
  std::vector <Float_t>         jet_rawPt       ;   //[njet]
  std::vector <Float_t>         jet_mcPt        ;   //[njet]
  std::vector <Int_t  >         jet_mcFlavour   ;   //[njet]
  std::vector <Float_t>         jet_quarkGluonID;   //[njet]
  std::vector <Float_t>         jet_area        ;   //[njet]
  std::vector <Int_t  >         jet_id          ;   //[njet]
  std::vector <Int_t  >         jet_puId        ;   //[njet]

//----- pfMETs
  Float_t chpfmet_trk_pt;
  Float_t chpfmet_trk_phi;

  Float_t chpfmet_pv1_pt;
  Float_t chpfmet_pv1_phi;

  Float_t chphpfmet_trk_pt;
  Float_t chphpfmet_trk_phi;

  Float_t nupfmet_trk_pt;
  Float_t nupfmet_trk_phi;
  Float_t nupfmet_fwd_pt;
  Float_t nupfmet_fwd_phi;  
  Float_t nupfmet_all_pt;
  Float_t nupfmet_all_phi;

  Float_t nunophpfmet_trk_pt;
  Float_t nunophpfmet_trk_phi;
  Float_t nunophpfmet_fwd_pt;
  Float_t nunophpfmet_fwd_phi;  
  Float_t nunophpfmet_all_pt;
  Float_t nunophpfmet_all_phi;

  //pfcand vector sums
  Float_t chpfcands_0013_pt;
  Float_t chpfcands_1316_pt;
  Float_t chpfcands_1624_pt;
  Float_t chpfcands_2430_pt;
  Float_t chpfcands_30in_pt;
  Float_t phpfcands_0013_pt;
  Float_t phpfcands_1316_pt;
  Float_t phpfcands_1624_pt;
  Float_t phpfcands_2430_pt;
  Float_t phpfcands_30in_pt;
  Float_t nupfcands_0013_pt;
  Float_t nupfcands_1316_pt;
  Float_t nupfcands_1624_pt;
  Float_t nupfcands_2430_pt;
  Float_t nupfcands_30in_pt;

  Float_t chpfcands_0013_phi;
  Float_t chpfcands_1316_phi;
  Float_t chpfcands_1624_phi;
  Float_t chpfcands_2430_phi;
  Float_t chpfcands_30in_phi;
  Float_t phpfcands_0013_phi;
  Float_t phpfcands_1316_phi;
  Float_t phpfcands_1624_phi;
  Float_t phpfcands_2430_phi;
  Float_t phpfcands_30in_phi;
  Float_t nupfcands_0013_phi;
  Float_t nupfcands_1316_phi;
  Float_t nupfcands_1624_phi;
  Float_t nupfcands_2430_phi;
  Float_t nupfcands_30in_phi;

  // lots of MET
  Float_t met_T1CHS_pt;
  Float_t met_T1CHS_phi;
  Float_t met_T1CHS_fromCORE_pt;
  Float_t met_T1CHS_fromCORE_phi;
  Float_t met_T1CHSNoHF_pt;
  Float_t met_T1CHSNoHF_phi;
  Float_t met_rawNoHF_pt;
  Float_t met_rawNoHF_phi;
  Float_t met_T1CHSNoHF_fromCORE_pt;
  Float_t met_T1CHSNoHF_fromCORE_phi;

};

#endif

