#ifndef Resistor_H
#define Resistor_H

#include "Spice.h"
#include "TwoTerminalsComponent.h"


namespace Spice {
    
    class Node;
    
    class Resistor : public TwoTerminalsComponent {

        
    public :
    
        Resistor(Node** newNodes, double value, unsigned long newKey);
        
        Resistor();
        
        virtual ~Resistor();

        
        virtual ComponentType getComponentType();
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif