#Roy Gross
#graphs phase difference in horizontal/verticle graph

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
from scipy.signal import medfilt

from rtlsdr import *

sdr = RtlSdr()

# configure device
sdr.sample_rate = 250e3
sdr.center_freq = 434.7e6
#sdr.center_freq = 99.7
sdr.gain = 20
#sdr.gain = 4
sampleSize = 20*1024;
#568
#samples = sdr.read_samples(256)

fig, ax = plt.subplots()


#plt.show()
while True:
    samples = sdr.read_samples(sampleSize)

    #270 340 500
    
    print(samples[0], samples.dtype)
    iData = samples.real
    qData = samples.imag

    Phase = np.arctan2(iData,qData)
    #print(Phase.shape)

    deltaPhase = Phase[0:sampleSize - 2] - Phase[2:sampleSize]
    #subtracting values 2 steps away(to compensate for samples taken mid-shift)

    deltaPhase = np.remainder(deltaPhase+np.pi, 2*np.pi)-np.pi
    #remander funct (like modulo)
    
    #deltaPhase = deltaPhase - medfilt(deltaPhase,(7))
    deltaPhase = (deltaPhase*180/np.pi )
    
    ax.clear()
    #ax.scatter(iData,qData)
    ax.plot(deltaPhase)

    #plt.xlim(-1.1,1.1)
    plt.ylim(-200,200)
    plt.pause(0.01) 
    #plt.draw()
    #plt.show()

    #print(sdr.get_gains())
sdr.close()

