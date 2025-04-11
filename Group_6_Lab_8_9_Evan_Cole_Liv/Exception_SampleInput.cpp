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
   
    string labels[6] = { "Face up", "Face down", "Portrait", "Portrait upside down", "Landscape left", "Landscape right" };

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

    if (xEntered + yEntered + zEntered >= 2) {
        vector<double> testPoint = { x, y, z };
        vector<double> result = data.performClassification(testPoint, trainingData);

        int i = result[3];

        m.setCursorPosition(0, 8);
        cout << "Predicted label: " << labels[i - 1] << endl;
    }
}