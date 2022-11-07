//void pileup()
void pileupweight()
{
//Macro for HLT Path PU 
static const int nHT=10;
Int_t trgthes[nHT]={60,80,140,200,260,320,400,450,500,550};
char rootfile[100];
TFile* Datapu[nHT];
for(int i=0; i< nHT ; i++){

sprintf(rootfile, "HLT_Histogram_%i.root",trgthes[i]);
Datapu[i]= new TFile(rootfile);
}

//TFile *filedata = new TFile("2017_ReReco_13TeV_v1.root");
TFile *filemc = new TFile("PileupMC.root");

  TCanvas *cpt0 = new TCanvas("cpt0", "canvas", 1000,1000 );  //for ESVs


ofstream myfile;
myfile.open ("HLT_path_PU_entries.txt");
myfile << "PU bin entries per bin f0r each HLT path \n";

for(int i=0; i< nHT ; i++){

cpt0->cd();

char histname[100];
sprintf(histname,"pileup");
TH1F* piledata=(TH1F*) Datapu[i]->Get(histname);
double xx=piledata->Integral();
piledata->Scale(1/xx);

sprintf(histname,"input_Event/N_TrueInteractions");
TH1F* pilemc=(TH1F*) filemc->Get(histname);
pilemc->Scale(1/pilemc->Integral());
piledata->Draw();
pilemc->SetLineColor(2);
pilemc->Draw("same");
TLegend *tleg = new TLegend(0.6,0.2,0.75,0.3);
  
  tleg->SetFillStyle(0);
  tleg->SetFillColor(10);
  tleg->SetTextSize(0.025);
  tleg->SetBorderSize(0);
  tleg->SetTextFont(42);
  sprintf(rootfile, "HLT_PFJet_%i",trgthes[i]);
  tleg->AddEntry(piledata, rootfile,"l");
  tleg->AddEntry(pilemc, "Pile-Up-MC","l");
  tleg->Draw();

  if(i==0){cpt0->Print("HLT_PU.pdf(","pdf");
   }else if(i==9) {cpt0->Print("HLT_PU.pdf)","pdf");
   }else{
     cpt0->Print("HLT_PU.pdf","pdf");}

//cpt0->Clear();

cout << "Data HT : " << trgthes[i] << endl;
myfile << "Data HT : " << trgthes[i] << endl;
int nbins=piledata->GetNbinsX();
int pp=0;
for( int ii = 1; ii < nbins ; ii++){

cout << piledata->GetBinContent(ii) <<", ";
myfile << piledata->GetBinContent(ii) <<", ";
pp++;
}
myfile << "\n" ;
cout << endl;
cout << " No of entries " << pp <<endl;

if(i==9){
int nbins=piledata->GetNbinsX();
 cout << " No. of Bins " << nbins ;
 myfile << " No. of Bins " << nbins ;
cout << " For MC " << endl;
myfile << " For MC " << endl;
for( int ij = 1; ij < nbins ; ij++){
cout << pilemc->GetBinContent(ij) <<", ";
myfile << pilemc->GetBinContent(ij) <<", ";
 }
}


}


myfile.close();

}


