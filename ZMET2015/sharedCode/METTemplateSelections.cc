#include <stdexcept>
#include <iostream>
#include <map>

#include "TH1.h"
#include "TH1F.h"
#include "TFile.h"
#include "TCollection.h"
#include "TDirectory.h"
#include "TKey.h"

#include "METTemplateSelections.h"
#include "histTools.h"

using namespace std;

METTemplates::METTemplates()
{
  photon_ptcuts.clear();
  photon_njetcuts.clear();
  photon_htcuts.clear();
}

METTemplates::~METTemplates()
{
  photon_ptcuts.clear();
  photon_njetcuts.clear();
  photon_htcuts.clear();
}

void METTemplates::bookMETHists( std::map<std::string, TH1F*> &methists )
{

  size_t njetcuts = photon_njetcuts.size();  
  size_t nhtcuts  = photon_htcuts  .size();  
  size_t nptcuts  = photon_ptcuts  .size();  
  std::string histname = "";
  std::string histtitle = "";
  for(  size_t njets_ind = 0; njets_ind < njetcuts; njets_ind++ ){
	for(   size_t ht_ind = 0;    ht_ind <  nhtcuts;    ht_ind++ ){
	  for( size_t pt_ind = 0;    pt_ind <  nptcuts;    pt_ind++ ){
		histname = Form("h_template_njetsind_%i_htind_%i_ptind_%i"
						, static_cast<int>(njets_ind)
						, static_cast<int>(ht_ind)
						, static_cast<int>(pt_ind) );
		histtitle = Form("h_template_njets%i_ht%i_pt%i"
						 , static_cast<int>(photon_njetcuts.at(njets_ind))
						 , static_cast<int>(photon_htcuts.at(ht_ind))
						 , static_cast<int>(photon_ptcuts.at(pt_ind)) );
		std::cout<<Form("Booking hist: %s", histname.c_str())<<std::endl;
		methists.insert ( pair<std::string,TH1F*>(histname, new TH1F(histname.c_str(), histtitle.c_str(), 500.0, 0, 500.0)));
		methists.at(histname)->Sumw2();	  
	  }
	}
  }

  // need to add these to the photon looper to make them decoupled from the templates class
		// methists.insert ( pair<std::string,TH1F*>("photon_pt", new TH1F("photon_pt", "", 1000.0, 0, 1000.0)));
		// methists.at("photon_pt")->Sumw2();	  
		// methists.insert ( pair<std::string,TH1F*>("ht", new TH1F("ht", "", 1000.0, 0, 1000.0)));
		// methists.at("ht")->Sumw2();	  
		// methists.insert ( pair<std::string,TH1F*>("met", new TH1F("met", "", 400.0, 0, 400.0)));
		// methists.at("met")->Sumw2();	  

		// methists.insert ( pair<std::string,TH1F*>("photon_pt_ht100", new TH1F("photon_pt_ht100", "", 1000.0, 0, 1000.0)));
		// methists.insert ( pair<std::string,TH1F*>("photon_pt_ht200", new TH1F("photon_pt_ht200", "", 1000.0, 0, 1000.0)));
		// methists.insert ( pair<std::string,TH1F*>("photon_pt_ht400", new TH1F("photon_pt_ht400", "", 1000.0, 0, 1000.0)));
		// methists.insert ( pair<std::string,TH1F*>("photon_pt_ht600", new TH1F("photon_pt_ht600", "", 1000.0, 0, 1000.0)));
		// methists.at("photon_pt_ht100")->Sumw2();	  
		// methists.at("photon_pt_ht200")->Sumw2();	  
		// methists.at("photon_pt_ht400")->Sumw2();	  
		// methists.at("photon_pt_ht600")->Sumw2();	  

		// methists.insert ( pair<std::string,TH1F*>("ht_ht100", new TH1F("ht_ht100", "", 1000.0, 0, 1000.0)));
		// methists.insert ( pair<std::string,TH1F*>("ht_ht200", new TH1F("ht_ht200", "", 1000.0, 0, 1000.0)));
		// methists.insert ( pair<std::string,TH1F*>("ht_ht400", new TH1F("ht_ht400", "", 1000.0, 0, 1000.0)));
		// methists.insert ( pair<std::string,TH1F*>("ht_ht600", new TH1F("ht_ht600", "", 1000.0, 0, 1000.0)));
		// methists.at("ht_ht100")->Sumw2();	  
		// methists.at("ht_ht200")->Sumw2();	  
		// methists.at("ht_ht400")->Sumw2();	  
		// methists.at("ht_ht600")->Sumw2();	  

		// methists.insert ( pair<std::string,TH1F*>("met_ht100", new TH1F("met_ht100", "", 400.0, 0, 400.0)));
		// methists.insert ( pair<std::string,TH1F*>("met_ht200", new TH1F("met_ht200", "", 400.0, 0, 400.0)));
		// methists.insert ( pair<std::string,TH1F*>("met_ht400", new TH1F("met_ht400", "", 400.0, 0, 400.0)));
		// methists.insert ( pair<std::string,TH1F*>("met_ht600", new TH1F("met_ht600", "", 400.0, 0, 400.0)));
		// methists.at("met_ht100")->Sumw2();	  
		// methists.at("met_ht200")->Sumw2();	  
		// methists.at("met_ht400")->Sumw2();	  
		// methists.at("met_ht600")->Sumw2();	  

}

