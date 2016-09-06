/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::Capacitor
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\Capacitor.h
*********************************************************************/

#ifndef Capacitor_H
#define Capacitor_H

namespace Spice {
    //#[ ignore
    #ifdef _MSC_VER
    // disable Microsoft compiler warning (debug information truncated)
    #pragma warning(disable: 4786)
    #endif
    
}


#include "Spice.h"
//## class Capacitor
#include "TwoTerminalsComponent.h"

//

#include <string>

#include <algorithm>
namespace Spice {
    
    class Node;
    

    
    //## class Capacitor
    class Capacitor : public TwoTerminalsComponent {

        
    public :
    
        //## operation Capacitor(Node,double,unsigned long)
        Capacitor(Node** newNodes, double value, unsigned long newKey);
        
        
        Capacitor();
        
        
        virtual ~Capacitor();
        
        
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\Capacitor.h
*********************************************************************/
