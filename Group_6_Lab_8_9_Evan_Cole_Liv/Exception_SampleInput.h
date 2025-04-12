#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "NN_Classifier.h"
#include "menu.h"

/// @file Exception_SampleInput.h
/// 
/// @brief Header file defining the exceptions interface
/// 
/// Defines the behaviours of each exeption

using namespace std;

/// @brief Class to define the exception of Character detection
/// 
/// This class creates execeptions to be thrown when this specific error is detetcted
class Character_Detected : public exception {
public:

	/// @brief This function prints an error message when it is called
	/// 
	/// This error message is specific to characters not being accepted
	const char* what() const {
		return "== Characters are not accepted ==";
	}

};

/// @brief Class to define the exception of Greater or less than range
/// 
/// This class creates execeptions to be thrown when this specific error is detetcted
class Greater_Or_Less_Than_Range : public exception {
public:

	/// @brief This function prints an error message when it is called
	/// 
	/// This error message is specific to an input being greater or less than accepted range
	const char* what() const {
		return "== Input can only be between -1 & 1 ==";
	}

};
