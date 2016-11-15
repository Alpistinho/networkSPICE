#ifndef _NETLIST_FUNCS_H_
#define _NETLIST_FUNCS_H_

#include "ComponentStorage.h"
#include "netlist.pb.cc"

Spice::ComponentStorage readComponents(networkSpiceMessages::Netlist &);

#endif