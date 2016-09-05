/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Simulation
//!	Generated Date	: Thu, 10, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Simulation.cpp
*********************************************************************/

//## auto_generated
#include "Simulation.h"
namespace Spice {
    //## package Spice
    
    //## class Simulation
    Simulation::Simulation() {
        tolerance = 1e-12;
    }
    
    Simulation::~Simulation() {
    }
    
    double Simulation::getTolerance() const {
        return tolerance;
    }
    
    void Simulation::setTolerance(double p_tolerance) {
        tolerance = p_tolerance;
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Simulation.cpp
*********************************************************************/
