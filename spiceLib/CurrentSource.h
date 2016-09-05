/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::CurrentSource
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\CurrentSource.h
*********************************************************************/

#ifndef CurrentSource_H
#define CurrentSource_H

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
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
//## class CurrentSource
#include "IndependentSource.h"
namespace Spice {
    //## auto_generated
    class Node;
    
    //## package Spice
    
    //## class CurrentSource
    class CurrentSource : public IndependentSource {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation CurrentSource(Node,int,int,unsigned long)
        CurrentSource(Node** newNodes, int current, int phase, unsigned long newKey);
        
        //## auto_generated
        CurrentSource();
        
        //## auto_generated
        virtual ~CurrentSource();
        
        ////    Operations    ////
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        ////    Additional operations    ////
        
        //## auto_generated
        std::complex<double> getValue() const;
        
        ////    Attributes    ////
    
    protected :
    
        std::complex<double> value;		//## attribute value
    
    public :
    
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step, double currentTime);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\CurrentSource.h
*********************************************************************/
