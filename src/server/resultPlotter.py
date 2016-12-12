import numpy as np
import multiprocessing as mp
import matplotlib.pyplot as plt
import time

import results_pb2

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

	def __init__(self, resultQueue, updateFrequency = 5):

		super().__init__()

		self.updatePeriod = 1/updateFrequency

		self.resultQueue = resultQueue
		self.freqFig = plt.figure()
		self.freqAx = self.freqFig.gca()
		self.freqFig.show()

		self.timeLastPlot = 0

		self.freqAx.set_xscale('log')

	def run(self):

		try:
			while True:
				if self.resultQueue.qsize() > 0:
					result = self.resultQueue.get()
					freqAmplitude, freqPhase, freqFreqs, tranAmplitude, tranTime = parseResults(result)
					print(freqFreqs)
					print(freqAmplitude)
					self.freqAx.plot(freqFreqs, freqAmplitude)

				
				currentTime = time.time()

				if ( (currentTime - self.timeLastPlot) > self.updatePeriod):
					
					self.timeLastPlot = currentTime
					self.freqFig.canvas.draw()


		except KeyboardInterrupt:
			self.freqFig.close()
			print("Shutting down ResultPlotter")