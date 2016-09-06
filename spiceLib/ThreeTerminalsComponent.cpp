#include "ThreeTerminalsComponent.h"
#include "Node.h"

namespace Spice {

    
    ThreeTerminalsComponent::ThreeTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey) : Component(newValue, newKey) {
        {
            for (int pos = 0; pos < 3; pos++) {
            	nodes[pos] = NULL;
            }
        }
        nodes[0] = newNodes[0];
        nodes[1] = newNodes[1];
        nodes[2] = newNodes[2];
        
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

