#include <stdexcept>
#include <iostream>
#include <map>

#include "TH1F.h"

#ifndef METTEMPLATESELECTIONS_H
#define METTEMPLATESELECTIONS_H

class METTemplates
{

public:
  METTemplates();
  ~METTemplates();

  void bookMETHists( std::map<std::string, TH1F*> &methists );
  void setBins();
  int getNjetsBin( const int &njets );
  int getHTBin( const float &HT );
  int getpTBin( const float &pT );

  void FillTemplate( std::map<std::string, TH1F*> &methists, int njets, float ht, float pt, float met, float weight );
  void NormalizeTemplates( std::map<std::string, TH1F*> &methists );
  void loadTemplatesFromFile( const std::string filename, std::map<std::string, TH1F*> &methists );
  TH1F* pickTemplate( std::map<std::string, TH1F*> &methists, int njets, float ht, float pt );
  void normalizeTemplate( TH1F * &current_template );

  
private:
  std::vector <int> photon_ptcuts;
  std::vector <int> photon_njetcuts;
  std::vector <int> photon_htcuts;
  
};

#endif
