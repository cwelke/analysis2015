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
  Int_t           HLT_MuEG;   
  Int_t           HLT_DoubleMu;   
  Int_t           HLT_Photons;   

  //----- LEPTONS
  Int_t           nlep;
  vector <LorentzVector> lep_p4;
  vector <Float_t> lep_pt         ;   //[nlep]
  vector <Float_t> lep_eta        ;   //[nlep]
  vector <Float_t> lep_phi        ;   //[nlep]
  vector <Float_t> lep_mass       ;   //[nlep]
  vector <Int_t  > lep_charge     ;   //[nlep]
  vector <Int_t  > lep_pdgId      ;   //[nlep]
  vector <Float_t> lep_dxy        ;   //[nlep]
  vector <Float_t> lep_dz         ;   //[nlep]
  vector <Int_t  > lep_tightId    ;   //[nlep]
  vector <Float_t> lep_relIso03   ;   //[nlep]
  vector <Float_t> lep_relIso03MREA   ;   //[nlep]
  vector <Float_t> lep_relIso03MRDB   ;   //[nlep]
  vector <Float_t> lep_relIso03MRNC   ;   //[nlep]
  vector <Float_t> lep_relIso04   ;   //[nlep]
  vector <Int_t  > lep_mcMatchId  ;   //[nlep]
  vector <Int_t  > lep_lostHits   ;   //[nlep]
  vector <Int_t  > lep_convVeto   ;   //[nlep]
  vector <Int_t  > lep_tightCharge;   //[nlep]
  vector <Int_t  > lep_islead     ;   //[nlep]
  vector <Int_t  > lep_istail     ;   //[nlep]
  
//----- TAUS
  Int_t           ntau;
  vector <Float_t> tau_pt       ;   //[ntau]
  vector <Float_t> tau_eta      ;   //[ntau]
  vector <Float_t> tau_phi      ;   //[ntau]
  vector <Float_t> tau_mass     ;   //[ntau]
  vector <Int_t  > tau_charge   ;   //[ntau]
  vector <Float_t> tau_dxy      ;   //[ntau]
  vector <Float_t> tau_dz       ;   //[ntau]
  vector <Int_t  > tau_idCI3hit ;   //[ntau]
  vector <Float_t> tau_isoCI3hit;   //[ntau]
  // vector <Float_t> tau_isoMVA2  ;   //[ntau]
  // vector <Int_t  > tau_idMVA2   ;   //[ntau]
  // vector <Int_t  > tau_mcMatchId;   //[ntau]

//----- PHOTONS
  Int_t           ngamma;
  vector <LorentzVector>   gamma_p4;
  vector <Float_t>         gamma_pt           ;   //[ngamma]
  vector <Float_t>         gamma_eta          ;   //[ngamma]
  vector <Float_t>         gamma_phi          ;   //[ngamma]
  vector <Float_t>         gamma_mass         ;   //[ngamma]
  vector <Float_t>         gamma_sigmaIetaIeta;   //[ngamma]
  vector <Float_t>         gamma_chHadIso     ;   //[ngamma]
  vector <Float_t>         gamma_neuHadIso    ;   //[ngamma]
  vector <Float_t>         gamma_phIso        ;   //[ngamma]
  vector <Float_t>         gamma_r9           ;   //[ngamma]
  vector <Float_t>         gamma_hOverE       ;   //[ngamma]
  vector <Int_t  >         gamma_idCutBased   ;   //[ngamma]
  vector <Int_t  >         gamma_mcMatchId    ;   //[ngamma]
  vector <Float_t>         gamma_genIso       ;   //[ngamma]

  // event level vars recalculated for photon+jets control region
  Int_t           gamma_nJet40;
  Int_t           gamma_nBJet40;

//----- GEN PARTICLES
  Int_t           ngenPart;
  vector <Float_t>         genPart_pt       ;   //[ngenPart]
  vector <Float_t>         genPart_eta      ;   //[ngenPart]
  vector <Float_t>         genPart_phi      ;   //[ngenPart]
  vector <Float_t>         genPart_mass     ;   //[ngenPart]
  vector <Int_t  >         genPart_pdgId    ;   //[ngenPart]
  vector <Int_t  >         genPart_status   ;   //[ngenPart]
  vector <Float_t>         genPart_charge   ;   //[ngenPart]
  vector <Int_t  >         genPart_motherId ;   //[ngenPart]
  vector <Int_t  >         genPart_grandmaId;   //[ngenPart]

//----- GEN LEPTONS (ELECTRONS/MUONS)
  Int_t           ngenLep;
  vector <Float_t>         genLep_pt      ;   //[ngenLep]
  vector <Float_t>         genLep_eta     ;   //[ngenLep]
  vector <Float_t>         genLep_phi     ;   //[ngenLep]
  vector <Float_t>         genLep_mass    ;   //[ngenLep]
  vector <Int_t  >         genLep_pdgId   ;   //[ngenLep]
  vector <Int_t  >         genLep_status  ;   //[ngenLep]
  vector <Float_t>         genLep_charge  ;   //[ngenLep]
  vector <Int_t  >         genLep_sourceId;   //[ngenLep]

//----- GEN TAUS
  Int_t           ngenTau;
  vector <Float_t>         genTau_pt      ;   //[ngenTau]
  vector <Float_t>         genTau_eta     ;   //[ngenTau]
  vector <Float_t>         genTau_phi     ;   //[ngenTau]
  vector <Float_t>         genTau_mass    ;   //[ngenTau]
  vector <Int_t  >         genTau_pdgId   ;   //[ngenTau]
  vector <Int_t  >         genTau_status  ;   //[ngenTau]
  vector <Float_t>         genTau_charge  ;   //[ngenTau]
  vector <Int_t  >         genTau_sourceId;   //[ngenTau]

//----- GEN LEPTONS FROM TAUS
  Int_t           ngenLepFromTau;
  vector <Float_t>         genLepFromTau_pt      ;   //[ngenLepFromTau]
  vector <Float_t>         genLepFromTau_eta     ;   //[ngenLepFromTau]
  vector <Float_t>         genLepFromTau_phi     ;   //[ngenLepFromTau]
  vector <Float_t>         genLepFromTau_mass    ;   //[ngenLepFromTau]
  vector <Int_t  >         genLepFromTau_pdgId   ;   //[ngenLepFromTau]
  vector <Int_t  >         genLepFromTau_status  ;   //[ngenLepFromTau]
  vector <Float_t>         genLepFromTau_charge  ;   //[ngenLepFromTau]
  vector <Int_t  >         genLepFromTau_sourceId;   //[ngenLepFromTau]

//----- JETS
  Int_t           njet;
  vector <LorentzVector>   jet_p4;
  vector <LorentzVector>   jets_p4;
  vector <LorentzVector>   jets_eta30_p4;
  vector <Float_t>         jet_pt          ;   //[njet]
  vector <Float_t>         jet_eta         ;   //[njet]
  vector <Float_t>         jet_phi         ;   //[njet]
  vector <Float_t>         jet_mass        ;   //[njet]
  vector <Float_t>         jet_btagCSV     ;   //[njet]
  vector <Float_t>         jet_rawPt       ;   //[njet]
  vector <Float_t>         jet_mcPt        ;   //[njet]
  vector <Int_t  >         jet_mcFlavour   ;   //[njet]
  vector <Float_t>         jet_quarkGluonID;   //[njet]
  vector <Float_t>         jet_area        ;   //[njet]
  vector <Int_t  >         jet_id          ;   //[njet]
  vector <Int_t  >         jet_puId        ;   //[njet]

};

#endif

