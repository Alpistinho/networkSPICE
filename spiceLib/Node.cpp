/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Node
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Node.cpp
*********************************************************************/

//## auto_generated
#include "Node.h"
//## operation addComponent(Component)
#include "Component.h"
namespace Spice {
    //## package Spice
    
    //## class Node
    Node::Node(std::string nodeIdentifier) : identifier(nodeIdentifier) {
        //#[ operation Node(std::string)
        //#]
    }
    
    Node::Node() {
    }
    
    Node::~Node() {
    }
    
    void Node::setNodeNumber(unsigned long position) {
        //#[ operation setNodeNumber(unsigned long)
        nodeNumber = position;
        //#]
    }
    
    std::map<unsigned long, Component*> Node::getComponentMap() const {
        return componentMap;
    }
    
    void Node::setComponentMap(std::map<unsigned long, Component*> p_componentMap) {
        componentMap = p_componentMap;
    }
    
    std::string Node::getIdentifier() const {
        return identifier;
    }
    
    void Node::setIdentifier(std::string p_identifier) {
        identifier = p_identifier;
    }
    
    unsigned long Node::getNodeNumber() const {
        return nodeNumber;
    }
    
    void Node::addComponent(const Component* component) {
        //#[ operation addComponent(Component)
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Node.cpp
*********************************************************************/
