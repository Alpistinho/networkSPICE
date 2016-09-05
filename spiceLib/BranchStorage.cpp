/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::BranchStorage
//!	Generated Date	: Thu, 10, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\BranchStorage.cpp
*********************************************************************/

//## auto_generated
#include "BranchStorage.h"
//## operation addBranch(unsigned long)
#include "Branch.h"
namespace Spice {
    //## package Spice
    
    //## class BranchStorage
    BranchStorage::BranchStorage() {
    }
    
    BranchStorage::~BranchStorage() {
    }
    
    Branch* BranchStorage::addBranch(unsigned long identifier) {
        //#[ operation addBranch(unsigned long)
        std::map<unsigned long, Branch*>::iterator it;
        
        it = branchMap.find(identifier);
        if (it != branchMap.end()) { //found the node
        	return it->second; //return existing Node
        } else {
        	Branch* newBranch = new Branch(identifier);
        	branchMap[identifier] = newBranch;
        	return newBranch;
        }
        
        //#]
    }
    
    void BranchStorage::allocateBranchNumbers(unsigned long firstPosition) {
        //#[ operation allocateBranchNumbers(unsigned long)
        unsigned long matrixPosition = firstPosition + 1;
        
        std::map<unsigned long, Branch*>::iterator it;
        
        for(it = branchMap.begin(); it != branchMap.end(); it++) {
        	it->second->setBranchNumber(matrixPosition);
        	matrixPosition++;
        }
        return;
        //#]
    }
    
    unsigned long BranchStorage::getBranchAmount() {
        //#[ operation getBranchAmount()
        return branchMap.size();
        //#]
    }
    
    std::map<unsigned long, Branch*> BranchStorage::getBranchMap() const {
        return branchMap;
    }
    
    void BranchStorage::setBranchMap(std::map<unsigned long, Branch*> p_branchMap) {
        branchMap = p_branchMap;
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\BranchStorage.cpp
*********************************************************************/
