#ifndef VoltageControlledVoltageSource_H
#define VoltageControlledVoltageSource_H


#include "Spice.h"
#include "FourTerminalsComponent.h"
#include "OneBranchComponent.h"


namespace Spice {
    
    class Branch;
    
    
    class Node;
    
    class VoltageControlledVoltageSource : public FourTerminalsComponent, public OneBranchComponent {

        
    public :
    
        VoltageControlledVoltageSource(Node** newNodes, Branch* newBranch, double value, unsigned long newKey);
        
        
        VoltageControlledVoltageSource();
        
        
        virtual ~VoltageControlledVoltageSource();
        
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif