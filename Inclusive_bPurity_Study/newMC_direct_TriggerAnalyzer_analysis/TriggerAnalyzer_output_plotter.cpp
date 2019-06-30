
#include "DataFormats/Math/interface/deltaR.h"
#include "tree_class.h"


void plotter(bool with_data){
     float jet_pt_cut =10.,jet_eta_cut = 2.1, muon_pt_cut = 9., muon_eta_cut = 1.5;
     float xsec_15to20 = 2799000.0,xsec_20to30 = 2526000.0,xsec_30to50 = 1362000.0,xsec_50to80 = 376600.0, xsec_80to120 = 88930.0, xsec_120to170 = 21230.0, xsec_170to300 = 7055.0;  
     //XSDB for DAS=QCD_Pt-*_MuEnrichedPt5_TuneCP5_13TeV_pythia8 
     float relative_weight_20to30=1.; //Let the relative statistical weight of the events be normalized according to the 20to30 xsec.
     float relative_weight_15to20 = xsec_15to20/xsec_20to30, relative_weight_30to50 = xsec_30to50/xsec_20to30, relative_weight_50to80=xsec_50to80/xsec_20to30, relative_weight_80to120=xsec_80to120/xsec_20to30, relative_weight_120to170=xsec_120to170/xsec_20to30,relative_weight_170to300=xsec_170to300/xsec_20to30;
  
  std::vector<std::pair<std::string,float>> file_weight_pair={make_pair("15to20",relative_weight_15to20),make_pair("20to30",relative_weight_20to30),make_pair("30to50",relative_weight_30to50),make_pair("50to80",relative_weight_50to80),make_pair("80to120",relative_weight_80to120),make_pair("120to170",relative_weight_120to170),make_pair("170to300",relative_weight_170to300)};

     int nJets_offCone_mc=0, mc_events=0, nJets_offCone_data=0, data_events=0;


     TChain *mc_chain = new TChain("demo/mytree");
//     mc_chain->Add("/afs/cern.ch/work/v/vbelis/private/MINIAOD_QCD_samples_15to300/*.root");     
     mc_chain->Add("/afs/cern.ch/work/v/vbelis/private/MINIAOD_QCD_samples_15to300_pTrelCalc/*.root");
     int nentries = mc_chain->GetEntries();
//     int nentries = 10000;
     tree_class MC;
     MC.Init(mc_chain,"ALL");
     TH1F *Hdata_jet_pt = new TH1F("Hdata_jet_pt","Data inclusive p_{T}^{jet};p_{T}^{jet};Events/2 GeV",45,jet_pt_cut,100);
     Hdata_jet_pt->SetLineColor(kRed);
     Hdata_jet_pt->SetLineWidth(2);

     TH1F *Hmc_jet_pt = new TH1F("Hmc_jet_pt","MC inclusive p_{T}^{jet};p_{T}^{jet};Events/2 GeV",45,jet_pt_cut,100);
     Hmc_jet_pt->SetLineWidth(2);
     
     TH1F *Hmc_deltaR_jet_mu = new TH1F("#DeltaR(jet,#mu) MC",";#DeltaR(jet,#mu);",50,0.,0.4);
     Hmc_deltaR_jet_mu->SetLineWidth(2);
     TH1F *Hdata_deltaR_jet_mu = new TH1F("#DeltaR(jet,#mu) DATA",";#DeltaR(jet,#mu);",50,0.,0.4);
     Hdata_deltaR_jet_mu->SetLineWidth(2);
     Hdata_deltaR_jet_mu->SetLineColor(kRed);

     TH1F *Hmc_deltaR_no04_jet_mu = new TH1F("#DeltaR(jet,#mu)_no04 MC",";#DeltaR(jet,#mu);",50,0.,4);
     Hmc_deltaR_no04_jet_mu->SetLineWidth(2);
     TH1F *Hdata_deltaR_no04_jet_mu = new TH1F("#DeltaR(jet,#mu)_no04 DATA",";#DeltaR(jet,#mu);",50,0.,4);
     Hdata_deltaR_no04_jet_mu->SetLineWidth(2);
     Hdata_deltaR_no04_jet_mu->SetLineColor(kRed);

     TH1F *Hmc_ratioPT_mu_jet = new TH1F("pT(#mu)/pT(jet) MC",";p_{T}(#mu)/p_{T}(jet);",50,0.,1.1);
     Hmc_ratioPT_mu_jet->SetLineWidth(2);
     TH1F *Hdata_ratioPT_mu_jet = new TH1F("pT(#mu)/pT(jet) DATA",";p_{T}(#mu)/p_{T}(jet);",50,0.,1.1);
     Hdata_ratioPT_mu_jet->SetLineWidth(2);
     Hdata_ratioPT_mu_jet->SetLineColor(kRed);

     TH1F *Hmc_ratioPT_mu15_jet = new TH1F("pT(#mu)/pT(jet) MC (p_{T}(#mu)>15 GeV)",";p_{T}(#mu)/p_{T}(jet);",50,0.,1.1);
     Hmc_ratioPT_mu15_jet->SetLineWidth(2);
     TH1F *Hdata_ratioPT_mu15_jet = new TH1F("pT(#mu)/pT(jet) DATA (p_{T}(#mu)>15 GeV)",";p_{T}(#mu)/p_{T}(jet);",50,0.,1.1);
     Hdata_ratioPT_mu15_jet->SetLineWidth(2);
     Hdata_ratioPT_mu15_jet->SetLineColor(kRed);

//     TH1F *HdeltaR_outOf04Cone_mc = new TH1F("deltaR(jet,mu)_mc",";#Delta R(jet,#mu);",50,0.4,3.5); 
//     HdeltaR_outOf04Cone_mc->SetLineWidth(2);
//     TH1F *HdeltaR_outOf04Cone_data = new TH1F("deltaR(jet,mu)_data",";#Delta R(jet,#mu);",50,0.4,3.5); 
//     HdeltaR_outOf04Cone_data->SetLineWidth(2);
//     HdeltaR_outOf04Cone_data->SetLineColor(kRed);

     cout<<"Analyzing "<<nentries<<" MC events"<<endl;
     for(int ievent=0;ievent<10000;++ievent){
	     MC.GetEntry(ievent);
	     if(MC.muon_pt->size() == 0 || MC.jet_pt->size()==0) continue;
	     if(MC.muon_pt->at(0)<muon_pt_cut || MC.jet_pt->at(0)<jet_pt_cut || abs(MC.jet_eta->at(0))>jet_eta_cut || abs(MC.muon_eta->at(0))>muon_eta_cut) continue;
             std::string current_input_file(mc_chain->GetFile()->GetName());
             ++mc_events;
	     int current_weight=-1;
	     if(current_input_file.std::string::find("15to20") != std::string::npos) current_weight=0;
	     else if(current_input_file.std::string::find("20to30") != std::string::npos) current_weight=1;
	     else if(current_input_file.std::string::find("30to50") != std::string::npos)  current_weight=2;
	     else if(current_input_file.std::string::find("50to80") != std::string::npos) current_weight=3;
	     else if(current_input_file.std::string::find("80to120") != std::string::npos) current_weight=4;
	     else if(current_input_file.std::string::find("120to170") != std::string::npos) current_weight=5;
	     else if(current_input_file.std::string::find("170to300") != std::string::npos) current_weight=6;

             float DR = deltaR(MC.jet_eta->at(0),MC.jet_phi->at(0),MC.muon_eta->at(0),MC.muon_phi->at(0));
                          Hmc_deltaR_no04_jet_mu->Fill(DR,file_weight_pair.at(current_weight).second);
            if(DR<=0.4){
//******Just for pT(mu)/pT(jet) MC-vs-DATA investigation. Dependance on pT(mu)>15 GeV
               if(MC.muon_pt->at(0)>=15) Hmc_ratioPT_mu15_jet->Fill(MC.muon_pt->at(0)/MC.jet_pt->at(0),file_weight_pair.at(current_weight).second); 
//******
                Hmc_jet_pt->Fill(MC.jet_pt->at(0),file_weight_pair.at(current_weight).second);
		Hmc_ratioPT_mu_jet->Fill(MC.muon_pt->at(0)/MC.jet_pt->at(0),file_weight_pair.at(current_weight).second);
		Hmc_deltaR_jet_mu->Fill(DR,file_weight_pair.at(current_weight).second);
		printf("Sizes: pTb_rel/pTb_rel_dir/pTb_rel_indir= %lu/%lu/%lu\n",MC.pTb_rel->size(),MC.pTb_rel_dir->size(),MC.pTb_rel_indir->size());
		printf("Sizes: pTc_rel= %lu\n",MC.pTc_rel->size());
		printf("Sizes: pTq_rel= %lu\n",MC.pTq_rel->size());
                       }
             else{ 
		   ++nJets_offCone_mc; 
//                   HdeltaR_outOf04Cone_mc->Fill(DR,file_weight_pair.at(current_weight).second);
	          }
                                               }

   if(with_data){
     TChain *data_chain = new TChain("mytree");
     data_chain->Add("/afs/cern.ch/work/v/vbelis/private/Inclusive_bPurity_data/data_*04*.root");
     nentries = data_chain->GetEntries();
//     nentries = 10000;
     tree_class DATA;
     DATA.Init(data_chain,"DATA");  
     cout<<"Analyzing "<<nentries<<" DATA events"<<endl;
     for(int ievent=0;ievent<nentries;++ievent){
//	     cout<<"ievent= "<<ievent<<endl;
	     DATA.GetEntry(ievent);
	     if(DATA.good_muon_pt->size() == 0 || DATA.good_jet_pt->size()==0) continue;
	     if(DATA.good_muon_pt->at(0)<muon_pt_cut || DATA.good_jet_pt->at(0)<jet_pt_cut || abs(DATA.good_jet_eta->at(0))>jet_eta_cut || abs(DATA.good_muon_eta->at(0))>muon_eta_cut) continue;
             ++data_events;
             float DR = deltaR(DATA.good_jet_eta->at(0),DATA.good_jet_phi->at(0),DATA.good_muon_eta->at(0),DATA.good_muon_phi->at(0));
             Hdata_deltaR_no04_jet_mu->Fill(DR);
             if(DR>0.4){ ++nJets_offCone_data; /*HdeltaR_outOf04Cone_data->Fill(DR);*/}
	     else{ 
		   Hdata_deltaR_jet_mu->Fill(DR);
                   Hdata_jet_pt->Fill(DATA.good_jet_pt->at(0)); 
	           Hdata_ratioPT_mu_jet->Fill(DATA.good_muon_pt->at(0)/DATA.good_jet_pt->at(0));
		   if(DATA.good_muon_pt->at(0)>=15){
			   Hdata_ratioPT_mu15_jet->Fill(DATA.good_muon_pt->at(0)/DATA.good_jet_pt->at(0));
			                           }
                 }
                                               }
   }//if_with_data

     gStyle->SetLegendBorderSize(0);
     gROOT->SetBatch(kTRUE);//no graphical output on Draw()
     TFile *output_file = new TFile("data_vs_mc_plots.root","recreate");
     Hmc_jet_pt->Write();
     Hdata_jet_pt->Write();

     TCanvas *mc_vs_data_jet_canvas = new TCanvas("data -vs- MC jet_pt","data -vs- MC jet_pt");
     mc_vs_data_jet_canvas->Divide(1,2);
     mc_vs_data_jet_canvas->cd(1);
     Hmc_jet_pt->Scale(1/Hmc_jet_pt->Integral("width"));
     Hdata_jet_pt->Scale(1/Hdata_jet_pt->Integral("width"));
     Hmc_jet_pt->Draw("hist,e");
     Hdata_jet_pt->Draw("hist,sames,E");
     mc_vs_data_jet_canvas->cd(1)->BuildLegend(); 
     mc_vs_data_jet_canvas->cd(2);
     TH1F *Hmc_data_divide = (TH1F*)Hmc_jet_pt->Clone("Hmc_data_divide");
     Hmc_data_divide->Divide(Hdata_jet_pt);
     Hmc_data_divide->SetMarkerStyle(20);
     Hmc_data_divide->GetYaxis()->SetTitle("MC/Data");
     Hmc_data_divide->Draw("E");

//     TCanvas *deltaR_outOf04Cone_canvas = new TCanvas("deltaR_outOf04Cone_canvas","deltaR_outOf04Cone_canvas");
//     HdeltaR_outOf04Cone_data->Scale(1/HdeltaR_outOf04Cone_data->Integral("width"));
//     HdeltaR_outOf04Cone_mc->Scale(1/HdeltaR_outOf04Cone_mc->Integral("width"));
//     HdeltaR_outOf04Cone_data->Draw("hist,E");
//     HdeltaR_outOf04Cone_mc->Draw("hist,E,sames");
//     deltaR_outOf04Cone_canvas->BuildLegend(); 

     TCanvas *deltaR_canvas = new TCanvas("deltaR_canvas","deltaR_canvas");
     Hdata_deltaR_jet_mu->Scale(1/Hdata_deltaR_jet_mu->Integral("width"));
     Hmc_deltaR_jet_mu->Scale(1/Hmc_deltaR_jet_mu->Integral("width"));
     Hdata_deltaR_jet_mu->Draw("hist,E");
     Hmc_deltaR_jet_mu->Draw("hist,E,sames");
     deltaR_canvas->BuildLegend();

     TCanvas *deltaR_no04_canvas = new TCanvas("deltaR_no04_canvas","deltaR_no04_canvas");
     Hdata_deltaR_no04_jet_mu->Scale(1/Hdata_deltaR_no04_jet_mu->Integral("width"));
     Hmc_deltaR_no04_jet_mu->Scale(1/Hmc_deltaR_no04_jet_mu->Integral("width"));
     Hdata_deltaR_no04_jet_mu->Draw("hist,E");
     Hmc_deltaR_no04_jet_mu->Draw("hist,E,sames");
     deltaR_no04_canvas->BuildLegend();
     
     TCanvas *pT_jet_mu_ratio_canvas = new TCanvas("pT_jet_mu_ratio_canvas","pT_jet_mu_ratio_canvas");
     Hdata_ratioPT_mu_jet->Scale(1/Hdata_ratioPT_mu_jet->Integral("width"));
     Hdata_ratioPT_mu_jet->SetStats(0);
     Hmc_ratioPT_mu_jet->Scale(1/Hmc_ratioPT_mu_jet->Integral("width"));
     Hmc_ratioPT_mu_jet->SetStats(0);

//******** TO be made a class for fancy plots
     TRatioPlot *pT_jet_mu_ratio_plot = new TRatioPlot(Hmc_ratioPT_mu_jet,Hdata_ratioPT_mu_jet,"divsym");
     float margin=0.01;
     pT_jet_mu_ratio_plot->SetSeparationMargin(margin);
     pT_jet_mu_ratio_plot->SetH1DrawOpt("hist,E");
     pT_jet_mu_ratio_plot->SetH2DrawOpt("hist,E");
     pT_jet_mu_ratio_plot->Draw();

     TGraph* lowerGraph = pT_jet_mu_ratio_plot->GetLowerRefGraph();
     lowerGraph->SetMarkerStyle(20);
     lowerGraph->SetMarkerColor(kBlack);
     lowerGraph->SetLineColor(kBlack);
//     lowerGraph.GetYaxis()->SetTicks("+-");
//     lowerGraph.GetXaxis()->SetTicks("+-");
//     
//     pT_jet_mu_ratio_plot->GetUpperRefXaxis()->SetTicks("+-");
//     pT_jet_mu_ratio_plot->GetUpperRefYaxis()->SetTicks("+-");
     TPad* upperPad = pT_jet_mu_ratio_plot->GetUpperPad();
     upperPad->cd();
//     Hdata_ratioPT_mu_jet->Draw("hist,E");
//     Hmc_ratioPT_mu_jet->Draw("hist,E,sames");
     upperPad->cd()->BuildLegend();

     pT_jet_mu_ratio_canvas->Modified();
     pT_jet_mu_ratio_canvas->Update();
//*******

     TCanvas *pT_jet_mu15_ratio_canvas = new TCanvas("pT_jet_mu15_ratio_canvas","pT_jet_mu15_ratio_canvas");
     Hdata_ratioPT_mu15_jet->Scale(1/Hdata_ratioPT_mu15_jet->Integral("width"));
     Hdata_ratioPT_mu15_jet->SetStats(0);
     Hmc_ratioPT_mu15_jet->Scale(1/Hmc_ratioPT_mu15_jet->Integral("width"));
     Hmc_ratioPT_mu15_jet->SetStats(0);
//******** TO be made a class for fancy plots
     TRatioPlot *pT_jet_mu15_ratio_plot = new TRatioPlot(Hmc_ratioPT_mu15_jet,Hdata_ratioPT_mu15_jet,"divsym");
     pT_jet_mu15_ratio_plot->SetSeparationMargin(margin);
     pT_jet_mu15_ratio_plot->SetH1DrawOpt("hist,E");
     pT_jet_mu15_ratio_plot->SetH2DrawOpt("hist,E");
     pT_jet_mu15_ratio_plot->Draw();

     TGraph* lowerGraph15 = pT_jet_mu15_ratio_plot->GetLowerRefGraph();
     lowerGraph15->SetMarkerStyle(20);
     lowerGraph15->SetMarkerColor(kBlack);
     lowerGraph15->SetLineColor(kBlack);
//     lowerGraph15.GetYaxis()->SetTicks("+-");
//     lowerGraph15.GetXaxis()->SetTicks("+-");
//     
//     pT_jet_mu15_ratio_plot->GetUpperRefXaxis()->SetTicks("+-");
//     pT_jet_mu15_ratio_plot->GetUpperRefYaxis()->SetTicks("+-");
     TPad* upperPad15 = pT_jet_mu15_ratio_plot->GetUpperPad();
     upperPad15->cd()->BuildLegend();

     pT_jet_mu15_ratio_canvas->Modified();
     pT_jet_mu15_ratio_canvas->Update();
//*******
//     divsym 	uses the histogram TH1::Divide method, yields symmetric errors
//     diff 	subtracts the histograms
//     diffsig 	subtracts the histograms and divides by the uncertainty 
//     Hdata_ratioPT_mu15_jet->Draw("hist,E");
//     Hmc_ratioPT_mu15_jet->Draw("hist,E,sames");



     mc_vs_data_jet_canvas->Write();
     pT_jet_mu15_ratio_canvas->Write();
     deltaR_canvas->Write();
//     deltaR_outOf04Cone_canvas->Write();
     deltaR_no04_canvas->Write();
     pT_jet_mu_ratio_canvas->Write();

     delete output_file;     
     //C-Style text file I/O:
     FILE *print_file;
     print_file = fopen("calculation_results.txt","w");
     fprintf(print_file,"Number of MC events that passed all cuts & criteria: %i. Number of Jets with deltaR(jet,mu)>0.4: %i, perc=%f %%\n",mc_events,nJets_offCone_mc,100.*nJets_offCone_mc/mc_events);
     fprintf(print_file,"Number of DATA events that passed all cuts & criteria: %i. Number of Jets with deltaR(jet,mu)>0.4: %i, perc=%f %%\n",data_events,nJets_offCone_data,100.*nJets_offCone_data/data_events);
     fprintf(print_file,"MC: N(pTjet>25)/Ntot = %f %%\n",Hmc_jet_pt->Integral(Hmc_jet_pt->FindBin(25.),Hmc_jet_pt->GetNbinsX()+1)/Hmc_jet_pt->Integral(0,Hmc_jet_pt->GetNbinsX()+1)*100);
     fprintf(print_file,"DATA: N(pTjet>25)/Ntot = %f %%\n",Hdata_jet_pt->Integral(Hdata_jet_pt->FindBin(25.),Hdata_jet_pt->GetNbinsX()+1)/Hdata_jet_pt->Integral(0,Hdata_jet_pt->GetNbinsX()+1)*100);
     for(int ibin=0;ibin<Hmc_jet_pt->GetSize();++ibin) fprintf(print_file,"Hmc_jet_pt->GetBinContent(%i)=%f\n",ibin,Hmc_jet_pt->GetBinContent(ibin));
     fprintf(print_file,"+++Now for the data:");
     for(int ibin=0;ibin<Hdata_jet_pt->GetSize();++ibin) fprintf(print_file,"Hdata_jet_pt->GetBinContent(%i)=%f\n",ibin,Hdata_jet_pt->GetBinContent(ibin));
     fclose(print_file);
    //delete print_file;
}
