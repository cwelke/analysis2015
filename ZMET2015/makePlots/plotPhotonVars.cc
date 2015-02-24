#include <iostream>

#include "TFile.h"
#include "TH1.h"
#include "THStack.h"
#include "TKey.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TColor.h"

using namespace std;

void plotPhotonVars()
{

  int rebin = 10;
  
  string filename = "../output/photon/V00-00-00/All_MC_photon_templates.root";
  string outputdir = "../output/ZMET2015/V00-00-00/plots/Templates/";

  TCanvas * c1 = new TCanvas("c1","c1",800,800);
  
  TFile *infile = new TFile(filename.c_str());
  std::cout<<"Reading hists from file: "<<filename<<endl;
  // infile->cd();
  // TIter iKey(infile->GetListOfKeys());
  // TKey* key=0;
  // while((key=(TKey*)iKey())) {
  // 	TH1* hist=(TH1*)key->ReadObjectAny(TH1::Class());
  // 	string histname = hist->GetName();
  // 	// cout<<"Name:  "<<TString(hist->GetName())<<endl;
  // 	string histtitle = hist->GetTitle();
  // 	// cout<<"Title: "<<TString(hist->GetTitle())<<endl;

  // 	c1->cd();
  // 	c1->SetLogy(true);
  // 	hist->Rebin(rebin);
  //   double entries = hist->GetEntries();
  // 	hist->GetXaxis()->SetTitle(Form("E_{T}^{miss}; %i entries",(int)entries));
  // 	hist->GetYaxis()->SetTitle(Form("Normalized Entries/%i GeV",rebin));
  // 	hist->GetYaxis()->SetRangeUser(1e-6,1);
  // 	hist->Draw("histe1");

  // 	string outfile = outputdir+histtitle+".png";	
  // 	c1->SaveAs(outfile.c_str());
  //   // outfile = outputdir+histtitle+".ps";
  // 	// c1->SaveAs(outfile.c_str());
	
  // }

  TH1* hist_pt=(TH1*)infile->Get("photon_pt");
  TH1* hist_pt_ht100=(TH1*)infile->Get("photon_pt_ht100");
  TH1* hist_pt_ht200=(TH1*)infile->Get("photon_pt_ht200");
  TH1* hist_pt_ht400=(TH1*)infile->Get("photon_pt_ht400");
  TH1* hist_pt_ht600=(TH1*)infile->Get("photon_pt_ht600");

  THStack * stack = new THStack("","");

  stack->Add(hist_pt_ht600);
  stack->Add(hist_pt_ht400);
  stack->Add(hist_pt_ht200);
  stack->Add(hist_pt_ht100);
  
  hist_pt->Rebin(10);
  hist_pt_ht100->Rebin(10);
  hist_pt_ht200->Rebin(10);
  hist_pt_ht400->Rebin(10);
  hist_pt_ht600->Rebin(10);

  hist_pt_ht100->SetFillColor(kGreen  );
  hist_pt_ht200->SetFillColor(kBlue   );
  hist_pt_ht400->SetFillColor(kRed    );
  hist_pt_ht600->SetFillColor(kMagenta);

  hist_pt_ht600->SetFillStyle(1001);
  hist_pt_ht400->SetFillStyle(1001);
  hist_pt_ht200->SetFillStyle(1001);
  hist_pt_ht100->SetFillStyle(1001);
	
  c1->cd();
  c1->SetLogy(true);

  double entries = hist_pt->GetEntries();
  hist_pt->GetXaxis()->SetTitle(Form("photon p_{T}; %i entries",(int)entries));
  hist_pt->GetYaxis()->SetTitle(Form("Entries/%i GeV",rebin));
  // hist->GetYaxis()->SetRangeUser(1e-6,1);
  hist_pt->Draw("histe1");
  stack->Draw("hist");
  // hist_pt->Draw("histe1");
  
  string histtitle = "photon_pt";

  string outfile = outputdir+histtitle+".png";	
  c1->SaveAs(outfile.c_str());
  // outfile = outputdir+histtitle+".ps";
  // c1->SaveAs(outfile.c_str());

  return;
}
