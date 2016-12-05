import numpy as np
import multiprocessing as mp
import matplotlib.pyplot as plt

import results_pb2

def plotResults(results):

	plt.plot(freqFreqs, freqAmplitude)
	plt.xscale('log')
	plt.show()


	return

def parseResults(results):

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

	return freqAmplitude, freqPhase, freqFreqs, tranAmplitude, tranTime



class ResultPlotter(mp.Process):

	def __init__(self, resultQueue, updateFrequency = 1):

		self.resultQueue = resultQueue

	def run(self):

		try:
			while True:
				if self.resultQueue.qsize() > 0:
					result = self.resultQueue.get()
					freqAmplitude, freqPhase, freqFreqs, tranAmplitude, tranTime = parseResults(results)
					


		except KeyboardInterrupt:
			print("Shutting down ResultPlotter")