void METTemplates::setBins()
{

  //set photon pT cuts
  photon_ptcuts.push_back(22);
  photon_ptcuts.push_back(30);
  photon_ptcuts.push_back(36);
  photon_ptcuts.push_back(50);
  photon_ptcuts.push_back(75);
  photon_ptcuts.push_back(90);
  photon_ptcuts.push_back(120);
  photon_ptcuts.push_back(165);
  photon_ptcuts.push_back(200);
  photon_ptcuts.push_back(250);

  //set photon njets cuts
  photon_njetcuts.push_back(2);
  photon_njetcuts.push_back(3);

  //set event HT cuts
  photon_htcuts.push_back(40);
  photon_htcuts.push_back(80);
  photon_htcuts.push_back(120);
  photon_htcuts.push_back(160);
  photon_htcuts.push_back(200);
  photon_htcuts.push_back(240);
  photon_htcuts.push_back(280);
  photon_htcuts.push_back(320);
  photon_htcuts.push_back(360);
  photon_htcuts.push_back(400);

}

int METTemplates::getNjetsBin( const int &njets )
{

  size_t ncuts = photon_njetcuts.size();  
  for( size_t njets_ind = 0; njets_ind < ncuts; njets_ind++ ){
	if( njets < photon_njetcuts.at(0) )
	  {
		std::cout<<Form("Number of jets less than %i. ", photon_njetcuts.at(0)) <<std::endl;
		return -999;
	  }
	else if( njets_ind+1 < ncuts ){
	  if     ( njets == photon_njetcuts.at(njets_ind) ){ return njets_ind; }
	}
	else if( njets_ind+1 == ncuts ){
	  if     ( njets >= photon_njetcuts.at(njets_ind) ){ return njets_ind; }
	}
  }
  std::cout<<"WARNING: Did not find good Njets Bin. " <<std::endl;
  std::cout<<"NJets: "<<njets<<std::endl;
  return -9999;
}

int METTemplates::getHTBin( const float &HT )
{
  size_t ncuts = photon_htcuts.size();  
  for( size_t ht_ind = 0; ht_ind < ncuts; ht_ind++ ){
	if( HT < photon_htcuts.at(0) )
	  {
		std::cout<<Form("HT less than %f. ", static_cast<double>(photon_htcuts.at(0))) <<std::endl;
		return -999;
	  }
	else if( ht_ind+1 < ncuts ){
	  if     ( HT >= photon_htcuts.at(ht_ind) && HT < photon_htcuts.at(ht_ind+1) ){ return ht_ind;}
	}else if( ht_ind+1 == ncuts ){
	  if     ( HT >= photon_htcuts.at(ht_ind) ){ return ht_ind;}
	}
  }
  std::cout<<"WARNING: Did not find good HT Bin. " <<std::endl;
  std::cout<<"HT: "<<HT<<std::endl;
  return -9999;
}

