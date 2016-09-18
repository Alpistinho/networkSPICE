#ifndef TransientSimulation_H
#define TransientSimulation_H

#include <string>
#include <algorithm>

#include "Spice.h"
#include "Simulation.h"

namespace Spice {
    class ComponentStorage;
}

namespace Spice {

    
    class TransientSimulation : public Simulation {

        
    public :
    
        
        TransientSimulation();
        
        
        ~TransientSimulation();
    
    private :
    
        std::vector<double>* solveEquationSystem(std::vector<std::vector<double>>& equationSystem);
    
    public :
    
        
        double getEndTime() const;
        
        
        void setEndTime(double p_endTime);
        
        
        std::vector<std::pair<double, std::vector<double> > > *getResults();
        
        
        void setResults(std::vector<std::pair<double, std::vector<double>>> p_results);
        
        
        double getStep() const;
        
        
        void setStep(double p_step);
    
    protected :
    
        double endTime;	
        
        std::vector<std::pair<double, std::vector<double>>> results;
        
        double step;
    
    public :
    
        std::vector<std::pair<double, std::vector<double>>>* simulateTransientResponse(ComponentStorage* componentStorage, std::vector<double> initialConditions);
    };
}

#endif