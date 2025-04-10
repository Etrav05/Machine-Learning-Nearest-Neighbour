#include "Exception_SampleInput.h"

void acceptSampleData(double& i) {
    cout << "\nEnter value (-1 >= 1): ";
    
    Character_Detected cd;
    Greater_Or_Less_Than_Range glr;

    string input;
    cin >> input;

    for (char c : input) {                                      // now for all the characters in this input
        if (!isdigit(c) && c != '-' && c != '.' && c != ',') { // check if theya re a digit or an acceptable char (. , or -)
            throw cd;
        }

        else
            i = stod(input);
    }

    if (i < -1 || i > 1) { // check if the input is between -1 and 1;
        i = 0;
        throw glr;
    }
}