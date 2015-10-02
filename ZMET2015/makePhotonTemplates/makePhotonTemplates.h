#ifndef makePhotonTemplates_h
#define makePhotonTemplates_h

#include "TChain.h"
#include "TH1F.h"

class TChain;

class makePhotonTemplates
{
public:

  makePhotonTemplates();
  makePhotonTemplates( bool htreweighting );
  ~makePhotonTemplates();
  void ScanChain (TChain * chain,const std::string iter,const std::string sample, const std::string selection);
  void bookHistos();
  void bookHist( std::string name, std::string title, int nbins, float xmin, float xmax );
  void fillHist( std::string obj, std::string var, std::string sel, float value, float weight );

  bool dohtreweighting;

private:

  std::map<std::string, TH1F*> mettemplate_hists;
  std::map<std::string, TH1F*> event_hists;
  
};
#endif
