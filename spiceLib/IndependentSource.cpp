/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::IndependentSource
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\IndependentSource.cpp
*********************************************************************/

//## auto_generated
#include "IndependentSource.h"
//## auto_generated
#include "Node.h"

namespace Spice {
    //## package Spice
    
    //## class IndependentSource
    
    using namespace std;
    
    IndependentSource::IndependentSource(Node** newNodes, double modulus, double phase, unsigned long newKey) : TwoTerminalsComponent(newNodes, modulus, newKey), mode(DC), modulus(modulus), phase(phase) {
        //#[ operation IndependentSource(Node,double,double,unsigned long)
        //#]
    }
    
    IndependentSource::IndependentSource() {
    }
    
    IndependentSource::~IndependentSource() {
    }
    
    double IndependentSource::getOutput(double currentTime) {
        //#[ operation getOutput(double)
        switch(mode) {
        	
        	case DC:
          		return modulus;
          		break;
        
          	case Sinusoidal:                   
          		return sin( (frequency*currentTime) + phase);
          		break;
          	case Step:
          		
          		if (currentTime > phase) {
          			return modulus;
          		} else {
          			return 0;
          		}
          		break;
        
          	case Square:
          	
          	    double insidePeriodTime = fmod(currentTime,(1/frequency));
        
          	    if (insidePeriodTime < highTime) {
          	    	return modulus;
          	    } else {
          	    	if (insidePeriodTime < (highTime + offTime)) {
          	    		return 0;	
          	    	} else {
          	    		if (insidePeriodTime < (highTime + offTime + lowTime)) {
          	    			return -modulus;
          	    		}
        				return 0;
        			}
        		}
        		break;
        }	    		
          	    
        //#]
    }
    
    void IndependentSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double,double)
        //#]
    }
    
    void IndependentSource::setMode(SourceType operationMode, double DC) {
        //#[ operation setMode(SourceType,double)

        mode = operationMode;
        modulus = DC;
        //#]
    }
    
    void IndependentSource::setMode(SourceType operationMode, double freq, double mod, double p) {
        //#[ operation setMode(SourceType,double,double,double)

        mode = operationMode;
        frequency = freq;
        modulus = mod;
        phase = p;
        
        //#]
    }
    
    void IndependentSource::setMode(const SourceType& operationMode, double freq, double high, double low, double off) {
        //#[ operation setMode(SourceType,double,double,double,double,double,int)

        mode = operationMode;
        frequency = freq;
        highTime = high; 
        lowTime = low;
        offTime = off;
        //#]
    }
    
    void IndependentSource::setMode(const SourceType& operationMode, double DC, double delay) {
        //#[ operation setMode(SourceType,double,double)

        mode = operationMode;
        modulus = DC;
        phase = delay;
        //#]
    }
    
    double IndependentSource::getFrequency() const {
        return frequency;
    }
    
    void IndependentSource::setFrequency(double p_frequency) {
        frequency = p_frequency;
    }
    
    double IndependentSource::getOffTime() const {
        return offTime;
    }
    
    void IndependentSource::setOffTime(double p_offTime) {
        offTime = p_offTime;
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\IndependentSource.cpp
*********************************************************************/
