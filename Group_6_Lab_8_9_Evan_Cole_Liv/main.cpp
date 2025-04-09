#include "menu.h"
#include "Model.h"

// Group 6: Evan, Cole, Liv

// TODO: Include more explicit error handling with specific error class
// 

// BUGS:
//

int main() {
	Menu m;
	int selected = 0; // initialize variable(s)
	int choice = 0;

	// == testing ==
	// double trn[4] = { 0 };
	// double tst[4] = { 0 };

	// DataPoint point;                                                     // used to verify Learning phase and inference phases (passed * 2)
	// point.accessFileNN("testingData.txt", "trainingData.txt", trn, tst);


	while (choice != 1) { // display the main menu until the user selects ths first option (NN Classifier)
		choice = m.mainMenu(selected);
	}

	cout << "\n\n\n\n~=~ End of program ~=~" << endl; // just a little message
	return 0;
}

