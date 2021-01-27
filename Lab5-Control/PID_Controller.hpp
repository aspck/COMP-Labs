/* 
 * File:   PID_Controller.hpp
 * Author: Alex Spacek C0401123
 *
 * Created 20-OCT-2020
 * 
 * Implements a stateful PID controller that computes one step of a controller
 * response. Uses a leaky integration approximation for the I component.
 * 
 */

#ifndef PID_CONTROLLER_HPP
#define PID_CONTROLLER_HPP

#include "Controller.hpp"

class PID_Controller : public Controller {
private:
    const double kc;  // The proportional gain
    const double ti;  // The inverse of the integral constant
    const double td;  // The derivative constant
    
    double qPrev;
    double plantOutputPrev;
public:
    /**
     * Constructor copies the gains and initializes the state variables to 0
     *
     * @param propGain The proportional gain
     * 
     * @param intGain The integral gain
     * 
     * @param derivGain The derivative gain
     * 
     */
    PID_Controller (const double propGain, const double intGain, const double derivGain) : 
                    kc(propGain), ti(intGain), td(derivGain), qPrev(0), plantOutputPrev(0) {   };
    
    // Our promise to implement the function from the abstract base class
    double controlStep (double plantOutput, double setpoint);
};

#endif /* PID_CONTROLLER_HPP */

