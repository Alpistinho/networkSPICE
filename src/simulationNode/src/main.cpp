#include <iostream> 
#include <string>

#include "ComponentStorage.h"
#include "FrequencySimulation.h"
#include "TransientSimulation.h"

#include "zmq.hpp"

#include "simulationrequest.pb.h"
#include "results.pb.h"

#include "netlistfuncs.h"

int main(int argc, char *argv[]) {

	std::string ventilatorAddress("tcp://");
	std::string sinkAddress("tcp://");

	if (argc == 1) {

		std::cout << std::endl << "Using localhost as address" << std::endl << std::endl;
		std::cout << "For different usage see:" << std::endl << std::endl;
		std::cout << "Usage: simulationNode <server address>. e.g. simulationNode 192.168.1.10" << std::endl;
		std::cout << "Usage: simulationNode <server address> <ventilator port> <sink port>. e.g. simulationNode 192.168.1.10 5558 5557" << std::endl << std::endl;

		ventilatorAddress = "tcp://localhost:5557";
		sinkAddress = "tcp://localhost:5558";

	}

	if (argc == 3) {

		std::cout << "Usage: simulationNode <server address>. e.g. simulationNode 192.168.1.10" << std::endl;
		std::cout << "Usage: simulationNode <server address> <ventilator port> <sink port>. e.g. simulationNode 192.168.1.10 5558 5557" << std::endl;
		
		return 1;
	}



	if (argc == 2) {

		
		ventilatorAddress.append(argv[1]);
		ventilatorAddress.append(":5557");

		sinkAddress.append(argv[1]);
		sinkAddress.append(":5558");


	}

	if (argc == 4) {

		ventilatorAddress.append(argv[1]);
		ventilatorAddress.append(":");
		ventilatorAddress.append(argv[2]);

		
		sinkAddress.append(argv[1]);
		sinkAddress.append(":");
		sinkAddress.append(argv[3]);

	}



	
	Spice::ComponentStorage componentStorage; 
	Spice::FrequencySimulation freqSim;
	Spice::TransientSimulation timeSim;
	
	networkSpiceMessages::SimulationRequest simReq;
	networkSpiceMessages::Netlist netlist;
	networkSpiceMessages::Results results;

	zmq::context_t context(1);

	std::cout << ventilatorAddress << std::endl;
	std::cout << sinkAddress << std::endl;

	//  Socket to receive messages on
	zmq::socket_t receiver(context, ZMQ_PULL);
	receiver.connect(ventilatorAddress);

	//  Socket to send messages to
	zmq::socket_t sender(context, ZMQ_PUSH);
	sender.connect(sinkAddress);

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