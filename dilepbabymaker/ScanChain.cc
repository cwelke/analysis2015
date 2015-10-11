// C++
#include <iostream>
#include <vector>
#include <set>

// ROOT
#include "TChain.h"
#include "TDirectory.h"
#include "TTreeCache.h"
#include "Math/VectorUtil.h"
#include "TVector2.h"
#include "TBenchmark.h"
#include "TLorentzVector.h"

// CORE
#include "../CORE/CMS3.h"
#include "../CORE/Base.h"
#include "../CORE/OSSelections.h"
#include "../CORE/ElectronSelections.h"
#include "../CORE/IsolationTools.h"
#include "../CORE/JetSelections.h"
#include "../CORE/MuonSelections.h"
#include "../CORE/IsoTrackVeto.h"
#include "../CORE/PhotonSelections.h"
#include "../CORE/TriggerSelections.h"
#include "../CORE/VertexSelections.h"
#include "../CORE/MCSelections.h"
#include "../CORE/MetSelections.h"
#include "../CORE/Tools/jetcorr/FactorizedJetCorrector.h"
#include "../CORE/Tools/JetCorrector.h"
#include "../CORE/Tools/MT2/MT2.h"
#include "../CORE/Tools/hemJet.h"
#include "../CORE/Tools/utils.h"
#include "../CORE/Tools/goodrun.h"

// header
#include "ScanChain.h"

using namespace std;
using namespace tas;

// turn on to add debugging statements
const bool verbose = false;
// turn on to apply JEC from text files
const bool applyJECfromFile = true;
//turn on to veto transition region for leps and photons
const bool vetoXitionRegion = false;
//turn on to veto eta > 2.4 for leps and photons
const bool maxEta24 = true;

//--------------------------------------------------------------------

// This is meant to be passed as the third argument, the predicate, of the standard library sort algorithm
inline bool sortByPt(const LorentzVector &vec1, const LorentzVector &vec2 ) {
  return vec1.pt() > vec2.pt();
}

//--------------------------------------------------------------------

