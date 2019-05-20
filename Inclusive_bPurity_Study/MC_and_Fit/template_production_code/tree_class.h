//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Jul 15 22:24:47 2018 by ROOT version 6.10/09
// from TTree mytree/mytree
// found on file: /eos/cms/store/group/cmst3/user/gkaratha/Parking_2018A_8_BKmumu_part1/ParkingBPH1/crab_Parking_2018A_8_BKmumu_part1/180715_132305/0000/output_9.root
//////////////////////////////////////////////////////////

#ifndef tree_class_h
#define tree_class_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class tree_class {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           event;
   Int_t           run_number;
   Int_t           ls;
   Int_t           HLT_path1;
   Int_t           HLT_path2;
   Int_t           HLT_path3;
   Int_t           HLT_path4;
   Int_t           HLT_path5;
   Int_t           HLT_path6;
   Int_t           L1_seed1;
   Int_t           L1_seed2;
   Int_t           L1_seed3;
   Int_t           L1_seed4;
   Int_t           L1_seed5;
   Int_t           L1_seed6;
   Double_t        met_pt;
   Double_t        met_phi;
   Int_t           nmuon;
   vector<float>   *muon_pt;
   vector<float>   *muon_eta;
   vector<float>   *muon_phi;
   vector<float>   *muon_charge;
   vector<float>   *muon_qual;
   vector<float>   *muon_dxy;
   vector<float>   *muon_dz;
   vector<float>   *muon_edxy;
   vector<float>   *muon_edz;
   vector<float>   *muon_d0;
   vector<float>   *muon_ed0;
   vector<float>   *muon_vx;
   vector<float>   *muon_vy;
   vector<float>   *muon_vz;
   vector<float>   *muon_iso;
   vector<float>   *muon_global_flag;
   vector<float>   *muon_tracker_flag;
   vector<float>   *muon_standalone_flag;
   vector<bool>    *muon_soft;
   vector<bool>    *muon_loose;
   vector<bool>    *muon_medium;
   vector<bool>    *muon_tight;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_y;
   vector<float>   *jet_phi;
   vector<float>   *jet_mass;
   vector<float>   *jet_cEmEF;
   vector<float>   *jet_cHEF;
   vector<float>   *jet_cHMult;
   vector<float>   *jet_cMuEF;
   vector<float>   *jet_cMult;
   vector<float>   *jet_MuEF;
   vector<float>   *jet_nEmEF;
   vector<float>   *jet_nHEF;
   vector<float>   *jet_nMult;
   vector<float>   *jet_eEF;
   vector<float>   *jet_pEF;
   Int_t           njets;
   Int_t           nelectron;
   vector<float>   *el_pt;
   vector<float>   *el_eta;
   vector<float>   *el_phi;
   vector<float>   *el_charge;
   vector<float>   *el_dxy;
   vector<float>   *el_dz;
   vector<float>   *el_vx;
   vector<float>   *el_vy;
   vector<float>   *el_vz;
   vector<float>   *el_mva_out;
   vector<float>   *el_mva_iso;
   vector<float>   *el_iso;
   vector<bool>    *el_veto;
   vector<bool>    *el_soft;
   vector<bool>    *el_medium;
   vector<bool>    *el_tight;
   vector<float>   *el_mva_map_value;
   vector<vector<float> > *HLT1Obj_pt_eta_phi_charge;
   vector<vector<float> > *HLT2Obj_pt_eta_phi_charge;
   vector<vector<float> > *HLT3Obj_pt_eta_phi_charge;
   vector<vector<float> > *HLT4Obj_pt_eta_phi_charge;
   vector<vector<float> > *HLT5Obj_pt_eta_phi_charge;
   vector<vector<float> > *HLT6Obj_pt_eta_phi_charge;
   vector<float>   *l1muon_pt;
   vector<float>   *l1muon_eta;
   vector<float>   *l1muon_phi;
   vector<float>   *l1muon_iso;
   vector<float>   *l1muon_qual;
   vector<float>   *l1jet_pt;
   vector<float>   *l1jet_eta;
   vector<float>   *l1jet_phi;
   vector<float>   *l1jet_iso;
   vector<float>   *l1jet_qual;
   Double_t        l1met;
   Double_t        l1met_phi;
   Double_t        l1ht;
   Double_t        l1hf_met;
   Double_t        l1hf_met_phi;
   vector<float>   *genpart_pt;
   vector<float>   *genpart_phi;
   vector<float>   *genpart_eta;
   vector<float>   *genpart_pdgId;
   vector<float>   *genpart_Bindex;
   vector<float>   *genpart_Daughtindex;
   vector<float>   *genpart_charge;
   vector<float>   *genpart_mother_pdgId;
   vector<float>   *genpart_mother_pt;
   vector<float>   *genpart_mother_phi;
   vector<float>   *genpart_mother_eta;
   vector<float>   *genpart_mother_Bindex;
   vector<float>   *genpart_mother_Daughtindex;
   vector<float>   *genpart_grandmother_pdgId;
   vector<float>   *genpart_grandmother_pt;
   vector<float>   *genpart_grandmother_phi;
   vector<float>   *genpart_grandmother_eta;
   vector<float>   *genpart_grandmother_Bindex;
   Int_t           good_vertex;
   vector<vector<int> > *muon_vertex_IsValid;
   vector<vector<float> > *muon_vertex_chiSquared;
   vector<vector<float> > *muon_vertex_DOF;
   vector<vector<float> > *muon_vertex_x;
   vector<vector<float> > *muon_vertex_y;
   vector<vector<float> > *muon_vertex_z;
   vector<vector<float> > *muon_vertex_ex;
   vector<vector<float> > *muon_vertex_ey;
   vector<vector<float> > *muon_vertex_ez;
   vector<vector<float> > *muon_vertex_distPV;
   vector<vector<float> > *muon_vertex_probability;
   vector<vector<float> > *muon_vertex_refitPt1;
   vector<vector<float> > *muon_vertex_refitPt2;
   vector<vector<float> > *muon_DCA;
   vector<float>   *muon_trkpt;
   vector<float>   *muon_trketa;
   vector<float>   *muon_trkphi;
   vector<float>   *el_trkpt;
   vector<float>   *el_trketa;
   vector<float>   *el_trkphi;
   vector<vector<int> > *el_vertex_IsValid;
   vector<vector<float> > *el_vertex_chiSquared;
   vector<vector<float> > *el_vertex_DOF;
   vector<vector<float> > *el_vertex_x;
   vector<vector<float> > *el_vertex_y;
   vector<vector<float> > *el_vertex_z;
   vector<vector<float> > *el_vertex_ex;
   vector<vector<float> > *el_vertex_ey;
   vector<vector<float> > *el_vertex_ez;
   vector<vector<float> > *el_vertex_distPV;
   vector<vector<float> > *el_vertex_probability;
   vector<vector<float> > *el_vertex_refitPt1;
   vector<vector<float> > *el_vertex_refitPt2;
   Float_t         pvertex_x;
   Float_t         pvertex_y;
   Float_t         pvertex_z;
   Float_t         pvertex_ex;
   Float_t         pvertex_ey;
   Float_t         pvertex_ez;
   Int_t           ntracks;
   vector<float>   *track_pt;
   vector<float>   *track_eta;
   vector<float>   *track_phi;
   vector<float>   *track_norm_chi2;
   vector<float>   *track_charge;
   vector<float>   *track_dxy;
   vector<float>   *track_dz;
   vector<float>   *track_validhits;
   vector<float>   *track_losthits;
   vector<float>   *track_validfraction;
   Bool_t          bit;
   Int_t           nkaons;
   vector<float>   *kaon_pt;
   vector<float>   *kaon_eta;
   vector<float>   *kaon_phi;
   vector<float>   *kaon_mass;
   vector<float>   *kaon_norm_chi2;
   vector<float>   *kaon_x;
   vector<float>   *kaon_y;
   vector<float>   *kaon_z;
   vector<float>   *kaon_trk1pt;
   vector<float>   *kaon_trk1eta;
   vector<float>   *kaon_trk1phi;
   vector<float>   *kaon_trk1charge;
   vector<float>   *kaon_trk2pt;
   vector<float>   *kaon_trk2eta;
   vector<float>   *kaon_trk2phi;
   vector<float>   *kaon_trk2charge;
   Int_t           beam_x;
   Int_t           beam_y;
   Int_t           beam_z;
   Int_t           beam_ex;
   Int_t           beam_ey;
   Int_t           beam_ez;
   vector<float>   *vertex_x;
   vector<float>   *vertex_y;
   vector<float>   *vertex_z;
   vector<float>   *vertex_ex;
   vector<float>   *vertex_ey;
   vector<float>   *vertex_ez;
   vector<float>   *vertex_chi;
   vector<float>   *vertex_ndof;
   Int_t           npv;
   Int_t           njpsi_mumu;
   Int_t           njpsi_ee;
   vector<float>   *jpsi_pt;
   vector<float>   *jpsi_eta;
   vector<float>   *jpsi_phi;
   vector<float>   *jpsi_chi2;
   vector<float>   *jpsi_ndof;
   vector<float>   *jpsi_ctxy;
   vector<float>   *jpsi_x;
   vector<float>   *jpsi_y;
   vector<float>   *jpsi_z;
   vector<float>   *jpsi_ex;
   vector<float>   *jpsi_ey;
   vector<float>   *jpsi_ez;
   vector<float>   *jpsi_prob;
   vector<float>   *jpsi_mass;
   vector<float>   *jpsi_trk1pt;
   vector<float>   *jpsi_trk1eta;
   vector<float>   *jpsi_trk1phi;
   vector<float>   *jpsi_trk1charge;
   vector<float>   *jpsi_trk2pt;
   vector<float>   *jpsi_trk2eta;
   vector<float>   *jpsi_trk2phi;
   vector<float>   *jpsi_trk2charge;
   vector<float>   *jpsi_pf1pt;
   vector<float>   *jpsi_pf1eta;
   vector<float>   *jpsi_pf1phi;
   vector<float>   *jpsi_pf2pt;
   vector<float>   *jpsi_pf2eta;
   vector<float>   *jpsi_pf2phi;
   vector<string>  *jpsi_flavour;
   vector<float>   *jpsi_trk1ept;
   vector<float>   *jpsi_trk1eeta;
   vector<float>   *jpsi_trk1ephi;
   vector<float>   *jpsi_trk2ept;
   vector<float>   *jpsi_trk2eeta;
   vector<float>   *jpsi_trk2ephi;
   vector<float>   *jpsi_trk1pt_unfit;
   vector<float>   *jpsi_trk2pt_unfit;
   vector<float>   *jpsi_trk1ept_unfit;
   vector<float>   *jpsi_trk2ept_unfit;
   vector<float>   *jpsi_trk1eta_unfit;
   vector<float>   *jpsi_trk2eta_unfit;
   vector<float>   *jpsi_trk1eeta_unfit;
   vector<float>   *jpsi_trk2eeta_unfit;
   vector<float>   *jpsi_trk1phi_unfit;
   vector<float>   *jpsi_trk2phi_unfit;
   vector<float>   *jpsi_trk1ephi_unfit;
   vector<float>   *jpsi_trk2ephi_unfit;
   vector<float>   *jpsi_lep1id;
   vector<float>   *jpsi_lep2id;
   vector<vector<float> > *kaon_ch_pt;
   vector<vector<float> > *kaon_ch_eta;
   vector<vector<float> > *kaon_ch_phi;
   vector<vector<float> > *kaon_ch_charge;
   vector<vector<float> > *kaon_ch_chinorm;
   vector<vector<float> > *kaon_ch_ept;
   vector<vector<float> > *kaon_ch_eeta;
   vector<vector<float> > *kaon_ch_ephi;
   vector<vector<float> > *b_pt;
   vector<vector<float> > *b_pz;
   vector<vector<float> > *b_eta;
   vector<vector<float> > *b_phi;
   vector<vector<float> > *b_charge;
   vector<vector<float> > *b_mass;
   vector<vector<float> > *b_chi;
   vector<vector<float> > *b_ndof;
   vector<vector<float> > *b_x;
   vector<vector<float> > *b_y;
   vector<vector<float> > *b_z;
   vector<vector<float> > *b_ex;
   vector<vector<float> > *b_ey;
   vector<vector<float> > *b_ez;
   vector<vector<float> > *b_ept;
   vector<vector<float> > *b_eeta;
   vector<vector<float> > *b_ephi;
   vector<vector<float> > *NRb_pt_eta_phi;
   vector<float>   *NRb_mass;
   vector<float>   *NRb_chi_prob;
   vector<vector<float> > *NRb_x_y_z;
   vector<vector<float> > *NRb_ex_ey_ez;
   vector<vector<float> > *NRb_ept_eeta_ephi;
   vector<bool>    *NRb_mudecay;
   vector<vector<float> > *NRb_Kpt_eta_phi;
   vector<float>   *NRb_charge;
   vector<vector<float> > *NRb_l1pt_eta_phi_charge;
   vector<vector<float> > *NRb_l2pt_eta_phi_charge;
   vector<float>   *NRb_lep1Id;
   vector<float>   *NRb_lep2Id;
   vector<float>   *NRb_mll;
   vector<float>   *NRb_ll_prob;
   vector<float>   *NRb_trk_sdxy;
   vector<vector<float> > *D0_pt;
   vector<float>   *D0_pt_unfit;
   vector<vector<float> > *D0_eta;
   vector<vector<float> > *D0_phi;
   vector<float>   *D0_x;
   vector<float>   *D0_y;
   vector<float>   *D0_z;
   vector<float>   *D0_chi2;
   vector<float>   *D0_ndof;
   vector<float>   *D0_prob;
   vector<vector<float> > *D0_mass;
   vector<vector<float> > *D0_IsKtrk;
   vector<vector<float> > *D0_ctxy;
   vector<float>   *D0_trk1pt;
   vector<float>   *D0_trk1pt_unfit;
   vector<float>   *D0_trk1eta;
   vector<float>   *D0_trk1phi;
   vector<float>   *D0_trk1charge;
   vector<float>   *D0_trk2pt;
   vector<float>   *D0_trk2pt_unfit;
   vector<float>   *D0_trk2eta;
   vector<float>   *D0_trk2phi;
   vector<float>   *D0_trk2charge;
   vector<vector<float> > *Dstar_pt;
   vector<vector<float> > *Dstar_eta;
   vector<vector<float> > *Dstar_phi;
   vector<vector<float> > *Dstar_x;
   vector<vector<float> > *Dstar_y;
   vector<vector<float> > *Dstar_z;
   vector<vector<float> > *Dstar_chi2;
   vector<vector<float> > *Dstar_ndof;
   vector<vector<float> > *Dstar_mass;
   vector<vector<float> > *Dstar_trk1pt;
   vector<vector<float> > *Dstar_trk1eta;
   vector<vector<float> > *Dstar_trk1phi;
   vector<vector<float> > *Dstar_trk1charge;
   vector<vector<float> > *Dstar_trk1chinorm;
   vector<vector<float> > *Dstar_DRtrk1D0;
   vector<vector<float> > *Dstar_trk1error;
   vector<vector<float> > *Dstar_Mdif;
   vector<vector<float> > *Dstar_IsK;
   vector<float>   *DstarB_muId;
   vector<float>   *DstarB_x;
   vector<float>   *DstarB_y;
   vector<float>   *DstarB_z;
   vector<float>   *DstarB_chi2;
   vector<float>   *DstarB_chi2prob;
   vector<float>   *DstarB_D0Id;
   vector<float>   *DstarB_DsId;
   Float_t         ngenB;
   vector<float>   *genbq_pt;
   vector<float>   *genbq_eta;
   vector<float>   *genbq_phi;
   vector<float>   *genbq_charge;
   vector<float>   *genbqhadr_pt;
   vector<float>   *genB_pdgId;
   vector<float>   *genBtoDsMu;
   vector<float>   *genBisMuDecay;
   vector<float>   *genB0_pt;
   vector<float>   *genB0_eta;
   vector<float>   *genB0_phi;
   vector<float>   *genMuBMother_pdgId;


   vector<float>   *genMuB_pt;
   vector<float>   *genMuB_eta;
   vector<float>   *genMuB_phi;

   vector<float>   *genMuC_pt;
   vector<float>   *genMuC_eta;
   vector<float>   *genMuC_phi;

   vector<float>   *genMuUDS_pt;
   vector<float>   *genMuUDS_eta;
   vector<float>   *genMuUDS_phi;

   vector<float>   *genMuBDs;
   vector<float>   *genMuBDsWithGamma;
   vector<float>   *genMuBDsGammaPt;
   vector<float>   *genMuBMother_bqId;
   vector<float>   *genMuB_bgPt;
   vector<float>   *genMuB_bqEta;
   vector<float>   *genMuB_bqPhi;
   vector<float>   *genMu_pt;
   vector<float>   *genMu_eta;
   vector<float>   *genMu_phi;
   vector<float>   *genMu_ch;
   vector<float>   *genMu_motherId;
   vector<float>   *genMu_gmotherId;
   vector<float>   *genMu_dxy;
   vector<float>   *genMu_edxy;
   vector<vector<float> > *genB0Daughter_pt;
   vector<vector<float> > *genB0Daughter_eta;
   vector<vector<float> > *genB0Daughter_phi;
   vector<vector<float> > *genB0Daughter_pdgId;
   vector<vector<float> > *genB0Daughter_dxy;
   vector<vector<float> > *genB0Daughter_edxy;
   vector<vector<float> > *genDsDaughter_pt;
   vector<vector<float> > *genDsDaughter_eta;
   vector<vector<float> > *genDsDaughter_phi;
   vector<vector<float> > *genDsDaughter_pdgId;
   vector<vector<float> > *genD0Daughter_pt;
   vector<vector<float> > *genD0Daughter_eta;
   vector<vector<float> > *genD0Daughter_phi;
   vector<vector<float> > *genD0Daughter_pdgId;

   //VB:For genJet analysis
   vector<int> *genJet_flavour;
   vector<float> *genJet_pt;
   vector<float> *genJet_eta;
   vector<float> *genJet_y;
   vector<float> *genJet_phi;
   vector<float> *genJet_mass;
   vector<float> *dR_cJet_matching;
   vector<float> *dR_bJet_matching;
   vector<float> *dR_lightJet_matching;

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_run_number;   //!
   TBranch        *b_ls;   //!
   TBranch        *b_HLT_path1;   //!
   TBranch        *b_HLT_path2;   //!
   TBranch        *b_HLT_path3;   //!
   TBranch        *b_HLT_path4;   //!
   TBranch        *b_HLT_path5;   //!
   TBranch        *b_HLT_path6;   //!
   TBranch        *b_L1_seed1;   //!
   TBranch        *b_L1_seed2;   //!
   TBranch        *b_L1_seed3;   //!
   TBranch        *b_L1_seed4;   //!
   TBranch        *b_L1_seed5;   //!
   TBranch        *b_L1_seed6;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_nmuon;   //!
   TBranch        *b_muon_pt;   //!
   TBranch        *b_muon_eta;   //!
   TBranch        *b_muon_phi;   //!
   TBranch        *b_muon_charge;   //!
   TBranch        *b_muon_qual;   //!
   TBranch        *b_muon_dxy;   //!
   TBranch        *b_muon_dz;   //!
   TBranch        *b_muon_edxy;   //!
   TBranch        *b_muon_edz;   //!
   TBranch        *b_muon_d0;   //!
   TBranch        *b_muon_ed0;   //!
   TBranch        *b_muon_vx;   //!
   TBranch        *b_muon_vy;   //!
   TBranch        *b_muon_vz;   //!
   TBranch        *b_muon_iso;   //!
   TBranch        *b_muon_global_flag;   //!
   TBranch        *b_muon_tracker_flag;   //!
   TBranch        *b_muon_standalone_flag;   //!
   TBranch        *b_muon_soft;   //!
   TBranch        *b_muon_loose;   //!
   TBranch        *b_muon_medium;   //!
   TBranch        *b_muon_tight;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_y;
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_mass;
   TBranch        *b_jet_cEmEF;   //!
   TBranch        *b_jet_cHEF;   //!
   TBranch        *b_jet_cHMult;   //!
   TBranch        *b_jet_cMuEF;   //!
   TBranch        *b_jet_cMult;   //!
   TBranch        *b_jet_MuEF;   //!
   TBranch        *b_jet_nEmEF;   //!
   TBranch        *b_jet_nHEF;   //!
   TBranch        *b_jet_nMult;   //!
   TBranch        *b_jet_eEF;   //!
   TBranch        *b_jet_pEF;   //!
   TBranch        *b_njets;   //!
   TBranch        *b_nelectron;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_dxy;   //!
   TBranch        *b_el_dz;   //!
   TBranch        *b_el_vx;   //!
   TBranch        *b_el_vy;   //!
   TBranch        *b_el_vz;   //!
   TBranch        *b_el_mva_out;   //!
   TBranch        *b_el_mva_iso;   //!
   TBranch        *b_el_iso;   //!
   TBranch        *b_el_veto;   //!
   TBranch        *b_el_soft;   //!
   TBranch        *b_el_medium;   //!
   TBranch        *b_el_tight;   //!
   TBranch        *b_el_mva_map_value;   //!
   TBranch        *b_HLT1Obj_pt_eta_phi_charge;   //!
   TBranch        *b_HLT2Obj_pt_eta_phi_charge;   //!
   TBranch        *b_HLT3Obj_pt_eta_phi_charge;   //!
   TBranch        *b_HLT4Obj_pt_eta_phi_charge;   //!
   TBranch        *b_HLT5Obj_pt_eta_phi_charge;   //!
   TBranch        *b_HLT6Obj_pt_eta_phi_charge;   //!
   TBranch        *b_l1muon_pt;   //!
   TBranch        *b_l1muon_eta;   //!
   TBranch        *b_l1muon_phi;   //!
   TBranch        *b_l1muon_iso;   //!
   TBranch        *b_l1muon_qual;   //!
   TBranch        *b_l1jet_pt;   //!
   TBranch        *b_l1jet_eta;   //!
   TBranch        *b_l1jet_phi;   //!
   TBranch        *b_l1jet_iso;   //!
   TBranch        *b_l1jet_qual;   //!
   TBranch        *b_l1met;   //!
   TBranch        *b_l1met_phi;   //!
   TBranch        *b_l1ht;   //!
   TBranch        *b_l1hf_met;   //!
   TBranch        *b_l1hf_met_phi;   //!
   TBranch        *b_genpart_pt;   //!
   TBranch        *b_genpart_phi;   //!
   TBranch        *b_genpart_eta;   //!
   TBranch        *b_genpart_pdgId;   //!
   TBranch        *b_genpart_Bindex;   //!
   TBranch        *b_genpart_Daughtindex;   //!
   TBranch        *b_genpart_charge;   //!
   TBranch        *b_genpart_mother_pdgId;   //!
   TBranch        *b_genpart_mother_pt;   //!
   TBranch        *b_genpart_mother_phi;   //!
   TBranch        *b_genpart_mother_eta;   //!
   TBranch        *b_genpart_mother_Bindex;   //!
   TBranch        *b_genpart_mother_Daughtindex;   //!
   TBranch        *b_genpart_grandmother_pdgId;   //!
   TBranch        *b_genpart_grandmother_pt;   //!
   TBranch        *b_genpart_grandmother_phi;   //!
   TBranch        *b_genpart_grandmother_eta;   //!
   TBranch        *b_genpart_grandmother_Bindex;   //!
   TBranch        *b_good_vertex;   //!
   TBranch        *b_muon_vertex_IsValid;   //!
   TBranch        *b_muon_vertex_chiSquared;   //!
   TBranch        *b_muon_vertex_DOF;   //!
   TBranch        *b_muon_vertex_x;   //!
   TBranch        *b_muon_vertex_y;   //!
   TBranch        *b_muon_vertex_z;   //!
   TBranch        *b_muon_vertex_ex;   //!
   TBranch        *b_muon_vertex_ey;   //!
   TBranch        *b_muon_vertex_ez;   //!
   TBranch        *b_muon_vertex_distPV;   //!
   TBranch        *b_muon_vertex_probability;   //!
   TBranch        *b_muon_vertex_refitPt1;   //!
   TBranch        *b_muon_vertex_refitPt2;   //!
   TBranch        *b_muon_DCA;   //!
   TBranch        *b_muon_trkpt;   //!
   TBranch        *b_muon_trketa;   //!
   TBranch        *b_muon_trkphi;   //!
   TBranch        *b_el_trkpt;   //!
   TBranch        *b_el_trketa;   //!
   TBranch        *b_el_trkphi;   //!
   TBranch        *b_el_vertex_IsValid;   //!
   TBranch        *b_el_vertex_chiSquared;   //!
   TBranch        *b_el_vertex_DOF;   //!
   TBranch        *b_el_vertex_x;   //!
   TBranch        *b_el_vertex_y;   //!
   TBranch        *b_el_vertex_z;   //!
   TBranch        *b_el_vertex_ex;   //!
   TBranch        *b_el_vertex_ey;   //!
   TBranch        *b_el_vertex_ez;   //!
   TBranch        *b_el_vertex_distPV;   //!
   TBranch        *b_el_vertex_probability;   //!
   TBranch        *b_el_vertex_refitPt1;   //!
   TBranch        *b_el_vertex_refitPt2;   //!
   TBranch        *b_pvertex_x;   //!
   TBranch        *b_pvertex_y;   //!
   TBranch        *b_pvertex_z;   //!
   TBranch        *b_pvertex_ex;   //!
   TBranch        *b_pvertex_ey;   //!
   TBranch        *b_pvertex_ez;   //!
   TBranch        *b_ntracks;   //!
   TBranch        *b_track_pt;   //!
   TBranch        *b_track_eta;   //!
   TBranch        *b_track_phi;   //!
   TBranch        *b_track_norm_chi2;   //!
   TBranch        *b_track_charge;   //!
   TBranch        *b_track_dxy;   //!
   TBranch        *b_track_dz;   //!
   TBranch        *b_track_validhits;   //!
   TBranch        *b_track_losthits;   //!
   TBranch        *b_track_validfraction;   //!
   TBranch        *b_bit;   //!
   TBranch        *b_nkaons;   //!
   TBranch        *b_kaon_pt;   //!
   TBranch        *b_kaon_eta;   //!
   TBranch        *b_kaon_phi;   //!
   TBranch        *b_kaon_mass;   //!
   TBranch        *b_kaon_norm_chi2;   //!
   TBranch        *b_kaon_x;   //!
   TBranch        *b_kaon_y;   //!
   TBranch        *b_kaon_z;   //!
   TBranch        *b_kaon_trk1pt;   //!
   TBranch        *b_kaon_trk1eta;   //!
   TBranch        *b_kaon_trk1phi;   //!
   TBranch        *b_kaon_trk1charge;   //!
   TBranch        *b_kaon_trk2pt;   //!
   TBranch        *b_kaon_trk2eta;   //!
   TBranch        *b_kaon_trk2phi;   //!
   TBranch        *b_kaon_trk2charge;   //!
   TBranch        *b_beam_x;   //!
   TBranch        *b_beam_y;   //!
   TBranch        *b_beam_z;   //!
   TBranch        *b_beam_ex;   //!
   TBranch        *b_beam_ey;   //!
   TBranch        *b_beam_ez;   //!
   TBranch        *b_vertex_x;   //!
   TBranch        *b_vertex_y;   //!
   TBranch        *b_vertex_z;   //!
   TBranch        *b_vertex_ex;   //!
   TBranch        *b_vertex_ey;   //!
   TBranch        *b_vertex_ez;   //!
   TBranch        *b_vertex_chi;   //!
   TBranch        *b_vertex_ndof;   //!
   TBranch        *b_npv;   //!
   TBranch        *b_njpsi_mumu;   //!
   TBranch        *b_njpsi_ee;   //!
   TBranch        *b_jpsi_pt;   //!
   TBranch        *b_jpsi_eta;   //!
   TBranch        *b_jpsi_phi;   //!
   TBranch        *b_jpsi_chi2;   //!
   TBranch        *b_jpsi_ndof;   //!
   TBranch        *b_jpsi_ctxy;   //!
   TBranch        *b_jpsi_x;   //!
   TBranch        *b_jpsi_y;   //!
   TBranch        *b_jpsi_z;   //!
   TBranch        *b_jpsi_ex;   //!
   TBranch        *b_jpsi_ey;   //!
   TBranch        *b_jpsi_ez;   //!
   TBranch        *b_jpsi_prob;   //!
   TBranch        *b_jpsi_mass;   //!
   TBranch        *b_jpsi_trk1pt;   //!
   TBranch        *b_jpsi_trk1eta;   //!
   TBranch        *b_jpsi_trk1phi;   //!
   TBranch        *b_jpsi_trk1charge;   //!
   TBranch        *b_jpsi_trk2pt;   //!
   TBranch        *b_jpsi_trk2eta;   //!
   TBranch        *b_jpsi_trk2phi;   //!
   TBranch        *b_jpsi_trk2charge;   //!
   TBranch        *b_jpsi_pf1pt;   //!
   TBranch        *b_jpsi_pf1eta;   //!
   TBranch        *b_jpsi_pf1phi;   //!
   TBranch        *b_jpsi_pf2pt;   //!
   TBranch        *b_jpsi_pf2eta;   //!
   TBranch        *b_jpsi_pf2phi;   //!
   TBranch        *b_jpsi_flavour;   //!
   TBranch        *b_jpsi_trk1ept;   //!
   TBranch        *b_jpsi_trk1eeta;   //!
   TBranch        *b_jpsi_trk1ephi;   //!
   TBranch        *b_jpsi_trk2ept;   //!
   TBranch        *b_jpsi_trk2eeta;   //!
   TBranch        *b_jpsi_trk2ephi;   //!
   TBranch        *b_jpsi_trk1pt_unfit;   //!
   TBranch        *b_jpsi_trk2pt_unfit;   //!
   TBranch        *b_jpsi_trk1ept_unfit;   //!
   TBranch        *b_jpsi_trk2ept_unfit;   //!
   TBranch        *b_jpsi_trk1eta_unfit;   //!
   TBranch        *b_jpsi_trk2eta_unfit;   //!
   TBranch        *b_jpsi_trk1eeta_unfit;   //!
   TBranch        *b_jpsi_trk2eeta_unfit;   //!
   TBranch        *b_jpsi_trk1phi_unfit;   //!
   TBranch        *b_jpsi_trk2phi_unfit;   //!
   TBranch        *b_jpsi_trk1ephi_unfit;   //!
   TBranch        *b_jpsi_trk2ephi_unfit;   //!
   TBranch        *b_jpsi_lep1id;   //!
   TBranch        *b_jpsi_lep2id;   //!
   TBranch        *b_kaon_ch_pt;   //!
   TBranch        *b_kaon_ch_eta;   //!
   TBranch        *b_kaon_ch_phi;   //!
   TBranch        *b_kaon_ch_charge;   //!
   TBranch        *b_kaon_ch_chinorm;   //!
   TBranch        *b_kaon_ch_ept;   //!
   TBranch        *b_kaon_ch_eeta;   //!
   TBranch        *b_kaon_ch_ephi;   //!
   TBranch        *b_b_pt;   //!
   TBranch        *b_b_pz;   //!
   TBranch        *b_b_eta;   //!
   TBranch        *b_b_phi;   //!
   TBranch        *b_b_charge;   //!
   TBranch        *b_b_mass;   //!
   TBranch        *b_b_chi;   //!
   TBranch        *b_b_ndof;   //!
   TBranch        *b_b_x;   //!
   TBranch        *b_b_y;   //!
   TBranch        *b_b_z;   //!
   TBranch        *b_b_ex;   //!
   TBranch        *b_b_ey;   //!
   TBranch        *b_b_ez;   //!
   TBranch        *b_b_ept;   //!
   TBranch        *b_b_eeta;   //!
   TBranch        *b_b_ephi;   //!
   TBranch        *b_NRb_pt_eta_phi;   //!
   TBranch        *b_NRb_mass;   //!
   TBranch        *b_NRb_chi_prob;   //!
   TBranch        *b_NRb_x_y_z;   //!
   TBranch        *b_NRb_ex_ey_ez;   //!
   TBranch        *b_NRb_ept_eeta_ephi;   //!
   TBranch        *b_NRb_mudecay;   //!
   TBranch        *b_NRb_Kpt_eta_phi;   //!
   TBranch        *b_NRb_charge;   //!
   TBranch        *b_NRb_l1pt_eta_phi_charge;   //!
   TBranch        *b_NRb_l2pt_eta_phi_charge;   //!
   TBranch        *b_NRb_lep1Id;   //!
   TBranch        *b_NRb_lep2Id;   //!
   TBranch        *b_NRb_mll;   //!
   TBranch        *b_NRb_ll_prob;   //!
   TBranch        *b_NRb_trk_sdxy;   //!
   TBranch        *b_D0_pt;   //!
   TBranch        *b_D0_pt_unfit;   //!
   TBranch        *b_D0_eta;   //!
   TBranch        *b_D0_phi;   //!
   TBranch        *b_D0_x;   //!
   TBranch        *b_D0_y;   //!
   TBranch        *b_D0_z;   //!
   TBranch        *b_D0_chi2;   //!
   TBranch        *b_D0_ndof;   //!
   TBranch        *b_D0_prob;   //!
   TBranch        *b_D0_mass;   //!
   TBranch        *b_D0_IsKtrk;   //!
   TBranch        *b_D0_ctxy;   //!
   TBranch        *b_D0_trk1pt;   //!
   TBranch        *b_D0_trk1pt_unfit;   //!
   TBranch        *b_D0_trk1eta;   //!
   TBranch        *b_D0_trk1phi;   //!
   TBranch        *b_D0_trk1charge;   //!
   TBranch        *b_D0_trk2pt;   //!
   TBranch        *b_D0_trk2pt_unfit;   //!
   TBranch        *b_D0_trk2eta;   //!
   TBranch        *b_D0_trk2phi;   //!
   TBranch        *b_D0_trk2charge;   //!
   TBranch        *b_Dstar_pt;   //!
   TBranch        *b_Dstar_eta;   //!
   TBranch        *b_Dstar_phi;   //!
   TBranch        *b_Dstar_x;   //!
   TBranch        *b_Dstar_y;   //!
   TBranch        *b_Dstar_z;   //!
   TBranch        *b_Dstar_chi2;   //!
   TBranch        *b_Dstar_ndof;   //!
   TBranch        *b_Dstar_mass;   //!
   TBranch        *b_Dstar_trk1pt;   //!
   TBranch        *b_Dstar_trk1eta;   //!
   TBranch        *b_Dstar_trk1phi;   //!
   TBranch        *b_Dstar_trk1charge;   //!
   TBranch        *b_Dstar_trk1chinorm;   //!
   TBranch        *b_Dstar_DRtrk1D0;   //!
   TBranch        *b_Dstar_trk1error;   //!
   TBranch        *b_Dstar_Mdif;   //!
   TBranch        *b_Dstar_IsK;   //!
   TBranch        *b_DstarB_muId;   //!
   TBranch        *b_DstarB_x;   //!
   TBranch        *b_DstarB_y;   //!
   TBranch        *b_DstarB_z;   //!
   TBranch        *b_DstarB_chi2;   //!
   TBranch        *b_DstarB_chi2prob;   //!
   TBranch        *b_DstarB_D0Id;   //!
   TBranch        *b_DstarB_DsId;   //!
   TBranch        *b_ngenB;   //!
   TBranch        *b_genbq_pt;   //!
   TBranch        *b_genbq_eta;   //!
   TBranch        *b_genbq_phi;   //!
   TBranch        *b_genbq_charge;   //!
   TBranch        *b_genbqhadr_pt;   //!
   TBranch        *b_genB_pdgId;   //!
   TBranch        *b_genBtoDsMu;   //!
   TBranch        *b_genBisMuDecay;   //!
   TBranch        *b_genB0_pt;   //!
   TBranch        *b_genB0_eta;   //!
   TBranch        *b_genB0_phi;   //!
   TBranch        *b_genMuBMother_pdgId;   //!

   TBranch        *b_genMuB_pt;   //!
   TBranch        *b_genMuB_eta;   //!
   TBranch        *b_genMuB_phi;   //!
 
   TBranch        *b_genMuC_pt;   //!
   TBranch        *b_genMuC_eta;   //!
   TBranch        *b_genMuC_phi;   //!

   TBranch        *b_genMuUDS_pt;   //!
   TBranch        *b_genMuUDS_eta;   //!
   TBranch        *b_genMuUDS_phi;   //!

   TBranch        *b_genMuBDs;   //!
   TBranch        *b_genMuBDsWithGamma;   //!
   TBranch        *b_genMuBDsGammaPt;   //!
   TBranch        *b_genMuBMother_bqId;   //!
   TBranch        *b_genMuB_bgPt;   //!
   TBranch        *b_genMuB_bqEta;   //!
   TBranch        *b_genMuB_bqPhi;   //!
   TBranch        *b_genMu_pt;   //!
   TBranch        *b_genMu_eta;   //!
   TBranch        *b_genMu_phi;   //!
   TBranch        *b_genMu_ch;   //!
   TBranch        *b_genMu_motherId;   //!
   TBranch        *b_genMu_gmotherId;   //!
   TBranch        *b_genMu_dxy;   //!
   TBranch        *b_genMu_edxy;   //!
   TBranch        *b_genB0Daughter_pt;   //!
   TBranch        *b_genB0Daughter_eta;   //!
   TBranch        *b_genB0Daughter_phi;   //!
   TBranch        *b_genB0Daughter_pdgId;   //!
   TBranch        *b_genB0Daughter_dxy;   //!
   TBranch        *b_genB0Daughter_edxy;   //!
   TBranch        *b_genDsDaughter_pt;   //!
   TBranch        *b_genDsDaughter_eta;   //!
   TBranch        *b_genDsDaughter_phi;   //!
   TBranch        *b_genDsDaughter_pdgId;   //!
   TBranch        *b_genD0Daughter_pt;   //!
   TBranch        *b_genD0Daughter_eta;   //!
   TBranch        *b_genD0Daughter_phi;   //!
   TBranch        *b_genD0Daughter_pdgId;   //!

