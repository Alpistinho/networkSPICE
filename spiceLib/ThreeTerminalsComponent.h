#ifndef ThreeTerminalsComponent_H
#define ThreeTerminalsComponent_H

#include <string>
#include <algorithm>

#include "Spice.h"
#include "Component.h"

namespace Spice {

    class Node;
    
    class ThreeTerminalsComponent : public Component {

        
    public :
    
        ThreeTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey);
        
        ThreeTerminalsComponent();
        
        ~ThreeTerminalsComponent();
        

    
    protected :
    
        
        void cleanUpRelations();
                
        Node* nodes[3];		
    };
}

#endif