#ifndef Simulation_H
#define Simulation_H

#include <string>
#include <algorithm>

#include "Spice.h"

namespace Spice {

    class Simulation {

        
    public :
    
        
        Simulation();
        
        ~Simulation();
        

        double getTolerance() const;
        
        void setTolerance(double p_tolerance);
        
       
    
    protected :
    
        double tolerance;		//## attribute tolerance
    };
}

#endif