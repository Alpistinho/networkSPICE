#ifndef Node_H
#define Node_H

#include <string>
#include <algorithm>

#include "Spice.h"
#include "CircuitElement.h"

namespace Spice {

    class Component;
    

    class Node : public CircuitElement {

        
    public :
    
        Node(std::string nodeIdentifier);
        
        Node();
        
        ~Node();

        
        void setNodeNumber(unsigned long position);
                
        std::map<unsigned long, Component*> getComponentMap() const;
        
        void setComponentMap(std::map<unsigned long, Component*> p_componentMap);    
       
        std::string getIdentifier() const;      
        
        void setIdentifier(std::string p_identifier);  
        
        unsigned long getNodeNumber() const;
        
    
    protected :
    
        std::map<unsigned long, Component*> componentMap;	
        
        std::string identifier;	

        unsigned long nodeNumber;
        
    
    public :
    
        void addComponent(const Component* component);
    };
}

#endif
