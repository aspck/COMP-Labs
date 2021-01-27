/* 
 * File:   spherical.cpp
 * Author: Alex Spacek
 *
 * Created on October 6, 2020, 11:14 AM
 */
#include "spherical.hpp"

double *sphericalToRectangular (double r, double azimuth, double inclination){
    double *c = new double[3];
    
    c[0] = r * sin(inclination) * cos(azimuth);
    c[1] = r * sin(inclination) * sin(azimuth);
    c[2] = r * cos(inclination);
    
    return c;
}

SphericalCoords rectangularToSpherical (double x, double y, double z){
    SphericalCoords s;
    
    s.radius = getRadius(x,y,z);
    s.azimuth = atan2(y,x);
    s.inclination = atan2(sqrt(x*x+y*y), z);

    return s;
}