#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector> 

class Position {
public:
	double difference(double i);

	double calculateDistance(double* trn, double* tst); // calculate between given point and another point

	void orientation(int xEntered, int yEntered, int zEntered, double x, double y, double z);
};