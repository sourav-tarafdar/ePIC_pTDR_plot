#include "TString.h"
#include "TDatime.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TCanvas.h"

void plot_rad_MPGD(){

 
  
  TFile *f_rad = new TFile("bryceCanyon_radDose_pythia_crossing_angle_10x275_central_7_6_2023.root");
  
  TH2F *charged_hadron_dose = (TH2F*)f_rad->Get("charged_hadron_dose")->Clone("charged_hadron_dose");
  
  TH2F *electromagnetic_dose = (TH2F*)f_rad->Get("electromagnetic_dose")->Clone("electromagnetic_dose");
  

  TLine *BOT = new TLine(-164.5, 72.5, 174.5, 72.5);
  BOT->SetLineWidth(2);
  BOT->SetLineColor(2);

  TLine *MMG = new TLine(-71.5, 55, 143, 55);
  MMG->SetLineWidth(2);
  MMG->SetLineColor(2);

  TLine *L1 = new TLine(-110, 4.6, -110, 50);
  L1->SetLineWidth(2);
  L1->SetLineColor(2);

  TLine *L2 = new TLine(-120, 4.6, -120, 50);
  L2->SetLineWidth(2);
  L2->SetLineColor(2);

  TLine *H1 = new TLine(161, 9, 161, 50);
  H1->SetLineWidth(2);
  H1->SetLineColor(2);

  TLine *H2 = new TLine(148, 9, 148, 50);
  H2->SetLineWidth(2);
  H2->SetLineColor(2);

  
  
  TCanvas *c1 = new TCanvas("c1","c1", 800, 600);
  c1->cd();
  c1->SetLogz();
  //gStyle->SetPalette(1);
  charged_hadron_dose->SetTitle("10x275 GeV e+p, top luminosity, 1 run period (~ 6 months)");
  charged_hadron_dose->GetYaxis()->SetRangeUser(0, 100);
  charged_hadron_dose->Draw("colz");
  gPad->SetRightMargin(0.16);
  BOT->Draw("same");
  MMG->Draw("same");
  L1->Draw("same");
  L2->Draw("same");
  H1->Draw("same");
  H2->Draw("same");
  gPad->Update();
  
  TPaletteAxis *palette = (TPaletteAxis*)charged_hadron_dose->GetListOfFunctions()->FindObject("palette");
  palette->SetX1NDC(0.845);
  palette->SetX2NDC(0.89);
  palette->SetY1NDC(0.155);
  palette->SetY2NDC(0.95);
  
  TLatex *l1 = new TLatex();
  l1->SetTextSize(0.04);
  l1->SetTextAlign(13);
  l1->DrawLatex(-200, 90, "Hadronic Accumulated Dose");
  

  TCanvas *c2 = new TCanvas("c2","c2", 800, 600);
  c2->cd();
  c2->SetLogz();
  electromagnetic_dose->SetTitle("10x275 GeV e+p, top luminosity, 1 run period (~ 6 months)");
  electromagnetic_dose->GetYaxis()->SetRangeUser(0, 100);
  electromagnetic_dose->Draw("colz");
  gPad->SetRightMargin(0.16);
  BOT->Draw("same");
  MMG->Draw("same");
  L1->Draw("same");
  L2->Draw("same");
  H1->Draw("same");
  H2->Draw("same");
  
  TLatex *l2 = new TLatex();
  l2->SetTextSize(0.04);
  l2->SetTextAlign(13);
  l2->DrawLatex(-200, 90, "EM Accumulated Dose");

  
  
}


