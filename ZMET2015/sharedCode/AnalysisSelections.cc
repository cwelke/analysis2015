#include <stdexcept>
#include <iostream>
#include <map>

#include "TH1.h"
#include "TMath.h"
#include "TH1F.h"
#include "TFile.h"
#include "TCollection.h"
#include "TDirectory.h"
#include "TKey.h"

#include "AnalysisSelections.h"
#include "histTools.h"
#include "ZMET.h"

using namespace std;

bool passBaselineSelections()
{
  if( zmet.njets()                       < 2         ) return false; // >=2 jets  
  // if( zmet.ht()                          < 240       ) return false; // >=240 GeV HT  
  return true;
}

bool passMETFilters()
{

  if( zmet.isData()                   ){
	if (zmet.nVert() == 0               ) return false;
	// MET filters (data and MC)	   
	if (!zmet.Flag_goodVertices()       ) return false;
	if (!zmet.Flag_CSCTightHaloFilter() ) return false;
	if (!zmet.Flag_eeBadScFilter()      ) return false;
	if (!zmet.Flag_HBHENoiseFilter()    ) return false;
  }
  return true;
}

bool passSignalRegionSelection( string selection )
{

  try
	{
  if( TString(selection).Contains("SRA"            ) && !((zmet.njets() == 2 ||
														   zmet.njets() == 3  ) &&
														  (zmet.ht()    > 400 )) ) return false; //high HT region
  if( TString(selection).Contains("SRB"            ) && zmet.njets() < 4         ) return false; //large njets
  if( TString(selection).Contains("bveto"          ) && zmet.nBJetMedium() > 0   ) return false; //bveto
  if( TString(selection).Contains("withb"          ) && zmet.nBJetMedium() < 1   ) return false; //at least 1 b-tag
  if( TString(selection).Contains("with2"          ) && zmet.nBJetMedium() < 2   ) return false; //at least 1 b-tag
  if( TString(selection).Contains("twojets"        ) && zmet.njets() > 2         ) return false; //exactly 2 jets
  if( TString(selection).Contains("2jets_inclusive") && zmet.njets() < 2         ) return false; //at least 2 jets
  if( TString(selection).Contains("3jets_inclusive") && zmet.njets() < 3         ) return false; //at least 3 jets
  if( TString(selection).Contains("SR_ATLAS"       ) && 
	  !( ( ( zmet.evt_type() == 0 && ( zmet.ht() + zmet.lep_pt().at(0) + zmet.lep_pt().at(1) ) > 600 ) ||
		   ( zmet.evt_type() == 2 && ( zmet.ht() + zmet.gamma_pt().at(0)                     ) > 600 ) ) &&
		 ( zmet.njets() > 1       && ( ( acos( cos( zmet.met_T1CHS_fromCORE_pt() - zmet.jets_p4().at(0).phi() ) ) > 0.4  ) &&
									   ( acos( cos( zmet.met_T1CHS_fromCORE_pt() - zmet.jets_p4().at(1).phi() ) ) > 0.4  ) ) ) )
	  )return false; //ATLAS run I SR
  if( TString(selection).Contains("forward"        ) && !((zmet.evt_type() == 0 &&
														   ((abs(zmet.lep_eta().at(0)) < 1.4 && abs(zmet.lep_eta().at(1)) > 1.6) ||
															(abs(zmet.lep_eta().at(1)) < 1.4 && abs(zmet.lep_eta().at(0)) > 1.6) ||
															(abs(zmet.lep_eta().at(0)) > 1.6 && abs(zmet.lep_eta().at(1)) > 1.6) ) ) ||
														  (zmet.evt_type() == 2 ) ) ) return false; //edge forward
  if( TString(selection).Contains("central"        ) && !((zmet.evt_type() == 0 &&
														   (abs(zmet.lep_eta().at(0)) < 1.4 && abs(zmet.lep_eta().at(1)) < 1.4  ) ) ||
														  (zmet.evt_type() == 2 ) ) ) return false; //edge central  														 

  if( TString(selection).Contains("CR3lep"       ) && !(zmet.evt_type() != 2 &&
														( zmet.nlep() == 3 &&
														  zmet.lep_pt().at(0) > 20 &&
														  zmet.lep_pt().at(1) > 20 &&
														  zmet.lep_pt().at(2) > 20 &&
														  zmet.nBJetMedium() == 0 &&
														  // zmet.met_pt() > 50 &&
														  (((zmet.lep_pdgId().at(0)*zmet.lep_pdgId().at(1) == -121 ||
															 zmet.lep_pdgId().at(0)*zmet.lep_pdgId().at(1) == -169) &&
															(zmet.lep_p4().at(0)+zmet.lep_p4().at(1)).mass() > 81 &&
															(zmet.lep_p4().at(0)+zmet.lep_p4().at(1)).mass() < 101 ) ||

														   ((zmet.lep_pdgId().at(0)*zmet.lep_pdgId().at(2) == -121 ||
															 zmet.lep_pdgId().at(0)*zmet.lep_pdgId().at(2) == -169) &&
															(zmet.lep_p4().at(0)+zmet.lep_p4().at(2)).mass() > 81 &&
															(zmet.lep_p4().at(0)+zmet.lep_p4().at(2)).mass() < 101 ) ||

														   ((zmet.lep_pdgId().at(1)*zmet.lep_pdgId().at(2) == -121 ||
															 zmet.lep_pdgId().at(1)*zmet.lep_pdgId().at(2) == -169) &&
															(zmet.lep_p4().at(1)+zmet.lep_p4().at(2)).mass() > 81 &&
															(zmet.lep_p4().at(1)+zmet.lep_p4().at(2)).mass() < 101 ) 
														   ))))return false;

  if( TString(selection).Contains("CR4lep"       ) && !(zmet.evt_type() != 2 &&
														( zmet.nlep() == 4 &&
														  zmet.lep_pt().at(0) > 20 &&
														  zmet.lep_pt().at(1) > 20 &&
														  zmet.lep_pt().at(2) > 20 &&
														  zmet.lep_pt().at(3) > 20 &&
														  // zmet.met_pt() > 50 &&
														  (((zmet.lep_pdgId().at(0)*zmet.lep_pdgId().at(1) == -121 ||
															 zmet.lep_pdgId().at(0)*zmet.lep_pdgId().at(1) == -169) &&
															(zmet.lep_p4().at(0)+zmet.lep_p4().at(1)).mass() > 81 &&
															(zmet.lep_p4().at(0)+zmet.lep_p4().at(1)).mass() < 101 ) ||

														   ((zmet.lep_pdgId().at(0)*zmet.lep_pdgId().at(2) == -121 ||
															 zmet.lep_pdgId().at(0)*zmet.lep_pdgId().at(2) == -169) &&
															(zmet.lep_p4().at(0)+zmet.lep_p4().at(2)).mass() > 81 &&
															(zmet.lep_p4().at(0)+zmet.lep_p4().at(2)).mass() < 101 ) ||

														   ((zmet.lep_pdgId().at(0)*zmet.lep_pdgId().at(3) == -121 ||
															 zmet.lep_pdgId().at(0)*zmet.lep_pdgId().at(3) == -169) &&
															(zmet.lep_p4().at(0)+zmet.lep_p4().at(3)).mass() > 81 &&
															(zmet.lep_p4().at(0)+zmet.lep_p4().at(3)).mass() < 101 ) ||

														   ((zmet.lep_pdgId().at(1)*zmet.lep_pdgId().at(2) == -121 ||
															 zmet.lep_pdgId().at(1)*zmet.lep_pdgId().at(2) == -169) &&
															(zmet.lep_p4().at(1)+zmet.lep_p4().at(2)).mass() > 81 &&
															(zmet.lep_p4().at(1)+zmet.lep_p4().at(2)).mass() < 101 ) ||

														   ((zmet.lep_pdgId().at(1)*zmet.lep_pdgId().at(3) == -121 ||
															 zmet.lep_pdgId().at(1)*zmet.lep_pdgId().at(3) == -169) &&
															(zmet.lep_p4().at(1)+zmet.lep_p4().at(3)).mass() > 81 &&
															(zmet.lep_p4().at(1)+zmet.lep_p4().at(3)).mass() < 101 ) ||

														   ((zmet.lep_pdgId().at(2)*zmet.lep_pdgId().at(3) == -121 ||
															 zmet.lep_pdgId().at(2)*zmet.lep_pdgId().at(3) == -169) &&
															(zmet.lep_p4().at(2)+zmet.lep_p4().at(3)).mass() > 81 &&
															(zmet.lep_p4().at(2)+zmet.lep_p4().at(3)).mass() < 101 )
														   ))))return false;

	}
  catch (exception &e)
	{
	  cout<<"failed"<<endl;
	}
  
  return true;
}

