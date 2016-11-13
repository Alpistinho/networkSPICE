#include "ComponentStorage.h"
#include "FrequencySimulation.h"
#include "TransientSimulation.h"

int main(int argc, char *argv[]) {
    
    Spice::ComponentStorage componentStorage;
    Spice::FrequencySimulation freqSim;
    Spice::TransientSimulation timeSim;

    std::vector<double> initialConditions(componentStorage.getSystemSize(), 0);

    return 0;
}