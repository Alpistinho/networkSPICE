#include "FourTerminalsComponent.h"
#include "Node.h"

namespace Spice {

    FourTerminalsComponent::FourTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey) : Component(newValue, newKey) {
        {
            for (int pos = 0; pos < 4; pos++) {
            	nodes[pos] = NULL;
            }
        }
        nodes[0] = newNodes[0];
        nodes[1] = newNodes[1];
        nodes[2] = newNodes[2];
        nodes[3] = newNodes[3];
        
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