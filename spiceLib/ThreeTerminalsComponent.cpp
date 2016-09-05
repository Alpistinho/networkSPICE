/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::ThreeTerminalsComponent
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\ThreeTerminalsComponent.cpp
*********************************************************************/

//## auto_generated
#include "ThreeTerminalsComponent.h"
//## operation ThreeTerminalsComponent(Node,double,unsigned long)
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class ThreeTerminalsComponent
    ThreeTerminalsComponent::ThreeTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey) : Component(newValue, newKey) {
        {
            for (int pos = 0; pos < 3; pos++) {
            	nodes[pos] = NULL;
            }
        }
        //#[ operation ThreeTerminalsComponent(Node,double,unsigned long)
        nodes[0] = newNodes[0];
        nodes[1] = newNodes[1];
        nodes[2] = newNodes[2];
        //#]
    }
    
    ThreeTerminalsComponent::ThreeTerminalsComponent() {
        {
            for (int pos = 0; pos < 3; pos++) {
            	nodes[pos] = NULL;
            }
        }
    }
    
    ThreeTerminalsComponent::~ThreeTerminalsComponent() {
        cleanUpRelations();
    }
    
    void ThreeTerminalsComponent::cleanUpRelations() {
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\ThreeTerminalsComponent.cpp
*********************************************************************/
