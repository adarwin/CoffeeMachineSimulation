/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#ifndef COFFEE_VENDING_MACHINE_H
#define COFFEE_VENDING_MACHINE_H
#include "SimulationModel.h"
#include <set>

namespace com_adarwin_simulation {
    class CVMState;
    class CVMSimulationModel : public SimulationModel {
        public:
            CVMSimulationModel(std::set<std::string>);
            void lambda(SimulationState*);
            void delta(SimulationState*, SimulationInput*);
        protected:
            std::set<std::string> acceptableInputs;
        private:
            bool shouldProvideChange(CVMState*);
            void changeStateForDispensedCoffee(CVMState*);
            void changeStateForDispensedChange(CVMState*);
    };
}
#endif