int METTemplates::getpTBin( const float &pT )
{
  size_t ncuts = photon_ptcuts.size();  
  for( size_t pt_ind = 0; pt_ind < ncuts; pt_ind++ ){
	if( pT < photon_ptcuts.at(0) )
	  {
		// std::cout<<Form("pT less than %f. ", static_cast<double>(photon_ptcuts.at(0))) <<std::endl;
		// return -999;
		return 0;
	  }
	else if( pt_ind+1 < ncuts ){
	  if     ( pT >= photon_ptcuts.at(pt_ind) && pT < photon_ptcuts.at(pt_ind+1) ){ return pt_ind;}
	}else if( pt_ind+1 == ncuts ){
	  if     ( pT >= photon_ptcuts.at(pt_ind) ){ return pt_ind;}
	}
  }
  std::cout<<"WARNING: Did not find good pT Bin. " <<std::endl;
  std::cout<<"pT: "<<pT<<std::endl;
  return -9999;
}

void METTemplates::FillTemplate( std::map<std::string, TH1F*> &methists, int njets, float ht, float pt, float met, float weight )
{
  std::string histname = Form("h_template_njetsind_%i_htind_%i_ptind_%i"
							  , static_cast<int>(getNjetsBin(njets))
							  , static_cast<int>(getHTBin(ht))
							  , static_cast<int>(getpTBin(pt)) );
  try
	{
	  fillUnderOverFlow(methists.at(histname.c_str()), met, weight);
	}
  catch ( exception &e )
	{
	  std::cout<<Form("Cannot find hist: %s", histname.c_str() )<<std::endl<<"Exiting."<<std::endl;
	  // exit(1);
	}  
}

void METTemplates::NormalizeTemplates( std::map<std::string, TH1F*> &methists )
{
  for (std::map<std::string, TH1F*>::iterator itr = methists.begin(); itr != methists.end(); itr++){
	if( itr->second->GetEntries() > 0 ){
	  itr->second->Scale(1.0/itr->second->GetSumOfWeights());
	}
  }
}

//How to use following functions:
  // cout << "Retrieving templates " << endl;
  // std::map<std::string, TH1F*> dummy;  
  // mettemplates.loadTemplatesFromFile( outputfilename, dummy);

  // double normalization = dummy.at("h_template_njetsind_1_htind_6_ptind_7")->GetEntries();
  // cout << "Nentries 1 " << normalization << endl;


  // cout << "Retrieving Hist for 3, 350, 175 " << endl;
  // TH1F * mettemplate = mettemplates.pickTemplate( dummy, 3, 350, 175 );
  // normalization = mettemplate->GetEntries();
  // cout << "Nentries 2 " << normalization << endl;

void METTemplates::loadTemplatesFromFile( const std::string filename, std::map<std::string, TH1F*> &methists )
{
  TFile *infile = new TFile(filename.c_str());
  std::cout<<"Reading hists from file: "<<filename<<std::endl;
  infile->cd();
  TIter iKey(infile->GetListOfKeys());
  TKey* key=0;
  while((key=(TKey*)iKey())) {
	TH1* hist=(TH1*)key->ReadObjectAny(TH1::Class());
	std::string histname = hist->GetName();
	std::cout<<"Name:  "<<TString(hist->GetName())<<std::endl;
	methists.insert ( pair<std::string,TH1F*>(histname, (TH1F*)hist));	
	// std::string histtitle = TString(hist->GetTitle())
	// std::cout<<"Title: "<<TString(hist->GetTitle())<<std::endl;
  }
  return;
}

TH1F* METTemplates::pickTemplate( std::map<std::string, TH1F*> &methists, int njets, float ht, float pt )
{
  std::string histname = Form("h_template_njetsind_%i_htind_%i_ptind_%i"
							  , static_cast<int>(getNjetsBin(njets))
							  , static_cast<int>(getHTBin(ht))
							  , static_cast<int>(getpTBin(pt)) );
  try
	{
	  return methists.at(histname.c_str());
	}
  catch ( exception &e )
	{
	  std::cout<<Form("Cannot find hist: %s", histname.c_str() )<<std::endl<<"Exiting."<<std::endl;
	  // exit(1);
	}  
  return NULL;
}

void METTemplates::normalizeTemplate( TH1F * &current_template )
{
  current_template->Scale(1.0/current_template->GetSumOfWeights());
  return;
}
