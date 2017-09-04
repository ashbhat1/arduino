import pandas as pd
import numpy as np
import sys
fname = sys.argv[1]
infname = sys.argv[2]
analysisflag = sys.argv[3]
if analysisflag=='0':
    f = open(infname,'r')
    readout = f.readline()
    readout = readout.split('\n')[0]
    readout = readout.split(" ")
elif analysisflag=='1':
    readout = pd.read_csv(infname,delimiter='\n',header=None)[0].values.tolist()
else:
    sys.exit();
readout = np.array(['0x'+x for x in readout])
specialchars = np.array(['D','E','S','F','t','u','d','a','p','A'])
specialhex = [hex(ord(x)) for x in specialchars]
binlist = np.array([format(int(x,16),'08b') for x in readout])
for idx,hexOI in enumerate(specialhex):
    locs = np.where(readout==hexOI)[0]
    if len(locs)>0:
        binlist[locs]=specialchars[idx]
df=pd.DataFrame()
df['hexval']=readout
df['binval']=binlist
df.to_csv(fname+'.csv',header=None,index=None,sep='\t')

