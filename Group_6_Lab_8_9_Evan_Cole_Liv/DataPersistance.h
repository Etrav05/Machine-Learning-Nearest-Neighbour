#pragma once
#include <iostream>
#include <vector>

/// @file DataPersistance.h
/// 
/// @brief Header file defining the interface of the abstract class DataPersistance
/// 
/// Defines the pure virtual functions of DataPersistance

using namespace std;

/// @brief Base class for file stream functions
/// 
/// Defines the base behaviours of file stream functions
/// @author Evan, Cole, Liv
/// @data 12/04/2025
class DataPersistence {
public:

	/// @brief Pure virtual function to get parsed training data from a line in a file
	/// 
	/// This function is purely virtual and is to be defined by derived classes
	/// 
	/// @param accepts a line from a file
	/// @return Returns nothing as it is an virtual function
	virtual vector<double> getParsedData(string& line) = 0;

	/// @brief Pure virtual function to get store each parsed training data line vector group to a larger vector group of vector groups
	/// 
	/// This function is purely virtual and is to be defined by derived classes
	/// 
	/// @param accepts a file name string
	/// @return Returns nothing as it is an virtual function
	virtual vector<vector<double>> createCoordinateGroups(string& filename) = 0;

	/// @brief Pure virtual function to get store the vector group of vectors created by the "createCoordinateGroups" function to a file named "results.txt"
	/// 
	/// This function is purely virtual and is to be defined by derived classes
	/// 
	/// @param accepts the created vector group of cooridinates which have been classified
	/// @return Returns nothing as it is an virtual function
	virtual bool saveResultsToFile(vector<vector<double>>& results) = 0;
};