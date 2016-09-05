#include "plotwindow.h"
#include "ComponentStorage.h"
#include "fileManager.h"
#include "FrequencySimulation.h"
#include "TransientSimulation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Spice::ComponentStorage componentStorage;
    Spice::FrequencySimulation freqSim;
    Spice::FileManager fileManager;
    fileManager.readNetlist("circuit_description.txt",&componentStorage,&freqSim);
    fileManager.writeResults(freqSim.simulateFrequencyResponse(&componentStorage));

    Spice::ComponentStorage componentStorage2;
    Spice::TransientSimulation timeSim;
    fileManager.readNetlist("circuit_description.txt", &componentStorage2, &timeSim);
    std::vector<double> initialConditions(componentStorage2.getSystemSize(), 0);
    fileManager.writeResults(timeSim.simulateTransientResponse(&componentStorage2, initialConditions));

    QApplication a(argc, argv);
    PlotWindow w;
    w.show();

    return a.exec();
}
