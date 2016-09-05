/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::OpAmp
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\OpAmp.h
*********************************************************************/

#ifndef OpAmp_H
#define OpAmp_H

//## auto_generated
#include "Spice.h"
//## class OpAmp
#include "FourTerminalsComponent.h"
//## class OpAmp
#include "OneBranchComponent.h"
//## auto_generated

namespace Spice {
    //## auto_generated
    class Branch;
    
    //## auto_generated
    class Node;
    
    //## package Spice
    
    //## class OpAmp
    class OpAmp : public FourTerminalsComponent, public OneBranchComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation OpAmp(Node,Branch,unsigned long)
        OpAmp(Node** newNodes, Branch* newBranch, unsigned long newKey);
        
        //## auto_generated
        OpAmp();
        
        //## auto_generated
        virtual ~OpAmp();
        
        ////    Operations    ////
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\OpAmp.h
*********************************************************************/