bool eventHas2GoodLeps()
{
  if( zmet.nlep()                        < 2         ) return false; // require at least 2 good leptons
  if( zmet.lep_pt().at(0)                < 20        ) return false; // leading lep pT > 25 GeV
  if( zmet.lep_pt().at(1)                < 20        ) return false; // tailing lep pT > 20 GeV
  if( abs(zmet.lep_p4().at(0).eta())     > 2.4       ) return false; // eta < 2.4
  if( abs(zmet.lep_p4().at(1).eta())     > 2.4       ) return false; // eta < 2.4
  if( abs(zmet.lep_p4().at(0).eta())     > 1.4 &&
	  abs(zmet.lep_p4().at(0).eta())     < 1.6       ) return false;
  if( abs(zmet.lep_p4().at(1).eta())     > 1.4 &&
	  abs(zmet.lep_p4().at(1).eta())     < 1.6       ) return false; // veto xition region
  if( zmet.dRll()                        < 0.1       ) return false;
  if( !(zmet.hyp_type() == 0 ||					     
		zmet.hyp_type() == 1 ||					     
		zmet.hyp_type() == 2 )                       ) return false; // require explicit dilepton event
  if( !(zmet.evt_type() == 0 )                       ) return false; // require opposite sign
  if( !(zmet.dilmass() > 81 && zmet.dilmass() < 101) ) return false; // on-Z
  if( !(zmet.dilpt() > 50)                           ) return false; // Z pT > 50 GeV
  return true;
}

bool eventHas3Jets()
{
  if( zmet.njets()                       < 3         ) return false; // require at least 3 jets
  return true;
}

bool eventHasGoodPhoton()
{
  if( zmet.ngamma()                      <  1    ) return false; // require at least 1 good photon
  if( zmet.evt_type()                    != 2    ) return false; // photon + jets events
  if( zmet.gamma_pt().at(0)              < 22    ) return false; // photon pt > 22 GeV
  if( abs(zmet.gamma_p4().at(0).eta())   > 1.4 &&
  	  abs(zmet.gamma_p4().at(0).eta())   < 1.6   ) return false; // veto xition region
  if( abs(zmet.gamma_p4().at(0).eta())   > 2.4   ) return false; // photon in EC or EB
  if( zmet.gamma_hOverE().at(0)          > 0.1   ) return false; // H/E < 0.1	  
  // if( zmet.matched_neutralemf()          < 0.7   ) return false; // jet neutral EM fraction cut
  if( zmet.matched_neutralemf()          < 0.9   ) return false; // jet neutral EM fraction cut
  if( acos( cos( zmet.gamma_phi().at(0)			 
				 - zmet.met_phi() ) )    < 0.14  ) return false; // kill photons aligned with MET
  if( zmet.elveto()                              ) return false; // veto pixel match
  return true;  
}

bool passPhotonTrigger()
{
  if(      passPhotonTrigger22()  ) return true;
  else if( passPhotonTrigger30()  ) return true;
  else if( passPhotonTrigger36()  ) return true;
  else if( passPhotonTrigger50()  ) return true;
  else if( passPhotonTrigger75()  ) return true;
  else if( passPhotonTrigger90()  ) return true;
  else if( passPhotonTrigger120() ) return true;
  else if( passPhotonTrigger165() ) return true;
  return false;
}

bool passPhotonTrigger22()
{
  // if( zmet.HLT_Photon22_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 25   && zmet.gamma_pt().at(0) < 35  ) return true;
  if( zmet.HLT_Photon22_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) < 33  ) return true;
  return false;
}

bool passPhotonTrigger30()
{
  // if( zmet.HLT_Photon30_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 35  && zmet.gamma_pt().at(0) < 40  ) return true;
  if( zmet.HLT_Photon30_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 33 ) return true;
  return false;
}

bool passPhotonTrigger36()
{
  // if( zmet.HLT_Photon36_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 40  && zmet.gamma_pt().at(0) < 60  ) return true;
  if( zmet.HLT_Photon36_R9Id90_HE10_IsoM()  > 0 ) return true;
  return false;
}

bool passPhotonTrigger50()
{
  // if( zmet.HLT_Photon50_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 60  && zmet.gamma_pt().at(0) < 80  ) return true;
  if( zmet.HLT_Photon50_R9Id90_HE10_IsoM()  > 0 ) return true;
  return false;
}

bool passPhotonTrigger75()
{
  // if( zmet.HLT_Photon75_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 80  && zmet.gamma_pt().at(0) < 100 ) return true;
  if( zmet.HLT_Photon75_R9Id90_HE10_IsoM()  > 0 ) return true;
  return false;
}

