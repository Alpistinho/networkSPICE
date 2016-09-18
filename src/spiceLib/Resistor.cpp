#include "Resistor.h"
#include "Node.h"

namespace Spice {

    Resistor::Resistor(Node** newNodes, double value, unsigned long newKey) : TwoTerminalsComponent(newNodes, value, newKey) {
        
    }
    
    Resistor::Resistor() {
    }
    
    Resistor::~Resistor() {
    }
    
    ComponentType Resistor::getComponentType() {
        return TypeResistor;
        
    }
    
    void Resistor::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += 1/value;
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] -= 1/value;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -= 1/value;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] += 1/value;
        
    }
    
    void Resistor::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += 1/value;
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] -= 1/value;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -= 1/value;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] += 1/value;
        
    }
}