#include "menu.h"

using namespace std;

void setCursorPosition(int x, int y) {      // this is a function made by windows to set a position to redraw an output from
    COORD coord = { (SHORT)x, (SHORT)y };  // rather than completly clear and redraw it (fixes the flickering issue)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {                                          // another windows made function to hide the cursor while redrawing the terminal
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // get the handle to the standard output (console)

    CONSOLE_CURSOR_INFO cursorInfo;                       // define the cursor info structure
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    cursorInfo.bVisible = 0;                             // set the cursor visibility to false (hide the cursor) --> 0 = false, 1 = true

    SetConsoleCursorInfo(consoleHandle, &cursorInfo);  // apply the changes
}

int mainMenu(int& selected) {
    int choice = 0;
    hideCursor();             // hides the cursor while redrawing
    setCursorPosition(0, 0); // redraws the console screen (Windows)
    cout << "Choose between designed classifiers:\n" << endl;

    cout << (selected == 0 ? ">" : " ") << "    NN Classifier" << endl;
    cout << (selected == 1 ? ">" : " ") << "    KNN Classifier" << endl;
    cout << (selected == 2 ? ">" : " ") << "    Another Classifier" << endl;

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

        if (selected == 0) {              // here is the implementation of the menu choice
            cout << "Implent things here                            " << endl;
            return 1;                   // return if the user selects NN
        }

        if (selected == 1) {
            KNNClassifer notAvailable;
        }

        if (selected == 2) {
            AnotherClassifer notAvailableAgain;
        }
    }

    // else if (ch == 27) {  // escape key here if we ever need to go back
        // return -1;       // return a special value to indicate "back"
    // }

    return 0;
}

/*The application should give an option for the user to enter sample data (x,y,z) and the output is the orientation of the phone.

  Also, the application should give an option for the user to enter a data file name (e.g., unknownData.txt). 
  In this case, the output of your application is another file named (e.g., result.txt) which includes your data and the corresponding phone orientation. 
  The file format of the result has to be as shown in the following figure:
*/