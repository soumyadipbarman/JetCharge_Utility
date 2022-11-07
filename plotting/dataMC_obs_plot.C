// dataMC_dist_plot.C

//Read the Data root file and the MC root file and plot them 
//author : S. Barman

#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"
#include "TRandom.h"
#include "TAxis.h"
#include "TMath.h"
#include "TGraph.h"
#include "TObject.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <TH2F.h>
#include <TTree.h>
#include "TVector.h"
#include <vector>
#include <TF1.h>
#include <TProfile.h>
#include <TStyle.h>
#include "TPostScript.h"

void dataMC_obs_plot(){

int numplot = 18;
char Title[800];
char Xaxis[800];
char Yaxis[800];

char histname2[400];  // For monte carlo histogram reading

 //Check the folder for all Monte carlo file for plots
 TH1F *MC_hist[30][4][3][11][11];  //maximum number of Monte carlo can be analysis in 30
 //TH1F *MC_hist[30][18];
 Int_t color[10] ={1,2,4,5,6,46,3,28,38,42};  // define the color for different histograms
 Int_t PTrange[11]={92,119,185,251,319,388,467,518,579,669,3000};
 //--------------------------------------------------------------------------------------
 Int_t outnum =0;
 char line[256];
 ifstream myfile ("MC_list.txt");
 if (myfile.is_open())
   {
     while (myfile)
       {                                                     //Start the loop using output number
         myfile.getline(line,256);
         if  (line[0] != '\0') {
           cout << "Root file name = "<< line << endl;
           TFile *MC_root = TFile::Open(line);

	for(int id=1; id<4; id++){
		for (int ij=1; ij<3; ij++){
			for (int ik=1; ik<11; ik++){
				for(int ipt=0; ipt<10; ipt++){
             
	     	sprintf(histname2, "analyzeBasicPat/reco_jetcharge_D%i_j%i_k%i_pt%i_eta0", id, ij, ik, ipt); //reco_jetcharge_D1_j1_k1_pt0_eta0

	     	MC_hist[outnum][id][ij][ik][ipt]= (TH1F*) MC_root->Get(histname2);
             	cout << histname2 << endl;

	     	MC_hist[outnum][id][ij][ik][ipt]->Scale(1/(MC_hist[outnum][id][ij][ik][ipt]->Integral()));
				}
			   }
		}
	      } //end of one MCinput root file  reading
           outnum++;
         } //end of the file list2.txt
       }
     myfile.close();

   }//end of loop using output root file number


 cout <<"number of root file present in that directory = " <<outnum << endl;

 //Input root files for Data
 TFile *file1 = TFile::Open("Test_Data_2017UL_29012022.root");  // data root file

 char histname1[400];
 TH1F *datahist[4][3][11][11];

	for (int id=1; id<4; id++){ 
	       for (int ij=1; ij<3; ij++){
                        for (int ik=1; ik<11; ik++){
                                for(int ipt=0; ipt<10; ipt++){

                sprintf(histname1, "analyzeBasicPat/reco_jetcharge_D%i_j%i_k%i_pt%i_eta0", id, ij, ik, ipt); //reco_jetcharge_j1_k01_pt0_eta0

         	datahist[id][ij][ik][ipt]= (TH1F*) file1->Get(histname1);
   	        cout << histname1 << endl;

   	        datahist[id][ij][ik][ipt]->Scale(1/(datahist[id][ij][ik][ipt]->Integral()));
				}
			}
 		}
	}
  //-------------------------------------------------------------------------------------------------------
/*
const char* varlogy[60] = {"1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d"};
*/
const char* obs_def[4]={"Test","Q","Q_{L}","Q_{T}"};
const char* jet_num[3]={"Test","Leading-Jet","Sub-Leading-Jet"};
const char* k_fact[11]={"k=0.0","k=0.1","k=0.2","k=0.3","k=0.4","k=0.5","k=0.6","k=0.7","k=0.8","k=0.9","k=1.0"};
const char* ptrange[10]={"92 < P_{T} < 119", "119 < P_{T} < 185", "185 < P_{T} < 251", "251 < P_{T} < 319", "319 < P_{T} < 388","388 < P_{T} < 467", "467 < P_{T} < 518", "518 < P_{T} < 579", "579 < P_{T} < 669", "P_{T} > 669"};
const char* obs_logy[10]={"1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d"};
 
 //for(int ivar=0; ivar < 10 ; ivar ++){ // loop for variables
 TCanvas *ratio_can(int Nplot[2],float plegend[7], TH1F* data, TH1F* MC[Nplot[0]], char* lowpadx);  // define the ratio plot canvas
 TCanvas *cpt0 = new TCanvas("cpt0", "canvas", 900,1000 );
 cout <<"Test 1"<<endl;
 //for(int ivar=0; ivar < 200 ; ivar ++){ // loop for variables
 for(int id=1; id<4; id++){
   for (int ij=1; ij<3; ij++){
   	for (int ik=1; ik<11; ik++){
        	for(int ipt=0; ipt<10; ipt++){

   datahist[id][ij][ik][ipt]->SetTitleOffset(0.4);
   datahist[id][ij][ik][ipt]->SetTitleSize(0.02);
   datahist[id][ij][ik][ipt]->GetYaxis()->SetLabelSize(0.03);
   datahist[id][ij][ik][ipt]->GetXaxis()->SetLabelSize(0.03);
   datahist[id][ij][ik][ipt]->GetYaxis()->SetTitleSize(0.040);
   datahist[id][ij][ik][ipt]->GetYaxis()->SetTitleOffset(1.0);
   datahist[id][ij][ik][ipt]->GetXaxis()->SetTitleSize(0.045);
   datahist[id][ij][ik][ipt]->GetXaxis()->SetTitleOffset(0.7);
   datahist[id][ij][ik][ipt]->GetYaxis()->CenterTitle();
   datahist[id][ij][ik][ipt]->GetXaxis()->CenterTitle();
   datahist[id][ij][ik][ipt]->SetLineWidth(1);

   //sprintf(Title," %s %s" ,jet_num[ij],obs_def[id]);
   //sprintf(Xaxis," %s %s" ,jet_num[ij],obs_def[id]);
   sprintf(Yaxis," %s %s^{%s}" ,obs_logy[ipt],obs_def[id],k_fact[ik]);
   //datahist[id][ij][ik][ipt]->SetTitle(Title);
   //datahist[id][ij][ik][ipt]->GetXaxis()->SetTitle(Xaxis);
   datahist[id][ij][ik][ipt]->GetYaxis()->SetTitle(Yaxis);
   //for(int iout =0 ; iout < outnum ; iout++){    // loop on the file number

   //define arguments for ratio plot function
   TH1F *MC_input[outnum];
   //const char *MCinput_index[outnum];
   for(int iout = 0 ; iout < outnum ; iout++){
     MC_input[iout]=MC_hist[iout][id][ij][ik][ipt];
   }
   char lplot_xtitle[800];
   sprintf(lplot_xtitle," %s %s^{%s} %s" ,jet_num[ij],obs_def[id],k_fact[ik],ptrange[ipt]);  //have to change
   //float ratio_range1[2]={1.2,0.9};
  int num1[2]={outnum,1} ;
  float lpos1[7] ={.6,0.7,0.9,0.88, .033, 2.2,.20};
  //cout << "variable =" << ivar << endl;
  cpt0 =(TCanvas*)(ratio_can(num1, lpos1, datahist[id][ij][ik][ipt], MC_input, lplot_xtitle));
  if(id==1 && ij==1 && ik==1 && ipt==0 ){cpt0->Print("JetCharge_observables_dist.pdf(","pdf");}
  else if(id ==3 && ij==2 && ik==10 && ipt==9) {cpt0->Print("JetCharge_observables_dist.pdf)","pdf");}
  else{cpt0->Print("JetCharge_observables_dist.pdf","pdf");};
  //cpt0->Print("JetCharge_observables_dist.pdf","pdf");
  // end of file loop
  //cpt0->Clear();
  //------------------------------------------------------------
 			} // end of variable loop
		}
	}
   }
 } // end of main program

 //Ratio plot function
