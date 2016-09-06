
#ifndef Branch_H
#define Branch_H

#include <string>
#include <algorithm>

#include "Spice.h"
#include "CircuitElement.h"



namespace Spice {

    class Branch : public CircuitElement {
        
    public :
    
        Branch(unsigned long branchIdentifier);
        
        Branch();
        
        ~Branch();
        

        unsigned long getBranchNumber() const;
        
        void setBranchNumber(unsigned long p_branchNumber);
        
    
    protected :
    
        unsigned long branchNumber;
        
        unsigned long identifier;	
    };
}

#endif

