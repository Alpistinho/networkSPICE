/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Resistor
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Resistor.cpp
*********************************************************************/

//## auto_generated
#include "Resistor.h"
//## auto_generated
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class Resistor
    Resistor::Resistor(Node** newNodes, double value, unsigned long newKey) : TwoTerminalsComponent(newNodes, value, newKey) {
        //#[ operation Resistor(Node,double,unsigned long)
        //#]
    }
    
    Resistor::Resistor() {
    }
    
    Resistor::~Resistor() {
    }
    
    ComponentType Resistor::getComponentType() {
        //#[ operation getComponentType()
        return TypeResistor;
        //#]
    }
    
    void Resistor::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += 1/value;
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] -= 1/value;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -= 1/value;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] += 1/value;
        //#]
    }
    
    void Resistor::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*)
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += 1/value;
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] -= 1/value;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -= 1/value;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] += 1/value;
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Resistor.cpp
*********************************************************************/
