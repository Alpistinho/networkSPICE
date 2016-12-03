#
#   Hello World server in Python
#   Binds REP socket to tcp://*:5555
#   Expects b"Hello" from client, replies with b"World"
#
import zmq
import component_pb2
import simulationrequest_pb2


simReq = simulationrequest_pb2.SimulationRequest()

simReq.begin = 10
simReq.end = 20
simReq.points = 30
simReq.step = 0.01
simReq.type = simulationrequest_pb2.Frequency

component = component_pb2.Component()
component.componentType = component_pb2.Resistor
node = component.nodes.add()
node = 2
node = component.nodes.add()
node = 3
value = component.values.add()
value = 1000


# context = zmq.Context()
# socket = context.socket(zmq.REP)
# socket.bind("tcp://*:5555")

# while True:
#     #  Wait for next request from client
#     message = socket.recv()
#     print("Received request: %s" % message)

#     #  Do some 'work'
#     time.sleep(1)

#     #  Send reply back to client
#     socket.send(b"World")
