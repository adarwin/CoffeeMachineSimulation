/* Andrew Darwin
 * www.adarwin.com
 * Fall 2013
 * CSC 454: System Simulation
 */

package com.adarwin.simulation;

public interface SimulationModel {
    public void lambda(SimulationState state);
    public void delta(SimulationInput inputs);
}
