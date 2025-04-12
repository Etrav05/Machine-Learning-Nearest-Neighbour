#include "AcceptInput.h"

void AcceptInput::acceptSampleData(double& i) {
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

void AcceptInput::handleInput(double& xyz, int& xyzEntered, double& x, double& y, double& z, int xEntered, int yEntered, int zEntered, NNClassifer& data, vector<vector<double>>& trainingData, Menu& m) {
    AcceptInput accept;
    string labels[6] = { "Face up", "Face down", "Portrait", "Portrait upside down", "Landscape left", "Landscape right" };

    try {
        accept.acceptSampleData(xyz);
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

        data.training(trainingData);

        vector<double> testPoint = { x, y, z };
        vector<double> result = data.performClassification(testPoint);

        int i = result[3];

        m.setCursorPosition(0, 8);
        cout << "Predicted label: " << labels[i - 1] << endl;
    }
}

int AcceptInput::sampleData(int& selected, double& x, double& y, double& z, int& xEntered, int& yEntered, int& zEntered) { // output will be orientation 
    Menu m;
    NNClassifer data;
    ReadWriteFile rwf;
    AcceptInput accept;

    m.hideCursor(0);             // hides the cursor while redrawing
    m.setCursorPosition(0, 0);  // redraws the console screen (Windows)
    cout << "Enter orientation sample data:\n" << endl;

    cout << (selected == 0 ? " >" : " ") << "    x = " << (xEntered == 1 ? x : 0) << " " << endl; // will allow the user to see their entries as they go
    cout << (selected == 1 ? " >" : " ") << "    y = " << (yEntered == 1 ? y : 0) << " " << endl;
    cout << (selected == 2 ? " >" : " ") << "    z = " << (zEntered == 1 ? z : 0) << " " << endl;

    int ch = _getch();

    if (ch == 224) {
        ch = _getch();

        if (ch == 72 && selected > 0) // up Arrow
            selected--;

        else if (ch == 80 && selected < MENU_ITEMS - 1) // down Arrow
            selected++;
    }

    else if (ch == 13) {          // enter key
        m.setCursorPosition(0, 5); // print message below menu but continue menus funtion
        m.hideCursor(1);          // show cursor when typing

        string trainingFile = "trainingData.txt";
        vector<vector<double>> trainingData = rwf.createCoordinateGroups(trainingFile);

        switch (selected) {
        case 0: // x          
            accept.handleInput(x, xEntered, x, y, z, xEntered, yEntered, zEntered, data, trainingData, m);
            break;
        case 1: // y
            accept.handleInput(y, yEntered, x, y, z, xEntered, yEntered, zEntered, data, trainingData, m);
            break;
        case 2: // z
            accept.handleInput(z, zEntered, x, y, z, xEntered, yEntered, zEntered, data, trainingData, m);
            break;
        }
    }

    else if (ch == 27) { // esc key
        return 1;
    }

    return 0;
}