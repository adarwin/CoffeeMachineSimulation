/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#include "SimulationModel.h"

namespace com_adarwin_simulation {
    SimulationModel::SimulationModel(std::set<std::string> acceptableInputs) :
                                           acceptableInputs(acceptableInputs) {
    }
}
