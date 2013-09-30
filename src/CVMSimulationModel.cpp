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
#include "CVMInput.h"

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
        CVMState* state = (CVMState*)simulationState;
        CVMState tempState(state->getCurrentQuarters(),
                           state->getCurrentDimes(),
                           state->getCurrentNickels(),
                           state->getTotalQuarters(),
                           state->getTotalDimes(),
                           state->getTotalNickels(),
                           state->isChangeSelected());
        // Determine whether coffee is due
        if (tempState.numberOfCoffeesToDispense() >= 1) {
            int numberOfCoffees = tempState.numberOfCoffeesToDispense();
            cout << "Have ";
            if (numberOfCoffees == 1) {
                cout << "a coffee!";
            } else {
                cout << numberOfCoffees << " coffees!";
            }
            cout << endl;
            tempState.changeStateForDispensedCoffee();
        }
        if (shouldProvideChange(&tempState)) {
            int change = state->centsToDispense();
            if (change != tempState.centsToDispense()) {
                cout << "Can't produce the necessary change, sorry." << endl;
            } else {
                double changeInDollars = (double)change/100;
                int* changeArray = new int[3];
                changeArray = tempState.changeStateForDispensedChange(changeArray);
                if (changeArray != NULL)
                {
                    cout << "Your change is $" << changeInDollars
                         << ", composed of " << changeArray[0];
                    if (changeArray[0] == 1 )
                        cout << " quarter, ";
                    else
                        cout << " quarters, ";
                    cout << changeArray[1];
                    if (changeArray[1] == 1)
                        cout << " dime, ";
                    else
                        cout << " dimes, ";
                    cout << "and " << changeArray[2];
                    if (changeArray[2] == 1)
                        cout << " nickel";
                    else
                        cout << " nickels";
                    cout << endl;
                } else {
                    cout << "You don't get any change, sorry" << endl;
                }
                delete changeArray;
            }
        }
    }




    void CVMSimulationModel::delta(SimulationState* simulationState,
                                   SimulationInput* simulationInput) {
        CVMState* state = (CVMState*)simulationState;
        /* Modify the current state so it matches what must have happened
           during the last call to lambda */
        if (state->numberOfCoffeesToDispense() >= 1) {
            state->changeStateForDispensedCoffee();
        }
        if (shouldProvideChange(state)) {
            int* changeArray = new int[3];
            state->changeStateForDispensedChange(changeArray);
            delete changeArray;
        }

        // Modify the current state in accordance with the input
        vector<string> inputList = simulationInput->getInputList();
        for (vector<string>::iterator it = inputList.begin();
             it != inputList.end(); it++) {
            if (*it == "nickel" || *it == "n") {
                state->incrementCurrentNickels();
            } else if (*it == "dime" || *it == "d") {
                state->incrementCurrentDimes();
            } else if (*it == "quarter" || *it == "q") {
                state->incrementCurrentQuarters();
            } else if (*it == "change" || *it == "c") {
                state->setChangeSelected(true);
            } else if (*it == "wait" || *it == "w") {
                state->setWaiting(true);
            }
        }
    }

    bool CVMSimulationModel::shouldProvideChange(CVMState* cvmState) {
        return cvmState->isChangeSelected();
    }

}
