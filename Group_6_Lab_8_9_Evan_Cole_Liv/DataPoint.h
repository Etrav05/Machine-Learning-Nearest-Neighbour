#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

class DataPoint {
	double* features; // (x, y, z)
	int label;       // 1 -> 6

public:

	DataPoint();

	void accessDataPoint(string testingfile, string trainingfile, double* trn, double* tst); // access file and specifically parse data

	double calculateDistance(double* trn, double* tst); // claculate between given point and another point

};

void getParsedData(string values, double* xyzlabel);
