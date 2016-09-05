/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::NodeStorage
//!	Generated Date	: Thu, 10, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\NodeStorage.cpp
*********************************************************************/

//## auto_generated
#include "NodeStorage.h"
//## operation addNode(std::string)
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class NodeStorage
    NodeStorage::NodeStorage() {
    }
    
    NodeStorage::~NodeStorage() {
    }
    
    Node* NodeStorage::addNode(std::string identifier) {
        //#[ operation addNode(std::string)
        std::map<std::string, Node*>::iterator it;
        
        it = nodeMap.find(identifier);
        if (it != nodeMap.end()) { //found the node
        	return it->second; //return existing Node
        } else {
        	Node* newNode = new Node(identifier);
        	nodeMap[identifier] = newNode;
        	return newNode;
        }
        //#]
    }
    
    unsigned long NodeStorage::allocateNodeNumbers() {
        //#[ operation allocateNodeNumbers()
        unsigned long matrixPosition = 1; // the 0 is always the ground
        
        std::map<std::string, Node*>::iterator it;
        
        for(it = nodeMap.begin(); it != nodeMap.end(); it++) {
        	if(!(it->first.compare("0"))) {
        		it->second->setNodeNumber(0);
        	} else {
        		it->second->setNodeNumber(matrixPosition);
        		matrixPosition++;
        	}
        }
        return matrixPosition - 1;//the for iterates one time too much
        //#]
    }
    
    unsigned long NodeStorage::getNodeAmount() {
        //#[ operation getNodeAmount()
        return nodeMap.size(); 
        //#]
    }
    
    std::map<std::string, Node*> NodeStorage::getNodeMap() const {
        return nodeMap;
    }
    
    void NodeStorage::setNodeMap(std::map<std::string, Node*> p_nodeMap) {
        nodeMap = p_nodeMap;
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\NodeStorage.cpp
*********************************************************************/
