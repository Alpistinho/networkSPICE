/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Inductor
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Inductor.h
*********************************************************************/

#ifndef Inductor_H
#define Inductor_H

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
//## class Inductor
#include "OneBranchComponent.h"
//## class Inductor
#include "TwoTerminalsComponent.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## auto_generated
    class Branch;
    
    //## auto_generated
    class Node;
    
    //## package Spice
    
    //## class Inductor
    class Inductor : public TwoTerminalsComponent, public OneBranchComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation Inductor(Node,Branch,double,unsigned long)
        Inductor(Node** newNodes, Branch* newBranches, double value, unsigned long newKey);
        
        //## auto_generated
        Inductor();
        
        //## auto_generated
        virtual ~Inductor();
        
        ////    Operations    ////
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Inductor.h
*********************************************************************/
