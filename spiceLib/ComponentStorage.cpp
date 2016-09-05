/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::ComponentStorage
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\ComponentStorage.cpp
*********************************************************************/

//## auto_generated
#include "ComponentStorage.h"
//## operation getComponentByIdentifier(unsigned long)
#include "Component.h"

namespace Spice {
    //## package Spice
    
    //## class ComponentStorage
    ComponentStorage::ComponentStorage() {
    }
    
    ComponentStorage::~ComponentStorage() {
    }
    
    unsigned long ComponentStorage::addBJT(std::string n1, std::string n2, std::string n3, double hfe, double hie, double hre, long double hoe, double cbe, double cbc) {
        //#[ operation addBJT(std::string,std::string,std::string,double,double,double,long double,double,double)
        
        ++componentIdentifier;
        Node* nodes[3];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        nodes[2] = nodeStorage.addNode(n3);
        
        BJT *bjt = new BJT(nodes, hfe, hie, hre, hoe, cbe, cbc , componentIdentifier); 
        
        nodes[0]->addComponent(bjt);
        nodes[1]->addComponent(bjt);
        nodes[2]->addComponent(bjt);
        
        componentMap[componentIdentifier] = bjt;
        
        return componentIdentifier;//identifies the component added
        //#]
    }
    
    unsigned long ComponentStorage::addCapacitor(std::string n1, std::string n2, double value) {
        //#[ operation addCapacitor(std::string,std::string,double)
        ++componentIdentifier;
        Node* nodes[2];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        
        Capacitor *capacitor = new Capacitor(nodes, value, componentIdentifier);
        
        nodes[0]->addComponent(capacitor);
        nodes[1]->addComponent(capacitor);
        
        componentMap[componentIdentifier] = capacitor;
        
        return componentIdentifier;//identifies the component added
        //#]
    }
    
    unsigned long ComponentStorage::addCurrentControlledCurrentSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {
        //#[ operation addCurrentControlledCurrentSource(std::string,std::string,std::string,std::string,double)
        ++componentIdentifier;
        Node* nodes[4];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        nodes[2] = nodeStorage.addNode(n3);
        nodes[3] = nodeStorage.addNode(n4);
        Branch* branch1 = branchStorage.addBranch(componentIdentifier);
        
        CurrentControlledCurrentSource *cccs = new CurrentControlledCurrentSource(nodes, branch1, value, componentIdentifier);
        
        nodes[0]->addComponent(cccs);
        nodes[1]->addComponent(cccs);
        nodes[2]->addComponent(cccs);
        nodes[3]->addComponent(cccs);
        
        componentMap[componentIdentifier] = cccs;
        
        return componentIdentifier;//identifies the component added
        //#]
    }
    
    unsigned long ComponentStorage::addCurrentControlledVoltageSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {
        //#[ operation addCurrentControlledVoltageSource(std::string,std::string,std::string,std::string,double)
        ++componentIdentifier;
        Node* nodes[4];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        nodes[2] = nodeStorage.addNode(n3);
        nodes[3] = nodeStorage.addNode(n4);
        
        Branch* branches[2];;
        branches[0] = branchStorage.addBranch(componentIdentifier);
        branches[1] = branchStorage.addBranch(componentIdentifier);
        
        CurrentControlledVoltageSource *ccvs = new CurrentControlledVoltageSource(nodes, branches, value, componentIdentifier); 
        
        nodes[0]->addComponent(ccvs);
        nodes[1]->addComponent(ccvs);
        nodes[2]->addComponent(ccvs);
        nodes[3]->addComponent(ccvs);
        
        componentMap[componentIdentifier] = ccvs;    
        return componentIdentifier;
        //#]
    }
    
    unsigned long ComponentStorage::addCurrentSource(std::string n1, std::string n2, double current, double phase) {
        //#[ operation addCurrentSource(std::string,std::string,double,double)
        ++componentIdentifier;
        Node* nodes[2];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        
        CurrentSource *currentSource = new CurrentSource(nodes, current, phase, componentIdentifier);
        
        nodes[0]->addComponent(currentSource);
        nodes[1]->addComponent(currentSource);
        
        componentMap[componentIdentifier] = currentSource;
        
        return componentIdentifier;//identifies the component added
        //#]
    }
    
