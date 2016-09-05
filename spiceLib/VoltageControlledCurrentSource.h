/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::VoltageControlledCurrentSource
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\VoltageControlledCurrentSource.h
*********************************************************************/

#ifndef VoltageControlledCurrentSource_H
#define VoltageControlledCurrentSource_H

//## auto_generated
#include "Spice.h"
//## class VoltageControlledCurrentSource
#include "FourTerminalsComponent.h"
//## auto_generated

namespace Spice {
    //## auto_generated
    class Node;
    
    //## package Spice
    
    //## class VoltageControlledCurrentSource
    class VoltageControlledCurrentSource : public FourTerminalsComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation VoltageControlledCurrentSource(Node,double,unsigned long)
        VoltageControlledCurrentSource(Node** newNodes, double value, unsigned long newKey);
        
        //## auto_generated
        VoltageControlledCurrentSource();
        
        //## auto_generated
        virtual ~VoltageControlledCurrentSource();
        
        ////    Operations    ////
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\VoltageControlledCurrentSource.h
*********************************************************************/
