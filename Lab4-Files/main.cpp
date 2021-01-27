/* 
 * File:   main.cpp
 * Author: Alex Spacek
 *
 * 
 * Lab 4 - Takes 2 files as command-line arguments. Reads characters from the 
 * first (input) file and separates them into words, then writes them individually
 * into the second file.
 * 
 * Created on October 12, 2020, 12:10 PM
 */

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <locale>
#include <functional>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 3){
        return EXIT_FAILURE;        
    }
    
    /* open input and output files */
    ifstream inText (argv[1]);
    ofstream outText (argv[2], std::ofstream::app);
    
    if (outText.fail()){
        return EXIT_FAILURE;
    }
    
    /* read characters until the stream is empty or an error occurs*/
    while (inText){
        string s;
        char c;
        
        /* append characters to string until a non-alphanumeric is read */
        while ( isalnum( c = inText.get()) ) {
            s += c;
        }        
        
        /* output string if it's alphabetic or digital */
        if (isalpha(s[0])){
            outText << "Found a " << s.length() << " letter word: " << s << endl;
        } else if (isdigit(s[0])){
            outText << "Found an integer: " << s << endl;           
        }                
    }
    
    inText.close();
    outText.close();

    return EXIT_SUCCESS;
}

