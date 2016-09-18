
#include "Branch.h"
namespace Spice {

    Branch::Branch(unsigned long branchIdentifier) : identifier(branchIdentifier) {

    }
    
    Branch::Branch() {
    }
    
    Branch::~Branch() {
    }
    
    unsigned long Branch::getBranchNumber() const {
        return branchNumber;
    }
    
    void Branch::setBranchNumber(unsigned long p_branchNumber) {
        branchNumber = p_branchNumber;
    }
}