    unsigned long ComponentStorage::addInductor(std::string n1, std::string n2, double value) {
        //#[ operation addInductor(std::string,std::string,double)
        ++componentIdentifier;
        Node* nodes[2];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        Branch* branch1 = branchStorage.addBranch(componentIdentifier);
        
        Inductor *inductor = new Inductor(nodes, branch1, value, componentIdentifier);
        
        nodes[0]->addComponent(inductor);
        nodes[1]->addComponent(inductor);
        
        componentMap[componentIdentifier] = inductor;
        
        return componentIdentifier;//identifies the component added
        //#]
    }
    
    unsigned long ComponentStorage::addOpAmp(std::string n1, std::string n2, std::string n3, std::string n4) {
        //#[ operation addOpAmp(std::string,std::string,std::string,std::string)
        ++componentIdentifier;
        Node* nodes[4];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        nodes[2] = nodeStorage.addNode(n3);
        nodes[3] = nodeStorage.addNode(n4);
        Branch* branch1 = branchStorage.addBranch(componentIdentifier);
        
        OpAmp *opAmp = new OpAmp(nodes, branch1, componentIdentifier); 
        
        nodes[0]->addComponent(opAmp);
        nodes[1]->addComponent(opAmp);
        nodes[2]->addComponent(opAmp);
        nodes[3]->addComponent(opAmp);
        
        componentMap[componentIdentifier] = opAmp;
        
        return componentIdentifier;//identifies the component added
        //#]
    }
    
    unsigned long ComponentStorage::addResistor(std::string n1, std::string n2, double value) {
        //#[ operation addResistor(std::string,std::string,double)
        ++componentIdentifier;
        Node* nodes[2];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        
        Resistor *resistor = new Resistor(nodes, value, componentIdentifier);
        nodes[0]->addComponent(resistor);
        nodes[1]->addComponent(resistor);
        
        componentMap[componentIdentifier] = resistor;
        
        return componentIdentifier;//identifies the component added
        //#]
    }
    
    unsigned long ComponentStorage::addVoltageControlledCurrentSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {
        //#[ operation addVoltageControlledCurrentSource(std::string,std::string,std::string,std::string,double)
        ++componentIdentifier;
        Node* nodes[4];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        nodes[2] = nodeStorage.addNode(n3);
        nodes[3] = nodeStorage.addNode(n4);
        
        VoltageControlledCurrentSource *vccs = new VoltageControlledCurrentSource(nodes, value, componentIdentifier); 
        
        nodes[0]->addComponent(vccs);
        nodes[1]->addComponent(vccs);
        nodes[2]->addComponent(vccs);
        nodes[3]->addComponent(vccs);
        
        componentMap[componentIdentifier] = vccs;
        
        return componentIdentifier;//identifies the component added
        //#]
    }
    
    unsigned long ComponentStorage::addVoltageControlledVoltageSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {
        //#[ operation addVoltageControlledVoltageSource(std::string,std::string,std::string,std::string,double)
        ++componentIdentifier;
        Node* nodes[4];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        nodes[2] = nodeStorage.addNode(n3);
        nodes[3] = nodeStorage.addNode(n4);
        Branch* branch1 = branchStorage.addBranch(componentIdentifier);
        
        VoltageControlledVoltageSource *vcvs = new VoltageControlledVoltageSource(nodes, branch1, value, componentIdentifier); 
        
        nodes[0]->addComponent(vcvs);
        nodes[1]->addComponent(vcvs);
        nodes[2]->addComponent(vcvs);
        nodes[3]->addComponent(vcvs);
        
        componentMap[componentIdentifier] = vcvs;
        
        return componentIdentifier;//identifies the component added
        //#]
    }
    
