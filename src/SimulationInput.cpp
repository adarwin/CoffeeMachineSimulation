/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#include <iostream>
#include <vector>
#include <string>
#include "SimulationInput.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

namespace com_adarwin_simulation {
    SimulationInput::SimulationInput(string inputString) {
        string currentString;
        for (string::iterator it = inputString.begin();
             it != inputString.end(); it++) {
            if (*it != ' ' && *it != ',') {
                currentString += *it;
            }
            inputList.push_back(currentString);
            currentString = "";
            /*
            if (*it == ',' || it == inputString.end()-1) {
                inputList.push_back(currentString);
                currentString = "";
            }
            */
        }
    }

    vector<string> SimulationInput::getInputList() {
        return inputList;
    }
}
