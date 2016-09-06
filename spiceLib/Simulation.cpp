#include "Simulation.h"
namespace Spice {

    
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