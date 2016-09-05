/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::NodeStorage
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\NodeStorage.h
*********************************************************************/

#ifndef NodeStorage_H
#define NodeStorage_H

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
//## class NodeStorage
#include "Storage.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## operation addNode(std::string)
    class Node;
}


//////////////

namespace Spice {
    //## package Spice
    
    //## class NodeStorage
    class NodeStorage : public Storage {
        ////    Constructors and destructors    ////
        
    public :
    
        //## auto_generated
        NodeStorage();
        
        //## auto_generated
        ~NodeStorage();
        
        ////    Operations    ////
        
        //## operation addNode(std::string)
        Node* addNode(std::string identifier);
        
        //## operation allocateNodeNumbers()
        unsigned long allocateNodeNumbers();
        
        //## operation getNodeAmount()
        unsigned long getNodeAmount();
        
        ////    Additional operations    ////
    
    private :
    
        //## auto_generated
        std::map<std::string, Node*> getNodeMap() const;
        
        //## auto_generated
        void setNodeMap(std::map<std::string, Node*> p_nodeMap);
        
        ////    Attributes    ////
    
    protected :
    
        std::map<std::string, Node*> nodeMap;		//## attribute nodeMap
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\NodeStorage.h
*********************************************************************/
