import multiprocessing as mp

import zmq

import results_pb2

class ResultReceiver(mp.Process):

	def __init__(self, port, resultQueue):
		super(ResultReceiver, self).__init__()
		self.resultQueue = resultQueue
		self.port = port

	def run(self):

		self.context = zmq.Context()
		self.receiver = self.context.socket(zmq.PULL)
		address = "tcp://*:%i" % self.port 
		self.receiver.bind(address)

		print("Waiting for signal from ventilator")
		message = self.receiver.recv() # waits for ventilator begin signal
		print("Signal from ventilator")
		
		try:
			while True:
				self.receiveResults()

		except KeyboardInterrupt:
			print("Shutting down ResultReceiver...")
			return

	def receiveResults(self):
		
		resultsReceived = results_pb2.Results()

		print('Waiting results...')
		print(self.receiver)
		message = self.receiver.recv()
		print('Got results')
		resultsReceived.ParseFromString(message)

		self.resultQueue.put(resultsReceived)
		