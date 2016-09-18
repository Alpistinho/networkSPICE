#ifndef IndependentSource_H
#define IndependentSource_H

#include <string>
#include <algorithm>
#include <cmath>

#include "Spice.h"
#include "TwoTerminalsComponent.h"


namespace Spice {
    
    class Node;
    
    class IndependentSource : public TwoTerminalsComponent {

        
    public :
    
        IndependentSource(Node** newNodes, double modulus, double phase, unsigned long newKey);
        
        IndependentSource();
        
        
        virtual ~IndependentSource();
        
        double getOutput(double currentTime);
        
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime);
        
        void setMode(SourceType operationMode, double DC);
        
        void setMode(SourceType operationMode, double freq, double mod, double p);
        
        void setMode(const SourceType& operationMode, double freq, double high, double low, double off);
        
        void setMode(const SourceType& operationMode, double DC, double delay);
     
        
        double getFrequency() const;
           
        void setFrequency(double p_frequency);
  
        double getOffTime() const;

        void setOffTime(double p_offTime);
       
    
    protected :
    
        double frequency;
        
        double highTime;
        
        double lowTime;
        
        SourceType mode;
        
        double modulus;	
        double offTime;	
        
        double phase;
    };
}

#endif