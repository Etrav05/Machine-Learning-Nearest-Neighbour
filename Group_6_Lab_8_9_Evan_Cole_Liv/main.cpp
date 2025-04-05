#include "menu.h"

// Group 6: Evan, Cole, Liv

int main() {
	int selected = 0; // initialize variable(s)
	int choice = 0;

	while (choice != 1) { // display the main menu until the user selects ths first option (NN Classifier)
		choice = mainMenu(selected);
	}

	cout << "Chunky" << endl;

	return 0;
}

