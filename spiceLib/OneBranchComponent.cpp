/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::OneBranchComponent
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\OneBranchComponent.cpp
*********************************************************************/

//## auto_generated
#include "OneBranchComponent.h"
//## operation OneBranchComponent(Branch)
#include "Branch.h"
namespace Spice {
    //## package Spice
    
    //## class OneBranchComponent
    OneBranchComponent::OneBranchComponent() {
        branches = NULL;
    }
    
    OneBranchComponent::~OneBranchComponent() {
        cleanUpRelations();
    }
    
    void OneBranchComponent::cleanUpRelations() {
        if(branches != NULL)
            {
                branches = NULL;
            }
    }
    
    OneBranchComponent::OneBranchComponent(Branch* newBranch) {
        branches = NULL;
        //#[ operation OneBranchComponent(Branch)
        branches = newBranch;
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\OneBranchComponent.cpp
*********************************************************************/
