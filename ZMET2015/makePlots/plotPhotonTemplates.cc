#include <iostream>

#include "TFile.h"
#include "TH1.h"
#include "TKey.h"
#include "TAxis.h"
#include "TCanvas.h"

using namespace std;

void plotPhotonTemplates()
{

  int rebin = 10;
  
  string filename = "../output/photon/V00-00-00/All_MC_photon_templates.root";
  string outputdir = "../output/ZMET2015/V00-00-00/plots/Templates/";

  TCanvas * c1 = new TCanvas("c1","c1",800,800);
  
  TFile *infile = new TFile(filename.c_str());
  std::cout<<"Reading hists from file: "<<filename<<endl;
  infile->cd();
  TIter iKey(infile->GetListOfKeys());
  TKey* key=0;
  while((key=(TKey*)iKey())) {
	TH1* hist=(TH1*)key->ReadObjectAny(TH1::Class());
	string histname = hist->GetName();
	// cout<<"Name:  "<<TString(hist->GetName())<<endl;
	string histtitle = hist->GetTitle();
	// cout<<"Title: "<<TString(hist->GetTitle())<<endl;

	c1->cd();
	c1->SetLogy(true);
	hist->Rebin(rebin);
    double entries = hist->GetEntries();
	hist->GetXaxis()->SetTitle(Form("E_{T}^{miss}; %i entries",(int)entries));
	hist->GetYaxis()->SetTitle(Form("Normalized Entries/%i GeV",rebin));
	hist->GetYaxis()->SetRangeUser(1e-6,1);
	hist->Draw("histe1");

	if( !(histtitle == "") ){	
	  string outfile = outputdir+histtitle+".png";	
	  c1->SaveAs(outfile.c_str());
	}

	else{ 
	  string outfile = outputdir+histname+".png";	
	  c1->SaveAs(outfile.c_str());
	}

	// outfile = outputdir+histtitle+".ps";
	// c1->SaveAs(outfile.c_str());
	
  }


  
  return;
}
