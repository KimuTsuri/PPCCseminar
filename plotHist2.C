{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(kFALSE);

  TCanvas* c1 = new TCanvas("c1", "", 20, 20, 1600, 400);
  c1->Divide(3,1);

  c1->cd(1);

  TFile *f_box_si = new TFile("Box_Si.root");
  TTree* t_box_si = (TTree*)f_box_si->Get("B1");
  TH1F *h_box_si = new TH1F("h1","", 100, 0.0, 3.5);
  h_box_si->SetTitle("Histogram of Box;Energy Deposit / MeV;Counts;");

  h_box_si->SetLineColor(kRed-9);
  h_box_si->SetFillStyle(3003);

  // h_box_si->SetXTitle("Energy Deposit / MeV");
  //h_box_si->SetTitleSize(0.04,"x");
  //h_box_si->SetLabelSize(0.03,"x");

  //h_box_si->SetYTitle("Counts");
  //h_box_si->SetTitleSize(0.04,"y");
  //h_box_si->SetLabelSize(0.03,"y");

  t_box_si->Draw("B1>>h_box_si");

  TFile *f_box_pb = new TFile("Box_Pb.root");
  TH1F* h_box_pb = (TH1F*)f_box_pb->Get("Edep");
  h_box_pb->SetLineColor(kBlue-9);
  h_box_si->SetFillStyle(3003);

  h_box_pb->Draw("same");

  TLegend *l_box= new TLegend(1.0,1.5,0.48,0.9);
  //  l_box->SetHeader("The Legend Title","C"); // option "C" allows to center the header
  l_box->AddEntry(h_box_si,"Si","l");
  l_box->AddEntry(h_box_pb,"Pb","l");
  l_box->SetFillStyle(0);
  l_box->Draw();

  c1->cd(2);

  TFile *f_board_si = new TFile("Board_Si.root");
  TH1F* h_board_si = (TH1F*)f_board_si->Get("Edep");
  h_board_si->SetLineColor(kRed-9);

  h_board_si->SetXTitle("Energy Deposit / MeV");
  h_board_si->SetTitleSize(0.04,"x");
  h_board_si->SetLabelSize(0.04,"x");

  h_board_si->SetYTitle("Counts");
  h_board_si->SetTitleSize(0.04,"y");
  h_board_si->SetLabelSize(0.04,"y");

  TFile *f_board_pb = new TFile("Board_Pb.root");
  TH1F* h_board_pb = (TH1F*)f_box_pb->Get("Edep");
  h_board_pb->SetLineColor(kBlue-9);

  h_board_pb->SetXTitle("Energy Deposit / MeV");
  h_board_pb->SetTitleSize(0.04,"x");
  h_board_pb->SetLabelSize(0.04,"x");

  h_board_pb->SetYTitle("Counts");
  h_board_pb->SetTitleSize(0.04,"y");
  h_board_pb->SetLabelSize(0.04,"y");

  h_board_si->Draw();
  h_board_pb->Draw("same");

  c1->cd(3);

  TFile *f_cone_si = new TFile("Cone_Si.root");
  TH1F* h_cone_si = (TH1F*)f_cone_si->Get("Edep");
  h_cone_si->SetLineColor(kRed-9);

  h_cone_si->SetXTitle("Energy Deposit / MeV");
  h_cone_si->SetTitleSize(0.04,"x");
  h_cone_si->SetLabelSize(0.04,"x");

  h_cone_si->SetYTitle("Counts");
  h_cone_si->SetTitleSize(0.04,"y");
  h_cone_si->SetLabelSize(0.04,"y");

  TFile *f_cone_pb = new TFile("Cone_Pb.root");
  TH1F* h_cone_pb = (TH1F*)f_cone_pb->Get("Edep");
  h_cone_pb->SetLineColor(kBlue-9);

  h_cone_pb->SetXTitle("Energy Deposit / MeV");
  h_cone_pb->SetTitleSize(0.04,"x");
  h_cone_pb->SetLabelSize(0.04,"x");

  h_cone_pb->SetYTitle("Counts");
  h_cone_pb->SetTitleSize(0.04,"y");
  h_cone_pb->SetLabelSize(0.04,"y");


  h_cone_si->Draw();
  h_cone_pb->Draw("same");
}
