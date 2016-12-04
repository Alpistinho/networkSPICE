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
				simReq = parseConfigurationLine(line, simReq)
			else:
				print("olar")
				parseComponentLine(line,simReq)

		fileNetlist.close()
	return simReq

#function to parse and fill the fields of protobuf 

def parseComponentLine(line,simReq):

	component = simReq.components.add()
	if line[0] == 'R':

		component.componentType = component.Resistor
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))

	
	if line[0] == 'C':
		component.componentType = component.Capacitor
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))

		

	if line[0] == 'L':
		component.componentType = component.Inductor
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))

		

	if line[0] == 'E':
		
		component.componentType = component.VoltageControlledVoltageSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])
		component.values.append(float(line[5]))

		

	if line[0] == 'F':
		
		component.componentType = component.CurrentControlledCurrentSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])
		component.values.append(float(line[5]))

		
		
	if line[0] == 'G':
		
		component.componentType = component.VoltageControlledCurrentSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])
		component.values.append(float(line[5]))

		

	if line[0] == 'H':
		
		component.componentType = component.CurrentControlledVoltageSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])
		component.values.append(float(line[5]))

		

	if line[0] == 'O':
		
		component.componentType = component.OpAmp
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.nodes.append(line[3])
		component.nodes.append(line[4])

		

	if line[0] == 'Q':
		
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

				

	if line[0] == 'V':
		
		component.componentType = component.VoltageSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))

		

	if line[0] == 'I':
		
		component.componentType = component.CurrentSource
		component.nodes.append(line[1])
		component.nodes.append(line[2])
		component.values.append(float(line[3]))

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

		for node in line[1:]:
			simReq.nodes.append(int(node))

		return simReq


#function to send the message using Py0MQ
# def sendMessage(simReq):


context = zmq.Context()

# Socket to send messages on
sender = context.socket(zmq.PUSH)
sender.bind("tcp://*:5557")

# Socket with direct access to the sink: used to syncronize start of batch
sink = context.socket(zmq.PUSH)
sink.connect("tcp://192.168.1.4:5558")


simProtocol=openNetlist('/home/gabriel/networkSPICE/src/server/netlist.txt')

print("Press Enter when the workers are ready: ")
_ = raw_input()
print("Sending tasks to workers...")


# The first message is "0" and signals start of batch
sink.send(b'0')
# sendMessage(simProtocol)
print(simProtocol.__str__())
sender.send(simProtocol.SerializeToString())

# Give 0MQ time to deliver
time.sleep(1)



