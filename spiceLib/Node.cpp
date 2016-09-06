#include "Node.h"
#include "Component.h"

namespace Spice {

    
    Node::Node(std::string nodeIdentifier) : identifier(nodeIdentifier) {
        
    }
    
    Node::Node() {
    }
    
    Node::~Node() {
    }
    
    void Node::setNodeNumber(unsigned long position) {
        nodeNumber = position;
        
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
        
    }
}