    unsigned long ComponentStorage::addVoltageSource(std::string n1, std::string n2, double voltage, double phase) {
        //#[ operation addVoltageSource(std::string,std::string,double,double)
        ++componentIdentifier;
        Node* nodes[2];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        Branch* branch1 = branchStorage.addBranch(componentIdentifier);
        
        VoltageSource *voltageSource = new VoltageSource(nodes, branch1, voltage, phase, componentIdentifier);
        
        nodes[0]->addComponent(voltageSource);
        nodes[1]->addComponent(voltageSource);
        
        componentMap[componentIdentifier] = voltageSource;
        
        return componentIdentifier;//identifies the component added
        //#]
    }
    
    void ComponentStorage::allocateNodeNumbers() {
        //#[ operation allocateNodeNumbers()
        unsigned long matrixPosition;
        matrixPosition = nodeStorage.allocateNodeNumbers();
        branchStorage.allocateBranchNumbers(matrixPosition);
        //#]
    }
    
    Component* ComponentStorage::getComponentByIdentifier(unsigned long identifier) {
        //#[ operation getComponentByIdentifier(unsigned long)
        return componentMap[identifier];
        //#]
    }
    
    void ComponentStorage::getFrequencySystem(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {
        //#[ operation getFrequencySystem(std::vector<std::vector<std::complex<double>>>*,double)
        unsigned long systemSize = getSystemSize();
        
        *equationSystem = std::vector<std::vector<std::complex<double>>>(); //clear the matrix
        equationSystem->resize(systemSize, std::vector<std::complex<double>>(systemSize + 1, 0));
//        equationSystem->resize(systemSize);
//        for(unsigned long i = 0; i < systemSize; i++ ) {
//            (*equationSystem)[i].resize(systemSize + 1);
//        } //resized the matrix
        
        std::map<unsigned long, Component*>::iterator it;
        Component *dummyComponent;
        for(it = componentMap.begin(); it != componentMap.end(); it++) {
        	dummyComponent = it->second;
        	dummyComponent->getFrequencyStamp(equationSystem, frequency);
        }
        
        //#]
    }
    
    unsigned long ComponentStorage::getSystemSize() {
        //#[ operation getSystemSize()
        return nodeStorage.getNodeAmount() + branchStorage.getBranchAmount();
        //#]
    }
    
    void ComponentStorage::getTransientSystem(std::vector<std::vector<double>> * equationSystem, std::vector<double> * pastResults, double step, double currentTime) {
        //#[ operation getTransientSystem(std::vector<std::vector<double>> *,std::vector<double> *,double,double)

        unsigned long systemSize = getSystemSize();
        
        *equationSystem = std::vector<std::vector<double>>();
        equationSystem->resize(systemSize, std::vector<double>(systemSize + 1, 0)); //clear the matrix
//        equationSystem->resize(systemSize, 0.0);
//        for(unsigned long i = 0; i < systemSize; i++ ) {
//            (*equationSystem)[i].resize(systemSize + 1, 0.0);
//        } //resized the matrix

//        std::cout  << "after creation\n\n";
//        for (unsigned long i = 0; i < equationSystem->size() - 1 ; i++) {
//            for(unsigned j = 0; j < equationSystem->size() + 1; j++) {
//            std::cout  << (*equationSystem)[i][j] << " ";
//            }
//            std::cout << std::endl << std::endl;
//        }
        std::map<unsigned long, Component*>::iterator it;
        Component *dummyComponent;
        for(it = componentMap.begin(); it != componentMap.end(); it++) {
        	dummyComponent = it->second;
        	if(IndependentSource *dummySource = dynamic_cast<IndependentSource *>(dummyComponent)) { // if it was pointing to a independent source
        		dummySource->getTransientStamp(equationSystem, pastResults, step, currentTime);
            } else {
                dummyComponent = it->second; //horrible hack
                dummyComponent->getTransientStamp(equationSystem, pastResults, step);
            }
        }
        

        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\ComponentStorage.cpp
*********************************************************************/
