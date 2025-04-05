#include "NN_Classifier.h"
#include "menu.h"

NNClassifer::NNClassifer() {

}

void NNClassifer::sampleData(double x, double y, double z, int selected) { // output will be orientation 
    int choice = 0;
    int xEntered = 0;
    int yEntered = 0;
    int zEntered = 0;

    hideCursor();             // hides the cursor while redrawing
    setCursorPosition(0, 0); // redraws the console screen (Windows)
    cout << "Enter orientation sample data:\n" << endl;

    cout << (selected == 0 ? ">" : " ") << "    x = " << (xEntered == 1 ? x : 0) << endl;
    cout << (selected == 1 ? ">" : " ") << "    y = " << (yEntered == 1 ? y : 0) << endl;
    cout << (selected == 2 ? ">" : " ") << "    z = " << (zEntered == 1 ? z : 0) << endl;

    int ch = _getch();

    if (ch == 224) {
        ch = _getch();

        if (ch == 72 && selected > 0) // up Arrow
            selected--;

        else if (ch == 80 && selected < MENU_ITEMS - 1) // down Arrow
            selected++;
    }

    else if (ch == 13) {                     // enter key
        setCursorPosition(0, 6);            // print message below menu but continue menus funtion

        if (selected == 0) { // x
            cin >> x;
            xEntered = 1;
        }

        if (selected == 1) { // y
            cin >> y;
            yEntered = 2;
        }

        if (selected == 2) { // z
            cin >> z;
            zEntered = 3;
        }
    }
}

void NNClassifer::userDataFile(string filename) { // output another file named result.txt which includes your data (presuming this means the users data file) and the corresponding phone orientation (0.2872,0.8627,-0.9832,1,Face up)

}