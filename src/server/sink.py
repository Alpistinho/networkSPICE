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

from resultReceiver import ResultReceiver
from resultPlotter import ResultPlotter


context = zmq.Context()

# Socket to receive messages on
receiver = context.socket(zmq.PULL)
receiver.bind("tcp://*:5558")

# array of frequency and transient points
simReturn = results_pb2.Results()

# Wait for start of batch
s = receiver.recv()

print("Signal from ventilator: " + str(s))


# Start our clock now
tstart = time.time()


resultQueue = mp.Manager().Queue()
resultReceiver = ResultReceiver(5558, resultQueue)
resultReceiver.start()


simReturn.ParseFromString(receiver.recv())
print(simReturn.__str__())

s = receiver.recv()
simReturn.ParseFromString(s)

resultPlotter = ResultPlotter(resultQueue, 1)
resultPlotter.start()


resultReceiver.join()
resultPlotter.join()
