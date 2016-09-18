#ifndef Inductor_H
#define Inductor_H


#include <string>
#include <algorithm>

#include "Spice.h"
#include "OneBranchComponent.h"
#include "TwoTerminalsComponent.h"


namespace Spice {
    
    class Branch;
    
    class Node;
    
    class Inductor : public TwoTerminalsComponent, public OneBranchComponent {

        
    public :
    
        Inductor(Node** newNodes, Branch* newBranches, double value, unsigned long newKey);
        
        Inductor();
        
        virtual ~Inductor();
        
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif
