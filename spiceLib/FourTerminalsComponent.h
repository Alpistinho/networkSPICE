#ifndef FourTerminalsComponent_H
#define FourTerminalsComponent_H

#include <string>
#include <algorithm>

#include "Spice.h"
#include "Component.h"

namespace Spice {
    class Node;
 
    class FourTerminalsComponent : public Component {
        
    public :
    
        FourTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey);
        
        
        FourTerminalsComponent();
        
        
        ~FourTerminalsComponent();
           
    protected :
    
        
        void cleanUpRelations();
                
        Node* nodes[4];		//## link nodes
    };
}

#endif