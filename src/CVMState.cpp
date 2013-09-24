/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#include "CVMState.h"

namespace com_adarwin_simulation {
    CVMState::CVMState() {
    }

    CVMState::CVMState(int nickels, int dimes, int quarters,
                       bool changeSelected) :
                       numNickels(nickels), numDimes(dimes),
                       numQuarters(quarters), changeSelected(changeSelected) {}

    int CVMState::getNumNickels() {
        return numNickels;
    }
    int CVMState::getNumDimes() {
        return numDimes;
    }
    int CVMState::getNumQuarters() {
        return numQuarters;
    }
    bool CVMState::isChangeSelected() {
        return changeSelected;
    }
    bool CVMState::isWaiting() {
        return waiting;
    }
    void CVMState::incrementNickels() {
        numNickels++;
    }
    void CVMState::incrementDimes() {
        numDimes++;
    }
    void CVMState::incrementQuarters() {
        numQuarters++;
    }
    void CVMState::setChangeSelected(bool value) {
        changeSelected = value;
    }
    void CVMState::setWaiting(bool value) {
        waiting = value;
    }
    int CVMState::getTotalCents() {
        return 5*numNickels + 10*numDimes + 25*numQuarters;
    }
}
