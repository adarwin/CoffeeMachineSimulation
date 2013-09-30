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
    set<string> acceptableInputs;
    acceptableInputs.insert("q");
    acceptableInputs.insert("d");
    acceptableInputs.insert("n");
    acceptableInputs.insert("c");
    acceptableInputs.insert("w");
    SimulationModel* simModel = new CVMSimulationModel(acceptableInputs);
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
    return 0;
}
