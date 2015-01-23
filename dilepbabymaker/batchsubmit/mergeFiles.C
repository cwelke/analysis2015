#include "TChain.h"

void mergeTriboson() {
  //  gSystem->Load("../libMiniFWLite.so");
  TChain *chain = new TChain("t");
  chain->SetMaxTreeSize(5000000000LL); //default is 100000000000LL

  chain->Add("zzzjets*.root");
  chain->Add("wzzjets*.root");
  chain->Add("wwzjets*.root");
  chain->Add("wwwjets*.root");
  chain->Add("wwgjets*.root");
  chain->Add("tbz*.root");

  chain->Merge("triboson.root", "fast");

}

void mergettV() {
  //  gSystem->Load("../libMiniFWLite.so");
  TChain *chain = new TChain("t");
  chain->SetMaxTreeSize(5000000000LL); //default is 100000000000LL

  chain->Add("ttzjets*.root");
  chain->Add("ttwjets*.root");
  chain->Add("ttgjets*.root");
  chain->Add("ttwwjets*.root");

  chain->Merge("ttV.root", "fast");

}

void mergeMuQCD() {
  //  gSystem->Load("../libMiniFWLite.so");
  TChain *chain = new TChain("t");
  chain->SetMaxTreeSize(5000000000LL); //default is 100000000000LL

  chain->Add("MuQCD15to20*.root");           
  chain->Add("MuQCD20to30*.root");           
  chain->Add("MuQCD30to50*.root");
  chain->Add("MuQCD50to80*.root");
  chain->Add("MuQCD80to120*.root");

  chain->Merge("qcd.root", "fast");

}

void mergeSingleMuData() {
  //  gSystem->Load("../libMiniFWLite.so");
  TChain *chain = new TChain("t");
  chain->SetMaxTreeSize(5000000000LL); //default is 100000000000LL
  chain->Add("SingleMu2012*.root");

  chain->Merge("data_muo.root", "fast");

}

void mergeDoubleMuData() {
  //  gSystem->Load("../libMiniFWLite.so");
  TChain *chain = new TChain("t");
  chain->SetMaxTreeSize(5000000000LL); //default is 100000000000LL
  chain->Add("DoubleMu2012*.root");

  chain->Merge("data_dimu.root", "fast");

}

void mergeDoubleElectronData() {
  //  gSystem->Load("../libMiniFWLite.so");
  TChain *chain = new TChain("t");
  chain->SetMaxTreeSize(5000000000LL); //default is 100000000000LL
  chain->Add("DoubleElectron2012*.root");

  chain->Merge("data_diel.root", "fast");

}

void mergeMuEGData() {
  //  gSystem->Load("../libMiniFWLite.so");
  TChain *chain = new TChain("t");
  chain->SetMaxTreeSize(5000000000LL); //default is 100000000000LL
  chain->Add("MuEG2012*.root");

  chain->Merge("data_mueg.root", "fast");

}

void mergeSingleElectronData() {
  //  gSystem->Load("../libMiniFWLite.so");
  TChain *chain = new TChain("t");
  chain->SetMaxTreeSize(5000000000LL); //default is 100000000000LL
  chain->Add("SingleElectron2012*.root");

  chain->Merge("data_ele.root", "fast");

}

void mergeSingleTop() {
  //  gSystem->Load("../libMiniFWLite.so");
  TChain *chain = new TChain("t");
  chain->SetMaxTreeSize(5000000000LL); //default is 100000000000LL

  chain->Add("tschan*.root");
  chain->Add("tbarschan*.root");
  chain->Add("ttchan*.root");
  chain->Add("tbartchan*.root");
  chain->Add("ttWchan*.root");
  chain->Add("tbartWchan*.root");

  chain->Merge("tW.root", "fast");

}

void mergeDiboson() {
  //  gSystem->Load("../libMiniFWLite.so");
  TChain *chain = new TChain("t");
  chain->SetMaxTreeSize(5000000000LL); //default is 100000000000LL

  chain->Add("ww2l2nujets*.root");
  chain->Add("zz4ljets*.root");
  chain->Add("zz2l2nujets*.root");
  chain->Add("zz2l2qjets*.root");
  chain->Add("wz3lnujets*.root");
  chain->Add("wz2l2qjets*.root");
  chain->Add("wglnu2ejets*.root");
  chain->Add("wglnu2mujets*.root");
  chain->Add("wglnu2taujets*.root");

  chain->Merge("diboson.root", "fast");

}

