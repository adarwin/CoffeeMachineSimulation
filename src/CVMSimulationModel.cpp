/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "CVMSimulationModel.h"
#include "SimulationState.h"
#include "SimulationInput.h"
#include "CVMState.h"

using std::cout;
using std::endl;
using std::set;
using std::string;
using std::vector;

namespace com_adarwin_simulation {
    CVMSimulationModel::CVMSimulationModel(set<string> acceptableInputs) :
                                            SimulationModel(acceptableInputs) {
    }

    void CVMSimulationModel::lambda(SimulationState* simulationState) {
        CVMState* temp = (CVMState*)simulationState;
        int cents = temp->getTotalCents();
        if (cents >= 100 && (temp->isWaiting() || temp->isChangeSelected())) {
            cout << "Have a coffee!" << endl;
        }
        double dollars = (double)cents/100;
        cout << "$" << dollars << endl;
        /*
        cout << "# Nickels = " << temp->getNumNickels() << endl;
        cout << "# Dimes = " << temp->getNumDimes() << endl;
        cout << "# Quarters = " << temp->getNumQuarters() << endl;
        cout << "Change Selected = " << temp->isChangeSelected() << endl;
        */
    }

    void CVMSimulationModel::delta(SimulationState* simulationState,
                                   SimulationInput* simulationInput) {
        CVMState* state = (CVMState*)simulationState;
        vector<string> inputList = simulationInput->getInputList();
        for (vector<string>::iterator it = inputList.begin();
             it != inputList.end(); it++) {
            if (*it == "nickel") {
                state->incrementNickels();
            } else if (*it == "dime") {
                state->incrementDimes();
            } else if (*it == "quarter") {
                state->incrementQuarters();
            } else if (*it == "change") {
                state->setChangeSelected(true);
            } else if (*it == "wait") {
                state->setWaiting(true);
            }
        }
    }
}
