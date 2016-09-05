/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Node
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Node.h
*********************************************************************/

#ifndef Node_H
#define Node_H

namespace Spice {
    //#[ ignore
    #ifdef _MSC_VER
    // disable Microsoft compiler warning (debug information truncated)
    #pragma warning(disable: 4786)
    #endif
    //#]
}

//## auto_generated
#include "Spice.h"
//## class Node
#include "CircuitElement.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## operation addComponent(Component)
    class Component;
    
    //## package Spice
    
    //## class Node
    class Node : public CircuitElement {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation Node(std::string)
        Node(std::string nodeIdentifier);
        
        //## auto_generated
        Node();
        
        //## auto_generated
        ~Node();
        
        ////    Operations    ////
        
        //## operation setNodeNumber(unsigned long)
        void setNodeNumber(unsigned long position);
        
        ////    Additional operations    ////
        
        //## auto_generated
        std::map<unsigned long, Component*> getComponentMap() const;
        
        //## auto_generated
        void setComponentMap(std::map<unsigned long, Component*> p_componentMap);
        
        //## auto_generated
        std::string getIdentifier() const;
        
        //## auto_generated
        void setIdentifier(std::string p_identifier);
        
        //## auto_generated
        unsigned long getNodeNumber() const;
        
        ////    Attributes    ////
    
    protected :
    
        std::map<unsigned long, Component*> componentMap;		//## attribute componentMap
        
        std::string identifier;		//## attribute identifier
        
        unsigned long nodeNumber;		//## attribute nodeNumber
    
    public :
    
        //## operation addComponent(Component)
        void addComponent(const Component* component);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Node.h
*********************************************************************/
