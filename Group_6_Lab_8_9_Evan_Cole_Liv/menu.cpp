#include "menu.h"
#include "KNN_Classifier.h"
#include "NN_Classifier.h"
#include "Another_Classifier.h"
#include "Exception_SampleInput.h"

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

    cout << "\n\n\n\n\n[Note: press ENTER on your option --- press ESC to go back]" << endl;

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
            Menu sampleDataOption;
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
            string testFile;
            string trainingFile = "trainingData.txt";
            hideCursor(1); 

            while (!back) { //TODO: make a new back function
                cout << "\nEnter txt file name here (Include .txt): ";
                cin >> testFile;

                NNClassifer data;
                ReadWriteFile rwf;

                vector<vector<double>> trainingData = rwf.createCoordinateGroups(trainingFile);
                vector<vector<double>> testData = rwf.createCoordinateGroups(testFile);
               
                for (int i = 0; i < testData.size(); i++) {
                    vector<double> testPoint = testData[i];
                    vector<double> result = data.performClassification(testPoint, trainingData);

                    cout << "Calculating line " << setw(3) << i + 1 << ": ( "  // this block is just to make it so the prints will all be aligned (improves readability up to the hundreds)
                        << fixed << setprecision(5)                           // set the number of decimal places we will print to
                        << setw(8) << result[0] << ", "                      // setw(x) sets the width that result[0] will print within, and since result[0] was set to a max precision of 5, it will never outgrow this space
                        << setw(8) << result[1] << ", "
                        << setw(8) << result[2] << " )    "
                        << "Predicted Label: " << (int)result[3] << "\n";
                }
            }
            break;
        }
    }

    else if (ch == 27) {     // escape key here if we ever need to go back
           return 1;       // return a special value to indicate "back"
    }

    return 0;
}

int Menu::sampleData(int& selected, double& x, double& y, double& z, int& xEntered, int& yEntered, int& zEntered) { // output will be orientation 
    Menu m;
    Position p;

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

        switch (selected) {
        case 0: // x          
            try {
                acceptSampleData(x);
                xEntered = 1;
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
            // p.orientation(xEntered, yEntered, zEntered, x, y, z);
            break;
        case 1: // y
            try {
                acceptSampleData(y);
                yEntered = 1;
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
            // p.orientation(xEntered, yEntered, zEntered, x, y, z);
            break;
        case 2: // z
            try {
                acceptSampleData(z);
                zEntered = 1;
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
            // p.orientation(xEntered, yEntered, zEntered, x, y, z);
            break;
        }
    }

    else if (ch == 27) {
        return 1;
    }

    return 0;
}