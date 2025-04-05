#include "NN_Classifier.h"
#include "menu.h"

NNClassifer::NNClassifer() {
    cout << "Must've been the wind" << endl;
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

    else if (ch == 13) {                     // enter key
        setCursorPosition(0, 6);            // print message below menu but continue menus funtion
        hideCursor(1);                     // show cursor when typing

        switch (selected) { 
        case 0:
            cout << "\nEnter value (0 >= 1): ";
            cin >> x;
            xEntered = 1;
            system("cls");
            break;
        case 1:
            cout << "\nEnter value (0 >= 1): ";
            cin >> y;
            yEntered = 1;
            system("cls");
            break;
        case 2:
            cout << "\nEnter value (0 >= 1): ";
            cin >> z;
            zEntered = 1;
            system("cls");
            break;
        case 3:          // done case
          
            break;
        }
    }
}

void NNClassifer::userDataFile(string filename) { // output another file named result.txt which includes your data (presuming this means the users data file) and the corresponding phone orientation (0.2872,0.8627,-0.9832,1,Face up)

}