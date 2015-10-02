#include <iostream>
#include <stdexcept>

#include <TFile.h>
#include <TH1F.h>

using namespace std;

void getReweightVtxHist()
{

  // TFile * f_data = TFile::Open("../output/V07-04-10/data_inclusive_novtxweight_hists.root" , "READ");
  // TFile * f_phot = TFile::Open("../output/V07-04-10/data_inclusive_templates.root"         , "READ");

  TFile * f_data = TFile::Open("../output/V07-04-10/zjetsmlm_rawMET_novtxweight_hists.root"   , "READ");
  TFile * f_phot = TFile::Open("../output/V07-04-10/All_MC_rawMET_novtxweight_templates.root" , "READ");

  TH1F * h_data = (TH1F*)f_data->Get("h_ll_event_nVert_passtrig")->Clone("h_data");
  TH1F * h_phot = (TH1F*)f_phot->Get("h_ph_event_nVert_passtrig")->Clone("h_phot");

  TH1F * h_phot_22  = (TH1F*)f_phot->Get("h_ph_event_nVert_passtrig22" )->Clone("h_phot_22");
  TH1F * h_phot_30  = (TH1F*)f_phot->Get("h_ph_event_nVert_passtrig30" )->Clone("h_phot_30");
  TH1F * h_phot_36  = (TH1F*)f_phot->Get("h_ph_event_nVert_passtrig36" )->Clone("h_phot_36");
  TH1F * h_phot_50  = (TH1F*)f_phot->Get("h_ph_event_nVert_passtrig50" )->Clone("h_phot_50");
  TH1F * h_phot_75  = (TH1F*)f_phot->Get("h_ph_event_nVert_passtrig75" )->Clone("h_phot_75");
  TH1F * h_phot_90  = (TH1F*)f_phot->Get("h_ph_event_nVert_passtrig90" )->Clone("h_phot_90");
  TH1F * h_phot_120 = (TH1F*)f_phot->Get("h_ph_event_nVert_passtrig120")->Clone("h_phot_120");
  TH1F * h_phot_165 = (TH1F*)f_phot->Get("h_ph_event_nVert_passtrig165")->Clone("h_phot_165");

  // double bins[23] = {0,5,6,7,8,
  // 					9,10,11,12,13,
  // 					14,15,16,17,18,
  // 					 19,20,21,22,23,24,25,35};
  // int nbins = 22;

  // h_data = (TH1F*) h_data->Rebin(nbins, "h_data_rebinned", bins);
  // h_phot = (TH1F*) h_phot->Rebin(nbins, "h_phot_rebinned", bins);
  // h_phot_22  = (TH1F*) h_phot_22 ->Rebin(nbins, "h_phot_22_rebinned", bins);
  // h_phot_30  = (TH1F*) h_phot_30 ->Rebin(nbins, "h_phot_30_rebinned", bins);
  // h_phot_36  = (TH1F*) h_phot_36 ->Rebin(nbins, "h_phot_36_rebinned", bins);
  // h_phot_50  = (TH1F*) h_phot_50 ->Rebin(nbins, "h_phot_50_rebinned", bins);
  // h_phot_75  = (TH1F*) h_phot_75 ->Rebin(nbins, "h_phot_75_rebinned", bins);
  // h_phot_90  = (TH1F*) h_phot_90 ->Rebin(nbins, "h_phot_90_rebinned", bins);
  // h_phot_120 = (TH1F*) h_phot_120->Rebin(nbins, "h_phot_120_rebinned", bins);
  // h_phot_165 = (TH1F*) h_phot_165->Rebin(nbins, "h_phot_165_rebinned", bins);

  // h_data->Rebin(5);
  // h_phot->Rebin(5);
  // h_phot_22 ->Rebin(5);
  // h_phot_30 ->Rebin(5);
  // h_phot_36 ->Rebin(5);
  // h_phot_50 ->Rebin(5);
  // h_phot_75 ->Rebin(5);
  // h_phot_90 ->Rebin(5);
  // h_phot_120->Rebin(5);
  // h_phot_165->Rebin(5);

  h_phot->Scale(1./h_phot->GetSumOfWeights());
  h_data->Scale(1./h_data->GetSumOfWeights());

  h_phot_22  -> Scale( 1./ h_phot_22  -> GetSumOfWeights() );
  h_phot_30  -> Scale( 1./ h_phot_30  -> GetSumOfWeights() );
  h_phot_36  -> Scale( 1./ h_phot_36  -> GetSumOfWeights() );
  h_phot_50  -> Scale( 1./ h_phot_50  -> GetSumOfWeights() );
  h_phot_75  -> Scale( 1./ h_phot_75  -> GetSumOfWeights() );
  h_phot_90  -> Scale( 1./ h_phot_90  -> GetSumOfWeights() );
  h_phot_120 -> Scale( 1./ h_phot_120 -> GetSumOfWeights() );
  h_phot_165 -> Scale( 1./ h_phot_165 -> GetSumOfWeights() );
  
  TH1F * h_vtx_ratio = (TH1F*) h_data->Clone("h_vtx_ratio");
  TH1F * h_vtx_ratio_22  = (TH1F*) h_data->Clone("h_vtx_ratio_22");
  TH1F * h_vtx_ratio_30  = (TH1F*) h_data->Clone("h_vtx_ratio_30");
  TH1F * h_vtx_ratio_36  = (TH1F*) h_data->Clone("h_vtx_ratio_36");
  TH1F * h_vtx_ratio_50  = (TH1F*) h_data->Clone("h_vtx_ratio_50");
  TH1F * h_vtx_ratio_75  = (TH1F*) h_data->Clone("h_vtx_ratio_75");
  TH1F * h_vtx_ratio_90  = (TH1F*) h_data->Clone("h_vtx_ratio_90");
  TH1F * h_vtx_ratio_120 = (TH1F*) h_data->Clone("h_vtx_ratio_120");
  TH1F * h_vtx_ratio_165 = (TH1F*) h_data->Clone("h_vtx_ratio_165");

  h_vtx_ratio->Divide(h_phot);
  h_vtx_ratio_22 -> Divide(h_phot_22 );
  h_vtx_ratio_30 -> Divide(h_phot_30 );
  h_vtx_ratio_36 -> Divide(h_phot_36 );
  h_vtx_ratio_50 -> Divide(h_phot_50 );
  h_vtx_ratio_75 -> Divide(h_phot_75 );
  h_vtx_ratio_90 -> Divide(h_phot_90 );
  h_vtx_ratio_120-> Divide(h_phot_120);
  h_vtx_ratio_165-> Divide(h_phot_165);

  
  TFile * file = TFile::Open("nvtx_ratio_MC.root","RECREATE");
  file->cd();
  h_data->Write();
  h_phot->Write();
  h_phot_22 ->Write();
  h_phot_30 ->Write();
  h_phot_36 ->Write();
  h_phot_50 ->Write();
  h_phot_75 ->Write();
  h_phot_90 ->Write();
  h_phot_120->Write();
  h_phot_165->Write();
  h_vtx_ratio->Write();
  h_vtx_ratio_22 ->Write();
  h_vtx_ratio_30 ->Write();
  h_vtx_ratio_36 ->Write();
  h_vtx_ratio_50 ->Write();
  h_vtx_ratio_75 ->Write();
  h_vtx_ratio_90 ->Write();
  h_vtx_ratio_120->Write();
  h_vtx_ratio_165->Write();
  file->Close();
  
  return;
}
