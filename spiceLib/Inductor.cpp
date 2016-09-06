#include "Inductor.h"
#include "Branch.h"
#include "Node.h"

namespace Spice {


    Inductor::Inductor(Node** newNodes, Branch* newBranches, double value, unsigned long newKey) : TwoTerminalsComponent(newNodes, value, newKey), OneBranchComponent(newBranches) {
        
    }
    
    Inductor::Inductor() {
    }
    
    Inductor::~Inductor() {
    }
    
    void Inductor::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][branches->getBranchNumber()] += std::complex<double>(0,	frequency*value);
        
        
    }
    
    void Inductor::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        unsigned long columns =(*equationSystem)[0].size(); // number of columns the matrix has
        
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][branches->getBranchNumber()] += value/step;
        
        (*equationSystem)[branches->getBranchNumber()][columns - 1] += (value/step)*(*pastResults)[branches->getBranchNumber()];
        
        
        
    }
}