import os, sys
#//--------------------------------------------------------------------------------------
def getXsec(samplename):
	(Xsec,evtnum)=(1.0,1.0)

        if 'MG_50_100'   in samplename:
                (Xsec,evtnum) = (19380000.0, 40690776)
	if 'MG_100_200'   in samplename: 
		(Xsec,evtnum) = (19380000.0, 77775408)
	if 'MG_200_300'   in samplename: 
		(Xsec,evtnum) = (1559000.0, 57721120)
	if 'MG_300_500'   in samplename: 
		(Xsec,evtnum) = (311900.0, 57191140)
	if 'MG_500_700'   in samplename: 
		(Xsec,evtnum) = (29070.0, 9188310)
	if 'MG_700_1000'   in samplename: 
		(Xsec,evtnum) = (5962.0, 45812757)
	if 'MG_1000_1500'   in samplename: 
		(Xsec,evtnum) = (1005.0, 15346629)
	if 'MG_1500_2000'   in samplename: 
		(Xsec,evtnum) = (101.8, 10598209)
	if 'MG_2000_inf'   in samplename: 
		(Xsec,evtnum) = (20.54, 5457021)
	return (Xsec,evtnum)
