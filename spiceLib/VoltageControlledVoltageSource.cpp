/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::VoltageControlledVoltageSource
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\VoltageControlledVoltageSource.cpp
*********************************************************************/

//## auto_generated
#include "VoltageControlledVoltageSource.h"
//## auto_generated
#include "Branch.h"
//## auto_generated
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class VoltageControlledVoltageSource
    VoltageControlledVoltageSource::VoltageControlledVoltageSource(Node** newNodes, Branch* newBranch, double value, unsigned long newKey) : FourTerminalsComponent(newNodes, value, newKey), OneBranchComponent(newBranch) {
        //#[ operation VoltageControlledVoltageSource(Node,Branch,double,unsigned long)
        //#]
    }
    
    VoltageControlledVoltageSource::VoltageControlledVoltageSource() {
    }
    
    VoltageControlledVoltageSource::~VoltageControlledVoltageSource() {
    }
    
    void VoltageControlledVoltageSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        (*equationSystem)[nodes[2]->getNodeNumber()][branches->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[3]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;	
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] += value;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] -= value;
        //#]
    }
    
    void VoltageControlledVoltageSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        (*equationSystem)[nodes[2]->getNodeNumber()][branches->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[3]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;	
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] += value;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] -= value;
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\VoltageControlledVoltageSource.cpp
*********************************************************************/
