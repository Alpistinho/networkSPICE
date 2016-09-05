/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::FourTerminalsComponent
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\FourTerminalsComponent.cpp
*********************************************************************/

//## auto_generated
#include "FourTerminalsComponent.h"
//## operation FourTerminalsComponent(Node,double,unsigned long)
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class FourTerminalsComponent
    FourTerminalsComponent::FourTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey) : Component(newValue, newKey) {
        {
            for (int pos = 0; pos < 4; pos++) {
            	nodes[pos] = NULL;
            }
        }
        //#[ operation FourTerminalsComponent(Node,double,unsigned long)
        nodes[0] = newNodes[0];
        nodes[1] = newNodes[1];
        nodes[2] = newNodes[2];
        nodes[3] = newNodes[3];
        //#]
    }
    
    FourTerminalsComponent::FourTerminalsComponent() {
        {
            for (int pos = 0; pos < 4; pos++) {
            	nodes[pos] = NULL;
            }
        }
    }
    
    FourTerminalsComponent::~FourTerminalsComponent() {
        cleanUpRelations();
    }
    
    void FourTerminalsComponent::cleanUpRelations() {
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\FourTerminalsComponent.cpp
*********************************************************************/
