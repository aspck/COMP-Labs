/* 
 * File:   PID_Controller.cpp
 * Author: Alex Spacek C0401123
 *
 * Created 20-OCT-2020
 */

#include "PID_Controller.hpp"

// Implementation of controlStep()
double PID_Controller::controlStep (const double plantOutput, double setpoint) {
    // calculate the integral approximation
    double q = 0.9 * qPrev + 0.1 * (setpoint - plantOutput);
    // calculate the integral term
    double iComponent = q / ti; 
    
    // calculate the derivative term
    double dComponent = td * (plantOutput - plantOutputPrev);    
    
    // implement equation (3) from lab manual
    double x = setpoint + kc * (setpoint - plantOutput + iComponent - dComponent);
    
    // update state variables for next step    
    plantOutputPrev = plantOutput; 
    qPrev = q;
    
    // return controller output
    return x;
}
