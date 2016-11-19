#include "netlistfuncs.h"

Spice::ComponentStorage readComponents(networkSpiceMessages::Netlist &netlist) {

	Spice::ComponentStorage componentStorage;

	for (unsigned i = 0; i < netlist.component_size(); i++) {

		const networkSpiceMessages::Component& component = netlist.component(i);
		
		switch (component.componenttype()) { 
        	case networkSpiceMessages::ComponentType::Resistor:
        		componentStorage.addResistor(component.nodes(0), component.nodes(1), component.values(0));
			break;
        
        	case networkSpiceMessages::ComponentType::Capacitor:
        		componentStorage.addCapacitor(component.nodes(0), component.nodes(1), component.values(0));
			break;
        
        	case networkSpiceMessages::ComponentType::Inductor:
        		componentStorage.addInductor(component.nodes(0), component.nodes(1), component.values(0));
			break;
        
        	case networkSpiceMessages::ComponentType::VoltageSource:
        		componentStorage.addVoltageSource(component.nodes(0), component.nodes(1), component.values(0), component.values(1));
			break;
        
        	case networkSpiceMessages::ComponentType::CurrentSource:
        		componentStorage.addCurrentSource(component.nodes(0), component.nodes(1), component.values(0), component.values(1));
			break;
        
        	case networkSpiceMessages::ComponentType::VoltageControlledVoltageSource:
        		componentStorage.addVoltageControlledVoltageSource(component.nodes(0), component.nodes(1),component.nodes(2), component.nodes(3), component.values(0));
			break;
        
        	case networkSpiceMessages::ComponentType::CurrentControlledCurrentSource:
        		componentStorage.addCurrentControlledCurrentSource(component.nodes(0), component.nodes(1),component.nodes(2), component.nodes(3), component.values(0));
			break;
        
        	case networkSpiceMessages::ComponentType::VoltageControlledCurrentSource:
        		componentStorage.addVoltageControlledCurrentSource(component.nodes(0), component.nodes(1),component.nodes(2), component.nodes(3), component.values(0));
        	break;
        
        	case networkSpiceMessages::ComponentType::CurrentControlledVoltageSource:
        		componentStorage.addCurrentControlledVoltageSource(component.nodes(0), component.nodes(1),component.nodes(2), component.nodes(3), component.values(0));
			break;
        
        	case networkSpiceMessages::ComponentType::OpAmp:
        		componentStorage.addOpAmp(component.nodes(0), component.nodes(1),component.nodes(2), component.nodes(3));
			break;
        	
			case networkSpiceMessages::ComponentType::BJT:
        		componentStorage.addBJT(component.nodes(0), component.nodes(1),component.nodes(2), component.values(0), component.values(1), component.values(2), component.values(3), component.values(4), component.values(5));
			break;
		}
	}


	return componentStorage;

}

networkSpiceMessages::Results writeResults(std::map<double,std::vector<std::complex<double>>*> &results, std::vector<unsigned> nodes) {

	networkSpiceMessages::Results resultMessage;

	std::map<double,std::vector<std::complex<double>>*>::const_iterator it;

	for(it = results.begin(); it != results.end(); it++) {

 		networkSpiceMessages::FrequencyPoint *freqPoint = resultMessage.add_frequencypoint();

		std::vector<unsigned>::const_iterator nodeIt;;

		for (nodeIt = nodes.begin(); nodeIt != nodes.end(); nodeIt++) {

			std::complex<double> value = it->second->at(*nodeIt);

			freqPoint->add_magnitude(std::abs(value));
			freqPoint->add_phase((180/M_PI)*atan2(imag(value), real(value)));
			freqPoint->add_node(*nodeIt);

		}

		freqPoint->set_frequency(it->first);

	}

	return resultMessage;



}

networkSpiceMessages::Results writeResults(std::vector<std::pair<double, std::vector<double>>> &results, std::vector<unsigned> nodes) {

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