/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::FourTerminalsComponent
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\FourTerminalsComponent.h
*********************************************************************/

#ifndef FourTerminalsComponent_H
#define FourTerminalsComponent_H

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
//## class FourTerminalsComponent
#include "Component.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## operation FourTerminalsComponent(Node,double,unsigned long)
    class Node;
    
    //## package Spice
    
    //## class FourTerminalsComponent
    class FourTerminalsComponent : public Component {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation FourTerminalsComponent(Node,double,unsigned long)
        FourTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey);
        
        //## auto_generated
        FourTerminalsComponent();
        
        //## auto_generated
        ~FourTerminalsComponent();
        
        ////    Additional operations    ////
    
    protected :
    
        //## auto_generated
        void cleanUpRelations();
        
        ////    Relations and components    ////
        
        Node* nodes[4];		//## link nodes
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\FourTerminalsComponent.h
*********************************************************************/
