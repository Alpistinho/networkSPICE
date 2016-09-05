/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Branch
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Branch.h
*********************************************************************/

#ifndef Branch_H
#define Branch_H

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
//## class Branch
#include "CircuitElement.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## package Spice
    
    //## class Branch
    class Branch : public CircuitElement {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation Branch(unsigned long)
        Branch(unsigned long branchIdentifier);
        
        //## auto_generated
        Branch();
        
        //## auto_generated
        ~Branch();
        
        ////    Additional operations    ////
        
        //## auto_generated
        unsigned long getBranchNumber() const;
        
        //## auto_generated
        void setBranchNumber(unsigned long p_branchNumber);
        
        ////    Attributes    ////
    
    protected :
    
        unsigned long branchNumber;		//## attribute branchNumber
        
        unsigned long identifier;		//## attribute identifier
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Branch.h
*********************************************************************/
