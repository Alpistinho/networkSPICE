/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::CurrentControlledVoltageSource
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\CurrentControlledVoltageSource.cpp
*********************************************************************/


#include "CurrentControlledVoltageSource.h"

#include "Branch.h"

#include "Node.h"
namespace Spice {

    CurrentControlledVoltageSource::CurrentControlledVoltageSource(Node** newNodes, Branch** newBranches, double value, unsigned long newKey) : FourTerminalsComponent(newNodes, value, newKey), TwoBranchesComponent(newBranches) {
    }
    
    CurrentControlledVoltageSource::CurrentControlledVoltageSource() {
    }
    
    CurrentControlledVoltageSource::~CurrentControlledVoltageSource() {
    }
    
    void CurrentControlledVoltageSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        (*equationSystem)[nodes[0]->getNodeNumber()][branches[0]->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[1]->getNodeNumber()][branches[0]->getBranchNumber()] -= 1;
        (*equationSystem)[nodes[2]->getNodeNumber()][branches[1]->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[3]->getNodeNumber()][branches[1]->getBranchNumber()] -= 1;
        
        (*equationSystem)[branches[0]->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;
        (*equationSystem)[branches[0]->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        (*equationSystem)[branches[1]->getBranchNumber()][nodes[2]->getNodeNumber()] -= 1;
        (*equationSystem)[branches[1]->getBranchNumber()][nodes[3]->getNodeNumber()] += 1;
        
        (*equationSystem)[branches[1]->getBranchNumber()][branches[0]->getBranchNumber()] += value;

    }
    
    void CurrentControlledVoltageSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {

        (*equationSystem)[nodes[0]->getNodeNumber()][branches[0]->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[1]->getNodeNumber()][branches[0]->getBranchNumber()] -= 1;
        (*equationSystem)[nodes[2]->getNodeNumber()][branches[1]->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[3]->getNodeNumber()][branches[1]->getBranchNumber()] -= 1;
        
        (*equationSystem)[branches[0]->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;
        (*equationSystem)[branches[0]->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        (*equationSystem)[branches[1]->getBranchNumber()][nodes[2]->getNodeNumber()] -= 1;
        (*equationSystem)[branches[1]->getBranchNumber()][nodes[3]->getNodeNumber()] += 1;
        
        (*equationSystem)[branches[1]->getBranchNumber()][branches[0]->getBranchNumber()] += value;

    }
}