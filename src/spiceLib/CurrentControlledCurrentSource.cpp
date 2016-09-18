#include "CurrentControlledCurrentSource.h"

#include "Branch.h"
#include "Node.h"

namespace Spice {
    
    CurrentControlledCurrentSource::CurrentControlledCurrentSource(Node** newNodes, Branch* newBranch, double value, unsigned long newKey) : FourTerminalsComponent(newNodes, value, newKey), OneBranchComponent(newBranch) {
    }
    
    CurrentControlledCurrentSource::CurrentControlledCurrentSource() {
    }
    
    CurrentControlledCurrentSource::~CurrentControlledCurrentSource() {
    }
    
    void CurrentControlledCurrentSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += value;	
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= value;
        
        (*equationSystem)[nodes[2]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[3]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[2]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[3]->getNodeNumber()] += 1;

    }
    
    void CurrentControlledCurrentSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += value;	
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= value;
        
        (*equationSystem)[nodes[2]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[3]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[2]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[3]->getNodeNumber()] += 1;

    }
}
