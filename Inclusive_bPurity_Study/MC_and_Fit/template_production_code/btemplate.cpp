#include "tree_class.h"
//#include <vector>
//#include <map>
#include "math.h"
//#include "TTree.h"
//Aparently when compiling a c++ code using CINT -> ROOT framework/environment you do not need to include all standard libraries and classes.

//using namespace std;

     float Dphi(float phi1,float phi2){

      float result = phi1 - phi2;
      while (result > float(M_PI)) result -= float(2*M_PI);
      while (result <= -float(M_PI)) result += float(2*M_PI);

        return result;
                                                                   }

          
         float DR(float eta1,float phi1,float eta2, float phi2){
   
               return TMath::Sqrt((eta1-eta2)*(eta1-eta2)+Dphi(phi1,phi2)*Dphi(phi1,phi2));
                                                                                                         }




void banalysis(){ 

   float pt_cut=9., eta_cut=1.5;
   //float jet_pt_cut=25., jet_eta_cut=2.1;
   float jet_pt_cut=10., jet_eta_cut=2.1;

      TChain * chain1= new TChain("/demo/mytree");//A TChain is a collection of TFile objects. the first parameter "name" is the name of the TTree object in the files added with Add. Use TChain::Add to add a new element to this chain.
//      TFile * file1 = new TFile("final_matching_4.root");  
//  TTree * t1 = (TTree *)file1->Get("demo/mytree");
//   chain1->Add("../QCD_Pt15-1000_das_sample/*.root");

//    chain1->Add("../DAS_sample_first_bPurity_result_080419/*part4*.root");
    chain1->Add("../../samples/Main_DAS_AOD-MINIAOD_samples/*.root");
    TFile * file2 = new TFile("../../templates/b_template_QCD_Pt-15to300_10JetpTcut.root","RECREATE");



//    TFile * file2 = new TFile("b_template_QCD_Pt15-1000.root","RECREATE");

  TH1F * HgenMuB_pt=new TH1F("HgenMuB_pt","Generated muons p_{T};p_{T} [GeV];entries/bin",70,pt_cut-0.2,32.);
  TH1F * HgenMuB_eta=new TH1F("HgenMuB_eta","Generated muons #eta^{gen};#eta^{gen};entries/bin",70,-eta_cut-0.8,eta_cut+0.8);

  TH1F * Hrecomu_unmatched_pt=new TH1F("Hrecomu_unmatched_pt","Reconstructed unmatched muons p_{T};p_{T} [GeV];entries/bin",70,0.,32.);
  TH1F * Hrecomu_unmatched_eta=new TH1F("Hrecomu_unmatched_eta","Reconstructed unmatched muons #eta^{reco};#eta^{reco};entries/bin",70,-4.,4.);

  TH1F * HDR=new TH1F("HDR","#Delta R (gen-reco);entries/bin",70,0.,0.05);

  TH1F * Hrecomu_pt=new TH1F("Hrecomu_pt","Reconstructed & matched muons p_{T};p_{T} [GeV];entries/bin",70,pt_cut,100.);
  TH1F * Hrecomu_eta=new TH1F("Hrecomu_eta","Reconstructed & matched muons #eta^{reco};#eta^{reco};entries/bin",70,-eta_cut-0.8,eta_cut+0.8);
  TH1F * Hrecomu_phi=new TH1F("Hrecomu_phi","Reconstructed & matched muons #phi^{reco};#phi^{reco};entries/bin",70,-eta_cut-0.8,eta_cut+0.8);
  TH1F * Hrecomu_final_pt=new TH1F("Hrecomu_final_pt","Reconstructed & matched muons p_{T};p_{T} [GeV];entries/bin",70,pt_cut,100.);
   TH1F *HDR_jet = new TH1F("HDR_jet","#Delta R between matched reco muon and reco jet",50,0,0.5);
/*//same as recoJet_* leaf
  TH1F * Hrecojet_unmatched_pt=new TH1F("Hrecojet_unmatched_pt","Reconstructed unmatched Jets p_{T};p_{T} [GeV];entries/bin",70,jet_pt_cut-5.,100.);
  TH1F * Hrecojet_unmatched_eta=new TH1F("Hrecojet_unmatched_eta","Reconstructed unmatched Jets #eta^{reco};#eta^{reco};entries/bin",70,-3.5,3.5);
  TH1F * Hrecojet_unmatched_phi=new TH1F("Hrecojet_unmatched_phi","Reconstructed unmatched Jets #phi^{reco};#phi^{reco};entries/bin",70,-3.5,3.5);
  TH1F * Hrecojet_unmatched_number=new TH1F("Hrecojet_unmatched_number"," Number of reconstructed unmatched Jets per event;#eta^{reco};entries/bin",20,0.,20.);
*/
  TH1F * Hrecojet_pt=new TH1F("Hrecojet_pt","Reconstructed matched Jets p_{T};p_{T} [GeV];entries/bin",70,jet_pt_cut,300.);
  TH1F * Hrecojet_eta=new TH1F("Hrecojet_eta","Reconstructed matched Jets #eta^{reco};#eta^{reco};entries/bin",70,-3.5,3.5);
  TH1F * Hrecojet_phi=new TH1F("Hrecojet_phi","Reconstructed matched Jets #phi^{reco};#phi^{reco};entries/bin",70,-3.5,3.5);

  TH1F * Hmu_reco_vs_gen_pt = new TH1F("Hmu_reco_vs_gen_pt","Relative difference between the p_{T} of reco and gen muons;#frac{p_{T}^{gen}-p_{T}^{reco}}{p_{T}^{gen}};entries/bin",70,-0.1,0.1);
  TH1F * Hmu_reco_vs_gen_eta = new TH1F("Hmu_reco_vs_gen_eta","Difference between the #eta of reco and gen muons;#eta^{gen}-#eta^{reco};entries/bin",70,-0.05,0.05);
  TH1F * Hmu_reco_vs_gen_phi = new TH1F("Hmu_reco_vs_gen_phi","Difference between the #phi of reco and gen muons;#phi^{gen}-#phi^{reco};entries/bin",70,-0.05,0.05);

  TH1F * Hpt_rel = new TH1F("Hpt_rel","Reco muon p_{T}^{rel} momentum to the b jet;p_{T}^{rel} [GeV];entries/bin",60,0.,6.5);
  TH1F * Hpt_rel_no_dif = new TH1F("Hpt_rel_no_dif","Reco muon p_{T}^{rel} momentum to the b jet;p_{T}^{rel} [GeV];entries/bin",60,0.,6.5);
  TH1F * Hpt_rel_gen = new TH1F("Hpt_rel_gen","Gen muon p_{T}^{rel} momentum to the b jet;p_{T}^{rel} [GeV];entries/bin",60,0.,6.5);
 // TH1F * Hpt_rel_gen_vs_reco = new TH1F("Hpt_rel_gen_vs_reco","p_{T}^{rel}(gen) -vs- p_{T}^{rel}(reco);p_{T}^{rel} [GeV];entries/bin",60,0.,4.5);

  TH2F * Hmuon_pt_rel_pt = new TH2F("Hmuon_pt_rel_pt",";p_{T}(b#rightarrow #mu+X) [GeV];p_{T}^{rel}(b#rightarrow #mu+X) [GeV]",70,pt_cut,45.,60,0.,6.5);
  TH2F * Hmuon_pt_rel_pt_no_dif = new TH2F("Hmuon_pt_rel_pt_no_dif",";p_{T}(b#rightarrow #mu+X) [GeV];p_{T}^{rel}(b#rightarrow #mu+X) [GeV]",70,pt_cut,45.,60,0.,6.5); 

  //1.04.19: This is to check "how a different pT spectrum affects the pTrel distribution.  You need a few plots of pTrel vs pT, the projections, and a few (2-3) pTrel distributions for different ranges in pT(muon)":
  float min_1,max_1,max_2;
  min_1=9.,max_1=12.,max_2=17.;
  TH1F *Hpt_rel_range1 = new TH1F("Hpt_rel_range_9to12",("p_{T}^{rel}(b#rightarrow #mu +X): "+std::to_string((int)min_1)+"#leq p_{T}(#mu)#leq"+std::to_string((int)max_1)+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);
  TH1F *Hpt_rel_range2 = new TH1F("Hpt_rel_range_12to17",("p_{T}^{rel}(b#rightarrow #mu +X): "+std::to_string((int)max_1)+"<p_{T}(#mu)#leq"+std::to_string((int)max_2)+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);
  TH1F *Hpt_rel_range3 = new TH1F("Hpt_rel_range_17toInf",("p_{T}^{rel}(b#rightarrow #mu +X): "+std::to_string((int)max_2)+"<p_{T}(#mu)"+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);

  TH1F *Hpt_rel_range1_no_dif = new TH1F("Hpt_rel_range_9to12_no_dif",("p_{T}^{rel}(b#rightarrow #mu +X): "+std::to_string((int)min_1)+"#leq p_{T}(jet)#leq"+std::to_string((int)max_1)+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);
  TH1F *Hpt_rel_range2_no_dif = new TH1F("Hpt_rel_range_12to17_no_dif",("p_{T}^{rel}(b#rightarrow #mu +X): "+std::to_string((int)max_1)+"<p_{T}(jet)#leq"+std::to_string((int)max_2)+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);
  TH1F *Hpt_rel_range3_no_dif = new TH1F("Hpt_rel_range_17toinf_no_dif",("p_{T}^{rel}(b#rightarrow #mu +X): "+std::to_string((int)max_2)+"<p_{T}(jet)"+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);

 //2.04.19: Lets check the flactuation of pT_rel distribution due to different pT(Jet) bins. Ideally there should be none due to invariance of pT_rel under boosts along the momentum axis of the quark. However, pT(Jet) != pT(quark) most of the times. Also not symmetric around pT(quark)/pT(jet)=1.
  float jet_min_1,jet_max_1,jet_max_2;
  jet_min_1=25.,jet_max_1=50.,jet_max_2=75.;
  TH1F *Hpt_rel_jet_range1 = new TH1F("Hpt_rel_jet_25to75",("p_{T}^{rel}(b#rightarrow #mu+X): "+std::to_string((int)jet_min_1)+"#leq p_{T}(#mu)#leq"+std::to_string((int)jet_max_1)+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);
  TH1F *Hpt_rel_jet_range2 = new TH1F("Hpt_rel_jet_75to150",("p_{T}^{rel}(b#rightarrow #mu+X): "+std::to_string((int)jet_max_1)+"#leq p_{T}(#mu)#leq"+std::to_string((int)jet_max_2)+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);
  TH1F *Hpt_rel_jet_range3 = new TH1F("Hpt_rel_jet_150toInf",("p_{T}^{rel}(b#rightarrow #mu +X): "+std::to_string((int)jet_max_2)+"< p_{T}(#mu)"+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);

  TH1F *Hpt_rel_jet_range1_no_dif = new TH1F("Hpt_rel_jet_25to50_no_dif",("p_{T}^{rel}(b#rightarrow #mu+X): "+std::to_string((int)jet_min_1)+"#leq p_{T}(jet)#leq"+std::to_string((int)jet_max_1)+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);
  TH1F *Hpt_rel_jet_range2_no_dif = new TH1F("Hpt_rel_jet_50to75_no_dif",("p_{T}^{rel}(b#rightarrow #mu+X): "+std::to_string((int)jet_max_1)+"#leq p_{T}(jet)#leq"+std::to_string((int)jet_max_2)+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);
  TH1F *Hpt_rel_jet_range3_no_dif = new TH1F("Hpt_rel_jet_75toInf_no_dif",("p_{T}^{rel}(b#rightarrow #mu +X): "+std::to_string((int)jet_max_2)+"< p_{T}(jet)"+";p_{T}^{rel} [GeV];entries/bin").c_str(),60,0.,6.5);

  TTree tree1("output_matching", "output_matching");
vector<float> GENMUB_PT,GENJET_PT;//for pt(mu)-vs-pt(jet) and pt(mu)-vs-pt(jet).

vector<float>  genJet_pt,genJet_eta,genJet_phi, genJet_mass,recoJet_pt,recoJet_eta,recoJet_phi, recoJet_mass, genJet_recoJet_deltaR,genJet_vs_recoJet_pt,genJet_vs_recoJet_eta,genJet_vs_recoJet_phi;
vector<float>  GENMuB_pt,GENMuB_eta,GENMuB_phi,GENpt_rel,GENpt_rel_no_dif,pt_rel_diff,GEN_jet_mu_DR;
  //recoJet= reconstructed jet that got matched with a genJet 

   tree1.Branch("genJet_pt",&genJet_pt);
   tree1.Branch("genJet_eta",&genJet_eta);
   tree1.Branch("genJet_phi",&genJet_phi);
   tree1.Branch("genJet_mass",&genJet_mass);
   tree1.Branch("recoJet_pt",&recoJet_pt);
   tree1.Branch("recoJet_eta",&recoJet_eta);
   tree1.Branch("recoJet_phi",&recoJet_phi);
   tree1.Branch("recoJet_mass",&recoJet_mass);
   tree1.Branch("genJet_recoJet_deltaR",&genJet_recoJet_deltaR);
   tree1.Branch("genJet_vs_recoJet_pt",&genJet_vs_recoJet_pt);
   tree1.Branch("genJet_vs_recoJet_eta",&genJet_vs_recoJet_eta);
   tree1.Branch("genJet_vs_recoJet_phi",&genJet_vs_recoJet_phi);
   tree1.Branch("GENMuB_pt",&GENMuB_pt);
   tree1.Branch("GENMuB_eta",&GENMuB_eta);
   tree1.Branch("GENMuB_phi",&GENMuB_phi);
   tree1.Branch("GENpt_rel",&GENpt_rel);
   tree1.Branch("GENpt_rel_no_dif",&GENpt_rel_no_dif);
   tree1.Branch("pt_rel_diff",&pt_rel_diff);
   tree1.Branch("GEN_jet_mu_DR", &GEN_jet_mu_DR);
  


  tree_class MC;
//  MC.Init(t1,"GENMU_JET_MUON_GENJET");
    MC.Init(chain1,"GENMU_JET_MUON_GENJET");
//  int nentries=t1->GetEntries();
    int nentries=chain1->GetEntries();
  int genmuons,unmatched_recomuons,unmatched_recojets,recomuons,recojets;//recomuons=#of all reco muons per event, recojets=#of all matched reco jets per event  

//07.04.19: Required modification for using events with weight != 1. Relative weight of events is given by the cross_section of the events. Name of input_file is needed to pinpoint the events and weight them.
   float xsec_15to20 = 2799000.0,xsec_20to30 = 2526000.0,xsec_30to50 = 1362000.0,xsec_50to80 = 376600.0, xsec_80to120 = 88930.0, xsec_120to170 = 21230.0, xsec_170to300 = 7055.0; /*xsec_300to470 =*/ /*no_XSDB_info...*/ 
   //XSDB for DAS=QCD_Pt-*_MuEnrichedPt5_TuneCP5_13TeV_pythia8
   //have to be read from files which have the cross_section values for the ranges, according to the SIM templates.

   float relative_weight_20to30=1.; //Let the relative statistical weight of the events be normalized according to the 20to30 xsec.
   float relative_weight_15to20 = xsec_15to20/xsec_20to30, relative_weight_30to50 = xsec_30to50/xsec_20to30, relative_weight_50to80=xsec_50to80/xsec_20to30, relative_weight_80to120=xsec_80to120/xsec_20to30, relative_weight_120to170=xsec_120to170/xsec_20to30,
   relative_weight_170to300=xsec_170to300/xsec_20to30;


   cout<<"Number of analyzed events: " <<nentries<<endl;
//==========================================EVENT LOOP================================================
   for(int i=0;i<nentries;i++){


   std::string current_input_file(chain1->GetFile()->GetName());
//   cout<<"Current File Name: "<<current_input_file<<endl;


  //  cout<<"=========START OF EVENT========="<<endl;
   genJet_pt.clear(),genJet_eta.clear(),genJet_phi.clear(),genJet_mass.clear(),recoJet_pt.clear(),recoJet_eta.clear(),recoJet_phi.clear(), recoJet_mass.clear(), genJet_recoJet_deltaR.clear();
   genJet_vs_recoJet_pt.clear(),genJet_vs_recoJet_eta.clear(),genJet_vs_recoJet_phi.clear();
   GENMuB_pt.clear(),GENMuB_eta.clear(),GENMuB_phi.clear(),GENpt_rel.clear(),GENpt_rel_no_dif.clear(),pt_rel_diff.clear(),GEN_jet_mu_DR.clear();//Initialized outside of this scope in order to be written it in the tree1 tree...


  vector<float>  RECOMu_unmatched_pt,RECOMu_unmatched_eta,RECOMu_unmatched_phi,RECOMu_pt,RECOMu_eta,RECOMu_phi;
  vector<float> RECOJet_unmatched_pt,RECOJet_unmatched_phi,RECOJet_unmatched_eta,RECOJet_unmatched_mass,RECOJet_unmatched_number,RECOJet_pt,RECOJet_phi,RECOJet_eta,RECOJet_mass;
    
    float px_mu,py_mu,pz_mu,pt_rel,px_jet,py_jet,pz_jet, m_mu=0.106,mt;
     TVector3 p_mu;
     TVector3 p_jet;  

         MC.GetEntry(i);//event counter               
       //if(MC.GetEntry(i)==0) continue;



          for(int j=0; j<MC.genMuB_pt->size(); j++){

            if(MC.genMuB_pt->at(j)<=pt_cut || abs(MC.genMuB_eta->at(j))>=eta_cut) continue;//Kinematic CUTS                                          
                  
              GENMuB_pt.push_back(MC.genMuB_pt->at(j));
              GENMuB_eta.push_back(MC.genMuB_eta->at(j));
              GENMuB_phi.push_back(MC.genMuB_phi->at(j));

                                                     }//end_for GENMuB_* leaf-vector size.
            if(GENMuB_pt.size()==0) continue;



          for(int j=0; j<MC.muon_pt->size(); j++){ 
 
             //if(MC.muon_tight->at(j)==0) continue; //reco_muon quality/id condition
              if(MC.muon_soft->at(j)==0 || MC.muon_pt->at(j)<=pt_cut || abs(MC.muon_eta->at(j))>=eta_cut) continue;       
           
              RECOMu_unmatched_pt.push_back(MC.muon_pt->at(j));
              RECOMu_unmatched_eta.push_back(MC.muon_eta->at(j));
              RECOMu_unmatched_phi.push_back(MC.muon_phi->at(j));
             
                                                         }//end_for RECOMu__unmatched_* leaf-vector size.
              if(RECOMu_unmatched_pt.size()==0) continue;        
/*           if(GENMuB_pt.size()>1){//picking only the heighest pT muon in the event.
           for(int igenmu=0;igenmu<GENMuB_pt.size();++igenmu){
               cout<<"GENMuB_pt("<<igenmu")= "<< GENMuB_pt.at(igenmu)<<endl;
                                                              }
           
           break;
                                 }

           if(GENMuB_pt.size()>1) cout <<"!!!!!!!!! GENMuB_pt.size()= "<<GENMuB_pt.size()<<endl;
           if(RECOMu_unmatched_pt.size() < GENMuB_pt.size()){
           cout<<"GENMuB_pt.size()/RECOMu_unmatched_pt.size() = "<< GENMuB_pt.size()<<"/"<<RECOMu_unmatched_pt.size()<<endl;
                                                              }
*/
    
 //========================== GENJETS ANALYSIS ========================================================================
 //genJet gen_mu jet matching
  map<int,int> genmu_jet_map,genjet_recojet_map;
  float deltaR;



//===================================genJet-recoJet matching=============================================================

  for(int igen_jet=0;igen_jet<MC.genJet_pt->size();++igen_jet){
      if(abs(MC.genJet_flavour->at(igen_jet)) !=5) continue; //choosing only bJets

     int genJet_recoJet_match=0;
     if(abs(MC.genJet_eta->at(igen_jet))>=jet_eta_cut || MC.genJet_pt->at(igen_jet)<=jet_pt_cut) continue;//Jet kinematic cuts and flavour ID
     genJet_pt.push_back(MC.genJet_pt->at(igen_jet));
     genJet_eta.push_back(MC.genJet_eta->at(igen_jet));
     genJet_phi.push_back(MC.genJet_phi->at(igen_jet));
     genJet_mass.push_back(MC.genJet_mass->at(igen_jet));
     deltaR=100.;

         for(int ireco_jet=0;ireco_jet<MC.jet_pt->size();++ireco_jet){
          if(DR(MC.genJet_eta->at(igen_jet),MC.genJet_phi->at(igen_jet),MC.jet_eta->at(ireco_jet),MC.jet_phi->at(ireco_jet))>=deltaR) continue;   
          deltaR=DR(MC.genJet_eta->at(igen_jet),MC.genJet_phi->at(igen_jet),MC.jet_eta->at(ireco_jet),MC.jet_phi->at(ireco_jet));
          genJet_recoJet_match=ireco_jet;
                                                                     }
           if(deltaR>=0.4 || abs(MC.jet_eta->at(genJet_recoJet_match))>=jet_eta_cut || MC.jet_pt->at(genJet_recoJet_match)<=jet_pt_cut || MC.jet_nHEF->at(genJet_recoJet_match)>=0.90 || MC.jet_nEmEF->at(genJet_recoJet_match)>=0.90 || (MC.jet_nMult->at(genJet_recoJet_match)+MC.jet_cMult->at(genJet_recoJet_match))<=1. || MC.jet_cHEF->at(genJet_recoJet_match)<=0. || MC.jet_cHMult->at(genJet_recoJet_match)<=0.) continue;
           //kinematic cuts and recoJet quality/id condition
           genjet_recojet_map[igen_jet]=genJet_recoJet_match;
           recoJet_pt.push_back(MC.jet_pt->at(genJet_recoJet_match));
           recoJet_eta.push_back(MC.jet_eta->at(genJet_recoJet_match));
           recoJet_phi.push_back(MC.jet_phi->at(genJet_recoJet_match));
           recoJet_mass.push_back(MC.jet_mass->at(genJet_recoJet_match));

//ideally I shouldn't copy recoJet's again but use pointers for saving copying time...............I will not change the code now :P....
              RECOJet_unmatched_pt.push_back(MC.jet_pt->at(genJet_recoJet_match));
              RECOJet_unmatched_eta.push_back(MC.jet_eta->at(genJet_recoJet_match));
              RECOJet_unmatched_phi.push_back(MC.jet_phi->at(genJet_recoJet_match));
              RECOJet_unmatched_mass.push_back(MC.jet_mass->at(genJet_recoJet_match));

           genJet_recoJet_deltaR.push_back(deltaR);
           genJet_vs_recoJet_pt.push_back((MC.genJet_pt->at(igen_jet)-MC.jet_pt->at(genJet_recoJet_match))/MC.genJet_pt->at(igen_jet));
           genJet_vs_recoJet_eta.push_back(MC.genJet_eta->at(igen_jet)-MC.jet_eta->at(genJet_recoJet_match));
           genJet_vs_recoJet_phi.push_back(MC.genJet_phi->at(igen_jet)-MC.jet_phi->at(genJet_recoJet_match));
                                                              }




//========================gen_mu-genJet matching & pT_rel calculation======================================================================

//TGraph
  for(int igen_mu=0;igen_mu<GENMuB_pt.size();++igen_mu){
     
     int genjet_mu_match=0;
     if(genJet_pt.size()==0) continue;
     deltaR=1000.;

      for(int ijet=0;ijet<genJet_pt.size();++ijet){
     //    if(abs(MC.genJet_eta->at(ijet))>=jet_eta_cut||) continue;

         if(DR(genJet_eta.at(ijet),genJet_phi.at(ijet),GENMuB_eta.at(igen_mu),GENMuB_phi.at(igen_mu))>=deltaR) continue;
          deltaR= DR(genJet_eta.at(ijet),genJet_phi.at(ijet),GENMuB_eta.at(igen_mu),GENMuB_phi.at(igen_mu));
          genjet_mu_match=ijet;
                                                  }
            if(deltaR>=0.4) continue; 
            GEN_jet_mu_DR.push_back(deltaR);
            GENMUB_PT.push_back(GENMuB_pt.at(igen_mu)); GENJET_PT.push_back(genJet_pt.at(genjet_mu_match));//for pt(mu)-vs-pt(jet) and pt(mu)-vs-pt(jet).

            genmu_jet_map[igen_mu]=genjet_mu_match;
            //cout << igen_mu <<"===>"<<genmu_jet_map[igen_mu]<<", with deltaR= "<<deltaR<<endl;
                   
             mt= TMath::Sqrt(GENMuB_pt.at(igen_mu)*GENMuB_pt.at(igen_mu)+m_mu*m_mu) ;              
             px_mu = GENMuB_pt.at(igen_mu) * cos(GENMuB_phi.at(igen_mu));
             py_mu = GENMuB_pt.at(igen_mu) * sin(GENMuB_phi.at(igen_mu));
             pz_mu = mt * sinh(GENMuB_eta.at(igen_mu));          

/*
             mt= TMath::Sqrt(genJet_pt.at(genjet_mu_match)*genJet_pt.at(genjet_mu_match)+genJet_mass.at(genjet_mu_match)*genJet_mass.at(genjet_mu_match));     
             px_jet = genJet_pt.at(genjet_mu_match) * cos(genJet_phi.at(genjet_mu_match));
             py_jet = genJet_pt.at(genjet_mu_match) * sin(genJet_phi.at(genjet_mu_match));
             pz_jet = mt * sinh(genJet_eta.at(genjet_mu_match));   
*/
             px_jet = genJet_pt.at(genjet_mu_match) * cos(genJet_phi.at(genjet_mu_match));
             py_jet = genJet_pt.at(genjet_mu_match) * sin(genJet_phi.at(genjet_mu_match));
             pz_jet = genJet_pt.at(genjet_mu_match) * sinh(genJet_eta.at(genjet_mu_match));   
             
             p_mu.SetXYZ(px_mu,py_mu,pz_mu);
             p_jet.SetXYZ(px_jet,py_jet,pz_jet);

             pt_rel=(p_mu.Cross(p_jet)).Mag()/p_jet.Mag();           
             GENpt_rel_no_dif.push_back(pt_rel);         

//             p_jet=p_jet-p_mu;   //CRITICALLLLLLLL!!!!       
       
//             pt_rel=(p_mu.Cross(p_jet)).Mag()/p_jet.Mag();
//             GENpt_rel.push_back(pt_rel);
//07.04.19 (abandoning the p_jet=pjet-p_mu idea, too much dependence on pT_jet and pT_muon
           if(current_input_file.std::string::find("30to50") != std::string::npos){
           //text.find should return a -1 if the word isnt there, otherwise it returns the position in string that you found it
           //some_string.find('a') will EITHER return the position of the first appearance of 'a' in some_string if 'a' appears at least once in some_string, OR it will return a value that is equal to
           //std::string::npos if 'a' does not appear at all in some_string.
            Hpt_rel_gen->Fill(pt_rel,relative_weight_30to50);
                                                                                  }
            else if(current_input_file.std::string::find("50to80") != std::string::npos)  Hpt_rel_gen->Fill(pt_rel,relative_weight_50to80);
            else if(current_input_file.std::string::find("80to120") != std::string::npos)  Hpt_rel_gen->Fill(pt_rel,relative_weight_80to120);
            else if(current_input_file.std::string::find("120to170") != std::string::npos)  Hpt_rel_gen->Fill(pt_rel,relative_weight_120to170);
            else if(current_input_file.std::string::find("170to300") != std::string::npos)  Hpt_rel_gen->Fill(pt_rel,relative_weight_170to300);
            else if(current_input_file.std::string::find("15to20") != std::string::npos){ cout<<"WTFFFFFFF 15to20????"<<endl; break; Hpt_rel_gen->Fill(pt_rel,relative_weight_15to20);}
            else Hpt_rel_gen->Fill(pt_rel,relative_weight_20to30);   
                                                    }           

//----------------------------------------------------------------------------------------------------------------------------------------------------

    genmuons=GENMuB_pt.size();   // cout << "yes and genmuons= " << genmuons << endl;  //Just for debugg.
    unmatched_recomuons=RECOMu_unmatched_pt.size();
    unmatched_recojets=RECOJet_unmatched_pt.size();

               //Number of Jets
                   RECOJet_unmatched_number.push_back(unmatched_recojets);
 
 // cout <<"unmatched_recomuons= "<< unmatched_recomuons << endl;

//------------------GEN and REC0 HISTOS--------------------------------------------------------------------------------

/*
                 for(int k=0;k<genmuons;k++){
                HgenMuB_pt->Fill(GENMuB_pt.at(k));
                HgenMuB_eta->Fill(GENMuB_eta.at(k));

                                                                                  }//end_for gen mu histograms
*/
//should promote these depictions to leaf too...
                 for(int k=0;k<unmatched_recomuons;k++){
//07.04.19: Bored to changed this histo, I do not use it that much..
                Hrecomu_unmatched_pt->Fill(RECOMu_unmatched_pt.at(k));
                Hrecomu_unmatched_eta->Fill(RECOMu_unmatched_eta.at(k));
                                                                                   }//end_for reco mu histograms

/*//same as recoJet_* leaf
                 for(int k=0;k<unmatched_recojets;k++){
                Hrecojet_unmatched_pt->Fill(RECOJet_unmatched_pt.at(k));
                Hrecojet_unmatched_eta->Fill(RECOJet_unmatched_eta.at(k));
                Hrecojet_unmatched_phi->Fill(RECOJet_unmatched_phi.at(k));

                                                                                   }//end_for reco jet histograms
*/
                

//--------------------------------------------------------RECO-GEN MATCHING----------------------------------------------------------

   float gen_phi,gen_eta,reco_phi,reco_eta,temp_DR_min=0.,temp_DR_min_loop=0.,DR_min=0.;
   int reco_number=0; //idex the entry number of the reco_muon which corresponds to each gen_muon.
   map <int, int> gen_reco_map; //dynamic  pairing basically a "vector<pair<int,int>>".



            for(int q=0;q<genmuons;q++){

                  if(unmatched_recomuons==0)        continue;

                gen_phi=GENMuB_phi.at(q);
                gen_eta=GENMuB_eta.at(q);

                reco_phi=RECOMu_unmatched_phi.at(0);
                reco_eta=RECOMu_unmatched_eta.at(0);

                temp_DR_min=DR(gen_eta,gen_phi,reco_eta,reco_phi);    //Initialization....
                 for(int r=0; r<unmatched_recomuons;r++){
                         reco_phi=RECOMu_unmatched_phi.at(r);
                         reco_eta=RECOMu_unmatched_eta.at(r);
                         temp_DR_min_loop=DR(gen_eta,gen_phi,reco_eta,reco_phi);
 
                      if(temp_DR_min_loop>=temp_DR_min ) continue ;
                      
                          temp_DR_min=temp_DR_min_loop;
                          reco_number=r;           
                                   
                                                                      }//end_for unmatched_recomuons
                                               DR_min=temp_DR_min;
//07.04.19
           if(current_input_file.std::string::find("30to50") != std::string::npos){
           //text.find should return a -1 if the word isnt there, otherwise it returns the position in string that you found it
           //some_string.find('a') will EITHER return the position of the first appearance of 'a' in some_string if 'a' appears at least once in some_string, OR it will return a value that is equal to
           //std::string::npos if 'a' does not appear at all in some_string.
             HDR->Fill(DR_min,relative_weight_30to50);
                                                                                  }
            else if(current_input_file.std::string::find("50to80") != std::string::npos)  HDR->Fill(DR_min,relative_weight_50to80);
            else if(current_input_file.std::string::find("80to120") != std::string::npos)  HDR->Fill(DR_min,relative_weight_80to120);
            else if(current_input_file.std::string::find("120to170") != std::string::npos)  HDR->Fill(DR_min,relative_weight_120to170);
            else if(current_input_file.std::string::find("170to300") != std::string::npos)  HDR->Fill(DR_min,relative_weight_170to300);
            else if(current_input_file.std::string::find("15to20") != std::string::npos) HDR->Fill(DR_min,relative_weight_15to20);
            else HDR->Fill(DR_min,relative_weight_20to30);   
                                               

                                               gen_reco_map[q]=reco_number;
                                                   }//end_for reco-gen matching 

     

//========================================EXAMINING THE MATCHING PROCEDURE=============================================================

             float temp_diff;
             for(map<int,int>::iterator it = gen_reco_map.begin(); it!=gen_reco_map.end();it++) {  

//07.04.19:
           if(current_input_file.std::string::find("30to50") != std::string::npos){
           //text.find should return a -1 if the word isnt there, otherwise it returns the position in string that you found it
           //some_string.find('a') will EITHER return the position of the first appearance of 'a' in some_string if 'a' appears at least once in some_string, OR it will return a value that is equal to
           //std::string::npos if 'a' does not appear at all in some_string.
                  temp_diff = (GENMuB_pt.at(it->first)-RECOMu_unmatched_pt.at(it->second))/GENMuB_pt.at(it->first);
                  Hmu_reco_vs_gen_pt->Fill(temp_diff,relative_weight_30to50);
                  temp_diff = GENMuB_eta.at(it->first)-RECOMu_unmatched_eta.at(it->second);
                  Hmu_reco_vs_gen_eta->Fill(temp_diff,relative_weight_30to50); 
                  temp_diff = (GENMuB_phi.at(it->first)-RECOMu_unmatched_phi.at(it->second));
                  Hmu_reco_vs_gen_phi->Fill(temp_diff,relative_weight_30to50);           

                                                                                  }
            else if(current_input_file.std::string::find("50to80") != std::string::npos){
                  temp_diff = (GENMuB_pt.at(it->first)-RECOMu_unmatched_pt.at(it->second))/GENMuB_pt.at(it->first);
                  Hmu_reco_vs_gen_pt->Fill(temp_diff,relative_weight_50to80);
                  temp_diff = GENMuB_eta.at(it->first)-RECOMu_unmatched_eta.at(it->second);
                  Hmu_reco_vs_gen_eta->Fill(temp_diff,relative_weight_50to80); 
                  temp_diff = (GENMuB_phi.at(it->first)-RECOMu_unmatched_phi.at(it->second));
                  Hmu_reco_vs_gen_phi->Fill(temp_diff,relative_weight_50to80);             
                                                                                        }
            else if(current_input_file.std::string::find("80to120") != std::string::npos){
                  temp_diff = (GENMuB_pt.at(it->first)-RECOMu_unmatched_pt.at(it->second))/GENMuB_pt.at(it->first);
                  Hmu_reco_vs_gen_pt->Fill(temp_diff,relative_weight_80to120);
                  temp_diff = GENMuB_eta.at(it->first)-RECOMu_unmatched_eta.at(it->second);
                  Hmu_reco_vs_gen_eta->Fill(temp_diff,relative_weight_80to120); 
                  temp_diff = (GENMuB_phi.at(it->first)-RECOMu_unmatched_phi.at(it->second));
                  Hmu_reco_vs_gen_phi->Fill(temp_diff,relative_weight_80to120);
                                                                                          }
            else if(current_input_file.std::string::find("120to170") != std::string::npos){
                  temp_diff = (GENMuB_pt.at(it->first)-RECOMu_unmatched_pt.at(it->second))/GENMuB_pt.at(it->first);
                  Hmu_reco_vs_gen_pt->Fill(temp_diff,relative_weight_120to170);
                  temp_diff = GENMuB_eta.at(it->first)-RECOMu_unmatched_eta.at(it->second);
                  Hmu_reco_vs_gen_eta->Fill(temp_diff,relative_weight_120to170); 
                  temp_diff = (GENMuB_phi.at(it->first)-RECOMu_unmatched_phi.at(it->second));
                  Hmu_reco_vs_gen_phi->Fill(temp_diff,relative_weight_120to170);                  
                                                                                          }
            else if(current_input_file.std::string::find("170to300") != std::string::npos){
                  temp_diff = (GENMuB_pt.at(it->first)-RECOMu_unmatched_pt.at(it->second))/GENMuB_pt.at(it->first);
                  Hmu_reco_vs_gen_pt->Fill(temp_diff,relative_weight_170to300);
                  temp_diff = GENMuB_eta.at(it->first)-RECOMu_unmatched_eta.at(it->second);
                  Hmu_reco_vs_gen_eta->Fill(temp_diff,relative_weight_170to300); 
                  temp_diff = (GENMuB_phi.at(it->first)-RECOMu_unmatched_phi.at(it->second));
                  Hmu_reco_vs_gen_phi->Fill(temp_diff,relative_weight_170to300);                  
                                                                                          }

            else if(current_input_file.std::string::find("15to20") != std::string::npos){
                  temp_diff = (GENMuB_pt.at(it->first)-RECOMu_unmatched_pt.at(it->second))/GENMuB_pt.at(it->first);
                  Hmu_reco_vs_gen_pt->Fill(temp_diff,relative_weight_15to20);
                  temp_diff = GENMuB_eta.at(it->first)-RECOMu_unmatched_eta.at(it->second);
                  Hmu_reco_vs_gen_eta->Fill(temp_diff,relative_weight_15to20); 
                  temp_diff = (GENMuB_phi.at(it->first)-RECOMu_unmatched_phi.at(it->second));
                  Hmu_reco_vs_gen_phi->Fill(temp_diff,relative_weight_15to20); 

                                                                                        }
            else {   
                  temp_diff = (GENMuB_pt.at(it->first)-RECOMu_unmatched_pt.at(it->second))/GENMuB_pt.at(it->first);
                  Hmu_reco_vs_gen_pt->Fill(temp_diff,relative_weight_20to30);
                  temp_diff = GENMuB_eta.at(it->first)-RECOMu_unmatched_eta.at(it->second);
                  Hmu_reco_vs_gen_eta->Fill(temp_diff,relative_weight_20to30); 
                  temp_diff = (GENMuB_phi.at(it->first)-RECOMu_unmatched_phi.at(it->second));
                  Hmu_reco_vs_gen_phi->Fill(temp_diff,relative_weight_20to30);

                  }

                 
                  RECOMu_pt.push_back(RECOMu_unmatched_pt.at(it->second));  
                  RECOMu_eta.push_back(RECOMu_unmatched_eta.at(it->second));                                  
                  RECOMu_phi.push_back(RECOMu_unmatched_phi.at(it->second));

              }
                 
                     for(int h=0;h<RECOMu_pt.size();h++){
           if(current_input_file.std::string::find("30to50") != std::string::npos){
           //text.find should return a -1 if the word isnt there, otherwise it returns the position in string that you found it
           //some_string.find('a') will EITHER return the position of the first appearance of 'a' in some_string if 'a' appears at least once in some_string, OR it will return a value that is equal to
           //std::string::npos if 'a' does not appear at all in some_string.

             Hrecomu_pt->Fill(RECOMu_pt.at(h),relative_weight_30to50);
             Hrecomu_eta->Fill(RECOMu_eta.at(h),relative_weight_30to50);
             Hrecomu_phi->Fill(RECOMu_phi.at(h),relative_weight_30to50);            
                                                                                  }
            else if(current_input_file.std::string::find("50to80") != std::string::npos){
             Hrecomu_pt->Fill(RECOMu_pt.at(h),relative_weight_50to80);
             Hrecomu_eta->Fill(RECOMu_eta.at(h),relative_weight_50to80);
             Hrecomu_phi->Fill(RECOMu_phi.at(h),relative_weight_50to80);
                                                                                        }
            else if(current_input_file.std::string::find("80to120") != std::string::npos){
             Hrecomu_pt->Fill(RECOMu_pt.at(h),relative_weight_80to120);
             Hrecomu_eta->Fill(RECOMu_eta.at(h),relative_weight_80to120);
             Hrecomu_phi->Fill(RECOMu_phi.at(h),relative_weight_80to120);                  
                                                                                          }
            else if(current_input_file.std::string::find("120to170") != std::string::npos){
             Hrecomu_pt->Fill(RECOMu_pt.at(h),relative_weight_120to170);
             Hrecomu_eta->Fill(RECOMu_eta.at(h),relative_weight_120to170);
             Hrecomu_phi->Fill(RECOMu_phi.at(h),relative_weight_120to170);                  
                                                                                          }
            else if(current_input_file.std::string::find("170to300") != std::string::npos){
             Hrecomu_pt->Fill(RECOMu_pt.at(h),relative_weight_170to300);
             Hrecomu_eta->Fill(RECOMu_eta.at(h),relative_weight_170to300);
             Hrecomu_phi->Fill(RECOMu_phi.at(h),relative_weight_170to300);                 
                                                                                          }
            else if(current_input_file.std::string::find("15to20") != std::string::npos){
             Hrecomu_pt->Fill(RECOMu_pt.at(h),relative_weight_15to20);
             Hrecomu_eta->Fill(RECOMu_eta.at(h),relative_weight_15to20);
             Hrecomu_phi->Fill(RECOMu_phi.at(h),relative_weight_15to20);                 
                                                                                          }
            else {   
             Hrecomu_pt->Fill(RECOMu_pt.at(h),relative_weight_20to30);
             Hrecomu_eta->Fill(RECOMu_eta.at(h),relative_weight_20to30);
             Hrecomu_phi->Fill(RECOMu_phi.at(h),relative_weight_20to30);

                  }

             recomuons=RECOMu_pt.size();

                                                    }
//===================================== RECO MUON  - RECO JET MATCHING =============================================================
        double cone_DR=0.4,temp_DR,temp_DR_loop;
        map <int, int> mu_jet_map;
                  
            for(int w=0;w<recomuons;w++){             

                      
                  if(unmatched_recomuons==0 || RECOJet_unmatched_pt.size()==0)        continue;


                 reco_phi=RECOMu_phi.at(w);
                 reco_eta=RECOMu_eta.at(w);

                 temp_DR=DR(reco_eta,reco_phi,RECOJet_unmatched_eta.at(0),RECOJet_unmatched_phi.at(0));  

                              
                    for(int l=0;l<unmatched_recojets;++l){

                    temp_DR_loop=DR(reco_eta,reco_phi,RECOJet_unmatched_eta.at(l),RECOJet_unmatched_phi.at(l));
                             
                       if(temp_DR_loop>temp_DR)           continue ;

                            temp_DR=temp_DR_loop; 
                            reco_number=l;
                
                                                        }//end_for l unmatched_recojets.  

                                          if(temp_DR<cone_DR){                                                                
                                               mu_jet_map[w] = reco_number;

//07.04.19
                                               if(current_input_file.std::string::find("30to50") != std::string::npos){
                                               //text.find should return a -1 if the word isnt there, otherwise it returns the position in string that you found it
                                               //some_string.find('a') will EITHER return the position of the first appearance of 'a' in some_string if 'a' appears at least once in some_string, OR it will return                                                 a value that is equal to
                                               //std::string::npos if 'a' does not appear at all in some_string.
                                    
                                               HDR_jet->Fill(temp_DR,relative_weight_30to50);
                                               Hrecomu_final_pt->Fill(RECOMu_pt.at(w),relative_weight_30to50);               
                                                                                                                      }
                                                else if(current_input_file.std::string::find("50to80") != std::string::npos){
                                               HDR_jet->Fill(temp_DR,relative_weight_50to80);
                                               Hrecomu_final_pt->Fill(RECOMu_pt.at(w),relative_weight_50to80);
                                                                                                                            }
                                                else if(current_input_file.std::string::find("80to120") != std::string::npos){
                                               HDR_jet->Fill(temp_DR,relative_weight_80to120);
                                               Hrecomu_final_pt->Fill(RECOMu_pt.at(w),relative_weight_80to120);
                                                                                                                              }
                                                else if(current_input_file.std::string::find("120to170") != std::string::npos){
                                               HDR_jet->Fill(temp_DR,relative_weight_120to170);
                                               Hrecomu_final_pt->Fill(RECOMu_pt.at(w),relative_weight_120to170);
                                                                                                                              }
                                                else if(current_input_file.std::string::find("170to300") != std::string::npos){
                                               HDR_jet->Fill(temp_DR,relative_weight_170to300);
                                               Hrecomu_final_pt->Fill(RECOMu_pt.at(w),relative_weight_170to300);
                                                                                                                              }
                                                else if(current_input_file.std::string::find("15to20") != std::string::npos){
                                               HDR_jet->Fill(temp_DR,relative_weight_15to20);
                                               Hrecomu_final_pt->Fill(RECOMu_pt.at(w),relative_weight_15to20);
                                                                                                                              }
                                                else {   
                                               HDR_jet->Fill(temp_DR,relative_weight_20to30);
                                               Hrecomu_final_pt->Fill(RECOMu_pt.at(w),relative_weight_20to30);
                                    
                                                      }
                                                                                                 }
                                    
                                         //   ELSE COUT<< "MUON NOT FOUND IN JET" << ENDL;



                                                               }//end_for w recomuons


              for(map<int,int>::iterator it2=mu_jet_map.begin();it2 !=mu_jet_map.end();it2++){
                   
          //      cout <<"----EVENT: "<< i<<",  "<< it2->first << " ==> " << it2->second << ", RECOJet_unmatched:  "<< unmatched_recojets << endl;

          //  if(genmuons>=2)       cout << "In event= " <<i <<": #mu==> #jet:  " << it2->first <<" ==> " << it2->second << endl;

                                  RECOJet_pt.push_back(RECOJet_unmatched_pt.at(it2->second));  
                                  RECOJet_eta.push_back(RECOJet_unmatched_eta.at(it2->second));                                  
                                  RECOJet_phi.push_back(RECOJet_unmatched_phi.at(it2->second));
                                  RECOJet_mass.push_back(RECOJet_unmatched_mass.at(it2->second));
                                                                                              }
                         //     cout << endl << endl;

                         for(int p=0;p<RECOJet_pt.size();p++){
              	           if(current_input_file.std::string::find("30to50") != std::string::npos){
                          //text.find should return a -1 if the word isnt there, otherwise it returns the position in string that you found it
                          //some_string.find('a') will EITHER return the position of the first appearance of 'a' in some_string if 'a' appears at least once in some_string, OR it will return a value that is equal to
                          //std::string::npos if 'a' does not appear at all in some_string.
               
                            Hrecojet_pt->Fill(RECOJet_pt.at(p),relative_weight_30to50);
                            Hrecojet_eta->Fill(RECOJet_eta.at(p),relative_weight_30to50);
                            Hrecojet_phi->Fill(RECOJet_phi.at(p),relative_weight_30to50);            
                                                                                                 }
                           else if(current_input_file.std::string::find("50to80") != std::string::npos){
                            Hrecojet_pt->Fill(RECOJet_pt.at(p),relative_weight_50to80);
                            Hrecojet_eta->Fill(RECOJet_eta.at(p),relative_weight_50to80);
                            Hrecojet_phi->Fill(RECOJet_phi.at(p),relative_weight_50to80);
                                                                                                       }
                           else if(current_input_file.std::string::find("80to120") != std::string::npos){
                            Hrecojet_pt->Fill(RECOJet_pt.at(p),relative_weight_80to120);
                            Hrecojet_eta->Fill(RECOJet_eta.at(p),relative_weight_80to120);
                            Hrecojet_phi->Fill(RECOJet_phi.at(p),relative_weight_80to120);                  
                                                                                                         }
                           else if(current_input_file.std::string::find("120to170") != std::string::npos){
                            Hrecojet_pt->Fill(RECOJet_pt.at(p),relative_weight_120to170);
                            Hrecojet_eta->Fill(RECOJet_eta.at(p),relative_weight_120to170);
                            Hrecojet_phi->Fill(RECOJet_phi.at(p),relative_weight_120to170);                  
                                                                                                         }
                           else if(current_input_file.std::string::find("170to300") != std::string::npos){
                            Hrecojet_pt->Fill(RECOJet_pt.at(p),relative_weight_170to300);
                            Hrecojet_eta->Fill(RECOJet_eta.at(p),relative_weight_170to300);
                            Hrecojet_phi->Fill(RECOJet_phi.at(p),relative_weight_170to300);                 
                                                                                                         }
                           else if(current_input_file.std::string::find("15to20") != std::string::npos){
                            Hrecojet_pt->Fill(RECOJet_pt.at(p),relative_weight_15to20);
                            Hrecojet_eta->Fill(RECOJet_eta.at(p),relative_weight_15to20);
                            Hrecojet_phi->Fill(RECOJet_phi.at(p),relative_weight_15to20);                 
                                                                                                         }
                           else {   
                            Hrecojet_pt->Fill(RECOJet_pt.at(p),relative_weight_20to30);
                            Hrecojet_eta->Fill(RECOJet_eta.at(p),relative_weight_20to30);
                            Hrecojet_phi->Fill(RECOJet_phi.at(p),relative_weight_20to30);
               
                                 }
               
                                                             }


//====================================p_T(rel) calculation=============================================================



           for(int m=0; m<recomuons;m++){
               
             if(mu_jet_map.size()==0 ) continue;

             if(RECOJet_pt.size() < RECOMu_pt.size()){   continue;

                                   }

             mt= TMath::Sqrt(RECOMu_pt.at(m)*RECOMu_pt.at(m)+m_mu*m_mu) ;

            
             px_mu = RECOMu_pt.at(m) * cos(RECOMu_phi.at(m));
             py_mu = RECOMu_pt.at(m) * sin(RECOMu_phi.at(m));
             pz_mu = mt * sinh(RECOMu_eta.at(m));

      //    cout << "GENMu_pt.size() =" << GENMu_pt.size() 

   //     cout << "px_mu= " << px_mu <<", py_mu= " << py_mu << ", pz_mu= " << pz_mu << endl;
/*
               mt=TMath::Sqrt( RECOJet_pt.at(m)*RECOJet_pt.at(m)+RECOJet_mass.at(m)*RECOJet_mass.at(m));
               px_jet = RECOJet_pt.at(m) * cos(RECOJet_phi.at(m));
               py_jet = RECOJet_pt.at(m) * sin(RECOJet_phi.at(m));
               pz_jet = mt * sinh(RECOJet_eta.at(m));
*/
               px_jet = RECOJet_pt.at(m) * cos(RECOJet_phi.at(m));
               py_jet = RECOJet_pt.at(m) * sin(RECOJet_phi.at(m));
               pz_jet = RECOJet_pt.at(m) * sinh(RECOJet_eta.at(m));

       
               p_mu.SetXYZ(px_mu,py_mu,pz_mu);
               p_jet.SetXYZ(px_jet,py_jet,pz_jet);

               pt_rel=(p_mu.Cross(p_jet)).Mag()/p_jet.Mag();

//07.04.19
                 if(current_input_file.std::string::find("30to50") != std::string::npos){
                 //text.find should return a -1 if the word isnt there, otherwise it returns the position in string that you found it
                 //some_string.find('a') will EITHER return the position of the first appearance of 'a' in some_string if 'a' appears at least once in some_string, OR it will return                                                 a value that is equal to
                 //std::string::npos if 'a' does not appear at all in some_string.

                      Hpt_rel_no_dif->Fill(pt_rel,relative_weight_30to50);
                      Hmuon_pt_rel_pt_no_dif->Fill(RECOMu_pt.at(m),pt_rel,relative_weight_30to50);
                          if(RECOMu_pt.at(m)>=min_1 && RECOMu_pt.at(m)<=max_1) Hpt_rel_range1_no_dif->Fill(pt_rel,relative_weight_30to50);
                          else if(RECOMu_pt.at(m)>max_1 && RECOMu_pt.at(m)<=max_2) Hpt_rel_range2_no_dif->Fill(pt_rel,relative_weight_30to50);
                          else if(RECOMu_pt.at(m)>max_2) Hpt_rel_range3_no_dif->Fill(pt_rel,relative_weight_30to50);
       
                          if(RECOJet_pt.at(m)>=jet_min_1 && RECOJet_pt.at(m)<=jet_max_1) Hpt_rel_jet_range1_no_dif->Fill(pt_rel,relative_weight_30to50);
                          else if(RECOJet_pt.at(m)>jet_max_1 && RECOJet_pt.at(m)<=jet_max_2) Hpt_rel_jet_range2_no_dif->Fill(pt_rel,relative_weight_30to50);
                          else if(RECOJet_pt.at(m)>jet_max_2) Hpt_rel_jet_range3_no_dif->Fill(pt_rel,relative_weight_30to50);
                      
                                                                                               }
                  else if(current_input_file.std::string::find("50to80") != std::string::npos){
                      Hpt_rel_no_dif->Fill(pt_rel,relative_weight_50to80);
                      Hmuon_pt_rel_pt_no_dif->Fill(RECOMu_pt.at(m),pt_rel,relative_weight_50to80);
                          if(RECOMu_pt.at(m)>=min_1 && RECOMu_pt.at(m)<=max_1) Hpt_rel_range1_no_dif->Fill(pt_rel,relative_weight_50to80);
                          else if(RECOMu_pt.at(m)>max_1 && RECOMu_pt.at(m)<=max_2) Hpt_rel_range2_no_dif->Fill(pt_rel,relative_weight_50to80);
                          else if(RECOMu_pt.at(m)>max_2) Hpt_rel_range3_no_dif->Fill(pt_rel,relative_weight_50to80);
       
                          if(RECOJet_pt.at(m)>=jet_min_1 && RECOJet_pt.at(m)<=jet_max_1) Hpt_rel_jet_range1_no_dif->Fill(pt_rel,relative_weight_50to80);
                          else if(RECOJet_pt.at(m)>jet_max_1 && RECOJet_pt.at(m)<=jet_max_2) Hpt_rel_jet_range2_no_dif->Fill(pt_rel,relative_weight_50to80);
                          else if(RECOJet_pt.at(m)>jet_max_2) Hpt_rel_jet_range3_no_dif->Fill(pt_rel,relative_weight_50to80);
                                                                                                     }
                  else if(current_input_file.std::string::find("80to120") != std::string::npos){
                      Hpt_rel_no_dif->Fill(pt_rel,relative_weight_80to120);
                      Hmuon_pt_rel_pt_no_dif->Fill(RECOMu_pt.at(m),pt_rel,relative_weight_80to120);
                          if(RECOMu_pt.at(m)>=min_1 && RECOMu_pt.at(m)<=max_1) Hpt_rel_range1_no_dif->Fill(pt_rel,relative_weight_80to120);
                          else if(RECOMu_pt.at(m)>max_1 && RECOMu_pt.at(m)<=max_2) Hpt_rel_range2_no_dif->Fill(pt_rel,relative_weight_80to120);
                          else if(RECOMu_pt.at(m)>max_2) Hpt_rel_range3_no_dif->Fill(pt_rel,relative_weight_80to120);
       
                          if(RECOJet_pt.at(m)>=jet_min_1 && RECOJet_pt.at(m)<=jet_max_1) Hpt_rel_jet_range1_no_dif->Fill(pt_rel,relative_weight_80to120);
                          else if(RECOJet_pt.at(m)>jet_max_1 && RECOJet_pt.at(m)<=jet_max_2) Hpt_rel_jet_range2_no_dif->Fill(pt_rel,relative_weight_80to120);
                          else if(RECOJet_pt.at(m)>jet_max_2) Hpt_rel_jet_range3_no_dif->Fill(pt_rel,relative_weight_80to120);
                                                                                                     }
                                                                                                       
                  else if(current_input_file.std::string::find("120to170") != std::string::npos){
                      Hpt_rel_no_dif->Fill(pt_rel,relative_weight_120to170);
                      Hmuon_pt_rel_pt_no_dif->Fill(RECOMu_pt.at(m),pt_rel,relative_weight_120to170);
                          if(RECOMu_pt.at(m)>=min_1 && RECOMu_pt.at(m)<=max_1) Hpt_rel_range1_no_dif->Fill(pt_rel,relative_weight_120to170);
                          else if(RECOMu_pt.at(m)>max_1 && RECOMu_pt.at(m)<=max_2) Hpt_rel_range2_no_dif->Fill(pt_rel,relative_weight_120to170);
                          else if(RECOMu_pt.at(m)>max_2) Hpt_rel_range3_no_dif->Fill(pt_rel,relative_weight_120to170);
       
                          if(RECOJet_pt.at(m)>=jet_min_1 && RECOJet_pt.at(m)<=jet_max_1) Hpt_rel_jet_range1_no_dif->Fill(pt_rel,relative_weight_120to170);
                          else if(RECOJet_pt.at(m)>jet_max_1 && RECOJet_pt.at(m)<=jet_max_2) Hpt_rel_jet_range2_no_dif->Fill(pt_rel,relative_weight_120to170);
                          else if(RECOJet_pt.at(m)>jet_max_2) Hpt_rel_jet_range3_no_dif->Fill(pt_rel,relative_weight_120to170);
                                                                                                       }
                  else if(current_input_file.std::string::find("170to300") != std::string::npos){
                      Hpt_rel_no_dif->Fill(pt_rel,relative_weight_170to300);
                      Hmuon_pt_rel_pt_no_dif->Fill(RECOMu_pt.at(m),pt_rel,relative_weight_170to300);
                          if(RECOMu_pt.at(m)>=min_1 && RECOMu_pt.at(m)<=max_1) Hpt_rel_range1_no_dif->Fill(pt_rel,relative_weight_170to300);
                          else if(RECOMu_pt.at(m)>max_1 && RECOMu_pt.at(m)<=max_2) Hpt_rel_range2_no_dif->Fill(pt_rel,relative_weight_170to300);
                          else if(RECOMu_pt.at(m)>max_2) Hpt_rel_range3_no_dif->Fill(pt_rel,relative_weight_170to300);
       
                          if(RECOJet_pt.at(m)>=jet_min_1 && RECOJet_pt.at(m)<=jet_max_1) Hpt_rel_jet_range1_no_dif->Fill(pt_rel,relative_weight_170to300);
                          else if(RECOJet_pt.at(m)>jet_max_1 && RECOJet_pt.at(m)<=jet_max_2) Hpt_rel_jet_range2_no_dif->Fill(pt_rel,relative_weight_170to300);
                          else if(RECOJet_pt.at(m)>jet_max_2) Hpt_rel_jet_range3_no_dif->Fill(pt_rel,relative_weight_170to300);
                                                                                                       }
                  else if(current_input_file.std::string::find("15to20") != std::string::npos){
                      Hpt_rel_no_dif->Fill(pt_rel,relative_weight_15to20);
                      Hmuon_pt_rel_pt_no_dif->Fill(RECOMu_pt.at(m),pt_rel,relative_weight_15to20);
                          if(RECOMu_pt.at(m)>=min_1 && RECOMu_pt.at(m)<=max_1) Hpt_rel_range1_no_dif->Fill(pt_rel,relative_weight_15to20);
                          else if(RECOMu_pt.at(m)>max_1 && RECOMu_pt.at(m)<=max_2) Hpt_rel_range2_no_dif->Fill(pt_rel,relative_weight_15to20);
                          else if(RECOMu_pt.at(m)>max_2) Hpt_rel_range3_no_dif->Fill(pt_rel,relative_weight_15to20);
       
                          if(RECOJet_pt.at(m)>=jet_min_1 && RECOJet_pt.at(m)<=jet_max_1) Hpt_rel_jet_range1_no_dif->Fill(pt_rel,relative_weight_15to20);
                          else if(RECOJet_pt.at(m)>jet_max_1 && RECOJet_pt.at(m)<=jet_max_2) Hpt_rel_jet_range2_no_dif->Fill(pt_rel,relative_weight_15to20);
                          else if(RECOJet_pt.at(m)>jet_max_2) Hpt_rel_jet_range3_no_dif->Fill(pt_rel,relative_weight_15to20);
                                                                                                       }
                  
                  else {   
                      Hpt_rel_no_dif->Fill(pt_rel,relative_weight_20to30);
                      Hmuon_pt_rel_pt_no_dif->Fill(RECOMu_pt.at(m),pt_rel,relative_weight_20to30);
                          if(RECOMu_pt.at(m)>=min_1 && RECOMu_pt.at(m)<=max_1) Hpt_rel_range1_no_dif->Fill(pt_rel,relative_weight_20to30);
                          else if(RECOMu_pt.at(m)>max_1 && RECOMu_pt.at(m)<=max_2) Hpt_rel_range2_no_dif->Fill(pt_rel,relative_weight_20to30);
                          else if(RECOMu_pt.at(m)>max_2) Hpt_rel_range3_no_dif->Fill(pt_rel,relative_weight_20to30);
       
                          if(RECOJet_pt.at(m)>=jet_min_1 && RECOJet_pt.at(m)<=jet_max_1) Hpt_rel_jet_range1_no_dif->Fill(pt_rel,relative_weight_20to30);
                          else if(RECOJet_pt.at(m)>jet_max_1 && RECOJet_pt.at(m)<=jet_max_2) Hpt_rel_jet_range2_no_dif->Fill(pt_rel,relative_weight_20to30);
                          else if(RECOJet_pt.at(m)>jet_max_2) Hpt_rel_jet_range3_no_dif->Fill(pt_rel,relative_weight_20to30);
             
                        }

//08.04.19: Not gonna use the diff anymore, so I won't reweight the events:
               p_jet=p_jet-p_mu;   //CRITICALLLLLLLL!!!!       
       
               pt_rel=(p_mu.Cross(p_jet)).Mag()/p_jet.Mag();
               Hpt_rel->Fill(pt_rel);
               Hmuon_pt_rel_pt->Fill(RECOMu_pt.at(m),pt_rel);
                   if(RECOMu_pt.at(m)>=min_1 && RECOMu_pt.at(m)<=max_1) Hpt_rel_range1->Fill(pt_rel);
                   else if(RECOMu_pt.at(m)>max_1 && RECOMu_pt.at(m)<=max_2) Hpt_rel_range2->Fill(pt_rel);
                   else if(RECOMu_pt.at(m)>max_2) Hpt_rel_range3->Fill(pt_rel);

                   if(RECOJet_pt.at(m)>=jet_min_1 && RECOJet_pt.at(m)<=jet_max_1) Hpt_rel_jet_range1->Fill(pt_rel);
                   else if(RECOJet_pt.at(m)>jet_max_1 && RECOJet_pt.at(m)<=jet_max_2) Hpt_rel_jet_range2->Fill(pt_rel);
                   else if(RECOJet_pt.at(m)>jet_max_2) Hpt_rel_jet_range3->Fill(pt_rel);

                                            
               }

                                        

  tree1.Fill();//save objects in trees
//=======================================================================================================================

  //  cout<<"=========END OF EVENT========="<<endl;
                                                                          }//end_for nentries. END OF EVENT LOOP


//=========================for pt(mu)-vs-pt(jet) and pt(mu)-vs-pt(jet).

vector<float> RATIO;
 for(int i=0;i<GENJET_PT.size();++i) RATIO.push_back(GENMUB_PT[i]/GENJET_PT[i]);

const TVectorF genMuB_pt_genJet_pt_ratio_yAxis(RATIO.size(), &RATIO[0]);
const TVectorF genJet_yAxis(GENJET_PT.size(), &GENJET_PT[0]);
const TVectorF genMuB_xAxis(GENMUB_PT.size(), &GENMUB_PT[0]);

TGraph * genMuB_pt_vs_genJet_pt = new TGraph(genMuB_xAxis,genJet_yAxis);
         genMuB_pt_vs_genJet_pt->SetTitle("genMu_pt -vs- corresponding GenJet");
         genMuB_pt_vs_genJet_pt->GetXaxis()->SetTitle("p_{T}^{muon} [GeV]");
         genMuB_pt_vs_genJet_pt->GetYaxis()->SetTitle("p_{T}^{jet} [GeV]");

TGraph * genMuB_pt_genJet_pt_ratio = new TGraph(genMuB_xAxis,genMuB_pt_genJet_pt_ratio_yAxis);
         genMuB_pt_genJet_pt_ratio->SetTitle("genMu_pt/GenJet_pt");
         genMuB_pt_genJet_pt_ratio->GetXaxis()->SetTitle("p_{T}^{muon} [GeV]");
         genMuB_pt_genJet_pt_ratio->GetYaxis()->SetTitle("p_{T}^{muon}/p_{T}^{jet}");


    gROOT->SetBatch(1);//Do not desplay graphics of this->Draw(), just save canvases in output files etc.
    //if you have a canvas, TCanvas *canvas, do canvas->SetBatch(kTRUE);

TCanvas * finding_pt_jet_cut = new TCanvas("finding_genJet_pt_cut");
         finding_pt_jet_cut->Divide(1,2);
         finding_pt_jet_cut->cd(1);
         genMuB_pt_vs_genJet_pt->Draw("AP");
         finding_pt_jet_cut->cd(2);
         genMuB_pt_genJet_pt_ratio->Draw("AP");

//Once a TFile object has been created it becomes the default file for all I/O. This default is held in the global variable gFile, which can be updated at any time
//To change the default:
               gFile = file2;
               tree1.Write();

        

// Normalize and divide pt_rel(gen) and pt_rel(reco)
//      cout<<"Hpt_rel_gen: /integral('width')/entries/= /" << Hpt_rel_gen->Integral("width") <<"/" << Hpt_rel_gen->GetEntries() <<"/" <<endl;
//      cout<<"Hpt_rel_reco: /integral('width')/entries/= /" << Hpt_rel->Integral("width") <<"/" << Hpt_rel->GetEntries() <<"/" <<endl;
  
      auto Hpt_rel_norm = new TH1F(*Hpt_rel);
      auto Hpt_rel_no_dif_norm = new TH1F(*Hpt_rel_no_dif);
      Hpt_rel_norm->SetName("Hpt_rel_norm");
      Hpt_rel_no_dif_norm->SetName("Hpt_rel_no_dif_norm");

      Hpt_rel_gen->Scale(1/Hpt_rel_gen->Integral("width"));
      Hpt_rel_norm->Scale(1/Hpt_rel->Integral("width"));
      Hpt_rel_no_dif_norm->Scale(1/Hpt_rel_no_dif_norm->Integral("width"));
      Hpt_rel_gen->Sumw2();
      Hpt_rel_norm->Sumw2();
      auto Hpt_rel_gen_vs_reco = new TH1F( *Hpt_rel_gen);
      Hpt_rel_gen_vs_reco->Divide(Hpt_rel_norm);


    Hpt_rel_gen_vs_reco->SetTitle(";;p_{T}^{rel}(gen)/p_{T}^{rel}(reco)");
    Hpt_rel_gen_vs_reco->SetLineColor(kGreen);
    Hpt_rel_gen->SetTitle(";;#frac{1}{N}#frac{dN}{dp_{T}^{rel}}");
    Hpt_rel_gen->GetXaxis()->SetTitle("p_{T}^{rel} [GeV]");



    TCanvas* pt_rel_div= new TCanvas("Hpt_rel(gen)-vs-Hpt_rel(reco)");
    pt_rel_div->Divide(1,2);
    pt_rel_div->cd(1);
    pt_rel_div->GetPad(1)->SetRightMargin(.01);
    Hpt_rel_gen->SetLineColor(kRed);
//    Hpt_rel_gen->DrawNormalized("Hist");
 //   Hpt_rel->DrawNormalized("HistSame");
    Hpt_rel_gen->Draw("Hist");
    Hpt_rel->Draw("HistSame");


 //   pt_rel_div->cd(1)->SetOptStat(1);
    pt_rel_div->cd(1)->BuildLegend();

    pt_rel_div->cd(2);
    Hpt_rel_gen_vs_reco->GetYaxis()->SetRangeUser(0,2.8);
    
    pt_rel_div->GetPad(2)->SetGridy();
 //   pt_rel_div->GetPad(2)->SetRightMargin(.01);
    Hpt_rel_gen_vs_reco->Draw("E0");

    TCanvas * muon_pt_vs_pt_rel = new TCanvas("muon_pt_vs_pt_rel","muon_pt_vs_pt_rel");
    Hmuon_pt_rel_pt->Draw("lego2z");
    TCanvas * muon_pt_vs_pt_rel_no_dif = new TCanvas("muon_pt_vs_pt_rel_no_dif","muon_pt_vs_pt_rel_no_dif");
    Hmuon_pt_rel_pt_no_dif->Draw("lego2z");




               Hrecomu_unmatched_pt->Write();
               Hrecomu_unmatched_eta->Write();

               Hrecomu_pt->Write();
               Hrecomu_eta->Write();
               Hrecomu_phi->Write();                   

               HDR->Write();//gen-reco matching
               Hrecomu_final_pt->Write();//mu matched with recoJet.
                  Hmu_reco_vs_gen_pt->Write();
                  Hmu_reco_vs_gen_eta->Write();
                  Hmu_reco_vs_gen_phi->Write();

               HDR_jet->Write();

               Hrecojet_pt->Write();
               Hrecojet_eta->Write();
               Hrecojet_phi->Write();
               Hpt_rel_gen->Write();
               Hpt_rel->Write();
               Hpt_rel_no_dif->Write();
               Hpt_rel_norm->Write();
               Hpt_rel_no_dif_norm->Write();
               pt_rel_div->Write();

               finding_pt_jet_cut->Write();
               Hmuon_pt_rel_pt->Write();
               Hmuon_pt_rel_pt_no_dif->Write();
               muon_pt_vs_pt_rel->Write();
               muon_pt_vs_pt_rel_no_dif->Write(); 
               Hpt_rel_range1->Write();
               Hpt_rel_range2->Write();
               Hpt_rel_range3->Write();
               Hpt_rel_range1_no_dif->Write();
               Hpt_rel_range2_no_dif->Write();
               Hpt_rel_range3_no_dif->Write();

//05.04.19: Investigating the dependence between pT_rel and pTmu, pTjet:	
          TCanvas * pt_rel_muon_pt_ranges_canvas = new TCanvas("pt_rel_muon_pt_ranges_canvas","pt_rel_muon_pt_ranges_canvas");
          pt_rel_muon_pt_ranges_canvas->Divide(1,2);
          Hpt_rel_range1->SetLineColor(kBlue);
          Hpt_rel_range2->SetLineColor(kRed);
          Hpt_rel_range3->SetLineColor(kGreen);

          //Normalize to 1, compare shapes:
          Hpt_rel_range1->Scale(1/Hpt_rel_range1->Integral("width"));
          Hpt_rel_range2->Scale(1/Hpt_rel_range2->Integral("width"));
          Hpt_rel_range3->Scale(1/Hpt_rel_range3->Integral("width"));          

          pt_rel_muon_pt_ranges_canvas->cd(1);
          Hpt_rel_range1->Draw("hist");
          Hpt_rel_range2->Draw("hist,sames");
          Hpt_rel_range3->Draw("hist,sames");
          gPad->Update();//Without gPad->Update() the line h->FindObject("stats") returns a null pointer
          pt_rel_muon_pt_ranges_canvas->cd(1)->BuildLegend();


          pt_rel_muon_pt_ranges_canvas->cd(2);
          Hpt_rel_range1_no_dif->SetLineColor(kBlue);
          Hpt_rel_range2_no_dif->SetLineColor(kRed);
          Hpt_rel_range3_no_dif->SetLineColor(kGreen);

          Hpt_rel_range1_no_dif->Scale(1/Hpt_rel_range1_no_dif->Integral("width"));
          Hpt_rel_range2_no_dif->Scale(1/Hpt_rel_range2_no_dif->Integral("width"));
          Hpt_rel_range3_no_dif->Scale(1/Hpt_rel_range3_no_dif->Integral("width"));

          Hpt_rel_range1_no_dif->Draw("hist");
          Hpt_rel_range2_no_dif->Draw("hist,sames");
          Hpt_rel_range3_no_dif->Draw("hist,sames");
          gPad->Update();//Without gPad->Update() the line h->FindObject("stats") returns a null pointer
          pt_rel_muon_pt_ranges_canvas->cd(2)->BuildLegend();

          pt_rel_muon_pt_ranges_canvas->Write();

          TCanvas * pt_rel_jet_pt_ranges_canvas = new TCanvas("pt_rel_jet_pt_ranges_canvas","pt_rel_jet_pt_ranges_canvas");
          pt_rel_jet_pt_ranges_canvas->Divide(1,2);
          pt_rel_jet_pt_ranges_canvas->cd(1);
         
          Hpt_rel_jet_range1->SetLineColor(kBlue);
          Hpt_rel_jet_range2->SetLineColor(kRed);
          Hpt_rel_jet_range3->SetLineColor(kGreen);

          //Normalize to 1, compare shapes:
          Hpt_rel_jet_range1->Scale(1/Hpt_rel_jet_range1->Integral("width"));
          Hpt_rel_jet_range2->Scale(1/Hpt_rel_jet_range2->Integral("width"));
          Hpt_rel_jet_range3->Scale(1/Hpt_rel_jet_range3->Integral("width")); 

          Hpt_rel_jet_range1->Draw("hist");
          Hpt_rel_jet_range2->Draw("hist,sames");
          Hpt_rel_jet_range3->Draw("hist,sames"); 
          pt_rel_jet_pt_ranges_canvas->cd(1)->BuildLegend();

          pt_rel_jet_pt_ranges_canvas->cd(2);
          Hpt_rel_jet_range1_no_dif->SetLineColor(kBlue);
          Hpt_rel_jet_range2_no_dif->SetLineColor(kRed);
          Hpt_rel_jet_range3_no_dif->SetLineColor(kGreen);

          Hpt_rel_jet_range1_no_dif->Scale(1/Hpt_rel_jet_range1_no_dif->Integral("width"));
          Hpt_rel_jet_range2_no_dif->Scale(1/Hpt_rel_jet_range2_no_dif->Integral("width"));
          Hpt_rel_jet_range3_no_dif->Scale(1/Hpt_rel_jet_range3_no_dif->Integral("width")); 

          Hpt_rel_jet_range1_no_dif->Draw("hist");
          Hpt_rel_jet_range2_no_dif->Draw("hist,sames");
          Hpt_rel_jet_range3_no_dif->Draw("hist,sames"); 
          pt_rel_jet_pt_ranges_canvas->cd(2)->BuildLegend();

          pt_rel_jet_pt_ranges_canvas->Write();

                delete file2;
  //             delete file1;
//system("./open_browser_script.sh");

}


