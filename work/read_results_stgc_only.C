Double_t gausFunc(Double_t *x, Double_t *par)
{
  Double_t fun = (1./TMath::Sqrt(2*TMath::Pi()))*(0.01/par[2])*par[0]*exp(-pow(x[0]-par[1], 2)/2./(par[2]*par[2]));
  return fun;
}



void read_results_stgc_only(){

  gStyle->SetTitleW(0.5); //title width
  gStyle->SetTitleH(0.11); //title height
  
  gStyle->SetTitleFontSize(0.03);
  gStyle->SetTitleOffset(1);

  TFile *file = new TFile("results_r0p01.root");
  //results_stgc_only.root");//path for root file

  //  file->ls();

  //extract histograms from root files
  
  TH1F *EffVsMcPt_4hits = (TH1F*)file->Get("EffVsMcPt_4hits");
  TH1F *EffVsMcEta_4hits = (TH1F*)file->Get("EffVsMcEta_4hits");
  TH1F *EffVsMcPhi_4hits = (TH1F*)file->Get("EffVsMcPhi_4hits");
  TH1F *AllQuality = (TH1F*)file->Get("AllQuality");
  TH1F *DurationPerEvent = (TH1F*)file->Get("DurationPerEvent");
  TH1F *InvPtRes = (TH1F*)file->Get("InvPtRes");
  TH1F *PtRes = (TH1F*)file->Get("PtRes");
  
  
  TCanvas *can = new TCanvas("can","can",700,800);
  can->cd();
  EffVsMcPt_4hits->Draw();
  EffVsMcPt_4hits->GetYaxis()->SetTitle("Efficiency");
  EffVsMcPt_4hits->GetYaxis()->SetTitleOffset(1.1);
  EffVsMcPt_4hits->GetYaxis()->SetLabelOffset(0.005);
  EffVsMcPt_4hits->GetYaxis()->SetLabelSize(0.028);
  EffVsMcPt_4hits->GetYaxis()->CenterTitle();
  EffVsMcPt_4hits->GetXaxis()->SetRangeUser(0,7);
  EffVsMcPt_4hits->GetYaxis()->SetRangeUser(0,1);
  EffVsMcPt_4hits->GetYaxis()->SetTickSize(0.016);
  EffVsMcPt_4hits->GetYaxis()->SetTitleFont(42);
  EffVsMcPt_4hits->GetYaxis()->SetLabelFont(42);
  EffVsMcPt_4hits->GetYaxis()->SetTitleSize(0.04);
  EffVsMcPt_4hits->GetXaxis()->SetTitleOffset(1.0);
  EffVsMcPt_4hits->GetXaxis()->SetLabelOffset(0.005);
  EffVsMcPt_4hits->GetXaxis()->SetLabelSize(0.028);
  EffVsMcPt_4hits->GetXaxis()->SetTitleFont(42);
  EffVsMcPt_4hits->GetXaxis()->SetLabelFont(42);
  EffVsMcPt_4hits->GetXaxis()->CenterTitle();
  EffVsMcPt_4hits->GetXaxis()->SetTitleSize(0.04);
  EffVsMcPt_4hits->SetTitle("Efficiency vs p_{T} (4 sTGC hits)");
  can->SaveAs("effi_vs_Pt_4sTGC.pdf","pdf");
  
  TCanvas *can1 = new TCanvas("can1","can1",700,800);
  can1->cd();
  EffVsMcEta_4hits->Draw();
  EffVsMcEta_4hits->GetYaxis()->SetTitle("Efficiency");
  EffVsMcEta_4hits->GetYaxis()->SetTitleOffset(1.1);
  EffVsMcEta_4hits->GetYaxis()->SetLabelOffset(0.005);
  EffVsMcEta_4hits->GetYaxis()->SetLabelSize(0.028);
  EffVsMcEta_4hits->GetYaxis()->CenterTitle();
  EffVsMcEta_4hits->GetXaxis()->SetRangeUser(0,7);
  EffVsMcEta_4hits->GetYaxis()->SetRangeUser(0,1);
  EffVsMcEta_4hits->GetYaxis()->SetTickSize(0.016);
  EffVsMcEta_4hits->GetYaxis()->SetTitleFont(42);
  EffVsMcEta_4hits->GetYaxis()->SetLabelFont(42);
  EffVsMcEta_4hits->GetYaxis()->SetTitleSize(0.04);
  EffVsMcEta_4hits->GetXaxis()->SetTitleOffset(1.0);
  EffVsMcEta_4hits->GetXaxis()->SetLabelOffset(0.005);
  EffVsMcEta_4hits->GetXaxis()->SetLabelSize(0.028);
  EffVsMcEta_4hits->GetXaxis()->SetTitleFont(42);
  EffVsMcEta_4hits->GetXaxis()->SetLabelFont(42);
  EffVsMcEta_4hits->GetXaxis()->CenterTitle();
  EffVsMcEta_4hits->GetXaxis()->SetTitleSize(0.04);
  EffVsMcEta_4hits->SetTitle("Efficiency vs #eta (4 sTGC hits)");
  EffVsMcEta_4hits->GetXaxis()->SetTitle("#eta^{MC}");
  can1->SaveAs("effi_vs_Eta_4sTGC.pdf","pdf");

  TCanvas *can2 = new TCanvas("can2","can2",700,800);
  can2->cd();
  EffVsMcPhi_4hits->Draw();
  EffVsMcPhi_4hits->GetYaxis()->SetTitle("Efficiency");
  EffVsMcPhi_4hits->GetYaxis()->SetTitleOffset(1.1);
  EffVsMcPhi_4hits->GetYaxis()->SetLabelOffset(0.005);
  EffVsMcPhi_4hits->GetYaxis()->SetLabelSize(0.028);
  EffVsMcPhi_4hits->GetYaxis()->CenterTitle();
  EffVsMcPhi_4hits->GetYaxis()->SetTickSize(0.016);
  EffVsMcPhi_4hits->GetYaxis()->SetTitleFont(42);
  EffVsMcPhi_4hits->GetYaxis()->SetLabelFont(42);
  EffVsMcPhi_4hits->GetYaxis()->SetTitleSize(0.04);
  EffVsMcPhi_4hits->GetXaxis()->SetTitleOffset(1.0);
  EffVsMcPhi_4hits->GetXaxis()->SetLabelOffset(0.005);
  EffVsMcPhi_4hits->GetXaxis()->SetLabelSize(0.028);
  EffVsMcPhi_4hits->GetXaxis()->SetTitleFont(42);
  EffVsMcPhi_4hits->GetXaxis()->SetLabelFont(42);
  EffVsMcPhi_4hits->GetXaxis()->CenterTitle();
  EffVsMcPhi_4hits->GetXaxis()->SetTitleSize(0.04);
  EffVsMcPhi_4hits->SetTitle("Efficiency vs #phi (4 sTGC hits)");
  EffVsMcPhi_4hits->GetXaxis()->SetTitle("#phi^{MC}");
  can2->SaveAs("effi_vs_Phi_4sTGC.pdf","pdf");

  TCanvas *can3 = new TCanvas("can3","can3",700,800);
  can3->cd();
  can3->SetLogy();
  AllQuality->Draw("text same");
  AllQuality->GetYaxis()->SetTitleOffset(1.1);
  AllQuality->GetYaxis()->SetLabelOffset(0.005);
  AllQuality->GetYaxis()->SetLabelSize(0.028);
  AllQuality->GetYaxis()->CenterTitle();
  AllQuality->GetYaxis()->SetTickSize(0.016);
  AllQuality->GetYaxis()->SetTitleFont(42);
  AllQuality->GetYaxis()->SetLabelFont(42);
  AllQuality->GetYaxis()->SetTitleSize(0.04);
  AllQuality->GetXaxis()->SetTitleOffset(1.0);
  AllQuality->GetXaxis()->SetLabelOffset(0.005);
  AllQuality->GetXaxis()->SetLabelSize(0.028);
  AllQuality->GetXaxis()->SetTitleFont(42);
  AllQuality->GetXaxis()->SetLabelFont(42);
  AllQuality->GetXaxis()->CenterTitle();
  AllQuality->GetXaxis()->SetTitleSize(0.04);
  can3->SaveAs("TrackQuality_from_4sTGC.pdf","pdf");
  AllQuality->GetYaxis()->SetTitle("counts");


  TCanvas *can5 = new TCanvas("can5","can5",700,800);
  can5->cd();
  can5->SetLogy();
  DurationPerEvent->Draw();
  DurationPerEvent->GetYaxis()->SetTitleOffset(1.1);
  DurationPerEvent->GetYaxis()->SetLabelOffset(0.005);
  DurationPerEvent->GetYaxis()->SetLabelSize(0.028);
  DurationPerEvent->GetYaxis()->CenterTitle();
  DurationPerEvent->GetYaxis()->SetTickSize(0.016);
  DurationPerEvent->GetYaxis()->SetTitleFont(42);
  DurationPerEvent->GetYaxis()->SetLabelFont(42);
  DurationPerEvent->GetYaxis()->SetTitleSize(0.04);
  DurationPerEvent->GetXaxis()->SetTitleOffset(1.0);
  DurationPerEvent->GetXaxis()->SetLabelOffset(0.005);
  DurationPerEvent->GetXaxis()->SetLabelSize(0.028);
  DurationPerEvent->GetXaxis()->SetTitleFont(42);
  DurationPerEvent->GetXaxis()->SetLabelFont(42);
  DurationPerEvent->GetXaxis()->CenterTitle();
  DurationPerEvent->GetXaxis()->SetTitleSize(0.04);
  DurationPerEvent->GetXaxis()->SetRangeUser(0,200);
  DurationPerEvent->GetYaxis()->SetTitle("counts");
  can5->SaveAs("duration_per_event_4stgc.pdf","pdf");
  
  
  TCanvas *can6 = new TCanvas("can6","can6",700,800);
  can6->cd();
  InvPtRes->Draw();
  InvPtRes->GetYaxis()->SetTitleOffset(1.1);
  InvPtRes->GetYaxis()->SetLabelOffset(0.005);
  InvPtRes->GetYaxis()->SetLabelSize(0.028);
  InvPtRes->GetYaxis()->CenterTitle();
  InvPtRes->GetYaxis()->SetTickSize(0.016);
  InvPtRes->GetYaxis()->SetTitleFont(42);
  InvPtRes->GetYaxis()->SetLabelFont(42);
  InvPtRes->GetYaxis()->SetTitleSize(0.04);
  InvPtRes->GetXaxis()->SetTitleOffset(1.0);
  InvPtRes->GetXaxis()->SetLabelOffset(0.005);
  InvPtRes->GetXaxis()->SetLabelSize(0.028);
  InvPtRes->GetXaxis()->SetTitleFont(42);
  InvPtRes->GetXaxis()->SetLabelFont(42);
  InvPtRes->GetXaxis()->CenterTitle();
  InvPtRes->GetXaxis()->SetTitleSize(0.04);
  InvPtRes->GetYaxis()->SetTitle("counts"); 
  InvPtRes->GetXaxis()->SetTitle("(p^{RC}_{T}-p^{MC}_{T})/p_{T}^{MC}");
  can6->SaveAs("InvPtRes_4sTGC.pdf","pdf");

  
  TCanvas *can7 = new TCanvas("can7","can7",700,800);
  can7->cd();
  PtRes->Draw();
  PtRes->GetYaxis()->SetTitleOffset(1.1);
  PtRes->GetYaxis()->SetLabelOffset(0.005);
  PtRes->GetYaxis()->SetLabelSize(0.028);
  PtRes->GetYaxis()->CenterTitle();
  PtRes->GetYaxis()->SetTickSize(0.016);
  PtRes->GetYaxis()->SetTitleFont(42);
  PtRes->GetYaxis()->SetLabelFont(42);
  PtRes->GetYaxis()->SetTitleSize(0.04);
  PtRes->GetXaxis()->SetTitleOffset(1.0);
  PtRes->GetXaxis()->SetLabelOffset(0.005);
  PtRes->GetXaxis()->SetLabelSize(0.028);
  PtRes->GetXaxis()->SetTitleFont(42);
  PtRes->GetXaxis()->SetLabelFont(42);
  PtRes->GetXaxis()->CenterTitle();
  PtRes->GetXaxis()->SetTitleSize(0.04);
  PtRes->GetYaxis()->SetTitle("counts");
  can7->SaveAs("PtRes_4sTGC.pdf","pdf");

  TH1F *WrongQVsMcPt = (TH1F*)file->Get("WrongQVsMcPt");
  TH1F *AllQVsMcPt = (TH1F*)file->Get("AllQVsMcPt");

  TCanvas *can8 = new TCanvas("can8","can8",700,800);
  can8->cd();
  WrongQVsMcPt->Divide(AllQVsMcPt);
  WrongQVsMcPt->Draw();
  WrongQVsMcPt->GetYaxis()->SetTitleOffset(1.1);
  WrongQVsMcPt->GetYaxis()->SetLabelOffset(0.005);
  WrongQVsMcPt->GetYaxis()->SetLabelSize(0.028);
  WrongQVsMcPt->GetYaxis()->CenterTitle();
  WrongQVsMcPt->GetYaxis()->SetTickSize(0.016);
  WrongQVsMcPt->GetYaxis()->SetTitleFont(42);
  WrongQVsMcPt->GetYaxis()->SetLabelFont(42);
  WrongQVsMcPt->GetYaxis()->SetTitleSize(0.04);
  WrongQVsMcPt->GetXaxis()->SetTitleOffset(1.0);
  WrongQVsMcPt->GetXaxis()->SetLabelOffset(0.005);
  WrongQVsMcPt->GetXaxis()->SetLabelSize(0.028);
  WrongQVsMcPt->GetXaxis()->SetTitleFont(42);
  WrongQVsMcPt->GetXaxis()->SetLabelFont(42);
  WrongQVsMcPt->GetXaxis()->CenterTitle();
  WrongQVsMcPt->GetXaxis()->SetTitleSize(0.04);
  WrongQVsMcPt->SetName("WrongQVsMcPt/AllQVsMcPt");
  WrongQVsMcPt->SetTitle("charge Mis-ID rate vs P_{T}");
  can8->SaveAs("ChargeMisID_pT_4sTGC.pdf","pdf");

  //=================================for Pt and 1/Pt resolution  fitting ==========================
  
  //  TH1F *InvPtRes = (TH1F*)file->Get("InvPtRes");
  // TH1F *PtRes = (TH1F*)file->Get("PtRes");
  
  TH1F *InvPtRes3s = (TH1F*)InvPtRes->Clone();
  InvPtRes3s->SetName("InvPtRes3s");

  TH1F *PtRes3s = (TH1F*)PtRes->Clone();
  PtRes3s->SetName("PtRes3s");

  TH1F *InvPtRes2s = (TH1F*)InvPtRes->Clone();
  InvPtRes2s->SetName("InvPtRes2s");

  TH1F *PtRes2s = (TH1F*)PtRes->Clone();
  PtRes2s->SetName("PtRes2s");
  
  cout<<InvPtRes->GetXaxis()->GetBinWidth(1)<<endl;

  // first fit with gauss range (-1,1)
  TCanvas *can01 = new TCanvas("can01","can01",700,800);
  can01->cd();
  TF1 *func0 = new TF1("func0",gausFunc,-1.0,1,3);
  func0->SetParameter(0,8.82926e+03);
  func0->SetParameter(1,4.82347e-02);
  func0->SetParameter(2,4.59776e-01);
 
  InvPtRes->Fit("func0","R","",-1,1);
  InvPtRes->GetYaxis()->SetTitleOffset(1.1);
  InvPtRes->GetYaxis()->SetLabelOffset(0.005);
  InvPtRes->GetYaxis()->SetLabelSize(0.028);
  InvPtRes->GetYaxis()->CenterTitle();
  InvPtRes->GetYaxis()->SetTickSize(0.016);
  InvPtRes->GetYaxis()->SetTitleFont(42);
  InvPtRes->GetYaxis()->SetLabelFont(42);
  InvPtRes->GetYaxis()->SetTitleSize(0.04);
  InvPtRes->GetXaxis()->SetTitleOffset(1.0);
  InvPtRes->GetXaxis()->SetLabelOffset(0.005);
  InvPtRes->GetXaxis()->SetLabelSize(0.028);
  InvPtRes->GetXaxis()->SetTitleFont(42);
  InvPtRes->GetXaxis()->SetLabelFont(42);
  InvPtRes->GetXaxis()->CenterTitle();
  InvPtRes->GetXaxis()->SetTitleSize(0.04);
  InvPtRes->GetYaxis()->SetTitle("counts");
  InvPtRes->GetXaxis()->SetRangeUser(-3,3);
  cout<<func0->GetChisquare()<<endl;

  //fit with gauss range (-3sigma,3sigma)  
  TCanvas *can02 = new TCanvas("can02","can02",700,800);
  can02->cd();
  Double_t range= 3*func0->GetParameter(2);
  cout<<range<<endl;
  TF1 *func2 = new TF1("func2",gausFunc,-range,+range,3);
  func2->SetParameter(0,func0->GetParameter(0));
  func2->SetParameter(1,func0->GetParameter(1));
  func2->SetParameter(2,func0->GetParameter(2));
  InvPtRes3s->Fit("func2","R","",-1,1);
  InvPtRes3s->GetYaxis()->SetTitleOffset(1.1);
  InvPtRes3s->GetYaxis()->SetLabelOffset(0.005);
  InvPtRes3s->GetYaxis()->SetLabelSize(0.028);
  InvPtRes3s->GetYaxis()->CenterTitle();
  InvPtRes3s->GetYaxis()->SetTickSize(0.016);
  InvPtRes3s->GetYaxis()->SetTitleFont(42);
  InvPtRes3s->GetYaxis()->SetLabelFont(42);
  InvPtRes3s->GetYaxis()->SetTitleSize(0.04);
  InvPtRes3s->GetXaxis()->SetTitleOffset(1.0);
  InvPtRes3s->GetXaxis()->SetLabelOffset(0.005);
  InvPtRes3s->GetXaxis()->SetLabelSize(0.028);
  InvPtRes3s->GetXaxis()->SetTitleFont(42);
  InvPtRes3s->GetXaxis()->SetLabelFont(42);
  InvPtRes3s->GetXaxis()->CenterTitle();
  InvPtRes3s->GetXaxis()->SetTitleSize(0.04);
  InvPtRes3s->GetYaxis()->SetTitle("counts");
  InvPtRes3s->GetXaxis()->SetRangeUser(-3,3);
  cout<<func2->GetChisquare()<<endl;
  
  //fit with gauss range (-2sigma,2sigma)
  TCanvas *can03 = new TCanvas("can03","can03",700,800);
  can03->cd();
  Double_t range1= 2*func0->GetParameter(2);
  cout<<range1<<endl;
  InvPtRes2s->Draw();  
  TF1 *func4 = new TF1("func4",gausFunc,-range1,+range1,3);
  func4->SetParameter(0,func2->GetParameter(0));
  func4->SetParameter(1,func2->GetParameter(1));
  func4->SetParameter(2,func2->GetParameter(2));
  InvPtRes2s->Fit("func4","R","",-1,1);
  InvPtRes2s->GetYaxis()->SetTitleOffset(1.1);
  InvPtRes2s->GetYaxis()->SetLabelOffset(0.005);
  InvPtRes2s->GetYaxis()->SetLabelSize(0.028);
  InvPtRes2s->GetYaxis()->CenterTitle();
  InvPtRes2s->GetYaxis()->SetTickSize(0.016);
  InvPtRes2s->GetYaxis()->SetTitleFont(42);
  InvPtRes2s->GetYaxis()->SetLabelFont(42);
  InvPtRes2s->GetYaxis()->SetTitleSize(0.04);
  InvPtRes2s->GetXaxis()->SetTitleOffset(1.0);
  InvPtRes2s->GetXaxis()->SetLabelOffset(0.005);
  InvPtRes2s->GetXaxis()->SetLabelSize(0.028);
  InvPtRes2s->GetXaxis()->SetTitleFont(42);
  InvPtRes2s->GetXaxis()->SetLabelFont(42);
  InvPtRes2s->GetXaxis()->CenterTitle();
  InvPtRes2s->GetXaxis()->SetTitleSize(0.04);
  InvPtRes2s->GetYaxis()->SetTitle("counts");
  InvPtRes2s->GetXaxis()->SetRangeUser(-3,3);
  can03->SaveAs("InvPtRes_fit_3_2sigma_4sTGC.pdf","pdf");
  cout<<func4->GetChisquare()<<endl;
  
 
 //====================================================== for PtRes ====================================================

 // first fit with gauss range (-1,1)
  TCanvas *can04 = new TCanvas("can04","can04",700,800);
  can04->cd();
  TF1 *func1 = new TF1("func1",gausFunc,-1.0,1,3);
  func1->SetParameter(0,8.71032e+03);
  func1->SetParameter(1,1.01803e-01);
  func1->SetParameter(2,3.88281e-01);
  PtRes->Fit("func1","R","",-1,1);
  PtRes->GetYaxis()->SetTitleOffset(1.1);
  PtRes->GetYaxis()->SetLabelOffset(0.005);
  PtRes->GetYaxis()->SetLabelSize(0.028);
  PtRes->GetYaxis()->CenterTitle();
  PtRes->GetYaxis()->SetTickSize(0.016);
  PtRes->GetYaxis()->SetTitleFont(42);
  PtRes->GetYaxis()->SetLabelFont(42);
  PtRes->GetYaxis()->SetTitleSize(0.04);
  PtRes->GetXaxis()->SetTitleOffset(1.0);
  PtRes->GetXaxis()->SetLabelOffset(0.005);
  PtRes->GetXaxis()->SetLabelSize(0.028);
  PtRes->GetXaxis()->SetTitleFont(42);
  PtRes->GetXaxis()->SetLabelFont(42);
  PtRes->GetXaxis()->CenterTitle();
  PtRes->GetXaxis()->SetTitleSize(0.04);
  PtRes->GetYaxis()->SetTitle("counts");
  PtRes->GetXaxis()->SetRangeUser(-3,3);
  cout<<func1->GetChisquare()<<endl;

  //fit with gauss range (-3sigma,3sigma)  
 TCanvas *can05 = new TCanvas("can05","can05",700,800);
 can05->cd();
 TF1 *func3 = new TF1("func3",gausFunc,-range,+range,3);
 func3->SetParameter(0,func1->GetParameter(0));
 func3->SetParameter(1,func1->GetParameter(1));
 func3->SetParameter(2,func1->GetParameter(2));
 PtRes3s->Fit("func3","R","",-1,1);
 PtRes3s->GetYaxis()->SetTitleOffset(1.1);
 PtRes3s->GetYaxis()->SetLabelOffset(0.005);
 PtRes3s->GetYaxis()->SetLabelSize(0.028);
 PtRes3s->GetYaxis()->CenterTitle();
 PtRes3s->GetYaxis()->SetTickSize(0.016);
 PtRes3s->GetYaxis()->SetTitleFont(42);
 PtRes3s->GetYaxis()->SetLabelFont(42);
 PtRes3s->GetYaxis()->SetTitleSize(0.04);
 PtRes3s->GetXaxis()->SetTitleOffset(1.0);
 PtRes3s->GetXaxis()->SetLabelOffset(0.005);
 PtRes3s->GetXaxis()->SetLabelSize(0.028);
 PtRes3s->GetXaxis()->SetTitleFont(42);
 PtRes3s->GetXaxis()->SetLabelFont(42);
 PtRes3s->GetXaxis()->CenterTitle();
 PtRes3s->GetXaxis()->SetTitleSize(0.04);
 PtRes3s->GetYaxis()->SetTitle("counts");
 PtRes3s->GetXaxis()->SetRangeUser(-3,3);
 cout<<func3->GetChisquare()<<endl;

 //fit with gauss range (-2sigma,2sigma)
 TCanvas *can06 = new TCanvas("can06","can06",700,800);
 can06->cd();
 PtRes2s->Draw();  
 TF1 *func5 = new TF1("func5",gausFunc,-range1,+range1,3);
 func5->SetParameter(0,func3->GetParameter(0));
 func5->SetParameter(1,func3->GetParameter(1));
 func5->SetParameter(2,func3->GetParameter(2));
 PtRes2s->Fit("func5","R","",-1,1);
 PtRes2s->GetYaxis()->SetTitleOffset(1.1);
 PtRes2s->GetYaxis()->SetLabelOffset(0.005);
 PtRes2s->GetYaxis()->SetLabelSize(0.028);
 PtRes2s->GetYaxis()->CenterTitle();
 PtRes2s->GetYaxis()->SetTickSize(0.016);
 PtRes2s->GetYaxis()->SetTitleFont(42);
 PtRes2s->GetYaxis()->SetLabelFont(42);
 PtRes2s->GetYaxis()->SetTitleSize(0.04);
 PtRes2s->GetXaxis()->SetTitleOffset(1.0);
 PtRes2s->GetXaxis()->SetLabelOffset(0.005);
 PtRes2s->GetXaxis()->SetLabelSize(0.028);
 PtRes2s->GetXaxis()->SetTitleFont(42);
 PtRes2s->GetXaxis()->SetLabelFont(42);
 PtRes2s->GetXaxis()->CenterTitle();
 PtRes2s->GetXaxis()->SetTitleSize(0.04);
 PtRes2s->GetYaxis()->SetTitle("counts");
 PtRes2s->GetXaxis()->SetRangeUser(-3,3);
 can06->SaveAs("PtRes_fit_3_2sigma_4sTGC.pdf","pdf");
 cout<<func5->GetChisquare()<<endl;
 
  


  
  
  
}
