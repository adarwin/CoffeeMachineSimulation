/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#include "StateVariable.h"

namespace com_adarwin_simulation {

    template <class T> void StateVariable<T>::setValue(T newValue) {
        value = newValue;
    }

    template <class T> T StateVariable<T>::getValue() {
        return value;
    }
}
