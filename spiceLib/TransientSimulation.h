/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::TransientSimulation
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\TransientSimulation.h
*********************************************************************/

#ifndef TransientSimulation_H
#define TransientSimulation_H

namespace Spice {
    //#[ ignore
    #ifdef _MSC_VER
    // disable Microsoft compiler warning (debug information truncated)
    #pragma warning(disable: 4786)
    #endif
    //#]
}

//## auto_generated
#include "Spice.h"
//## class TransientSimulation
#include "Simulation.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## operation simulateTransientResponse(ComponentStorage,std::vector<double>)
    class ComponentStorage;
}

//

//////
////////

//////////

namespace Spice {
    //## package Spice
    
    //## class TransientSimulation
    class TransientSimulation : public Simulation {
        ////    Constructors and destructors    ////
        
    public :
    
        //## auto_generated
        TransientSimulation();
        
        //## auto_generated
        ~TransientSimulation();
    
    private :
    
        //## operation solveEquationSystem(std::vector<std::vector<double>>&)
        std::vector<double>* solveEquationSystem(std::vector<std::vector<double>>& equationSystem);
    
    public :
    
        //## auto_generated
        double getEndTime() const;
        
        //## auto_generated
        void setEndTime(double p_endTime);
        
        //## auto_generated
        std::vector<std::pair<double, std::vector<double> > > *getResults();
        
        //## auto_generated
        void setResults(std::vector<std::pair<double, std::vector<double>>> p_results);
        
        //## auto_generated
        double getStep() const;
        
        //## auto_generated
        void setStep(double p_step);
    
    protected :
    
        double endTime;		//## attribute endTime
        
        std::vector<std::pair<double, std::vector<double>>> results;		//## attribute results
        
        double step;		//## attribute step
    
    public :
    
        //## operation simulateTransientResponse(ComponentStorage,std::vector<double>)
        std::vector<std::pair<double, std::vector<double>>>* simulateTransientResponse(ComponentStorage* componentStorage, std::vector<double> initialConditions);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\TransientSimulation.h
*********************************************************************/
