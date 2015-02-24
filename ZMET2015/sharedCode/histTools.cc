#include <iostream>

#include "TH1.h"
#include "TFile.h"
#include "TList.h"
#include "TIterator.h"
#include "TRegexp.h"
#include "TObject.h"

using namespace std;

void fillUnderOverFlow(TH1F * &h1, float value, float weight){
  float min = h1->GetXaxis()->GetXmin();
  float max = h1->GetXaxis()->GetXmax();
  if (value > max) value = h1->GetBinCenter(h1->GetNbinsX());
  if (value < min) value = h1->GetBinCenter(1);
  h1->Fill(value, weight);
}

void fillUnderOverFlow(TH1D * &h1, double value, float weight){
  double min = h1->GetXaxis()->GetXmin();
  double max = h1->GetXaxis()->GetXmax();
  if (value > max) value = h1->GetBinCenter(h1->GetNbinsX());
  if (value < min) value = h1->GetBinCenter(1);
  h1->Fill(value, weight);
}

void saveHist(const string filename, const string pat)
{
   TList* list = gDirectory->GetList() ;
   TIterator* iter = list->MakeIterator();
   TRegexp re(pat.c_str(),kTRUE) ;
   TObject *obj;
   TFile outf(filename.c_str(),"RECREATE") ;
   while((obj=iter->Next())) {
      if (TString(obj->GetName()).Index(re)>=0) {
         obj->Write() ;
         cout << "." ;
         cout.flush() ;
      }
   }
   cout << endl ;
   outf.Close() ;
   delete iter ;
}

