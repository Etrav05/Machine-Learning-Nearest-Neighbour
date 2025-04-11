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

void handleInput(double& xyz, int& xyzEntered, double& x, double& y, double& z, int xEntered, int yEntered, int zEntered, NNClassifer& data, vector<vector<double>>& trainingData, Menu& m) {
   
    try {
        acceptSampleData(xyz);
        xyzEntered = 1;
    }
    catch (Character_Detected cd) {
        cout << cd.what() << endl;
        Sleep(1500);
    }
    catch (Greater_Or_Less_Than_Range glr) {
        cout << glr.what() << endl;
        Sleep(1500);
    }

    system("cls");

    if (xEntered == 1 && yEntered == 1 && zEntered == 1) {
        vector<double> testPoint = { x, y, z };
        vector<double> result = data.performClassification(testPoint, trainingData);

        m.setCursorPosition(0, 8);
        cout << result[0] << ", " << result[1] << ", " << result[2] << ", " << endl;
        cout << "Predicted label: " << result[3] << endl;
    }
}