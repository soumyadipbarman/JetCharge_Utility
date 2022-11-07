import os, sys
#//--------------------------------------------------------------------------------------
def getXsec(samplename):
	(Xsec,evtnum)=(1.0,1.0)

        if 'PY_CP5_15_30'   in samplename:
                (Xsec,evtnum) = (1246000000.0, 19997400)
	if 'PY_CP5_30_50'   in samplename: 
		(Xsec,evtnum) = (106900000.0, 19082200)
	if 'PY_CP5_50_80'   in samplename: 
		(Xsec,evtnum) = (15710000.0, 19989400)
	if 'PY_CP5_80_120'   in samplename: 
		(Xsec,evtnum) = (2336000.0, 29640900)
	if 'PY_CP5_120_170'   in samplename: 
		(Xsec,evtnum) = (407300.0, 29951400)
	if 'PY_CP5_170_300'   in samplename: 
		(Xsec,evtnum) = (103500.0, 29522100)
	if 'PY_CP5_300_470'   in samplename: 
		(Xsec,evtnum) = (6830.0, 57365500)
	if 'PY_CP5_470_600'   in samplename: 
		(Xsec,evtnum) = (552.1, 27559600)
	if 'PY_CP5_600_800'   in samplename: 
		(Xsec,evtnum) = (156.5, 65128700)
	if 'PY_CP5_800_1000'   in samplename: 
		(Xsec,evtnum) = (26.28, 39261600)
	if 'PY_CP5_1000_1400'   in samplename: 
		(Xsec,evtnum) = (7.47, 19967700)
	if 'PY_CP5_1400_1800'   in samplename: 
		(Xsec,evtnum) = (0.6484, 5434800)
	if 'PY_CP5_1800_2400'   in samplename: 
		(Xsec,evtnum) = (0.08743, 2999700)
	if 'PY_CP5_2400_3200'   in samplename: 
		(Xsec,evtnum) = (0.005236, 1919400)
	if 'PY_CP5_3200_inf'   in samplename: 
		(Xsec,evtnum) = (0.0001357, 800000)
	return (Xsec,evtnum)
