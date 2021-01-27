/*
 * Implementation of the Square class
 *
 * File:   Square.cpp
 * Author: alex spacek
 *
 */
#include "Square.hpp"
#include <iostream>

/**
 * The draw() member function
 */

void Square::draw() const {
    std::cout << "Square of size " << getWidth() << " drawn at " << getX() << " " << getY() << std::endl;
}

//can't access the private member variables of Rectangle so we use getWidth instead
void Square::printMe(std::ostream& os) const {
    os << "Square of size "  << getWidth() << " at " << getX() << " " << getY();
}
