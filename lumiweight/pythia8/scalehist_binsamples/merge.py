from ROOT import TObject, TDirectory, TFile, TTree, TH1F, TH1D, TH1, TCanvas, TChain, TGraph, TMultiGraph, TGraphAsymmErrors, TMath, TH2D, TLorentzVector, AddressOf, gROOT, TNamed, gStyle, TF1
import ROOT as ROOT
import os
import sys, optparse
from array import array
import math
import numpy as numpy_
import sample_xsec_number as crsec

def Analyze():

	path = "../All_files/"
	outfilename= 'Outputplot.root'
	output= "$PWD/"
	outfile = TFile(output+outfilename,'RECREATE')
	filename = list()
	with open ("file.txt", "r") as myfile:
		for line in myfile:
			filename.append(line.strip())
        histname = list()
        with open ("MC_hist_name.txt", "r") as hfile:
                for line in hfile:
                        histname.append(line.strip())
        #outputDir = TDirectory("analyzeBasicPat","analyzeBasicPat");
	histarray=[]
	xbins=array( 'd' )
	for i in range(len(filename)):
		print filename[i]
		(a,b)=crsec.getXsec(filename[i])
		openf = TFile(path+filename[i], "read")
		xx=filename[i].replace(".root", "_merge")
		outfilename= xx+'_Outputplot.root'
        	output= "$PWD/"
        	outfile = TFile(output+outfilename,'RECREATE')	
	        analyzeBasicPat = outfile.mkdir("analyzeBasicPat")
                for i in range(len(histname)):
		   # print histname[i]		    
                    name = 'analyzeBasicPat/'+histname[i]
		    hist1d=openf.Get(name)
		   # print hist1d.GetName()
		    for ix in range(0,hist1d.GetNbinsX()+1):
                	xbins.append(hist1d.GetXaxis().GetBinLowEdge(ix+1))
		        #histarray.append
		        #histx= TH1F(hist1d.GetName(), hist1d.GetTitle(), hist1d.GetNbinsX(), xbins)
		    histx=hist1d.Clone()
              	    #histx.Sumw2()
		   # print 'Entries = ', histx.GetNbinsX()	
		    scalefact=(41000*a)/b
		    histx.Scale(scalefact)
		    outfile.cd()
                    analyzeBasicPat.cd();
		    histx.Write() 	
		    histarray.append(histx)

                analyzeBasicPat1D = outfile.mkdir("analyzeBasicPat1D")
                for i in range(len(histname)):
                   # print histname[i]              
                    name = 'analyzeBasicPat/'+histname[i]
                    hist1d=openf.Get(name)
                   # print hist1d.GetName()
                    for ix in range(0,hist1d.GetNbinsX()+1):
                        xbins.append(hist1d.GetXaxis().GetBinLowEdge(ix+1))
                        #histarray.append
                        #histx= TH1F(hist1d.GetName(), hist1d.GetTitle(), hist1d.GetNbinsX(), xbins)
                    histx=hist1d.Clone()
                    #histx.Sumw2()
                   # print 'Entries = ', histx.GetNbinsX()      
                    scalefact=(41000*a)/b
                    histx.Scale(scalefact)
                    outfile.cd()
                    analyzeBasicPat1D.cd();
                    histx.Write()
                    histarray.append(histx)
	        analyzeBasicPat2D = outfile.mkdir("analyzeBasicPat2D")
                for i in range(len(histname)):
                   # print histname[i]              
                    name = 'analyzeBasicPat/'+histname[i]
                    hist1d=openf.Get(name)
                   # print hist1d.GetName()
                    for ix in range(0,hist1d.GetNbinsX()+1):
                        xbins.append(hist1d.GetXaxis().GetBinLowEdge(ix+1))
                        #histarray.append
                        #histx= TH1F(hist1d.GetName(), hist1d.GetTitle(), hist1d.GetNbinsX(), xbins)
                    histx=hist1d.Clone()
                    #histx.Sumw2()
                   # print 'Entries = ', histx.GetNbinsX()      
                    scalefact=(41000*a)/b
                    histx.Scale(scalefact)
                    outfile.cd()
                    analyzeBasicPat2D.cd();
                    histx.Write()
                    histarray.append(histx)
	
	
#	histarray.Write() 	
        #outputDir.Close();
	outfile.Close()
		

if __name__ == "__main__":
	Analyze()
