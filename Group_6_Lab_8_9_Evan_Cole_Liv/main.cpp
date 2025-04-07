#include "menu.h"
#include "Training.h"
#include "UnknownLabel.h"

// Group 6: Evan, Cole, Liv

// TODO:
//

// BUGS:
//

int main() {
	int selected = 0; // initialize variable(s)
	int choice = 0;

	/* == testing ==
	// double trn[4] = { 0 };
	// double tst[4] = { 0 };

	// DataPoint point;                                                     // used to verify Learning phase (passed)
	// point.accessFileNN("testingData.txt", "trainingData.txt", trn, tst);

	// UnknownLabel unknown;                                                // used to verify Inference phase (passed)
	// unknown.accessFileNN_UnknownLabel("unknownData.txt", "trainingData.txt", trn, tst);
	*/

	while (choice != 1) { // display the main menu until the user selects ths first option (NN Classifier)
		choice = mainMenu(selected);
	}

	cout << "\n\n\n\n~=~ End of program ~=~" << endl; // just a little message
	return 0;
}

