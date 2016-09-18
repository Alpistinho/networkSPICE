#ifndef TwoBranchesComponent_H
#define TwoBranchesComponent_H

#include <string>
#include <algorithm>

#include "Spice.h"

namespace Spice {

    class Branch;
    
    class TwoBranchesComponent {

        
    public :
    
        TwoBranchesComponent(Branch** newBranches);
        
        
        TwoBranchesComponent();
        
        
        ~TwoBranchesComponent();
        

    
    protected :
    
        
        void cleanUpRelations();
        
        
        Branch* branches[2];
    };
}

#endif