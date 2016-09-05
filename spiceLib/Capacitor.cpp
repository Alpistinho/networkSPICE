/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Capacitor
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Capacitor.cpp
*********************************************************************/

//## auto_generated
#include "Capacitor.h"
//## auto_generated
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class Capacitor
    Capacitor::Capacitor(Node** newNodes, double value, unsigned long newKey) : TwoTerminalsComponent(newNodes, value, newKey) {
        //#[ operation Capacitor(Node,double,unsigned long)
        //#]
    }
    
    Capacitor::Capacitor() {
    }
    
    Capacitor::~Capacitor() {
    }
    
    void Capacitor::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += std::complex<double>(0,	frequency*value);
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] -= std::complex<double>(0,	frequency*value);
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -= std::complex<double>(0,	frequency*value);
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] += std::complex<double>(0,	frequency*value);
        //#]
    }
    
    void Capacitor::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        unsigned long columns =(*equationSystem)[0].size(); // number of columns the matrix has
        
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += value/step; 
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] -= value/step;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -= value/step;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] += value/step;
        
        double lastVoltage = (*pastResults)[nodes[0]->getNodeNumber()] - (*pastResults)[nodes[1]->getNodeNumber()];  
        (*equationSystem)[nodes[0]->getNodeNumber()][columns - 1] += (value/step)*lastVoltage;
        (*equationSystem)[nodes[1]->getNodeNumber()][columns - 1] -= (value/step)*lastVoltage;
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Capacitor.cpp
*********************************************************************/
