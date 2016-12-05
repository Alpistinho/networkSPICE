import numpy as np
import matplotlib.pyplot as plt

import results_pb2

def plotResults(results):

	freqAmplitude = []
	freqPhase = []
	freqFreqs = []

	tranAmplitude = []
	tranTime = []
	
	for freqPoint in results.frequencyPoint:

		freqAmplitude.append(freqPoint.magnitude[0])
		freqPhase.append(freqPoint.phase[0])
		freqFreqs.append(freqPoint.frequency)

	for tranPoint in results.transientPoint:

		tranAmplitude.append(tranPoint.magnitude[0])
		tranTime.append(tranPoint.time)

	
	freqAmplitude = np.array(freqAmplitude)
	freqPhase = np.array(freqPhase)
	freqFreqs = np.array(freqFreqs)

	tranAmplitude = np.array(tranAmplitude)
	tranTime = np.array(tranTime)

	

	plt.plot(freqFreqs, freqAmplitude)
	plt.xscale('log')
	plt.show()


	return