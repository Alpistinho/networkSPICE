#include "ComponentStorage.h"
#include "FrequencySimulation.h"
#include "TransientSimulation.h"

#include "netlist.pb.h"
#include "results.pb.h"

#include "zmq.hpp"

int main(int argc, char *argv[]) {
	
	Spice::ComponentStorage componentStorage;
	Spice::FrequencySimulation freqSim;
	Spice::TransientSimulation timeSim;
	
	networkSpiceMessages::Netlist netlist;
	networkSpiceMessages::Results results;

	zmq::context_t context(1);

	//  Socket to receive messages on
	zmq::socket_t receiver(context, ZMQ_PULL);
	receiver.connect("tcp://localhost:5557");

	//  Socket to send messages to
	zmq::socket_t sender(context, ZMQ_PUSH);
	sender.connect("tcp://localhost:5558");

	std::vector<double> initialConditions(componentStorage.getSystemSize(), 0);

	while (1) {

		zmq::message_t receivedMessage;
		receiver.recv(&receivedMessage);

		netlist.ParseFromArray(receivedMessage.data(), receivedMessage.size());


		/*
		READ NETLIST
		SIMULATE
		WRITE RESULTS
		*/
		
		std::string serializedResults;
		results.SerializeToString(&serializedResults); 
		
		zmq::message_t sentMessage;

		memcpy(sentMessage.data(), serializedResults.data(), serializedResults.size());

		sender.send(sentMessage);
		
	}

	return 0;
}