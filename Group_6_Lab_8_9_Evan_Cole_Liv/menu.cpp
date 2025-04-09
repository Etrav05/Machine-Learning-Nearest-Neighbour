#include "menu.h"
#include "Model.h"
#include "KNN_Classifier.h"
#include "NN_Classifier.h"
#include "Another_Classifier.h"


using namespace std;

void Menu::setCursorPosition(int x, int y) {      // this is a function made by windows to set a position to redraw an output from
    COORD coord = { (SHORT)x, (SHORT)y };  // rather than completly clear and redraw it (fixes the flickering issue)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Menu::hideCursor(int state) {                                          // another windows made function to hide the cursor while redrawing the terminal
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // get the handle to the standard output (console)

    CONSOLE_CURSOR_INFO cursorInfo;                       // define the cursor info structure
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    cursorInfo.bVisible = state;                             // set the cursor visibility to false (hide the cursor) --> 0 = false, 1 = true

    SetConsoleCursorInfo(consoleHandle, &cursorInfo);  // apply the changes
}

int Menu::mainMenu(int& selected) {
    int choice = 0;
    int back = 0;
    hideCursor(0);             // hides the cursor while redrawing
    setCursorPosition(0, 0);  // redraws the console screen (Windows)
    cout << "Choose between designed classifiers:\n" << endl;

    cout << (selected == 0 ? " >" : " ") << "    NN Classifier " << endl;
    cout << (selected == 1 ? " >" : " ") << "    KNN Classifier " << endl;
    cout << (selected == 2 ? " >" : " ") << "    Another Classifier " << endl;

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
                while (!back) {
                    back = NNMenu(selected);
                }
                system("cls");
                break;
            case 1:
                { KNNClassifier notAvailable; 
                  notAvailable.notImplemented();
                } 
                break;
            case 2:
                { AnotherClassifer notAvailableAgain; 
                  notAvailableAgain.notImplemented();
                }
                break;
        }
    }

    else if (ch == 27) {  // escape key here if we ever need to go back
        return 1;       // return a special value to indicate "back"
    }

    return 0;
}

int Menu::NNMenu(int& selected) {
    hideCursor(0);             // hides the cursor while redrawing
    setCursorPosition(0, 0);  // redraws the console screen (Windows)
    int back = 0;

    cout << "[NN Classifier selected]" << endl;
    cout << "Choose option: \n" << endl;

    cout << (selected == 0 ? " >" : " ") << "    Enter sample data " << endl;
    cout << (selected == 1 ? " >" : " ") << "    Enter a data file " << endl;
    
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

            while (!back) {
                back = sampleDataOption.sampleData(selected, x, y, z, xEntered, yEntered, zEntered);
            }
            system("cls");
        }
            break;
        case 1: // enter a data file option
            double trn[4] = { 0 };
            double tst[4] = { 0 };
            string textFile;
            hideCursor(1); 

            while (!back) {
                cout << "\nEnter txt file name here (Include .txt): ";
                cin >> textFile;

                DataPoint data;
                back = data.accessFileNN(textFile, "trainingData.txt", trn, tst);
            }
            break;
        }
    }

    else if (ch == 27) {     // escape key here if we ever need to go back
           return 1;       // return a special value to indicate "back"
    }

    return 0;
}
