#ifndef VoltageSource_H
#define VoltageSource_H

#include <string>
#include <algorithm>

#include "Spice.h"
#include "OneBranchComponent.h"
#include "IndependentSource.h"

namespace Spice {
    
    class Branch;
    
    class Node;
    
    class VoltageSource : public OneBranchComponent, public IndependentSource {

        
    public :
    
        
        VoltageSource();
        
        
        virtual ~VoltageSource();
        
        
        
        virtual ComponentType getComponentType();
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        

        
        
        std::complex<double> getValue() const;
        
       
    
    protected :
    
        std::complex<double> value;		//## attribute value
    
    public :
    
        VoltageSource(Node** newNodes, Branch* newBranches, double voltage, int phase, unsigned long newKey);
        
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime);
    };
}

#endif