{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(kFALSE);
  gStyle->SetLabelFont(42,"XYZ");
  gStyle->SetLabelFont(42,"");
  gStyle->SetTitleFont(42,"");
  gStyle->SetLegendFont(42);

  TCanvas* c1 = new TCanvas("c1", "", 20, 20, 600, 400);

  TH2F *h = new TH2F("name","Efficiency of thicknes dependence; Thickness; Efficiency"
		      , 100, 0.0, 2.1, 100, 0., 0.005);

  stringstream ss;

 for(int i=0; i<19; i++)
    {
      ss.str("");
      ss.clear(stringstream::goodbit);
      ss<<i;
      string file = "thickness_" + ss.str() + ".root";
      TFile *f = TFile::Open(file.c_str());
      
      int event = B1->GetEntries();
      double E, efficiency, sum_efficiency;
      double Eall = 3.0;

      cout << "file number : " << i << endl;

      for(int n=0; n<event; n++)
	{
	  B1->GetEntry(n);
	  B1->SetBranchAddress("Edep", &E);
	  efficiency = E/Eall;
	  sum_efficiency = efficiency++;
	}
      double x, y;
      double thickness = 0.1;

      x += thickness;
      y  = sum_efficiency / event;

      h -> Fill(x,y);      
      
      cout << "x : " << x << endl;
      cout << "y : " << y << endl;
      cout << "---------------------" << endl;
      f -> Close();
    }
 h->SetMakerSize(5);
 h->Draw();
 c1->SaveAs("RsltThickness.png");
}
