#ifndef FrequencySimulation_H
#define FrequencySimulation_H

#include <cmath>
#include <string>
#include <algorithm>

#include "Spice.h"
#include "Simulation.h"

namespace Spice {

    class ComponentStorage;
}

namespace Spice {

    class FrequencySimulation : public Simulation {
        
    public :
    
        
        FrequencySimulation();
        
        
        ~FrequencySimulation();
            
    private :
    
        std::vector<std::complex<double>>* solveEquationSystem(std::vector<std::vector<std::complex<double>>>& equationSystem);
            
    public :
    
        
        double getEndFreq() const;
        
        
        void setEndFreq(double p_endFreq);
        
        
        double getInitFreq() const;
        
        
        void setInitFreq(double p_initFreq);
        
        
        unsigned long getPoints() const;
        
        
        void setPoints(unsigned long p_points);
        
        
        std::map<double,std::vector<std::complex<double>>*> * getResults() const;
        
        
        void setResults(std::map<double,std::vector<std::complex<double>>*> * p_results);
        
    
    protected :
    
        double endFreq;	
        
        double initFreq;
        
        unsigned long points;
        
        std::map<double,std::vector<std::complex<double>>*> *results;
    
    public :
    
        std::map<double,std::vector<std::complex<double>>*> * simulateFrequencyResponse(ComponentStorage* componentStorage);
    };
}

#endif