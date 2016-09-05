/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Spice.h
*********************************************************************/

#ifndef Spice_H
#define Spice_H

namespace Spice {
    //#[ ignore
    #ifdef _MSC_VER
    // disable Microsoft compiler warning (debug information truncated)
    #pragma warning(disable: 4786)
    #endif
    //#]
}

//## auto_generated
#include <vector>
//## auto_generated
#include <complex>
//## auto_generated
#include <map>
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
//## auto_generated
//
namespace Spice {
    //## auto_generated
    class BJT;
    
    //## auto_generated
    class Branch;
    
    //## auto_generated
    class BranchStorage;
    
    //## auto_generated
    class Capacitor;
    
    //## auto_generated
    class CircuitElement;
    
    //## auto_generated
    class Component;
    
    //## auto_generated
    class ComponentStorage;
    
    //## auto_generated
    class CurrentControlledCurrentSource;
    
    //## auto_generated
    class CurrentControlledVoltageSource;
    
    //## auto_generated
    class CurrentSource;
    
    //## auto_generated
    class FileManager;
    
    //## auto_generated
    class FourTerminalsComponent;
    
    //## auto_generated
    class FrequencySimulation;
    
    //## auto_generated
    class IndependentSource;
    
    //## auto_generated
    class Inductor;
    
    //## auto_generated
    class Node;
    
    //## auto_generated
    class NodeStorage;
    
    //## auto_generated
    class OneBranchComponent;
    
    //## auto_generated
    class OpAmp;
    
    //## auto_generated
    class Resistor;
    
    //## auto_generated
    class Simulation;
    
    //## auto_generated
    class Storage;
    
    //## auto_generated
    class ThreeTerminalsComponent;
    
    //## auto_generated
    class TransientSimulation;
    
    //## auto_generated
    class TwoBranchesComponent;
    
    //## auto_generated
    class TwoTerminalsComponent;
    
    //## auto_generated
    class VoltageControlledCurrentSource;
    
    //## auto_generated
    class VoltageControlledVoltageSource;
    
    //## auto_generated
    class VoltageSource;
    
    //## package Spice
    
    
    //## type ComponentType
    enum ComponentType {
        Undefined,
        TypeResistor,
        TypeVoltageSource
    };
    
    //## type SourceType
    enum SourceType {
        DC,
        Step,
        Sinusoidal,
        Square
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Spice.h
*********************************************************************/
