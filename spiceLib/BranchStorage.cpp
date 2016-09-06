
#include "BranchStorage.h"

#include "Branch.h"
namespace Spice {

    BranchStorage::BranchStorage() {
    }
    
    BranchStorage::~BranchStorage() {
    }
    
    Branch* BranchStorage::addBranch(unsigned long identifier) {

        std::map<unsigned long, Branch*>::iterator it;
        
        it = branchMap.find(identifier);
        if (it != branchMap.end()) { //found the node
        	return it->second; //return existing Node
        } else {
        	Branch* newBranch = new Branch(identifier);
        	branchMap[identifier] = newBranch;
        	return newBranch;
        }
        
        
    }
    
    void BranchStorage::allocateBranchNumbers(unsigned long firstPosition) {

        unsigned long matrixPosition = firstPosition + 1;
        
        std::map<unsigned long, Branch*>::iterator it;
        
        for(it = branchMap.begin(); it != branchMap.end(); it++) {
        	it->second->setBranchNumber(matrixPosition);
        	matrixPosition++;
        }
        return;
        
    }
    
    unsigned long BranchStorage::getBranchAmount() {

        return branchMap.size();

    }
    
    std::map<unsigned long, Branch*> BranchStorage::getBranchMap() const {
        return branchMap;
    }
    
    void BranchStorage::setBranchMap(std::map<unsigned long, Branch*> p_branchMap) {
        branchMap = p_branchMap;
    }
}
