/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::TwoTerminalsComponent
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\TwoTerminalsComponent.h
*********************************************************************/

#ifndef TwoTerminalsComponent_H
#define TwoTerminalsComponent_H

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
//## class TwoTerminalsComponent
#include "Component.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## operation TwoTerminalsComponent(Node,double,unsigned long)
    class Node;
    
    //## package Spice
    
    //## class TwoTerminalsComponent
    class TwoTerminalsComponent : public Component {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation TwoTerminalsComponent(Node,double,unsigned long)
        TwoTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey);
        
        //## auto_generated
        TwoTerminalsComponent();
        
        //## auto_generated
        ~TwoTerminalsComponent();
        
        ////    Additional operations    ////
    
    protected :
    
        //## auto_generated
        void cleanUpRelations();
        
        ////    Relations and components    ////
        
        Node* nodes[2];		//## link nodes
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\TwoTerminalsComponent.h
*********************************************************************/
