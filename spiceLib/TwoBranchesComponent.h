/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::TwoBranchesComponent
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\TwoBranchesComponent.h
*********************************************************************/

#ifndef TwoBranchesComponent_H
#define TwoBranchesComponent_H

namespace Spice {
    //#[ ignore
    #ifdef _MSC_VER
    // disable Microsoft compiler warning (debug information truncated)
    #pragma warning(disable: 4786)
    #endif
    //#]
}

//## auto_generated
#include "Spice.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## operation TwoBranchesComponent(Branch)
    class Branch;
    
    //## package Spice
    
    //## class TwoBranchesComponent
    class TwoBranchesComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation TwoBranchesComponent(Branch)
        TwoBranchesComponent(Branch** newBranches);
        
        //## auto_generated
        TwoBranchesComponent();
        
        //## auto_generated
        ~TwoBranchesComponent();
        
        ////    Additional operations    ////
    
    protected :
    
        //## auto_generated
        void cleanUpRelations();
        
        ////    Relations and components    ////
        
        Branch* branches[2];		//## link branches
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\TwoBranchesComponent.h
*********************************************************************/
