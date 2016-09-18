#include "VoltageSource.h"

#include "Branch.h"

#include "Node.h"

namespace Spice {

    
    VoltageSource::VoltageSource() {
    }
    
    VoltageSource::~VoltageSource() {
    }
    
    ComponentType VoltageSource::getComponentType() {
        return TypeVoltageSource;
        
    }
    
    void VoltageSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {

        unsigned long columns = (*equationSystem)[0].size(); // number of columns the matrix has

        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        
        (*equationSystem)[branches->getBranchNumber()][columns - 1] -= value;


        
    }
    
    std::complex<double> VoltageSource::getValue() const {
        return value;
    }
    
    VoltageSource::VoltageSource(Node** newNodes, Branch* newBranches, double voltage, int phase, unsigned long newKey) : OneBranchComponent(newBranches), IndependentSource(newNodes, voltage, phase, newKey) {

        value = std::complex<double>(voltage*std::cos(phase), voltage*std::sin(phase));
        
    }
    
    void VoltageSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime) {

        unsigned long columns = (*equationSystem)[0].size(); // number of columns the matrix has

        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        
        (*equationSystem)[branches->getBranchNumber()][columns - 1] -= getOutput(currentTime);


    }
}