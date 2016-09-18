#include "Capacitor.h"

#include "Node.h"

namespace Spice {

    

    Capacitor::Capacitor(Node** newNodes, double value, unsigned long newKey) : TwoTerminalsComponent(newNodes, value, newKey) {

    }
    
    Capacitor::Capacitor() {
    }
    
    Capacitor::~Capacitor() {
    }
    
    void Capacitor::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += std::complex<double>(0,	frequency*value);
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] -= std::complex<double>(0,	frequency*value);
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -= std::complex<double>(0,	frequency*value);
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] += std::complex<double>(0,	frequency*value);

    }
    
    void Capacitor::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {

        unsigned long columns =(*equationSystem)[0].size(); // number of columns the matrix has
        
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += value/step; 
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] -= value/step;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -= value/step;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] += value/step;
        
        double lastVoltage = (*pastResults)[nodes[0]->getNodeNumber()] - (*pastResults)[nodes[1]->getNodeNumber()];  
        (*equationSystem)[nodes[0]->getNodeNumber()][columns - 1] += (value/step)*lastVoltage;
        (*equationSystem)[nodes[1]->getNodeNumber()][columns - 1] -= (value/step)*lastVoltage;

    }
}