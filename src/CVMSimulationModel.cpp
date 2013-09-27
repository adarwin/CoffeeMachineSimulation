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
        //cout << "State before lambda:" << endl << state->getString() << endl;
        //cout << "Lambda executes" << endl << endl;
        // Determine whether coffee is due
        if (numberOfCoffeesToDispense(state) >= 1) {//shouldDispenseCoffee(state)) {
            int numberOfCoffees = numberOfCoffeesToDispense(state);
            cout << "Have ";
            if (numberOfCoffees == 1) {
                cout << "a coffee!";
            } else {
                cout << numberOfCoffees << " coffees!";
            }
            cout << endl;
        }
        if (shouldProvideChange(state)) {
            int change = centsToDispense(state);
            double changeInDollars = (double)change/100;
            cout << "Your change is $" << changeInDollars << endl;
        }
        //cout << endl << "State after lambda:" << endl << state->getString() << endl;
    }

    void CVMSimulationModel::delta(SimulationState* simulationState,
                                   SimulationInput* simulationInput) {
        CVMState* state = (CVMState*)simulationState;
        //CVMInput* input = (CVMInput*)simulationInput;
        //cout << "Input before delta:" << input->getString() << endl;
        //cout << "Delta executes" << endl << endl;
        if (numberOfCoffeesToDispense(state) >= 1) {//shouldDispenseCoffee(state)) {
            changeStateForDispensedCoffee(state);
        }
        if (shouldProvideChange(state)) {
            changeStateForDispensedChange(state);
        }
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
        //cout << "State after delta:" << endl << state->getString() << endl;
    }

    int CVMSimulationModel::numberOfCoffeesToDispense(CVMState* state) {
        int cents = state->getCurrentCents();
        return cents/100;
    }

    bool CVMSimulationModel::shouldProvideChange(CVMState* cvmState) {
        return cvmState->isChangeSelected();
    }
    int CVMSimulationModel::centsToDispense(CVMState* state) {
        return state->getCurrentCents()%100;
    }

    void CVMSimulationModel::changeStateForDispensedCoffee(CVMState* cvmState) {
        int numberOfCoffees = numberOfCoffeesToDispense(cvmState);
        if (!cvmState->moveCentsToTotalStorage(numberOfCoffees*100)) {
            cout << "The cents did not all move properly!!!" << endl;
        }
    }
    void CVMSimulationModel::changeStateForDispensedChange(CVMState* state) {
        int change = centsToDispense(state);
        state->removeCents(change);
        state->setChangeSelected(false);
    }
}
