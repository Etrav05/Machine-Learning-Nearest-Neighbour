#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector> 

using namespace std;

class DataPoint {
public:

	DataPoint();

	int accessFileNN(string testingfile, string trainingfile, double* trn, double* tst); // access file and specifically parse data

	double calculateDistance(double* trn, double* tst); // calculate between given point and another point

};

void getParsedData(string values, double* xyzlabel);
