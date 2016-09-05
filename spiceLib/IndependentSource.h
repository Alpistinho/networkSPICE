/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::IndependentSource
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\IndependentSource.h
*********************************************************************/

#ifndef IndependentSource_H
#define IndependentSource_H

namespace Spice {
    //#[ ignore
    #ifdef _MSC_VER
    // disable Microsoft compiler warning (debug information truncated)
    #pragma warning(disable: 4786)
    #endif
    //#]
}

//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
//## auto_generated
#include "Spice.h"
//## class IndependentSource
#include "TwoTerminalsComponent.h"
//## auto_generated
#include <cmath>
namespace Spice {
    //## auto_generated
    class Node;
    
    //## package Spice
    
    //## class IndependentSource
    class IndependentSource : public TwoTerminalsComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation IndependentSource(Node,double,double,unsigned long)
        IndependentSource(Node** newNodes, double modulus, double phase, unsigned long newKey);
        
        //## auto_generated
        IndependentSource();
        
        //## auto_generated
        virtual ~IndependentSource();
        
        ////    Operations    ////
        
        //## operation getOutput(double)
        double getOutput(double currentTime);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime);
        
        //## operation setMode(SourceType,double)
        void setMode(SourceType operationMode, double DC);
        
        //## operation setMode(SourceType,double,double,double)
        void setMode(SourceType operationMode, double freq, double mod, double p);
        
        //## operation setMode(SourceType,double,double,double,double,double,int)
        void setMode(const SourceType& operationMode, double freq, double high, double low, double off);
        
        //## operation setMode(SourceType,double,double)
        void setMode(const SourceType& operationMode, double DC, double delay);
        
        ////    Additional operations    ////
        
        //## auto_generated
        double getFrequency() const;
        
        //## auto_generated
        void setFrequency(double p_frequency);
        
        //## auto_generated
        double getOffTime() const;
        
        //## auto_generated
        void setOffTime(double p_offTime);
        
        ////    Attributes    ////
    
    protected :
    
        double frequency;		//## attribute frequency
        
        double highTime;		//## attribute highTime
        
        double lowTime;		//## attribute lowTime
        
        SourceType mode;		//## attribute mode
        
        double modulus;		//## attribute modulus
        
        double offTime;		//## attribute offTime
        
        double phase;		//## attribute phase
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\IndependentSource.h
*********************************************************************/
