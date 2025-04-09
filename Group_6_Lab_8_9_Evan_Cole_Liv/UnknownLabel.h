#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector> 
#include <iomanip>
#include <conio.h>
#include <windows.h> 
#include "Training.h"

using namespace std;

class UnknownLabel : public DataPoint {
public:

	UnknownLabel();

	int accessFileNN_UnknownLabel(string testingfile, string trainingfile, double* trn, double* tst); // access file and specifically parse data

};

void getParsedDataFromUnknown(string values, double* xyzlabel);

