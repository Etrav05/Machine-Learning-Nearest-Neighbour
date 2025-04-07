#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector> 
#include <iomanip>

using namespace std;

class UnknownLabel {
	double* features; // (x, y, z)

public:

	UnknownLabel();

	void accessFileNN_UnknownLabel(string testingfile, string trainingfile, double* trn, double* tst); // access file and specifically parse data

};

void getParsedDataFromUnknown(string values, double* xyzlabel);

