/*********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::FileManager
//!	Generated Date	: Sat, 12, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\FileManager.h
*********************************************************************/

#ifndef FileManager_H
#define FileManager_H

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
#include <sstream>
//## auto_generated
#include <fstream>
//## auto_generated
//
//## auto_generated
#include <string>
//## auto_generated
#include <algorithm>
namespace Spice {
    //## operation readNetlist(std::string,ComponentStorage,FrequencySimulation)
    class ComponentStorage;
    
    //## operation readNetlist(std::string,ComponentStorage,FrequencySimulation)
    class FrequencySimulation;
    
    //## operation readNetlist(std::string,ComponentStorage,TransientSimulation)
    class TransientSimulation;
}

//

////////////

namespace Spice {
    //## package Spice
    
    //## class FileManager
    class FileManager {
        ////    Constructors and destructors    ////
        
    public :
    
        //## auto_generated
        FileManager();
        
        //## auto_generated
        ~FileManager();
        
        ////    Operations    ////
        
        //## operation writeResults(std::map<double,std::vector<std::complex<double>>*>*)
        void writeResults(std::map<double,std::vector<std::complex<double>>*>* results);
        
        //## operation readNetlist(std::string,ComponentStorage,FrequencySimulation)
        void readNetlist(std::string fileName, ComponentStorage* componentStorage, FrequencySimulation* frequencySimulation);
        
        //## operation readNetlist(std::string,ComponentStorage,TransientSimulation)
        void readNetlist(std::string fileName, ComponentStorage* componentStorage, TransientSimulation* timeSim);
        
        //## operation writeResults(std::map<double,std::vector<double>*>*)
        void writeResults(std::vector<std::pair<double, std::vector<double> > > *results);
    };
}

#endif
/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\FileManager.h
*********************************************************************/
