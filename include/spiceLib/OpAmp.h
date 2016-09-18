#ifndef OpAmp_H
#define OpAmp_H

#include "Spice.h"
#include "FourTerminalsComponent.h"
#include "OneBranchComponent.h"


namespace Spice {
    
    class Branch;
    
    class Node;
    
    
    class OpAmp : public FourTerminalsComponent, public OneBranchComponent {

        
    public :
    
        OpAmp(Node** newNodes, Branch* newBranch, unsigned long newKey);
        
        
        OpAmp();
        
        
        virtual ~OpAmp();
        
        
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif