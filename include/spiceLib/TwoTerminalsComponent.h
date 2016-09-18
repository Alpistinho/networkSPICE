#ifndef TwoTerminalsComponent_H
#define TwoTerminalsComponent_H


#include <string>
#include <algorithm>

#include "Spice.h"
#include "Component.h"

namespace Spice {
    class Node;
    

    class TwoTerminalsComponent : public Component {

        
    public :
    
        TwoTerminalsComponent(Node** newNodes, double newValue, unsigned long newKey);
        
        
        TwoTerminalsComponent();
        
        
        ~TwoTerminalsComponent();
        

    
    protected :
    
        
        void cleanUpRelations();
        
        
        Node* nodes[2];		//## link nodes
    };
}

#endif