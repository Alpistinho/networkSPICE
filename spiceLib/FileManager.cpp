/********************************************************************
	Rhapsody	: 8.1 
	Login		: Daniel
	Component	: SpiceComponent 
	Configuration 	: SpiceConfig
	Model Element	: Spice::FileManager
//!	Generated Date	: Fri, 11, Dec 2015  
	File Path	: SpiceComponent\SpiceConfig\FileManager.cpp
*********************************************************************/

//## auto_generated
#include "FileManager.h"
//## operation readNetlist(std::string,ComponentStorage,FrequencySimulation)
#include "ComponentStorage.h"
//## operation readNetlist(std::string,ComponentStorage,FrequencySimulation)
#include "FrequencySimulation.h"
//## operation readNetlist(std::string,ComponentStorage,TransientSimulation)
#include "TransientSimulation.h"

namespace Spice {
    //## package Spice
    
    //## class FileManager
    
    using namespace std;
    
    FileManager::FileManager() {
    }
    
    FileManager::~FileManager() {
    }
    
    //#[ ignore
    #define _USE_MATH_DEFINES
    #include <math.h>
    //#]
    void FileManager::writeResults(std::map<double,std::vector<std::complex<double>>*>* results) {
        //#[ operation writeResults(std::map<double,std::vector<std::complex<double>>*>*)
        //#[ operation writeResults(std::map<double,std::vector<std::complex<double>>*>*)
                map<double,vector<complex<double>>*>::iterator it;
                ofstream resultFile;
                resultFile.open("freq_results.txt");
                resultFile << ((results->begin()->second->size())*2) + 1 << endl;
                for(it = results->begin(); it != results->end(); it++) {
                    double frequency = it->first;
                    resultFile << frequency << ",";
                    for(unsigned i = 0; i < it->second->size(); i++) {
        
                        complex<double> value = (*(it->second))[i];
        				
                        resultFile << abs(value) << ',' << (180/M_PI)*atan2(imag(value), real(value)) << ',';
        
                    }
                    resultFile << endl;
                }
        
                return;
        //#]
    }
    
    void FileManager::readNetlist(std::string fileName, ComponentStorage* componentStorage, FrequencySimulation* frequencySimulation) {

        std::ifstream file(fileName);
        std::string str; 
        vector<string> line;
        while (getline(file, str)) {
            line.clear();
            stringstream ss(str);
            string item;
        	while (getline(ss, item, ' ')) {
                line.push_back(item);
            }

            switch (line[0][0]) { //switch on the first char of the first string. No error treatment
        	case 'R':
        		componentStorage->addResistor(line[1], line[2], stod(line[3]));
        		break;
        
        	case 'C':
        		componentStorage->addCapacitor(line[1], line[2], stod(line[3]));
        		break;
        
        	case 'L':
        		componentStorage->addInductor(line[1], line[2], stod(line[3]));
        		break;
        
        	case 'V':
        		componentStorage->addVoltageSource(line[1], line[2], stod(line[3]), stod(line[4]));
        		break;
        
        	case 'I':
        		componentStorage->addCurrentSource(line[1], line[2], stod(line[3]), stod(line[4]));
        		break;
        
        	case 'E':
        		componentStorage->addVoltageControlledVoltageSource(line[1], line[2], line[3], line[4], stod(line[5]));
        		break;
        
        	case 'F':
        		componentStorage->addCurrentControlledCurrentSource(line[1], line[2], line[3], line[4], stod(line[5]));
        		break;
        
        	case 'G':
        		componentStorage->addVoltageControlledCurrentSource(line[1], line[2], line[3], line[4], stod(line[5]));
        	break;
        
        	case 'H':
        		componentStorage->addCurrentControlledVoltageSource(line[1], line[2], line[3], line[4], stod(line[5]));
        		break;
        
        	case 'O':
        		componentStorage->addOpAmp(line[1], line[2], line[3], line[4]);
        		break;
        	case 'Q':
        		componentStorage->addBJT(line[1], line[2], line[3], stod(line[4]), stod(line[5]), stod(line[6]), stod(line[7]), stod(line[8]), stod(line[9]));
        		break;
        	case '.': //condiguration line
        		frequencySimulation->setInitFreq(stod(line[2]));
        		frequencySimulation->setEndFreq(stod(line[3]));
        		frequencySimulation->setPoints(stod(line[1]));
        		//format is .AC      points   initial  final
        		//         line[0]   line[1]  line[2]  line[3]
        		break;
        	default:
        		break;
        	}
        
        }
        return;
        //#]
    }
    
