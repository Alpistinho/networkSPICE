#include "IndependentSource.h"

#include "Node.h"

namespace Spice {
    
    
    using namespace std;
    
    IndependentSource::IndependentSource(Node** newNodes, double modulus, double phase, unsigned long newKey) : TwoTerminalsComponent(newNodes, modulus, newKey), mode(DC), modulus(modulus), phase(phase) {
        
    }
    
    IndependentSource::IndependentSource() {
    }
    
    IndependentSource::~IndependentSource() {
    }
    
    double IndependentSource::getOutput(double currentTime) {
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
          	    
        
    }
    
    void IndependentSource::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime) {
        
    }
    
    void IndependentSource::setMode(SourceType operationMode, double DC) {

        mode = operationMode;
        modulus = DC;
        
    }
    
    void IndependentSource::setMode(SourceType operationMode, double freq, double mod, double p) {

        mode = operationMode;
        frequency = freq;
        modulus = mod;
        phase = p;
        
        
    }
    
    void IndependentSource::setMode(const SourceType& operationMode, double freq, double high, double low, double off) {

        mode = operationMode;
        frequency = freq;
        highTime = high; 
        lowTime = low;
        offTime = off;
        
    }
    
    void IndependentSource::setMode(const SourceType& operationMode, double DC, double delay) {

        mode = operationMode;
        modulus = DC;
        phase = delay;
        
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