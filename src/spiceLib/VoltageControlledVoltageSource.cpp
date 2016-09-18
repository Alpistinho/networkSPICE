#include "VoltageControlledVoltageSource.h"
#include "Branch.h"
#include "Node.h"

namespace Spice {

    
    VoltageControlledVoltageSource::VoltageControlledVoltageSource(Node** newNodes, Branch* newBranch, double value, unsigned long newKey) : FourTerminalsComponent(newNodes, value, newKey), OneBranchComponent(newBranch) {
        
    }
    
    VoltageControlledVoltageSource::VoltageControlledVoltageSource() {
    }
    
    VoltageControlledVoltageSource::~VoltageControlledVoltageSource() {
    }
    
    void VoltageControlledVoltageSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {

        (*equationSystem)[nodes[2]->getNodeNumber()][branches->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[3]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;	
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] += value;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] -= value;
        
    }
    
    void VoltageControlledVoltageSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {

        (*equationSystem)[nodes[2]->getNodeNumber()][branches->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[3]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;	
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] += value;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] -= value;
        
    }
}