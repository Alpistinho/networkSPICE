#include "CurrentSource.h"
#include "Node.h"

namespace Spice {
    
    CurrentSource::CurrentSource(Node** newNodes, int current, int phase, unsigned long newKey) : IndependentSource(newNodes, current, phase, newKey) {
        value = std::complex<double>(current*std::cos(phase), current*std::sin(phase));
    }
    
    CurrentSource::CurrentSource() {
    }
    
    CurrentSource::~CurrentSource() {
    }
    
    void CurrentSource::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        unsigned long columns =(*equationSystem)[0].size(); // number of columns the matrix has
        (*equationSystem)[nodes[0]->getNodeNumber()][columns-1] += value;
        (*equationSystem)[nodes[1]->getNodeNumber()][columns-1] -= value;
    }
    
    std::complex<double> CurrentSource::getValue() const {
        return value;
    }
    
    void CurrentSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime) {
        unsigned long columns =(*equationSystem)[0].size(); // number of columns the matrix has
        (*equationSystem)[nodes[0]->getNodeNumber()][columns-1] += getOutput(currentTime);
        (*equationSystem)[nodes[1]->getNodeNumber()][columns-1] -= getOutput(currentTime);
    }
}