    void FileManager::readNetlist(std::string fileName, ComponentStorage* componentStorage, TransientSimulation* timeSim) {
        //#[ operation readNetlist(std::string,ComponentStorage,TransientSimulation)

        std::ifstream file(fileName);
        std::string str; 
        vector<string> line;
        while (getline(file, str)) {
        	line.clear();
        	stringstream ss(str);
        	string item;
        	while (getline(ss, item, ' ')) {
        		line.push_back(item);
        	}

        	switch (line[0][0]) {//switch on the first char of the first string. No error treatment
        
        	case 'R':
        		componentStorage->addResistor(line[1], line[2], stod(line[3]));
        		break;
        
        	case 'C':
        		componentStorage->addCapacitor(line[1], line[2], stod(line[3]));
        		break;
        
        	case 'L':
        		componentStorage->addInductor(line[1], line[2], stod(line[3]));
        		break;
        
        	case 'V':

                {
                    unsigned long componentIdentifier;
                    componentIdentifier = componentStorage->addVoltageSource(line[1], line[2], stod(line[3]), stod(line[4]));

                    VoltageSource* dummyComponent = static_cast<VoltageSource*>(componentStorage->getComponentByIdentifier(componentIdentifier));

                    if( line[5] == "sine") {

                        dummyComponent->setMode(Sinusoidal, stod(line[6]), stod(line[3]), stod(line[4]));

                    } else {
                        if (line[5] == "square") {
                            dummyComponent->setMode(Square, stod(line[6]), stod(line[7]), stod(line[8]), stod(line[9]));
                        } else{
                            if(line[5] == "step") {
                                dummyComponent->setMode(Step, stod(line[6]), stod(line[7]));
                            } else {
                                if(line[5] == "DC") {
                                    dummyComponent->setMode(DC, stod(line[3]));
                                }
                              }
                          }
                    }
                }
        		break;
        
        	case 'I':
                {
                    unsigned long componentIdentifier;
                    componentIdentifier = componentStorage->addVoltageSource(line[1], line[2], stod(line[3]), stod(line[4]));

                    CurrentSource* dummyComponent = static_cast<CurrentSource*>(componentStorage->getComponentByIdentifier(componentIdentifier));

                    if( line[5] == "sine") {

                        dummyComponent->setMode(Sinusoidal, stod(line[6]), stod(line[3]), stod(line[4]));

                    } else {
                        if (line[5] == "square") {
                            dummyComponent->setMode(Square, stod(line[6]), stod(line[7]), stod(line[8]), stod(line[9]));
                        } else{
                            if(line[5] == "step") {
                                dummyComponent->setMode(Step, stod(line[6]), stod(line[7]));
                            } else {
                                if(line[5] == "DC") {
                                    dummyComponent->setMode(DC, stod(line[3]));
                                }
                              }
                          }
                    }
                }
                break;
        
        	case 'E':
        		componentStorage->addVoltageControlledVoltageSource(line[1], line[2], line[3], line[4], stod(line[5]));
        		break;
        
        	case 'F':
        		componentStorage->addCurrentControlledCurrentSource(line[1], line[2], line[3], line[4], stod(line[5]));
        		break;
        
        	case 'G':
        		componentStorage->addVoltageControlledCurrentSource(line[1], line[2], line[3], line[4], stod(line[5]));
        	break;
        
        	case 'H':
        		componentStorage->addCurrentControlledVoltageSource(line[1], line[2], line[3], line[4], stod(line[5]));
        		break;
        
        	case 'O':
        		componentStorage->addOpAmp(line[1], line[2], line[3], line[4]);
        		break;
        	case 'Q':
        		componentStorage->addBJT(line[1], line[2], line[3], stod(line[4]), stod(line[5]), stod(line[6]), stod(line[7]), stod(line[8]), stod(line[9]));
        		break;
            case '!': //configuration line
        		timeSim->setEndTime(stod(line[1]));
        		timeSim->setStep(stod(line[2]));
        
                //format is #T      endTime  step
        		//         line[0]  line[1]  line[2] 
        		break;
        	default:
        		break;
        	}
        
        }
        
        return;
        //#]
    }
    
    void FileManager::writeResults(std::vector<std::pair<double, std::vector<double>>>* results) {

                std::vector<std::pair<double, std::vector<double>>>::iterator it;
        		ofstream resultFile;
                resultFile.open("time_results.txt");

                resultFile << ((results->begin()->second.size()))  << endl;
                for(it = results->begin(); it != results->end(); ++it) {
        			double time = it->first;
        			resultFile << time << ",";
                    for(unsigned i = 1; i < it->second.size(); ++i) {
                        vector<double> dummyVec = (it->second);

                        double value = (it->second)[i];

                        resultFile << value << ',';
        
                    }
        			resultFile << endl;
        		}
        
        		return;
        //#]
    }
}

/*********************************************************************
	File Path	: SpiceComponent\SpiceConfig\FileManager.cpp
*********************************************************************/
