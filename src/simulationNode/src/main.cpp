#include <iostream> 
#include <string>

#include "ComponentStorage.h"
#include "FrequencySimulation.h"
#include "TransientSimulation.h"

#include <google/protobuf/text_format.h>

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
		std::cout << "Usage: simulationNode <server address> <ventilator port> <sink port>. e.g. simulationNode 192.168.1.10 5557 5558" << std::endl;
		
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


	std::cout << "Ventilator address: " << ventilatorAddress << std::endl;
	std::cout << "Sink address: " << sinkAddress << std::endl;

	zmq::context_t context(1);

	//  Socket to receive messages on
	zmq::socket_t receiver(context, ZMQ_PULL);
	receiver.connect(ventilatorAddress);

	//  Socket to send messages to
	zmq::socket_t sender(context, ZMQ_PUSH);
	sender.connect(sinkAddress);

	
	Spice::ComponentStorage componentStorage; 
	Spice::FrequencySimulation freqSim;
	Spice::TransientSimulation timeSim;
	
	networkSpiceMessages::SimulationRequest simReq;
	networkSpiceMessages::Results results;

	std::vector<double> initialConditions(componentStorage.getSystemSize(), 0);

	while (1) {

		std::cout << "Waiting for jobs" << std::endl;

		zmq::message_t receivedMessage;
		receiver.recv(&receivedMessage);

		std::string msg_str(static_cast<char*>(receivedMessage.data()), receivedMessage.size());

		bool success = simReq.ParseFromString(msg_str);

        // std::string text_str;
        // google::protobuf::TextFormat::PrintToString(simReq, &text_str);
        // std::cout << text_str << std::endl;

		// printSimulationRequest(simReq);

		std::vector<unsigned> requestedNodes;

		for (int i = 0; i < simReq.nodes_size(); i++) {
			
			const unsigned &node = simReq.nodes(i);
			requestedNodes.push_back(node);

		}

		componentStorage = readComponents(simReq);
		
		if (simReq.type() == networkSpiceMessages::SimulationRequest::Frequency) {

			std::cout << "Simulating..." << std::endl;

			freqSim.setInitFreq(simReq.begin());
			freqSim.setEndFreq(simReq.end());
			freqSim.setPoints(simReq.points());

			std::map<double,std::vector<std::complex<double>>*> *freqResults = freqSim.simulateFrequencyResponse(&componentStorage);
			results = writeResults(freqResults, requestedNodes);

		} else { 

			if (simReq.type() == networkSpiceMessages::SimulationRequest::Transient) {

				timeSim.setEndTime(simReq.end());
				timeSim.setStep(simReq.step());

				std::vector<std::pair<double, std::vector<double>>> *tranResults = timeSim.simulateTransientResponse(&componentStorage, initialConditions);
				results = writeResults(*tranResults, requestedNodes);

			}
		}
		
		std::string serializedResults;
		results.SerializeToString(&serializedResults); 

		// std::string text_str;
		// google::protobuf::TextFormat::PrintToString(results, &text_str);
        // std::cout << text_str << std::endl;
		
		zmq::message_t sentMessage(serializedResults.size());

		std::cout << "Simulation Complete. Sending results..." << std::endl;
		// std::cout << "Byte size: " << serializedResults.size() << std::endl;

		memcpy ((void *) sentMessage.data (), serializedResults.c_str(), serializedResults.size());;

		sender.send(sentMessage);
		
		
	}

	return 0;
}