#pragma once
#include "KNN_Classifier.h"
#include "Another_Classifier.h"
#include <iostream>
#include <fstream>
#include <conio.h>    // _getch()
#include <windows.h> // hide cursors 

#define MENU_ITEMS		3

void hideCursor();

int mainMenu(int& selected);
