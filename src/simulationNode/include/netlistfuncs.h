#ifndef _NETLIST_FUNCS_H_
#define _NETLIST_FUNCS_H_

#include <complex>
#include <iostream>
#include <cmath>
#include "ComponentStorage.h"
#include "simulationrequest.pb.h"
#include "results.pb.h"

Spice::ComponentStorage readComponents(networkSpiceMessages::SimulationRequest &);

networkSpiceMessages::Results writeResults(std::map<double,std::vector<std::complex<double>>*> * results, std::vector<unsigned> nodes);

networkSpiceMessages::Results writeResults(std::vector<std::pair<double, std::vector<double>>> results, std::vector<unsigned> nodes);

void printSimulationRequest(networkSpiceMessages::SimulationRequest simReq);


#endif