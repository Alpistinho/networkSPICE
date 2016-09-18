/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Component
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Component.h
*********************************************************************/

#ifndef Component_H
#define Component_H

namespace Spice {
    //#[ ignore
    #ifdef _MSC_VER
    // disable Microsoft compiler warning (debug information truncated)
    #pragma warning(disable: 4786)
    #endif
    
}


#include "Spice.h"

//

#include <string>

#include <algorithm>
namespace Spice {

    class Component {

    public :
    

        Component(double newValue, unsigned long newKey);

        Component();

        virtual ~Component();
        
        virtual ComponentType getComponentType();
        
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);

        unsigned long getKey() const;

        double getValue() const;

    protected :
    
        unsigned long key;
        
        double value;
    };
}

#endif