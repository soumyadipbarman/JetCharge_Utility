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

void dataMC_basic_plot(){

int numplot = 20;
char Title[100];
char Xaxis[100];
char Yaxis[100];

char histname2[100];  // For monte carlo histogram reading

//Check the folder for all Monte carlo file for plots
 TH1F *MC_hist[30][20];  //maximum number of Monte carlo can be analysis in 30
 Int_t color[10] ={1,2,4,5,6,46,3,28,38,42};  // define the color for different histograms

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


           for(int ivar=0; ivar < numplot ; ivar ++){
             if(ivar==0){sprintf(histname2, "analyzeBasicPat/njets_0");};
             if(ivar==1){sprintf(histname2, "analyzeBasicPat/recojt_pt_0");};
             if(ivar==2){sprintf(histname2, "analyzeBasicPat/recojt_eta");};
             if(ivar==3){sprintf(histname2, "analyzeBasicPat/recojt_phi");};
             if(ivar==4){sprintf(histname2, "analyzeBasicPat/recojet1_pt_0");};
             if(ivar==5){sprintf(histname2, "analyzeBasicPat/recojet1_eta");};
             if(ivar==6){sprintf(histname2, "analyzeBasicPat/recojet1_phi");};
	     if(ivar==7){sprintf(histname2, "analyzeBasicPat/recojet2_pt_0");};
             if(ivar==8){sprintf(histname2, "analyzeBasicPat/recojet2_eta");};
             if(ivar==9){sprintf(histname2, "analyzeBasicPat/recojet2_phi");};
	     if(ivar==10){sprintf(histname2, "analyzeBasicPat/ncharges_0");};
             if(ivar==11){sprintf(histname2, "analyzeBasicPat/recochg_pt");};
             if(ivar==12){sprintf(histname2, "analyzeBasicPat/recochg_eta");};
	     if(ivar==13){sprintf(histname2, "analyzeBasicPat/recochg_phi");};
             if(ivar==14){sprintf(histname2, "analyzeBasicPat/recochg1_pt");};
             if(ivar==15){sprintf(histname2, "analyzeBasicPat/recochg1_eta");};
             if(ivar==16){sprintf(histname2, "analyzeBasicPat/recochg1_phi");};
             if(ivar==17){sprintf(histname2, "analyzeBasicPat/recochg2_pt");};
             if(ivar==18){sprintf(histname2, "analyzeBasicPat/recochg2_eta");};
             if(ivar==19){sprintf(histname2, "analyzeBasicPat/recochg2_phi");};
	     /*
             if(ivar==20){sprintf(histname2, "analyzeBasicPat/jetcharge1_1");};
             if(ivar==21){sprintf(histname2, "analyzeBasicPat/jetcharge1_06");};
             if(ivar==22){sprintf(histname2, "analyzeBasicPat/jetcharge1_03");};
             if(ivar==23){sprintf(histname2, "analyzeBasicPat/jetcharge2_1");};
             if(ivar==24){sprintf(histname2, "analyzeBasicPat/jetcharge2_06");};
             if(ivar==25){sprintf(histname2, "analyzeBasicPat/jetcharge2_03");};
	     if(ivar==26){sprintf(histname2, "analyzeBasicPat/jetcharge_long1_1");};
             if(ivar==27){sprintf(histname2, "analyzeBasicPat/jetcharge_long1_06");};
             if(ivar==28){sprintf(histname2, "analyzeBasicPat/jetcharge_long1_03");};
             if(ivar==29){sprintf(histname2, "analyzeBasicPat/jetcharge_long2_1");};
             if(ivar==30){sprintf(histname2, "analyzeBasicPat/jetcharge_long2_06");};
             if(ivar==31){sprintf(histname2, "analyzeBasicPat/jetcharge_long2_03");};
	     if(ivar==32){sprintf(histname2, "analyzeBasicPat/jetcharge_tran1_1");};
             if(ivar==33){sprintf(histname2, "analyzeBasicPat/jetcharge_tran1_06");};
             if(ivar==34){sprintf(histname2, "analyzeBasicPat/jetcharge_tran1_03");};
             if(ivar==35){sprintf(histname2, "analyzeBasicPat/jetcharge_tran2_1");};
             if(ivar==36){sprintf(histname2, "analyzeBasicPat/jetcharge_tran2_06");};
             if(ivar==37){sprintf(histname2, "analyzeBasicPat/jetcharge_tran2_03");};

*/

	     MC_hist[outnum][ivar]= (TH1F*) MC_root->Get(histname2);
             cout << histname2 << endl;

	     MC_hist[outnum][ivar]->Scale(1/(MC_hist[outnum][ivar]->Integral()));
	      } //end of one MCinput root file  reading
           outnum++;
         } //end of the file list2.txt
       }
     myfile.close();

   }//end of loop using output root file number


 cout <<"number of root file present in that directory = " <<outnum << endl;

 //Input root files for Data
 TFile *file1 = TFile::Open("Test_Data_2017UL_29012022.root");  // data root file


 char histname1[100];

 TH1F *datahist[20];

 for(int ivar=0; ivar < numplot ; ivar ++){
	     if(ivar==0){sprintf(histname1, "analyzeBasicPat/njets_0");};
	     if(ivar==1){sprintf(histname1, "analyzeBasicPat/recojt_pt_0");};
             if(ivar==2){sprintf(histname1, "analyzeBasicPat/recojt_eta");};
             if(ivar==3){sprintf(histname1, "analyzeBasicPat/recojt_phi");};
             if(ivar==4){sprintf(histname1, "analyzeBasicPat/recojet1_pt_0");};
             if(ivar==5){sprintf(histname1, "analyzeBasicPat/recojet1_eta");};
             if(ivar==6){sprintf(histname1, "analyzeBasicPat/recojet1_phi");};
             if(ivar==7){sprintf(histname1, "analyzeBasicPat/recojet2_pt_0");};
             if(ivar==8){sprintf(histname1, "analyzeBasicPat/recojet2_eta");};
             if(ivar==9){sprintf(histname1, "analyzeBasicPat/recojet2_phi");};
             if(ivar==10){sprintf(histname1, "analyzeBasicPat/ncharges_0");};
	     if(ivar==11){sprintf(histname1, "analyzeBasicPat/recochg_pt");};
             if(ivar==12){sprintf(histname1, "analyzeBasicPat/recochg_eta");};
             if(ivar==13){sprintf(histname1, "analyzeBasicPat/recochg_phi");};
             if(ivar==14){sprintf(histname1, "analyzeBasicPat/recochg1_pt");};
             if(ivar==15){sprintf(histname1, "analyzeBasicPat/recochg1_eta");};
             if(ivar==16){sprintf(histname1, "analyzeBasicPat/recochg1_phi");};
             if(ivar==17){sprintf(histname1, "analyzeBasicPat/recochg2_pt");};
             if(ivar==18){sprintf(histname1, "analyzeBasicPat/recochg2_eta");};
             if(ivar==19){sprintf(histname1, "analyzeBasicPat/recochg2_phi");};
	     /*
             if(ivar==20){sprintf(histname1, "analyzeBasicPat/jetcharge1_1");};
             if(ivar==21){sprintf(histname1, "analyzeBasicPat/jetcharge1_06");};
             if(ivar==22){sprintf(histname1, "analyzeBasicPat/jetcharge1_03");};
             if(ivar==23){sprintf(histname1, "analyzeBasicPat/jetcharge2_1");};
             if(ivar==24){sprintf(histname1, "analyzeBasicPat/jetcharge2_06");};
             if(ivar==25){sprintf(histname1, "analyzeBasicPat/jetcharge2_03");};
             if(ivar==26){sprintf(histname1, "analyzeBasicPat/jetcharge_long1_1");};
             if(ivar==27){sprintf(histname1, "analyzeBasicPat/jetcharge_long1_06");};
             if(ivar==28){sprintf(histname1, "analyzeBasicPat/jetcharge_long1_03");};
             if(ivar==29){sprintf(histname1, "analyzeBasicPat/jetcharge_long2_1");};
             if(ivar==30){sprintf(histname1, "analyzeBasicPat/jetcharge_long2_06");};
             if(ivar==31){sprintf(histname1, "analyzeBasicPat/jetcharge_long2_03");};
             if(ivar==32){sprintf(histname1, "analyzeBasicPat/jetcharge_tran1_1");};
             if(ivar==33){sprintf(histname1, "analyzeBasicPat/jetcharge_tran1_06");};
             if(ivar==34){sprintf(histname1, "analyzeBasicPat/jetcharge_tran1_03");};
             if(ivar==35){sprintf(histname1, "analyzeBasicPat/jetcharge_tran2_1");};
             if(ivar==36){sprintf(histname1, "analyzeBasicPat/jetcharge_tran2_06");};
             if(ivar==37){sprintf(histname1, "analyzeBasicPat/jetcharge_tran2_03");};

*/
	     datahist[ivar]= (TH1F*) file1->Get(histname1);
   	     cout << histname1 << endl;

   	     datahist[ivar]->Scale(1/(datahist[ivar]->Integral()));
 }

  //-------------------------------------------------------------------------------------------------------
 const char* var_name[20] ={ "No. of jet", "Pt of all jets (GeV/c)","#eta of all jets","#phi of all jets","Pt of leading jet (GeV/c)","#eta of leading jet","#phi of leading jet", "Pt of sub-leading jet (GeV/c)","#eta of sub-leading jet", "#phi of sub-leading jet","No. of Charged particles","Pt of all Charged particles (GeV/c)","#eta of all Charged particles", "#phi of all Charged particles","Pt of Charged particles inside leading jet (GeV/c)","#eta of Charged particles inside leading jet", "#phi of Charged particles inside leadng jet", "Pt of Charged particles inside sub-leading jet (GeV/c)","#eta of Charged particles inside sub-leading jet", "#phi of Charged particles inside sub-leadng jet"}; //, "Default jet charge of leading jet, k=1.0","Default jet charge of leading jet, k=0.6","Default jet charge of leading jet, k=0.3","Default jet charge of sub-leading jet, k=1.0","Default jet charge of sub-leading jet, k=0.6","Default jet charge of sub-leading jet, k=0.3","Longitudinal jet charge of leading jet, k=1.0","Longitudinal jet charge of leading jet, k=0.6", "Longitudinal jet charge of leading jet, k=0.3","Longitudinal jet charge of sub-leading jet, k=1.0","Longitudinal jet charge of sub-leading jet, k=0.6", "Longitudinal jet charge of sub-leading jet, k=0.3","Transverse jet charge of leading jet, k=1.0","Transverse jet charge of leading jet, k=0.6", "Transverse jet charge of leading jet, k=0.3","Transverse jet charge of sub-leading jet, k=1.0","Transverse jet charge of sub-leading jet, k=0.6", "Transverse jet charge of sub-leading jet, k=0.3"};
