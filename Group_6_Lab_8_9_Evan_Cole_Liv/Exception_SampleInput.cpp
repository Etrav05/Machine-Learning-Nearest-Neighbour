#include "Exception_SampleInput.h"

void acceptSampleData(double& i) {
    cout << "\nEnter value (-1 >= 1): ";
    
    Character_Detected cd;
    Greater_Or_Less_Than_Range glr;

    string input; // accept input as a string 
    cin >> input;

    for (char c : input) {                          // now for all the characters in this input
        if (!isdigit(c) && c != '-' && c != '.') { // check if they are a digit or an acceptable char (. or -) or a digit
            throw cd;                             // if not, throw exceptions
        }

        else
            i = stod(input);
    }

    if (i < -1 || i > 1) { // check if the input is between -1 and 1;
        i = 0;
        throw glr;
    }
}