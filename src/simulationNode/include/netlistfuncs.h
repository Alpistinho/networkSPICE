#ifndef _NETLIST_FUNCS_H_
#define _NETLIST_FUNCS_H_

#include <complex>
#include "ComponentStorage.h"
#include "netlist.pb.h"
#include "results.pb.h"

Spice::ComponentStorage readComponents(networkSpiceMessages::Netlist &);

networkSpiceMessages::Results writeResults(std::map<double,std::vector<std::complex<double>>*> &results, std::vector<unsigned> nodes);

networkSpiceMessages::Results writeResults(std::vector<std::pair<double, std::vector<double>>> &results, std::vector<unsigned> nodes);


#endif