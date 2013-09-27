/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#include "CVMInput.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::stringstream;
using std::vector;
using std::endl;

namespace com_adarwin_simulation {
    CVMInput::CVMInput(string inputString) : SimulationInput(inputString) {}
    string CVMInput::getString() {
        stringstream ss;
        ss << "  ";
        for (vector<string>::iterator it = inputList.begin();
             it != inputList.end();
             it++)
        {
            ss << *it << " ";
        }
        ss << endl;
        return ss.str();
    }
}
