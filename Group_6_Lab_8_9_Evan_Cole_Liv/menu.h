#pragma once
#include "NN_Classifier.h"
#include "KNN_Classifier.h"
#include "Another_Classifier.h"
#include <iostream>
#include <fstream>
#include <conio.h>    // _getch()
#include <windows.h> // hide cursors 

#define MENU_ITEMS		3

void setCursorPosition(int x, int y);

void hideCursor(int state);

int mainMenu(int& selected);

int NNMenu(int& selected);
