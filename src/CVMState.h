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
            CVMState(int quarters, int dimes, int nickels);
            CVMState(int currentQuarters, int currentDimes, int currentNickels,
                     int totalQuarters, int totalDimes, int totalNickels,
                     bool changeSelected);
            //void setVariable(std::string name, StateVariable<int>);
            int getCurrentNickels();
            int getCurrentDimes();
            int getCurrentQuarters();
            int getTotalQuarters();
            int getTotalDimes();
            int getTotalNickels();
            bool isChangeSelected();
            bool isWaiting();
            void incrementCurrentNickels();
            void incrementCurrentDimes();
            void incrementCurrentQuarters();
            void setChangeSelected(bool);
            void setWaiting(bool);
            int getTotalCents();
            int getCurrentCents();
            bool moveCentsToMainStorage(int);
            void moveChangeToMainStorage(int*);
            void moveChangeToTransactionStorage(int*);
            bool removeCents(int);
            std::string getString();
            bool canProvideChange();
            int* changeToProvide();
            int* makeChange(int changeCents, int quartersAvailable,
                            int dimesAvailable, int nickelsAvailable);
            int* makeChangeFor(int);
            int numberOfCoffeesToDispense();
            int centsToDispense();
            void changeStateForDispensedCoffee();
            int* changeStateForDispensedChange();
        private:
            void removeChangeFromTransactionStorage(int*);
            void addChangeToTransactionStorage(int*);
            void removeChangeFromMainStorage(int*);
            void addChangeToMainStorage(int*);
            bool moveCentsToTransactionStorage(int);
            bool moveCurrentCents(int, bool);
            std::string getStringLine(std::string, int, int);
            std::string getRightPadding(std::string, int);
            int numDigits(int);
            int currentQuarters, currentDimes, currentNickels;
            int totalQuarters, totalDimes, totalNickels;
            bool changeSelected, waiting;
    };
}
#endif
