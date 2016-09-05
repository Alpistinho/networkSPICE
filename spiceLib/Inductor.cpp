/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Inductor
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Inductor.cpp
*********************************************************************/

//## auto_generated
#include "Inductor.h"
//## auto_generated
#include "Branch.h"
//## auto_generated
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class Inductor
    Inductor::Inductor(Node** newNodes, Branch* newBranches, double value, unsigned long newKey) : TwoTerminalsComponent(newNodes, value, newKey), OneBranchComponent(newBranches) {
        //#[ operation Inductor(Node,Branch,double,unsigned long)
        //#]
    }
    
    Inductor::Inductor() {
    }
    
    Inductor::~Inductor() {
    }
    
    void Inductor::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][branches->getBranchNumber()] += std::complex<double>(0,	frequency*value);
        
        //#]
    }
    
    void Inductor::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        unsigned long columns =(*equationSystem)[0].size(); // number of columns the matrix has
        
        (*equationSystem)[branches->getBranchNumber()][nodes[0]->getNodeNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][nodes[1]->getNodeNumber()] += 1;
        (*equationSystem)[nodes[0]->getNodeNumber()][branches->getBranchNumber()] += 1;
        (*equationSystem)[nodes[1]->getNodeNumber()][branches->getBranchNumber()] -= 1;
        (*equationSystem)[branches->getBranchNumber()][branches->getBranchNumber()] += value/step;
        
        (*equationSystem)[branches->getBranchNumber()][columns - 1] += (value/step)*(*pastResults)[branches->getBranchNumber()];
        
        
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Inductor.cpp
*********************************************************************/
