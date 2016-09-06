#ifndef NodeStorage_H
#define NodeStorage_H

#include <string>
#include <algorithm>

#include "Spice.h"
#include "Storage.h"


namespace Spice {
    class Node;
}

namespace Spice {

    
    class NodeStorage : public Storage {

        
    public :
    
        
        NodeStorage();
        
        
        ~NodeStorage();
        
        
        
        Node* addNode(std::string identifier);
        
        unsigned long allocateNodeNumbers();
        
        unsigned long getNodeAmount();
        

    
    private :
    
        
        std::map<std::string, Node*> getNodeMap() const;
        
        
        void setNodeMap(std::map<std::string, Node*> p_nodeMap);
        
       
    
    protected :
    
        std::map<std::string, Node*> nodeMap;
    };
}

#endif