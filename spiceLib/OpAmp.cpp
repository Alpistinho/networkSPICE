/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::OpAmp
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\OpAmp.cpp
*********************************************************************/

//## auto_generated
#include "OpAmp.h"
//## auto_generated
#include "Branch.h"
//## auto_generated
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class OpAmp
    OpAmp::OpAmp(Node** newNodes, Branch* newBranch, unsigned long newKey) : FourTerminalsComponent(newNodes, 0, newKey), OneBranchComponent(newBranch) {
        //#[ operation OpAmp(Node,Branch,unsigned long)
        //#]
    }
    
    OpAmp::OpAmp() {
    }
    
    OpAmp::~OpAmp() {
    }
    
    void OpAmp::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[2]->getNodeNumber()] += 1;	
        (*equationSystem)[branches->getBranchNumber()][nodes[3]->getNodeNumber()] -= 1;
        //#]
    }
    
    void OpAmp::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;	
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[2]->getNodeNumber()] += 1;	
        (*equationSystem)[branches->getBranchNumber()][nodes[3]->getNodeNumber()] -= 1;
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\OpAmp.cpp
*********************************************************************/
