/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::OneBranchComponent
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\OneBranchComponent.h
*********************************************************************/

#ifndef OneBranchComponent_H
#define OneBranchComponent_H

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
    //## operation OneBranchComponent(Branch)
    class Branch;
    
    //## package Spice
    
    //## class OneBranchComponent
    class OneBranchComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## auto_generated
        OneBranchComponent();
        
        //## auto_generated
        ~OneBranchComponent();
        
        ////    Additional operations    ////
    
    protected :
    
        //## auto_generated
        void cleanUpRelations();
        
        ////    Relations and components    ////
        
        Branch* branches;		//## link branches
    
    public :
    
        //## operation OneBranchComponent(Branch)
        OneBranchComponent(Branch* newBranch);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\OneBranchComponent.h
*********************************************************************/
