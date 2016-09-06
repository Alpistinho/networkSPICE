#include "ComponentStorage.h"
#include "FileManager.h"
#include "FrequencySimulation.h"
#include "TransientSimulation.h"

int main(int argc, char *argv[])
{
    Spice::ComponentStorage componentStorage;
    Spice::FrequencySimulation freqSim;
    Spice::FileManager fileManager;
    // fileManager.readNetlist("circuit_description.txt",&componentStorage,&freqSim);
    // fileManager.writeResults(freqSim.simulateFrequencyResponse(&componentStorage));

    Spice::ComponentStorage componentStorage2;
    Spice::TransientSimulation timeSim;
    // fileManager.readNetlist("circuit_description.txt", &componentStorage2, &timeSim);
    std::vector<double> initialConditions(componentStorage2.getSystemSize(), 0);
    // fileManager.writeResults(timeSim.simulateTransientResponse(&componentStorage2, initialConditions));

    return 0;
}
