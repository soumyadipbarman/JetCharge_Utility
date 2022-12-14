//S.k.Kundu 25 sep 20
#include "TFile.h"
#include "TKey.h"
#include "TMacro.h"

 

void macro_Readdir(){
TFile *infile = new TFile("../All_files/PY_CP5_170_300.root");

 int i=0; 
  TIter nextkey(gDirectory->GetListOfKeys());
  while (TKey* key = (TKey*)nextkey()){
    cout << "i: " << i ;
    ++i;
 
    TObject* obj = key->ReadObj();
    std::string name = obj->GetName();
    cout << "  dir name : " << name ;
    TClass *cl =gROOT->GetClass(key->GetClassName());
    cout << " " << key->GetClassName() ;
    
    if (key->IsFolder()) {

   cout <<"  "<< key->GetName()<< endl;
   const char* idir = key->GetName();
   const TString name = key->GetName();
   TDirectory* dir = infile->GetDirectory(idir); 
    dir->cd();
    ofstream file;
    file.open(name +".txt");

    
    TIter nextkey(gDirectory->GetListOfKeys());
    
        while (TKey* kkey = (TKey*)nextkey()){
             file << kkey->GetName()<< endl;
    
          }
	file.close();
    }
  }
}
