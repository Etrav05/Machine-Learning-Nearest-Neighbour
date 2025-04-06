#include "NN_Classifier.h"
#include "Exception_String_Input.h"
#include "menu.h"

NNClassifer::NNClassifer() {
    cout << "Must've been the wind" << endl;
}

void NNClassifer::sampleDataOrientation(double x, double y, double z) {

}

void NNClassifer::sampleData(int& selected, double& x, double& y, double& z, int& xEntered, int& yEntered, int& zEntered) { // output will be orientation 

    hideCursor(0);             // hides the cursor while redrawing
    setCursorPosition(0, 0);  // redraws the console screen (Windows)
    cout << "Enter orientation sample data:\n" << endl;

    cout << (selected == 0 ? ">" : " ") << "    x = " << (xEntered == 1 ? x : 0) << endl; // will allow the user to see their entry as they go
    cout << (selected == 1 ? ">" : " ") << "    y = " << (yEntered == 1 ? y : 0) << endl;
    cout << (selected == 2 ? ">" : " ") << "    z = " << (zEntered == 1 ? z : 0) << endl;
    cout << (selected == 3 ? ">" : " ") << "    Done?" << endl;

    int ch = _getch();

    if (ch == 224) {
        ch = _getch();

        if (ch == 72 && selected > 0) // up Arrow
            selected--;

        else if (ch == 80 && selected < MENU_ITEMS) // down Arrow
            selected++;
    }

    else if (ch == 13) {                       // enter key
        setCursorPosition(0, 6);              // print message below menu but continue menus funtion
        hideCursor(1);                       // show cursor when typing
        // User_Input_Contains_Character UICC; // catch user inputs which contain a character

        switch (selected) { 
        case 0: // x
            cout << "\nEnter value (0 >= 1): ";
            
            try {
                cin >> x;
            }
            catch (User_Input_Contains_Character UICC) {
                cout << UICC.what() << endl;
            }

            if (x < 0 || x > 1) {
                x = 0;
                cout << "Invalid entry" << endl;
                Sleep(750);
            }
            else 
                xEntered = 1;
   
            system("cls");
            break;
        case 1: // y
            cout << "\nEnter value (0 >= 1): ";
            cin >> y;

            if (y < 0 || y > 1) {
                y = 0;
                cout << "Invalid entry" << endl;
                Sleep(750);
            }
            else
                yEntered = 1;

            system("cls");
            break;
        case 2: // z
            cout << "\nEnter value (0 >= 1): ";
            cin >> z;

            if (z < 0 || z > 1) {
                z = 0;
                cout << "Invalid entry" << endl;
                Sleep(750);
            }
            else
                zEntered = 1;

            system("cls");
            break;
        case 3: // done option
            if (xEntered == 1 && yEntered == 1 && zEntered == 1) {
                sampleDataOrientation(x, y, z);
            }
            else {
                cout << "Please enter value(s) for: " << (xEntered == 0 ? "x " : " ") << (yEntered == 0 ? "y " : " ") << (zEntered == 0 ? "z " : " ") << endl;
            }
            break;
        }
    }
}

void NNClassifer::userDataFile(string filename) { // output another file named result.txt which includes your data (presuming this means the users data file) and the corresponding phone orientation (0.2872,0.8627,-0.9832,1,Face up)

}