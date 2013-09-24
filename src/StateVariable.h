/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#ifndef STATE_VARIABLE_H
#define STATE_VARIABLE_H

namespace com_adarwin_simulation {
    template <class T> class StateVariable {
        public:
            void setValue(T);
            T getValue();
        private:
            T value;
    };
}
#endif

