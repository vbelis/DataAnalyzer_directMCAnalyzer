
#include "DataFormats/Math/interface/deltaR.h"
#include "tree_class.h"


void plotter(){
     float muon_pt_cut=8.;
     float xsec_15to20 = 2799000.0,xsec_20to30 = 2526000.0,xsec_30to50 = 1362000.0,xsec_50to80 = 376600.0, xsec_80to120 = 88930.0, xsec_120to170 = 21230.0, xsec_170to300 = 7055.0;  
     //XSDB for DAS=QCD_Pt-*_MuEnrichedPt5_TuneCP5_13TeV_pythia8 
     float relative_weight_20to30=1.; //Let the relative statistical weight of the events be normalized according to the 20to30 xsec.
     float relative_weight_15to20 = xsec_15to20/xsec_20to30, relative_weight_30to50 = xsec_30to50/xsec_20to30, relative_weight_50to80=xsec_50to80/xsec_20to30, relative_weight_80to120=xsec_80to120/xsec_20to30, relative_weight_120to170=xsec_120to170/xsec_20to30,relative_weight_170to300=xsec_170to300/xsec_20to30;

     int nJets_offCone_mc=0, mc_events=0, nJets_offCone_data=0, data_events=0;
     std::vector<std::pair<std::string,float>> file_weight_pair={make_pair("15to20",relative_weight_15to20),make_pair("20to30",relative_weight_20to30),make_pair("30to50",relative_weight_30to50),make_pair("50to80",relative_weight_50to80),make_pair("80to120",relative_weight_80to120),make_pair("120to170",relative_weight_120to170),make_pair("170to300",relative_weight_170to300)};
     

     TChain *mc_chain = new TChain("demo/mytree");
//     mc_chain->Add("/afs/cern.ch/work/v/vbelis/private/MINIAOD_QCD_samples_15to300_pTrelCalc/*20to30*.root");     
//       mc_chain->Add("/afs/cern.ch/work/v/vbelis/private/*20to30*_25e4Evts*.root");
//       mc_chain->Add("/afs/cern.ch/work/v/vbelis/private/*15to20*_25e4Evts*.root");
       mc_chain->Add("/afs/cern.ch/work/v/vbelis/private/MINIAOD_QCD_samples_15to300_onlyMuon/*.root");
     int nentries = mc_chain->GetEntries();
//     int nentries = 1000;
     tree_class MC;
     MC.Init(mc_chain,"ALL");
     
     //TH1F *Hmc_bmuon_dir_pt = new TH1F("p_{T}(b#rightarrow#mu)",";p_{T}^{#mu} [GeV];Events/Bin",(int)(33-muon_pt_cut)/5,muon_pt_cut,33);
     TH1F *Hmc_bmuon_dir_pt = new TH1F("p_{T}(b#rightarrow#mu)",";p_{T}^{#mu} [GeV];Events/Bin",(int)(30-5)/5,5,30);
     Hmc_bmuon_dir_pt->SetLineWidth(2);
     Hmc_bmuon_dir_pt->SetLineColor(kBlue);
     Hmc_bmuon_dir_pt->SetTitleOffset(1);
      
     //TH1F *Hmc_bmuon_seq_pt = new TH1F("p_{T}(b#rightarrow c#rightarrow#mu)",";p_{T}^{#mu} [GeV];Events/Bin",(int)(33-muon_pt_cut)/5,muon_pt_cut,33);
     TH1F *Hmc_bmuon_seq_pt = new TH1F("p_{T}(b#rightarrowq#rightarrow#mu)",";p_{T}^{#mu} [GeV];Events/Bin",(int)(30-5)/5,5,30);
     Hmc_bmuon_seq_pt->SetLineWidth(2);
     Hmc_bmuon_seq_pt->SetLineColor(kRed);
     Hmc_bmuon_seq_pt->SetTitleOffset(1);

     //TH1F *Hmc_bmuon_pt = new TH1F("p_{T}(all #mu)",";p_{T}^{#mu} [GeV];Events/Bin",(int)(33-muon_pt_cut)/5,muon_pt_cut,33);
     TH1F *Hmc_bmuon_pt = new TH1F("p_{T}(tot. b#rightarrow#mu)",";p_{T}^{#mu} [GeV];Events/Bin",(int)(30-5)/5,5,30);
     Hmc_bmuon_pt->SetLineWidth(2);
     Hmc_bmuon_pt->SetLineColor(kGreen);
     Hmc_bmuon_pt->SetTitleOffset(1);


     




//     HdeltaR_outOf04Cone_mc->SetLineWidth(2);
//     HdeltaR_outOf04Cone_data->SetLineWidth(2);
//     HdeltaR_outOf04Cone_data->SetLineColor(kRed);

     cout<<"Analyzing "<<nentries<<" MC events"<<endl;
     for(int ievent=0;ievent<nentries;++ievent){
	     MC.GetEntry(ievent);
	     cout<<"iEvent= "<<ievent<<endl;
             std::string current_input_file(mc_chain->GetFile()->GetName());
	     //cout<<current_input_file<<endl;
	     if(MC.mub_dir_pt->size() != 0 || MC.mub_seq_pt->size()!=0){
	     int current_weight=-1;
                if(current_input_file.std::string::find("15to20") != std::string::npos) current_weight=0;
                else if(current_input_file.std::string::find("20to30") != std::string::npos) current_weight=1;
                else if(current_input_file.std::string::find("30to50") != std::string::npos)  current_weight=2;
                else if(current_input_file.std::string::find("50to80") != std::string::npos) current_weight=3;
                else if(current_input_file.std::string::find("80to120") != std::string::npos) current_weight=4;
                else if(current_input_file.std::string::find("120to170") != std::string::npos) current_weight=5;
                else if(current_input_file.std::string::find("170to300") != std::string::npos) current_weight=6;
//Fast indir/tot calculation for b->muon
            printf("sizes: mub_seq_pt/mub_dir_pt = %lu/%lu\n",MC.mub_seq_pt->size(),MC.mub_dir_pt->size());	     
             
	    if(MC.mub_seq_pt->size() != 0) {
		    int imax_pt=-1;
		    float max_pt=-1;
		    for(int imu=0;imu<MC.mub_seq_pt->size();++imu){
		       if(MC.mub_seq_pt->at(imu)<=max_pt) continue;
		       max_pt=MC.mub_seq_pt->at(imu);
		       imax_pt=imu;
		    }
		     if(MC.mub_seq_pt->at(imax_pt)<muon_pt_cut) continue;
		     cout<<"MC.mub_seq_pt->at(imax_pt)= "<<MC.mub_seq_pt->at(imax_pt)<<endl;
		     Hmc_bmuon_seq_pt->Fill(MC.mub_seq_pt->at(imax_pt),file_weight_pair.at(current_weight).second);
		     Hmc_bmuon_pt->Fill(MC.mub_seq_pt->at(imax_pt),file_weight_pair.at(current_weight).second);
		    }
	             if(MC.mub_dir_pt->size() != 0){
		    int imax_pt=-1;
		    float max_pt=-1;
		    for(int imu=0;imu<MC.mub_dir_pt->size();++imu){
		       if(MC.mub_dir_pt->at(imu)<=max_pt) continue;
		       max_pt=MC.mub_dir_pt->at(imu);
		       imax_pt=imu;
		    }
		     if(MC.mub_dir_pt->at(imax_pt)<muon_pt_cut) continue;
		     cout<<"MC.mub_dir_pt->at(imax_pt)= "<<MC.mub_dir_pt->at(imax_pt)<<endl;
		     Hmc_bmuon_dir_pt->Fill(MC.mub_dir_pt->at(imax_pt),file_weight_pair.at(current_weight).second);
		     Hmc_bmuon_pt->Fill(MC.mub_dir_pt->at(imax_pt),file_weight_pair.at(current_weight).second);
		    }
	     }//mu_size
                                                       }//MC_loop
     gStyle->SetLegendBorderSize(0);
     gROOT->SetBatch(kTRUE);//no graphical output on Draw()

     TFile *output_file = new TFile("onlyBMuon_dir-sec_MCplots.root","recreate");
//indir/tot calculation:
     TCanvas* bmuon_seq_dir_canvas = new TCanvas("bmuon_seq_dir_canvas","bmuon_seq_dir_canvas");
     TRatioPlot* bmuon_seq_dir_plot = new TRatioPlot(Hmc_bmuon_seq_pt,Hmc_bmuon_pt,"divsym");
     bmuon_seq_dir_plot->SetH1DrawOpt("hist,E,sames");
     bmuon_seq_dir_plot->SetH2DrawOpt("hist,E,sames");
     bmuon_seq_dir_plot->SetSeparationMargin(0.01);
     bmuon_seq_dir_plot->Draw();
     bmuon_seq_dir_plot->GetUpperRefYaxis()->SetTitleOffset(1.2);
     bmuon_seq_dir_plot->GetLowerPad()->GetTickx();
     bmuon_seq_dir_plot->GetLowerPad()->GetTicky();
     bmuon_seq_dir_plot->GetUpperRefYaxis()->SetRangeUser(0,Hmc_bmuon_pt->GetMaximum()*1.05);
     bmuon_seq_dir_plot->GetLowerRefYaxis()->SetTitle("#frac{N(b#rightarrowq#rightarrow#mu)}{N(tot. b#rightarrow#mu)}");
     bmuon_seq_dir_plot->GetLowerRefYaxis()->SetTitleOffset(1.2);
     bmuon_seq_dir_plot->GetLowerRefGraph()->SetLineColor(kBlack);
     bmuon_seq_dir_plot->GetUpperPad()->cd();
     Hmc_bmuon_dir_pt->Draw("hist,E,sames"); 
     bmuon_seq_dir_plot->GetUpperPad()->cd()->BuildLegend();

       TLatex * cms_logo = new TLatex(5.,Hmc_bmuon_pt->GetMaximum()*1.095,"#bf{CMS} #it{Simulation}");
              cms_logo->SetTextSize(0.065);
	      cms_logo->SetTextFont(42);
	      cms_logo->Draw("same");

     bmuon_seq_dir_canvas->Update();
      
     bmuon_seq_dir_canvas->Write();
     Hmc_bmuon_dir_pt->Write();
     Hmc_bmuon_seq_pt->Write();
     Hmc_bmuon_pt->Write();  
}
