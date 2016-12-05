#!/usr/bin/python3

import sys
import math

import numpy as np

import zmq
import time 

import component_pb2
import simulationrequest_pb2
import results_pb2

import resultReader


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


s = receiver.recv()
simReturn.ParseFromString(s)

tend = time.time()
print("Total elapsed time: %d msec" % ((tend-tstart)*1000))

resultReader.plotResults(simReturn)
