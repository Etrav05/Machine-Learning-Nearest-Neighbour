#pragma once
#include "Classifier.h"
#include <iostream>
#include <fstream>
#include <conio.h>    // _getch()
#include <windows.h> // hide cursors

#define MENU_ITEMS		3

class Menu {
public:
	void setCursorPosition(int x, int y);

	void hideCursor(int state);

	int mainMenu(int& selected);

	int NNMenu(int& selected);

	int sampleData(int& selected, double& x, double& y, double& z, int& xEntered, int& yEntered, int& zEntered);
};