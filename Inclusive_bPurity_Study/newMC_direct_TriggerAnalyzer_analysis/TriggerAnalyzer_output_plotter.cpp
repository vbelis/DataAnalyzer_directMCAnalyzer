
#include "DataFormats/Math/interface/deltaR.h"
#include "tree_class.h"

void plotter(){
     float jet_pt_cut =10.,jet_eta_cut = 2.1, muon_pt_cut = 9., muon_eta_cut = 1.5;
     float xsec_15to20 = 2799000.0,xsec_20to30 = 2526000.0,xsec_30to50 = 1362000.0,xsec_50to80 = 376600.0, xsec_80to120 = 88930.0, xsec_120to170 = 21230.0, xsec_170to300 = 7055.0;  
     //XSDB for DAS=QCD_Pt-*_MuEnrichedPt5_TuneCP5_13TeV_pythia8 
     float relative_weight_20to30=1.; //Let the relative statistical weight of the events be normalized according to the 20to30 xsec.
     float relative_weight_15to20 = xsec_15to20/xsec_20to30, relative_weight_30to50 = xsec_30to50/xsec_20to30, relative_weight_50to80=xsec_50to80/xsec_20to30, relative_weight_80to120=xsec_80to120/xsec_20to30, relative_weight_120to170=xsec_120to170/xsec_20to30,relative_weight_170to300=xsec_170to300/xsec_20to30;

     int nJets_offCone_mc=0, mc_events=0, nJets_offCone_data=0, data_events=0;


     TChain *mc_chain = new TChain("demo/mytree");
     mc_chain->Add("/afs/cern.ch/work/v/vbelis/private/MINIAOD_QCD_samples_15to300/*.root");     
     int nentries = mc_chain->GetEntries();

     tree_class MC;
     MC.Init(mc_chain,"JET_MUON");
             
     TH1F *Hdata_jet_pt = new TH1F("Hdata_jet_pt","Data inclusive p_{T}^{jet};p_{T}^{jet};entries/bin",70,jet_pt_cut,300.);
     Hdata_jet_pt->SetLineColor(kRed);
     Hdata_jet_pt->SetLineWidth(2);

     TH1F *Hmc_jet_pt = new TH1F("Hmc_jet_pt","MC inclusive p_{T}^{jet};p_{T}^{jet};entries/bin",70,jet_pt_cut,300.);
     Hmc_jet_pt->SetLineWidth(2);
     
     TH1F *Hmc_deltaR_jet_mu = new TH1F("#DeltaR(jet,#mu) MC",";#DeltaR(jet,#mu);",50,0.,0.4);
     Hmc_deltaR_jet_mu->SetLineWidth(2);
     TH1F *Hdata_deltaR_jet_mu = new TH1F("#DeltaR(jet,#mu) DATA",";#DeltaR(jet,#mu);",50,0.,0.4);
     Hdata_deltaR_jet_mu->SetLineWidth(2);
     Hdata_deltaR_jet_mu->SetLineColor(kRed);

     TH1F *Hmc_deltaR_no04_jet_mu = new TH1F("#DeltaR(jet,#mu) MC",";#DeltaR(jet,#mu);",50,0.,4);
     Hmc_deltaR_no04_jet_mu->SetLineWidth(2);
     TH1F *Hdata_deltaR_no04_jet_mu = new TH1F("#DeltaR(jet,#mu) DATA",";#DeltaR(jet,#mu);",50,0.,4);
     Hdata_deltaR_no04_jet_mu->SetLineWidth(2);
     Hdata_deltaR_no04_jet_mu->SetLineColor(kRed);

     TH1F *Hmc_ratioPT_mu_jet = new TH1F("pT(#mu)/pT(jet) MC",";p_{T}(#mu)/p_{T}(jet);",50,0.,1.1);
     Hmc_ratioPT_mu_jet->SetLineWidth(2);
     TH1F *Hdata_ratioPT_mu_jet = new TH1F("pT(#mu)/pT(jet) DATA",";p_{T}(#mu)/p_{T}(jet);",50,0.,1.1);
     Hdata_ratioPT_mu_jet->SetLineWidth(2);
     Hdata_ratioPT_mu_jet->SetLineColor(kRed);

     TH1F *HdeltaR_outOf04Cone_mc = new TH1F("deltaR(jet,mu)_mc",";#Delta R(jet,#mu);",50,0.4,3.5); 
     HdeltaR_outOf04Cone_mc->SetLineWidth(2);
     TH1F *HdeltaR_outOf04Cone_data = new TH1F("deltaR(jet,mu)_data",";#Delta R(jet,#mu);",50,0.4,3.5); 
     HdeltaR_outOf04Cone_data->SetLineWidth(2);
     HdeltaR_outOf04Cone_data->SetLineColor(kRed);

     cout<<"Analyzing "<<nentries<<" MC events"<<endl;
     for(int ievent=0;ievent<nentries;++ievent){
	     MC.GetEntry(ievent);
             std::string current_input_file(mc_chain->GetFile()->GetName());
	     if(MC.muon_pt->size() == 0 || MC.jet_pt->size()==0) continue;

	     if(MC.muon_pt->at(0)<muon_pt_cut || MC.jet_pt->at(0)<jet_pt_cut || abs(MC.jet_eta->at(0))>jet_eta_cut || abs(MC.muon_eta->at(0))>muon_eta_cut) continue;
//	     cout<<"MC.jet_pt->at(0)"<<MC.jet_pt->at(0)<<endl;
             ++mc_events;
             float DR = deltaR(MC.jet_eta->at(0),MC.jet_phi->at(0),MC.muon_eta->at(0),MC.muon_phi->at(0));
                         if(current_input_file.std::string::find("30to50") != std::string::npos) Hmc_deltaR_no04_jet_mu->Fill(DR,relative_weight_30to50);
                         else if(current_input_file.std::string::find("50to80") != std::string::npos) Hmc_deltaR_no04_jet_mu->Fill(DR,relative_weight_50to80);
                         else if(current_input_file.std::string::find("80to120") != std::string::npos) Hmc_deltaR_no04_jet_mu->Fill(DR,relative_weight_80to120);
                         else if(current_input_file.std::string::find("120to170") != std::string::npos) Hmc_deltaR_no04_jet_mu->Fill(DR,relative_weight_120to170);
                         else if(current_input_file.std::string::find("170to300") != std::string::npos) Hmc_deltaR_no04_jet_mu->Fill(DR,relative_weight_170to300);
                         else if(current_input_file.std::string::find("15to20") != std::string::npos) Hmc_deltaR_no04_jet_mu->Fill(DR,relative_weight_15to20);	 
                         else if(current_input_file.std::string::find("20to30") != std::string::npos) Hmc_deltaR_no04_jet_mu->Fill(DR,relative_weight_20to30);
            if(DR<=0.4){
             if(current_input_file.std::string::find("30to50") != std::string::npos){
                        //text.find should return a -1 if the word isnt there, otherwise it returns the position in string that you found it
                        //some_string.find('a') will EITHER return the position of the first appearance of 'a' in some_string if 'a' appears at least once in some_string, OR it will return a value that is equal to std::string::npos if 'a' does not appear at all in some_string.
                         Hmc_jet_pt->Fill(MC.jet_pt->at(0),relative_weight_30to50);
			 Hmc_ratioPT_mu_jet->Fill(MC.muon_pt->at(0)/MC.jet_pt->at(0),relative_weight_30to50);
			 Hmc_deltaR_jet_mu->Fill(DR,relative_weight_30to50);
                                                                                    }
                         else if(current_input_file.std::string::find("50to80") != std::string::npos){
                                 Hmc_jet_pt->Fill(MC.jet_pt->at(0),relative_weight_50to80);
			         Hmc_ratioPT_mu_jet->Fill(MC.muon_pt->at(0)/MC.jet_pt->at(0),relative_weight_50to80);
			         Hmc_deltaR_jet_mu->Fill(DR,relative_weight_50to80);
				                                                                     }
                         else if(current_input_file.std::string::find("80to120") != std::string::npos){
		                 Hmc_jet_pt->Fill(MC.jet_pt->at(0),relative_weight_80to120);
			         Hmc_ratioPT_mu_jet->Fill(MC.muon_pt->at(0)/MC.jet_pt->at(0),relative_weight_80to120);
			         Hmc_deltaR_jet_mu->Fill(DR,relative_weight_80to120);
			                                                                              }
                         else if(current_input_file.std::string::find("120to170") != std::string::npos){
				 Hmc_jet_pt->Fill(MC.jet_pt->at(0),relative_weight_120to170);
			         Hmc_ratioPT_mu_jet->Fill(MC.muon_pt->at(0)/MC.jet_pt->at(0),relative_weight_120to170);
			         Hmc_deltaR_jet_mu->Fill(DR,relative_weight_120to170);
				                                                                       }
                         else if(current_input_file.std::string::find("170to300") != std::string::npos){
			         Hmc_jet_pt->Fill(MC.jet_pt->at(0),relative_weight_170to300);
			         Hmc_ratioPT_mu_jet->Fill(MC.muon_pt->at(0)/MC.jet_pt->at(0),relative_weight_170to300);
			         Hmc_deltaR_jet_mu->Fill(DR,relative_weight_170to300);
				                                                                       }
                         else if(current_input_file.std::string::find("15to20") != std::string::npos){	 
			         Hmc_jet_pt->Fill(MC.jet_pt->at(0),relative_weight_15to20);
			         Hmc_ratioPT_mu_jet->Fill(MC.muon_pt->at(0)/MC.jet_pt->at(0),relative_weight_15to20);
			         Hmc_deltaR_jet_mu->Fill(DR,relative_weight_15to20);
				  								     }
                         else if(current_input_file.std::string::find("20to30") != std::string::npos){
				 Hmc_jet_pt->Fill(MC.jet_pt->at(0),relative_weight_20to30);
			         Hmc_ratioPT_mu_jet->Fill(MC.muon_pt->at(0)/MC.jet_pt->at(0),relative_weight_20to30);
			         Hmc_deltaR_jet_mu->Fill(DR,relative_weight_20to30);
				  							  	     }	
                       }
             else{ 
		         ++nJets_offCone_mc; 
                         if(current_input_file.std::string::find("30to50") != std::string::npos) HdeltaR_outOf04Cone_mc->Fill(DR,relative_weight_30to50);
                         else if(current_input_file.std::string::find("50to80") != std::string::npos) HdeltaR_outOf04Cone_mc->Fill(DR,relative_weight_50to80);
                         else if(current_input_file.std::string::find("80to120") != std::string::npos) HdeltaR_outOf04Cone_mc->Fill(DR,relative_weight_80to120);
                         else if(current_input_file.std::string::find("120to170") != std::string::npos) HdeltaR_outOf04Cone_mc->Fill(DR,relative_weight_120to170);
                         else if(current_input_file.std::string::find("170to300") != std::string::npos) HdeltaR_outOf04Cone_mc->Fill(DR,relative_weight_170to300);
                         else if(current_input_file.std::string::find("15to20") != std::string::npos) HdeltaR_outOf04Cone_mc->Fill(DR,relative_weight_15to20);	 
                         else if(current_input_file.std::string::find("20to30") != std::string::npos) HdeltaR_outOf04Cone_mc->Fill(DR,relative_weight_20to30);
	          }
                                               }

     TChain *data_chain = new TChain("mytree");
     data_chain->Add("/afs/cern.ch/work/v/vbelis/private/Inclusive_bPurity_data/data_*04*.root");
     nentries = data_chain->GetEntries();

     tree_class DATA;
     DATA.Init(data_chain,"DATA");
     
     cout<<"Analyzing "<<nentries<<" DATA events"<<endl;
     for(int ievent=0;ievent<nentries;++ievent){
	     cout<<"ievent= "<<ievent<<endl;
	     DATA.GetEntry(ievent);
	     if(DATA.good_muon_pt->size() == 0 || DATA.good_jet_pt->size()==0) continue;
	     if(DATA.good_muon_pt->at(0)<muon_pt_cut || DATA.good_jet_pt->at(0)<jet_pt_cut || abs(DATA.good_jet_eta->at(0))>jet_eta_cut || abs(DATA.good_muon_eta->at(0))>muon_eta_cut) continue;
             ++data_events;
             Hdata_jet_pt->Fill(DATA.good_jet_pt->at(0)); 

             float DR = deltaR(DATA.good_jet_eta->at(0),DATA.good_jet_phi->at(0),DATA.good_muon_eta->at(0),DATA.good_muon_phi->at(0));
	     Hdata_ratioPT_mu_jet->Fill(DATA.good_muon_pt->at(0)/DATA.good_jet_pt->at(0));
             Hdata_deltaR_no04_jet_mu->Fill(DR);
             if(DR>0.4){ ++nJets_offCone_data; HdeltaR_outOf04Cone_data->Fill(DR);}
	     else Hdata_deltaR_jet_mu->Fill(DR);

                                               }
     gStyle->SetLegendBorderSize(0);
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

     TCanvas *deltaR_outOf04Cone_canvas = new TCanvas("deltaR_outOf04Cone_canvas","deltaR_outOf04Cone_canvas");
     HdeltaR_outOf04Cone_data->Scale(1/HdeltaR_outOf04Cone_data->Integral("width"));
     HdeltaR_outOf04Cone_mc->Scale(1/HdeltaR_outOf04Cone_mc->Integral("width"));
     HdeltaR_outOf04Cone_data->Draw("hist,E");
     HdeltaR_outOf04Cone_mc->Draw("hist,E,sames");
     deltaR_outOf04Cone_canvas->BuildLegend(); 

     TCanvas *pT_jet_mu_ratio_canvas = new TCanvas("pT_jet_mu_ratio_canvas","pT_jet_mu_ratio_canvas");
     Hdata_ratioPT_mu_jet->Scale(1/Hdata_ratioPT_mu_jet->Integral("width"));
     Hmc_ratioPT_mu_jet->Scale(1/Hmc_ratioPT_mu_jet->Integral("width"));
     Hdata_ratioPT_mu_jet->Draw("hist,E");
     Hmc_ratioPT_mu_jet->Draw("hist,E,sames");
     pT_jet_mu_ratio_canvas->BuildLegend();

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

     TFile *output_file = new TFile("data_vs_mc_plots.root","recreate");
     mc_vs_data_jet_canvas->Write();
     deltaR_canvas->Write();
     deltaR_outOf04Cone_canvas->Write();
     deltaR_no04_canvas->Write();
     pT_jet_mu_ratio_canvas->Write();

     printf("Number of MC events that passed all cuts & criteria: %i. Number of Jets with deltaR(jet,mu)>0.4: %i, perc=%f %%\n",mc_events,nJets_offCone_mc,100.*nJets_offCone_mc/mc_events);
     printf("Number of DATA events that passed all cuts & criteria: %i. Number of Jets with deltaR(jet,mu)>0.4: %i, perc=%f %%\n",data_events,nJets_offCone_data,100.*nJets_offCone_data/data_events);
     delete output_file;
}
