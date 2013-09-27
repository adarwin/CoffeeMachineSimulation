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
            CVMState(int, int, int);
            //void setVariable(std::string name, StateVariable<int>);
            int getCurrentNickels();
            int getCurrentDimes();
            int getCurrentQuarters();
            bool isChangeSelected();
            bool isWaiting();
            void incrementCurrentNickels();
            void incrementCurrentDimes();
            void incrementCurrentQuarters();
            void setChangeSelected(bool);
            void setWaiting(bool);
            int getTotalCents();
            int getCurrentCents();
            bool moveCentsToTotalStorage(int);
            bool removeCents(int);
            std::string getString();
        private:
            bool moveCurrentCents(int, bool);
            std::string getStringLine(std::string, int, int);
            std::string getRightPadding(std::string, int);
            int numDigits(int);
            int totalNickels, totalDimes, totalQuarters;
            int currentNickels, currentDimes, currentQuarters;
            bool changeSelected, waiting;
    };
}
#endif
