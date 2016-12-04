
import sys
import simulationrequest_pb2
import component_pb2
import zmq

try:
    raw_input
except NameError:
    # Python 3
    raw_input = input

#function to create netlist
#def createNetlist ()

#function to open a netlist and return a array with the values and fields-TO DO-
def openNetlist(fileName):
	
	with open(fileName,'r') as fileNetlist:
		component = fileNetlist.readline()
		
	fileNetlist.close()
	return component

#function to fill the fields of protobuf 
def fillProtobuf(simReq):
	
	simReq.begin = 10
	simReq.end = 20
	simReq.points = 30
	simReq.step = 0.01
	simReq.type = simulationrequest_pb2.Frequency
	simReq.points = 0
	component = component_pb2.Component()
	component.componentType = component_pb2.Resistor
	node = component.nodes.append('2')
	node = component.nodes.append('3')

	value = component.values.append(1000.0)

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


simReq = simulationrequest_pb2.SimulationRequest()

#print('component: {}'  .format(openNetlist('netlist.txt')))

fillProtobuf(simReq)



print("Press Enter when the workers are ready: ")
_ = raw_input()
print("Sending tasks to workers...")


# The first message is "0" and signals start of batch
sink.send(b'0')

sendMessage(simReq)

# Give 0MQ time to deliver
time.sleep(1)