//const char* varlogx[26] ={"Pt of leading jet (GeV/c)", "Pt of second leading jet (GeV/c)","H_{T2} (GeV/c)","#Delta Pt of two leading jets (GeV/c)","Pt2 x sin( #Delta #phi )/Pt1","#eta of leading jet", "#eta of second leading jet", "#phi of leading jet","#Delta#phi of Jets","No. of jet","No. of Charged particles"};
//const char* varlogx[38] ={ "No. of jet", "Pt of all jets (GeV/c)","#eta of all jets","#phi of all jets","Pt of leading jet (GeV/c)","#eta of leading jet","#phi of leading jet", "Pt of sub-leading jet (GeV/c)","#eta of sub-leading jet", "#phi of sub-leading jet","No. of Charged particles","Pt of all Charged particles (GeV/c)","#eta of all Charged particles", "#phi of all Charged particles", "No. of Charged particles inside leading jet","Pt of Charged particles inside leading jet (GeV/c)","#eta of Charged particles inside leading jet", "#phi of Charged particles inside leadng jet", "No. of Charged particles inside sub-leading jet","Pt of Charged particles inside sub-leading jet (GeV/c)","#eta of Charged particles inside sub-leading jet", "#phi of Charged particles inside sub-leadng jet", "No. of particles inside leading jet", "No. of particles inside sub-leading jet", "Jet Charge of leading jet (log scale)", "Jet Charge of sub-leading jet (log scale)"};
 const char* varlogx[20] ={ "No. of jet", "Pt of all jets (GeV/c)","#eta of all jets","#phi of all jets","Pt of leading jet (GeV/c)","#eta of leading jet","#phi of leading jet", "Pt of sub-leading jet (GeV/c)","#eta of sub-leading jet", "#phi of sub-leading jet","No. of Charged particles","Pt of all Charged particles (GeV/c)","#eta of all Charged particles", "#phi of all Charged particles","Pt of Charged particles inside leading jet (GeV/c)","#eta of Charged particles inside leading jet", "#phi of Charged particles inside leadng jet", "Pt of Charged particles inside sub-leading jet (GeV/c)","#eta of Charged particles inside sub-leading jet", "#phi of Charged particles inside sub-leadng jet"};//, "Default jet charge of leading jet, k=1.0","Default jet charge of leading jet, k=0.6","Default jet charge of leading jet, k=0.3","Default jet charge of sub-leading jet, k=1.0","Default jet charge of sub-leading jet, k=0.6","Default jet charge of sub-leading jet, k=0.3","Longitudinal jet charge of leading jet, k=1.0","Longitudinal jet charge of leading jet, k=0.6", "Longitudinal jet charge of leading jet, k=0.3","Longitudinal jet charge of sub-leading jet, k=1.0","Longitudinal jet charge of sub-leading jet, k=0.6", "Longitudinal jet charge of sub-leading jet, k=0.3","Transverse jet charge of leading jet, k=1.0","Transverse jet charge of leading jet, k=0.6", "Transverse jet charge of leading jet, k=0.3","Transverse jet charge of sub-leading jet, k=1.0","Transverse jet charge of sub-leading jet, k=0.6", "Transverse jet charge of sub-leading jet, k=0.3"};
 const char* varlogy[20] ={"1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d"};//,"1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d","1/N dN/d"};

  //for(int ivar=0; ivar < 10 ; ivar ++){ // loop for variables
 TCanvas *ratio_can(int Nplot[2],float plegend[7], TH1F* data, TH1F* MC[Nplot[0]], char* lowpadx);  // define the ratio plot canvas
 TCanvas *cpt0 = new TCanvas("cpt0", "canvas", 900,1000 );

 for(int ivar=0; ivar < 20 ; ivar ++){ // loop for variables

   datahist[ivar]->SetTitleOffset(0.4);
   datahist[ivar]->SetTitleSize(0.02);
   datahist[ivar]->GetYaxis()->SetLabelSize(0.03);
   datahist[ivar]->GetXaxis()->SetLabelSize(0.03);
   datahist[ivar]->GetYaxis()->SetTitleSize(0.040);
   datahist[ivar]->GetYaxis()->SetTitleOffset(1.0);
   datahist[ivar]->GetXaxis()->SetTitleSize(0.045);
   datahist[ivar]->GetXaxis()->SetTitleOffset(0.7);
   datahist[ivar]->GetYaxis()->CenterTitle();
   datahist[ivar]->GetXaxis()->CenterTitle();
   datahist[ivar]->SetLineWidth(1);

   sprintf(Title,"%s  ",var_name[ivar] );
   sprintf(Xaxis," %s" ,varlogx[ivar]);
   sprintf(Yaxis," %s%s" ,varlogy[ivar],var_name[ivar]);
   datahist[ivar]->SetTitle(Title);
   //   datahist[ivar]->GetXaxis()->SetTitle(Xaxis);
   datahist[ivar]->GetYaxis()->SetTitle(Yaxis);
   //for(int iout =0 ; iout < outnum ; iout++){    // loop on the file number

   //define arguments for ration plot function
   TH1F *MC_input[outnum];
   // const char *MCinput_index[outnum];
   for(int iout = 0 ; iout < outnum ; iout++){
     MC_input[iout]=MC_hist[iout][ivar];
   }
   char lplot_xtitle[100];
   sprintf(lplot_xtitle, "%s",varlogx[ivar]);  //have to change
   //  float ratio_range1[2]={1.2,0.9};
  int num1[2]={outnum,1} ;
  float lpos1[7] ={.6,0.7,0.9,0.88, .033, 2.2,.20};
  cout << "variable =" << ivar << endl;
  cpt0 =(TCanvas*)(ratio_can(num1, lpos1, datahist[ivar], MC_input, lplot_xtitle));
  if(ivar==0 ){cpt0->Print("JetCharge_basic_dist.pdf(","pdf");
  }else if(ivar==19) {cpt0->Print("JetCharge_basic_dist.pdf)","pdf");
  }else{
    cpt0->Print("JetCharge_basic_dist.pdf","pdf");};

  // end of file loop
  //cpt0->Clear();
  //------------------------------------------------------------
 } // end of variable loop

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
  char ratioXaxis1[100];
  char MCindex[100];
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
  if(Nplot[1]==1){gPad->SetLogy();} //condition for log scale
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
  const char* legendN[22] ={"Pythia8_Bin","Madgraph","Herwig7","Pythia8_Flat ","PY8 CUET PU HLT true","Herwig CUET","#alpha_{s} -10%","#alpha_{s} -8%","#alpha_{s} -6%","#alpha_{s} -4%","#alpha_{s} -2%","Monash tune","#alpha_{s} +2%","#alpha_{s} +4%","#alpha_{s} +6%","#alpha_{s} +8%","#alpha_{s} +10%","#alpha_{s} +12%","#alpha_{s} +14%","#alpha_{s} +16%","#alpha_{s} +18%","#alpha_{s} +20%"};
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