//VB: For genJet analysis
   TBranch        *b_genJet_flavour;
   TBranch        *b_genJet_pt;
   TBranch        *b_genJet_eta;
   TBranch        *b_genJet_y;
   TBranch        *b_genJet_phi;
   TBranch        *b_genJet_mass;
   TBranch        *b_dR_cJet_matching;
   TBranch        *b_dR_bJet_matching;
   TBranch        *b_dR_lightJet_matching;



   tree_class(TTree *tree=0);
   virtual ~tree_class();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree,TString part);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};


tree_class::tree_class(TTree *tree) : fChain(0) 
{
   TString part="0";
   Init(tree,part);
}

tree_class::~tree_class()
{
   if (!fChain) return;
 
}

Int_t tree_class::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tree_class::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void tree_class::Init(TTree *tree,TString part)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   muon_pt = 0;
   muon_eta = 0;
   muon_phi = 0;
   muon_charge = 0;
   muon_qual = 0;
   muon_dxy = 0;
   muon_dz = 0;
   muon_edxy = 0;
   muon_edz = 0;
   muon_d0 = 0;
   muon_ed0 = 0;
   muon_vx = 0;
   muon_vy = 0;
   muon_vz = 0;
   muon_iso = 0;
   muon_global_flag = 0;
   muon_tracker_flag = 0;
   muon_standalone_flag = 0;
   muon_soft = 0;
   muon_loose = 0;
   muon_medium = 0;
   muon_tight = 0;
   jet_pt = 0;
   jet_eta = 0;
   jet_y= 0;
   jet_phi = 0;
   jet_mass=0;
   jet_cEmEF = 0;
   jet_cHEF = 0;
   jet_cHMult = 0;
   jet_cMuEF = 0;
   jet_cMult = 0;
   jet_MuEF = 0;
   jet_nEmEF = 0;
   jet_nHEF = 0;
   jet_nMult = 0;
   jet_eEF = 0;
   jet_pEF = 0;
   el_pt = 0;
   el_eta = 0;
   el_phi = 0;
   el_charge = 0;
   el_dxy = 0;
   el_dz = 0;
   el_vx = 0;
   el_vy = 0;
   el_vz = 0;
   el_mva_out = 0;
   el_mva_iso = 0;
   el_iso = 0;
   el_veto = 0;
   el_soft = 0;
   el_medium = 0;
   el_tight = 0;
   el_mva_map_value = 0;
   HLT1Obj_pt_eta_phi_charge = 0;
   HLT2Obj_pt_eta_phi_charge = 0;
   HLT3Obj_pt_eta_phi_charge = 0;
   HLT4Obj_pt_eta_phi_charge = 0;
   HLT5Obj_pt_eta_phi_charge = 0;
   HLT6Obj_pt_eta_phi_charge = 0;
   l1muon_pt = 0;
   l1muon_eta = 0;
   l1muon_phi = 0;
   l1muon_iso = 0;
   l1muon_qual = 0;
   l1jet_pt = 0;
   l1jet_eta = 0;
   l1jet_phi = 0;
   l1jet_iso = 0;
   l1jet_qual = 0;
   genpart_pt = 0;
   genpart_phi = 0;
   genpart_eta = 0;
   genpart_pdgId = 0;
   genpart_Bindex = 0;
   genpart_Daughtindex = 0;
   genpart_charge = 0;
   genpart_mother_pdgId = 0;
   genpart_mother_pt = 0;
   genpart_mother_phi = 0;
   genpart_mother_eta = 0;
   genpart_mother_Bindex = 0;
   genpart_mother_Daughtindex = 0;
   genpart_grandmother_pdgId = 0;
   genpart_grandmother_pt = 0;
   genpart_grandmother_phi = 0;
   genpart_grandmother_eta = 0;
   genpart_grandmother_Bindex = 0;
   muon_vertex_IsValid = 0;
   muon_vertex_chiSquared = 0;
   muon_vertex_DOF = 0;
   muon_vertex_x = 0;
   muon_vertex_y = 0;
   muon_vertex_z = 0;
   muon_vertex_ex = 0;
   muon_vertex_ey = 0;
   muon_vertex_ez = 0;
   muon_vertex_distPV = 0;
   muon_vertex_probability = 0;
   muon_vertex_refitPt1 = 0;
   muon_vertex_refitPt2 = 0;
   muon_DCA = 0;
   muon_trkpt = 0;
   muon_trketa = 0;
   muon_trkphi = 0;
   el_trkpt = 0;
   el_trketa = 0;
   el_trkphi = 0;
   el_vertex_IsValid = 0;
   el_vertex_chiSquared = 0;
   el_vertex_DOF = 0;
   el_vertex_x = 0;
   el_vertex_y = 0;
   el_vertex_z = 0;
   el_vertex_ex = 0;
   el_vertex_ey = 0;
   el_vertex_ez = 0;
   el_vertex_distPV = 0;
   el_vertex_probability = 0;
   el_vertex_refitPt1 = 0;
   el_vertex_refitPt2 = 0;
   track_pt = 0;
   track_eta = 0;
   track_phi = 0;
   track_norm_chi2 = 0;
   track_charge = 0;
   track_dxy = 0;
   track_dz = 0;
   track_validhits = 0;
   track_losthits = 0;
   track_validfraction = 0;
   kaon_pt = 0;
   kaon_eta = 0;
   kaon_phi = 0;
   kaon_mass = 0;
   kaon_norm_chi2 = 0;
   kaon_x = 0;
   kaon_y = 0;
   kaon_z = 0;
   kaon_trk1pt = 0;
   kaon_trk1eta = 0;
   kaon_trk1phi = 0;
   kaon_trk1charge = 0;
   kaon_trk2pt = 0;
   kaon_trk2eta = 0;
   kaon_trk2phi = 0;
   kaon_trk2charge = 0;
   vertex_x = 0;
   vertex_y = 0;
   vertex_z = 0;
   vertex_ex = 0;
   vertex_ey = 0;
   vertex_ez = 0;
   vertex_chi = 0;
   vertex_ndof = 0;
   jpsi_pt = 0;
   jpsi_eta = 0;
   jpsi_phi = 0;
   jpsi_chi2 = 0;
   jpsi_ndof = 0;
   jpsi_ctxy = 0;
   jpsi_x = 0;
   jpsi_y = 0;
   jpsi_z = 0;
   jpsi_ex = 0;
   jpsi_ey = 0;
   jpsi_ez = 0;
   jpsi_prob = 0;
   jpsi_mass = 0;
   jpsi_trk1pt = 0;
   jpsi_trk1eta = 0;
   jpsi_trk1phi = 0;
   jpsi_trk1charge = 0;
   jpsi_trk2pt = 0;
   jpsi_trk2eta = 0;
   jpsi_trk2phi = 0;
   jpsi_trk2charge = 0;
   jpsi_pf1pt = 0;
   jpsi_pf1eta = 0;
   jpsi_pf1phi = 0;
   jpsi_pf2pt = 0;
   jpsi_pf2eta = 0;
   jpsi_pf2phi = 0;
   jpsi_flavour = 0;
   jpsi_trk1ept = 0;
   jpsi_trk1eeta = 0;
   jpsi_trk1ephi = 0;
   jpsi_trk2ept = 0;
   jpsi_trk2eeta = 0;
   jpsi_trk2ephi = 0;
   jpsi_trk1pt_unfit = 0;
   jpsi_trk2pt_unfit = 0;
   jpsi_trk1ept_unfit = 0;
   jpsi_trk2ept_unfit = 0;
   jpsi_trk1eta_unfit = 0;
   jpsi_trk2eta_unfit = 0;
   jpsi_trk1eeta_unfit = 0;
   jpsi_trk2eeta_unfit = 0;
   jpsi_trk1phi_unfit = 0;
   jpsi_trk2phi_unfit = 0;
   jpsi_trk1ephi_unfit = 0;
   jpsi_trk2ephi_unfit = 0;
   jpsi_lep1id = 0;
   jpsi_lep2id = 0;
   kaon_ch_pt = 0;
   kaon_ch_eta = 0;
   kaon_ch_phi = 0;
   kaon_ch_charge = 0;
   kaon_ch_chinorm = 0;
   kaon_ch_ept = 0;
   kaon_ch_eeta = 0;
   kaon_ch_ephi = 0;
   b_pt = 0;
   b_pz = 0;
   b_eta = 0;
   b_phi = 0;
   b_charge = 0;
   b_mass = 0;
   b_chi = 0;
   b_ndof = 0;
   b_x = 0;
   b_y = 0;
   b_z = 0;
   b_ex = 0;
   b_ey = 0;
   b_ez = 0;
   b_ept = 0;
   b_eeta = 0;
   b_ephi = 0;
   NRb_pt_eta_phi = 0;
   NRb_mass = 0;
   NRb_chi_prob = 0;
   NRb_x_y_z = 0;
   NRb_ex_ey_ez = 0;
   NRb_ept_eeta_ephi = 0;
   NRb_mudecay = 0;
   NRb_Kpt_eta_phi = 0;
   NRb_charge = 0;
   NRb_l1pt_eta_phi_charge = 0;
   NRb_l2pt_eta_phi_charge = 0;
   NRb_lep1Id = 0;
   NRb_lep2Id = 0;
   NRb_mll = 0;
   NRb_ll_prob = 0;
   NRb_trk_sdxy = 0;
   D0_pt = 0;
   D0_pt_unfit = 0;
   D0_eta = 0;
   D0_phi = 0;
   D0_x = 0;
   D0_y = 0;
   D0_z = 0;
   D0_chi2 = 0;
   D0_ndof = 0;
   D0_prob = 0;
   D0_mass = 0;
   D0_IsKtrk = 0;
   D0_ctxy = 0;
   D0_trk1pt = 0;
   D0_trk1pt_unfit = 0;
   D0_trk1eta = 0;
   D0_trk1phi = 0;
   D0_trk1charge = 0;
   D0_trk2pt = 0;
   D0_trk2pt_unfit = 0;
   D0_trk2eta = 0;
   D0_trk2phi = 0;
   D0_trk2charge = 0;
   Dstar_pt = 0;
   Dstar_eta = 0;
   Dstar_phi = 0;
   Dstar_x = 0;
   Dstar_y = 0;
   Dstar_z = 0;
   Dstar_chi2 = 0;
   Dstar_ndof = 0;
   Dstar_mass = 0;
   Dstar_trk1pt = 0;
   Dstar_trk1eta = 0;
   Dstar_trk1phi = 0;
   Dstar_trk1charge = 0;
   Dstar_trk1chinorm = 0;
   Dstar_DRtrk1D0 = 0;
   Dstar_trk1error = 0;
   Dstar_Mdif = 0;
   Dstar_IsK = 0;
   DstarB_muId = 0;
   DstarB_x = 0;
   DstarB_y = 0;
   DstarB_z = 0;
   DstarB_chi2 = 0;
   DstarB_chi2prob = 0;
   DstarB_D0Id = 0;
   DstarB_DsId = 0;
   genbq_pt = 0;
   genbq_eta = 0;
   genbq_phi = 0;
   genbq_charge = 0;
   genbqhadr_pt = 0;
   genB_pdgId = 0;
   genBtoDsMu = 0;
   genBisMuDecay = 0;
   genB0_pt = 0;
   genB0_eta = 0;
   genB0_phi = 0;
   genMuBMother_pdgId = 0;

   genMuB_pt = 0;
   genMuB_eta = 0;
   genMuB_phi = 0;

   genMuC_pt = 0;
   genMuC_eta = 0;
   genMuC_phi = 0;

   genMuUDS_pt = 0;
   genMuUDS_eta = 0;
   genMuUDS_phi = 0;

   genMuBDs = 0;
   genMuBDsWithGamma = 0;
   genMuBDsGammaPt = 0;
   genMuBMother_bqId = 0;
   genMuB_bgPt = 0;
   genMuB_bqEta = 0;
   genMuB_bqPhi = 0;
   genMu_pt = 0;
   genMu_eta = 0;
   genMu_phi = 0;
   genMu_ch = 0;
   genMu_motherId = 0;
   genMu_gmotherId = 0;
   genMu_dxy = 0;
   genMu_edxy = 0;
   genB0Daughter_pt = 0;
   genB0Daughter_eta = 0;
   genB0Daughter_phi = 0;
   genB0Daughter_pdgId = 0;
   genB0Daughter_dxy = 0;
   genB0Daughter_edxy = 0;
   genDsDaughter_pt = 0;
   genDsDaughter_eta = 0;
   genDsDaughter_phi = 0;
   genDsDaughter_pdgId = 0;
   genD0Daughter_pt = 0;
   genD0Daughter_eta = 0;
   genD0Daughter_phi = 0;
   genD0Daughter_pdgId = 0;

