#include <iostream>
#include <stdexcept>

#include <TFile.h>
#include <TH1F.h>

using namespace std;

void getReweightHTHist( string signalregion )
{

  // TFile * f_data = TFile::Open("../output/V07-04-10/data_inclusive_hists.root"     , "READ");
  // TFile * f_phot = TFile::Open("../output/V07-04-10/data_inclusive_templates.root" , "READ");

  TFile * f_data = TFile::Open(Form("../output/V07-04-10/zjetsmlm_%s_novtxweight_hists.root", signalregion.c_str() )   , "READ");
  TFile * f_phot = TFile::Open(Form("../output/V07-04-10/All_MC_%s_novtxweight_nohtweight_templates.root", signalregion.c_str() ) , "READ");
  
  TH1F * h_data = (TH1F*)f_data->Get("h_ll_event_ht_gt1j_passtrig")->Clone("h_data");
  TH1F * h_phot = (TH1F*)f_phot->Get("h_ph_event_htgt1jets_passtrig")->Clone("h_phot");

  TH1F * h_phot_22  = (TH1F*)f_phot->Get("h_ph_event_htgt1jets_passtrig22" )->Clone("h_phot_22");
  TH1F * h_phot_30  = (TH1F*)f_phot->Get("h_ph_event_htgt1jets_passtrig30" )->Clone("h_phot_30");
  TH1F * h_phot_36  = (TH1F*)f_phot->Get("h_ph_event_htgt1jets_passtrig36" )->Clone("h_phot_36");
  TH1F * h_phot_50  = (TH1F*)f_phot->Get("h_ph_event_htgt1jets_passtrig50" )->Clone("h_phot_50");
  TH1F * h_phot_75  = (TH1F*)f_phot->Get("h_ph_event_htgt1jets_passtrig75" )->Clone("h_phot_75");
  TH1F * h_phot_90  = (TH1F*)f_phot->Get("h_ph_event_htgt1jets_passtrig90" )->Clone("h_phot_90");
  TH1F * h_phot_120 = (TH1F*)f_phot->Get("h_ph_event_htgt1jets_passtrig120")->Clone("h_phot_120");
  TH1F * h_phot_165 = (TH1F*)f_phot->Get("h_ph_event_htgt1jets_passtrig165")->Clone("h_phot_165");

  // for data
  // double bins[28] = {0,35,40,45,50,55,60,65,70,
  // 					 80,90,100,110,120,130,140,
  // 					 150,175,200,
  // 					 250,300,350,400,450,500,600,700,1000};
  // int nbins = 27;

  // h_data     = (TH1F*) h_data    ->Rebin(nbins, "h_data_rebinned", bins);
  // h_phot     = (TH1F*) h_phot    ->Rebin(nbins, "h_phot_rebinned", bins);
  // h_phot_22  = (TH1F*) h_phot_22 ->Rebin(nbins, "h_phot_22_rebinned", bins);
  // h_phot_30  = (TH1F*) h_phot_30 ->Rebin(nbins, "h_phot_30_rebinned", bins);
  // h_phot_36  = (TH1F*) h_phot_36 ->Rebin(nbins, "h_phot_36_rebinned", bins);
  // h_phot_50  = (TH1F*) h_phot_50 ->Rebin(nbins, "h_phot_50_rebinned", bins);
  // h_phot_75  = (TH1F*) h_phot_75 ->Rebin(nbins, "h_phot_75_rebinned", bins);
  // h_phot_90  = (TH1F*) h_phot_90 ->Rebin(nbins, "h_phot_90_rebinned", bins);
  // h_phot_120 = (TH1F*) h_phot_120->Rebin(nbins, "h_phot_120_rebinned", bins);
  // h_phot_165 = (TH1F*) h_phot_165->Rebin(nbins, "h_phot_165_rebinned", bins);

  vector <double> v_bin;
  v_bin.push_back(0);
  v_bin.push_back(35);
  v_bin.push_back(40);
  v_bin.push_back(45);
  v_bin.push_back(50);
  v_bin.push_back(55);
  v_bin.push_back(60);
  v_bin.push_back(65);
  v_bin.push_back(70);
  v_bin.push_back(80);
  v_bin.push_back(90);

  v_bin.push_back(100);
  v_bin.push_back(105);
  v_bin.push_back(110);
  v_bin.push_back(115);
  v_bin.push_back(120);
  v_bin.push_back(125);
  v_bin.push_back(130);
  v_bin.push_back(135);
  v_bin.push_back(140);
  v_bin.push_back(145);
  v_bin.push_back(150);
  v_bin.push_back(160);
  v_bin.push_back(170);
  v_bin.push_back(180);
  v_bin.push_back(190);

  v_bin.push_back(200);
  v_bin.push_back(225);
  v_bin.push_back(250);
  v_bin.push_back(275);
  v_bin.push_back(300);
  v_bin.push_back(325);
  v_bin.push_back(350);
  v_bin.push_back(400);
  v_bin.push_back(450);
  v_bin.push_back(500);
  v_bin.push_back(600);
  v_bin.push_back(700);
  v_bin.push_back(800);
  v_bin.push_back(900);
  v_bin.push_back(1000);
  v_bin.push_back(1100);
  v_bin.push_back(1200);
  v_bin.push_back(1300);
  v_bin.push_back(1400);
  v_bin.push_back(1500);
  // v_bin.push_back(1750);
  // v_bin.push_back(2000);
  // v_bin.push_back(2500);
  v_bin.push_back(3000);


  int nbins = v_bin.size()-1;
  
  double bins[nbins+1];

  for( size_t bini = 0; bini < v_bin.size(); bini++ ){
	bins[bini] = v_bin.at(bini);
  }
  
  h_data     = (TH1F*) h_data    ->Rebin(nbins, "h_data_rebinned", bins);
  h_phot     = (TH1F*) h_phot    ->Rebin(nbins, "h_phot_rebinned", bins);
  h_phot_22  = (TH1F*) h_phot_22 ->Rebin(nbins, "h_phot_22_rebinned", bins);
  h_phot_30  = (TH1F*) h_phot_30 ->Rebin(nbins, "h_phot_30_rebinned", bins);
  h_phot_36  = (TH1F*) h_phot_36 ->Rebin(nbins, "h_phot_36_rebinned", bins);
  h_phot_50  = (TH1F*) h_phot_50 ->Rebin(nbins, "h_phot_50_rebinned", bins);
  h_phot_75  = (TH1F*) h_phot_75 ->Rebin(nbins, "h_phot_75_rebinned", bins);
  h_phot_90  = (TH1F*) h_phot_90 ->Rebin(nbins, "h_phot_90_rebinned", bins);
  h_phot_120 = (TH1F*) h_phot_120->Rebin(nbins, "h_phot_120_rebinned", bins);
  h_phot_165 = (TH1F*) h_phot_165->Rebin(nbins, "h_phot_165_rebinned", bins);

  // h_data    ->Rebin(10);
  // h_phot    ->Rebin(10);
  // h_phot_22 ->Rebin(10);
  // h_phot_30 ->Rebin(10);
  // h_phot_36 ->Rebin(10);
  // h_phot_50 ->Rebin(10);
  // h_phot_75 ->Rebin(10);
  // h_phot_90 ->Rebin(10);
  // h_phot_120->Rebin(10);
  // h_phot_165->Rebin(10);

  // h_data    ->Rebin(25);
  // h_phot    ->Rebin(25);
  // h_phot_22 ->Rebin(25);
  // h_phot_30 ->Rebin(25);
  // h_phot_36 ->Rebin(25);
  // h_phot_50 ->Rebin(25);
  // h_phot_75 ->Rebin(25);
  // h_phot_90 ->Rebin(25);
  // h_phot_120->Rebin(25);
  // h_phot_165->Rebin(25);

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
  
  TH1F * h_ht_ratio = (TH1F*) h_data->Clone("h_ht_ratio");
  TH1F * h_ht_ratio_22  = (TH1F*) h_data->Clone("h_ht_ratio_22");
  TH1F * h_ht_ratio_30  = (TH1F*) h_data->Clone("h_ht_ratio_30");
  TH1F * h_ht_ratio_36  = (TH1F*) h_data->Clone("h_ht_ratio_36");
  TH1F * h_ht_ratio_50  = (TH1F*) h_data->Clone("h_ht_ratio_50");
  TH1F * h_ht_ratio_75  = (TH1F*) h_data->Clone("h_ht_ratio_75");
  TH1F * h_ht_ratio_90  = (TH1F*) h_data->Clone("h_ht_ratio_90");
  TH1F * h_ht_ratio_120 = (TH1F*) h_data->Clone("h_ht_ratio_120");
  TH1F * h_ht_ratio_165 = (TH1F*) h_data->Clone("h_ht_ratio_165");

  h_ht_ratio->Divide(h_phot);
  h_ht_ratio_22 -> Divide(h_phot_22 );
  h_ht_ratio_30 -> Divide(h_phot_30 );
  h_ht_ratio_36 -> Divide(h_phot_36 );
  h_ht_ratio_50 -> Divide(h_phot_50 );
  h_ht_ratio_75 -> Divide(h_phot_75 );
  h_ht_ratio_90 -> Divide(h_phot_90 );
  h_ht_ratio_120-> Divide(h_phot_120);
  h_ht_ratio_165-> Divide(h_phot_165);


  string filename = Form("ht_ratio_MC_novtx_nohtweight_%s.root", signalregion.c_str() );
  
  TFile * file = TFile::Open( filename.c_str() ,"RECREATE");
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
  h_ht_ratio->Write();
  h_ht_ratio_22 ->Write();
  h_ht_ratio_30 ->Write();
  h_ht_ratio_36 ->Write();
  h_ht_ratio_50 ->Write();
  h_ht_ratio_75 ->Write();
  h_ht_ratio_90 ->Write();
  h_ht_ratio_120->Write();
  h_ht_ratio_165->Write();
  file->Close();

  cout<<"Writing reweighting hists to file: "<<filename.c_str() <<endl;
  return;
}
