
void muon_pt_fit(){

       TFile * data_file = new TFile("../BParking18_data/data_output.root","read");
       TFile * b_template_MUOVal_file = new TFile("../templates/b_template_QCD_MUOVal_sample.root","read");
       TFile * c_template_MUOVal_file = new TFile("../templates/c_template_QCD_MUOVal_sample.root","read");
       TFile * uds_template_MUOVal_file = new TFile("../templates/uds_template_QCD_MUOVal_sample.root","read");
       TFile * b_template_Pt15_1000_file = new TFile("../templates/b_template_QCD_Pt15-1000.root","read");
       TFile * c_template_Pt15_1000_file = new TFile("../templates/c_template_QCD_Pt15-1000.root","read");
       TFile * uds_template_Pt15_1000_file = new TFile("../templates/uds_template_QCD_Pt15-1000.root","read");


       TH1F * Hdata_muon_pt = (TH1F*)data_file->Get("Hdata_muon_pt");
       Hdata_muon_pt->SetMarkerStyle(20);
       Hdata_muon_pt->SetLineColor(kBlack);
       Hdata_muon_pt->SetLineWidth(2);
       Hdata_muon_pt->SetTitle("p_{T}(#mu): BParking18 dataset");
       Hdata_muon_pt->SetName("p_{T}(#mu): BParking18 dataset");

       TH1F * Hsim_MUOVal_bmuon_pt = (TH1F*)b_template_MUOVal_file->Get("Hrecomu_final_pt");
       TH1F * Hsim_MUOVal_cmuon_pt = (TH1F*)c_template_MUOVal_file->Get("Hrecomu_final_pt");
       TH1F * Hsim_MUOVal_lmuon_pt = (TH1F*)uds_template_MUOVal_file->Get("Hrecomu_final_pt");
       TH1F * Hsim_Pt_15_1000_bmuon_pt = (TH1F*)b_template_Pt15_1000_file->Get("Hrecomu_final_pt");
       TH1F * Hsim_Pt_15_1000_cmuon_pt = (TH1F*)c_template_Pt15_1000_file->Get("Hrecomu_final_pt");
       TH1F * Hsim_Pt_15_1000_lmuon_pt = (TH1F*)uds_template_Pt15_1000_file->Get("Hrecomu_final_pt");
       auto Hsim_MUOVal_clmuon_pt = new TH1F(*Hsim_MUOVal_cmuon_pt);
       Hsim_MUOVal_clmuon_pt->Add(Hsim_MUOVal_lmuon_pt); 
       auto Hsim_Pt_15_1000_clmuon_pt = new TH1F(*Hsim_Pt_15_1000_cmuon_pt);
       Hsim_Pt_15_1000_clmuon_pt->Add(Hsim_Pt_15_1000_lmuon_pt); 

       Hsim_MUOVal_bmuon_pt -> Sumw2();
       Hsim_MUOVal_cmuon_pt -> Sumw2();
       Hsim_MUOVal_lmuon_pt -> Sumw2();
       Hsim_Pt_15_1000_bmuon_pt-> Sumw2();
       Hsim_Pt_15_1000_cmuon_pt-> Sumw2();
       Hsim_Pt_15_1000_lmuon_pt-> Sumw2();
       Hsim_MUOVal_clmuon_pt-> Sumw2();
       Hsim_Pt_15_1000_clmuon_pt->Sumw2();

       float x_max=45.;
       Hdata_muon_pt->GetXaxis()->SetRangeUser(9.,x_max);
       Hsim_MUOVal_bmuon_pt->GetXaxis()->SetRangeUser(9,x_max);
       Hsim_MUOVal_cmuon_pt->GetXaxis()->SetRangeUser(9,x_max);
       Hsim_MUOVal_lmuon_pt->GetXaxis()->SetRangeUser(9,x_max);
       Hsim_MUOVal_clmuon_pt->GetXaxis()->SetRangeUser(9,x_max);

       Hsim_MUOVal_bmuon_pt->SetTitle("p_{T}(b#rightarrow #mu + X)");
       Hsim_MUOVal_cmuon_pt->SetTitle("p_{T}(c#rightarrow #mu + X')");
       Hsim_MUOVal_lmuon_pt->SetTitle("p_{T}(l#rightarrow #mu + X'')");
       Hsim_MUOVal_clmuon_pt->SetTitle("p_{T}(udsc#rightarrow #mu + #tilde{X})");

       Hsim_Pt_15_1000_bmuon_pt->GetXaxis()->SetRangeUser(9,x_max);
       Hsim_Pt_15_1000_cmuon_pt->GetXaxis()->SetRangeUser(9,x_max);
       Hsim_Pt_15_1000_lmuon_pt->GetXaxis()->SetRangeUser(9,x_max);
       Hsim_Pt_15_1000_clmuon_pt->GetXaxis()->SetRangeUser(9,x_max);




       Hsim_MUOVal_bmuon_pt->SetLineColor(kBlue);
       Hsim_MUOVal_cmuon_pt->SetLineColor(kRed);
       Hsim_MUOVal_lmuon_pt->SetLineColor(kGreen);
       Hsim_MUOVal_clmuon_pt->SetLineColor(kOrange-3);
       Hsim_MUOVal_bmuon_pt->SetLineWidth(2);
       Hsim_MUOVal_cmuon_pt->SetLineWidth(2);
       Hsim_MUOVal_lmuon_pt->SetLineWidth(2);
       Hsim_MUOVal_clmuon_pt->SetLineWidth(2);

       Hsim_Pt_15_1000_bmuon_pt->SetLineColor(kBlue);
       Hsim_Pt_15_1000_cmuon_pt->SetLineColor(kRed);
       Hsim_Pt_15_1000_lmuon_pt->SetLineColor(kGreen);
       Hsim_Pt_15_1000_clmuon_pt->SetLineColor(kOrange-3);
       Hsim_Pt_15_1000_bmuon_pt->SetLineWidth(2);
       Hsim_Pt_15_1000_cmuon_pt->SetLineWidth(2);
       Hsim_Pt_15_1000_lmuon_pt->SetLineWidth(2);
       Hsim_Pt_15_1000_clmuon_pt->SetLineWidth(2);


       ROOT::Math::MinimizerOptions::SetDefaultMaxFunctionCalls(10000);
       TF1 * bfit_MUOVal = new TF1("bfit","[0]*pow(x,[1])*exp([2]*x+[3]*x*x+[4]*x*x*x)",0.,x_max);
       bfit_MUOVal->SetLineColor(kBlue);
       TF1 * cfit_MUOVal = new TF1("cfit","[0]*pow(x,[1])*exp([2]*x+[3]*x*x+[4]*x*x*x)",0.,x_max);
       cfit_MUOVal->SetLineColor(kRed);
       TF1 * lfit_MUOVal = new TF1("lfit","[0]*pow(x,[1])*exp([2]*x+[3]*x*x+[4]*x*x*x)",0.,x_max);
       lfit_MUOVal->SetLineColor(kGreen);
       TF1 * clfit_MUOVal = new TF1("clfit","[0]*pow(x,[1])*exp([2]*x+[3]*x*x+[4]*x*x*x)",0.,x_max);
       clfit_MUOVal->SetLineColor(kOrange-3);

       TF1 * bfit_Pt_15_1000 = new TF1("bfit","[0]*pow(x,[1])*exp([2]*x+[3]*x*x+[4]*x*x*x)",0.,x_max);
       bfit_Pt_15_1000->SetLineColor(kBlue);                                                 
       TF1 * cfit_Pt_15_1000 = new TF1("cfit","[0]*pow(x,[1])*exp([2]*x+[3]*x*x+[4]*x*x*x)",0.,x_max);
       cfit_Pt_15_1000->SetLineColor(kRed);                                                  
       TF1 * lfit_Pt_15_1000 = new TF1("lfit","[0]*pow(x,[1])*exp([2]*x+[3]*x*x+[4]*x*x*x)",0.,x_max);
       lfit_Pt_15_1000->SetLineColor(kGreen);
       TF1 * clfit_Pt_15_1000 = new TF1("clfit","[0]*pow(x,[1])*exp([2]*x+[3]*x*x+[4]*x*x*x)",0.,x_max);
       clfit_Pt_15_1000->SetLineColor(kOrange-3);


       gStyle->SetOptFit(1);
       TCanvas * canvas_1 = new TCanvas("(Val)Parametrizing the input pT(muon) distributions","MUO_VAL");
       canvas_1->Divide(2,2);

       canvas_1->cd(1);
       bfit_MUOVal->SetParameter(0,10);
       Hsim_MUOVal_bmuon_pt->Fit(bfit_MUOVal,"L");
       Hsim_MUOVal_bmuon_pt->Draw("same,hist");

       canvas_1->cd(2);
       cfit_MUOVal->SetParameter(0,1000);
       Hsim_MUOVal_cmuon_pt->Fit(cfit_MUOVal,"L");
       Hsim_MUOVal_cmuon_pt->Draw("same,hist");

       canvas_1->cd(3);
       lfit_MUOVal->SetParameter(0,100);
       Hsim_MUOVal_lmuon_pt->Fit(lfit_MUOVal,"L");
       Hsim_MUOVal_lmuon_pt->Draw("same,hist");

       canvas_1->cd(4);
       clfit_MUOVal->SetParameter(0,50);
       Hsim_MUOVal_clmuon_pt->Fit(clfit_MUOVal,"L");
       Hsim_MUOVal_clmuon_pt->Draw("same,hist");

       cout<<"\n\n";
       cout<<"Now QCD_Pt15-1000:\n\n"<<endl;

       TCanvas * canvas_2 = new TCanvas("(pT-15_1000)Parametrizing the input pT(muon) distributions","Pt_15_1000");
       canvas_2->Divide(2,2);

       canvas_2->cd(1);
       bfit_Pt_15_1000->SetParameter(0,1000);
       Hsim_Pt_15_1000_bmuon_pt->Fit(bfit_Pt_15_1000,"L");
       Hsim_Pt_15_1000_bmuon_pt->Draw("same,hist");

       canvas_2->cd(2);
       cfit_Pt_15_1000->SetParameter(0,10);
       Hsim_Pt_15_1000_cmuon_pt->Fit(cfit_Pt_15_1000,"L");
       Hsim_Pt_15_1000_cmuon_pt->Draw("same,hist");

       canvas_2->cd(3);	
       lfit_Pt_15_1000->SetParameter(0,1000);
       Hsim_Pt_15_1000_lmuon_pt->Fit(lfit_Pt_15_1000,"L");
       Hsim_Pt_15_1000_lmuon_pt->Draw("same,hist");

       canvas_2->cd(4);
       clfit_Pt_15_1000->SetParameter(0,50);
       Hsim_Pt_15_1000_clmuon_pt->Fit(clfit_Pt_15_1000,"L");
       Hsim_Pt_15_1000_clmuon_pt->Draw("same,hist");


       //Normalize the fit to obtain number of events as fit parameter values:
       bfit_MUOVal->SetParameter(0,bfit_MUOVal->GetParameter(0)/Hsim_MUOVal_bmuon_pt->GetEntries());
       cfit_MUOVal->SetParameter(0,cfit_MUOVal->GetParameter(0)/Hsim_MUOVal_cmuon_pt->GetEntries());
       lfit_MUOVal->SetParameter(0,lfit_MUOVal->GetParameter(0)/Hsim_MUOVal_lmuon_pt->GetEntries());
       clfit_MUOVal->SetParameter(0,clfit_MUOVal->GetParameter(0)/Hsim_MUOVal_clmuon_pt->GetEntries());    

       TF1 *f_fit_MUOVal_3 = new TF1("f_fit",bfit_MUOVal->GetFormula()->GetExpFormula("P")+"++"+cfit_MUOVal->GetFormula()->GetExpFormula("P")+"++"+lfit_MUOVal->GetFormula()->GetExpFormula("P"),9.,x_max);
       TF1 *f_fit_MUOVal_2 = new TF1("f_fit",bfit_MUOVal->GetFormula()->GetExpFormula("P")+"++"+clfit_MUOVal->GetFormula()->GetExpFormula("P"),9.,x_max);

       TF1 *my_fit_MUOVal_2 = new TF1("my_fit","[0]*"+bfit_MUOVal->GetFormula()->GetExpFormula("P")+"+("+std::to_string(Hdata_muon_pt->GetEntries())+"-[0])*"+cfit_MUOVal->GetFormula()->GetExpFormula("P"));
       my_fit_MUOVal_2->SetLineColor(kViolet);
       my_fit_MUOVal_2->SetLineWidth(3);
       my_fit_MUOVal_2->SetParName(0,"n_b");

       TCanvas * fit_canvas = new TCanvas("MUOVal dataset 3-fit pT(muon)","MUOVal dataset fit pT(muon)");
       my_fit_MUOVal_2->SetParameter(0,0.7*Hdata_muon_pt->GetEntries());
       Hdata_muon_pt->Fit(my_fit_MUOVal_2,"L");
       Hdata_muon_pt->SetTitle("");
//       fit_canvas->SetGrid();
       TF1 * bfit_MUOVal_copy = new TF1("p_{T}^{muon}(b#rightarrow #mu+X)",std::to_string(my_fit_MUOVal_2->GetParameter(0))+"*"+bfit_MUOVal->GetFormula()->GetExpFormula("P"),9.,x_max);
       TF1 * clfit_MUOVal_copy = new TF1("p_{T}^{muon}(udsc#rightarrow #mu+#tilde{X})",std::to_string(Hdata_muon_pt->GetEntries()-my_fit_MUOVal_2->GetParameter(0))+"*"+clfit_MUOVal->GetFormula()->GetExpFormula("P"),9.,x_max);
       bfit_MUOVal_copy->SetTitle(bfit_MUOVal_copy->GetName());
       bfit_MUOVal_copy->SetLineColor(kBlue);
       bfit_MUOVal_copy->SetLineStyle(2);
       bfit_MUOVal_copy->SetLineWidth(2);
       clfit_MUOVal_copy->SetTitle(clfit_MUOVal_copy->GetName());
       clfit_MUOVal_copy->SetLineColor(kRed);
       clfit_MUOVal_copy->SetLineStyle(2);
       clfit_MUOVal_copy->SetLineWidth(2);

       TLatex * cms_logo = new TLatex(11.5,Hdata_muon_pt->GetMaximum(),"CMS");
       cms_logo->SetTextSize(0.055);
       cms_logo->Draw();
       float bPurity=my_fit_MUOVal_2->GetParameter(0)/Hdata_muon_pt->GetEntries(),bPurity_err=my_fit_MUOVal_2->GetParError(0)/Hdata_muon_pt->GetEntries();
       //std::c_str: string to cons char *
       bfit_MUOVal_copy->Draw("same");
       clfit_MUOVal_copy->Draw("same");      
       fit_canvas->BuildLegend();
       TLatex * bPurity_text = new TLatex(25.,0.5*Hdata_muon_pt->GetMaximum(),("bPurity= "+std::to_string(bPurity)+" #pm "+std::to_string(bPurity_err)).c_str());
       bPurity_text->SetTextSize(0.04);
       bPurity_text->SetTextFont(42);
       bPurity_text->Draw();

       TFile * muon_pt_fit_output = new TFile("muon_pt_fit_output.root","recreate");
       bfit_MUOVal->Write();
       cfit_MUOVal->Write();
       lfit_MUOVal->Write();
       clfit_MUOVal->Write();
     
//       TCanvas * fit_canvas2 = new TCanvas("MUOVal dataset 2-fit pT(muon)","MUOVal dataset 2-fit pT(muon)");
//       Hdata_muon_pt->Fit(f_fit_MUOVal_3);
//cout<<"bPurity= "<<my_fit_MUOVal_2->GetParameter(0)/Hdata_muon_pt->GetEntries()<<endl;
//cout<<"bPurity= "<<f_fit_MUOVal_3->GetParameter(0)/Hdata_muon_pt->GetEntries()<<endl;

}
