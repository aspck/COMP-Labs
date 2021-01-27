/* 
 * File:   main.cpp
 * Author: Alex Spacek
 *
 * Created on September 17, 2020, 1:43 PM
 * 
 * COMP139E Lab 1 - Streetlights
 * Calculates number of streetlights for a curved road, given radius of the 
 * curve, chord length and minimum spacing
 */

#include <cstdlib>
#include <cmath>
#include "helper.h"

using namespace std;

/*
 * The main() calls functions for user input and output of results.
 * It also calculates the distance and angle for each streetlight in a loop.
 */
int main(int argc, char** argv) {
    double radius = 0, pegDist = 0, spacing = 0;
    
    getUserInput(radius, pegDist, spacing);
    
    /* calculate the angle between the two pegs */
    double arcAngle = 2 * asin(pegDist / radius / 2);
    
    /* divide total arc length by the maximum spacing to get # of sectors */
    int numSectors = ceil(radius * arcAngle / spacing);
    
    /* number of street lights = number of sectors + 1 */
    double angles[numSectors + 1];
    double pegDists[numSectors + 1];
    
    /* exception for the last light which is always the length of the chord */
    angles[numSectors] = 0;
    pegDists[numSectors] = pegDist;
    
    /* for each sector, compute the angle and distance from peg 1 */
    for (int c = 0; c < numSectors; c++) {
        double sectorHalfAngle = arcAngle * c / 2 / numSectors;        
        pegDists[c] = 2 * radius * sin(sectorHalfAngle);
        angles[c] = (arcAngle / 2) - sectorHalfAngle;        
    }
        
    outputResults(angles, pegDists, numSectors+1);
    
    return 0;
}

