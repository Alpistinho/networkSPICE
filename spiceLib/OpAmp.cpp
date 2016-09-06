#include "OpAmp.h"
#include "Branch.h"
#include "Node.h"

namespace Spice {

    
    OpAmp::OpAmp(Node** newNodes, Branch* newBranch, unsigned long newKey) : FourTerminalsComponent(newNodes, 0, newKey), OneBranchComponent(newBranch) {
        
    }
    
    OpAmp::OpAmp() {
    }
    
    OpAmp::~OpAmp() {
    }
    
    void OpAmp::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[2]->getNodeNumber()] += 1;	
        (*equationSystem)[branches->getBranchNumber()][nodes[3]->getNodeNumber()] -= 1;
        
    }
    
    void OpAmp::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[2]->getNodeNumber()] += 1;	
        (*equationSystem)[branches->getBranchNumber()][nodes[3]->getNodeNumber()] -= 1;
        
    }
}