
//Vasilis Belis, 06/02/2019: File for inclusive pT_rel calculation in the BParking dataset(2018)
#include "tree_class.h"
#include "DataFormats/Math/interface/deltaR.h"
//#include "DataFormats/JetReco/interface/PFJet.h"
void data_analysis(){

   float mu_pt_cut=5., mu_eta_cut=1.5;
   float jet_pt_cut=5., jet_eta_cut=2.1;  

   TChain *c_data = new TChain("demo/mytree");

   for(int ifile=76;ifile<=151;++ifile){
   TString path_to_input;
   path_to_input.Form("/eos/cms/store/cmst3/group/bpark/gkaratha/Parking_2018B_9_DstarMuNu3/ParkingBPH5/crab_Parking_2018B_9_DstarMuNu3/190108_091150/0000/output_dstar_%i.root",ifile);
   c_data->Add(path_to_input);
//   c_data->Add("/eos/cms/store/cmst3/group/bpark/gkaratha/Parking_2018B_9_DstarMuNu3/ParkingBPH5/crab_Parking_2018B_9_DstarMuNu3/190108_091150/0000/output_dstar*.root");
                                      }

   TTree * t2 = new TTree("mytree","mytree");//output analysis tree
   vector<float> recoJet_collection_pt,recoJet_collection_eta,recoJet_collection_phi,HLT1_muon_reco_reldelta_pt,HLT1_muon_reco_delta_eta,HLT1_muon_reco_delta_phi,HLT1_muon_reco_deltaR,good_muon_pt,good_muon_eta,good_muon_phi,good_jet_pt,good_jet_eta,good_jet_phi,muon_jet_pt_ratio,muon_jet_deltaR;
   vector<float> pt_rel,pt_rel_no_dif;//We may have/want 1 muon + jet in this analysis, but for generality we vectors for tree leaf objects.
   vector<float> no_04_good_muon_pt,no_04_good_muon_eta,no_04_good_muon_phi,no_04_good_jet_pt,no_04_good_jet_eta,no_04_good_jet_phi,no_04_muon_jet_pt_ratio,no_04_muon_jet_deltaR;
   vector<float> no_04_pt_rel,no_04_pt_rel_no_dif;//We may have/want 1 muon + jet in this analysis, but for generality we vectors for tree leaf objects.


   t2->Branch("recoJet_collection_pt",&recoJet_collection_pt);
   t2->Branch("recoJet_collection_eta",&recoJet_collection_eta);
   t2->Branch("recoJet_collection_phi",&recoJet_collection_phi);
   t2->Branch("HLT1_muon_reco_reldelta_pt",&HLT1_muon_reco_reldelta_pt);
   t2->Branch("HLT1_muon_reco_delta_eta",&HLT1_muon_reco_delta_eta);
   t2->Branch("HLT1_muon_reco_delta_phi",&HLT1_muon_reco_delta_phi);
   t2->Branch("HLT1_muon_reco_deltaR",&HLT1_muon_reco_deltaR);
   t2->Branch("good_muon_pt",&good_muon_pt);
   t2->Branch("good_muon_eta",&good_muon_eta);
   t2->Branch("good_muon_phi",&good_muon_phi);
   t2->Branch("good_jet_pt",&good_jet_pt);
   t2->Branch("good_jet_eta",&good_jet_eta);
   t2->Branch("good_jet_phi",&good_jet_phi);
   t2->Branch("muon_jet_pt_ratio",&muon_jet_pt_ratio);
   t2->Branch("muon_jet_deltaR",&muon_jet_deltaR);
   t2->Branch("pt_rel",&pt_rel);
   t2->Branch("pt_rel_no_dif",&pt_rel_no_dif);
   t2->Branch("no_04_good_muon_pt",&no_04_good_muon_pt);
   t2->Branch("no_04_good_muon_eta",&no_04_good_muon_eta);
   t2->Branch("no_04_good_muon_phi",&no_04_good_muon_phi);
   t2->Branch("no_04_good_jet_pt",&no_04_good_jet_pt);
   t2->Branch("no_04_good_jet_eta",&no_04_good_jet_eta);
   t2->Branch("no_04_good_jet_phi",&no_04_good_jet_phi);
   t2->Branch("no_04_muon_jet_pt_ratio",&no_04_muon_jet_pt_ratio);
   t2->Branch("no_04_muon_jet_deltaR",&no_04_muon_jet_deltaR);
   t2->Branch("no_04_pt_rel",&no_04_pt_rel);
   t2->Branch("no_04_pt_rel_no_dif",&no_04_pt_rel_no_dif);

   tree_class data;
   data.Init(c_data,"JET_MUON_L1");
   int nevents=c_data->GetEntries();
   cout<<"Entries/Events= " <<nevents<<endl;
   bool excludeSeedL1Mu22=true;//exclude eventst that uniquely fire seed_6 (i.e. L1Mu22) trigger

    for(int ievent=0;ievent<nevents;++ievent){
        data.GetEntry(ievent);

        if(data.HLT_path1 != 1) continue;//Want muons that fire the Mu9_Ip6 trigger.
        if (excludeSeedL1Mu22){//exclude seed_6-only events
        if (data.L1_seed1==0 && data.L1_seed2==0 && data.L1_seed3==0 && data.L1_seed4==0 && data.L1_seed5==0 && data.L1_seed6==1) continue;
                              }
           //1. Pick the highest pT muon that fired the HLT1 trigger(Mu9-IP6) and has |eta|<1.5.   
           float maxpt=0; int trg_index=-1;
           for (int itrg=0; itrg<data.HLT1Obj_pt_eta_phi_charge->size(); ++itrg){
                    if (maxpt>data.HLT1Obj_pt_eta_phi_charge->at(itrg).at(0))  continue;
                    if (fabs(data.HLT1Obj_pt_eta_phi_charge->at(itrg).at(1))>1.5) continue;
                        maxpt=data.HLT1Obj_pt_eta_phi_charge->at(itrg).at(0);
                        trg_index=itrg;
                                    }
           if(trg_index==-1) continue;//If no HLT1 muon passed ALL the requirements then skip event. ALSO: caution on unsigned long int -> int conversion

         //2. Save reco Jets, which pass the kinematic cuts and have tigth id (defined: https://twiki.cern.ch/twiki/bin/view/CMS/JetID13TeVRun2017)
          recoJet_collection_pt.clear(),recoJet_collection_eta.clear(),recoJet_collection_phi.clear();
          HLT1_muon_reco_reldelta_pt.clear(),HLT1_muon_reco_delta_eta.clear(),HLT1_muon_reco_delta_phi.clear(),HLT1_muon_reco_deltaR.clear();
          good_muon_pt.clear(),good_muon_eta.clear(),good_muon_phi.clear(),good_jet_pt.clear(),good_jet_eta.clear(),good_jet_phi.clear();
          muon_jet_deltaR.clear(),muon_jet_pt_ratio.clear(),pt_rel.clear(),pt_rel_no_dif.clear();
         no_04_good_muon_pt.clear(),no_04_good_muon_eta.clear(),no_04_good_muon_phi.clear(),no_04_good_jet_pt.clear(),no_04_good_jet_eta.clear(),no_04_good_jet_phi.clear();
         no_04_muon_jet_deltaR.clear(),no_04_muon_jet_pt_ratio.clear(),no_04_pt_rel.clear(),no_04_pt_rel_no_dif.clear();

          for(unsigned int ijet=0;ijet<data.jet_pt->size();++ijet){
            if(data.jet_pt->at(ijet)<=jet_pt_cut || fabs(data.jet_eta->at(ijet))>=jet_eta_cut) continue;//kinematic cuts
            if(data.jet_nHEF->at(ijet)>=0.90 || data.jet_nEmEF->at(ijet)>=0.90 || (data.jet_nMult->at(ijet)+data.jet_cMult->at(ijet))<=1 || data.jet_cHEF->at(ijet)<=0 || data.jet_cMult->at(ijet)<=0) continue;//tight Jet ID condition.
              recoJet_collection_pt.push_back(data.jet_pt->at(ijet));
              recoJet_collection_eta.push_back(data.jet_eta->at(ijet));
              recoJet_collection_phi.push_back(data.jet_phi->at(ijet));
              //printf("-Collected Jet in event '%i': pT/eta/phi= %f/%f/%f \n",ievent,data.jet_pt->at(ijet),data.jet_eta->at(ijet),data.jet_phi->at(ijet));


                                                                  }        
        
        if(recoJet_collection_pt.size()==0) continue;//Muon must be within a Jet.

/*
       for(unsigned long int i=0;i<data.HLT1Obj_pt_eta_phi_charge->size();++i){
       cout<<"--HLT1 Muon in event '"<<ievent<<"', pT/eta= "<<data.HLT1Obj_pt_eta_phi_charge->at(i).at(0)<<"/"<<data.HLT1Obj_pt_eta_phi_charge->at(i).at(1)<<"\n";
                                                                              }
*/
           //3. Match the reconstructed muon_* objects to the the muon that fired the HLT1 trigger to maximize the "quality" of detected muon.
            float minDR=10000;
            int good_muon_index=-1;
            float pt_hlt1=data.HLT1Obj_pt_eta_phi_charge->at(trg_index).at(0),eta_hlt1=data.HLT1Obj_pt_eta_phi_charge->at(trg_index).at(1),phi_hlt1=data.HLT1Obj_pt_eta_phi_charge->at(trg_index).at(2);
            for(unsigned int imuon=0;imuon<data.muon_pt->size();++imuon){
               if(!data.muon_soft->at(imuon)) continue;//wanting soft muon ID.
               if(data.muon_pt->at(imuon)<mu_pt_cut || fabs(data.muon_eta->at(imuon))>mu_eta_cut) continue;
               if(fabs(data.muon_dxy->at(imuon)/data.muon_edxy->at(imuon))<5) continue;//IP="muon Impact Parameter" condition
//               cout<<"@@@@@@@@@@@@@@@@@@@@@@muon_* size= "<<data.muon_pt->size()<<"\n";
		float rel_deltapT=(-data.muon_pt->at(imuon)+pt_hlt1)/data.muon_pt->at(imuon);
		float deltaEta=data.muon_eta->at(imuon)-eta_hlt1;
		float deltaPhi=data.muon_phi->at(imuon)-phi_hlt1;
		float DR=deltaR(data.muon_eta->at(imuon),data.muon_phi->at(imuon),eta_hlt1,phi_hlt1);
//                      printf("delta(HLT1-mu)/pt(mu)/-/deltaEta/-/deltaPhi/-/deltaR(mu-HLT1) = %f/-/%f/-/%f/-/%f\n",rel_deltapT,deltaEta,deltaPhi,DR); 
                      if(DR>=minDR) continue;
                       minDR=DR;
                       good_muon_index=imuon;
                                                                       }
          //4. Check if HLT-muon_leaf(reco) match is considered good.
          if(minDR>=0.03 || good_muon_index==-1 || fabs((-data.muon_pt->at(good_muon_index)+pt_hlt1)/data.muon_pt->at(good_muon_index))>0.4) continue;
          HLT1_muon_reco_reldelta_pt.push_back((-data.muon_pt->at(good_muon_index)+pt_hlt1)/data.muon_pt->at(good_muon_index));
          HLT1_muon_reco_delta_eta.push_back(data.muon_eta->at(good_muon_index)-eta_hlt1);
          HLT1_muon_reco_delta_phi.push_back(data.muon_phi->at(good_muon_index)-phi_hlt1);
          HLT1_muon_reco_deltaR.push_back(deltaR(data.muon_eta->at(good_muon_index),data.muon_phi->at(good_muon_index),eta_hlt1,phi_hlt1));
          good_muon_pt.push_back(data.muon_pt->at(good_muon_index));
          good_muon_eta.push_back(data.muon_eta->at(good_muon_index));
          good_muon_phi.push_back(data.muon_phi->at(good_muon_index));
     
         //5. Match a collected jet to a good_muon.
         if(good_muon_pt.size()>1){cout<<"========================MORE THAN ONE MUON WTFFFFFFFFFFFFFF================="<<endl; break;}

         int matched_jet=-1;
             minDR=10000;
            for(unsigned int ijet=0;ijet<recoJet_collection_pt.size();++ijet){
               float DR=deltaR(good_muon_eta.at(0),good_muon_phi.at(0),recoJet_collection_eta.at(ijet),recoJet_collection_phi.at(ijet));
               //cout<<"----delta(muon-jet)= "<<DR<<endl;
                if(DR>=minDR) continue;
                  minDR=DR;
                  matched_jet=ijet;
                                                                             }
//              if(matched_jet==-1 || minDR>=0.4) continue;//Only events wuth matched mu-jet are accepted for the final analysis.
              if(matched_jet==-1){ cout<<"============+++!!!!!!!!!! WTF HAPPENED!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl; break;}
//(23.04.19): Lifting the DR<0.4 requirement for the mu-jet and pT_jet_cut=5.
              cout<<"================= EVENT: '"<<ievent<<" ================='"<<"\n";
              cout<<"HLT1 Muon: pT/eta/DR(mu-Jet)= "<<good_muon_pt.at(0)<<"/"<<good_muon_eta.at(0)<<"/"<<minDR<<endl;
//              cout<<"Matched good Jet: pT/deltaR(muon-jet)"<<recoJet_collection_pt.at(matched_jet)<<"/"<<minDR<<endl;

              TLorentzVector p4_mu;
              p4_mu.SetPtEtaPhiM(good_muon_pt.at(0),good_muon_eta.at(0),good_muon_phi.at(0),0.10566);              
              TVector3 p_jet,p_mu;
                float   px_jet = recoJet_collection_pt.at(matched_jet) * cos(recoJet_collection_phi.at(matched_jet));
                float   py_jet = recoJet_collection_pt.at(matched_jet) * sin(recoJet_collection_phi.at(matched_jet));
                float   pz_jet = recoJet_collection_pt.at(matched_jet) * sinh(recoJet_collection_eta.at(matched_jet));
              p_jet.SetXYZ(px_jet,py_jet,pz_jet);
              p_mu=p4_mu.Vect();

              pt_rel_no_dif.push_back((p_mu.Cross(p_jet)).Mag()/p_jet.Mag()); 
              p_jet=p_jet-p_mu;   //CRITICALLLLLLLL!!!!       

              pt_rel.push_back((p_mu.Cross(p_jet)).Mag()/p_jet.Mag());
 
              good_jet_pt.push_back(recoJet_collection_pt.at(matched_jet));
              good_jet_eta.push_back(recoJet_collection_eta.at(matched_jet));
              good_jet_phi.push_back(recoJet_collection_phi.at(matched_jet));
                         
              muon_jet_deltaR.push_back(minDR);
              muon_jet_pt_ratio.push_back(good_muon_pt.at(0)/recoJet_collection_pt.at(matched_jet));
          //Save the DR>0.4 individually just in case...    
              if(minDR>=0.4){
                 no_04_good_muon_pt.push_back(data.muon_pt->at(good_muon_index));
                 no_04_good_muon_eta.push_back(data.muon_eta->at(good_muon_index));
                 no_04_good_muon_phi.push_back(data.muon_phi->at(good_muon_index));
                 p_jet.SetXYZ(px_jet,py_jet,pz_jet);
                 p_mu=p4_mu.Vect();

                 no_04_pt_rel_no_dif.push_back((p_mu.Cross(p_jet)).Mag()/p_jet.Mag()); 
                 p_jet=p_jet-p_mu;   //CRITICALLLLLLLL!!!!       

                 no_04_pt_rel.push_back((p_mu.Cross(p_jet)).Mag()/p_jet.Mag());
 
                 no_04_good_jet_pt.push_back(recoJet_collection_pt.at(matched_jet));
                 no_04_good_jet_eta.push_back(recoJet_collection_eta.at(matched_jet));
                 no_04_good_jet_phi.push_back(recoJet_collection_phi.at(matched_jet));
                            
                 no_04_muon_jet_deltaR.push_back(minDR);
                 no_04_muon_jet_pt_ratio.push_back(good_muon_pt.at(0)/recoJet_collection_pt.at(matched_jet));
                            }
     
         t2->Fill();
                                            }


  TFile * output_file1 = new TFile("/afs/cern.ch/work/v/vbelis/private/Inclusive_bPurity_data/data_76to150_230419_noDR_04.root","RECREATE");

  gFile=output_file1; //For 100% safety
  output_file1->cd();

  gDirectory->pwd();//Check which is the current Directory

  t2->Write();
//  output_file1->Write();
//11/2/2019: Not sure whether I should let them on/off
  delete output_file1;
  delete t2;


}


