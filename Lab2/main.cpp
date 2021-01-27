/* 
 * File:   main.cpp
 * Author: Alex Spacek
 *
 * Created on September 29, 2020, 10:41 AM
 * 
 * COMP139E Lab 2 - Grades
 * Prompts for a pair of grade and weight until the user chooses to stop, then
 * converts the total grade to a letter.
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

// min/max allowable input values
const double minMark = 0.0, maxMark = 100.0, minWeight = 1.0, maxWeight = 50.0;
const double minWeightSum = 99.0, maxWeightSum = 101.0;

/**
 * A reusable function for getting validated in-range numbers.
 * Repeatedly asks for the value if an out-of-range number gets entered
 *
 * @param prompt A string such as "Enter the mark"
 * @param number A pointer to the number we are trying to read
 * @param min The minimum permissible value
 * @param max The maximum permissible value  
 *
 * @return true if the input contains only numeric characters, false otherwise
 */
bool getValidNumber(string prompt, double *value, const double min, const double max);

/**
 * Converts numerical grades to alphabetical
 * 
 * @param mark A percentage representing a grade
 * @return A string containing a letter grade e.g. "A+"
 */
string gradeFromMark(const double mark);

/*
 * 
 */
int main(int argc, char** argv) {    
    cout << "This program computes a letter grade from a weighted sum of marks." << endl
        << "Minimum allowable mark is " << minMark << ", maximum is " << maxMark << endl
        << "Minimum allowable weight is " << minWeight << ", maximum is " << maxWeight << endl
        << "Weights must total 100%" << endl
        << "Enter a non-numeric character to terminate your list" << endl << endl;
    
    double total = 0, sumWeights = 0;
    bool bRun = true;
    
    while (bRun) {
        double weight = 0, mark = 0;
        
        // prompt for two numbers in sequence, if either is not a number we finish the loop
        bRun = getValidNumber("Enter a mark in percent: ", &mark, minMark, maxMark);
        if (bRun) {
            bRun = getValidNumber("Enter a weight in percent: ", &weight, minWeight, maxWeight);   
        }
        
        sumWeights += weight;
        total += mark * weight / 100;
    }
    
    
    if (sumWeights < minWeightSum || sumWeights > maxWeightSum){
        cout << "Invalid weight total, no grade will be computed.";
        return EXIT_FAILURE;
    }
    
    cout << "Mark is " << total << " and grade is " << gradeFromMark(total);
    
    return EXIT_SUCCESS;
}

bool getValidNumber(string prompt, double *value, const double min, const double max){
   
    do {        
        cout << prompt << endl;
        cin >> *value;
        
        if (cin.good() == false) {   // Invalid Input (not a number in this case)
            cin.clear();             // Clear the error flags
            cin.ignore(255, '\n');   // Throw away the line of input
            // This cout should be where your call to this function returns false
            cout << "List completed." << endl; 
            return false;
        }
    // loop until a value within our range is entered
    } while (*value > max || *value < min);
    
    return true;
}

string gradeFromMark(const double mark){

    if (mark >= 90) {
            return "A+";
    } else if  (mark >= 85) {
            return "A";
    } else if  (mark >= 80) {
            return "A-";
    } else if  (mark >= 77) {
            return "B+";
    } else if  (mark >= 73) {
            return "B";
    } else if  (mark >= 70) {
            return "B-";
    } else if  (mark >= 65) {
            return "C+";
    } else if  (mark >= 60) {
            return "C";
    } else if  (mark >= 50) {
            return "D";     
    } else {
        return "F";
    }
}