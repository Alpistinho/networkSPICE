/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::VoltageSource
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\VoltageSource.h
*********************************************************************/

#ifndef VoltageSource_H
#define VoltageSource_H

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
//## class VoltageSource
#include "OneBranchComponent.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
//## class VoltageSource
#include "IndependentSource.h"
namespace Spice {
    //## auto_generated
    class Branch;
    
    //## auto_generated
    class Node;
    
    //## package Spice
    
    //## class VoltageSource
    class VoltageSource : public OneBranchComponent, public IndependentSource {
        ////    Constructors and destructors    ////
        
    public :
    
        //## auto_generated
        VoltageSource();
        
        //## auto_generated
        virtual ~VoltageSource();
        
        ////    Operations    ////
        
        //## operation getComponentType()
        virtual ComponentType getComponentType();
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        ////    Additional operations    ////
        
        //## auto_generated
        std::complex<double> getValue() const;
        
        ////    Attributes    ////
    
    protected :
    
        std::complex<double> value;		//## attribute value
    
    public :
    
        //## operation VoltageSource(Node,Branch,double,int,unsigned long)
        VoltageSource(Node** newNodes, Branch* newBranches, double voltage, int phase, unsigned long newKey);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\VoltageSource.h
*********************************************************************/
