#ifndef CurrentControlledVoltageSource_H
#define CurrentControlledVoltageSource_H

#include "Spice.h"
#include "FourTerminalsComponent.h"
#include "TwoBranchesComponent.h"


namespace Spice {
    
    class Branch;
    
    
    class Node;
    

    class CurrentControlledVoltageSource : public FourTerminalsComponent, public TwoBranchesComponent {
        
    public :
    
        CurrentControlledVoltageSource(Node** newNodes, Branch** newBranches, double value, unsigned long newKey);
        
        
        CurrentControlledVoltageSource();
        
        
        virtual ~CurrentControlledVoltageSource();
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif