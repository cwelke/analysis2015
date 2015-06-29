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
  return true;
}

bool passSignalRegionSelection( string selection )
{
  if( TString(selection).Contains("bveto"          ) && zmet.nBJetMedium() > 0   ) return false; //bveto
  if( TString(selection).Contains("withb"          ) && zmet.nBJetMedium() < 1   ) return false; //at least 1 b-tag
  if( TString(selection).Contains("SRA"            ) && !((zmet.njets() == 2 ||
														   zmet.njets() == 3  ) &&
														  (zmet.ht()    > 600 )) ) return false; //high HT region
  if( TString(selection).Contains("SRB"            ) && zmet.njets() < 4         ) return false; //large njets
  if( TString(selection).Contains("twojets"        ) && zmet.njets() > 2         ) return false; //exactly 2 jets
  if( TString(selection).Contains("2jets_inclusive") && zmet.njets() < 2         ) return false; //at least 2 jets
  if( TString(selection).Contains("3jets_inclusive") && zmet.njets() < 3         ) return false; //at least 3 jets

  return true;
}

bool eventHas2GoodLeps()
{
  if( zmet.nlep()                        < 2         ) return false; // require at least 2 good leptons
  if( zmet.lep_pt().at(0)                < 25        ) return false; // leading lep pT > 25 GeV
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
  if( !(zmet.dilmass() > 81 && zmet.dilmass() < 101) ) return false; // HT > 100
  return true;
}

bool eventHasGoodPhoton()
{
  
  return;
}
