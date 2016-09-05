/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Branch
//!	Generated Date	: Thu, 10, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Branch.cpp
*********************************************************************/

//## auto_generated
#include "Branch.h"
namespace Spice {
    //## package Spice
    
    //## class Branch
    Branch::Branch(unsigned long branchIdentifier) : identifier(branchIdentifier) {
        //#[ operation Branch(unsigned long)
        //#]
    }
    
    Branch::Branch() {
    }
    
    Branch::~Branch() {
    }
    
    unsigned long Branch::getBranchNumber() const {
        return branchNumber;
    }
    
    void Branch::setBranchNumber(unsigned long p_branchNumber) {
        branchNumber = p_branchNumber;
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Branch.cpp
*********************************************************************/
