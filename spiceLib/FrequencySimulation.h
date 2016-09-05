/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::FrequencySimulation
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\FrequencySimulation.h
*********************************************************************/

#ifndef FrequencySimulation_H
#define FrequencySimulation_H

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
//## class FrequencySimulation
#include "Simulation.h"
//## auto_generated
#include <cmath>
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## operation simulateFrequencyResponse(ComponentStorage,double,double,unsigned long)
    class ComponentStorage;
}


////

namespace Spice {
    //## package Spice
    
    //## class FrequencySimulation
    class FrequencySimulation : public Simulation {
        ////    Constructors and destructors    ////
        
    public :
    
        //## auto_generated
        FrequencySimulation();
        
        //## auto_generated
        ~FrequencySimulation();
        
        ////    Operations    ////
    
    private :
    
        //## operation solveEquationSystem(std::vector<std::vector<std::complex<double>>>&)
        std::vector<std::complex<double>>* solveEquationSystem(std::vector<std::vector<std::complex<double>>>& equationSystem);
        
        ////    Additional operations    ////
    
    public :
    
        //## auto_generated
        double getEndFreq() const;
        
        //## auto_generated
        void setEndFreq(double p_endFreq);
        
        //## auto_generated
        double getInitFreq() const;
        
        //## auto_generated
        void setInitFreq(double p_initFreq);
        
        //## auto_generated
        unsigned long getPoints() const;
        
        //## auto_generated
        void setPoints(unsigned long p_points);
        
        //## auto_generated
        std::map<double,std::vector<std::complex<double>>*> * getResults() const;
        
        //## auto_generated
        void setResults(std::map<double,std::vector<std::complex<double>>*> * p_results);
        
        ////    Attributes    ////
    
    protected :
    
        double endFreq;		//## attribute endFreq
        
        double initFreq;		//## attribute initFreq
        
        unsigned long points;		//## attribute points
        
        std::map<double,std::vector<std::complex<double>>*> *results;		//## attribute results
    
    public :
    
        //## operation simulateFrequencyResponse(ComponentStorage,double,double,unsigned long)
        std::map<double,std::vector<std::complex<double>>*> * simulateFrequencyResponse(ComponentStorage* componentStorage);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\FrequencySimulation.h
*********************************************************************/
