#include <iostream> 

#include "ComponentStorage.h"
#include "FrequencySimulation.h"
#include "TransientSimulation.h"

#include "zmq.hpp"

#include "simulationrequest.pb.h"
#include "results.pb.h"

#include "netlistfuncs.h"

int main(int argc, char *argv[]) {
	
	Spice::ComponentStorage componentStorage;
	Spice::FrequencySimulation freqSim;
	Spice::TransientSimulation timeSim;
	
	networkSpiceMessages::SimulationRequest simReq;
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

		std::cout << "Waiting for jobs" << std::endl;

		zmq::message_t receivedMessage;
		receiver.recv(&receivedMessage);

		std::cout << "Parsing..." << std::endl;

		simReq.ParseFromArray(receivedMessage.data(), receivedMessage.size());

		netlist = simReq.netlist();

		std::vector<unsigned> requestedNodes;

		for (unsigned i = 0; i < simReq.nodes_size(); i++) {
			requestedNodes.push_back(simReq.nodes(i));
		}
		

		componentStorage = readComponents(netlist);
		
		if (simReq.type() == networkSpiceMessages::SimulationType::Frequency) {

			std::cout << "Simulating..." << std::endl;

			freqSim.setInitFreq(simReq.begin());
			freqSim.setEndFreq(simReq.end());
			freqSim.setPoints(simReq.points());

			std::map<double,std::vector<std::complex<double>>*> *results = freqSim.simulateFrequencyResponse(&componentStorage);
			writeResults(results, requestedNodes);

		} else { 

			if (simReq.type() == networkSpiceMessages::SimulationType::Transient) {

				timeSim.setEndTime(simReq.end());
				timeSim.setStep(simReq.step());

				std::vector<std::pair<double, std::vector<double>>> *results = timeSim.simulateTransientResponse(&componentStorage, initialConditions);
				writeResults(*results, requestedNodes);

			}
		}
		/*
		READ NETLIST
		SIMULATE
		WRITE RESULTS
		*/
		
		std::string serializedResults;
		results.SerializeToString(&serializedResults); 
		
		zmq::message_t sentMessage;

		memcpy(sentMessage.data(), serializedResults.data(), serializedResults.size());

		std::cout << "Simulation Complete. Sending results..." << std::endl;
		
		sender.send(sentMessage);
		
		
	}

	return 0;
}