void babyMaker::ScanChain(TChain* chain, std::string baby_name){

  // Benchmark
  TBenchmark *bmark = new TBenchmark();
  bmark->Start("benchmark");

  createAndInitMVA("MVAinput", false); // for electrons

  MakeBabyNtuple( Form("%s.root", baby_name.c_str()) );

  // do this once per job
  const char* json_file = "json_golden_168pb_290915_sntformat.txt";
  set_goodrun_file(json_file);
  
  // File Loop
  int nDuplicates = 0;
  int nEvents = chain->GetEntries();
  unsigned int nEventsChain = nEvents;
  cout << "Running on " << nEventsChain << " events" << endl;
  unsigned int nEventsTotal = 0;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;
  while ( (currentFile = (TFile*)fileIter.Next()) ) {
    cout << "running on file: " << currentFile->GetTitle() << endl;

    // evt_id = sampleID(currentFile->GetTitle());

    // Get File Content
    TFile f( currentFile->GetTitle() );
    TTree *tree = (TTree*)f.Get("Events");
    TTreeCache::SetLearnEntries(10);
    tree->SetCacheSize(128*1024*1024);
    cms3.Init(tree);
    
    // ----------------------------------
    // retrieve JEC from files, if using
    // ----------------------------------

    std::vector<std::string> jetcorr_filenames_pfL1FastJetL2L3;
    FactorizedJetCorrector *jet_corrector_pfL1FastJetL2L3;

    if (applyJECfromFile) {
      jetcorr_filenames_pfL1FastJetL2L3.clear();

	  if( TString(currentFile->GetTitle()).Contains("Run2015B") ){
		// files for 50ns Data  
        jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_50nsV4_DATA_L1FastJet_AK4PFchs.txt"   );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_50nsV4_DATA_L2Relative_AK4PFchs.txt"  );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_50nsV4_DATA_L3Absolute_AK4PFchs.txt"  );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_50nsV4_DATA_L2L3Residual_AK4PFchs.txt");
	  }
	  
	  if( TString(currentFile->GetTitle()).Contains("Run2015C") ){
		// files for 25ns Data
        jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_25nsV5ch1pv_DATA_L1FastJet_AK4PFchs.txt"   );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_25nsV5_DATA_L2Relative_AK4PFchs.txt"  );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_25nsV5_DATA_L3Absolute_AK4PFchs.txt"  );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_25nsV3M3_DATA_L2L3Residual_AK4PFchs.txt");

	  }
	  
	  if( TString(currentFile->GetTitle()).Contains("Run2015D") ){
		// files for 25ns Data
        jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_25nsV2_MC_L1FastJet_AK4PFchs.txt"   );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_25nsV2_MC_L2Relative_AK4PFchs.txt"  );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_25nsV2_MC_L3Absolute_AK4PFchs.txt"  );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_50nsV4_DATA_L2L3Residual_AK4PFchs.txt");

	  }
	  
	  else{
		// files for 25ns MC  
        jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_25nsV2_MC_L1FastJet_AK4PFchs.txt"   );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_25nsV2_MC_L2Relative_AK4PFchs.txt"  );
		jetcorr_filenames_pfL1FastJetL2L3.push_back  ("jetCorrections/Summer15_25nsV2_MC_L3Absolute_AK4PFchs.txt"  );
	  }
	  
      jet_corrector_pfL1FastJetL2L3  = makeJetCorrector(jetcorr_filenames_pfL1FastJetL2L3);
    }

    // Event Loop
    unsigned int nEventsTree = tree->GetEntriesFast();
    for( unsigned int event = 0; event < nEventsTree; ++event) {
	  //for( unsigned int event = 0; event < 100; ++event) {

	  // if( event > 1000 ) continue;
	  
      // Get Event Content
      tree->LoadTree(event);
      cms3.GetEntry(event);
      ++nEventsTotal;
    
      // Progress
      CMS3::progress( nEventsTotal, nEventsChain );

      InitBabyNtuple();

      run    = cms3.evt_run();
      lumi   = cms3.evt_lumiBlock();
      evt    = cms3.evt_event();
      isData = cms3.evt_isRealData();

      evt_nEvts    = cms3.evt_nEvts();
      evt_scale1fb = cms3.evt_scale1fb();
      evt_xsec     = cms3.evt_xsec_incl();
      evt_kfactor  = cms3.evt_kfactor();
      evt_filter   = cms3.evt_filt_eff();
	  if( !isData ){
		nTrueInt     = cms3.puInfo_trueNumInteractions().at(0);
	  }
      rho          = cms3.evt_fixgridfastjet_all_rho(); //this one is used in JECs
      puWeight     =      1.;

      if (verbose) cout << "before vertices" << endl;

      //VERTICES
      nVert = 0;
      for(unsigned int ivtx=0; ivtx < cms3.evt_nvtxs(); ivtx++){

        if(     cms3.vtxs_isFake()   .at(ivtx)             ) continue;
        if(     cms3.vtxs_ndof()     .at(ivtx)       <= 4  ) continue;
        if(fabs(cms3.vtxs_position() .at(ivtx).z())  >  24 ) continue;
        if(     cms3.vtxs_position() .at(ivtx).Rho() >  2  ) continue;

        nVert++;
  
      }
      
      met_pt     = cms3.evt_pfmet();
      met_phi    = cms3.evt_pfmetPhi();
      met_genPt  = cms3.gen_met();
      met_genPhi = cms3.gen_metPhi();
      met_rawPt  = cms3.evt_pfmet_raw();
      met_rawPhi = cms3.evt_pfmetPhi_raw();
      sumet_raw  = cms3.evt_pfsumet_raw();

      // MET FILTERS
      Flag_EcalDeadCellTriggerPrimitiveFilter       = cms3.filt_ecalTP();
      Flag_trkPOG_manystripclus53X                  = cms3.filt_trkPOG_manystripclus53X();
      Flag_ecalLaserCorrFilter                      = cms3.filt_ecalLaser();
      Flag_trkPOG_toomanystripclus53X               = cms3.filt_trkPOG_toomanystripclus53X();
      Flag_hcalLaserEventFilter                     = cms3.filt_hcalLaser();
      Flag_trkPOG_logErrorTooManyClusters           = cms3.filt_trkPOG_logErrorTooManyClusters();
      Flag_trkPOGFilters                            = cms3.filt_trkPOGFilters();
      Flag_trackingFailureFilter                    = cms3.filt_trackingFailure();
      Flag_goodVertices                             = cms3.filt_goodVertices();
      Flag_eeBadScFilter                            = cms3.filt_eeBadSc();
      // note: in CMS3, filt_cscBeamHalo and evt_cscTightHaloId are the same
      Flag_CSCTightHaloFilter                       = cms3.filt_cscBeamHalo();
      // note: in CMS3, filt_hbheNoise and evt_hbheFilter are the same
      //      Flag_HBHENoiseFilter                          = cms3.filt_hbheNoise();
      // recompute HBHE noise filter decision using CORE to avoid maxZeros issue
      if (!isData) Flag_HBHENoiseFilter             = cms3.filt_hbheNoise();
      else if (TString(currentFile->GetTitle()).Contains("Run2015B")) Flag_HBHENoiseFilter = hbheNoiseFilter();
      else                                                            Flag_HBHENoiseFilter = hbheNoiseFilter_25ns();
      Flag_HBHEIsoNoiseFilter                       = hbheIsoNoiseFilter();
      // necessary?
      Flag_METFilters                               = cms3.filt_metfilter();
	  
      //TRIGGER
      HLT_DoubleEl_noiso = passHLTTriggerPattern( "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v");
      HLT_DoubleEl       = passHLTTriggerPattern( "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v");
	  HLT_DoubleEl_DZ    = passHLTTriggerPattern( "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
      HLT_MuEG           = (passHLTTriggerPattern("HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v") ||
							passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v") );
      HLT_MuEG_2         = (passHLTTriggerPattern("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v") ||
							passHLTTriggerPattern("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v") );
      HLT_DoubleMu       = passHLTTriggerPattern( "HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v");
      HLT_DoubleMu_tk    = passHLTTriggerPattern( "HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v");

      HLT_DoubleMu_nonDZ             = HLT_prescale(triggerName("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v"));	  
	  HLT_Photon22_R9Id90_HE10_IsoM  = HLT_prescale(triggerName("HLT_Photon22_R9Id90_HE10_IsoM_v" ));
	  HLT_Photon30_R9Id90_HE10_IsoM  = HLT_prescale(triggerName("HLT_Photon30_R9Id90_HE10_IsoM_v" ));
	  HLT_Photon36_R9Id90_HE10_IsoM  = HLT_prescale(triggerName("HLT_Photon36_R9Id90_HE10_IsoM_v" ));
	  HLT_Photon50_R9Id90_HE10_IsoM  = HLT_prescale(triggerName("HLT_Photon50_R9Id90_HE10_IsoM_v" ));
	  HLT_Photon75_R9Id90_HE10_IsoM  = HLT_prescale(triggerName("HLT_Photon75_R9Id90_HE10_IsoM_v" ));
	  HLT_Photon90_R9Id90_HE10_IsoM  = HLT_prescale(triggerName("HLT_Photon90_R9Id90_HE10_IsoM_v" ));
	  HLT_Photon120_R9Id90_HE10_IsoM = HLT_prescale(triggerName("HLT_Photon120_R9Id90_HE10_IsoM_v"));
	  HLT_Photon165_R9Id90_HE10_IsoM = HLT_prescale(triggerName("HLT_Photon165_R9Id90_HE10_IsoM_v"));
      
      if (verbose) cout << "before gen particles" << endl;

      //GEN PARTICLES
      ngenPart       = 0;
	  ngen_p6s3Part  = 0;
      ngenLep        = 0;
	  ngen_p6s3Lep   = 0;
	  ngenTau        = 0;
      ngenLepFromTau = 0;
      gen_ht         = 0;

	  if ( cms3.evt_isRealData() && !goodrun(cms3.evt_run(), cms3.evt_lumiBlock()) ) evt_passgoodrunlist = false;
	  
	  if( !isData ){
	  
		for(unsigned int iGen = 0; iGen < cms3.genps_p4().size(); iGen++){
		  genPart_p4            .push_back( cms3.genps_p4()                           .at(iGen));
		  genPart_pt            .push_back( cms3.genps_p4()                           .at(iGen).pt());
		  genPart_eta           .push_back( cms3.genps_p4()                           .at(iGen).eta());
		  genPart_phi           .push_back( cms3.genps_p4()                           .at(iGen).phi());
		  genPart_mass          .push_back( cms3.genps_mass()                         .at(iGen));
		  genPart_pdgId         .push_back( cms3.genps_id()                           .at(iGen));
		  genPart_status        .push_back( cms3.genps_status()                       .at(iGen));
		  genPart_isp6status3   .push_back( cms3.genps_isMostlyLikePythia6Status3()   .at(iGen));
		  genPart_charge        .push_back( cms3.genps_charge()                       .at(iGen));
		  genPart_motherId      .push_back( cms3.genps_id_simplemother()              .at(iGen));
		  genPart_grandmaId     .push_back( cms3.genps_id_simplegrandma()             .at(iGen));
		  ngenPart++;
		  if( cms3.genps_isMostlyLikePythia6Status3().at(iGen) ) ngen_p6s3Part++;
		  //calculate gen_ht for stitching purposes
		  if((abs(cms3.genps_id().at(iGen)) <  6 || // quarks
			  abs(cms3.genps_id().at(iGen)) == 21)  // gluons
			 && (cms3.genps_status().at(iGen) == 22 || // something to do with "status 3"
				 cms3.genps_status().at(iGen) == 23)){
			gen_ht += cms3.genps_p4()              .at(iGen).pt();
		  }

		  // save lepton info
		  int pdgId = abs(cms3.genps_id().at(iGen));
		  if ((pdgId != 11) && (pdgId != 13) && (pdgId != 15)) continue;

		  int motherId  = abs(cms3.genps_id_simplemother()  .at(iGen));
		  int grandmaId = abs(cms3.genps_id_simplegrandma() .at(iGen));
		  int status    =     cms3.genps_status()           .at(iGen);

		  // reject leptons with direct parents of quarks or hadrons. 
		  //  Allow SUSY parents - not explicitly checking for now though
		  if (motherId <= 5 || (motherId > 100 && motherId < 1000000)) continue;

		  bool goodLep = false;
		  bool goodTau = false;
		  bool goodLepFromTau = false;
		  int sourceId = 0;

		  // electrons, muons: status 1 or 23 and mother W/Z/H or tau from W/Z/H
		  if ( (pdgId == 11 || pdgId == 13) && (status == 1 || status == 23) ) {
			// save leptons pre-FSR: prefer status 23 over status 1
			if (status == 1 && motherId == pdgId && (cms3.genps_status().at(cms3.genps_idx_simplemother().at(iGen)) == 23)) {
			  // don't save
			}
			// leptons from taus
			else if (motherId == 15 && (grandmaId == 25 || grandmaId == 24 || grandmaId == 23 || grandmaId == 15)) {
			  goodLepFromTau = true;
			} 
			// leptons from W/Z/H
			else if (motherId == 25 || motherId == 24 || motherId == 23) {
			  goodLep = true;
			} 
		  } // status 1 e or mu

		  // taus: status 2 or 23, from W/Z/H
		  else if (pdgId == 15 && (status == 2 || status == 23)) {
			// save leptons pre-FSR: prefer status 23 over status 2
			if (status == 2 && motherId == pdgId && (cms3.genps_status().at(cms3.genps_idx_simplemother().at(iGen)) == 23)) {
			  // don't save
			}
			// leptons from W/Z/H
			else if (motherId == 25 || motherId == 24 || motherId == 23) {
			  goodTau = true;
			} 
		  } // status 2 tau

		  //broken for some reason :(
		  // if (goodLep || goodTau || goodLepFromTau) {
		  //   sourceId = getSourceId(iGen);
		  // }

		  // save gen leptons (e/mu) directly from W/Z/H
		  if (goodLep) {
			genLep_pt            .push_back( cms3.genps_p4()     .at(iGen).pt());
			genLep_eta           .push_back( cms3.genps_p4()     .at(iGen).eta());
			genLep_phi           .push_back( cms3.genps_p4()     .at(iGen).phi());
			genLep_mass          .push_back( cms3.genps_mass()   .at(iGen));
			genLep_pdgId         .push_back( cms3.genps_id()     .at(iGen));
			genLep_status        .push_back( cms3.genps_status() .at(iGen));
			genLep_charge        .push_back( cms3.genps_charge() .at(iGen));
			genLep_isp6status3   .push_back( cms3.genps_isMostlyLikePythia6Status3()   .at(iGen));
			genLep_sourceId      .push_back( sourceId );
			++ngenLep;
			if( cms3.genps_isMostlyLikePythia6Status3().at(iGen) ) ++ngen_p6s3Lep;
		  }

		  // save gen taus from W/Z/H
		  if (goodTau) {
			genTau_pt      .push_back(cms3.genps_p4()     .at(iGen).pt());
			genTau_eta     .push_back(cms3.genps_p4()     .at(iGen).eta());
			genTau_phi     .push_back(cms3.genps_p4()     .at(iGen).phi());
			genTau_mass    .push_back(cms3.genps_mass()   .at(iGen));
			genTau_pdgId   .push_back(cms3.genps_id()     .at(iGen));
			genTau_status  .push_back(cms3.genps_status() .at(iGen));
			genTau_charge  .push_back(cms3.genps_charge() .at(iGen));
			genTau_sourceId.push_back(sourceId);
			++ngenTau;
		  }

		  // save gen e/mu from taus (which are from W/Z/H)
		  if (goodLepFromTau) {
			genLepFromTau_pt      .push_back(cms3.genps_p4()     .at(iGen).pt());
			genLepFromTau_eta     .push_back(cms3.genps_p4()     .at(iGen).eta());
			genLepFromTau_phi     .push_back(cms3.genps_p4()     .at(iGen).phi());
			genLepFromTau_mass    .push_back(cms3.genps_mass()   .at(iGen));
			genLepFromTau_pdgId   .push_back(cms3.genps_id()     .at(iGen));
			genLepFromTau_status  .push_back(cms3.genps_status() .at(iGen));
			genLepFromTau_charge  .push_back(cms3.genps_charge() .at(iGen));
			genLepFromTau_sourceId.push_back(sourceId);
			++ngenLepFromTau;
		  }

		} // loop over genPart
		// cout<<__LINE__<<endl;
	  }

      //LEPTONS
      std::map<float, int> lep_pt_ordering;
      vector<float>vec_lep_pt;
      vector<float>vec_lep_eta;
      vector<float>vec_lep_phi;
      vector<float>vec_lep_mass;
      vector<float>vec_lep_charge;
      vector<int>  vec_lep_pdgId;
      vector<float>vec_lep_dxy;
      vector<float>vec_lep_dz;
      vector<int>  vec_lep_tightId;
      vector<float>vec_lep_relIso03;
      vector<float>vec_lep_relIso03MREA;
      vector<float>vec_lep_relIso03MRDB;
      vector<float>vec_lep_relIso03MRNC;
      vector<float>vec_lep_relIso04;
      vector<int>  vec_lep_mcMatchId;
      vector<int>  vec_lep_lostHits;
      vector<int>  vec_lep_convVeto;
      vector<int>  vec_lep_tightCharge;
      vector<float>vec_lep_etaSC;
	  
	  vector<LorentzVector> vec_lep_p4s;

	  vector<LorentzVector> p4sLeptonsForJetCleaning;

      if (verbose) cout << "before electrons" << endl;

      //ELECTRONS
      nlep = 0;
      nElectrons10 = 0;
	  for(unsigned int iEl = 0; iEl < cms3.els_p4().size(); iEl++){
 	  	if( !passElectronSelection_ZMET( iEl ) ) continue;

        nElectrons10++;

		if( cms3.els_p4().at(iEl).pt() > 15.0 ){
		  lep_pt_ordering[cms3.els_p4().at(iEl).pt()] = nlep;
		  vec_lep_p4s          .push_back( cms3.els_p4().at(iEl)           );
		  vec_lep_pt           .push_back( cms3.els_p4().at(iEl).pt()      );
		  vec_lep_eta          .push_back( cms3.els_p4().at(iEl).eta()     ); //save eta, even though we use SCeta for ID
		  vec_lep_phi          .push_back( cms3.els_p4().at(iEl).phi()     );
		  vec_lep_mass         .push_back( cms3.els_mass().at(iEl)         );
		  vec_lep_charge       .push_back( cms3.els_charge().at(iEl)       );
		  vec_lep_pdgId        .push_back( cms3.els_charge().at(iEl)*(-11) );
		  vec_lep_dxy          .push_back( cms3.els_dxyPV().at(iEl)        );
		  vec_lep_dz           .push_back( cms3.els_dzPV().at(iEl)         );
		  vec_lep_tightId      .push_back( eleTightID(iEl, ZMET)           );
		  vec_lep_relIso03MREA .push_back( elMiniRelIsoCMS3_EA( iEl )      );
		  vec_lep_etaSC        .push_back( els_etaSC().at(iEl)             );

		  // if( !isData){
		  if (!isData && (cms3.els_mc3dr().at(iEl) < 0.2 && cms3.els_mc3idx().at(iEl) != -9999 && abs(cms3.els_mc3_id().at(iEl)) == 11 )) { // matched to a prunedGenParticle electron?
			  int momid =  abs(genPart_motherId[cms3.els_mc3idx().at(iEl)]);
			  vec_lep_mcMatchId.push_back ( momid != 11 ? momid : genPart_grandmaId[cms3.els_mc3idx().at(iEl)]); // if mother is different store mother, otherwise store grandmother
			}
			else{ vec_lep_mcMatchId.push_back (0);}
		  // }
		  
		  vec_lep_lostHits.push_back ( cms3.els_exp_innerlayers().at(iEl)); //cms2.els_lost_pixelhits().at(iEl);
		  vec_lep_convVeto.push_back ( !cms3.els_conv_vtx_flag().at(iEl));
		  vec_lep_tightCharge.push_back ( tightChargeEle(iEl));

		  nlep++;
		  // if( cms3.els_p4().at(iEl).pt() < 20.0 ) continue;
		}

		p4sLeptonsForJetCleaning.push_back(cms3.els_p4().at(iEl));

      }

	  // if( nlep > 1 ) cout<<"2 electrons pass this event"<<endl<<endl;
	  
	  if (verbose) cout << "before muons" << endl;

      //MUONS
      nMuons10 = 0;
	  // RCLSA: this is a TEMPORARY protections for a problem with CMS3 samples
	  if (cms3.mus_p4().size() != cms3.mus_dzPV().size()) continue;
      
	  for(unsigned int iMu = 0; iMu < cms3.mus_p4().size(); iMu++){
 	  	if( !passMuonSelection_ZMET( iMu ) ) continue;
		nMuons10++;

		if( cms3.mus_p4().at(iMu).pt() > 15.0 ){
		  lep_pt_ordering[cms3.mus_p4().at(iMu).pt()] = nlep;
		  vec_lep_p4s          .push_back ( cms3.mus_p4().at(iMu)                       );
		  vec_lep_pt           .push_back ( cms3.mus_p4().at(iMu).pt()                  );
		  vec_lep_eta          .push_back ( cms3.mus_p4().at(iMu).eta()                 );
		  vec_lep_phi          .push_back ( cms3.mus_p4().at(iMu).phi()                 );
		  vec_lep_mass         .push_back ( cms3.mus_mass().at(iMu)                     );
		  vec_lep_charge       .push_back ( cms3.mus_charge().at(iMu)                   );
		  vec_lep_pdgId        .push_back ( cms3.mus_charge().at(iMu)*(-13)             );
		  vec_lep_dxy          .push_back ( cms3.mus_dxyPV().at(iMu)                    );
		  vec_lep_dz           .push_back ( cms3.mus_dzPV().at(iMu)                     );
		  vec_lep_tightId      .push_back ( muTightID(iMu, ZMET)                        );
		  vec_lep_relIso03MREA .push_back( muMiniRelIso( iMu, true , 0.5, false, true ) );
		  vec_lep_etaSC        .push_back( cms3.mus_p4().at(iMu).eta()                  );

		  // if( !isData){
		  if (!isData && (cms3.mus_mc3dr().at(iMu) < 0.2 && cms3.mus_mc3idx().at(iMu) != -9999 && abs(cms3.mus_mc3_id().at(iMu)) == 13 )) { // matched to a prunedGenParticle electron?
			int momid =  abs(genPart_motherId[cms3.mus_mc3idx().at(iMu)]);
			vec_lep_mcMatchId.push_back ( momid != 13 ? momid : genPart_grandmaId[cms3.mus_mc3idx().at(iMu)]); // if mother is different store mother, otherwise store grandmother
		  }
		  else vec_lep_mcMatchId.push_back (0);
		  // }

		  vec_lep_lostHits.push_back ( cms3.mus_exp_innerlayers().at(iMu)); // use defaults as if "good electron"
		  vec_lep_convVeto.push_back ( 1);// use defaults as if "good electron"
		  vec_lep_tightCharge.push_back ( tightChargeMuon(iMu));

		  nlep++;

		  // if( cms3.mus_p4().at(iMu).pt() < 20.0 ) continue;
		}

		p4sLeptonsForJetCleaning.push_back(cms3.mus_p4().at(iMu));
      }

	  if (verbose) cout<<" before ordering"<<endl;
	  
      // Implement pT ordering for leptons (it's irrelevant but easier for us to add than for ETH to remove)
      //now fill arrays from vectors, isotracks with largest pt first
      int i = 0;
      for(std::map<float, int>::reverse_iterator it = lep_pt_ordering.rbegin(); it!= lep_pt_ordering.rend(); ++it){
		lep_p4           .push_back( vec_lep_p4s          .at(it->second));
		lep_pt           .push_back( vec_lep_pt           .at(it->second));
		lep_eta          .push_back( vec_lep_eta          .at(it->second));
		lep_phi          .push_back( vec_lep_phi          .at(it->second));
		lep_mass         .push_back( vec_lep_mass         .at(it->second));
		lep_charge       .push_back( vec_lep_charge       .at(it->second));
		lep_pdgId        .push_back( vec_lep_pdgId        .at(it->second));
		lep_dz           .push_back( vec_lep_dz           .at(it->second));
		lep_dxy          .push_back( vec_lep_dxy          .at(it->second));
        lep_etaSC        .push_back( vec_lep_etaSC        .at(it->second));
		lep_tightId      .push_back( vec_lep_tightId      .at(it->second));
		lep_relIso03MREA .push_back( vec_lep_relIso03MREA .at(it->second));
		lep_mcMatchId    .push_back( vec_lep_mcMatchId    .at(it->second));
		lep_lostHits     .push_back( vec_lep_lostHits     .at(it->second));
		lep_convVeto     .push_back( vec_lep_convVeto     .at(it->second));
		lep_tightCharge  .push_back( vec_lep_tightCharge  .at(it->second));
		i++;
      }
        
      if (verbose) cout << "before photons" << endl;

      //PHOTONS
      ngamma = 0;
      nGammas20 = 0;
	  for(unsigned int iGamma = 0; iGamma < cms3.photons_p4().size(); iGamma++){
 		if( !passPhotonSelection_ZMET( iGamma ) )continue;

		float pt  = cms3.photons_p4().at(iGamma).pt();
		float eta = cms3.photons_p4().at(iGamma).eta();
		float phi = cms3.photons_p4().at(iGamma).phi();

		gamma_p4           .push_back( cms3.photons_p4().at(iGamma) );
		gamma_pt           .push_back( pt                           );
		gamma_eta          .push_back( eta                          );
		gamma_phi          .push_back( phi                          );

		gamma_mass         .push_back( cms3.photons_mass().at(iGamma)                  );
		gamma_sigmaIetaIeta.push_back( cms3.photons_full5x5_sigmaIEtaIEta().at(iGamma) );
		gamma_chHadIso     .push_back( cms3.photons_chargedHadronIso().at(iGamma)      );
		gamma_neuHadIso    .push_back( cms3.photons_neutralHadronIso().at(iGamma)      );
		gamma_phIso        .push_back( cms3.photons_photonIso().at(iGamma)             );
		gamma_r9           .push_back( cms3.photons_full5x5_r9().at(iGamma)            );
		gamma_hOverE       .push_back( cms3.photons_full5x5_hOverEtowBC().at(iGamma)   );
		gamma_idCutBased   .push_back( isTightPhoton(iGamma,HAD) ? 1 : 0               ); 		
		if(gamma_pt[ngamma] > 20) nGammas20++;
	
		// Some work for truth-matching (should be integrated in CMS3 as for the leptons)
		int bestMatch = -1;
		float bestDr = 0.1;

		if( !isData){		  
		  for(unsigned int iGen = 0; iGen < cms3.genps_p4().size(); iGen++){
			if ( cms3.genps_id()                   .at(iGen)        != 22 ) continue; 
			if ( cms3.genps_status()               .at(iGen)        != 1  ) continue; 
			if ( fabs(cms3.genps_id_simplemother() .at(iGen))       > 22  ) continue; // pions etc 
			if ( fabs(eta - cms3.genps_p4()        .at(iGen).eta()) > 0.1 ) continue;
			if ( 2*cms3.genps_p4()                 .at(iGen).pt()   < pt  ) continue;
			if ( 0.5*cms3.genps_p4()               .at(iGen).pt()   > pt  ) continue;
			float thisDR = DeltaR( cms3.genps_p4() .at(iGen).eta(), eta, cms3.genps_p4().at(iGen).phi(), phi);
			if (thisDR < bestDr) {
			  bestDr = thisDR;
			  bestMatch = iGen;
			}
		  }
		  if (bestMatch != -1) {
			// 7 is a special code for photons without a mother. this seems to be due to a miniAOD bug where links are broken.
			gamma_mcMatchId.push_back(cms3.genps_id_simplemother().at(bestMatch) == 0 ? 7 : 22); 
			gamma_genIso.push_back(-1); //cms2.genps_iso().at(bestMatch);
		  }
		  else {
			gamma_mcMatchId.push_back(0);
			gamma_genIso.push_back(-1);
		  }
		}   


		ngamma++;
      }
	
       
	  // add selections to keep only events with photons and dilepton events
	  if( !(ngamma > 0 || nlep > 0) ) continue;// fix for not iso study
       
		// std::pair <int, int> hyp_indices =  getHypLepIndices( lep_p4, lep_pdgId );
	  std::pair <int, int> hyp_indices = std::make_pair(0, 1);
		
	  if (nlep > 1 ) {//require min 2 leps
		if (lep_charge.at(hyp_indices.first)*lep_charge.at(hyp_indices.second) > 0){
		  evt_type = 1; // same sign event
		}else{
		  evt_type = 0; // oppo sign event 
		}

		if (        abs(lep_pdgId.at(hyp_indices.first)) == 11 && abs(lep_pdgId.at(hyp_indices.second)) == 11  ){ hyp_type = 0;// ee event												   			   
		}else if (  abs(lep_pdgId.at(hyp_indices.first)) == 13 && abs(lep_pdgId.at(hyp_indices.second)) == 13  ){ hyp_type = 1;// mm event												   			   
		}else if ( (abs(lep_pdgId.at(hyp_indices.first)) == 11 && abs(lep_pdgId.at(hyp_indices.second)) == 13) ||
				   (abs(lep_pdgId.at(hyp_indices.first)) == 13 && abs(lep_pdgId.at(hyp_indices.second)) == 11) ){ hyp_type = 2;// em event
		}else {
		  cout<<"Leptype not ee, mm, or em! Exiting."<<endl;
		  continue;
		}
		
		dilmass = (lep_p4.at(hyp_indices.first)+lep_p4.at(hyp_indices.second)).mass();
		dilpt   = (lep_p4.at(hyp_indices.first)+lep_p4.at(hyp_indices.second)).pt();       

		//Add dRll
		float dEtall =            lep_p4.at(hyp_indices.first).eta() - lep_p4.at(hyp_indices.second).eta();
		float dPhill = acos( cos( lep_p4.at(hyp_indices.first).phi() - lep_p4.at(hyp_indices.second).phi() ) );
		dRll = sqrt(pow( dEtall, 2) + pow( dPhill, 2));

		for( size_t lepind = 0; lepind < lep_p4.size(); lepind++ ){
		  if( lepind == (size_t)hyp_indices.first  ) lep_islead.push_back(1);
		  else          			        lep_islead.push_back(0);
		  if( lepind == (size_t)hyp_indices.second ) lep_istail.push_back(1);
		  else          			        lep_istail.push_back(0);
		}
		
	  }else{
		evt_type = 2; // photon + jets event
	  }
       	  
	  if (verbose) cout << "before jets" << endl;
	  
      //JETS
      //correct jets and check baseline selections
      vector<LorentzVector> p4sCorrJets; // store corrected p4 for ALL jets, so indices match CMS3 ntuple
      vector<int> passJets; //index of jets that pass baseline selections
      for(unsigned int iJet = 0; iJet < cms3.pfjets_p4().size(); iJet++){

		LorentzVector pfjet_p4_cor = cms3.pfjets_p4().at(iJet);

		if (applyJECfromFile) {

		  // get uncorrected jet p4 to use as input for corrections
		  LorentzVector pfjet_p4_uncor = cms3.pfjets_p4().at(iJet) * cms3.pfjets_undoJEC().at(iJet);

		  // get L1FastL2L3Residual total correction
		  jet_corrector_pfL1FastJetL2L3->setRho   ( cms3.evt_fixgridfastjet_all_rho() );
		  jet_corrector_pfL1FastJetL2L3->setJetA  ( cms3.pfjets_area().at(iJet)       );
		  jet_corrector_pfL1FastJetL2L3->setJetPt ( pfjet_p4_uncor.pt()               );
		  jet_corrector_pfL1FastJetL2L3->setJetEta( pfjet_p4_uncor.eta()              );
		  double corr = jet_corrector_pfL1FastJetL2L3->getCorrection();

		  // apply new JEC to p4
		  pfjet_p4_cor = pfjet_p4_uncor * corr;
		  
		}
		
		p4sCorrJets.push_back(pfjet_p4_cor);
		
		if(p4sCorrJets.at(iJet).pt() < 10.0) continue; 
        if(fabs(p4sCorrJets.at(iJet).eta()) > 5.2) continue;
		// note this uses the eta of the jet as stored in CMS3
		//  chance for small discrepancies if JEC changes direction slightly..
        if(!isLoosePFJet_50nsV1(iJet)) continue;
		passJets.push_back(iJet);
      }

	  if (verbose) cout << "before jet/photon requirements" << endl;
 	  //matched to pfJet with pT > 10 GeV, within cone of dR < 0.3. neutral EM energy fraction > 0.7
 	  for(int iGamma = 0; iGamma < ngamma; iGamma++){
 		if (iGamma>0) continue; // Only care about leading photon.
 
 		float minDR = 0.3;
 		int minIndex = -1;
 		for(unsigned int passIdx = 0; passIdx < passJets.size(); passIdx++){ //loop through jets that passed baseline selections
 	
 		  // int iJet = passJets.at(passIdx);
 		  int iJet = passJets.at(passIdx);
 
 		  if(p4sCorrJets.at(iJet).pt() < 10.0       ) continue;
 		  if(fabs(p4sCorrJets.at(iJet).eta()) > 5.2 ) continue;
 
 		  // float thisDR = DeltaR(p4sCorrJets.at(iJet).eta(), gamma_eta[iGamma], p4sCorrJets.at(iJet).phi(), gamma_phi[iGamma]);
 		  // float thisDR = DeltaR(pfjets_p4().at(iJet).eta(), gamma_eta[iGamma], pfjets_p4().at(iJet).phi(), gamma_phi[iGamma]);
 		  float thisDR = ROOT::Math::VectorUtil::DeltaR(p4sCorrJets.at(iJet), gamma_p4[iGamma]);
 		  if(thisDR < minDR){
 			minDR = thisDR; 
 			minIndex = iJet;
 		  }
 		} // end jet loop
 		if( minIndex > -1 ){
 		  matched_neutralemf = cms3.pfjets_neutralEmE().at(minIndex) / p4sCorrJets.at(minIndex).energy();
 		}	  
 	  
 		if (verbose) cout << "before checking for photon/electron overlap" << endl;
 		//	  elveto
 		for(unsigned int iEl = 0; iEl < cms3.els_p4().size(); iEl++){
 		  if(cms3.els_p4().at(iEl).pt() < 10.0                                              ) continue; // pT > 10 GeV
 		  if( ROOT::Math::VectorUtil::DeltaR(cms3.els_p4().at(iEl), gamma_p4[iGamma]) > 0.2 ) continue; // dr < 0.2
 		  elveto = true;
 		} // end electron loop	  		
 	  }	  
	  
      if (verbose) cout << "before jet/lepton overlap" << endl;

      //check overlapping with leptons
      //only want to remove the closest jet to a lepton, threshold deltaR < 0.4
      vector<int> removedJets; //index of jets to be removed because they overlap with a lepton
      for(unsigned int iLep = 0; iLep < p4sLeptonsForJetCleaning.size(); iLep++){

        float minDR = 0.4;
        int minIndex = -1;
        for(unsigned int passIdx = 0; passIdx < passJets.size(); passIdx++){ //loop through jets that passed baseline selections

          int iJet = passJets.at(passIdx);

          if(      p4sCorrJets.at(iJet).pt()    < 10.0 ) continue;
          if( fabs(p4sCorrJets.at(iJet).eta() ) > 5.2  ) continue;
          if( !isLoosePFJet_50nsV1(iJet)               ) continue;

          bool alreadyRemoved = false;
          for(unsigned int j=0; j<removedJets.size(); j++){
            if(iJet == removedJets.at(j)){
              alreadyRemoved = true;
              break;
            }
          }
          if(alreadyRemoved) continue;

          float thisDR = DeltaR(p4sCorrJets.at(iJet).eta(), p4sLeptonsForJetCleaning.at(iLep).eta(), p4sCorrJets.at(iJet).phi(), p4sLeptonsForJetCleaning.at(iLep).phi());
          if(thisDR < minDR){
            minDR = thisDR; 
            minIndex = iJet;
          }
        }
        removedJets.push_back(minIndex);
      }

      if (verbose) cout << "before jet/photon overlap" << endl;

      //check overlapping with photons
      //only want to remove the closest jet to a photon, threshold deltaR < 0.4
      vector<int> removedJetsGamma; //index of jets to be removed because they overlap with a photon
      for(int iGamma = 0; iGamma < ngamma; iGamma++){
		if (iGamma>0) continue; // Only check leading photon. Let the others be

        float minDR = 0.4;
        int minIndex = -1;
        for(unsigned int passIdx = 0; passIdx < passJets.size(); passIdx++){ //loop through jets that passed baseline selections

          int iJet = passJets.at(passIdx);

          if(      p4sCorrJets.at(iJet).pt()    < 35.0 ) continue;
          if( fabs(p4sCorrJets.at(iJet).eta() ) > 3.0  ) continue;
          if( !isLoosePFJet_50nsV1(iJet)               ) continue;

          bool alreadyRemoved = false;
          for(unsigned int j=0; j<removedJetsGamma.size(); j++){
            if(iJet == removedJetsGamma.at(j)){
              alreadyRemoved = true;
              break;
            }
          }
          if(alreadyRemoved) continue;

          float thisDR = DeltaR(p4sCorrJets.at(iJet).eta(), gamma_eta[iGamma], p4sCorrJets.at(iJet).phi(), gamma_phi[iGamma]);
          if(thisDR < minDR){
            minDR = thisDR; 
            minIndex = iJet;
          }
        }
        removedJetsGamma.push_back(minIndex);
      }

      njet = 0;
      nJet40 = 0;
      nBJet40 = 0;
      nBJetTight  = 0;
      nBJetMedium = 0;
      nBJetLoose  = 0;

	  njets = 0;
	  ht    = 0;
	  njets_eta30 = 0;
	  ht_eta30    = 0;

      if (verbose) cout << "before main jet loop" << endl;
      //now fill variables for jets that pass baseline selections and don't overlap with a lepton
      for(unsigned int passIdx = 0; passIdx < passJets.size(); passIdx++){

        int iJet = passJets.at(passIdx);

        //check against list of jets that overlap with a lepton
        bool isOverlapJet = false;
        for(unsigned int j=0; j<removedJets.size(); j++){
          if(iJet == removedJets.at(j)){
            isOverlapJet = true;
            break;
          }
        }
        if(evt_type == 0 && isOverlapJet) continue;

        //check against list of jets that overlap with a photon for photon+jets events
        bool isOverlapJetGamma = false;
        for(unsigned int j=0; j<removedJetsGamma.size(); j++){
          if(iJet == removedJetsGamma.at(j)){
            isOverlapJetGamma = true;
            break;
          }
        }
        if(evt_type == 2 && isOverlapJetGamma) continue;

		if( p4sCorrJets.at(iJet).pt() > 35.0 && abs(p4sCorrJets.at(iJet).eta()) < 2.4 ){
 		  jets_p4       .push_back(p4sCorrJets.at(iJet));
		  ht+=p4sCorrJets.at(iJet).pt();
		  njets++;
          if(cms3.pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag().at(iJet) >= 0.970) { nBJetTight++; }
          if(cms3.pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag().at(iJet) >= 0.890) { nBJetMedium++; }
          if(cms3.pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag().at(iJet) >= 0.605) { nBJetLoose++; }
		}
		if( p4sCorrJets.at(iJet).pt() > 40.0 && abs(p4sCorrJets.at(iJet).eta()) < 3.0 ){
 		  jets_eta30_p4       .push_back(p4sCorrJets.at(iJet));
 		  ht_eta30+=p4sCorrJets.at(iJet).pt();
 		  njets_eta30++;
		}
		
        jet_p4       .push_back(p4sCorrJets.at(iJet));
        jet_pt       .push_back(p4sCorrJets.at(iJet).pt());
        jet_eta      .push_back(p4sCorrJets.at(iJet).eta());
        jet_phi      .push_back(p4sCorrJets.at(iJet).phi());
        jet_mass     .push_back(cms3.pfjets_mass().at(iJet));
        jet_btagCSV  .push_back(cms3.pfjets_pfCombinedInclusiveSecondaryVertexV2BJetTag().at(iJet)); 
		if( !isData){
		  jet_mcPt     .push_back(cms3.pfjets_mc_p4().at(iJet).pt());
		  jet_mcFlavour.push_back(cms3.pfjets_partonFlavour().at(iJet));
		}
		//jet_quarkGluonID
        jet_area .push_back(cms3.pfjets_area().at(iJet));
		jet_rawPt.push_back(cms3.pfjets_p4().at(iJet).pt() * cms3.pfjets_undoJEC().at(iJet));

        if(     isTightPFJet_50nsV1  (iJet)) jet_id.push_back(3);
        else                               jet_id.push_back(1); //required to be loose above

        jet_puId.push_back(loosePileupJetId(iJet) ? 1 : 0);

        if( (jet_pt[njet] > 40.0) && (fabs(jet_eta[njet]) < 2.5) ){ 
          nJet40++;
		  //CSVv2IVFM
          if(jet_btagCSV[njet] >= 0.890) { nBJet40++; }
        } // pt 40 eta 2.5

        njet++;
      }

	  // add kinematic variables to do with jets leps and photons here
	  // MT2J( MET_MAGNITUDE, MET_PHI, P4_LEPTON_1, P4_LEPTON_2, VECT_P4_Jets, MASS_INVISIBLE_PARTICLE, MT2_CALCULATION_METHOD )
	  if( lep_p4.size() > 1 ){
 	
 		if( jets_p4.size() > 1 ){
 		  mt2j = MT2J( met_pt, met_phi, lep_p4.at(0), lep_p4.at(1), jets_p4, 0.0 );
		}else{
		  mt2j = -1.0;
		}

 		if( jets_eta30_p4.size() > 1 ){
 		  mt2j_eta30 = MT2J( met_pt, met_phi, lep_p4.at(0), lep_p4.at(1),jets_eta30_p4, 0.0 );
 		}else{
		  mt2j_eta30 = -1.0;
		}
	  }else{
		mt2j = -1.0;
		mt2j_eta30 = -1.0;
	  }

	  //remove for now until V08 samples are available
	  pair<float,float> newMET = getT1CHSMET(jet_corrector_pfL1FastJetL2L3);
	  met_T1CHS_fromCORE_pt  = newMET.first;
	  met_T1CHS_fromCORE_phi = newMET.second;

	  pair <float, float> newMET3p0 = getT1CHSMET3p0(jet_corrector_pfL1FastJetL2L3);
	  met_T1CHSNoHF_fromCORE_pt  = newMET3p0.first;
      met_T1CHSNoHF_fromCORE_phi = newMET3p0.second;

	  met_T1CHS_pt  = cms3.evt_METToolbox_pfmet();
      met_T1CHS_phi = cms3.evt_METToolbox_pfmetPhi();

	  met_T1CHSNoHF_pt  = cms3.evt_METToolboxNoHF_pfmet();
      met_T1CHSNoHF_phi = cms3.evt_METToolboxNoHF_pfmetPhi();

	  met_rawNoHF_pt  = cms3.evt_METToolboxNoHF_pfmet_raw();
      met_rawNoHF_phi = cms3.evt_METToolboxNoHF_pfmetPhi_raw();

	  // cout<<"CORE: "<<met_T1CHS_fromCORE_pt<<endl;
	  // cout<<"METG: "<<met_T1CHS_pt<<endl<<endl;
	  
	  float metx = 0.0;
	  float mety = 0.0;
	  float pzx  = 0.0;
	  float pzy  = 0.0;
	  float dx   = 0.0;
	  float dy   = 0.0;

	  if( nlep > 1 ){
		//---------------------------------------------
		// calculate JZB = | -MET - pTZ | - | pTZ |
		//---------------------------------------------
		metx = met_pt * cos( met_phi );
		mety = met_pt * sin( met_phi );
		pzx  = (lep_p4.at(0)+lep_p4.at(1)).px();       
		pzy  = (lep_p4.at(0)+lep_p4.at(1)).py();       
		dx   = -1 * ( metx + pzx );
		dy   = -1 * ( mety + pzy );
		jzb_T1 = sqrt( dx*dx + dy*dy ) - (lep_p4.at(0)+lep_p4.at(1)).pt();
	  
		//---------------------------------------------
		// calculate JZB = | -MET - pTZ | - | pTZ |; using raw pfMET
		//---------------------------------------------
		metx = met_rawPt * cos( met_rawPhi );
		mety = met_rawPt * sin( met_rawPhi );
		dx   = -1 * ( metx + pzx );
		dy   = -1 * ( mety + pzy );
		jzb_raw = sqrt( dx*dx + dy*dy ) - (lep_p4.at(0)+lep_p4.at(1)).pt();
	  }
	  
	  if( ngamma > 0 ){
		//---------------------------------------------
		// calculate JGB = | -MET - pTZ | - | pTZ |
		//---------------------------------------------
		metx = met_pt * cos( met_phi );
		mety = met_pt * sin( met_phi );
		pzx  = cms3.photons_p4().at(0).px();       
		pzy  = cms3.photons_p4().at(0).py();       
		dx   = -1 * ( metx + pzx );
		dy   = -1 * ( mety + pzy );
		jgb_T1 = sqrt( dx*dx + dy*dy ) - cms3.photons_p4().at(0).pt();

		//---------------------------------------------
		// calculate JGB = | -MET - pTZ | - | pTZ |; using raw pfMET
		//---------------------------------------------
		metx = met_rawPt * cos( met_rawPhi );
		mety = met_rawPt * sin( met_rawPhi );
		dx   = -1 * ( metx + pzx );
		dy   = -1 * ( mety + pzy );
		jgb_raw = sqrt( dx*dx + dy*dy ) - cms3.photons_p4().at(0).pt();
	  }
	  

      FillBabyNtuple();

	}//end loop on events in a file
  
    delete tree;
    f.Close();
  }//end loop on files
  
  cout << "Processed " << nEventsTotal << " events" << endl;
  if ( nEventsChain != nEventsTotal ) {
    std::cout << "ERROR: number of events from files is not equal to total number of events" << std::endl;
  }

  cout << nDuplicates << " duplicate events were skipped." << endl;

  CloseBabyNtuple();

  bmark->Stop("benchmark");
  cout << endl;
  cout << nEventsTotal << " Events Processed" << endl;
  cout << "------------------------------" << endl;
  cout << "CPU  Time:	" << Form( "%.01f s", bmark->GetCpuTime("benchmark")  ) << endl;
  cout << "Real Time:	" << Form( "%.01f s", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;
  // delete bmark;

  return;
}

void babyMaker::MakeBabyNtuple(const char *BabyFilename){

  //
  BabyFile_ = new TFile(Form("%s", BabyFilename), "RECREATE");
  BabyFile_->cd();
  BabyTree_ = new TTree("t", "A Baby Ntuple");

  BabyTree_->Branch("run", &run );
  BabyTree_->Branch("lumi", &lumi );
  BabyTree_->Branch("evt", &evt );
  BabyTree_->Branch("isData", &isData );
  BabyTree_->Branch("evt_passgoodrunlist", &evt_passgoodrunlist);
  BabyTree_->Branch("evt_scale1fb", &evt_scale1fb);
  BabyTree_->Branch("evt_xsec", &evt_xsec );
  BabyTree_->Branch("evt_kfactor", &evt_kfactor );
  BabyTree_->Branch("evt_filter", &evt_filter );
  BabyTree_->Branch("evt_nEvts", &evt_nEvts );
  // BabyTree_->Branch("evt_id", &evt_id );
  BabyTree_->Branch("puWeight", &puWeight );
  BabyTree_->Branch("nVert", &nVert );
  BabyTree_->Branch("nTrueInt", &nTrueInt );
  BabyTree_->Branch("rho", &rho );
  BabyTree_->Branch("rho25", &rho25 );

  BabyTree_->Branch("njets", &njets );
  BabyTree_->Branch("ht", &ht );
  BabyTree_->Branch("gen_ht", &gen_ht );
  BabyTree_->Branch("njets_eta30", &njets_eta30 );
  BabyTree_->Branch("ht_eta30", &ht_eta30 );

  BabyTree_->Branch("mt2", &mt2 );
  BabyTree_->Branch("mt2j", &mt2j );
  BabyTree_->Branch("mt2j_eta30", &mt2j_eta30 );

  BabyTree_->Branch("nJet40", &nJet40 );
  BabyTree_->Branch("nBJet40", &nBJet40 );
  BabyTree_->Branch("nBJetTight", &nBJetTight );
  BabyTree_->Branch("nBJetMedium", &nBJetMedium );
  BabyTree_->Branch("nBJetLoose", &nBJetLoose );
  BabyTree_->Branch("nMuons10", &nMuons10 );
  BabyTree_->Branch("nElectrons10", &nElectrons10 );
  BabyTree_->Branch("nGammas20", &nGammas20 );

  BabyTree_->Branch("met_pt", &met_pt );
  BabyTree_->Branch("met_phi", &met_phi );
  BabyTree_->Branch("met_rawPt",  &met_rawPt );
  BabyTree_->Branch("met_rawPhi", &met_rawPhi );
  BabyTree_->Branch("met_caloPt",  &met_caloPt );
  BabyTree_->Branch("met_caloPhi", &met_caloPhi );
  BabyTree_->Branch("met_genPt",  &met_genPt );
  BabyTree_->Branch("met_genPhi", &met_genPhi );

  BabyTree_->Branch("sumet_raw", &sumet_raw );
  BabyTree_->Branch("jzb_raw"  , &jzb_raw   );
  BabyTree_->Branch("jzb_T1"   , &jzb_T1    );
  BabyTree_->Branch("jgb_raw"  , &jgb_raw   );
  BabyTree_->Branch("jgb_T1"   , &jgb_T1    );
  
  BabyTree_->Branch("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter );
  BabyTree_->Branch("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X );
  BabyTree_->Branch("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter );
  BabyTree_->Branch("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X );
  BabyTree_->Branch("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter );
  BabyTree_->Branch("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters );
  BabyTree_->Branch("Flag_trkPOGFilters", &Flag_trkPOGFilters );
  BabyTree_->Branch("Flag_trackingFailureFilter", &Flag_trackingFailureFilter );
  BabyTree_->Branch("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter );
  BabyTree_->Branch("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter );
  BabyTree_->Branch("Flag_HBHEIsoNoiseFilter", &Flag_HBHEIsoNoiseFilter );
  BabyTree_->Branch("Flag_goodVertices", &Flag_goodVertices );
  BabyTree_->Branch("Flag_eeBadScFilter", &Flag_eeBadScFilter );
  BabyTree_->Branch("Flag_METFilters"   , &Flag_METFilters );

  BabyTree_->Branch("HLT_DoubleEl"      , &HLT_DoubleEl );
  BabyTree_->Branch("HLT_DoubleEl_DZ"   , &HLT_DoubleEl_DZ );
  BabyTree_->Branch("HLT_DoubleEl_noiso", &HLT_DoubleEl_noiso );
  BabyTree_->Branch("HLT_MuEG"          , &HLT_MuEG );
  BabyTree_->Branch("HLT_MuEG_2"        , &HLT_MuEG_2 );
  BabyTree_->Branch("HLT_DoubleMu"      , &HLT_DoubleMu );
  BabyTree_->Branch("HLT_DoubleMu_tk"   , &HLT_DoubleMu_tk );
  BabyTree_->Branch("HLT_DoubleMu_nonDZ"   , &HLT_DoubleMu_nonDZ );
  BabyTree_->Branch("HLT_Photon22_R9Id90_HE10_IsoM" , &HLT_Photon22_R9Id90_HE10_IsoM  ); 
  BabyTree_->Branch("HLT_Photon30_R9Id90_HE10_IsoM" , &HLT_Photon30_R9Id90_HE10_IsoM  ); 
  BabyTree_->Branch("HLT_Photon36_R9Id90_HE10_IsoM" , &HLT_Photon36_R9Id90_HE10_IsoM  ); 
  BabyTree_->Branch("HLT_Photon50_R9Id90_HE10_IsoM" , &HLT_Photon50_R9Id90_HE10_IsoM  ); 
  BabyTree_->Branch("HLT_Photon75_R9Id90_HE10_IsoM" , &HLT_Photon75_R9Id90_HE10_IsoM  ); 
  BabyTree_->Branch("HLT_Photon90_R9Id90_HE10_IsoM" , &HLT_Photon90_R9Id90_HE10_IsoM  ); 
  BabyTree_->Branch("HLT_Photon120_R9Id90_HE10_IsoM", &HLT_Photon120_R9Id90_HE10_IsoM );
  BabyTree_->Branch("HLT_Photon165_R9Id90_HE10_IsoM", &HLT_Photon165_R9Id90_HE10_IsoM );

  BabyTree_->Branch("dilmass", &dilmass );
  BabyTree_->Branch("dilpt"  , &dilpt );
  BabyTree_->Branch("dRll"   , &dRll );

  BabyTree_->Branch("matched_neutralemf", &matched_neutralemf );
  BabyTree_->Branch("elveto", &elveto );

  BabyTree_->Branch("nlep", &nlep, "nlep/I" );
  BabyTree_->Branch("lep_p4"         , &lep_p4         );
  BabyTree_->Branch("lep_pt"         , "std::vector< Float_t >"       , &lep_pt         );
  BabyTree_->Branch("lep_eta"        , "std::vector< Float_t >"       , &lep_eta        );
  BabyTree_->Branch("lep_phi"        , "std::vector< Float_t >"       , &lep_phi        );
  BabyTree_->Branch("lep_mass"       , "std::vector< Float_t >"       , &lep_mass       );
  BabyTree_->Branch("lep_charge"     , "std::vector< Int_t >"         , &lep_charge     );
  BabyTree_->Branch("lep_pdgId"      , "std::vector< Int_t >"         , &lep_pdgId      );
  BabyTree_->Branch("lep_dxy"        , "std::vector< Float_t >"       , &lep_dxy        );
  BabyTree_->Branch("lep_etaSC"      , "std::vector< Float_t >"       , &lep_etaSC      );
  BabyTree_->Branch("lep_dz"         , "std::vector< Float_t >"       , &lep_dz         );
  BabyTree_->Branch("lep_tightId"    , "std::vector< Int_t >"         , &lep_tightId    );
  BabyTree_->Branch("lep_relIso03"   , "std::vector< Float_t >"       , &lep_relIso03   );
  BabyTree_->Branch("lep_relIso03MREA"   , "std::vector< Float_t >"       , &lep_relIso03MREA   );
  BabyTree_->Branch("lep_relIso03MRDB"   , "std::vector< Float_t >"       , &lep_relIso03MRDB   );
  BabyTree_->Branch("lep_relIso03MRNC"   , "std::vector< Float_t >"       , &lep_relIso03MRNC   );
  BabyTree_->Branch("lep_relIso04"   , "std::vector< Float_t >"       , &lep_relIso04   );
  BabyTree_->Branch("lep_mcMatchId"  , "std::vector< Int_t >"         , &lep_mcMatchId  );
  BabyTree_->Branch("lep_lostHits"   , "std::vector< Int_t >"         , &lep_lostHits   );
  BabyTree_->Branch("lep_convVeto"   , "std::vector< Int_t >"         , &lep_convVeto   );
  BabyTree_->Branch("lep_tightCharge", "std::vector< Int_t >"         , &lep_tightCharge);
  BabyTree_->Branch("lep_islead"     , "std::vector< Int_t >"         , &lep_islead     );
  BabyTree_->Branch("lep_istail"     , "std::vector< Int_t >"         , &lep_istail     );


  BabyTree_->Branch("ngamma"             , &ngamma        , "ngamma/I" );
  BabyTree_->Branch("gamma_p4"           , &gamma_p4    );
  BabyTree_->Branch("gamma_pt"           , "std::vector <Float_t>" , &gamma_pt           );
  BabyTree_->Branch("gamma_eta"          , "std::vector <Float_t>" , &gamma_eta          );
  BabyTree_->Branch("gamma_phi"          , "std::vector <Float_t>" , &gamma_phi          );
  BabyTree_->Branch("gamma_mass"         , "std::vector <Float_t>" , &gamma_mass         );
  BabyTree_->Branch("gamma_mcMatchId"    , "std::vector <Int_t  >" , &gamma_mcMatchId    );
  BabyTree_->Branch("gamma_genIso"       , "std::vector <Float_t>" , &gamma_genIso       );
  BabyTree_->Branch("gamma_chHadIso"     , "std::vector <Float_t>" , &gamma_chHadIso     );
  BabyTree_->Branch("gamma_neuHadIso"    , "std::vector <Float_t>" , &gamma_neuHadIso    );
  BabyTree_->Branch("gamma_phIso"        , "std::vector <Float_t>" , &gamma_phIso        );
  BabyTree_->Branch("gamma_sigmaIetaIeta", "std::vector <Float_t>" , &gamma_sigmaIetaIeta);
  BabyTree_->Branch("gamma_r9"           , "std::vector <Float_t>" , &gamma_r9           );
  BabyTree_->Branch("gamma_hOverE"       , "std::vector <Float_t>" , &gamma_hOverE       );
  BabyTree_->Branch("gamma_idCutBased"   , "std::vector <Int_t  >" , &gamma_idCutBased   );

  BabyTree_->Branch("ngenPart"         , &ngenPart        , "ngenPart/I" );
  BabyTree_->Branch("genPart_p4"       , &genPart_p4         );
  BabyTree_->Branch("genPart_pt"       , "std::vector <Float_t>" , &genPart_pt        );
  BabyTree_->Branch("genPart_eta"      , "std::vector <Float_t>" , &genPart_eta       );
  BabyTree_->Branch("genPart_phi"      , "std::vector <Float_t>" , &genPart_phi       );
  BabyTree_->Branch("genPart_mass"     , "std::vector <Float_t>" , &genPart_mass      );
  BabyTree_->Branch("genPart_pdgId"    , "std::vector <Int_t  >" , &genPart_pdgId     );
  BabyTree_->Branch("genPart_status"   , "std::vector <Int_t  >" , &genPart_status    );
  BabyTree_->Branch("genPart_charge"   , "std::vector <Float_t>" , &genPart_charge    );
  BabyTree_->Branch("genPart_motherId" , "std::vector <Int_t  >" , &genPart_motherId  );
  BabyTree_->Branch("genPart_grandmaId", "std::vector <Int_t  >" , &genPart_grandmaId );
  BabyTree_->Branch("genPart_isp6status3"  , "std::vector <Bool_t  >" , &genPart_isp6status3  );

  BabyTree_->Branch("ngenLep", &ngenLep, "ngenLep/I" );
  BabyTree_->Branch("genLep_pt"      , "std::vector <Float_t>" , &genLep_pt      );
  BabyTree_->Branch("genLep_eta"     , "std::vector <Float_t>" , &genLep_eta     );
  BabyTree_->Branch("genLep_phi"     , "std::vector <Float_t>" , &genLep_phi     );
  BabyTree_->Branch("genLep_mass"    , "std::vector <Float_t>" , &genLep_mass    );
  BabyTree_->Branch("genLep_pdgId"   , "std::vector <Int_t  >" , &genLep_pdgId   );
  BabyTree_->Branch("genLep_status"  , "std::vector <Int_t  >" , &genLep_status  );
  BabyTree_->Branch("genLep_charge"  , "std::vector <Float_t>" , &genLep_charge  );
  BabyTree_->Branch("genLep_sourceId", "std::vector <Int_t  >" , &genLep_sourceId);
  BabyTree_->Branch("genLep_isp6status3"  , "std::vector <Bool_t  >" , &genLep_isp6status3  );

  BabyTree_->Branch("ngenTau", &ngenTau, "ngenTau/I" );
  BabyTree_->Branch("genTau_pt"      , "std::vector <Float_t>" , &genTau_pt      );
  BabyTree_->Branch("genTau_eta"     , "std::vector <Float_t>" , &genTau_eta     );
  BabyTree_->Branch("genTau_phi"     , "std::vector <Float_t>" , &genTau_phi     );
  BabyTree_->Branch("genTau_mass"    , "std::vector <Float_t>" , &genTau_mass    );
  BabyTree_->Branch("genTau_pdgId"   , "std::vector <Int_t  >" , &genTau_pdgId   );
  BabyTree_->Branch("genTau_status"  , "std::vector <Int_t  >" , &genTau_status  );
  BabyTree_->Branch("genTau_charge"  , "std::vector <Float_t>" , &genTau_charge  );
  BabyTree_->Branch("genTau_sourceId", "std::vector <Int_t  >" , &genTau_sourceId);

  BabyTree_->Branch("ngenLepFromTau", &ngenLepFromTau, "ngenLepFromTau/I" );
  BabyTree_->Branch("genLepFromTau_pt"      , "std::vector <Float_t>" , &genLepFromTau_pt      );
  BabyTree_->Branch("genLepFromTau_eta"     , "std::vector <Float_t>" , &genLepFromTau_eta     );
  BabyTree_->Branch("genLepFromTau_phi"     , "std::vector <Float_t>" , &genLepFromTau_phi     );
  BabyTree_->Branch("genLepFromTau_mass"    , "std::vector <Float_t>" , &genLepFromTau_mass    );
  BabyTree_->Branch("genLepFromTau_pdgId"   , "std::vector <Int_t  >" , &genLepFromTau_pdgId   );
  BabyTree_->Branch("genLepFromTau_status"  , "std::vector <Int_t  >" , &genLepFromTau_status  );
  BabyTree_->Branch("genLepFromTau_charge"  , "std::vector <Float_t>" , &genLepFromTau_charge  );
  BabyTree_->Branch("genLepFromTau_sourceId", "std::vector <Int_t  >" , &genLepFromTau_sourceId);

  BabyTree_->Branch("njet", &njet, "njet/I" );
  BabyTree_->Branch("jet_p4"          , &jet_p4       );
  BabyTree_->Branch("jets_p4"         , &jets_p4      );
  BabyTree_->Branch("jets_eta30_p4"   , &jets_eta30_p4 );
  BabyTree_->Branch("jet_pt"          , "std::vector <Float_t>" , &jet_pt          );
  BabyTree_->Branch("jet_eta"         , "std::vector <Float_t>" , &jet_eta         );
  BabyTree_->Branch("jet_phi"         , "std::vector <Float_t>" , &jet_phi         );
  BabyTree_->Branch("jet_mass"        , "std::vector <Float_t>" , &jet_mass        );
  BabyTree_->Branch("jet_btagCSV"     , "std::vector <Float_t>" , &jet_btagCSV     );
  BabyTree_->Branch("jet_rawPt"       , "std::vector <Float_t>" , &jet_rawPt       );
  BabyTree_->Branch("jet_mcPt"        , "std::vector <Float_t>" , &jet_mcPt        );
  BabyTree_->Branch("jet_mcFlavour"   , "std::vector <Int_t  >" , &jet_mcFlavour   );
  BabyTree_->Branch("jet_quarkGluonID", "std::vector <Float_t>" , &jet_quarkGluonID);
  BabyTree_->Branch("jet_area"        , "std::vector <Float_t>" , &jet_area        );
  BabyTree_->Branch("jet_id"          , "std::vector <Int_t  >" , &jet_id          );
  BabyTree_->Branch("jet_puId"        , "std::vector <Int_t  >" , &jet_puId        );

  BabyTree_->Branch("met_T1CHS_pt"               , &met_T1CHS_pt               );
  BabyTree_->Branch("met_T1CHS_phi"              , &met_T1CHS_phi              );
  BabyTree_->Branch("met_T1CHS_fromCORE_pt"      , &met_T1CHS_fromCORE_pt      );
  BabyTree_->Branch("met_T1CHS_fromCORE_phi"     , &met_T1CHS_fromCORE_phi     );
  BabyTree_->Branch("met_T1CHSNoHF_pt"           , &met_T1CHSNoHF_pt           );
  BabyTree_->Branch("met_T1CHSNoHF_phi"          , &met_T1CHSNoHF_phi          );
  BabyTree_->Branch("met_rawNoHF_pt"             , &met_rawNoHF_pt             );
  BabyTree_->Branch("met_rawNoHF_phi"            , &met_rawNoHF_phi            );
  BabyTree_->Branch("met_T1CHSNoHF_fromCORE_pt"  , &met_T1CHSNoHF_fromCORE_pt  );
  BabyTree_->Branch("met_T1CHSNoHF_fromCORE_phi" , &met_T1CHSNoHF_fromCORE_phi );

  BabyTree_->Branch("hyp_type", &hyp_type);
  BabyTree_->Branch("evt_type", &evt_type);
 
  return;
}

void babyMaker::InitBabyNtuple () {

  run    = -999;
  lumi   = -999;
  evt    = -1;
  isData = -999;
  evt_passgoodrunlist = 1;
  evt_scale1fb = 0;
  evt_xsec = -999.0;
  evt_kfactor = -999.0;
  evt_filter = -999.0;
  evt_nEvts = 0;
  //evt_id = -1; // don't reset every event
  puWeight = -999.0;
  nVert = -999;
  nTrueInt = -999;
  rho = -999.0;
  rho25 = -999.0;
  nJet40 = -999;
  nBJet40 = -999;
  nBJetTight = -999;
  nBJetMedium = -999;
  nBJetLoose = -999;
  nMuons10 = -999;
  nElectrons10 = -999;
  nGammas20 = -999;

  njets  = -999;
  ht     = -999.0;
  gen_ht = -999.0;
 
  njets_eta30 = -999;
  ht_eta30    = -999.0;

  mt2 = -999.0;
  mt2j = -999.0;
  mt2j_eta30 = -999.0;

  met_pt      = -999.0;
  met_phi     = -999.0;
  met_rawPt   = -999.0;
  met_rawPhi  = -999.0;
  met_caloPt  = -999.0;
  met_caloPhi = -999.0;
  met_genPt   = -999.0;
  met_genPhi  = -999.0;

  sumet_raw = -999.0;
  jzb_raw   = -999.0;
  jzb_T1    = -999.0;
  jgb_raw   = -999.0;
  jgb_T1    = -999.0;

  Flag_EcalDeadCellTriggerPrimitiveFilter = -999;
  Flag_trkPOG_manystripclus53X = -999;
  Flag_ecalLaserCorrFilter = -999;
  Flag_trkPOG_toomanystripclus53X = -999;
  Flag_hcalLaserEventFilter = -999;
  Flag_trkPOG_logErrorTooManyClusters = -999;
  Flag_trkPOGFilters = -999;
  Flag_trackingFailureFilter = -999;
  Flag_CSCTightHaloFilter = -999;
  Flag_HBHENoiseFilter = -999;
  Flag_HBHEIsoNoiseFilter = -999;
  Flag_goodVertices = -999;
  Flag_eeBadScFilter = -999;
  Flag_METFilters = -999;

  HLT_DoubleEl       = -999;   
  HLT_DoubleEl_DZ    = -999;   
  HLT_DoubleEl_noiso = -999;   
  HLT_MuEG           = -999;   
  HLT_MuEG_2         = -999;   
  HLT_DoubleMu       = -999;   
  HLT_DoubleMu_tk    = -999;   
  HLT_DoubleMu_nonDZ    = -999;   

  HLT_Photon22_R9Id90_HE10_IsoM  = -999; 
  HLT_Photon30_R9Id90_HE10_IsoM  = -999; 
  HLT_Photon36_R9Id90_HE10_IsoM  = -999; 
  HLT_Photon50_R9Id90_HE10_IsoM  = -999; 
  HLT_Photon75_R9Id90_HE10_IsoM  = -999; 
  HLT_Photon90_R9Id90_HE10_IsoM  = -999; 
  HLT_Photon120_R9Id90_HE10_IsoM = -999;
  HLT_Photon165_R9Id90_HE10_IsoM = -999;

  dilmass = -999;
  dilpt   = -999;
  dRll    = -999;
 
  matched_neutralemf = -999.0;
  elveto = false;  
 
  hyp_type = -999;
  evt_type = -999;
  
  nlep = -999;
  lep_p4         .clear();   //[nlep]
  lep_pt         .clear();   //[nlep]
  lep_eta        .clear();   //[nlep]
  lep_phi        .clear();   //[nlep]
  lep_mass       .clear();   //[nlep]
  lep_charge     .clear();   //[nlep]
  lep_pdgId      .clear();   //[nlep]
  lep_dxy        .clear();   //[nlep]
  lep_etaSC      .clear();   //[nlep]
  lep_dz         .clear();   //[nlep]
  lep_tightId    .clear();   //[nlep]
  lep_relIso03   .clear();   //[nlep]
  lep_relIso03MREA   .clear();   //[nlep]
  lep_relIso03MRDB   .clear();   //[nlep]
  lep_relIso03MRNC   .clear();   //[nlep]
  lep_relIso04   .clear();   //[nlep]
  lep_mcMatchId  .clear();   //[nlep]
  lep_lostHits   .clear();   //[nlep]
  lep_convVeto   .clear();   //[nlep]
  lep_tightCharge.clear();   //[nlep]
  lep_islead     .clear();   //[nlep]
  lep_istail     .clear();   //[nlep]


  ngamma = -999;
  gamma_p4           .clear();   //[ngamma]
  gamma_pt           .clear();   //[ngamma]
  gamma_eta          .clear();   //[ngamma]
  gamma_phi          .clear();   //[ngamma]
  gamma_mass         .clear();   //[ngamma]
  gamma_mcMatchId    .clear();   //[ngamma]
  gamma_genIso       .clear();   //[ngamma]
  gamma_chHadIso     .clear();   //[ngamma]
  gamma_neuHadIso    .clear();   //[ngamma]
  gamma_phIso        .clear();   //[ngamma]
  gamma_sigmaIetaIeta.clear();   //[ngamma]
  gamma_r9           .clear();   //[ngamma]
  gamma_hOverE       .clear();   //[ngamma]
  gamma_idCutBased   .clear();   //[ngamma]

  ngenPart = -999;
  ngen_p6s3Part = -999;
  genPart_p4         .clear();   //[ngenPart]
  genPart_pt         .clear();   //[ngenPart]
  genPart_eta        .clear();   //[ngenPart]
  genPart_phi        .clear();   //[ngenPart]
  genPart_mass       .clear();   //[ngenPart]
  genPart_pdgId      .clear();   //[ngenPart]
  genPart_isp6status3.clear();   //[ngenPart]
  genPart_status     .clear();   //[ngenPart]
  genPart_charge     .clear();   //[ngenPart]
  genPart_motherId   .clear();   //[ngenPart]
  genPart_grandmaId  .clear();   //[ngenPart]

  ngenLep = -999;
  ngen_p6s3Lep = -999;
  genLep_pt         .clear();   //[ngenLep]
  genLep_eta        .clear();   //[ngenLep]
  genLep_phi        .clear();   //[ngenLep]
  genLep_mass       .clear();   //[ngenLep]
  genLep_pdgId      .clear();   //[ngenLep]
  genLep_status     .clear();   //[ngenLep]
  genLep_isp6status3.clear();   //[ngenLep]
  genLep_charge     .clear();   //[ngenLep]
  genLep_sourceId   .clear();   //[ngenLep]

  ngenTau = -999;
  genTau_pt      .clear();   //[ngenTau]
  genTau_eta     .clear();   //[ngenTau]
  genTau_phi     .clear();   //[ngenTau]
  genTau_mass    .clear();   //[ngenTau]
  genTau_pdgId   .clear();   //[ngenTau]
  genTau_status  .clear();   //[ngenTau]
  genTau_charge  .clear();   //[ngenTau]
  genTau_sourceId.clear();   //[ngenTau]

  ngenLepFromTau = -999;
  genLepFromTau_pt      .clear();   //[ngenLepFromTau]
  genLepFromTau_eta     .clear();   //[ngenLepFromTau]
  genLepFromTau_phi     .clear();   //[ngenLepFromTau]
  genLepFromTau_mass    .clear();   //[ngenLepFromTau]
  genLepFromTau_pdgId   .clear();   //[ngenLepFromTau]
  genLepFromTau_status  .clear();   //[ngenLepFromTau]
  genLepFromTau_charge  .clear();   //[ngenLepFromTau]
  genLepFromTau_sourceId.clear();   //[ngenLepFromTau]
  
  njet = -999;
  jet_p4          .clear();   //[njet]
  jets_p4         .clear();   //[njet]
  jets_eta30_p4   .clear();   //[njet]
  jet_pt          .clear();   //[njet]
  jet_eta         .clear();   //[njet]
  jet_phi         .clear();   //[njet]
  jet_mass        .clear();   //[njet]
  jet_btagCSV     .clear();   //[njet]
  jet_rawPt       .clear();   //[njet]
  jet_mcPt        .clear();   //[njet]
  jet_mcFlavour   .clear();   //[njet]
  jet_quarkGluonID.clear();   //[njet]
  jet_area        .clear();   //[njet]
  jet_id          .clear();   //[njet]
  jet_puId        .clear();   //[njet]

  //----- pfMETs
  met_T1CHS_pt               = -999;
  met_T1CHS_phi              = -999;
  met_T1CHS_fromCORE_pt      = -999;
  met_T1CHS_fromCORE_phi     = -999;
  met_T1CHSNoHF_pt           = -999;
  met_T1CHSNoHF_phi          = -999;
  met_rawNoHF_pt           = -999;
  met_rawNoHF_phi          = -999;
  met_T1CHSNoHF_fromCORE_pt  = -999;
  met_T1CHSNoHF_fromCORE_phi = -999;
  
  return;
}

void babyMaker::FillBabyNtuple(){
  BabyTree_->Fill();
  return;
}

void babyMaker::CloseBabyNtuple(){
  BabyFile_->cd();
  BabyTree_->Write();
  BabyFile_->Close();
  return;
}
