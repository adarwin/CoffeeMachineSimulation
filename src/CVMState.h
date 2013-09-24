/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

#ifndef CVM_STATE_H
#define CVM_STATE_H
namespace com_adarwin_simulation {
    class CVMState {
        public:
            CVMState();
            CVMState(int, int, int, bool);
        private:
            int numNickels, numDimes, numQuarters;
            bool changeSelected;
    };
}
#endif
