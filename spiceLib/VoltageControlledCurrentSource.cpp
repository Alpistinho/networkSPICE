/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::VoltageControlledCurrentSource
//!	Generated Date	: Sun, 13, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\VoltageControlledCurrentSource.cpp
*********************************************************************/

//## auto_generated
#include "VoltageControlledCurrentSource.h"
//## auto_generated
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class VoltageControlledCurrentSource
    VoltageControlledCurrentSource::VoltageControlledCurrentSource(Node** newNodes, double value, unsigned long newKey) : FourTerminalsComponent(newNodes, value, newKey) {
        //#[ operation VoltageControlledCurrentSource(Node,double,unsigned long)
        //#]
    }
    
    VoltageControlledCurrentSource::VoltageControlledCurrentSource() {
    }
    
    VoltageControlledCurrentSource::~VoltageControlledCurrentSource() {
    }
    
    void VoltageControlledCurrentSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[0]->getNodeNumber()] += value;	
        (*equationSystem)[nodes[3]->getNodeNumber()][nodes[0]->getNodeNumber()] -= value;
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[1]->getNodeNumber()] -= value;	
        (*equationSystem)[nodes[3]->getNodeNumber()][nodes[1]->getNodeNumber()] += value;
        //#]
    }
    
    void VoltageControlledCurrentSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[0]->getNodeNumber()] += value;	
        (*equationSystem)[nodes[3]->getNodeNumber()][nodes[0]->getNodeNumber()] -= value;
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[1]->getNodeNumber()] -= value;	
        (*equationSystem)[nodes[3]->getNodeNumber()][nodes[1]->getNodeNumber()] += value;
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\VoltageControlledCurrentSource.cpp
*********************************************************************/
