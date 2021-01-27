/* 
 * Lab 7 - Standard Template Vectors
 * 
 * Demonstrates usage of vector functions {push_back, [], front, back, size,
 *  capacity, insert, pop_back, at, max_size}
 * and methods of looping with iterators.
 * 
 * File:   main.cpp
 * Author: Alex Spacek
 *
 * Created on November 7, 2020, 6:30 PM
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Rectangle.hpp"
#include "Circle.hpp"


using namespace std;

// this is probably a bad idea - enabled with c++14 compile option '-fconcepts'
inline void report(const vector<auto> &v) {
    cout << "current size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl << endl;
}

int main(int argc, char** argv) {
    Circle c1(20.5, 4, 10);
    Rectangle r1(10, 20.7, 8, 8);
    Circle c2(11, 10, 5);
    Rectangle r2(5, 6, 1, 1);
    Circle c3(4, 12, 40);

    vector<Shape*> v;
    vector<int> v2 = {1, 2, 3, 4};

    // store some shape pointers in the vector
    v.push_back(&c1);
    v.push_back(&r1);

    cout << "vector of Shape*s:" << endl;
    cout << "max size in theory: " << v.max_size() << endl;
    report(v);
    cout << "vector of ints:" << endl;
    cout << "max size in theory: " << v2.max_size() << endl;
    report(v2);

    cout << "drawing " << v.size() << " shapes:" << endl;
    for (vector<Shape*>::iterator ihead = v.begin(); ihead != v.end(); ihead++) {
        (*ihead)->draw();
    }
    cout << endl;

    // add two shapes to the end- this will cause a reallocation!    
    v.push_back(&r2);
    v.push_back(&c2);

    cout << "drawing " << v.size() << " shapes:" << endl;
    for (int c = 0; c < v.size(); c++) {
        try {
            v.at(c)->draw();
        } catch (std::out_of_range& oor) {
            cerr << "out of range error:  " << oor.what() << endl;
            break;
        }
    }
    cout << endl;

    v.push_back(&c3);

    cout << "drawing " << v.size() << " shapes:" << endl;
    for (auto i = v.begin(); i != v.end(); i++) { // second way to use iterators
        (*i)->draw();
    }
    cout << endl;

    cout << "removing last element from vector..." << endl;
    v.pop_back();
    report(v);

    cout << "setting first element to a copy of last element..." << endl;
    v.front() = v.back();
    for (auto i2 : v) { // third way to use iterators
        i2->draw();
    }
    cout << endl;

    cout << "but c1 is unchanged: " << endl;
    c1.draw();

    cout << endl << "modifying c2 is reflected in both vector elements: " << endl;
    c2.moveTo(3, 3);
    v[0]->draw();
    v[3]->draw();

    // do something to hopefully cause an exception
    long nbig = 100000000000;
    cout << endl << "inserting " << nbig << " shapes into vector... " << endl;
    try {
        v.insert(v.begin(), nbig, &c3);
    } catch (std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }

    report(v);

    return EXIT_SUCCESS;
}

