/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::TwoBranchesComponent
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\TwoBranchesComponent.cpp
*********************************************************************/

//## auto_generated
#include "TwoBranchesComponent.h"
//## operation TwoBranchesComponent(Branch)
#include "Branch.h"
namespace Spice {
    //## package Spice
    
    //## class TwoBranchesComponent
    TwoBranchesComponent::TwoBranchesComponent(Branch** newBranches) {
        {
            for (int pos = 0; pos < 2; pos++) {
            	branches[pos] = NULL;
            }
        }
        //#[ operation TwoBranchesComponent(Branch)
        branches[0] = newBranches[0];
        branches[1] = newBranches[1];
        //#]
    }
    
    TwoBranchesComponent::TwoBranchesComponent() {
        {
            for (int pos = 0; pos < 2; pos++) {
            	branches[pos] = NULL;
            }
        }
    }
    
    TwoBranchesComponent::~TwoBranchesComponent() {
        cleanUpRelations();
    }
    
    void TwoBranchesComponent::cleanUpRelations() {
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\TwoBranchesComponent.cpp
*********************************************************************/
