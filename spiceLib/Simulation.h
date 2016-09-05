/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Simulation
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Simulation.h
*********************************************************************/

#ifndef Simulation_H
#define Simulation_H

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
    
    //## class Simulation
    class Simulation {
        ////    Constructors and destructors    ////
        
    public :
    
        //## auto_generated
        Simulation();
        
        //## auto_generated
        ~Simulation();
        
        ////    Additional operations    ////
        
        //## auto_generated
        double getTolerance() const;
        
        //## auto_generated
        void setTolerance(double p_tolerance);
        
        ////    Attributes    ////
    
    protected :
    
        double tolerance;		//## attribute tolerance
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Simulation.h
*********************************************************************/
