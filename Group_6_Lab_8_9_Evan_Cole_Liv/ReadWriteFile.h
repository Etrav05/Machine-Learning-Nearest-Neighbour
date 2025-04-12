#pragma once
#include "DataPersistance.h"
#include "Position.h"
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <iomanip>

/// @file ReadWriteFile.h
/// 
/// @brief Header file defining the ReadWriteFile interface
/// 
/// Defines the behaviours of ReadWriteFile

using namespace std;

class ReadWriteFile : public DataPersistance {
public:

	/// @brief Function to get parsed training data from a line in a file
	/// 
	/// This function is used to parse each data point of a file line, pushing the value which is before/after commas to a vector group
	vector<double> getParsedData(string& line);

	/// @brief Function to get store each parsed training data line vector group to a larger vector group of vector groups
	/// 
	/// This function is opens a file and calls the "getParsedData" function on each of its lines, saving the "getParsedData" vector groups to a larger vector group made of vector groups
	vector<vector<double>> createCoordinateGroups(string& filename);

	/// @brief Function to get store the vector group of vectors created by the "createCoordinateGroups" function to a file named "results.txt"
	/// 
	/// This function creates a results file and reads through a vector grouping created by the "createCoordinateGroups" function, while reading, it saves the testing cooridinates to file, 
	/// then the training label, and lastly, based on this training label, a specific label name. This repeats for each grouping in the passed vector group
	bool saveResultsToFile(vector<vector<double>>& results);
};