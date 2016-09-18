#include "TwoTerminalsComponent.h"
#include "Node.h"

namespace Spice {

    
    TwoTerminalsComponent::TwoTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey) : Component(newValue, newKey) {
        {
            for (int pos = 0; pos < 2; pos++) {
            	nodes[pos] = NULL;
            }
        }
        nodes[0] = newNodes[0];
        nodes[1] = newNodes[1];
        
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