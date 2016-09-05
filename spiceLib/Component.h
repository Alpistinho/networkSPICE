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
    //#]
}

//## auto_generated
#include "Spice.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## package Spice
    
    //## class Component
    class Component {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation Component(double,unsigned long)
        Component(double newValue, unsigned long newKey);
        
        //## auto_generated
        Component();
        
        //## auto_generated
        virtual ~Component();
        
        ////    Operations    ////
        
        //## operation getComponentType()
        virtual ComponentType getComponentType();
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
        
        ////    Additional operations    ////
        
        //## auto_generated
        unsigned long getKey() const;
        
        //## auto_generated
        double getValue() const;
        
        ////    Attributes    ////
    
    protected :
    
        unsigned long key;		//## attribute key
        
        double value;		//## attribute value
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Component.h
*********************************************************************/
