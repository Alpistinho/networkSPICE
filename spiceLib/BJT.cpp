/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::BJT
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\BJT.cpp
*********************************************************************/

//## auto_generated
#include "BJT.h"
//## auto_generated
#include "Node.h"

namespace Spice {
    //## package Spice
    
    //## class BJT
    BJT::BJT(Node** newNodes, double hfe, double hie, double hre, double hoe, double cbe, double cbc, unsigned long newKey) : ThreeTerminalsComponent(newNodes, hfe, newKey), cbc(cbc), cbe(cbe), hie(hie), hoe(hoe), hre(hre) {
        //#[ operation BJT(Node,double,double,double,double,double,double,unsigned long)
        //#]
    }
    
    BJT::BJT() {
    }
    
    BJT::~BJT() {
    }
    
    void BJT::getFrequencyStamp(std::vector<std::vector<std::complex<double>>> * equationSystem, double frequency) {
        //#[ operation getFrequencyStamp(std::vector<std::vector<std::complex<double>>> *,double)
        
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += hoe - (hfe*hre)/hie;
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] += hfe/hie;
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[2]->getNodeNumber()] -= hoe + ( ((1-hre)*hfe)/hie );
        
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -=  (hre/hie);
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] +=  (1/hie);
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[2]->getNodeNumber()] +=  (hre - 1)/hie;
        
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[0]->getNodeNumber()] += -hoe + (1/hie) * ( (1 + hfe) * hre);
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[1]->getNodeNumber()] -= (1/hie) * (1 + hfe);
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[2]->getNodeNumber()] += hoe + (1/hie) * (1 + hfe) * (1 - hre);
        
        //parasitic capacitors
        
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += std::complex<double>(0,frequency*cbc);
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] -= std::complex<double>(0,frequency*cbc);
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -= std::complex<double>(0,frequency*cbc);
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] += std::complex<double>(0,frequency*cbc);
        
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += std::complex<double>(0,frequency*cbe);
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[2]->getNodeNumber()] -= std::complex<double>(0,frequency*cbc);
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[0]->getNodeNumber()] -= std::complex<double>(0,frequency*cbc);
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[2]->getNodeNumber()] += std::complex<double>(0,frequency*cbc);
        //#]
    }
    
    int BJT::getCbc() const {
        return cbc;
    }
    
    void BJT::setCbc(int p_cbc) {
        cbc = p_cbc;
    }
    
    int BJT::getCbe() const {
        return cbe;
    }
    
    void BJT::setCbe(int p_cbe) {
        cbe = p_cbe;
    }
    
    int BJT::getHfe() const {
        return hfe;
    }
    
    void BJT::setHfe(int p_hfe) {
        hfe = p_hfe;
    }
    
    int BJT::getHie() const {
        return hie;
    }
    
    void BJT::setHie(int p_hie) {
        hie = p_hie;
    }
    
    int BJT::getHoe() const {
        return hoe;
    }
    
    void BJT::setHoe(int p_hoe) {
        hoe = p_hoe;
    }
    
    int BJT::getHre() const {
        return hre;
    }
    
    void BJT::setHre(int p_hre) {
        hre = p_hre;
    }
    
    void BJT::getTransientStamp(std::vector<std::vector<double>>* equationSystem, std::vector<double>* pastResults, double step) {
        //#[ operation getTransientStamp(std::vector<std::vector<double>>*,std::vector<double>*,double)
        unsigned long columns =(*equationSystem)[0].size(); // number of columns the matrix has
        
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += hoe - (hfe*hre)/hie;
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] += hfe/hie;
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[2]->getNodeNumber()] -= hoe + ( ((1-hre)*hfe)/hie );
        
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -=  (hre/hie);
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] +=  (1/hie);
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[2]->getNodeNumber()] +=  (hre - 1)/hie;
        
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[0]->getNodeNumber()] += -hoe + (1/hie) * ( (1 + hfe) * hre);
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[1]->getNodeNumber()] -= (1/hie) * (1 + hfe);
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[2]->getNodeNumber()] += hoe + (1/hie) * (1 + hfe) * (1 - hre);
        
        
        //parasitic capacitor 1 (cbc)
        
        
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += value/step;
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[1]->getNodeNumber()] -= value/step;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[0]->getNodeNumber()] -= value/step;
        (*equationSystem)[nodes[1]->getNodeNumber()][nodes[1]->getNodeNumber()] += value/step;
        
        double lastVoltage = (*pastResults)[nodes[0]->getNodeNumber()] - (*pastResults)[nodes[1]->getNodeNumber()];  
        (*equationSystem)[nodes[0]->getNodeNumber()][columns - 1] += (value/step)*lastVoltage;
        (*equationSystem)[nodes[1]->getNodeNumber()][columns - 1] -= (value/step)*lastVoltage;
         
         
        //parasitic capacitor 2 (cbe)
        lastVoltage = (*pastResults)[nodes[0]->getNodeNumber()] - (*pastResults)[nodes[1]->getNodeNumber()];
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[0]->getNodeNumber()] += value/step;
        (*equationSystem)[nodes[0]->getNodeNumber()][nodes[2]->getNodeNumber()] -= value/step;
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[0]->getNodeNumber()] -= value/step;
        (*equationSystem)[nodes[2]->getNodeNumber()][nodes[2]->getNodeNumber()] += value/step;
        
          
        (*equationSystem)[nodes[0]->getNodeNumber()][columns - 1] += (value/step)*lastVoltage;
        (*equationSystem)[nodes[1]->getNodeNumber()][columns - 1] -= (value/step)*lastVoltage;
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\BJT.cpp
*********************************************************************/
