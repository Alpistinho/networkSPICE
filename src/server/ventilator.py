#!/usr/bin/python3

import sys
import math
import zmq
import time 

import component_pb2
import simulationrequest_pb2


try:
    raw_input
except NameError:
    # Python 3
    raw_input = input

#function to create netlist
def openNetlist(fileName):

	simReq = simulationrequest_pb2.SimulationRequest()
	with open(fileName,'r') as fileNetlist:

		for line in fileNetlist:
			
			line = line.split(' ')

			if (line[0][0] == '.'):
				simReq = parseLine(line, simReq)
			else:
				print("olar")
				component = component_pb2.Component()
				component = parseLine(line)
		
		fileNetlist.close()
	return simReq

#function to parse and fill the fields of protobuf 
def parseLine(line, simReq = None):

	if line[0] == 'R':
		
		component.componentType = component_pb2.Resistor
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))

		return component

	if line[0] == 'C':
		component = component_pb2.Component()
		component.componentType = component_pb2.Capacitor
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))

		return component

	if line[0] == 'L':
		component = component_pb2.Component()
		component.componentType = component_pb2.Inductor
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))

		return component

	if line[0] == 'E':
		component = component_pb2.Component()
		component.componentType = component_pb2.VoltageControlledVoltageSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])
		component.values.append(float(line[5]))

		return component

	if line[0] == 'F':
		component = component_pb2.Component()
		component.componentType = component_pb2.CurrentControlledCurrentSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])
		component.values.append(float(line[5]))

		return component
		
	if line[0] == 'G':
		component = component_pb2.Component()
		component.componentType = component_pb2.VoltageControlledCurrentSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])
		component.values.append(float(line[5]))

		return component

	if line[0] == 'H':
		component = component_pb2.Component()
		component.componentType = component_pb2.CurrentControlledVoltageSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])
		component.values.append(float(line[5]))

		return component

	if line[0] == 'O':
		component = component_pb2.Component()
		component.componentType = component_pb2.OpAmp
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])

		return component

	if line[0] == 'Q':
		component = component_pb2.Component()
		component.componentType = component_pb2.BJT
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.values.append(float(line[4]))
		component.values.append(float(line[5]))
		component.values.append(float(line[6]))
		component.values.append(float(line[7]))
		component.values.append(float(line[8]))
		component.values.append(float(line[9]))

		return component		

	if line[0] == 'V':
		component = component_pb2.Component()
		component.componentType = component_pb2.VoltageSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))

		return component

	if line[0] == 'I':
		component = component_pb2.Component()
		component.componentType = component_pb2.CurrentSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))

		return component

	if line[0].ascii_uppercase == '.TRAN':
		
		simReq.SimulationType = simulationrequest_pb2.Transient
		simReq.end = float(line[1])
		simReq.step = float(line[2])

		return simReq

	if line[0].ascii_uppercase == '.AC':
				
		simReq.SimulationType = simulationrequest_pb2.Frequency
		points = float(line[1])
		begin = float(line[2])*2*math.pi
		end = float(line[3])*2*math.pi

		if line[1].ascii_uppercase == 'DEC':
			decades = math.log10(end/begin)
			totalPoints = decades * points

		if line[1].ascii_uppercase == 'OCT':

			octaves = math.log2(end/begin)
			totalPoints = octaves * points

		if line[1].ascii_uppercase == 'LIN':

			totalPoints = points

		simReq.points = totalPoints
		simReq.begin = begin
		simReq.end = end

		return simReq

#function to send the message using Py0MQ
def sendMessage(simReq):

	sender.send_string(u'%s' % simReq.SerializeToString())

context = zmq.Context()

# Socket to send messages on
sender = context.socket(zmq.PUSH)
sender.bind("tcp://*:5557")

# Socket with direct access to the sink: used to syncronize start of batch
sink = context.socket(zmq.PUSH)
sink.connect("tcp://localhost:5558")


simProtocol=openNetlist('netlist.txt')

print("Press Enter when the workers are ready: ")
_ = raw_input()
print("Sending tasks to workers...")


# The first message is "0" and signals start of batch
sink.send(b'0')

sendMessage(simProtocol)

# Give 0MQ time to deliver
time.sleep(1)



