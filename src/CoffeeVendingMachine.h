/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#ifndef COFFEE_VENDING_MACHINE_H
#define COFFEE_VENDING_MACHINE_H

namespace com_adarwin_simulation {
    class CoffeeVendingMachine : SimulationModel {
        public:
            void lambda(SimulationState);
            void delta(SimulationInput);
    };
}
#endif

