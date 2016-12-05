#!/usr/bin/python3

import sys
import math

import numpy as np
import multiprocessing as mp

import zmq
import time 

import component_pb2
import simulationrequest_pb2
import results_pb2

import resultReader
from resultReceiver import ResultReceiver


resultQueue = mp.Manager().Queue()
resultReceiver = ResultReceiver(5558, resultQueue)
resultReceiver.start()

# Start our clock now
tstart = time.time()


while resultQueue.qsize() == 0:
	time.sleep(0.5)

print("here")
result = resultQueue.get()


tend = time.time()
print("Total elapsed time: %d msec" % ((tend-tstart)*1000))

resultReader.plotResults(result)
resultReceiver.join()
