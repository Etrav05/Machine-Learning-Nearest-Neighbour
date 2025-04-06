#include "menu.h"

// Group 6: Evan, Cole, Liv

// TODO:
// - Make menus go back
// - Add functionality to the sample data (x,y,z) option
// - Add functionality to the enter a data file option
//
//

// BUGS:
// - During the sample data (x,y,z) option, if you enter a string it stops showing input/output 
// - Expection case to fix the above doesnt work
//

int main() {
	int selected = 0; // initialize variable(s)
	int choice = 0;

	while (choice != 1) { // display the main menu until the user selects ths first option (NN Classifier)
		choice = mainMenu(selected);
	}

	cout << "Chunky" << endl;

	return 0;
}

