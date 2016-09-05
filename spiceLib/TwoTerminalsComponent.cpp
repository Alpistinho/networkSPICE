/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::TwoTerminalsComponent
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\TwoTerminalsComponent.cpp
*********************************************************************/

//## auto_generated
#include "TwoTerminalsComponent.h"
//## operation TwoTerminalsComponent(Node,double,unsigned long)
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class TwoTerminalsComponent
    TwoTerminalsComponent::TwoTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey) : Component(newValue, newKey) {
        {
            for (int pos = 0; pos < 2; pos++) {
            	nodes[pos] = NULL;
            }
        }
        //#[ operation TwoTerminalsComponent(Node,double,unsigned long)
        nodes[0] = newNodes[0];
        nodes[1] = newNodes[1];
        //#]
    }
    
    TwoTerminalsComponent::TwoTerminalsComponent() {
        {
            for (int pos = 0; pos < 2; pos++) {
            	nodes[pos] = NULL;
            }
        }
    }
    
    TwoTerminalsComponent::~TwoTerminalsComponent() {
        cleanUpRelations();
    }
    
    void TwoTerminalsComponent::cleanUpRelations() {
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\TwoTerminalsComponent.cpp
*********************************************************************/
