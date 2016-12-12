#!/usr/bin/python3

import sys
import math
import copy 
import random

import numpy as np

import tkinter as tk
from tkinter import filedialog


import zmq
import time 

import component_pb2
import simulationrequest_pb2


import time 
try:
    raw_input
except NameError:
    # Python 3
    raw_input = input


# function to create random values for components for monte carlo simulation
def createMonteCarloProto(simProtocolAux):
	# requires that the tolerance is the last element in the netlist and in percentage 
	# Ex: C 2 0 1e-6 10


	changeComponent = simProtocolAux.components.add()
	
	
	mean = changeComponent.values[0]
	var = changeComponent.tolerance[0]

	tolerance = tolerance*0.01
	randomComponentValue=float(abs(np.random.normal(changeComponent.value,changeComponent.tolerance,1)))

	
	mean = changeComponent.values[0]
	var = changeComponent.tolerance[0]
	mu = []
	sigma = []


	simNewProtocol=copy.deepcopy(simProtocolAux)
	# print(simNewProtocol)

	
	# access components in protobuf
	for protoIterator in simNewProtocol.components:
		#see if the component has tolerance to create new random value
		
		checker = bool(protoIterator.tolerance)
		if checker:
			print("tolerancia: ",protoIterator.tolerance[0])
			
			print(protoIterator.componentType)
			#add value to a variable
			for valueIterator in protoIterator.values: 			
				mu = valueIterator
				# print(" mu :", mu)
			for toleranceIterator in protoIterator.tolerance:
	 			sigma = toleranceIterator
				
			# print("sigma :", sigma)

			protoIterator.values[0] = float(abs(np.random.normal(mu,mu*sigma,1)))
			# print(protoIterator)
				
	return simNewProtocol

#function to create netlist
def openNetlist(fileName):

	simReq = simulationrequest_pb2.SimulationRequest()
	with open(fileName,'r') as fileNetlist:

		for line in fileNetlist:
			
			line = line.split(' ')

			if (line[0][0] == '.'):
				simReq = parseConfigurationLine(line, simReq)
			else:
				parseComponentLine(line,simReq)

		fileNetlist.close()
	return simReq

#function to parse and fill the fields of protobuf 

def parseComponentLine(line,simReq):

	component = simReq.components.add()                                                      

	if line[0][0] == 'R':

		component.componentType = component.Resistor
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))
		component.tolerance.append(float(line[4])/100)
	
	if line[0][0] == 'C':
		component.componentType = component.Capacitor
		component.nodes.append(line[1])
		component.nodes.append(line[2])		
		component.values.append(float(line[3]))
		component.tolerance.append(float(line[4])/100)
	

	if line[0][0] == 'L':
		component.componentType = component.Inductor
		component.nodes.append(line[1])
		component.nodes.append(line[2])				
		component.values.append(float(line[3]))
		component.tolerance.append(float(line[4])/100)
		

	if line[0][0] == 'E':
		
		component.componentType = component.VoltageControlledVoltageSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])		
		component.values.append(float(line[5]))

	if line[0][0] == 'F':
		
		component.componentType = component.CurrentControlledCurrentSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])				
		component.values.append(float(line[5]))
		
	if line[0][0] == 'G':
		
		component.componentType = component.VoltageControlledCurrentSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])				
		component.values.append(float(line[5]))

	if line[0][0] == 'H':
		
		component.componentType = component.CurrentControlledVoltageSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])				
		component.values.append(float(line[5]))

	if line[0][0] == 'O':
		
		component.componentType = component.OpAmp
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])

		

	if line[0][0] == 'Q':
		
		component.componentType = component.BJT
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.values.append(float(line[4]))
		component.values.append(float(line[5]))
		component.values.append(float(line[6]))
		component.values.append(float(line[7]))
		component.values.append(float(line[8]))
		component.values.append(float(line[9]))

				
	# No montecarlo's curve implementation for this component
	if line[0][0] == 'V':
		
		component.componentType = component.VoltageSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))
		component.values.append(float(line[4]))
		
	# No montecarlo's curve implementation for this component	
	if line[0][0] == 'I':
		
		component.componentType = component.CurrentSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))
		component.values.append(float(line[4]))
		
	return simReq

def parseConfigurationLine(line, simReq):

	if line[0].upper() == '.TRAN':
		
		simReq.type = simReq.Transient
		simReq.end = float(line[1])
		simReq.step = float(line[2])
		

		return simReq


	if line[0].upper() == '.AC':
				
		simReq.type = simReq.Frequency
		points = float(line[2])
		begin = float(line[3])*2*math.pi
		end = float(line[4])*2*math.pi

		if line[1].upper() == 'DEC':
			decades = math.log10(end/begin)
			totalPoints = decades * points

		if line[1].upper() == 'OCT':

			octaves = math.log2(end/begin)
			totalPoints = octaves * points

		if line[1].upper() == 'LIN':

			totalPoints = points

		simReq.points = int(totalPoints)
		simReq.begin = begin
		simReq.end = end

		return simReq

	
	if line[0].upper() == '.PRINT':

		simReq.nodes.append(int(line[1]))

		return simReq


#function to send the message using Py0MQ
# def sendMessage(simReq):

context = zmq.Context()

# Socket to send messages on
sender = context.socket(zmq.PUSH)
sender.bind("tcp://*:5557")

# Socket with direct access to the sink: used to syncronize start of batch
sink = context.socket(zmq.PUSH)
sink.connect("tcp://localhost:5559")

root = tk.Tk()
root.withdraw()
file_path = filedialog.askopenfilename()
simProtocol = openNetlist(file_path)

print("Press Enter when the workers are ready: ")
_ = raw_input()
print("Sending tasks to workers...")

# The first message is "0" and signals start of batch

print("node %i" % (simProtocol.nodes[0]))

sink.send_string(str(simProtocol.nodes[0]))

# sendMessage(simProtocol)

try:
	simulationCount = int(sys.argv[1])
except IndexError:
	print("No number of simulations defined. Using 1 as default")
	simulationCount = 1

	
	

for index in range(simulationCount):
	# creates a new protocol with random values respecting tolerance of components
	# return the protocol to be sent 	
	# need to be tested:
	# 1. test if the new protocol has different memory space as simProtocol
	# 2. test the new random values
	# 3. add tolerance in component.proto
	# 4. changes in the worker program if necessary
	# print(simProtocol.__str__())
	print(simProtocol)

	simMonteCarloProtocol = createMonteCarloProto(simProtocol)
	print(simMonteCarloProtocol.__str__())
	
	sender.send(simMonteCarloProtocol.SerializeToString())

# Give 0MQ time to deliver
time.sleep(1)



