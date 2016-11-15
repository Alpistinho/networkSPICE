#include "ComponentStorage.h"
#include "FrequencySimulation.h"
#include "TransientSimulation.h"

#include "component.pb.h"

int main(int argc, char *argv[]) {
    
    Spice::ComponentStorage componentStorage;
    Spice::FrequencySimulation freqSim;
    Spice::TransientSimulation timeSim;
    
    networkSpiceMessages::Component component;

    std::vector<double> initialConditions(componentStorage.getSystemSize(), 0);

    return 0;
}