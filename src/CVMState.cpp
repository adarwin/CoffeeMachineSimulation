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

}
