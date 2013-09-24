/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#ifndef SIMULATION_MODEL_H
#define SIMULATION_MODEL_H

namespace com_adarwin_simulation {
    class SimulationState;
    class SimulationInput;

    class SimulationModel {
        public:
            virtual void lambda(SimulationState);
            virtual void delta(SimulationInput);
    };
}
#endif
