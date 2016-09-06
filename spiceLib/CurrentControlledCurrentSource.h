#ifndef CurrentControlledCurrentSource_H
#define CurrentControlledCurrentSource_H

#include "Spice.h"
#include "FourTerminalsComponent.h"
#include "OneBranchComponent.h"

namespace Spice {
        class Branch;
    
        class Node;
    
    
    class CurrentControlledCurrentSource : public FourTerminalsComponent, public OneBranchComponent {
        
    public :
    
        CurrentControlledCurrentSource(Node** newNodes, Branch* newBranch, double value, unsigned long newKey);
        
        CurrentControlledCurrentSource();
        
        virtual ~CurrentControlledCurrentSource();
        
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif