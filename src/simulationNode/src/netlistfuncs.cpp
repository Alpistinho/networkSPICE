#include "netlistfuncs.h"

void printSimulationRequest(networkSpiceMessages::SimulationRequest simReq) {

	std::cout << "SimlationRequest Message: " << std::endl << std::endl;

	std::cout << "Begin: " << simReq.begin() << std::endl;
	std::cout << "End: " << simReq.end() << std::endl;
	std::cout << "Points: " << simReq.points()  << std::endl;
	std::cout << "Step: " << simReq.step()  << std::endl;
	std::cout << "Type: " << simReq.type()  << std::endl;

	const networkSpiceMessages::Netlist &netlist = simReq.netlist();
	std::cout << "Components: " << std::endl << std::endl;

	for (int i = 0; i < netlist.component_size(); i++) {

		const networkSpiceMessages::Component &component = netlist.component(i);
		
		std::cout << "Type: " << component.componenttype()  << std::endl;
		
		std::cout << "Nodes: ";
		
		for (int j = 0; j < component.nodes_size(); j++) {

			std::cout << component.nodes(j) << " ";

		}
		
		std::cout << std::endl;
		
		std::cout << "Values: ";
		
		for (int j = 0; j < component.values_size(); j++) {

			std::cout << component.values(j) << " ";

		}
		
		std::cout << std::endl;
		

	}

	return;

}

Spice::ComponentStorage readComponents(networkSpiceMessages::Netlist &netlist) {

	Spice::ComponentStorage componentStorage;

	for (unsigned i = 0; i < netlist.component_size(); i++) {

		const networkSpiceMessages::Component& component = netlist.component(i);
		
		switch (component.componenttype()) { 
        	case networkSpiceMessages::Component::Resistor:
        		componentStorage.addResistor(component.nodes(0), component.nodes(1), component.values(0));
			break;
        
        	case networkSpiceMessages::Component::Capacitor:
        		componentStorage.addCapacitor(component.nodes(0), component.nodes(1), component.values(0));
			break;
        
        	case networkSpiceMessages::Component::Inductor:
        		componentStorage.addInductor(component.nodes(0), component.nodes(1), component.values(0));
			break;
        
        	case networkSpiceMessages::Component::VoltageSource:
        		componentStorage.addVoltageSource(component.nodes(0), component.nodes(1), component.values(0), component.values(1));
			break;
        
        	case networkSpiceMessages::Component::CurrentSource:
        		componentStorage.addCurrentSource(component.nodes(0), component.nodes(1), component.values(0), component.values(1));
			break;
        
        	case networkSpiceMessages::Component::VoltageControlledVoltageSource:
        		componentStorage.addVoltageControlledVoltageSource(component.nodes(0), component.nodes(1),component.nodes(2), component.nodes(3), component.values(0));
			break;
        
        	case networkSpiceMessages::Component::CurrentControlledCurrentSource:
        		componentStorage.addCurrentControlledCurrentSource(component.nodes(0), component.nodes(1),component.nodes(2), component.nodes(3), component.values(0));
			break;
        
        	case networkSpiceMessages::Component::VoltageControlledCurrentSource:
        		componentStorage.addVoltageControlledCurrentSource(component.nodes(0), component.nodes(1),component.nodes(2), component.nodes(3), component.values(0));
        	break;
        
        	case networkSpiceMessages::Component::CurrentControlledVoltageSource:
        		componentStorage.addCurrentControlledVoltageSource(component.nodes(0), component.nodes(1),component.nodes(2), component.nodes(3), component.values(0));
			break;
        
        	case networkSpiceMessages::Component::OpAmp:
        		componentStorage.addOpAmp(component.nodes(0), component.nodes(1),component.nodes(2), component.nodes(3));
			break;
        	
			case networkSpiceMessages::Component::BJT:
        		componentStorage.addBJT(component.nodes(0), component.nodes(1),component.nodes(2), component.values(0), component.values(1), component.values(2), component.values(3), component.values(4), component.values(5));
			break;
		}
	}


	return componentStorage;

}

networkSpiceMessages::Results writeResults(std::map<double,std::vector<std::complex<double>>*> * results, std::vector<unsigned> nodes) {

	networkSpiceMessages::Results resultMessage;

	std::map<double,std::vector<std::complex<double>>*>::const_iterator it;

	for(it = results->begin(); it != results->end(); it++) {

 		networkSpiceMessages::FrequencyPoint *freqPoint = resultMessage.add_frequencypoint();

		std::vector<unsigned>::const_iterator nodeIt;;

		for (nodeIt = nodes.begin(); nodeIt != nodes.end(); nodeIt++) {

			freqPoint->add_magnitude(std::abs(it->second->at(*nodeIt)));
			freqPoint->add_phase(std::arg(it->second->at(*nodeIt)));
			freqPoint->add_node(*nodeIt);

		}

		freqPoint->set_frequency(it->first);

	}

	return resultMessage;

}

networkSpiceMessages::Results writeResults(std::vector<std::pair<double, std::vector<double>>> results, std::vector<unsigned> nodes) {

	networkSpiceMessages::Results resultMessage;

	std::vector<std::pair<double, std::vector<double>>>::const_iterator it;

	for(it = results.begin(); it != results.end(); it++) {

 		networkSpiceMessages::TransientPoint *tranPoint = resultMessage.add_transientpoint();

		std::vector<unsigned>::const_iterator nodeIt;;

		for (nodeIt = nodes.begin(); nodeIt != nodes.end(); nodeIt++) {

			tranPoint->add_magnitude(it->second.at(*nodeIt));
			tranPoint->add_node(*nodeIt);

		}

		tranPoint->set_time(it->first);

	}

	return resultMessage;


}