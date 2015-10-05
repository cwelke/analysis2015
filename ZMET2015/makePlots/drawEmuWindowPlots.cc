#include <iostream>

#include "TFile.h"
#include "TCut.h"
#include "TH1F.h"
#include "TChain.h"
#include "TColor.h"
#include "TPad.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TLine.h"
#include "TLegend.h"
#include "TStyle.h"

using namespace std;

//______________________________________________________________________________
// returns the error on C = A*B (or C = A/B)
float err_mult(float A, float B, float errA, float errB, float C) {
  return sqrt(C*C*(pow(errA/A,2) + pow(errB/B,2)));
}

void drawEmuWindowPlots( string version = "V07-04-10", string selection = "rawMET_bveto_SRA" )
{

  
  TFile * f_mc   = TFile::Open(Form("../output/%s/ttbar_%s_hists.root", version.c_str(), selection.c_str()));
  TFile * f_data = TFile::Open(Form("../output/%s/data_%s_hists.root", version.c_str(), selection.c_str()));

  // TH1F * h_mc_met50   = dynamic_cast<TH1F*>(f_mc   -> Get("h_ll_event_mll_metrawgt50_passtrig")->Clone("h_mc_met50"));
  // TH1F * h_data_met50 = dynamic_cast<TH1F*>(f_data -> Get("h_ll_event_mll_metrawgt50_passtrig")->Clone("h_data_met50"));

  TH1F * h_mc_met50   = dynamic_cast<TH1F*>(f_mc   -> Get("h_em_event_mll_passtrig")->Clone("h_mc_met50"));
  TH1F * h_data_met50 = dynamic_cast<TH1F*>(f_data -> Get("h_em_event_mll_passtrig")->Clone("h_data_met50"));

  h_mc_met50->SetMarkerSize(1);
  h_data_met50->SetMarkerSize(1);

  h_mc_met50->SetLineColor(kRed);  
  h_data_met50->SetLineColor(kRed);

  h_mc_met50   -> GetXaxis() -> SetTitle("m_{\\ell\\ell} [GeV]");
  h_data_met50 -> GetXaxis() -> SetTitle("m_{\\ell\\ell} [GeV]");

  h_mc_met50   -> GetYaxis() -> SetTitle("Events/1 [GeV]");
  h_data_met50 -> GetYaxis() -> SetTitle("Events/1 [GeV]");

  // h_mc_met50->Scale(10);
  // h_data_met50->Scale(10);

  // h_mc_met50   -> GetYaxis() -> SetRangeUser(2e1,2e6);
  // h_data_met50 -> GetYaxis() -> SetRangeUser(2e1,2e6);

  // h_mc_met50   -> GetXaxis() -> SetRangeUser(76,106);
  // h_data_met50 -> GetXaxis() -> SetRangeUser(76,106);

  // TCanvas * c_met = new TCanvas("c_met","",800,800);
  // c_met->cd();

  // TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 1.0);
  // pad->SetBottomMargin(0.12);
  // pad->SetRightMargin(0.07);
  // pad->SetTopMargin(0.07);
  // pad->SetLeftMargin(0.18);
  // pad->Draw();
  // pad->cd();
  // pad->SetLogy();

  // float lobin = 81;
  // float hibin = 101;
  
  // TLine * cut_lo = new TLine( lobin-5, 2e1, lobin-5, 2e6);
  // TLine * cut_hi = new TLine( hibin+5, 2e1, hibin+5, 2e6);
  
  // TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.90);    
  // l1->SetLineColor(kWhite);    
  // l1->SetShadowColor(kWhite);    
  // l1->SetFillColor(kWhite);    
  // l1->AddEntry( h_mc_met50 , "ee events"       , "lpe");
  // l1->AddEntry( h_data_met50 , "#mu#mu events"   , "lpe");

  // h_data_met50->Draw("histe1");
  // h_mc_met50->Draw("histe1same");
  // // h_mc_met50->Draw("histe1");
  // cut_hi->Draw("same");
  // cut_lo->Draw("same");
  // l1->Draw("same");

  // c_met->SaveAs("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/mll.pdf");
  // c_met->SaveAs("/home/users/cwelke/public_html/ZMET2015/V00-00-15/plots/mll.png");

  double val_den_mc_met50 = 0;
  double err_den_mc_met50 = 0;

  double val_den_data_met50 = 0;
  double err_den_data_met50 = 0;

  val_den_mc_met50   = h_mc_met50   -> IntegralAndError(0, -1., err_den_mc_met50);

  val_den_data_met50 = h_data_met50 -> IntegralAndError(0, -1., err_den_data_met50);

  double val_num_mc_met50 = 0;
  double err_num_mc_met50 = 0;

  double val_num_data_met50 = 0;
  double err_num_data_met50 = 0;

  val_num_mc_met50   = h_mc_met50   -> IntegralAndError(h_mc_met50->FindBin(81)  , h_mc_met50->FindBin(101)-1  , err_num_mc_met50);

  val_num_data_met50 = h_data_met50 -> IntegralAndError(h_data_met50->FindBin(81), h_data_met50->FindBin(101)-1, err_num_data_met50);

  cout<<"total mc:   "<<val_den_mc_met50  << " | "<<err_den_mc_met50  <<endl;
  cout<<"total data: "<<val_den_data_met50<< " | "<<err_den_data_met50<<endl;
  cout<<"on-Z  mc:   "<<val_num_mc_met50  << " | "<<err_num_mc_met50  <<endl;
  cout<<"on-Z  data: "<<val_num_data_met50<< " | "<<err_num_data_met50<<endl;
  cout<<"eff   mc:   "<<val_num_mc_met50/val_den_mc_met50    << " | "<<err_mult(val_num_mc_met50, val_den_mc_met50, err_num_mc_met50, err_den_mc_met50, val_num_mc_met50/val_den_mc_met50)  <<endl;
  cout<<"eff   data: "<<val_num_data_met50/val_den_data_met50<< " | "<<err_mult(val_num_data_met50, val_den_data_met50, err_num_data_met50, err_den_data_met50, val_num_data_met50/val_den_data_met50)  <<endl;
  
  return;
}
