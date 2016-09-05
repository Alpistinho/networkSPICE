/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::VoltageSource
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\VoltageSource.cpp
*********************************************************************/

//## auto_generated
#include "VoltageSource.h"
//## auto_generated
#include "Branch.h"
//## auto_generated
#include "Node.h"

namespace Spice {
    //## package Spice
    
    //## class VoltageSource
    VoltageSource::VoltageSource() {
    }
    
    VoltageSource::~VoltageSource() {
    }
    
    ComponentType VoltageSource::getComponentType() {
        //#[ operation getComponentType()
        return TypeVoltageSource;
        //#]
    }
    
    void VoltageSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        unsigned long columns = (*equationSystem)[0].size(); // number of columns the matrix has

        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        
        (*equationSystem)[branches->getBranchNumber()][columns - 1] -= value;


        //#]
    }
    
    std::complex<double> VoltageSource::getValue() const {
        return value;
    }
    
    VoltageSource::VoltageSource(Node** newNodes, Branch* newBranches, double voltage, int phase, unsigned long newKey) : OneBranchComponent(newBranches), IndependentSource(newNodes, voltage, phase, newKey) {
        //#[ operation VoltageSource(Node,Branch,double,int,unsigned long)
        value = std::complex<double>(voltage*std::cos(phase), voltage*std::sin(phase));
        //#]
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

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\VoltageSource.cpp
*********************************************************************/
