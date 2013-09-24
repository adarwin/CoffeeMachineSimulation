/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#include <iostream>
#include "CVMState.h"
#include "CVMInput.h"
#include "DiscreteSimulator.h"
#include "CVMSimulationModel.h"
#include "SimulationModel.h"

using namespace com_adarwin_simulation;
using namespace std;

int main() {
    string values[] = {"test1", "test2", "test3"};
    set<string> test;
    test.insert("test1");
    test.insert("test2");
    SimulationModel* simModel = new CVMSimulationModel(test);
    SimulationState* simState = new CVMState(0, 0, 0, false);
    SimulationInput* simInput = new CVMInput("quarter, quarter, quarter, "
                                             "quarter, quarter");
    simModel->lambda(simState);
    simModel->delta(simState, simInput);
    cout << "After delta..." << endl;
    simModel->lambda(simState);
    return 0;
}
