/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

package com.adarwin.simulation;

public class CVMState implements SimulationState {
    int numNickels, numDimes, numQuarters;
    boolean changeSelected;
    public CVMState() {
        this(0, 0, 0, false);
    }
    public CVMState(int nickels, int dimes, int quarters,
                    boolean changeSelected) {
        numNickels = nickels;
        numDimes = dimes;
        numQuarters = quarters;
        this.changeSelected = changeSelected;
    }
}