bool passPhotonTrigger90()
{
  // if( zmet.HLT_Photon90_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 100 && zmet.gamma_pt().at(0) < 125 ) return true;
  if( zmet.HLT_Photon90_R9Id90_HE10_IsoM()  > 0 ) return true;
  return false;
}

bool passPhotonTrigger120()
{
  // if( zmet.HLT_Photon120_R9Id90_HE10_IsoM() > 0 && zmet.gamma_pt().at(0) > 125 && zmet.gamma_pt().at(0) < 170 ) return true;
  if( zmet.HLT_Photon120_R9Id90_HE10_IsoM() > 0 ) return true;
  return false;
}

bool passPhotonTrigger165()
{
  // if( zmet.HLT_Photon165_R9Id90_HE10_IsoM() > 0 && zmet.gamma_pt().at(0) > 170                                ) return true;
  if( zmet.HLT_Photon165_R9Id90_HE10_IsoM() > 0 ) return true;
  return false;
}

int getPrescale()
{
  if( !( zmet.HLT_Photon22_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon30_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon36_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon50_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon75_R9Id90_HE10_IsoM()  > 0 || 
		 zmet.HLT_Photon90_R9Id90_HE10_IsoM()  > 0 || 
		 zmet.HLT_Photon120_R9Id90_HE10_IsoM() > 0 ||
		 zmet.HLT_Photon165_R9Id90_HE10_IsoM() > 0 
		 ) ) return 0;
  if(      passPhotonTrigger22()  ) return zmet.HLT_Photon22_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger30()  ) return zmet.HLT_Photon30_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger36()  ) return zmet.HLT_Photon36_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger50()  ) return zmet.HLT_Photon50_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger75()  ) return zmet.HLT_Photon75_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger90()  ) return zmet.HLT_Photon90_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger120() ) return zmet.HLT_Photon120_R9Id90_HE10_IsoM();
  else if( passPhotonTrigger165() ) return zmet.HLT_Photon165_R9Id90_HE10_IsoM();
  return -1; // should not get here
}

int getPrescaleNoBins()
{
  if( !( zmet.HLT_Photon22_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon30_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon36_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon50_R9Id90_HE10_IsoM()  > 0 ||
		 zmet.HLT_Photon75_R9Id90_HE10_IsoM()  > 0 || 
		 zmet.HLT_Photon90_R9Id90_HE10_IsoM()  > 0 || 
		 zmet.HLT_Photon120_R9Id90_HE10_IsoM() > 0 ||
		 zmet.HLT_Photon165_R9Id90_HE10_IsoM() > 0 
		 ) ) return 0;
  if(      zmet.HLT_Photon165_R9Id90_HE10_IsoM() > 0 ) return zmet.HLT_Photon165_R9Id90_HE10_IsoM();
  else if( zmet.HLT_Photon120_R9Id90_HE10_IsoM() > 0 ) return zmet.HLT_Photon120_R9Id90_HE10_IsoM();
  else if( zmet.HLT_Photon90_R9Id90_HE10_IsoM()  > 0 ) return zmet.HLT_Photon90_R9Id90_HE10_IsoM();
  else if( zmet.HLT_Photon75_R9Id90_HE10_IsoM()  > 0 ) return zmet.HLT_Photon75_R9Id90_HE10_IsoM();
  else if( zmet.HLT_Photon50_R9Id90_HE10_IsoM()  > 0 ) return zmet.HLT_Photon50_R9Id90_HE10_IsoM();
  else if( zmet.HLT_Photon36_R9Id90_HE10_IsoM()  > 0 ) return zmet.HLT_Photon36_R9Id90_HE10_IsoM();
  else if( zmet.HLT_Photon30_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) > 33 ) return zmet.HLT_Photon30_R9Id90_HE10_IsoM();
  else if( zmet.HLT_Photon22_R9Id90_HE10_IsoM()  > 0 && zmet.gamma_pt().at(0) < 33 ) return zmet.HLT_Photon22_R9Id90_HE10_IsoM();
  // else if( zmet.HLT_Photon22_R9Id90_HE10_IsoM()  > 0 ) return 0;
  return -1; // should not get here
}

bool highHT_zjinc( string samplename )
{
  if( TString(samplename).Contains("m50inc") ){
	if( zmet.gen_ht() > 100 ) return true;
  }
  return false;
}

