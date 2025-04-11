#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "NN_Classifier.h"
#include "menu.h"

using namespace std;

class Character_Detected : public exception {
public:
	const char* what() const {
		return "== Characters are not accepted ==";
	}

};

class Greater_Or_Less_Than_Range : public exception {
public:
	const char* what() const {
		return "== Input can only be between -1 & 1 ==";
	}

};

void acceptSampleData(double& i);

void handleInput(double& xyz, int& xyzEntered, double& x, double& y, double& z, int xEntered, int yEntered, int zEntered, NNClassifer& data, vector<vector<double>>& trainingData, Menu& m);