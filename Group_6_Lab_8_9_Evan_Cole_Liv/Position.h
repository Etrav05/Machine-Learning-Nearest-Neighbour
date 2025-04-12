#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector> 

/// @file Position.h
/// 
/// @brief Header file defining the Position interface
/// 
/// Defines the behaviours of Position

class Position {
public:

	/// @brief Function to calculate the distance between a test and training point
	/// 
	/// This function accepts a test point and a training point then calculates the distance between them with a Euclidean distance formula
	double calculateDistance(vector<double>& trn, vector<double>& tst);
};