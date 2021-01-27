/*
 * A main() to demonstrate inheritance, polymorphism, virtual functions,
 * and an abstract class.
 * Uses classes: Shape, Rectangle, and Circle.
 * 
 * File:   main.cpp
 * Author: dale
 *
 * Created on November 7, 2011, 2:27 PM
 * 
 * modified by Alex Spacek on November 3, 2020
 */

#include <iostream>
#include <cstdlib>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Stack.hpp"
#include "Square.hpp"

int main(int argc, char* argv[]) {
    Circle c1(20.5, 4, 10);
    Rectangle r1(10, 20.7, 8, 8);
    Circle c2(11, 10, 5);
    Square s1(9, 20, 22);
    

    /* 
     */
    Stack<Shape*> shapes;
    shapes.push(&c1);
    shapes.push(&r1);
    shapes.push(&c2);
    shapes.push(&s1);

    c1.moveTo(27, 36);         // move the first circle
    
    shapes.top()->moveTo(17, 4);  // this will move the square

    /* Draw all of the Shapes.
    */
    while (!(shapes.isEmpty())){

        try {           
            // save the popped shape so we can use it twice
            Shape* currentShape = shapes.pop();

            // Each shape knows how to draw itself
            currentShape->draw();        

            std::cout << *currentShape << std::endl;
        } 
        catch (StackException& e)
        {
            std::cout << e.getMessage();
        }
      
    }

    try {         
    shapes.pop();
    } 
    catch (StackException& e)
    {
        std::cout << e.getMessage();
    }
    return EXIT_SUCCESS;
}

