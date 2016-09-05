/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::CurrentControlledCurrentSource
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\CurrentControlledCurrentSource.h
*********************************************************************/

#ifndef CurrentControlledCurrentSource_H
#define CurrentControlledCurrentSource_H

//## auto_generated
#include "Spice.h"
//## class CurrentControlledCurrentSource
#include "FourTerminalsComponent.h"
//## class CurrentControlledCurrentSource
#include "OneBranchComponent.h"
//## auto_generated

namespace Spice {
    //## auto_generated
    class Branch;
    
    //## auto_generated
    class Node;
    
    //## package Spice
    
    //## class CurrentControlledCurrentSource
    class CurrentControlledCurrentSource : public FourTerminalsComponent, public OneBranchComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation CurrentControlledCurrentSource(Node,Branch,double,unsigned long)
        CurrentControlledCurrentSource(Node** newNodes, Branch* newBranch, double value, unsigned long newKey);
        
        //## auto_generated
        CurrentControlledCurrentSource();
        
        //## auto_generated
        virtual ~CurrentControlledCurrentSource();
        
        ////    Operations    ////
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\CurrentControlledCurrentSource.h
*********************************************************************/
