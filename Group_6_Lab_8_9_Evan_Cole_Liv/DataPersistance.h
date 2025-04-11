#pragma once
#include <iostream>
#include <vector>

using namespace std;

class DataPersistance {
public:

	virtual vector<double> getParsedData(string& line) = 0; // parse each line from file

	virtual vector<vector<double>> createCoordinateGroups(string& filename) = 0; // create a vector which contatains the coordinates + label as individual groupings

	virtual bool saveResultsToFile(vector<vector<double>>& results) = 0;
};