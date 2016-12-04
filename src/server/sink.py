#!/usr/bin/python3

import sys
import math

import zmq
import time 

import component_pb2
import simulationrequest_pb2
import results_pb2


context = zmq.Context()

# Socket to receive messages on
receiver = context.socket(zmq.PULL)
receiver.bind("tcp://*:5558")

# array of frequency and transient points
simReturn=results_pb2.Results()

# Wait for start of batch
s = receiver.recv()
print("olar")

# Start our clock now
tstart = time.time()

simReturn.ParseFromString(receiver.recv())
print(simReturn.__str__())

print("Total elapsed time: %d msec" % ((tend-tstart)*1000))
tend = time.time()