/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::CurrentControlledCurrentSource
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\CurrentControlledCurrentSource.cpp
*********************************************************************/

//## auto_generated
#include "CurrentControlledCurrentSource.h"
//## auto_generated
#include "Branch.h"
//## auto_generated
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class CurrentControlledCurrentSource
    CurrentControlledCurrentSource::CurrentControlledCurrentSource(Node** newNodes, Branch* newBranch, double value, unsigned long newKey) : FourTerminalsComponent(newNodes, value, newKey), OneBranchComponent(newBranch) {
        //#[ operation CurrentControlledCurrentSource(Node,Branch,double,unsigned long)
        //#]
    }
    
    CurrentControlledCurrentSource::CurrentControlledCurrentSource() {
    }
    
    CurrentControlledCurrentSource::~CurrentControlledCurrentSource() {
    }
    
    void CurrentControlledCurrentSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += value;	
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= value;
        
        (*equationSystem)[nodes[2]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[3]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[2]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[3]->getNodeNumber()] += 1;
        //#]
    }
    
    void CurrentControlledCurrentSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += value;	
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= value;
        
        (*equationSystem)[nodes[2]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[3]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[2]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[3]->getNodeNumber()] += 1;
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\CurrentControlledCurrentSource.cpp
*********************************************************************/
