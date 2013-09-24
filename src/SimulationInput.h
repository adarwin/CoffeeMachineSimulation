/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#ifndef SIMULATION_INPUT_H
#define SIMULATION_INPUT_H
#include <vector>
#include <string>

namespace com_adarwin_simulation {
    class SimulationInput {
        public:
            SimulationInput(std::string);
            std::vector<std::string> getInputList();
        private:
            std::vector<std::string> inputList;
    };
}
#endif
