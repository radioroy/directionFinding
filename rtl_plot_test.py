#Roy Gross
#graphs I vs Q in a scatter plot to see the phase
import matplotlib
import matplotlib.pyplot as plt

from rtlsdr import *
#import files

sdr = RtlSdr()

# configure device
sdr.sample_rate = 1000e3
sdr.center_freq = 434.7e6
###sdr.gain = 'auto'
sdr.gain = 25
samples = sdr.read_samples(256)#sample size

fig, ax = plt.subplots()


#plt.show()
while True:
    samples = sdr.read_samples(256*1)
    print(samples[0], samples.dtype)
    iData = samples.real
    qData = samples.imag
    ax.clear()
    ax.scatter(iData,qData) # when true, plot a scatter plot if I vs Q data
    ax.plot(iData,qData)

    plt.xlim(-1,1)
    plt.ylim(-1,1)
    plt.pause(0.01) 
    #plt.draw()
    #plt.show()

    #print(sdr.get_gain())
sdr.close()

