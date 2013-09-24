/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#ifndef CVM_STATE_H
#define CVM_STATE_H
#include "SimulationState.h"

namespace com_adarwin_simulation {
    class CVMState : public SimulationState {
        public:
            CVMState();
            CVMState(int, int, int, bool);
            //void setVariable(std::string name, StateVariable<int>);
            int getNumNickels();
            int getNumDimes();
            int getNumQuarters();
            bool isChangeSelected();
            bool isWaiting();
            void incrementNickels();
            void incrementDimes();
            void incrementQuarters();
            void setChangeSelected(bool);
            void setWaiting(bool);
            int getTotalCents();
        private:
            int numNickels, numDimes, numQuarters;
            bool changeSelected, waiting;
    };
}
#endif
