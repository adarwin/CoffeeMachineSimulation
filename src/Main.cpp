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
//#include <fstream>

using namespace com_adarwin_simulation;
using namespace std;

int main() {
    set<string> test;
    test.insert("test1");
    test.insert("test2");
    SimulationModel* simModel = new CVMSimulationModel(test);
    CVMState* simState = new CVMState(0, 0, 0);
    CVMInput* simInput;
    string input = "";
    do {
        cout << endl << "Enter a command: ";
        getline(cin, input);
        if (input == "exit") continue;
        simInput = new CVMInput(input);
        simModel->lambda(simState);
        simModel->delta(simState, simInput);
        cout << simState->getString();
    } while (input != "exit");
    /*
    CVMInput* simInput = new CVMInput("quarter, quarter, quarter, "
                                             "quarter");
    simModel->lambda(simState);
    simModel->delta(simState, simInput);
    simModel->lambda(simState);
    simInput = new CVMInput("dime, dime, dime");
    simModel->delta(simState, simInput);
    simModel->lambda(simState);
    simInput = new CVMInput("change");
    simModel->delta(simState, simInput);
    simModel->lambda(simState);
    simInput = new CVMInput("wait");
    simModel->delta(simState, simInput);
    simModel->lambda(simState);
    */
    return 0;
}
