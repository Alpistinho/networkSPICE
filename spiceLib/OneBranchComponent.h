#ifndef OneBranchComponent_H
#define OneBranchComponent_H

#include <string>
#include <algorithm>

#include "Spice.h"

namespace Spice {
    class Branch;
    

    
    class OneBranchComponent {

        
    public :
        
        OneBranchComponent(Branch* newBranch);

        OneBranchComponent();
        
        ~OneBranchComponent();
    
    protected :
    
        void cleanUpRelations();
                
        Branch* branches;
    
        
    };
}

#endif