/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::CurrentSource
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\CurrentSource.cpp
*********************************************************************/

//## auto_generated
#include "CurrentSource.h"
//## auto_generated
#include "Node.h"
namespace Spice {
    //## package Spice
    
    //## class CurrentSource
    CurrentSource::CurrentSource(Node** newNodes, int current, int phase, unsigned long newKey) : IndependentSource(newNodes, current, phase, newKey) {
        //#[ operation CurrentSource(Node,int,int,unsigned long)
        value = std::complex<double>(current*std::cos(phase), current*std::sin(phase));
        //#]
    }
    
    CurrentSource::CurrentSource() {
    }
    
    CurrentSource::~CurrentSource() {
    }
    
    void CurrentSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        unsigned long columns =(*equationSystem)[0].size(); // number of columns the matrix has
        (*equationSystem)[nodes[0]->getNodeNumber()][columns-1] += value;
        (*equationSystem)[nodes[1]->getNodeNumber()][columns-1] -= value;
        //#]
    }
    
    std::complex<double> CurrentSource::getValue() const {
        return value;
    }
    
    void CurrentSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double,double)
        unsigned long columns =(*equationSystem)[0].size(); // number of columns the matrix has
        (*equationSystem)[nodes[0]->getNodeNumber()][columns-1] += getOutput(currentTime);
        (*equationSystem)[nodes[1]->getNodeNumber()][columns-1] -= getOutput(currentTime);
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\CurrentSource.cpp
*********************************************************************/
