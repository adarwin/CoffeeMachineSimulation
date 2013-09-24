/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#ifndef SIMULATION_MODEL_H
#define SIMULATION_MODEL_H
#include <set>
#include <string>

namespace com_adarwin_simulation {
    class SimulationState;
    class SimulationInput;

    class SimulationModel {
        public:
            SimulationModel(std::set<std::string>);
            virtual void lambda(SimulationState*) = 0;
            virtual void delta(SimulationState*, SimulationInput*) = 0;
        protected:
            std::set<std::string> acceptableInputs;
    };
}
#endif
