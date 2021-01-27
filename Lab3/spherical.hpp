/* 
 * File:   spherical.hpp
 * Author: Alex Spacek
 *
 * Lab 3 - Modules, Testing, and Trigonometry
 * Provides functions to convert between spherical and rectangular coordinates.
 * 
 * 
 * 
 */

#ifndef SPHERICAL_HPP
#define SPHERICAL_HPP

#include <cmath>

const double M_PI = 3.14159265358979323846;

typedef struct {
    double radius;
    double azimuth;
    double inclination;
} SphericalCoords;

/*
 * Computes the distance from the origin to a point in 3d space
 */
inline double getRadius (double x=0, double y=0, double z=0){
    return sqrt(x*x + y*y + z*z);
}

/* 
 * Converts spherical coordinates to rectangular. Uses new to allocate memory,
 * caller should use delete[] to free memory when the array is no longer needed
 * 
 * Valid ranges for the spherical coordinates:
 * @param r radius >= 0.0
 * @param azimuth -pi < azimuth <= pi
 * @param inclination -pi < inclination <= pi, default pi/2
 *
 * @return pointer to the new array [x,y,z]
 */
double *sphericalToRectangular (double r=0, double azimuth=0, double inclination=M_PI/2);

/* 
 * Converts rectangular coordinates to spherical
 * 
 * @param x x-coordinate
 * @param y y-coordinate
 * @param z z-coordinate, default 0
 *
 * @return a SpehericalCoords struct with the spherical coordinates
 */
SphericalCoords rectangularToSpherical (double x, double y, double z=0);  


#endif /* SPHERICAL_HPP */

