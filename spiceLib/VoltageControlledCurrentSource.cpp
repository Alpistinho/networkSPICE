#include "VoltageControlledCurrentSource.h"

#include "Node.h"
namespace Spice {

    VoltageControlledCurrentSource::VoltageControlledCurrentSource(Node** newNodes, double value, unsigned long newKey) : FourTerminalsComponent(newNodes, value, newKey) {
        
    }
    
    VoltageControlledCurrentSource::VoltageControlledCurrentSource() {
    }
    
    VoltageControlledCurrentSource::~VoltageControlledCurrentSource() {
    }
    
    void VoltageControlledCurrentSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[0]->getNodeNumber()] += value;	
        (*equationSystem)[nodes[3]->getNodeNumber()][nodes[0]->getNodeNumber()] -= value;
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[1]->getNodeNumber()] -= value;	
        (*equationSystem)[nodes[3]->getNodeNumber()][nodes[1]->getNodeNumber()] += value;
        
    }
    
    void VoltageControlledCurrentSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[0]->getNodeNumber()] += value;	
        (*equationSystem)[nodes[3]->getNodeNumber()][nodes[0]->getNodeNumber()] -= value;
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[1]->getNodeNumber()] -= value;	
        (*equationSystem)[nodes[3]->getNodeNumber()][nodes[1]->getNodeNumber()] += value;
        
    }
}