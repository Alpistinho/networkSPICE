#ifndef CurrentSource_H
#define CurrentSource_H

#include <string>

#include <algorithm>

#include "Spice.h"
#include "IndependentSource.h"

namespace Spice {
    
    class Node;
    

    class CurrentSource : public IndependentSource {
        
    public :
    
        CurrentSource(Node** newNodes, int current, int phase, unsigned long newKey);
        
        
        CurrentSource();
        
        
        virtual ~CurrentSource();
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
                
        
        std::complex<double> getValue() const;
            
    protected :
    
        std::complex<double> value;	
    
    public :
    
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime);
    };
}

#endif
