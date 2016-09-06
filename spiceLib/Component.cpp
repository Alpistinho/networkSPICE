/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Component
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Component.cpp
*********************************************************************/


#include "Component.h"
namespace Spice {

    
    //## class Component
    Component::Component(double newValue, unsigned long newKey) : key(newKey), value(newValue) {
        //#[ operation Component(double,unsigned long)
        
    }
    
    Component::Component() {
    }
    
    Component::~Component() {
    }
    
    ComponentType Component::getComponentType() {
        //#[ operation getComponentType()
        return Undefined;
        
    }
    
    void Component::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        
    }
    
    void Component::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        
    }
    
    unsigned long Component::getKey() const {
        return key;
    }
    
    double Component::getValue() const {
        return value;
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Component.cpp
*********************************************************************/
