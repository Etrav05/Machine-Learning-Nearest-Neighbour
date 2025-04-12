#pragma once
#include <iostream>
#include <vector>

/// @file DataPersistance.h
/// 
/// @brief Header file defining the interface of the abstract class DataPersistance
/// 
/// Defines the pure virtual functions of DataPersistance

using namespace std;

class DataPersistance {
public:

	/// @brief Pure virtual function to get parsed training data from a line in a file
	/// 
	/// This function is purely virtual and is to be defined by derived classes
	virtual vector<double> getParsedData(string& line) = 0;

	/// @brief Pure virtual function to get store each parsed training data line vector group to a larger vector group of vector groups
	/// 
	/// This function is purely virtual and is to be defined by derived classes
	virtual vector<vector<double>> createCoordinateGroups(string& filename) = 0;
};