#include "NN_Classifier.h"
#include "Exception_SampleInput.h"
#include "ReadWriteFile.h"
#include "menu.h"

/*
-z = face up
 z = face down
-y = portrait
 y = portrait upside down
-x = landscape left
 x = landscape right
*/

void NNClassifer::sampleDataOrientation(double x, double y, double z) {
    Menu m;
    Position p;
    m.setCursorPosition(0, 9);
    
    double a = p.difference(x);
    double b = p.difference(y);
    double c = p.difference(z);
    double temp;

    temp = a; // find least difference
    if (b < temp) temp = b;
    if (c < temp) temp = c;

    cout << "Orientation: ";

    if (temp == a) { cout << (x < 0 ? "Landscape left" : "Landscape right") << endl; } // given the lowest difference, check if the inital value (x, y, z) was + or -, print orientation based on this
    if (temp == b) { cout << (y < 0 ? "Portrait" : "Portrait upside down") << endl; }
    if (temp == c) { cout << (z < 0 ? "Face up" : "Face down") << endl; }
}

int NNClassifer::sampleData(int& selected, double& x, double& y, double& z, int& xEntered, int& yEntered, int& zEntered) { // output will be orientation 
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
            p.orientation(xEntered, yEntered, zEntered, x, y, z);
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
            p.orientation(xEntered, yEntered, zEntered, x, y, z);
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
            p.orientation(xEntered, yEntered, zEntered, x, y, z);
            break;
        }
    }

    else if (ch == 27) {
        return 1;
    }

    return 0;
}

int NNClassifer::performClassification(string testingfile, string trainingfile, double* trn, double* tst) {
    ifstream finTst;		   // in read mode (specific to this file)
    finTst.open(testingfile); // open file	
    PLINENODE head = NULL;   // create the head of the linked list
    ReadWriteFile rwf;

    if (!finTst.is_open()) { // make sure the file was opened
        cout << "Could not find testing file" << endl;
        Sleep(2000);       // give the user some time to read the error message
        system("cls");
        return 1;
    }

    Position p;
    string tstline;
    int i = 0;

    while (getline(finTst, tstline)) {
        rwf.getParsedData(tstline, tst); // get the data of the ith line line { x, y, z, label }
        double min = 420;           // used to find the minimum (set to a high number so every value will initally be smaller)
        vector<double> result(5);  // vector group (typed double) to hold result values

        ifstream finTrn;        // this is why we made a specific fin the file, so we can open out training file concurently
        finTrn.open(trainingfile);
        if (!finTrn.is_open()) {  // make sure the file was opened again
            cout << "Could not find training file" << endl;
            Sleep(2000);        // give the user some time to read the error message
            system("cls");
            return 1;
        }

        string trnline;
        while (getline(finTrn, trnline)) {
            rwf.getParsedData(trnline, trn); // get the data of each line from the training file { x, y, z, label }

            double distance = p.calculateDistance(trn, tst); // calculate the distance from the given line data to our initial test line data
            if (distance < min) {      // keep track of the shortest distance
                min = distance;

                result[0] = tst[0];  // if we have a new shortest distance, save the test features and the training label to a vector group (to compare labels) 
                result[1] = tst[1];
                result[2] = tst[2];
                result[3] = trn[3];
                result[4] = tst[3]; // TODO: if tst 3 exists (so with the training and test files) then take it, else dont
            }
        }
        finTrn.close(); // close the training file

        cout << "Calculating line " << setw(3) << i + 1 << ": ( "  // this block is just to make it so the prints will all be aligned (improves readability up to the hundreds)
            << fixed << setprecision(5)                           // set the number of decimal places we will print to
            << setw(8) << result[0] << ", "                      // setw(x) sets the width that result[0] will print within, and since result[0] was set to a max precision of 5, it will never outgrow this space
            << setw(8) << result[1] << ", "
            << setw(8) << result[2] << " )    "
            << "Predicted Label: " << (int)result[3] << "\n";

        LINE line = createLine(result[0], result[1], result[2], result[3]); // save these results to a linked list node
        addNode(&head, line);                                              // add the node to the linked list

        i++; // increment to the next line of the test file
    }
    if (rwf.saveResultsToFile(head)) { // save these results to a file, if this passes then print a message
        cout << "=====+===== =======+===== =====+======+=====+===== =====+======= =====+=====" << endl;
        cout << "=====+===== This information has been save to file (results.txt) =====+=====" << endl;
        cout << "=====+===== =======+===== =====+======+=====+===== =====+======= =====+=====" << endl;
    }

    finTst.close();
    return 0;
}