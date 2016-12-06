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


resultQueue = mp.Manager().Queue()
resultReceiver = ResultReceiver(5558, resultQueue)
resultReceiver.start()

resultPlotter = ResultPlotter(resultQueue, 1)
resultPlotter.start()

resultReceiver.join()
resultPlotter.join()
