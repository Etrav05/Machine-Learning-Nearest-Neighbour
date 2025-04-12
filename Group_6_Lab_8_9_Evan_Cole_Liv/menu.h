#pragma once
#include "Classifier.h"
#include <iostream>
#include <fstream>
#include <conio.h>    // _getch()
#include <windows.h> // hide cursors

#define MENU_ITEMS		3

/// @file menu.h
/// 
/// @brief Header file defining the menu class interface
/// 
/// Defines the functions used in menu operations


/// @brief Class for menu functions
/// 
/// Defines the behaviours of menu functions
/// @author Evan, Cole, Liv
/// @data 12/04/2025
class Menu {
public:

	/// @brief Windows API function to set a cursor position for printing
	/// 
	/// This function sets the cursors position to a specified location and redraws the scene from that location which prevents the terminal from flickering
	/// 
	/// @param Accepts coordinates on a 2D plane
	void setCursorPosition(int x, int y);

	/// @brief Windows API function to hide the cursor
	/// 
	/// This function sets the cursors visiblity to true or false which prevents the cursor from visibly moving around the screen while redrawing
	/// 
	/// @param Accepts state, 1 = visible, 0 = hidden
	void hideCursor(int state);

	/// @brief Function to display and allow operation of a main menu
	/// 
	/// This function provides the user with the options of classifiers and allows then to select which they wish perform, if an option is selected, it will run that function
	/// 
	/// @param Accepts the value of selected when the user presses enter on a menu option
	/// @return Returns 1 if the user presses escape
	int mainMenu(int& selected);

	/// @brief Function to display and allow operation of a NNClassifier menu
	/// 
	/// This function provides the user with the options of how they wish to use the NNclassifiers and it allows then to select which they want to perform, if an option is selected, it will run that function
	/// 
	/// @param Accepts the value of selected when the user presses enter on a NNmenu option
	/// @return Returns 1 if the user presses escape
	int NNMenu(int& selected);
};