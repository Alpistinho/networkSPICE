#ifndef Spice_H
#define Spice_H

#include <vector>
#include <complex>
#include <map>
#include <string>
#include <algorithm>

namespace Spice {
    
    class BJT;
    
    
    class Branch;
    
    
    class BranchStorage;
    
    
    class Capacitor;
    
    
    class CircuitElement;
    
    
    class Component;
    
    
    class ComponentStorage;
    
    
    class CurrentControlledCurrentSource;
    
    
    class CurrentControlledVoltageSource;
    
    
    class CurrentSource;
    
    
    class FileManager;
    
    
    class FourTerminalsComponent;
    
    
    class FrequencySimulation;
    
    
    class IndependentSource;
    
    
    class Inductor;
    
    
    class Node;
    
    
    class NodeStorage;
    
    
    class OneBranchComponent;
    
    
    class OpAmp;
    
    
    class Resistor;
    
    
    class Simulation;
    
    
    class Storage;
    
    
    class ThreeTerminalsComponent;
    
    
    class TransientSimulation;
    
    
    class TwoBranchesComponent;
    
    
    class TwoTerminalsComponent;
    
    
    class VoltageControlledCurrentSource;
    
    
    class VoltageControlledVoltageSource;
    
    
    class VoltageSource;
    

    enum ComponentType {
        Undefined,
        TypeResistor,
        TypeVoltageSource
    };
    
    enum SourceType {
        DC,
        Step,
        Sinusoidal,
        Square
    };
}

#endif