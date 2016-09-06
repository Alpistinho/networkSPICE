#include "ComponentStorage.h"
#include "Component.h"

namespace Spice {

    ComponentStorage::ComponentStorage() {
    }
    
    ComponentStorage::~ComponentStorage() {
    }
    
    unsigned long ComponentStorage::addBJT(std::string n1, std::string n2, std::string n3, double hfe, double hie, double hre, long double hoe, double cbe, double cbc) {
        
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
        
        return componentIdentifier;
    }

    unsigned long ComponentStorage::addCapacitor(std::string n1, std::string n2, double value) {

        ++componentIdentifier;
        Node* nodes[2];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        
        Capacitor *capacitor = new Capacitor(nodes, value, componentIdentifier);
        
        nodes[0]->addComponent(capacitor);
        nodes[1]->addComponent(capacitor);
        
        componentMap[componentIdentifier] = capacitor;
        
        return componentIdentifier;
    }
    
    unsigned long ComponentStorage::addCurrentControlledCurrentSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {

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
        
        return componentIdentifier;
    }
    
    unsigned long ComponentStorage::addCurrentControlledVoltageSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {

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

    }
    
    unsigned long ComponentStorage::addCurrentSource(std::string n1, std::string n2, double current, double phase) {

        ++componentIdentifier;
        Node* nodes[2];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        
        CurrentSource *currentSource = new CurrentSource(nodes, current, phase, componentIdentifier);
        
        nodes[0]->addComponent(currentSource);
        nodes[1]->addComponent(currentSource);
        
        componentMap[componentIdentifier] = currentSource;
        
        return componentIdentifier;

    }
    
    unsigned long ComponentStorage::addInductor(std::string n1, std::string n2, double value) {

        ++componentIdentifier;
        Node* nodes[2];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        Branch* branch1 = branchStorage.addBranch(componentIdentifier);
        
        Inductor *inductor = new Inductor(nodes, branch1, value, componentIdentifier);
        
        nodes[0]->addComponent(inductor);
        nodes[1]->addComponent(inductor);
        
        componentMap[componentIdentifier] = inductor;
        
        return componentIdentifier;
    }
    
    unsigned long ComponentStorage::addOpAmp(std::string n1, std::string n2, std::string n3, std::string n4) {

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
        
        return componentIdentifier;

    }
    
    unsigned long ComponentStorage::addResistor(std::string n1, std::string n2, double value) {
        
        ++componentIdentifier;
        Node* nodes[2];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        
        Resistor *resistor = new Resistor(nodes, value, componentIdentifier);
        nodes[0]->addComponent(resistor);
        nodes[1]->addComponent(resistor);
        
        componentMap[componentIdentifier] = resistor;
        
        return componentIdentifier;

    }
    
    unsigned long ComponentStorage::addVoltageControlledCurrentSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {
        
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
        
        return componentIdentifier;

    }
    
    unsigned long ComponentStorage::addVoltageControlledVoltageSource(std::string n1, std::string n2, std::string n3, std::string n4, double value) {
        
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
        
        return componentIdentifier;

    }
    
    unsigned long ComponentStorage::addVoltageSource(std::string n1, std::string n2, double voltage, double phase) {
        
        ++componentIdentifier;
        Node* nodes[2];
        
        nodes[0] = nodeStorage.addNode(n1);
        nodes[1] = nodeStorage.addNode(n2);
        Branch* branch1 = branchStorage.addBranch(componentIdentifier);
        
        VoltageSource *voltageSource = new VoltageSource(nodes, branch1, voltage, phase, componentIdentifier);
        
        nodes[0]->addComponent(voltageSource);
        nodes[1]->addComponent(voltageSource);
        
        componentMap[componentIdentifier] = voltageSource;
        
        return componentIdentifier;

    }
    
    void ComponentStorage::allocateNodeNumbers() {
        
        unsigned long matrixPosition;
        matrixPosition = nodeStorage.allocateNodeNumbers();
        branchStorage.allocateBranchNumbers(matrixPosition);
        
    }
    
    Component* ComponentStorage::getComponentByIdentifier(unsigned long identifier) {
        
        return componentMap[identifier];

    }
    
    void ComponentStorage::getFrequencySystem(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency) {

        unsigned long systemSize = getSystemSize();
        
        *equationSystem = std::vector<std::vector<std::complex<double>>>(); //clear the matrix
        equationSystem->resize(systemSize, std::vector<std::complex<double>>(systemSize + 1, 0));

        
        std::map<unsigned long, Component*>::iterator it;
        Component *dummyComponent;
        for(it = componentMap.begin(); it != componentMap.end(); it++) {
        	dummyComponent = it->second;
        	dummyComponent->getFrequencyStamp(equationSystem, frequency);
        }
        
    }
    
    unsigned long ComponentStorage::getSystemSize() {

        return nodeStorage.getNodeAmount() + branchStorage.getBranchAmount();

    }
    
    void ComponentStorage::getTransientSystem(std::vector<std::vector<double>> * equationSystem, std::vector<double> * pastResults, double step, double currentTime) {

        unsigned long systemSize = getSystemSize();
        
        *equationSystem = std::vector<std::vector<double>>();
        equationSystem->resize(systemSize, std::vector<double>(systemSize + 1, 0)); //clear the matrix

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
        
    }
}