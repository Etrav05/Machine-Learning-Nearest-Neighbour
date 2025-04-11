#include "menu.h"

// Group 6: Evan, Cole, Liv

int main() {
	Menu m;
	int selected = 0; // initialize variable(s)
	int choice = 0;

	while (choice != 1) { // display the main menu until the user selects ths first option (NN Classifier)
		choice = m.mainMenu(selected);
	}

	cout << "\n\n\n\n~=~ End of program ~=~" << endl; // just a little message
	return 0;
}

