/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Resistor
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Resistor.h
*********************************************************************/

#ifndef Resistor_H
#define Resistor_H

//## auto_generated
#include "Spice.h"
//## class Resistor
#include "TwoTerminalsComponent.h"
//## auto_generated

namespace Spice {
    //## auto_generated
    class Node;
    
    //## package Spice
    
    //## class Resistor
    class Resistor : public TwoTerminalsComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation Resistor(Node,double,unsigned long)
        Resistor(Node** newNodes, double value, unsigned long newKey);
        
        //## auto_generated
        Resistor();
        
        //## auto_generated
        virtual ~Resistor();
        
        ////    Operations    ////
        
        //## operation getComponentType()
        virtual ComponentType getComponentType();
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Resistor.h
*********************************************************************/
