#include "TFile.h"
#include "TChain.h"
#include "TH1.h"
#include "TH2.h"
#include "TString.h"

void make_nsig_weight_hists(TString dir, TString sample) {


  
  TChain* t = new TChain("t");
  t->Add(Form("%s/%s*.root",dir.Data(),sample.Data()));

  TFile* fout = new TFile("nsig_weights_T5ZZ.root","RECREATE");
  
  // assuming here: 50 GeV binning, m1 from 600-1650, m2 from 100-1550
  TH2D* h_nsig = new TH2D("h_nsig",";mass1 [GeV];mass2 [GeV]",(1600-550)/50,575,1625,(1500-50)/50,75,1525);
  TH2D* h_avg_weight_btagsf = (TH2D*) h_nsig->Clone("h_avg_weight_btagsf");
  TH2D* h_avg_weight_btagsf_heavy_UP = (TH2D*) h_nsig->Clone("h_avg_weight_btagsf_heavy_UP");
  TH2D* h_avg_weight_btagsf_light_UP = (TH2D*) h_nsig->Clone("h_avg_weight_btagsf_light_UP");
  TH2D* h_avg_weight_btagsf_heavy_DN = (TH2D*) h_nsig->Clone("h_avg_weight_btagsf_heavy_DN");
  TH2D* h_avg_weight_btagsf_light_DN = (TH2D*) h_nsig->Clone("h_avg_weight_btagsf_light_DN");

  TH2D* h_avg_weight_isr    = (TH2D*) h_nsig->Clone("h_avg_weight_isr");
  TH2D* h_avg_weight_isr_lo = (TH2D*) h_nsig->Clone("h_avg_weight_isr_lo");
  TH2D* h_avg_weight_isr_hi = (TH2D*) h_nsig->Clone("h_avg_weight_isr_hi");

  t->Draw("mass_LSP:mass_gluino>>h_nsig");
  t->Draw("mass_LSP:mass_gluino>>h_avg_weight_btagsf","(met_pt > -1.)*weight_btagsf" );
  t->Draw("mass_LSP:mass_gluino>>h_avg_weight_btagsf_heavy_UP","(met_pt > -1.)*weight_btagsf_heavy_UP" );
  t->Draw("mass_LSP:mass_gluino>>h_avg_weight_btagsf_light_UP","(met_pt > -1.)*weight_btagsf_light_UP" );
  t->Draw("mass_LSP:mass_gluino>>h_avg_weight_btagsf_heavy_DN","(met_pt > -1.)*weight_btagsf_heavy_DN" );
  t->Draw("mass_LSP:mass_gluino>>h_avg_weight_btagsf_light_DN","(met_pt > -1.)*weight_btagsf_light_DN" );

  t->Draw("mass_LSP:mass_gluino>>h_avg_weight_isr"   ,"(                  isrboost < 400)" );
  t->Draw("mass_LSP:mass_gluino>>h_avg_weight_isr_lo","(isrboost > 400 && isrboost < 600)*0.85" );
  t->Draw("mass_LSP:mass_gluino>>h_avg_weight_isr_hi","(isrboost > 600                  )*0.70" );

  h_avg_weight_isr->Add(h_avg_weight_isr_lo);
  h_avg_weight_isr->Add(h_avg_weight_isr_hi);
  
  h_avg_weight_btagsf->Divide(h_nsig);
  h_avg_weight_btagsf_heavy_UP->Divide(h_nsig);
  h_avg_weight_btagsf_light_UP->Divide(h_nsig);
  h_avg_weight_btagsf_heavy_DN->Divide(h_nsig);
  h_avg_weight_btagsf_light_DN->Divide(h_nsig);
  h_avg_weight_isr->Divide(h_nsig);
  
  fout->Write();
  fout->Close();

}
