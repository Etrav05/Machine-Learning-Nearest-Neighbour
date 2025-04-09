#include "NN_Classifier.h"
#include "Exception_String_Input.h"
#include "menu.h"

NNClassifer::NNClassifer() {
    cout << "Must've been the wind" << endl;
}

/*
-z = face up
 z = face down
-y = portrait
 y = portrait upside down
-x = landscape left
 x = landscape right
*/

double difference(double i) {
    if (i > 0) { return  1 - i; }
    else { return 1 + i; }
}

bool acceptSampleData(double& i) {
    cout << "\nEnter value (-1 >= 1): ";

    string input;
    cin >> input;

    bool isValid = true;    // set a bool for if the input is acceptable

    for (char c : input) {                                      // now for all the characters in this input
        if (!isdigit(c) && c != '-' && c != '.' && c != ',') { // check if theya re a digit or an acceptable char (. , or -)
            isValid = false;                                  // if there is something other than the accpeted digits or chars, then the input is NOT valid
            cout << "Invalid entry" << endl;
            Sleep(750);
            return false;
        }

        else
            i = stod(input);
    }

    if (i < -1 || i > 1) {                               // cheack if the input is between -1 and 1;
        i = 0;
        cout << "Invalid entry" << endl;
        Sleep(750);
        return false;
    }

    return true;
}

void NNClassifer::sampleDataOrientation(double x, double y, double z) {
    setCursorPosition(0, 9);
    
    double a = difference(x);
    double b = difference(y);
    double c = difference(z);
    double temp;

    temp = a; // find least difference
    if (b < temp) temp = b;
    if (c < temp) temp = c;

    cout << "Orientation: ";

    if (temp == a) { cout << (x < 0 ? "Landscape left" : "Landscape right") << endl; } // given the lowest difference, check if the inital value (x, y, z) was + or -, print orientation based on this
    if (temp == b) { cout << (y < 0 ? "Portrait" : "Portrait upside down") << endl; }
    if (temp == c) { cout << (z < 0 ? "Face up" : "Face down") << endl; }
}

void orientation(int xEntered, int yEntered, int zEntered, double x, double y, double z) {
    NNClassifer sample;
    setCursorPosition(0, 8);

    if (xEntered == 1 && yEntered == 1 && zEntered == 1) {
        sample.sampleDataOrientation(x, y, z);
    }
    else {
        cout << "Please enter value(s) for: " << (xEntered == 0 ? "x " : " ") << (yEntered == 0 ? "y " : " ") << (zEntered == 0 ? "z " : " ") << endl;
    }
    setCursorPosition(0, 0);
}

int NNClassifer::sampleData(int& selected, double& x, double& y, double& z, int& xEntered, int& yEntered, int& zEntered) { // output will be orientation 

    hideCursor(0);             // hides the cursor while redrawing
    setCursorPosition(0, 0);  // redraws the console screen (Windows)
    cout << "Enter orientation sample data:\n" << endl;

    cout << (selected == 0 ? " >" : " ") << "    x = " << (xEntered == 1 ? x : 0) << " " << endl; // will allow the user to see their entry as they go
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
        setCursorPosition(0, 5); // print message below menu but continue menus funtion
        hideCursor(1);          // show cursor when typing

        switch (selected) { 
        case 0: // x          
            if (acceptSampleData(x)) {  // check each entry for characters
                xEntered = 1;
            }

            system("cls");
            orientation(xEntered, yEntered, zEntered, x, y, z);
            break;
        case 1: // y
            if (acceptSampleData(y)) {
                yEntered = 1;
            }

            system("cls");
            orientation(xEntered, yEntered, zEntered, x, y, z);
            break;
        case 2: // z
            if (acceptSampleData(z)) { 
                zEntered = 1;
            }

            system("cls");
            orientation(xEntered, yEntered, zEntered, x, y, z);
            break;
        }
    }

    else if (ch == 27) {
        return 1;
    }

    return 0;
}
