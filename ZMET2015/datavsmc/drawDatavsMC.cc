#include "TH1F.h"
#include "TFile.h"
#include "TLine.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TPad.h"
#include "TLatex.h"
#include "THStack.h"

#include <iostream>

#include "../sharedCode/histTools.cc"

using namespace std;
void drawDatavsMC( std::string iter = "", float luminosity = 1.0, const string selection = "_inclusive", string dilep = "ll", string variable = "mll", string region = "passtrig" )
{

  bool usetemplates   = true;
  bool usefsbkg       = true;
  bool applysysts     = true;
  bool isblind        = true;
  bool printyields    = true;

  TH1F * h_data  = NULL;
  TH1F * h_zjets = NULL;
  TH1F * h_ttbar = NULL;
  TH1F * h_wz    = NULL;
  TH1F * h_ww    = NULL;
  TH1F * h_zz    = NULL;
  TH1F * h_st    = NULL;
  TH1F * h_vvv   = NULL;
  TH1F * h_ttv   = NULL;

  // TH1F * h_fsbkg = NULL;
  // TH1F * h_other = NULL;
  // TH1F * h_vvbkg = NULL;

  // string variable = "mll";
  // string dilep = "ll";
  
  getBackground(   h_data, iter, Form("data%s" , selection.c_str() ), variable, dilep, region );
  if( usefsbkg ){
	// getBackground(  h_ttbar, iter, Form("data%s", selection.c_str() ),    "metgt1jet", "em", "inclusive" );
	getBackground(  h_ttbar, iter, Form("data%s", selection.c_str() ),    variable, "em", "passtrig" );
  }
  else           getBackground(  h_ttbar, iter, Form("ttbar%s", selection.c_str() ), variable, dilep, region );

  getBackground(                 h_st   , iter, Form("st%s"   , selection.c_str() ), variable, dilep, region );
  getBackground(                 h_wz   , iter, Form("wz%s"   , selection.c_str() ), variable, dilep, region );
  getBackground(                 h_ww   , iter, Form("ww%s"   , selection.c_str() ), variable, dilep, region );
  getBackground(                 h_zz   , iter, Form("zz%s"   , selection.c_str() ), variable, dilep, region );
  getBackground(                 h_ttv  , iter, Form("vvv%s"  , selection.c_str() ), variable, dilep, region );
  getBackground(                 h_vvv  , iter, Form("ttv%s"  , selection.c_str() ), variable, dilep, region );

  if( usetemplates ) getTemplateMET( h_zjets, iter, Form("data%s", selection.c_str() ) );
  else getBackground(  h_zjets, iter, Form("zjets%s", selection.c_str() ), variable, dilep, region );

  if( isblind ){
	if( TString(selection).Contains("SR_ATLAS") ){
	  for( int binind = 0; binind < h_data -> GetNbinsX()+1; binind++ ){
		if( binind >= h_data->FindBin(225) ) h_data -> SetBinContent( binind, 0 );
		if( binind >= h_data->FindBin(225) ) h_data -> SetBinError( binind, 0 );
	  }
	}
	else if( TString(selection).Contains("twojets") && !TString(selection).Contains("3jets") ){
	  for( int binind = 0; binind < h_data -> GetNbinsX()+1; binind++ ){
		if( binind >= h_data->FindBin(150) ) h_data -> SetBinContent( binind, 0 );
		if( binind >= h_data->FindBin(150) ) h_data -> SetBinError( binind, 0 );
	  }
	}
	else{	  
	  for( int binind = 0; binind < h_data -> GetNbinsX()+1; binind++ ){
		if( binind >= h_data->FindBin(100) ) h_data -> SetBinContent( binind, 0 );
		if( binind >= h_data->FindBin(100) ) h_data -> SetBinError( binind, 0 );
	  }
	}
  }
  
  h_st ->Scale(luminosity);
  h_ww ->Scale(luminosity);
  h_wz ->Scale(luminosity);
  h_zz ->Scale(0);
  h_ttv->Scale(luminosity);
  h_vvv->Scale(luminosity);

  // h_st ->Scale(0);
  // h_ww ->Scale(0);
  // h_wz ->Scale(0);
  // h_zz ->Scale(0);
  // h_ttv->Scale(0);
  // h_vvv->Scale(0);
  
  if( usetemplates ){
  
	// h_ttbar->Scale(0.13);
	// h_zjets->Scale(1./h_zjets->GetSumOfWeights());

	float val_data  = h_data  -> Integral(1,50);
	float val_ttbar = h_ttbar -> Integral(1,50);
	float val_zjets = h_zjets -> Integral(1,50);
	val_ttbar += h_wz  -> Integral(1,50);
	val_ttbar += h_zz  -> Integral(1,50);
	val_ttbar += h_ttv -> Integral(1,50);
	val_ttbar += h_vvv -> Integral(1,50);

	cout<<"data:  "<<val_data<<endl;
	cout<<"zjets: "<<val_zjets<<endl;
	cout<<"ttbar: "<<val_ttbar<<endl;
  
	float scaleval = ((val_data-val_ttbar)/(val_zjets));
	h_zjets->Scale(scaleval);
  
	val_data  = h_data  -> Integral(1,50);
	// val_ttbar = h_ttbar -> Integral(1,50);
	val_zjets = h_zjets -> Integral(1,50);

	cout<<"data:  "<<val_data<<endl;
	cout<<"zjets: "<<val_zjets<<endl;
	cout<<"ttbar: "<<val_ttbar<<endl;

  }
  else{
	h_zjets->Scale(luminosity);
	  if( !usefsbkg ) h_ttbar->Scale(luminosity);
  }

  if( printyields ){
  
	//MAKE TABLES
	vector <float> metcut;
	if( variable == "mll" ){
	  metcut.clear();
	  // metcut.push_back(20);
	  // metcut.push_back(70);
	  metcut.push_back(81);
	  metcut.push_back(101);
	  // metcut.push_back(120);
	  // metcut.push_back(165);
	  // metcut.push_back(185);
	  metcut.push_back(-1);

	}else{

	  if( TString(selection).Contains("twojets"      ) ){
		metcut.clear();
		metcut.push_back(0.0);
		metcut.push_back(50);
		metcut.push_back(100);
		metcut.push_back(150);
		metcut.push_back(-1);

	  }
	  else if( TString(selection).Contains("3jets_inclusive"      ) ){
		metcut.clear();
		metcut.push_back(0.0);
		metcut.push_back(50);
		metcut.push_back(100);
		metcut.push_back(-1);

	  }
	  else if( TString(selection).Contains("SR_ATLAS"      ) ){
		metcut.clear();
		metcut.push_back(0.0);
		metcut.push_back(50);
		metcut.push_back(100);
		metcut.push_back(150);
		metcut.push_back(225);
		metcut.push_back(-1);

	  }
	  else{
		metcut.clear();
		metcut.push_back(0.0);
		metcut.push_back(50);
		metcut.push_back(100);
		metcut.push_back(150);
		metcut.push_back(225);
		metcut.push_back(300);
		metcut.push_back(-1);

	  }

	}

  
	vector <double> val_data;
	vector <double> err_data;

	vector <double> val_zjets;
	vector <double> err_zjets;

	vector <double> val_fsbkg;
	vector <double> err_fsbkg;

	vector <double> val_ttvbg;
	vector <double> err_ttvbg;

	vector <double> val_vvvbg;
	vector <double> err_vvvbg;

	vector <double> val_zzbkg;
	vector <double> err_zzbkg;

	vector <double> val_vvbkg;
	vector <double> err_vvbkg;

	vector <double> val_allbg;
	vector <double> err_allbg;

	vector <double> val_ratio;
	vector <double> err_ratio;
  
	for( size_t i = 0; i < metcut.size(); i++ ){
	  val_data.push_back(0);
	  err_data.push_back(0);
	  val_zjets.push_back(0);
	  err_zjets.push_back(0);
	  val_fsbkg.push_back(0);
	  err_fsbkg.push_back(0);
	  val_ttvbg.push_back(0);
	  err_ttvbg.push_back(0);
	  val_vvvbg.push_back(0);
	  err_vvvbg.push_back(0);
	  val_zzbkg.push_back(0);
	  err_zzbkg.push_back(0);
	  val_vvbkg.push_back(0);
	  err_vvbkg.push_back(0);
	  val_allbg.push_back(0);
	  err_allbg.push_back(0);
	  val_ratio.push_back(0);
	  err_ratio.push_back(0);
	}

	for( size_t bini = 0; bini < metcut.size()-1; bini++ ){

	  float zsyst = 0;
	  if( bini < metcut.size()-1 ){
		// cout<<"getting yields for: "<<metcut.at(bini)<<" | "<< metcut.at(bini+1)-1<<endl;
		// cout<<"getting yields for: "<<h_data ->FindBin(metcut.at(bini))<<" | "<< h_data ->FindBin(metcut.at(bini+1)-1)<<endl;
		val_data .at(bini) = h_data ->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_data .at(bini));
		val_zjets.at(bini) = h_zjets->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_zjets.at(bini));
		val_fsbkg.at(bini) = h_ttbar->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_fsbkg.at(bini));
		val_ttvbg.at(bini) = h_ttv  ->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_ttvbg.at(bini));
		val_vvvbg.at(bini) = h_vvv  ->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_vvvbg.at(bini));
		val_vvbkg.at(bini) = h_wz   ->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_vvbkg.at(bini));
		val_zzbkg.at(bini) = h_zz   ->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_zzbkg.at(bini));

		// if( isblind && metcut.at(bini) >= 100 ){
		//   val_data .at(bini) = 0;
		//   err_data .at(bini) = 0;
		// }
		
		if(       metcut.at(bini+1)   < 0   ){  
		  if( TString(selection).Contains("central_twojets"      ) )zsyst = 0.55;
		  if( TString(selection).Contains("central_withb_twojets") )zsyst = 0.55;
		  if( TString(selection).Contains("central_with2_twojets") )zsyst = 0.55;
		  if( TString(selection).Contains("forward_twojets"      ) )zsyst = 0.30;
		  if( TString(selection).Contains("forward_withb_twojets") )zsyst = 0.75;
		  if( TString(selection).Contains("forward_with2_twojets") )zsyst = 0.80;
		  if( TString(selection).Contains("central_3jets_inclusive"      ) )zsyst = 0.05;
		  if( TString(selection).Contains("central_withb_3jets_inclusive") )zsyst = 0.10;
		  if( TString(selection).Contains("central_with2_3jets_inclusive") )zsyst = 0.15;
		  if( TString(selection).Contains("forward_3jets_inclusive"      ) )zsyst = 0.10;
		  if( TString(selection).Contains("forward_withb_3jets_inclusive") )zsyst = 0.40;
		  if( TString(selection).Contains("forward_with2_3jets_inclusive") )zsyst = 0.60;
		  if( TString(selection).Contains("bveto_SRA"            ) )zsyst = 0.30;
		  if( TString(selection).Contains("withb_SRA"            ) )zsyst = 0.50;
		  if( TString(selection).Contains("bveto_SRB"            ) )zsyst = 0.25;
		  if( TString(selection).Contains("withb_SRB"            ) )zsyst = 0.70;
		  if( TString(selection).Contains("SR_ATLAS"             ) )zsyst = 0.20;

		}else if( metcut.at(bini+1)-1 < 50  ){  
		  if( TString(selection).Contains("central_twojets"      ) )zsyst = 0.01;
		  if( TString(selection).Contains("central_withb_twojets") )zsyst = 0.01;
		  if( TString(selection).Contains("central_with2_twojets") )zsyst = 0.05;
		  if( TString(selection).Contains("forward_twojets"      ) )zsyst = 0.01;
		  if( TString(selection).Contains("forward_withb_twojets") )zsyst = 0.02;
		  if( TString(selection).Contains("forward_with2_twojets") )zsyst = 0.10;
		  if( TString(selection).Contains("central_3jets_inclusive"      ) )zsyst = 0.01;
		  if( TString(selection).Contains("central_withb_3jets_inclusive") )zsyst = 0.01;
		  if( TString(selection).Contains("central_with2_3jets_inclusive") )zsyst = 0.03;
		  if( TString(selection).Contains("forward_3jets_inclusive"      ) )zsyst = 0.01;
		  if( TString(selection).Contains("forward_withb_3jets_inclusive") )zsyst = 0.02;
		  if( TString(selection).Contains("forward_with2_3jets_inclusive") )zsyst = 0.05;
		  if( TString(selection).Contains("bveto_SRA"            ) )zsyst = 0.01;
		  if( TString(selection).Contains("withb_SRA"            ) )zsyst = 0.01;
		  if( TString(selection).Contains("bveto_SRB"            ) )zsyst = 0.01;
		  if( TString(selection).Contains("withb_SRB"            ) )zsyst = 0.02;
		  if( TString(selection).Contains("SR_ATLAS"             ) )zsyst = 0.02;


		}else if( metcut.at(bini+1)-1 < 100 ){
		  if( TString(selection).Contains("central_twojets"      ) )zsyst = 0.06;
		  if( TString(selection).Contains("central_withb_twojets") )zsyst = 0.06;
		  if( TString(selection).Contains("central_with2_twojets") )zsyst = 0.15;
		  if( TString(selection).Contains("forward_twojets"      ) )zsyst = 0.05;
		  if( TString(selection).Contains("forward_withb_twojets") )zsyst = 0.10;
		  if( TString(selection).Contains("forward_with2_twojets") )zsyst = 0.35;
		  if( TString(selection).Contains("central_3jets_inclusive"      ) )zsyst = 0.05;
		  if( TString(selection).Contains("central_withb_3jets_inclusive") )zsyst = 0.05;
		  if( TString(selection).Contains("central_with2_3jets_inclusive") )zsyst = 0.10;
		  if( TString(selection).Contains("forward_3jets_inclusive"      ) )zsyst = 0.02;
		  if( TString(selection).Contains("forward_withb_3jets_inclusive") )zsyst = 0.05;
		  if( TString(selection).Contains("forward_with2_3jets_inclusive") )zsyst = 0.10;
		  if( TString(selection).Contains("bveto_SRA"            ) )zsyst = 0.01;
		  if( TString(selection).Contains("withb_SRA"            ) )zsyst = 0.02;
		  if( TString(selection).Contains("bveto_SRB"            ) )zsyst = 0.02;
		  if( TString(selection).Contains("withb_SRB"            ) )zsyst = 0.06;
		  if( TString(selection).Contains("SR_ATLAS"             ) )zsyst = 0.04;

		}else if( metcut.at(bini+1)-1 < 150 ){
		  if( TString(selection).Contains("central_twojets"      ) )zsyst = 0.10;
		  if( TString(selection).Contains("central_withb_twojets") )zsyst = 0.25;
		  if( TString(selection).Contains("central_with2_twojets") )zsyst = 0.35;
		  if( TString(selection).Contains("forward_twojets"      ) )zsyst = 0.15;
		  if( TString(selection).Contains("forward_withb_twojets") )zsyst = 0.30;
		  if( TString(selection).Contains("forward_with2_twojets") )zsyst = 0.80;
		  if( TString(selection).Contains("central_3jets_inclusive"      ) )zsyst = 0.05;
		  if( TString(selection).Contains("central_withb_3jets_inclusive") )zsyst = 0.10;
		  if( TString(selection).Contains("central_with2_3jets_inclusive") )zsyst = 0.15;
		  if( TString(selection).Contains("forward_3jets_inclusive"      ) )zsyst = 0.10;
		  if( TString(selection).Contains("forward_withb_3jets_inclusive") )zsyst = 0.40;
		  if( TString(selection).Contains("forward_with2_3jets_inclusive") )zsyst = 0.60;
		  if( TString(selection).Contains("bveto_SRA"            ) )zsyst = 0.03;
		  if( TString(selection).Contains("withb_SRA"            ) )zsyst = 0.06;
		  if( TString(selection).Contains("bveto_SRB"            ) )zsyst = 0.04;
		  if( TString(selection).Contains("withb_SRB"            ) )zsyst = 0.10;
		  if( TString(selection).Contains("SR_ATLAS"             ) )zsyst = 0.10;

		}else if( metcut.at(bini+1)-1 < 225 ){ 
		  if( TString(selection).Contains("central_twojets"      ) )zsyst = 0.10;
		  if( TString(selection).Contains("central_withb_twojets") )zsyst = 0.25;
		  if( TString(selection).Contains("central_with2_twojets") )zsyst = 0.35;
		  if( TString(selection).Contains("forward_twojets"      ) )zsyst = 0.15;
		  if( TString(selection).Contains("forward_withb_twojets") )zsyst = 0.30;
		  if( TString(selection).Contains("forward_with2_twojets") )zsyst = 0.80;
		  if( TString(selection).Contains("central_3jets_inclusive"      ) )zsyst = 0.05;
		  if( TString(selection).Contains("central_withb_3jets_inclusive") )zsyst = 0.10;
		  if( TString(selection).Contains("central_with2_3jets_inclusive") )zsyst = 0.15;
		  if( TString(selection).Contains("forward_3jets_inclusive"      ) )zsyst = 0.10;
		  if( TString(selection).Contains("forward_withb_3jets_inclusive") )zsyst = 0.40;
		  if( TString(selection).Contains("forward_with2_3jets_inclusive") )zsyst = 0.60;
		  if( TString(selection).Contains("bveto_SRA"            ) )zsyst = 0.06;
		  if( TString(selection).Contains("withb_SRA"            ) )zsyst = 0.15;
		  if( TString(selection).Contains("bveto_SRB"            ) )zsyst = 0.10;
		  if( TString(selection).Contains("withb_SRB"            ) )zsyst = 0.15;
		  if( TString(selection).Contains("SR_ATLAS"             ) )zsyst = 0.10;

		}else if( metcut.at(bini+1)-1 < 300 ){
		  if( TString(selection).Contains("central_twojets"      ) )zsyst = 0.10;
		  if( TString(selection).Contains("central_withb_twojets") )zsyst = 0.25;
		  if( TString(selection).Contains("central_with2_twojets") )zsyst = 0.35;
		  if( TString(selection).Contains("forward_twojets"      ) )zsyst = 0.15;
		  if( TString(selection).Contains("forward_withb_twojets") )zsyst = 0.30;
		  if( TString(selection).Contains("forward_with2_twojets") )zsyst = 0.80;
		  if( TString(selection).Contains("central_3jets_inclusive"      ) )zsyst = 0.05;
		  if( TString(selection).Contains("central_withb_3jets_inclusive") )zsyst = 0.10;
		  if( TString(selection).Contains("central_with2_3jets_inclusive") )zsyst = 0.15;
		  if( TString(selection).Contains("forward_3jets_inclusive"      ) )zsyst = 0.10;
		  if( TString(selection).Contains("forward_withb_3jets_inclusive") )zsyst = 0.40;
		  if( TString(selection).Contains("forward_with2_3jets_inclusive") )zsyst = 0.60;
		  if( TString(selection).Contains("bveto_SRA"            ) )zsyst = 0.20;
		  if( TString(selection).Contains("withb_SRA"            ) )zsyst = 0.25;
		  if( TString(selection).Contains("bveto_SRB"            ) )zsyst = 0.20;
		  if( TString(selection).Contains("withb_SRB"            ) )zsyst = 0.70;
		  if( TString(selection).Contains("SR_ATLAS"             ) )zsyst = 0.10;

		}

		// cout<<"zsyts for: "<<metcut.at(bini+1)<<" | "<< zsyst<<endl;

		
	  }

	  if( bini == metcut.size()-1 ){
		val_data .at(bini) = h_data ->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_data .at(bini));
		val_zjets.at(bini) = h_zjets->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_zjets.at(bini));
		val_fsbkg.at(bini) = h_ttbar->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_fsbkg.at(bini));
		val_ttvbg.at(bini) = h_ttv  ->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_ttvbg.at(bini));
		val_vvvbg.at(bini) = h_vvv  ->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_vvvbg.at(bini));
		val_vvbkg.at(bini) = h_wz   ->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_vvbkg.at(bini));
		val_zzbkg.at(bini) = h_zz   ->IntegralAndError( metcut.at(bini)+1, metcut.at(bini+1), err_zzbkg.at(bini));
	  }

	  val_vvbkg.at(bini) += val_zzbkg.at(bini);
	  err_vvbkg.at(bini) = sqrt( pow(err_zzbkg.at(bini),2) + pow(err_vvbkg.at(bini),2));
		
	  if( applysysts ){
		err_zjets.at(bini) = sqrt( pow( err_zjets.at(bini), 2 ) + pow( val_zjets.at(bini)*zsyst, 2 ) );
		// err_fsbkg.at(bini) = sqrt( pow( err_fsbkg.at(bini), 2 ) + pow( val_fsbkg.at(bini)*.20, 2 ) );
		  
		err_ttvbg.at(bini) = sqrt( pow( err_ttvbg.at(bini), 2 ) + pow( val_ttvbg.at(bini)*.50, 2 ) );
		err_vvvbg.at(bini) = sqrt( pow( err_vvvbg.at(bini), 2 ) + pow( val_vvvbg.at(bini)*.50, 2 ) );
		err_vvbkg.at(bini) = sqrt( pow( err_vvbkg.at(bini), 2 ) + pow( val_vvbkg.at(bini)*.50, 2 ) );
	  }

	}

	
	// float norm_factor = (val_data.at(0) -
	// 					   val_fsbkg.at(0)
	// 					   // - val_vvbkg.at(0)
	// 					   // - val_other.at(0))
	// 					   )/(val_zjets.at(0));
	// for( size_t bini = 0; bini < metcut.size(); bini++ ){
	// 	val_zjets.at(bini) *= norm_factor;
	// 	err_zjets.at(bini) *= norm_factor;
	// }
  
	for( size_t bini = 0; bini < metcut.size(); bini++ ){
	  if( val_zjets.at(bini) < 0 ) val_zjets.at(bini) = 0.0;
	  
	  val_allbg.at(bini) =
		val_zjets.at(bini) +
		val_fsbkg.at(bini) +
		val_ttvbg.at(bini) +
		val_vvvbg.at(bini) +
		val_vvbkg.at(bini)
		;
	  err_allbg.at(bini) = sqrt( pow(err_zjets.at(bini), 2) +
								 pow(err_fsbkg.at(bini), 2) +
								 pow(err_ttvbg.at(bini), 2) +
								 pow(err_vvvbg.at(bini), 2) +
								 pow(err_vvbkg.at(bini), 2)
								 );
	  val_ratio.at(bini) = val_data .at(bini)/val_allbg.at(bini);
	  err_ratio.at(bini) = err_mult( val_data .at(bini), val_allbg.at(bini),
									 err_data .at(bini), err_allbg.at(bini), val_data .at(bini)/val_allbg.at(bini));
	}
  
	cout<<"$\\mathrm{E_{T}^{miss} [GeV]}$ &";
	for( size_t bini = 0; bini < metcut.size()-2; bini++ ){
	  if( metcut.at(bini) == -1 ) continue;
	  cout<<Form("%.0f - %.0f & ", metcut.at(bini), metcut.at(bini+1) );
	}
	cout<<Form("$\\geq$ %.0f \\\\", metcut.at(metcut.size()-2) );
	cout<<endl;

	cout<<"\\hline "<<endl;
	cout<<"Z+jets& ";
	for( size_t bini = 0; bini < val_zjets.size()-1; bini++ ){
	  if( metcut.at(bini) == -1 ) continue;
	  if( bini < val_zjets.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f & ", val_zjets.at(bini), err_zjets.at(bini));
	  if( bini == val_zjets.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_zjets.at(bini), err_zjets.at(bini));
	}
	cout<<endl;

	cout<<"FS bkg& ";
	for( size_t bini = 0; bini < val_fsbkg.size()-1; bini++ ){
	  if( metcut.at(bini) == -1 ) continue;
	  if( bini < val_fsbkg.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f & ", val_fsbkg.at(bini), err_fsbkg.at(bini));
	  if( bini == val_fsbkg.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_fsbkg.at(bini), err_fsbkg.at(bini));
	}
	cout<<endl;

  	cout<<"WZ + ZZ bkg& ";
  	for( size_t bini = 0; bini < val_vvbkg.size()-1; bini++ ){
	  if( metcut.at(bini) == -1 ) continue;
  	  if( bini < val_vvbkg.size()-2 )
  		cout<<Form(" %.1f $\\pm$ %.1f & ", val_vvbkg.at(bini), err_vvbkg.at(bini));
  	  if( bini == val_vvbkg.size()-2 )
  		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_vvbkg.at(bini), err_vvbkg.at(bini));
  	}
  	cout<<endl;

  	cout<<"ttv SM BG& ";
  	for( size_t bini = 0; bini < val_ttvbg.size()-1; bini++ ){
	  if( metcut.at(bini) == -1 ) continue;
  	  if( bini < val_ttvbg.size()-2 )
  		cout<<Form(" %.1f $\\pm$ %.1f & ", val_ttvbg.at(bini), err_ttvbg.at(bini));
  	  if( bini == val_ttvbg.size()-2 )
  		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_ttvbg.at(bini), err_ttvbg.at(bini));
  	}
  	cout<<endl;

  	cout<<"vvv SM BG& ";
  	for( size_t bini = 0; bini < val_vvvbg.size()-1; bini++ ){
	  if( metcut.at(bini) == -1 ) continue;
  	  if( bini < val_vvvbg.size()-2 )
  		cout<<Form(" %.1f $\\pm$ %.1f & ", val_vvvbg.at(bini), err_vvvbg.at(bini));
  	  if( bini == val_vvvbg.size()-2 )
  		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_vvvbg.at(bini), err_vvvbg.at(bini));
  	}
  	cout<<endl;

	// }
  
	cout<<"\\hline "<<endl;
	cout<<"total BG& ";
	for( size_t bini = 0; bini < val_allbg.size()-1; bini++ ){
	  if( metcut.at(bini) == -1 ) continue;
	  if( bini < val_allbg.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f & ", val_allbg.at(bini), err_allbg.at(bini));
	  if( bini == val_allbg.size()-2 )
		cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_allbg.at(bini), err_allbg.at(bini));
	}
	cout<<endl;

	cout<<"\\hline "<<endl;
	cout<<"Data& ";
	for( size_t bini = 0; bini < val_data.size()-1; bini++ ){
	  if( metcut.at(bini) == -1 ) continue;
	  if( bini < val_data.size()-2 )
		// cout<<Form(" %.1f $\\pm$ %.1f & ", val_data.at(bini), err_data.at(bini)); // with errors
		cout<<Form(" %.0f & ", val_data.at(bini));
	  if( bini == val_data.size()-2 )
		// cout<<Form(" %.1f $\\pm$ %.1f \\\\ ", val_data.at(bini), err_data.at(bini));
		cout<<Form(" %.0f \\\\ ", val_data.at(bini));
	}
	cout<<endl;

	cout<<"\\hline "<<endl;
  
	cout<<"Data/BG& ";
	for( size_t bini = 0; bini < val_ratio.size()-1; bini++ ){
	  if( metcut.at(bini) == -1 ) continue;
	  if( bini < val_ratio.size()-2 )
		cout<<Form(" %.2f $\\pm$ %.2f & ", val_ratio.at(bini), err_ratio.at(bini));
	  if( bini == val_ratio.size()-2 )
		cout<<Form(" %.2f $\\pm$ %.2f \\\\ ", val_ratio.at(bini), err_ratio.at(bini));
	}
	cout<<endl;
  }
  
  //MAKE PLOTS
  float xmin = 20; float xmax = 200;
  float ymin = 1e-1; float ymax = 1e2;

  int rebin = 5;
  if( dilep == "em" ){
	xmax = 250;
  }
	
  if( variable == "mt3" ){
	xmin = 0;
	xmax = 150;
    // ymin = 0;
	rebin = 10;
  }
  if( TString(variable).Contains("MHT") ){
	xmin = 0;
	xmax = 250;
    // ymin = 0;
	rebin = 5;
  }
  if( TString(variable).Contains("mhtphi") ){
	// xmin = 0;
	// xmax = 250;
    // // ymin = 0;
	rebin = 5;
  }
  if( dilep == "em" ){
    rebin = 10;
	ymin = 1e0;
	if( TString(variable).Contains("met") ){
	  rebin = 20;
	}
  }
  if( variable == "nVert" ){
	xmin = 0;
	xmax = 50;
    ymax = 100;
    ymin = 0;
	rebin = 1;
  }

  if( TString(variable).Contains("met") ){
	if( dilep == "em" ) rebin = 10;
	else rebin = 5;
	  xmin = 00;
	  xmax = 200;
	  if( usefsbkg ){
		xmax = 250;
		rebin = 25;
	  }
	  else
		xmax = 200;
	  ymax = 5e1;
  }

  if( variable == "ht" || TString(variable).Contains("sumet") ){
	xmin = 40;
	xmax = 800;
    // ymax = 5e1;
	rebin = 25;
	if( variable == "nupfcands_30in_sumet" ){
	  xmin = 0;
	  xmax = 1000;
	  // ymax = 5e1;
	  rebin = 10;
	}
  }
  if( TString(variable).Contains("pt") && !TString(variable).Contains("met") ){
	xmin = 0;
	xmax = 200;
    // ymax = 5e1;
	rebin = 5;
  }
  if( variable == "nbjets" || variable == "njets" || variable == "nFWjets" ){
	xmin = 0;
	xmax = 10;
    ymax = 5e1;
	rebin = 1;
  }
  if( TString(variable).Contains("phi") || variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
	xmin = -3.2;
	xmax = 3.2;
	ymax = 1000;
	rebin = 5;
  }
  if( TString(variable).Contains("metx") || TString(variable).Contains("mety") ){
	xmin = -150;
	xmax =  150;
	rebin = 1;
  }
  if( variable == "pfcandmet_0030_pt" ){
	xmin = 0;
	xmax = 200;
    // ymax = 5e1;
	rebin = 5;
  }
  
  h_data->Rebin(rebin);
  h_zjets->Rebin(rebin);
  h_ttbar->Rebin(rebin);
  h_st->Rebin(rebin);
  h_wz->Rebin(rebin);
  h_zz->Rebin(rebin);
  h_ww->Rebin(rebin);
  h_vvv->Rebin(rebin);
  h_ttv->Rebin(rebin);
  // h_vvbkg->Rebin(rebin);
  // h_other->Rebin(rebin);

  TCanvas * c1 = new TCanvas("c1","");
  c1->cd();
  // c1->SetLogy();

  TPad *pad = new TPad( "p_main", "p_main", 0.0, 0.3, 1.0, 1.0);
  pad->SetBottomMargin(0.05);
  pad->SetRightMargin(0.07);
  pad->SetTopMargin(0.08);
  pad->SetLeftMargin(0.18);
  pad->Draw();
  pad->cd();
  if( !(TString(variable).Contains("phi") || variable == "nVert" || variable == "mhtphi" || dilep == "em" || variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir") ){
	pad->SetLogy();
  }
  
  h_data->SetLineWidth(2);

  h_zjets->SetFillColor(kBlue);
  h_ttbar->SetFillColor(kYellow+1);
  h_zz->SetFillColor(kOrange-3);
  h_wz->SetFillColor(kRed);
  h_st->SetFillColor(kAzure-2);
  h_ww->SetFillColor(kGreen+1);
  h_ttv->SetFillColor(kViolet+2);
  h_vvv->SetFillColor(kMagenta);
  // h_vvbkg->SetFillColor(kRed);
  // h_other->SetFillColor(kMagenta);

  h_zjets->SetFillStyle(1001);
  h_ttbar->SetFillStyle(1001);
  h_st->SetFillStyle(1001);
  h_wz->SetFillStyle(1001);
  h_zz->SetFillStyle(1001);
  h_ww->SetFillStyle(1001);
  h_vvv->SetFillStyle(1001);
  h_ttv->SetFillStyle(1001);
  // h_vvbkg->SetFillStyle(1001);
  // h_other->SetFillStyle(1001);

  float lomll = 60;
  float himll = 120;
  
  float norm_factor =   h_data->Integral(h_data->FindBin(lomll),h_data->FindBin(himll)-1)/
	(h_zjets->Integral(h_zjets->FindBin(lomll),h_zjets->FindBin(himll)-1) +
	 h_ttbar->Integral(h_ttbar->FindBin(lomll),h_ttbar->FindBin(himll)-1) +
	 h_st->Integral(h_st->FindBin(lomll),h_st->FindBin(himll)-1) +
	 h_wz->Integral(h_wz->FindBin(lomll),h_wz->FindBin(himll)-1) +
	 h_zz->Integral(h_zz->FindBin(lomll),h_zz->FindBin(himll)-1) +
	 h_ww->Integral(h_ww->FindBin(lomll),h_ww->FindBin(himll)-1) +
	 h_vvv->Integral(h_vvv->FindBin(lomll),h_vvv->FindBin(himll)-1) + 
	 h_ttv->Integral(h_ttv->FindBin(lomll),h_ttv->FindBin(himll)-1) 
	 );
  cout<<"Norm factor for Z+jets: "<<norm_factor<<endl;

  if( variable != "mll" ){
	if( region == "passtrig" ){
	  if( dilep == "ll" ) norm_factor = 2.71145;
	  if( dilep == "ee" ) norm_factor = 4.19728;
	  if( dilep == "mm" ) norm_factor = 1.52758;
	}
	if( region == "inclusive" ){
	  if( dilep == "ll" ) norm_factor = 6.49903;
	  if( dilep == "ee" ) norm_factor = 6.11659;
	  if( dilep == "mm" ) norm_factor = 6.81433;
	}
  }

  norm_factor = 1;
  
  h_zjets->Scale(norm_factor);
  h_ttbar->Scale(norm_factor);
  h_st->Scale(norm_factor);
  h_wz->Scale(norm_factor);
  h_zz->Scale(norm_factor);
  h_ww->Scale(norm_factor);
  h_vvv->Scale(norm_factor);
  h_ttv->Scale(norm_factor);
  
  updateoverflow( h_data , xmax );
  updateoverflow( h_zjets, xmax );
  updateoverflow( h_ttbar, xmax );
  updateoverflow( h_st, xmax );
  updateoverflow( h_wz, xmax );
  updateoverflow( h_zz, xmax );
  updateoverflow( h_ww, xmax );
  updateoverflow( h_ttv, xmax );
  updateoverflow( h_vvv, xmax );
  // updateoverflow( h_vvbkg, xmax );
  // updateoverflow( h_other, xmax );

  THStack * stack = new THStack("stack","");

  // stack->Add(h_other);
  // stack->Add(h_vvbkg);

  stack->Add(h_ttv);
  stack->Add(h_vvv);
  if( usefsbkg ){
	stack->Add(h_ttbar);
  }
  else{
	stack->Add(h_ww);
	stack->Add(h_st);
	stack->Add(h_ttbar);
  }
  stack->Add(h_wz);
  stack->Add(h_zz);
  if( usetemplates ){
	stack->Add(h_zjets);
  }
  else{
	stack->Add(h_zjets);
  }

  
  h_data->GetXaxis()->SetLabelSize(0);
  h_data->GetYaxis()->SetLabelSize(0.05);
  h_data->GetYaxis()->SetTitleOffset(1.5);
  h_data->GetYaxis()->SetTitleSize(0.05);
  h_data->GetYaxis()->SetTitle(Form("Events/%.0f GeV", (float)rebin));
  if( TString(variable).Contains("phi") || variable == "mhtphi" || dilep    == "em" || variable == "nVert" ||variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
	h_data->GetYaxis()->SetRangeUser(0, h_data->GetMaximum()*1.4 );  
	if( TString(variable).Contains("phi") )h_data->GetYaxis()->SetTitle(Form("Events/%.2f", (2*3.14159)/200*(float)rebin));
  }
  else{
	h_data->GetYaxis()->SetRangeUser(ymin*luminosity, h_data->GetMaximum() * ymax );
  }
  if( TString(variable).Contains("phi") || variable == "metphi" || variable == "metphi20" || variable == "metphi40" || variable == "metphi60" || variable == "metphir" ){
	h_data->GetYaxis()->SetRangeUser(0, h_data->GetMaximum()*1.4 );  
  }

if( TString(variable).Contains("njets") )h_data->GetYaxis()->SetTitle(Form("Events", (2*3.14159)/200*(float)rebin));
  
  h_data->GetXaxis()->SetRangeUser(xmin, xmax);
  h_data->SetMarkerStyle(8);
  h_data->SetMarkerSize(0.75);

  h_data->Draw("e1");
  stack->Draw("samehist");
  h_data->Draw("samex0e1");
  
  pad->RedrawAxis();

  TLegend *l1 = new TLegend(0.6, 0.6, 0.9, 0.85);    
  l1->SetLineColor(kWhite);    
  l1->SetShadowColor(kWhite);    
  l1->SetFillColor(kWhite);    
  l1->AddEntry( h_data    , "data"          , "lpe");
  if( usetemplates ){
	l1->AddEntry( h_zjets , "MET Templates" , "f");
  }else{
	l1->AddEntry( h_zjets , "Z+jets MC" , "f");
  }
  l1->AddEntry( h_zz    , "ZZ MC"     , "f");
  l1->AddEntry( h_wz    , "WZ MC"     , "f");
  if( usefsbkg ){
  	l1->AddEntry( h_ttbar , "FS Bkg"       , "f");
  }else{
	l1->AddEntry( h_ttbar , "t#bar{t} MC"       , "f");
	l1->AddEntry( h_st , "Single-top MC"       , "f");
	l1->AddEntry( h_ww , "WW MC"       , "f");
  }
  l1->AddEntry( h_vvv , "VVV MC"       , "f");
  l1->AddEntry( h_ttv , "t#bar{t}V MC"       , "f");
  l1->Draw("same");
  
  c1->cd();
	
  TPad *rat_pad = new TPad( "p_main", "p_main", 0.0, 0.0, 1.0, 0.3);
  rat_pad->SetBottomMargin(0.36);
  rat_pad->SetRightMargin(0.07);
  rat_pad->SetTopMargin(0.07);
  rat_pad->SetLeftMargin(0.18);
  rat_pad->Draw();
  rat_pad->cd();
  rat_pad->SetGridy();

  TH1F* h_rat = (TH1F*)h_data  -> Clone("h_rat");
  TH1F* h_den = (TH1F*)h_zjets -> Clone("h_den");
  if( usefsbkg ){
	h_den->Add(h_ttbar);
  }else{
	h_den->Add(h_ttbar);
	h_den->Add(h_st);
	h_den->Add(h_ww);
  }
  h_den->Add(h_zz);
  h_den->Add(h_wz);
  h_den->Add(h_vvv);
  h_den->Add(h_ttv);
  // h_den->Add(h_other);
  // h_den->Add(h_vvbkg);

  h_rat->Divide(h_den);

  // h_rat->GetYaxis()->SetRangeUser(0.6,1.4);
  // if( TString(variable).Contains("met") ){
  h_rat->GetYaxis()->SetRangeUser(0.01,2.0);
  // }

  h_rat->GetYaxis()->SetLabelSize(0.12);
  h_rat->GetXaxis()->SetLabelSize(0.12);
  h_rat->GetYaxis()->SetNdivisions(5);

  h_rat->GetYaxis()->SetTitle("#frac{Data}{Prediction}");
  h_rat->GetYaxis()->SetTitleSize(0.12);
  h_rat->GetYaxis()->SetTitleOffset(0.5);
  h_rat->GetYaxis()->CenterTitle();
  // cout<<h_rat->GetYaxis()->GetTitleSize()<<endl;

  if( variable == "nVert"               ) h_rat->GetXaxis()->SetTitle("N_{vtx}");
  if( TString(variable).Contains("met") ) h_rat->GetXaxis()->SetTitle("E_{T}^{miss} GeV");
  if( TString(variable).Contains("sumet") ) h_rat->GetXaxis()->SetTitle("sum E_{T} GeV");
  if( TString(variable).Contains("MHT") ) h_rat->GetXaxis()->SetTitle("H_{T}^{miss} GeV");
  if( TString(variable).Contains("mhtphi") ) h_rat->GetXaxis()->SetTitle("H_{T} Phi");
  if( variable == "ht"                  ) h_rat->GetXaxis()->SetTitle("H_{T} GeV");
  if( TString(variable).Contains("pt")  ) h_rat->GetXaxis()->SetTitle("p_{T} GeV");
  if( variable == "njets"               ) h_rat->GetXaxis()->SetTitle("N_{jets}");  
  if( variable == "nbjets"               ) h_rat->GetXaxis()->SetTitle("N_{b-jets}");  
  if( variable == "mll"                 ) h_rat->GetXaxis()->SetTitle("M_{\\ell\\ell} GeV");
  if( TString(variable).Contains("phi") ) h_rat->GetXaxis()->SetTitle("E_{T}^{miss} #phi");
  if( TString(variable).Contains("_pt") ) h_rat->GetXaxis()->SetTitle("E_{T}^{miss} [GeV]");
  h_rat->GetXaxis()->SetTitleOffset(0.9);
  h_rat->GetXaxis()->SetTitleSize(0.15);

  h_rat->SetMarkerStyle(8);
  h_rat->SetMarkerSize(0.75);

  h_rat->Draw("e0x0");
  h_rat->Draw("e1x0same");

  TLine * xaxis = new TLine(xmin,1,xmax,1);
  xaxis->SetLineWidth(2);
  xaxis->Draw("same");  
 
  // if( luminosity*norm_factor < 0.0161 ) drawCMSLatex( c1, 0.0161 );
  // else                                  drawCMSLatex( c1, luminosity*norm_factor );

  drawCMSLatex( c1, luminosity*norm_factor );

  if( usefsbkg ) {
	c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_%s_%s_signalregion%s_fsbkg_%s.png", iter.c_str(), variable.c_str(), dilep.c_str(), selection.c_str(), region.c_str() ));
	c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_%s_%s_signalregion%s_fsbkg_%s.pdf", iter.c_str(), variable.c_str(), dilep.c_str(), selection.c_str(), region.c_str() ));
  }else{
	c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_%s_%s_signalregion%s_%s.png", iter.c_str(), variable.c_str(), dilep.c_str(), selection.c_str(), region.c_str() ));
	c1->SaveAs(Form("../output/ZMET2015/%s/plots/Closure/h_%s_%s_signalregion%s_%s.pdf", iter.c_str(), variable.c_str(), dilep.c_str(), selection.c_str(), region.c_str() ));
  }
  
  return;
}
