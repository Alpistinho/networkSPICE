/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::ComponentStorage
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\ComponentStorage.h
*********************************************************************/

#ifndef ComponentStorage_H
#define ComponentStorage_H

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
//## class ComponentStorage
#include "Storage.h"
//## link branchStorage
#include "BranchStorage.h"
//## link nodeStorage
#include "NodeStorage.h"
namespace Spice {
    //## operation getComponentByIdentifier(unsigned long)
    class Component;
}

//## auto_generated
#include "Resistor.h"
//## auto_generated
#include "Capacitor.h"
//## auto_generated
#include "Inductor.h"
//## auto_generated
#include "CurrentControlledCurrentSource.h"
//## auto_generated
#include "CurrentControlledVoltageSource.h"
//## auto_generated
#include "BJT.h"
//## auto_generated
#include "CurrentSource.h"
//## auto_generated
#include "OpAmp.h"
//## auto_generated
#include "VoltageControlledCurrentSource.h"
//## auto_generated
#include "VoltageControlledVoltageSource.h"
//## auto_generated
#include "VoltageSource.h"
//## auto_generated
#include "Node.h"
//## auto_generated
#include "Branch.h"
//## auto_generated
#include "Component.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
//
////

//////////

namespace Spice {
    //## package Spice
    
    //## class ComponentStorage
    class ComponentStorage : public Storage {
        ////    Constructors and destructors    ////
        
    public :
    
        //## auto_generated
        ComponentStorage();
        
        //## auto_generated
        ~ComponentStorage();
        
        ////    Operations    ////
        
        //## operation addCapacitor(std::string,std::string,double)
        unsigned long addCapacitor(std::string n1, std::string n2, double value);
        
        //## operation addCurrentControlledCurrentSource(std::string,std::string,std::string,std::string,double)
        unsigned long addCurrentControlledCurrentSource(std::string n1, std::string n2, std::string n3, std::string n4, double value);
        
        //## operation addCurrentControlledVoltageSource(std::string,std::string,std::string,std::string,double)
        unsigned long addCurrentControlledVoltageSource(std::string n1, std::string n2, std::string n3, std::string n4, double value);
        
        //## operation addCurrentSource(std::string,std::string,double,double)
        unsigned long addCurrentSource(std::string n1, std::string n2, double current, double phase);
        
        //## operation addInductor(std::string,std::string,double)
        unsigned long addInductor(std::string n1, std::string n2, double value);
        
        //## operation addResistor(std::string,std::string,double)
        unsigned long addResistor(std::string n1, std::string n2, double value);
        
        //## operation addVoltageControlledCurrentSource(std::string,std::string,std::string,std::string,double)
        unsigned long addVoltageControlledCurrentSource(std::string n1, std::string n2, std::string n3, std::string n4, double value);
        
        //## operation addVoltageControlledVoltageSource(std::string,std::string,std::string,std::string,double)
        unsigned long addVoltageControlledVoltageSource(std::string n1, std::string n2, std::string n3, std::string n4, double value);
        
        //## operation addVoltageSource(std::string,std::string,double,double)
        unsigned long addVoltageSource(std::string n1, std::string n2, double voltage, double phase);
        
        //## operation addBJT(std::string,std::string,std::string,double,double,double,long double,double,double)
        unsigned long addBJT(std::string n1, std::string n2, std::string n3, double hfe, double hie, double hre, long double hoe, double cbe, double cbc);
        
        //## operation addOpAmp(std::string,std::string,std::string,std::string)
        unsigned long addOpAmp(std::string n1, std::string n2, std::string n3, std::string n4);
        
        //## operation allocateNodeNumbers()
        void allocateNodeNumbers();
        
        //## operation getComponentByIdentifier(unsigned long)
        Component* getComponentByIdentifier(unsigned long identifier);
        
        //## operation getFrequencySystem(std::vector<std::vector<std::complex<double>>>*,double)
        void getFrequencySystem(std::vector<std::vector<std::complex<double>>>* equationSystem, double frequency);
        
        //## operation getSystemSize()
        unsigned long getSystemSize();
    
    protected :
    
        unsigned long branchesNeededAmount;		//## attribute branchesNeededAmount
        
        unsigned long componentIdentifier;		//## attribute componentIdentifier
        
        std::map<unsigned long, Component*> componentMap;		//## attribute componentMap
        
        unsigned long elementsAmount;		//## attribute elementsAmount
        
        BranchStorage branchStorage;		//## link branchStorage
        
        NodeStorage nodeStorage;		//## link nodeStorage
    
    public :
    
        //## operation getTransientSystem(std::vector<std::vector<double>> *,std::vector<double> *,double,double)
        void getTransientSystem(std::vector<std::vector<double>> * equationSystem, std::vector<double> * pastResults, double step, double currentTime);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\ComponentStorage.h
*********************************************************************/
