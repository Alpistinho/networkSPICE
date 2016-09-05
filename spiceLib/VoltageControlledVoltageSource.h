/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::VoltageControlledVoltageSource
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\VoltageControlledVoltageSource.h
*********************************************************************/

#ifndef VoltageControlledVoltageSource_H
#define VoltageControlledVoltageSource_H

//## auto_generated
#include "Spice.h"
//## class VoltageControlledVoltageSource
#include "FourTerminalsComponent.h"
//## class VoltageControlledVoltageSource
#include "OneBranchComponent.h"
//## auto_generated

namespace Spice {
    //## auto_generated
    class Branch;
    
    //## auto_generated
    class Node;
    
    //## package Spice
    
    //## class VoltageControlledVoltageSource
    class VoltageControlledVoltageSource : public FourTerminalsComponent, public OneBranchComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation VoltageControlledVoltageSource(Node,Branch,double,unsigned long)
        VoltageControlledVoltageSource(Node** newNodes, Branch* newBranch, double value, unsigned long newKey);
        
        //## auto_generated
        VoltageControlledVoltageSource();
        
        //## auto_generated
        virtual ~VoltageControlledVoltageSource();
        
        ////    Operations    ////
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\VoltageControlledVoltageSource.h
*********************************************************************/
