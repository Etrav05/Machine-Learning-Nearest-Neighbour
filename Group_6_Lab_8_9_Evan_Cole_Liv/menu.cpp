#include "menu.h"
#include "AcceptInput.h"
#include "KNN_Classifier.h"
#include "NN_Classifier.h"
#include "Another_Classifier.h"
#include "Exception_SampleInput.h"
#include "AcceptInput.h"
#include <cctype>

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
                  notAvailable.notImplemented(); // show that these classifiers are not implemented
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

    vector<vector<double>> results; // to be saved to file

    cout << "[NN Classifier selected]" << endl;
    cout << "Choose option: \n" << endl;

    cout << (selected == 0 ? " >" : " ") << "    Enter sample data " << endl; // allow the user to select what function they wish to do
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
            AcceptInput sampleDataOption;    // initialize all variables which must go into the sampleData function
            int selected = 0;
            double x = 0, y = 0, z = 0;
            int xEntered = 0, yEntered = 0, zEntered = 0;

            while (!back) {
                back = sampleDataOption.sampleData(selected, x, y, z, xEntered, yEntered, zEntered); // while the user still wants to input, repeat the function
            }
            system("cls");
        }
        break;
        case 1: // enter a data file option
            NNClassifer data;
            ReadWriteFile rwf;

            string testFile;
            string trainingFile = "trainingData.txt";
            hideCursor(1);

            while (1) { //TODO: make a new back function
                cout << "\nEnter file name here (or enter 'back' to select again): "; // accept anny file
                cin >> testFile;

                if (testFile == "back") { // allow the user to go back in menus by typing back
                    system("cls");
                    break;
                }

                vector<vector<double>> trainingData = rwf.createCoordinateGroups(trainingFile);
                data.training(trainingData); // save this training data to the class attribute

                vector<vector<double>> testData = rwf.createCoordinateGroups(testFile); // create vector group of the testing data from the users inputted file

                for (int i = 0; i < testData.size(); i++) {
                    vector<double> testPoint = testData[i];
                    vector<double> result = data.performClassification(testPoint);
                    results.push_back(result); // push each result to the "results" vector group

                    cout << "Calculating line " << setw(3) << i + 1 << ": ( "  // this block is just to make it so the prints will all be aligned (improves readability up to the hundreds)
                        << fixed << setprecision(5)                           // set the number of decimal places we will print to
                        << setw(8) << result[0] << ", "                      // setw(x) sets the width that result[0] will print within, and since result[0] was set to a max precision of 5, it will never outgrow this space
                        << setw(8) << result[1] << ", "
                        << setw(8) << result[2] << " )    "
                        << "Predicted Label: " << (int)result[3] << "\n";
                }

                if (rwf.saveResultsToFile(results)) { // save these results to a file, if this passes then print a message
                    cout << "=====+===== =======+===== =====+======+=====+===== =====+======= =====+=====" << endl;
                    cout << "=====+===== This information has been save to file (results.txt) =====+=====" << endl;
                    cout << "=====+===== =======+===== =====+======+=====+===== =====+======= =====+=====" << endl;
                }
            }

            break;
        }
    }

    else if (ch == 27) { // escape key here if we ever need to go back
           return 1;    // return a special value to indicate "back"
    }

    return 0;
}
