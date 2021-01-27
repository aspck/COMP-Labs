
/* 
 * inherits from rectangle
 * 
 * File:   Square.hpp
 * Author: Alex Spacek
 *
 * Created on November 3, 2020, 11:04 AM
 */

#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "Rectangle.hpp"

class Square : public Rectangle {
    protected:
    // we override the rectangle's print function to announce that we are a square...
    void printMe(std::ostream& os) const;
    public:
        inline Square(double l, int x, int y)
        : Rectangle(l, l, x, y) {            
        }
        void draw() const;
};

#endif /* SQUARE_HPP */

