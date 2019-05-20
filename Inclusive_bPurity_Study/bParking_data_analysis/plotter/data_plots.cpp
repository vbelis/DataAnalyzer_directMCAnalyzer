
//Vasilis Belis: 12/2/2019. Inclusive bPurity study, data plots. Extraction of b Fraction with pt_rel plots of muons. 
////
#include "tree_class.h"


void data_plots(){ 

     float pt_muon_cut=9.,pt_jet_cut=5.;
	TChain *ch1 = new TChain("mytree");

        ch1->Add("/afs/cern.ch/work/v/vbelis/private/Inclusive_bPurity_data/data_*04*.root");
        TH1F * Hdata_pt_rel = new TH1F("Hdata_pt_rel","p_{T}^{rel}(muon) from BParking dataset;p_{T}^{rel} [GeV];",60,0.,6.5);
        TH1F * Hdata_pt_rel_no_dif = new TH1F("Hdata_pt_rel_no_dif","p_{T}^{rel}(muon) (no dif) from BParking dataset ;p_{T}^{rel} [GeV];",60,0.,6.5);
        TH1F * Hdata_muon_pt = new TH1F("Hdata_muon_pt","Muon p_{T} from BParking dataset; p_{T}[GeV];",70,pt_muon_cut,100.);
        TH1F * Hdata_jet_pt = new TH1F("Hdata_jet_pt","Jet p_{T} from BParking dataset; p_{T}[GeV];",70,pt_jet_cut,300.);
        TH1F * Hdata_deltaR_jet_mu = new TH1F("Hdata_deltaR_jet_mu","#Delta R(jet-mu); #Delta R",50, 0.,2.5);

	tree_class data;
	data.Init(ch1,"ALL");

	int nentries= ch1->GetEntries();
	cout<<"Total analyzed events/entries: "<<nentries<<endl;
  
	for(int ientry=0;ientry<nentries;++ientry){
		data.GetEntry(ientry);
                int nmuons=data.pt_rel->size();
		for(int imuon=0;imuon<nmuons;++imuon){

			Hdata_pt_rel->Fill(data.pt_rel->at(imuon));
                        Hdata_pt_rel_no_dif->Fill(data.pt_rel_no_dif->at(imuon));
                        Hdata_muon_pt->Fill(data.good_muon_pt->at(imuon));
                        Hdata_jet_pt->Fill(data.good_jet_pt->at(imuon));
			Hdata_deltaR_jet_mu->Fill(data.muon_jet_deltaR->at(imuon));                          
                                                    }

		                                  }
	Hdata_pt_rel->Sumw2();
        Hdata_pt_rel_no_dif->Sumw2();
        Hdata_muon_pt->Sumw2(); 


	TCanvas * canvas1 = new TCanvas("pt_rel_data plot");
	Hdata_pt_rel->Draw("hist");
        TCanvas * canvas2 = new TCanvas("pt_rel_data_no_dif plot");
        Hdata_pt_rel_no_dif->Draw("hist");

        auto Hdata_pt_rel_norm= new TH1F (*Hdata_pt_rel);
        Hdata_pt_rel_norm->SetTitle("Hdata_pt_rel_norm");
        Hdata_pt_rel_norm->SetName("Hdata_pt_rel_norm");
        Hdata_pt_rel_norm->Scale(1/Hdata_pt_rel_norm->Integral("width"));
        auto Hdata_pt_rel_no_dif_norm= new TH1F (*Hdata_pt_rel_no_dif);
        Hdata_pt_rel_no_dif_norm->SetTitle("Hdata_pt_rel_no_dif_norm");
        Hdata_pt_rel_no_dif_norm->SetName("Hdata_pt_rel_no_dif_norm");
        Hdata_pt_rel_no_dif_norm->Scale(1/Hdata_pt_rel_no_dif_norm->Integral("width"));

        auto Hdata_muon_pt_norm= new TH1F (*Hdata_muon_pt);
        Hdata_muon_pt_norm->SetTitle("Hdata_muon_pt_norm");
        Hdata_muon_pt_norm->SetName("Hdata_muon_pt_norm");
        Hdata_muon_pt_norm->Scale(1/Hdata_muon_pt_norm->Integral("width"));



	TFile * data_output = new TFile("TESSSST_data_output_plots.root","recreate");
        Hdata_muon_pt->Write();
        Hdata_muon_pt_norm->Write();
        Hdata_jet_pt->Write();
	Hdata_pt_rel->Write();
        Hdata_pt_rel_norm->Write();
        Hdata_pt_rel_no_dif->Write();
        Hdata_pt_rel_no_dif_norm->Write();
        Hdata_deltaR_jet_mu->Write();
          
	delete data_output;

}
