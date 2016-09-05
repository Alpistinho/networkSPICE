/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::CurrentControlledVoltageSource
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\CurrentControlledVoltageSource.h
*********************************************************************/

#ifndef CurrentControlledVoltageSource_H
#define CurrentControlledVoltageSource_H

//## auto_generated
#include "Spice.h"
//## class CurrentControlledVoltageSource
#include "FourTerminalsComponent.h"
//## class CurrentControlledVoltageSource
#include "TwoBranchesComponent.h"
//## auto_generated

namespace Spice {
    //## auto_generated
    class Branch;
    
    //## auto_generated
    class Node;
    
    //## package Spice
    
    //## class CurrentControlledVoltageSource
    class CurrentControlledVoltageSource : public FourTerminalsComponent, public TwoBranchesComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation CurrentControlledVoltageSource(Node,Branch,double,unsigned long)
        CurrentControlledVoltageSource(Node** newNodes, Branch** newBranches, double value, unsigned long newKey);
        
        //## auto_generated
        CurrentControlledVoltageSource();
        
        //## auto_generated
        virtual ~CurrentControlledVoltageSource();
        
        ////    Operations    ////
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\CurrentControlledVoltageSource.h
*********************************************************************/
