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