//VB: For genJet analysis

   genJet_flavour=0;
   genJet_pt=0;
   genJet_eta=0;
   genJet_y=0;
   genJet_phi=0;
   genJet_mass=0;
   dR_cJet_matching=0;
   dR_bJet_matching=0;
   dR_lightJet_matching=0;


   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("run_number", &run_number, &b_run_number);
   fChain->SetBranchAddress("ls", &ls, &b_ls);
   fChain->SetBranchAddress("HLT_path1", &HLT_path1, &b_HLT_path1);
   fChain->SetBranchAddress("HLT_path2", &HLT_path2, &b_HLT_path2);
   fChain->SetBranchAddress("HLT_path3", &HLT_path3, &b_HLT_path3);
   fChain->SetBranchAddress("HLT_path4", &HLT_path4, &b_HLT_path4);
   fChain->SetBranchAddress("HLT_path5", &HLT_path5, &b_HLT_path5);
   fChain->SetBranchAddress("HLT_path6", &HLT_path6, &b_HLT_path6);
   fChain->SetBranchAddress("L1_seed1", &L1_seed1, &b_L1_seed1);
   fChain->SetBranchAddress("L1_seed2", &L1_seed2, &b_L1_seed2);
   fChain->SetBranchAddress("L1_seed3", &L1_seed3, &b_L1_seed3);
   fChain->SetBranchAddress("L1_seed4", &L1_seed4, &b_L1_seed4);
   fChain->SetBranchAddress("L1_seed5", &L1_seed5, &b_L1_seed5);
   fChain->SetBranchAddress("L1_seed6", &L1_seed6, &b_L1_seed6);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("nmuon", &nmuon, &b_nmuon);
   fChain->SetBranchAddress("muon_pt", &muon_pt, &b_muon_pt);
   fChain->SetBranchAddress("muon_eta", &muon_eta, &b_muon_eta);
   fChain->SetBranchAddress("muon_phi", &muon_phi, &b_muon_phi);
   fChain->SetBranchAddress("muon_charge", &muon_charge, &b_muon_charge);
   fChain->SetBranchAddress("muon_qual", &muon_qual, &b_muon_qual);
   fChain->SetBranchAddress("muon_dxy", &muon_dxy, &b_muon_dxy);
   fChain->SetBranchAddress("muon_dz", &muon_dz, &b_muon_dz);
   fChain->SetBranchAddress("muon_edxy", &muon_edxy, &b_muon_edxy);
   fChain->SetBranchAddress("muon_edz", &muon_edz, &b_muon_edz);
   fChain->SetBranchAddress("muon_d0", &muon_d0, &b_muon_d0);
   fChain->SetBranchAddress("muon_ed0", &muon_ed0, &b_muon_ed0);
   fChain->SetBranchAddress("muon_vx", &muon_vx, &b_muon_vx);
   fChain->SetBranchAddress("muon_vy", &muon_vy, &b_muon_vy);
   fChain->SetBranchAddress("muon_vz", &muon_vz, &b_muon_vz);
   fChain->SetBranchAddress("muon_iso", &muon_iso, &b_muon_iso);
   fChain->SetBranchAddress("muon_global_flag", &muon_global_flag, &b_muon_global_flag);
   fChain->SetBranchAddress("muon_tracker_flag", &muon_tracker_flag, &b_muon_tracker_flag);
   fChain->SetBranchAddress("muon_standalone_flag", &muon_standalone_flag, &b_muon_standalone_flag);
   fChain->SetBranchAddress("muon_soft", &muon_soft, &b_muon_soft);
   fChain->SetBranchAddress("muon_loose", &muon_loose, &b_muon_loose);
   fChain->SetBranchAddress("muon_medium", &muon_medium, &b_muon_medium);
   fChain->SetBranchAddress("muon_tight", &muon_tight, &b_muon_tight);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_y", &jet_y, &b_jet_y);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_mass",&jet_mass,&b_jet_mass);
   fChain->SetBranchAddress("jet_cEmEF", &jet_cEmEF, &b_jet_cEmEF);
   fChain->SetBranchAddress("jet_cHEF", &jet_cHEF, &b_jet_cHEF);
   fChain->SetBranchAddress("jet_cHMult", &jet_cHMult, &b_jet_cHMult);
   fChain->SetBranchAddress("jet_cMuEF", &jet_cMuEF, &b_jet_cMuEF);
   fChain->SetBranchAddress("jet_cMult", &jet_cMult, &b_jet_cMult);
   fChain->SetBranchAddress("jet_MuEF", &jet_MuEF, &b_jet_MuEF);
   fChain->SetBranchAddress("jet_nEmEF", &jet_nEmEF, &b_jet_nEmEF);
   fChain->SetBranchAddress("jet_nHEF", &jet_nHEF, &b_jet_nHEF);
   fChain->SetBranchAddress("jet_nMult", &jet_nMult, &b_jet_nMult);
   fChain->SetBranchAddress("jet_eEF", &jet_eEF, &b_jet_eEF);
   fChain->SetBranchAddress("jet_pEF", &jet_pEF, &b_jet_pEF);
   fChain->SetBranchAddress("njets", &njets, &b_njets);
   fChain->SetBranchAddress("nelectron", &nelectron, &b_nelectron);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_dxy", &el_dxy, &b_el_dxy);
   fChain->SetBranchAddress("el_dz", &el_dz, &b_el_dz);
   fChain->SetBranchAddress("el_vx", &el_vx, &b_el_vx);
   fChain->SetBranchAddress("el_vy", &el_vy, &b_el_vy);
   fChain->SetBranchAddress("el_vz", &el_vz, &b_el_vz);
   fChain->SetBranchAddress("el_mva_out", &el_mva_out, &b_el_mva_out);
   fChain->SetBranchAddress("el_mva_iso", &el_mva_iso, &b_el_mva_iso);
   fChain->SetBranchAddress("el_iso", &el_iso, &b_el_iso);
   fChain->SetBranchAddress("el_veto", &el_veto, &b_el_veto);
   fChain->SetBranchAddress("el_soft", &el_soft, &b_el_soft);
   fChain->SetBranchAddress("el_medium", &el_medium, &b_el_medium);
   fChain->SetBranchAddress("el_tight", &el_tight, &b_el_tight);
   fChain->SetBranchAddress("el_mva_map_value", &el_mva_map_value, &b_el_mva_map_value);
   fChain->SetBranchAddress("HLT1Obj_pt_eta_phi_charge", &HLT1Obj_pt_eta_phi_charge, &b_HLT1Obj_pt_eta_phi_charge);
   fChain->SetBranchAddress("HLT2Obj_pt_eta_phi_charge", &HLT2Obj_pt_eta_phi_charge, &b_HLT2Obj_pt_eta_phi_charge);
   fChain->SetBranchAddress("HLT3Obj_pt_eta_phi_charge", &HLT3Obj_pt_eta_phi_charge, &b_HLT3Obj_pt_eta_phi_charge);
   fChain->SetBranchAddress("HLT4Obj_pt_eta_phi_charge", &HLT4Obj_pt_eta_phi_charge, &b_HLT4Obj_pt_eta_phi_charge);
   fChain->SetBranchAddress("HLT5Obj_pt_eta_phi_charge", &HLT5Obj_pt_eta_phi_charge, &b_HLT5Obj_pt_eta_phi_charge);
   fChain->SetBranchAddress("HLT6Obj_pt_eta_phi_charge", &HLT6Obj_pt_eta_phi_charge, &b_HLT6Obj_pt_eta_phi_charge);
   fChain->SetBranchAddress("l1muon_pt", &l1muon_pt, &b_l1muon_pt);
   fChain->SetBranchAddress("l1muon_eta", &l1muon_eta, &b_l1muon_eta);
   fChain->SetBranchAddress("l1muon_phi", &l1muon_phi, &b_l1muon_phi);
   fChain->SetBranchAddress("l1muon_iso", &l1muon_iso, &b_l1muon_iso);
   fChain->SetBranchAddress("l1muon_qual", &l1muon_qual, &b_l1muon_qual);
   fChain->SetBranchAddress("l1jet_pt", &l1jet_pt, &b_l1jet_pt);
   fChain->SetBranchAddress("l1jet_eta", &l1jet_eta, &b_l1jet_eta);
   fChain->SetBranchAddress("l1jet_phi", &l1jet_phi, &b_l1jet_phi);
   fChain->SetBranchAddress("l1jet_iso", &l1jet_iso, &b_l1jet_iso);
   fChain->SetBranchAddress("l1jet_qual", &l1jet_qual, &b_l1jet_qual);
   fChain->SetBranchAddress("l1met", &l1met, &b_l1met);
   fChain->SetBranchAddress("l1met_phi", &l1met_phi, &b_l1met_phi);
   fChain->SetBranchAddress("l1ht", &l1ht, &b_l1ht);
   fChain->SetBranchAddress("l1hf_met", &l1hf_met, &b_l1hf_met);
   fChain->SetBranchAddress("l1hf_met_phi", &l1hf_met_phi, &b_l1hf_met_phi);
   fChain->SetBranchAddress("genpart_pt", &genpart_pt, &b_genpart_pt);
   fChain->SetBranchAddress("genpart_phi", &genpart_phi, &b_genpart_phi);
   fChain->SetBranchAddress("genpart_eta", &genpart_eta, &b_genpart_eta);
   fChain->SetBranchAddress("genpart_pdgId", &genpart_pdgId, &b_genpart_pdgId);
   fChain->SetBranchAddress("genpart_Bindex", &genpart_Bindex, &b_genpart_Bindex);
   fChain->SetBranchAddress("genpart_Daughtindex", &genpart_Daughtindex, &b_genpart_Daughtindex);
   fChain->SetBranchAddress("genpart_charge", &genpart_charge, &b_genpart_charge);
   fChain->SetBranchAddress("genpart_mother_pdgId", &genpart_mother_pdgId, &b_genpart_mother_pdgId);
   fChain->SetBranchAddress("genpart_mother_pt", &genpart_mother_pt, &b_genpart_mother_pt);
   fChain->SetBranchAddress("genpart_mother_phi", &genpart_mother_phi, &b_genpart_mother_phi);
   fChain->SetBranchAddress("genpart_mother_eta", &genpart_mother_eta, &b_genpart_mother_eta);
   fChain->SetBranchAddress("genpart_mother_Bindex", &genpart_mother_Bindex, &b_genpart_mother_Bindex);
   fChain->SetBranchAddress("genpart_mother_Daughtindex", &genpart_mother_Daughtindex, &b_genpart_mother_Daughtindex);
   fChain->SetBranchAddress("genpart_grandmother_pdgId", &genpart_grandmother_pdgId, &b_genpart_grandmother_pdgId);
   fChain->SetBranchAddress("genpart_grandmother_pt", &genpart_grandmother_pt, &b_genpart_grandmother_pt);
   fChain->SetBranchAddress("genpart_grandmother_phi", &genpart_grandmother_phi, &b_genpart_grandmother_phi);
   fChain->SetBranchAddress("genpart_grandmother_eta", &genpart_grandmother_eta, &b_genpart_grandmother_eta);
   fChain->SetBranchAddress("genpart_grandmother_Bindex", &genpart_grandmother_Bindex, &b_genpart_grandmother_Bindex);
   fChain->SetBranchAddress("good_vertex", &good_vertex, &b_good_vertex);
   fChain->SetBranchAddress("muon_vertex_IsValid", &muon_vertex_IsValid, &b_muon_vertex_IsValid);
   fChain->SetBranchAddress("muon_vertex_chiSquared", &muon_vertex_chiSquared, &b_muon_vertex_chiSquared);
   fChain->SetBranchAddress("muon_vertex_DOF", &muon_vertex_DOF, &b_muon_vertex_DOF);
   fChain->SetBranchAddress("muon_vertex_x", &muon_vertex_x, &b_muon_vertex_x);
   fChain->SetBranchAddress("muon_vertex_y", &muon_vertex_y, &b_muon_vertex_y);
   fChain->SetBranchAddress("muon_vertex_z", &muon_vertex_z, &b_muon_vertex_z);
   fChain->SetBranchAddress("muon_vertex_ex", &muon_vertex_ex, &b_muon_vertex_ex);
   fChain->SetBranchAddress("muon_vertex_ey", &muon_vertex_ey, &b_muon_vertex_ey);
   fChain->SetBranchAddress("muon_vertex_ez", &muon_vertex_ez, &b_muon_vertex_ez);
   fChain->SetBranchAddress("muon_vertex_distPV", &muon_vertex_distPV, &b_muon_vertex_distPV);
   fChain->SetBranchAddress("muon_vertex_probability", &muon_vertex_probability, &b_muon_vertex_probability);
   fChain->SetBranchAddress("muon_vertex_refitPt1", &muon_vertex_refitPt1, &b_muon_vertex_refitPt1);
   fChain->SetBranchAddress("muon_vertex_refitPt2", &muon_vertex_refitPt2, &b_muon_vertex_refitPt2);
   fChain->SetBranchAddress("muon_DCA", &muon_DCA, &b_muon_DCA);
   fChain->SetBranchAddress("muon_trkpt", &muon_trkpt, &b_muon_trkpt);
   fChain->SetBranchAddress("muon_trketa", &muon_trketa, &b_muon_trketa);
   fChain->SetBranchAddress("muon_trkphi", &muon_trkphi, &b_muon_trkphi);
   fChain->SetBranchAddress("el_trkpt", &el_trkpt, &b_el_trkpt);
   fChain->SetBranchAddress("el_trketa", &el_trketa, &b_el_trketa);
   fChain->SetBranchAddress("el_trkphi", &el_trkphi, &b_el_trkphi);
   fChain->SetBranchAddress("el_vertex_IsValid", &el_vertex_IsValid, &b_el_vertex_IsValid);
   fChain->SetBranchAddress("el_vertex_chiSquared", &el_vertex_chiSquared, &b_el_vertex_chiSquared);
   fChain->SetBranchAddress("el_vertex_DOF", &el_vertex_DOF, &b_el_vertex_DOF);
   fChain->SetBranchAddress("el_vertex_x", &el_vertex_x, &b_el_vertex_x);
   fChain->SetBranchAddress("el_vertex_y", &el_vertex_y, &b_el_vertex_y);
   fChain->SetBranchAddress("el_vertex_z", &el_vertex_z, &b_el_vertex_z);
   fChain->SetBranchAddress("el_vertex_ex", &el_vertex_ex, &b_el_vertex_ex);
   fChain->SetBranchAddress("el_vertex_ey", &el_vertex_ey, &b_el_vertex_ey);
   fChain->SetBranchAddress("el_vertex_ez", &el_vertex_ez, &b_el_vertex_ez);
   fChain->SetBranchAddress("el_vertex_distPV", &el_vertex_distPV, &b_el_vertex_distPV);
   fChain->SetBranchAddress("el_vertex_probability", &el_vertex_probability, &b_el_vertex_probability);
   fChain->SetBranchAddress("el_vertex_refitPt1", &el_vertex_refitPt1, &b_el_vertex_refitPt1);
   fChain->SetBranchAddress("el_vertex_refitPt2", &el_vertex_refitPt2, &b_el_vertex_refitPt2);
   fChain->SetBranchAddress("pvertex_x", &pvertex_x, &b_pvertex_x);
   fChain->SetBranchAddress("pvertex_y", &pvertex_y, &b_pvertex_y);
   fChain->SetBranchAddress("pvertex_z", &pvertex_z, &b_pvertex_z);
   fChain->SetBranchAddress("pvertex_ex", &pvertex_ex, &b_pvertex_ex);
   fChain->SetBranchAddress("pvertex_ey", &pvertex_ey, &b_pvertex_ey);
   fChain->SetBranchAddress("pvertex_ez", &pvertex_ez, &b_pvertex_ez);
   fChain->SetBranchAddress("ntracks", &ntracks, &b_ntracks);
   fChain->SetBranchAddress("track_pt", &track_pt, &b_track_pt);
   fChain->SetBranchAddress("track_eta", &track_eta, &b_track_eta);
   fChain->SetBranchAddress("track_phi", &track_phi, &b_track_phi);
   fChain->SetBranchAddress("track_norm_chi2", &track_norm_chi2, &b_track_norm_chi2);
   fChain->SetBranchAddress("track_charge", &track_charge, &b_track_charge);
   fChain->SetBranchAddress("track_dxy", &track_dxy, &b_track_dxy);
   fChain->SetBranchAddress("track_dz", &track_dz, &b_track_dz);
   fChain->SetBranchAddress("track_validhits", &track_validhits, &b_track_validhits);
   fChain->SetBranchAddress("track_losthits", &track_losthits, &b_track_losthits);
   fChain->SetBranchAddress("track_validfraction", &track_validfraction, &b_track_validfraction);
   fChain->SetBranchAddress("bit", &bit, &b_bit);
   fChain->SetBranchAddress("nkaons", &nkaons, &b_nkaons);
   fChain->SetBranchAddress("kaon_pt", &kaon_pt, &b_kaon_pt);
   fChain->SetBranchAddress("kaon_eta", &kaon_eta, &b_kaon_eta);
   fChain->SetBranchAddress("kaon_phi", &kaon_phi, &b_kaon_phi);
   fChain->SetBranchAddress("kaon_mass", &kaon_mass, &b_kaon_mass);
   fChain->SetBranchAddress("kaon_norm_chi2", &kaon_norm_chi2, &b_kaon_norm_chi2);
   fChain->SetBranchAddress("kaon_x", &kaon_x, &b_kaon_x);
   fChain->SetBranchAddress("kaon_y", &kaon_y, &b_kaon_y);
   fChain->SetBranchAddress("kaon_z", &kaon_z, &b_kaon_z);
   fChain->SetBranchAddress("kaon_trk1pt", &kaon_trk1pt, &b_kaon_trk1pt);
   fChain->SetBranchAddress("kaon_trk1eta", &kaon_trk1eta, &b_kaon_trk1eta);
   fChain->SetBranchAddress("kaon_trk1phi", &kaon_trk1phi, &b_kaon_trk1phi);
   fChain->SetBranchAddress("kaon_trk1charge", &kaon_trk1charge, &b_kaon_trk1charge);
   fChain->SetBranchAddress("kaon_trk2pt", &kaon_trk2pt, &b_kaon_trk2pt);
   fChain->SetBranchAddress("kaon_trk2eta", &kaon_trk2eta, &b_kaon_trk2eta);
   fChain->SetBranchAddress("kaon_trk2phi", &kaon_trk2phi, &b_kaon_trk2phi);
   fChain->SetBranchAddress("kaon_trk2charge", &kaon_trk2charge, &b_kaon_trk2charge);
   fChain->SetBranchAddress("beam_x", &beam_x, &b_beam_x);
   fChain->SetBranchAddress("beam_y", &beam_y, &b_beam_y);
   fChain->SetBranchAddress("beam_z", &beam_z, &b_beam_z);
   fChain->SetBranchAddress("beam_ex", &beam_ex, &b_beam_ex);
   fChain->SetBranchAddress("beam_ey", &beam_ey, &b_beam_ey);
   fChain->SetBranchAddress("beam_ez", &beam_ez, &b_beam_ez);
   fChain->SetBranchAddress("vertex_x", &vertex_x, &b_vertex_x);
   fChain->SetBranchAddress("vertex_y", &vertex_y, &b_vertex_y);
   fChain->SetBranchAddress("vertex_z", &vertex_z, &b_vertex_z);
   fChain->SetBranchAddress("vertex_ex", &vertex_ex, &b_vertex_ex);
   fChain->SetBranchAddress("vertex_ey", &vertex_ey, &b_vertex_ey);
   fChain->SetBranchAddress("vertex_ez", &vertex_ez, &b_vertex_ez);
   fChain->SetBranchAddress("vertex_chi", &vertex_chi, &b_vertex_chi);
   fChain->SetBranchAddress("vertex_ndof", &vertex_ndof, &b_vertex_ndof);
   fChain->SetBranchAddress("npv", &npv, &b_npv);
   fChain->SetBranchAddress("njpsi_mumu", &njpsi_mumu, &b_njpsi_mumu);
   fChain->SetBranchAddress("njpsi_ee", &njpsi_ee, &b_njpsi_ee);
   fChain->SetBranchAddress("jpsi_pt", &jpsi_pt, &b_jpsi_pt);
   fChain->SetBranchAddress("jpsi_eta", &jpsi_eta, &b_jpsi_eta);
   fChain->SetBranchAddress("jpsi_phi", &jpsi_phi, &b_jpsi_phi);
   fChain->SetBranchAddress("jpsi_chi2", &jpsi_chi2, &b_jpsi_chi2);
   fChain->SetBranchAddress("jpsi_ndof", &jpsi_ndof, &b_jpsi_ndof);
   fChain->SetBranchAddress("jpsi_ctxy", &jpsi_ctxy, &b_jpsi_ctxy);
   fChain->SetBranchAddress("jpsi_x", &jpsi_x, &b_jpsi_x);
   fChain->SetBranchAddress("jpsi_y", &jpsi_y, &b_jpsi_y);
   fChain->SetBranchAddress("jpsi_z", &jpsi_z, &b_jpsi_z);
   fChain->SetBranchAddress("jpsi_ex", &jpsi_ex, &b_jpsi_ex);
   fChain->SetBranchAddress("jpsi_ey", &jpsi_ey, &b_jpsi_ey);
   fChain->SetBranchAddress("jpsi_ez", &jpsi_ez, &b_jpsi_ez);
   fChain->SetBranchAddress("jpsi_prob", &jpsi_prob, &b_jpsi_prob);
   fChain->SetBranchAddress("jpsi_mass", &jpsi_mass, &b_jpsi_mass);
   fChain->SetBranchAddress("jpsi_trk1pt", &jpsi_trk1pt, &b_jpsi_trk1pt);
   fChain->SetBranchAddress("jpsi_trk1eta", &jpsi_trk1eta, &b_jpsi_trk1eta);
   fChain->SetBranchAddress("jpsi_trk1phi", &jpsi_trk1phi, &b_jpsi_trk1phi);
   fChain->SetBranchAddress("jpsi_trk1charge", &jpsi_trk1charge, &b_jpsi_trk1charge);
   fChain->SetBranchAddress("jpsi_trk2pt", &jpsi_trk2pt, &b_jpsi_trk2pt);
   fChain->SetBranchAddress("jpsi_trk2eta", &jpsi_trk2eta, &b_jpsi_trk2eta);
   fChain->SetBranchAddress("jpsi_trk2phi", &jpsi_trk2phi, &b_jpsi_trk2phi);
   fChain->SetBranchAddress("jpsi_trk2charge", &jpsi_trk2charge, &b_jpsi_trk2charge);
   fChain->SetBranchAddress("jpsi_pf1pt", &jpsi_pf1pt, &b_jpsi_pf1pt);
   fChain->SetBranchAddress("jpsi_pf1eta", &jpsi_pf1eta, &b_jpsi_pf1eta);
   fChain->SetBranchAddress("jpsi_pf1phi", &jpsi_pf1phi, &b_jpsi_pf1phi);
   fChain->SetBranchAddress("jpsi_pf2pt", &jpsi_pf2pt, &b_jpsi_pf2pt);
   fChain->SetBranchAddress("jpsi_pf2eta", &jpsi_pf2eta, &b_jpsi_pf2eta);
   fChain->SetBranchAddress("jpsi_pf2phi", &jpsi_pf2phi, &b_jpsi_pf2phi);
   fChain->SetBranchAddress("jpsi_flavour", &jpsi_flavour, &b_jpsi_flavour);
   fChain->SetBranchAddress("jpsi_trk1ept", &jpsi_trk1ept, &b_jpsi_trk1ept);
   fChain->SetBranchAddress("jpsi_trk1eeta", &jpsi_trk1eeta, &b_jpsi_trk1eeta);
   fChain->SetBranchAddress("jpsi_trk1ephi", &jpsi_trk1ephi, &b_jpsi_trk1ephi);
   fChain->SetBranchAddress("jpsi_trk2ept", &jpsi_trk2ept, &b_jpsi_trk2ept);
   fChain->SetBranchAddress("jpsi_trk2eeta", &jpsi_trk2eeta, &b_jpsi_trk2eeta);
   fChain->SetBranchAddress("jpsi_trk2ephi", &jpsi_trk2ephi, &b_jpsi_trk2ephi);
   fChain->SetBranchAddress("jpsi_trk1pt_unfit", &jpsi_trk1pt_unfit, &b_jpsi_trk1pt_unfit);
   fChain->SetBranchAddress("jpsi_trk2pt_unfit", &jpsi_trk2pt_unfit, &b_jpsi_trk2pt_unfit);
   fChain->SetBranchAddress("jpsi_trk1ept_unfit", &jpsi_trk1ept_unfit, &b_jpsi_trk1ept_unfit);
   fChain->SetBranchAddress("jpsi_trk2ept_unfit", &jpsi_trk2ept_unfit, &b_jpsi_trk2ept_unfit);
   fChain->SetBranchAddress("jpsi_trk1eta_unfit", &jpsi_trk1eta_unfit, &b_jpsi_trk1eta_unfit);
   fChain->SetBranchAddress("jpsi_trk2eta_unfit", &jpsi_trk2eta_unfit, &b_jpsi_trk2eta_unfit);
   fChain->SetBranchAddress("jpsi_trk1eeta_unfit", &jpsi_trk1eeta_unfit, &b_jpsi_trk1eeta_unfit);
   fChain->SetBranchAddress("jpsi_trk2eeta_unfit", &jpsi_trk2eeta_unfit, &b_jpsi_trk2eeta_unfit);
   fChain->SetBranchAddress("jpsi_trk1phi_unfit", &jpsi_trk1phi_unfit, &b_jpsi_trk1phi_unfit);
   fChain->SetBranchAddress("jpsi_trk2phi_unfit", &jpsi_trk2phi_unfit, &b_jpsi_trk2phi_unfit);
   fChain->SetBranchAddress("jpsi_trk1ephi_unfit", &jpsi_trk1ephi_unfit, &b_jpsi_trk1ephi_unfit);
   fChain->SetBranchAddress("jpsi_trk2ephi_unfit", &jpsi_trk2ephi_unfit, &b_jpsi_trk2ephi_unfit);
   fChain->SetBranchAddress("jpsi_lep1id", &jpsi_lep1id, &b_jpsi_lep1id);
   fChain->SetBranchAddress("jpsi_lep2id", &jpsi_lep2id, &b_jpsi_lep2id);
   fChain->SetBranchAddress("kaon_ch_pt", &kaon_ch_pt, &b_kaon_ch_pt);
   fChain->SetBranchAddress("kaon_ch_eta", &kaon_ch_eta, &b_kaon_ch_eta);
   fChain->SetBranchAddress("kaon_ch_phi", &kaon_ch_phi, &b_kaon_ch_phi);
   fChain->SetBranchAddress("kaon_ch_charge", &kaon_ch_charge, &b_kaon_ch_charge);
   fChain->SetBranchAddress("kaon_ch_chinorm", &kaon_ch_chinorm, &b_kaon_ch_chinorm);
   fChain->SetBranchAddress("kaon_ch_ept", &kaon_ch_ept, &b_kaon_ch_ept);
   fChain->SetBranchAddress("kaon_ch_eeta", &kaon_ch_eeta, &b_kaon_ch_eeta);
   fChain->SetBranchAddress("kaon_ch_ephi", &kaon_ch_ephi, &b_kaon_ch_ephi);
   fChain->SetBranchAddress("b_pt", &b_pt, &b_b_pt);
   fChain->SetBranchAddress("b_pz", &b_pz, &b_b_pz);
   fChain->SetBranchAddress("b_eta", &b_eta, &b_b_eta);
   fChain->SetBranchAddress("b_phi", &b_phi, &b_b_phi);
   fChain->SetBranchAddress("b_charge", &b_charge, &b_b_charge);
   fChain->SetBranchAddress("b_mass", &b_mass, &b_b_mass);
   fChain->SetBranchAddress("b_chi", &b_chi, &b_b_chi);
   fChain->SetBranchAddress("b_ndof", &b_ndof, &b_b_ndof);
   fChain->SetBranchAddress("b_x", &b_x, &b_b_x);
   fChain->SetBranchAddress("b_y", &b_y, &b_b_y);
   fChain->SetBranchAddress("b_z", &b_z, &b_b_z);
   fChain->SetBranchAddress("b_ex", &b_ex, &b_b_ex);
   fChain->SetBranchAddress("b_ey", &b_ey, &b_b_ey);
   fChain->SetBranchAddress("b_ez", &b_ez, &b_b_ez);
   fChain->SetBranchAddress("b_ept", &b_ept, &b_b_ept);
   fChain->SetBranchAddress("b_eeta", &b_eeta, &b_b_eeta);
   fChain->SetBranchAddress("b_ephi", &b_ephi, &b_b_ephi);
   fChain->SetBranchAddress("NRb_pt_eta_phi", &NRb_pt_eta_phi, &b_NRb_pt_eta_phi);
   fChain->SetBranchAddress("NRb_mass", &NRb_mass, &b_NRb_mass);
   fChain->SetBranchAddress("NRb_chi_prob", &NRb_chi_prob, &b_NRb_chi_prob);
   fChain->SetBranchAddress("NRb_x_y_z", &NRb_x_y_z, &b_NRb_x_y_z);
   fChain->SetBranchAddress("NRb_ex_ey_ez", &NRb_ex_ey_ez, &b_NRb_ex_ey_ez);
   fChain->SetBranchAddress("NRb_ept_eeta_ephi", &NRb_ept_eeta_ephi, &b_NRb_ept_eeta_ephi);
   fChain->SetBranchAddress("NRb_mudecay", &NRb_mudecay, &b_NRb_mudecay);
   fChain->SetBranchAddress("NRb_Kpt_eta_phi", &NRb_Kpt_eta_phi, &b_NRb_Kpt_eta_phi);
   fChain->SetBranchAddress("NRb_charge", &NRb_charge, &b_NRb_charge);
   fChain->SetBranchAddress("NRb_l1pt_eta_phi_charge", &NRb_l1pt_eta_phi_charge, &b_NRb_l1pt_eta_phi_charge);
   fChain->SetBranchAddress("NRb_l2pt_eta_phi_charge", &NRb_l2pt_eta_phi_charge, &b_NRb_l2pt_eta_phi_charge);
   fChain->SetBranchAddress("NRb_lep1Id", &NRb_lep1Id, &b_NRb_lep1Id);
   fChain->SetBranchAddress("NRb_lep2Id", &NRb_lep2Id, &b_NRb_lep2Id);
   fChain->SetBranchAddress("NRb_mll", &NRb_mll, &b_NRb_mll);
   fChain->SetBranchAddress("NRb_ll_prob", &NRb_ll_prob, &b_NRb_ll_prob);
   fChain->SetBranchAddress("NRb_trk_sdxy", &NRb_trk_sdxy, &b_NRb_trk_sdxy);
   fChain->SetBranchAddress("D0_pt", &D0_pt, &b_D0_pt);
   fChain->SetBranchAddress("D0_pt_unfit", &D0_pt_unfit, &b_D0_pt_unfit);
   fChain->SetBranchAddress("D0_eta", &D0_eta, &b_D0_eta);
   fChain->SetBranchAddress("D0_phi", &D0_phi, &b_D0_phi);
   fChain->SetBranchAddress("D0_x", &D0_x, &b_D0_x);
   fChain->SetBranchAddress("D0_y", &D0_y, &b_D0_y);
   fChain->SetBranchAddress("D0_z", &D0_z, &b_D0_z);
   fChain->SetBranchAddress("D0_chi2", &D0_chi2, &b_D0_chi2);
   fChain->SetBranchAddress("D0_ndof", &D0_ndof, &b_D0_ndof);
   fChain->SetBranchAddress("D0_prob", &D0_prob, &b_D0_prob);
   fChain->SetBranchAddress("D0_mass", &D0_mass, &b_D0_mass);
   fChain->SetBranchAddress("D0_IsKtrk", &D0_IsKtrk, &b_D0_IsKtrk);
   fChain->SetBranchAddress("D0_ctxy", &D0_ctxy, &b_D0_ctxy);
   fChain->SetBranchAddress("D0_trk1pt", &D0_trk1pt, &b_D0_trk1pt);
   fChain->SetBranchAddress("D0_trk1pt_unfit", &D0_trk1pt_unfit, &b_D0_trk1pt_unfit);
   fChain->SetBranchAddress("D0_trk1eta", &D0_trk1eta, &b_D0_trk1eta);
   fChain->SetBranchAddress("D0_trk1phi", &D0_trk1phi, &b_D0_trk1phi);
   fChain->SetBranchAddress("D0_trk1charge", &D0_trk1charge, &b_D0_trk1charge);
   fChain->SetBranchAddress("D0_trk2pt", &D0_trk2pt, &b_D0_trk2pt);
   fChain->SetBranchAddress("D0_trk2pt_unfit", &D0_trk2pt_unfit, &b_D0_trk2pt_unfit);
   fChain->SetBranchAddress("D0_trk2eta", &D0_trk2eta, &b_D0_trk2eta);
   fChain->SetBranchAddress("D0_trk2phi", &D0_trk2phi, &b_D0_trk2phi);
   fChain->SetBranchAddress("D0_trk2charge", &D0_trk2charge, &b_D0_trk2charge);
   fChain->SetBranchAddress("Dstar_pt", &Dstar_pt, &b_Dstar_pt);
   fChain->SetBranchAddress("Dstar_eta", &Dstar_eta, &b_Dstar_eta);
   fChain->SetBranchAddress("Dstar_phi", &Dstar_phi, &b_Dstar_phi);
   fChain->SetBranchAddress("Dstar_x", &Dstar_x, &b_Dstar_x);
   fChain->SetBranchAddress("Dstar_y", &Dstar_y, &b_Dstar_y);
   fChain->SetBranchAddress("Dstar_z", &Dstar_z, &b_Dstar_z);
   fChain->SetBranchAddress("Dstar_chi2", &Dstar_chi2, &b_Dstar_chi2);
   fChain->SetBranchAddress("Dstar_ndof", &Dstar_ndof, &b_Dstar_ndof);
   fChain->SetBranchAddress("Dstar_mass", &Dstar_mass, &b_Dstar_mass);
   fChain->SetBranchAddress("Dstar_trk1pt", &Dstar_trk1pt, &b_Dstar_trk1pt);
   fChain->SetBranchAddress("Dstar_trk1eta", &Dstar_trk1eta, &b_Dstar_trk1eta);
   fChain->SetBranchAddress("Dstar_trk1phi", &Dstar_trk1phi, &b_Dstar_trk1phi);
   fChain->SetBranchAddress("Dstar_trk1charge", &Dstar_trk1charge, &b_Dstar_trk1charge);
   fChain->SetBranchAddress("Dstar_trk1chinorm", &Dstar_trk1chinorm, &b_Dstar_trk1chinorm);
   fChain->SetBranchAddress("Dstar_DRtrk1D0", &Dstar_DRtrk1D0, &b_Dstar_DRtrk1D0);
   fChain->SetBranchAddress("Dstar_trk1error", &Dstar_trk1error, &b_Dstar_trk1error);
   fChain->SetBranchAddress("Dstar_Mdif", &Dstar_Mdif, &b_Dstar_Mdif);
   fChain->SetBranchAddress("Dstar_IsK", &Dstar_IsK, &b_Dstar_IsK);
   fChain->SetBranchAddress("DstarB_muId", &DstarB_muId, &b_DstarB_muId);
   fChain->SetBranchAddress("DstarB_x", &DstarB_x, &b_DstarB_x);
   fChain->SetBranchAddress("DstarB_y", &DstarB_y, &b_DstarB_y);
   fChain->SetBranchAddress("DstarB_z", &DstarB_z, &b_DstarB_z);
   fChain->SetBranchAddress("DstarB_chi2", &DstarB_chi2, &b_DstarB_chi2);
   fChain->SetBranchAddress("DstarB_chi2prob", &DstarB_chi2prob, &b_DstarB_chi2prob);
   fChain->SetBranchAddress("DstarB_D0Id", &DstarB_D0Id, &b_DstarB_D0Id);
   fChain->SetBranchAddress("DstarB_DsId", &DstarB_DsId, &b_DstarB_DsId);
   fChain->SetBranchAddress("ngenB", &ngenB, &b_ngenB);
   fChain->SetBranchAddress("genbq_pt", &genbq_pt, &b_genbq_pt);
   fChain->SetBranchAddress("genbq_eta", &genbq_eta, &b_genbq_eta);
   fChain->SetBranchAddress("genbq_phi", &genbq_phi, &b_genbq_phi);
   fChain->SetBranchAddress("genbq_charge", &genbq_charge, &b_genbq_charge);
   fChain->SetBranchAddress("genbqhadr_pt", &genbqhadr_pt, &b_genbqhadr_pt);
   fChain->SetBranchAddress("genB_pdgId", &genB_pdgId, &b_genB_pdgId);
   fChain->SetBranchAddress("genBtoDsMu", &genBtoDsMu, &b_genBtoDsMu);
   fChain->SetBranchAddress("genBisMuDecay", &genBisMuDecay, &b_genBisMuDecay);
   fChain->SetBranchAddress("genB0_pt", &genB0_pt, &b_genB0_pt);
   fChain->SetBranchAddress("genB0_eta", &genB0_eta, &b_genB0_eta);
   fChain->SetBranchAddress("genB0_phi", &genB0_phi, &b_genB0_phi);
   fChain->SetBranchAddress("genMuBMother_pdgId", &genMuBMother_pdgId, &b_genMuBMother_pdgId);

   fChain->SetBranchAddress("genMuB_pt", &genMuB_pt, &b_genMuB_pt);
   fChain->SetBranchAddress("genMuB_eta", &genMuB_eta, &b_genMuB_eta);
   fChain->SetBranchAddress("genMuB_phi", &genMuB_phi, &b_genMuB_phi);

   fChain->SetBranchAddress("genMuC_pt", &genMuC_pt, &b_genMuC_pt);
   fChain->SetBranchAddress("genMuC_eta", &genMuC_eta, &b_genMuC_eta);
   fChain->SetBranchAddress("genMuC_phi", &genMuC_phi, &b_genMuC_phi);

   fChain->SetBranchAddress("genMuUDS_pt", &genMuUDS_pt, &b_genMuUDS_pt);
   fChain->SetBranchAddress("genMuUDS_eta", &genMuUDS_eta, &b_genMuUDS_eta);
   fChain->SetBranchAddress("genMuUDS_phi", &genMuUDS_phi, &b_genMuUDS_phi);

   fChain->SetBranchAddress("genMuBDs", &genMuBDs, &b_genMuBDs);
   fChain->SetBranchAddress("genMuBDsWithGamma", &genMuBDsWithGamma, &b_genMuBDsWithGamma);
   fChain->SetBranchAddress("genMuBDsGammaPt", &genMuBDsGammaPt, &b_genMuBDsGammaPt);
   fChain->SetBranchAddress("genMuBMother_bqId", &genMuBMother_bqId, &b_genMuBMother_bqId);
   fChain->SetBranchAddress("genMuB_bgPt", &genMuB_bgPt, &b_genMuB_bgPt);
   fChain->SetBranchAddress("genMuB_bqEta", &genMuB_bqEta, &b_genMuB_bqEta);
   fChain->SetBranchAddress("genMuB_bqPhi", &genMuB_bqPhi, &b_genMuB_bqPhi);
   fChain->SetBranchAddress("genMu_pt", &genMu_pt, &b_genMu_pt);
   fChain->SetBranchAddress("genMu_eta", &genMu_eta, &b_genMu_eta);
   fChain->SetBranchAddress("genMu_phi", &genMu_phi, &b_genMu_phi);
   fChain->SetBranchAddress("genMu_ch", &genMu_ch, &b_genMu_ch);
   fChain->SetBranchAddress("genMu_motherId", &genMu_motherId, &b_genMu_motherId);
   fChain->SetBranchAddress("genMu_gmotherId", &genMu_gmotherId, &b_genMu_gmotherId);
   fChain->SetBranchAddress("genMu_dxy", &genMu_dxy, &b_genMu_dxy);
   fChain->SetBranchAddress("genMu_edxy", &genMu_edxy, &b_genMu_edxy);
   fChain->SetBranchAddress("genB0Daughter_pt", &genB0Daughter_pt, &b_genB0Daughter_pt);
   fChain->SetBranchAddress("genB0Daughter_eta", &genB0Daughter_eta, &b_genB0Daughter_eta);
   fChain->SetBranchAddress("genB0Daughter_phi", &genB0Daughter_phi, &b_genB0Daughter_phi);
   fChain->SetBranchAddress("genB0Daughter_pdgId", &genB0Daughter_pdgId, &b_genB0Daughter_pdgId);
   fChain->SetBranchAddress("genB0Daughter_dxy", &genB0Daughter_dxy, &b_genB0Daughter_dxy);
   fChain->SetBranchAddress("genB0Daughter_edxy", &genB0Daughter_edxy, &b_genB0Daughter_edxy);
   fChain->SetBranchAddress("genDsDaughter_pt", &genDsDaughter_pt, &b_genDsDaughter_pt);
   fChain->SetBranchAddress("genDsDaughter_eta", &genDsDaughter_eta, &b_genDsDaughter_eta);
   fChain->SetBranchAddress("genDsDaughter_phi", &genDsDaughter_phi, &b_genDsDaughter_phi);
   fChain->SetBranchAddress("genDsDaughter_pdgId", &genDsDaughter_pdgId, &b_genDsDaughter_pdgId);
   fChain->SetBranchAddress("genD0Daughter_pt", &genD0Daughter_pt, &b_genD0Daughter_pt);
   fChain->SetBranchAddress("genD0Daughter_eta", &genD0Daughter_eta, &b_genD0Daughter_eta);
   fChain->SetBranchAddress("genD0Daughter_phi", &genD0Daughter_phi, &b_genD0Daughter_phi);
   fChain->SetBranchAddress("genD0Daughter_pdgId", &genD0Daughter_pdgId, &b_genD0Daughter_pdgId);

