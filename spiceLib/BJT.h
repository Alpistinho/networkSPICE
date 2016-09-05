/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::BJT
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\BJT.h
*********************************************************************/

#ifndef BJT_H
#define BJT_H

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
//## class BJT
#include "ThreeTerminalsComponent.h"
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## auto_generated
    class Node;
}


////

namespace Spice {
    //## package Spice
    
    //## class BJT
    class BJT : public ThreeTerminalsComponent {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation BJT(Node,double,double,double,double,double,double,unsigned long)
        BJT(Node** newNodes, double hfe, double hie, double hre, double hoe, double cbe, double cbc, unsigned long newKey);
        
        //## auto_generated
        BJT();
        
        //## auto_generated
        virtual ~BJT();
        
        ////    Operations    ////
        
        //## operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        virtual void getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency);
        
        ////    Additional operations    ////
        
        //## auto_generated
        int getCbc() const;
        
        //## auto_generated
        void setCbc(int p_cbc);
        
        //## auto_generated
        int getCbe() const;
        
        //## auto_generated
        void setCbe(int p_cbe);
        
        //## auto_generated
        int getHfe() const;
        
        //## auto_generated
        void setHfe(int p_hfe);
        
        //## auto_generated
        int getHie() const;
        
        //## auto_generated
        void setHie(int p_hie);
        
        //## auto_generated
        int getHoe() const;
        
        //## auto_generated
        void setHoe(int p_hoe);
        
        //## auto_generated
        int getHre() const;
        
        //## auto_generated
        void setHre(int p_hre);
        
        ////    Attributes    ////
    
    protected :
    
        int cbc;		//## attribute cbc
        
        int cbe;		//## attribute cbe
        
        int hfe;		//## attribute hfe
        
        int hie;		//## attribute hie
        
        int hoe;		//## attribute hoe
        
        int hre;		//## attribute hre
    
    public :
    
        //## operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        virtual void getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\BJT.h
*********************************************************************/
