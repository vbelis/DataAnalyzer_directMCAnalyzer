
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
	   vector<float>  *HLT1_muon_reco_reldelta_pt;
	   vector<float>  *HLT1_muon_reco_delta_eta;
	   vector<float>  *HLT1_muon_reco_delta_phi;
	   vector<float>  *HLT1_muon_reco_deltaR;
	   vector<float>  *good_muon_pt;
	   vector<float>  *good_muon_eta;
	   vector<float>  *good_muon_phi;
	   vector<float>  *good_jet_pt;
	   vector<float>  *good_jet_eta;
	   vector<float>  *good_jet_phi;
	   vector<float>  *muon_jet_pt_ratio;
	   vector<float>  *muon_jet_deltaR;
	   vector<float>  *pt_rel;
	   vector<float>  *pt_rel_no_dif;

	   // List of branches
	   TBranch        * b_HLT1_muon_reco_reldelta_pt;
	   TBranch        * b_HLT1_muon_reco_delta_eta;    
	   TBranch        * b_HLT1_muon_reco_delta_phi;    
	   TBranch        * b_HLT1_muon_reco_deltaR;       
	   TBranch        * b_good_muon_pt;
	   TBranch        * b_good_muon_eta;
	   TBranch        * b_good_muon_phi;
	   TBranch        * b_good_jet_pt;
	   TBranch        * b_good_jet_eta;
	   TBranch        * b_good_jet_phi;
	   TBranch        * b_muon_jet_pt_ratio;
	   TBranch        * b_muon_jet_deltaR;
	   TBranch        * b_pt_rel;
	   TBranch        * b_pt_rel_no_dif;


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
	   HLT1_muon_reco_reldelta_pt=0;
	   HLT1_muon_reco_delta_eta=0;
	   HLT1_muon_reco_delta_phi=0;
	   HLT1_muon_reco_deltaR=0;
	   good_muon_pt=0;
	   good_muon_eta=0;
	   good_muon_phi=0;
	   good_jet_pt=0;
	   good_jet_eta=0;
	   good_jet_phi=0;
	   muon_jet_pt_ratio=0;
	   muon_jet_deltaR=0;
	   pt_rel=0;
	   pt_rel_no_dif=0;
	 
	  // Set branch addresses and branch pointers
	   if (!tree) return;
	   fChain = tree;
	   fCurrent = -1;
	   fChain->SetMakeClass(1);


	   fChain->SetBranchAddress("HLT1_muon_reco_reldelta_pt",&HLT1_muon_reco_reldelta_pt,&b_HLT1_muon_reco_reldelta_pt);
	   fChain->SetBranchAddress("HLT1_muon_reco_delta_eta",&HLT1_muon_reco_delta_eta,&b_HLT1_muon_reco_delta_eta);
	   fChain->SetBranchAddress("HLT1_muon_reco_delta_phi",&HLT1_muon_reco_delta_phi,&b_HLT1_muon_reco_delta_phi);
	   fChain->SetBranchAddress("HLT1_muon_reco_deltaR",&HLT1_muon_reco_deltaR,&b_HLT1_muon_reco_deltaR);
	   fChain->SetBranchAddress("good_muon_pt",&good_muon_pt,&b_good_muon_pt);
	   fChain->SetBranchAddress("good_muon_eta",&good_muon_eta,&b_good_muon_eta);
	   fChain->SetBranchAddress("good_muon_phi",&good_muon_phi,&b_good_muon_phi);
	   fChain->SetBranchAddress("good_jet_pt",&good_jet_pt,&b_good_jet_pt);
	   fChain->SetBranchAddress("good_jet_eta",&good_jet_eta,&b_good_jet_eta);
	   fChain->SetBranchAddress("good_jet_phi",&good_jet_phi,&b_good_jet_phi);
	   fChain->SetBranchAddress("muon_jet_pt_ratio",&muon_jet_pt_ratio,&b_muon_jet_pt_ratio);
	   fChain->SetBranchAddress("muon_jet_deltaR",&muon_jet_deltaR,&b_muon_jet_deltaR);
	   fChain->SetBranchAddress("pt_rel",&pt_rel,&b_pt_rel);
	   fChain->SetBranchAddress("pt_rel_no_dif",&pt_rel_no_dif,&b_pt_rel_no_dif);




	   Notify();
	   if (part.Contains("ALL"))  fChain->SetBranchStatus("*",1);


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
