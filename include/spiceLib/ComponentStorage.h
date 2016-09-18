#ifndef ComponentStorage_H
#define ComponentStorage_H

#include "Spice.h"
#include "Storage.h"
#include "BranchStorage.h"
#include "NodeStorage.h"
namespace Spice {
	class Component;
}

#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"
#include "CurrentControlledCurrentSource.h"
#include "CurrentControlledVoltageSource.h"
#include "BJT.h"
#include "CurrentSource.h"
#include "OpAmp.h"
#include "VoltageControlledCurrentSource.h"
#include "VoltageControlledVoltageSource.h"
#include "VoltageSource.h"
#include "Node.h"
#include "Branch.h"
#include "Component.h"
#include <string>
#include <algorithm>


namespace Spice {

	class ComponentStorage : public Storage {

		
	public :
	
		ComponentStorage();
		
		~ComponentStorage();
				
		unsigned long addCapacitor(std::string n1, std::string n2, double value);
		
		unsigned long addCurrentControlledCurrentSource(std::string n1, std::string n2, std::string n3, std::string n4, double value);
		
		unsigned long addCurrentControlledVoltageSource(std::string n1, std::string n2, std::string n3, std::string n4, double value);
		
		unsigned long addCurrentSource(std::string n1, std::string n2, double current, double phase);
		
		unsigned long addInductor(std::string n1, std::string n2, double value);
		
		unsigned long addResistor(std::string n1, std::string n2, double value);
		
		unsigned long addVoltageControlledCurrentSource(std::string n1, std::string n2, std::string n3, std::string n4, double value);
		
		unsigned long addVoltageControlledVoltageSource(std::string n1, std::string n2, std::string n3, std::string n4, double value);
		
		unsigned long addVoltageSource(std::string n1, std::string n2, double voltage, double phase);
		
		unsigned long addBJT(std::string n1, std::string n2, std::string n3, double hfe, double hie, double hre, long double hoe, double cbe, double cbc);
		
		unsigned long addOpAmp(std::string n1, std::string n2, std::string n3, std::string n4);
		
		void allocateNodeNumbers();
		
		Component* getComponentByIdentifier(unsigned long identifier);
		
		void getFrequencySystem(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency);

		unsigned long getSystemSize();
	
	protected :
	
		unsigned long branchesNeededAmount;
		
		unsigned long componentIdentifier;
		
		std::map<unsigned long, Component*> componentMap;
		
		unsigned long elementsAmount;
		
		BranchStorage branchStorage;
		
		NodeStorage nodeStorage;
	
	public :
	
		void getTransientSystem(std::vector<std::vector<double>> * equationSystem, std::vector<double> * pastResults, double step, double currentTime);

	};
}

#endif