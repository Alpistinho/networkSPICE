#ifndef FileManager_H
#define FileManager_H


#include "Spice.h"

#include <sstream>
#include <fstream>

#include <string>
#include <algorithm>

namespace Spice {

    class ComponentStorage;
    
    class FrequencySimulation;
    
    class TransientSimulation;
}

namespace Spice {
    
    class FileManager {
        
    public :
    
        
        FileManager();
        
        
        ~FileManager();
                
        void writeResults(std::map<double,std::vector<std::complex<double>>*>* results);
        
        void readNetlist(std::string fileName, ComponentStorage* componentStorage, FrequencySimulation* frequencySimulation);
        
        void readNetlist(std::string fileName, ComponentStorage* componentStorage, TransientSimulation* timeSim);
        
        void writeResults(std::vector<std::pair<double, std::vector<double> > > *results);
    };
}

#endif