//VB: For genJet analysis
   fChain->SetBranchAddress("genJet_flavour",&genJet_flavour, &b_genJet_flavour);
   fChain->SetBranchAddress("genJet_pt",&genJet_pt,&b_genJet_pt);
   fChain->SetBranchAddress("genJet_eta",&genJet_eta,&b_genJet_eta);
   fChain->SetBranchAddress("genJet_y",&genJet_y,&b_genJet_y);
   fChain->SetBranchAddress("genJet_phi",&genJet_phi,&b_genJet_phi);
   fChain->SetBranchAddress("genJet_mass",&genJet_mass,&b_genJet_mass);
   fChain->SetBranchAddress("dR_cJet_matching",&dR_cJet_matching,&b_dR_cJet_matching);
   fChain->SetBranchAddress("dR_bJet_matching",&dR_bJet_matching,&b_dR_bJet_matching);
   fChain->SetBranchAddress("dR_lightJet_matching",&dR_lightJet_matching,&b_dR_lightJet_matching);


   Notify();
   if (part.Contains("GENPART"))  fChain->SetBranchStatus("genpart_*",1);
   if (part.Contains("MUON"))  fChain->SetBranchStatus("muon_*",1);
   if (part.Contains("JET"))  fChain->SetBranchStatus("jet_*",1);
   if (part.Contains("ELECTRON"))  fChain->SetBranchStatus("el_*",1);
   if (part.Contains("ALL")) fChain->SetBranchStatus("*",1);
   if (part.Contains("NO_VERT")) fChain->SetBranchStatus("*_vertex_*",0);
   if (part.Contains("L1"))  fChain->SetBranchStatus("l1*",1);
   if (part.Contains("TRACK"))  fChain->SetBranchStatus("*track*",1);
   if (part.Contains("BMESON"))  fChain->SetBranchStatus("b_*",1);
   if (part.Contains("NRB"))  fChain->SetBranchStatus("NRb_*",1);
   if (part.Contains("JPSI"))  fChain->SetBranchStatus("jpsi_*",1);
   if (part.Contains("KAON"))  fChain->SetBranchStatus("kaon_*",1);
   if (part.Contains("D0"))  fChain->SetBranchStatus("D0_*",1);
   if (part.Contains("DSTAR"))  fChain->SetBranchStatus("Dstar_*",1);
   if (part.Contains("GENMU")) {
                                  fChain->SetBranchStatus("genMu_*",1);
                                  fChain->SetBranchStatus("genMu*",1);}
   if (part.Contains("DGEN")){
          fChain->SetBranchStatus("genB*",1);
          fChain->SetBranchStatus("genD*",1);
          fChain->SetBranchStatus("genMuB*",1);
          fChain->SetBranchStatus("ngenB",1);}
   
   if(part.Contains("GENJET")){
                 fChain->SetBranchStatus("genJet_*",1);
                 fChain->SetBranchStatus("dR_*",1);}


}

Bool_t tree_class::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tree_class::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tree_class::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tree_class_cxx
