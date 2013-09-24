/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#ifndef CVM_INPUT_H
#define CVM_INPUT_H
#include "SimulationInput.h"
#include <string>

namespace com_adarwin_simulation {
    class CVMInput : public SimulationInput {
        public:
            CVMInput(std::string);
    };
}
#endif
