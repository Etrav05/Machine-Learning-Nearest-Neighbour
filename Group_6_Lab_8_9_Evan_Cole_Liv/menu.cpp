#include "menu.h"

using namespace std;

void setCursorPosition(int x, int y) {      // this is a function made by windows to set a position to redraw an output from
    COORD coord = { (SHORT)x, (SHORT)y };  // rather than completly clear and redraw it (fixes the flickering issue)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor(int state) {                                          // another windows made function to hide the cursor while redrawing the terminal
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // get the handle to the standard output (console)

    CONSOLE_CURSOR_INFO cursorInfo;                       // define the cursor info structure
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    cursorInfo.bVisible = state;                             // set the cursor visibility to false (hide the cursor) --> 0 = false, 1 = true

    SetConsoleCursorInfo(consoleHandle, &cursorInfo);  // apply the changes
}

int mainMenu(int& selected) {
    int choice = 0;
    hideCursor(0);             // hides the cursor while redrawing
    setCursorPosition(0, 0);  // redraws the console screen (Windows)
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

        switch (selected) {
            case 0:                      // NN Classifier option
                selected = 0;
                system("cls");
                while (1) {
                    NNMenu(selected);
                }
                break;
            case 1:
                { KNNClassifer notAvailable; } // was getting error C2360 and the fix was to encase this initialization in { }
                break;
            case 2:
                AnotherClassifer notAvailableAgain;
                break;

        }
    }

    else if (ch == 27) {  // escape key here if we ever need to go back
           return 1;       // return a special value to indicate "back"
    }

    return 0;
}

int NNMenu(int& selected) {
    hideCursor(0);             // hides the cursor while redrawing
    setCursorPosition(0, 0);  // redraws the console screen (Windows)
    cout << "[NN Classifier selected]" << endl;
    cout << "Choose option: \n" << endl;

    cout << (selected == 0 ? ">" : " ") << "    Enter sample data" << endl;
    cout << (selected == 1 ? ">" : " ") << "    Enter a data file" << endl;
    
    int ch = _getch();

    if (ch == 224) {
        ch = _getch();

        if (ch == 72 && selected > 0) 
            selected--;

        else if (ch == 80 && selected < MENU_ITEMS - 2) 
            selected++;
    }

    else if (ch == 13) {                     
        setCursorPosition(0, 6); 

        switch (selected) {
        case 0: // enter sample data (x,y,z) option
        {
            system("cls");
            NNClassifer sampleDataOption;
            int selected = 0;
            double x = 0, y = 0, z = 0;
            int xEntered = 0, yEntered = 0, zEntered = 0;

            while (1) {
                sampleDataOption.sampleData(selected, x, y, z, xEntered, yEntered, zEntered);
            }
        }
            break;
        case 1: // enter a data file option

            break;
        }
    }

    // else if (ch == 27) {  // escape key here if we ever need to go back
           // return -1;       // return a special value to indicate "back"
    // }

    return 0;
}


/*
  Also, the application should give an option for the user to enter a data file name (e.g., unknownData.txt). 
  In this case, the output of your application is another file named (e.g., result.txt) which includes your data and the corresponding phone orientation. 
  The file format of the result has to be as shown in the following figure:
*/