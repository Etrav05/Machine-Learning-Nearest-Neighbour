#pragma once
#include <iostream>

using namespace std;

class User_Input_Contains_Character : exception {

public: 
	const char* what() const {
		return "Cannot enter characters";
	}
};