TCanvas *ratio_can(int Nplot[2],float plegend[7], TH1F* data, TH1F* MC[Nplot[0]], char* lowpadx){
  //Nplot[0] = number of MC enetered
  //Nplot[1] = place 1 if upper part is log scale needed
  //plegend[0->3] = x1,y1,x2,y2 of the legend of the upper plot
  //plegend[4]= text size
  //plegend[5-6]= ratio plot axis range
  //data = data histogram
  // MC = monte carlo histogram array
  //legendN = name of the legends for mC one by one
  //lowpadx = x axis title of the ratio plot

  TCanvas *canvas =new TCanvas("cptfun", "canvas_fun", 900,1000 );
  canvas->cd();
  char ratioXaxis1[800];
  char MCindex[800];
  //float ymax;
  // canvas->SetBottomMargin(0.1);
  data->GetYaxis()->SetLabelSize(0.03);
  data->GetXaxis()->SetLabelSize(0.03);
  data->GetYaxis()->SetTitleSize(0.045);
  data->GetYaxis()->SetTitleOffset(1.0);
  data->GetXaxis()->SetTitleSize(0.055);
  data->GetXaxis()->SetTitleOffset(0.12);
  data->GetYaxis()->CenterTitle();
  data->GetXaxis()->CenterTitle();
  data->SetLineWidth(2);
  data->SetMarkerStyle(8);
  data->SetMarkerSize(1);
  data->SetTitle("");
  //    ymax = data->GetMaximum();

  TPad *padfun1 = new TPad("padfun1", "padfun1", 0, 0.35, 1.0, 1.0);
  padfun1->SetBottomMargin(0.01); // Upper and lower plot are joined
  padfun1->SetTopMargin(0.1); // Upper and lowd
  padfun1->Draw();             // Draw the upper pad: pad1
  padfun1->cd();
  data->Draw(" ");
  //if(Nplot[1]==1){gPad->SetLogy();} //condition for log scale
  gStyle->SetOptStat(0);
  gPad->SetTickx();
  gPad->SetTicky();
  gPad->SetTopMargin(0.01);
  gPad->SetRightMargin(0.03);
  gPad->SetLeftMargin(0.1);

int  color[22] = {2,6,4,8,46,49,1,41,42,30,46,28,29,38,30,12,37,49,9,32,9,9};
  int   style[22]={1,1,1,1,5,6,7,8,9,9,2,3,4,5,6,7,8,9,9,9,9,9};
  for(int iup =0; iup < Nplot[0] ; iup++){
    MC[iup]->SetLineStyle(style[iup]);
    MC[iup]->SetLineColor(color[iup]);
    MC[iup]->SetLineWidth(2);
    MC[iup]->Draw("same hist");// gPad->SetLogy();
    //  if(fabs(MC[iup]->GetMaximum())>fabs(ymax)){ymax =MC[iup]->GetMaximum();}
    //  MC[iup]->SetMaximum(ymax);
  }
  //  data->Draw("same");
  // TLegend *legendn = new TLegend(.4,0.20,0.62,0.35);
  TLegend *legendn = new TLegend(plegend[0],plegend[1],plegend[2],plegend[3]);
  legendn->SetFillStyle(0);
  legendn->SetBorderSize(0);
  legendn->SetTextSize(plegend[4]);
  legendn->AddEntry(data, "Data 2017","lp");
  const char* legendN[22] ={"Pythia8_Bin","Madgraph","Herwig7","Pythia8_Flat","PY8 CUET PU HLT true","Herwig CUET","#alpha_{s} -10%","#alpha_{s} -8%","#alpha_{s} -6%","#alpha_{s} -4%","#alpha_{s} -2%","Monash tune","#alpha_{s} +2%","#alpha_{s} +4%","#alpha_{s} +6%","#alpha_{s} +8%","#alpha_{s} +10%","#alpha_{s} +12%","#alpha_{s} +14%","#alpha_{s} +16%","#alpha_{s} +18%","#alpha_{s} +20%"};
  for(int iup =0 ; iup <  Nplot[0] ; iup++){
    sprintf(MCindex,"%s" ,legendN[iup]);
    legendn->AddEntry(MC[iup], MCindex ,"lp");
  }
  legendn->Draw();
  canvas->cd();          // Go back to the main canvas before defining pad2
  TPad *padfun2 = new TPad("padfun2", "padfun2", 0, 0.1,1.0, 0.35);
  padfun2->SetTopMargin(0);
  padfun2->SetBottomMargin(.35);
  padfun2->SetGridy(); // Horizontal grid
  padfun2->Draw();
  padfun2->cd();
  gPad->SetTickx();
  gPad->SetTicky();
  gPad->SetRightMargin(0.03);
  //   gStyle->SetErrorX(0.5);
  for(int ilow =0 ; ilow <  Nplot[0] ; ilow++){  //loop for ratio plot
    TH1F *rh2;
    if(data->GetBinContent(1) >= 0){
      rh2 = (TH1F*)MC[ilow]->Clone("rh2");
      // rh2->Sumw2();
      rh2->Divide(data);     //MC devide by data
    }else{
      rh2 = (TH1F*)data->Clone("rh2");
      //   rh2->Sumw2();
      rh2->SetLineColor(MC[ilow]->GetLineColor());
      rh2->SetLineWidth(MC[ilow]->GetLineWidth());
      rh2->SetLineStyle(MC[ilow]->GetLineStyle());
      rh2->Divide(MC[ilow]);
    }

    rh2->SetTitle("");
    // rh2->SetLineColor(kBlack);
    // rh2->SetMaximum(lowYrange[0]);  // .. range
    // rh2->SetMinimum(lowYrange[1]);  // Define Y ..
    // cout << "max = " << plegend[5] << "  min = " << plegend[6] << endl;
    rh2->SetMinimum(plegend[6]);  // Define Y ..
    rh2->SetMaximum(plegend[5]);  // .. range
    rh2->SetStats(0);      // No statistics on lower plot
    // rh2->Divide(data);     //MC devide by data
    // rh2->SetMarkerStyle(21);
    rh2->Draw("hist same");
    rh2->GetXaxis()->SetTitleSize(0.13);
    //  rh2->GetXaxis()->SetTitleFont(43);
    rh2->GetXaxis()->SetTitleOffset(1.15);
    rh2->GetXaxis()->SetLabelSize(0.1);
    rh2->GetXaxis()->CenterTitle();
    sprintf(ratioXaxis1," %s" ,lowpadx);
    rh2->GetXaxis()->SetTitle(ratioXaxis1);

    rh2->GetYaxis()->SetTitle("MC/Data");
    rh2->GetYaxis()->CenterTitle();
    rh2->GetYaxis()->SetNdivisions(505);
    rh2->GetYaxis()->SetTitleSize(0.12);
    //  rh2->GetYaxis()->SetTitleFont(3);
    rh2->GetYaxis()->SetTitleOffset(0.35);
    //  rh2->GetYaxis()->SetLabelFont(1.0); // Absolute font size in pixel (precision 3)
    rh2->GetYaxis()->SetLabelSize(0.09);
  }
  canvas->Update();
  return canvas;
}//end of  ratio plot function


