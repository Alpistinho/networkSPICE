/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::ThreeTerminalsComponent
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\ThreeTerminalsComponent.h
*********************************************************************/

#ifndef ThreeTerminalsComponent_H
#define ThreeTerminalsComponent_H

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
//## class ThreeTerminalsComponent
#include "Component.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## operation ThreeTerminalsComponent(Node,double,unsigned long)
    class Node;
    
    //## package Spice
    
    //## class ThreeTerminalsComponent
    class ThreeTerminalsComponent : public Component {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation ThreeTerminalsComponent(Node,double,unsigned long)
        ThreeTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey);
        
        //## auto_generated
        ThreeTerminalsComponent();
        
        //## auto_generated
        ~ThreeTerminalsComponent();
        
        ////    Additional operations    ////
    
    protected :
    
        //## auto_generated
        void cleanUpRelations();
        
        ////    Relations and components    ////
        
        Node* nodes[3];		//## link nodes
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\ThreeTerminalsComponent.h
*********************************************************************/
