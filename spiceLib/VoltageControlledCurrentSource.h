#ifndef VoltageControlledCurrentSource_H
#define VoltageControlledCurrentSource_H


#include "Spice.h"
#include "FourTerminalsComponent.h"


namespace Spice {
    
    class Node;
    

    
    class VoltageControlledCurrentSource : public FourTerminalsComponent {

        
    public :
    
        VoltageControlledCurrentSource(Node** newNodes, double value, unsigned long newKey);
        
        
        VoltageControlledCurrentSource();
        
        
        virtual ~VoltageControlledCurrentSource();
        
        
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif