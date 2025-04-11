#pragma once
#include "DataPersistance.h"
#include "Linked_List.h"
#include "Position.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class ReadWriteFile : public DataPersistance {
public:

	vector<double> getParsedData(string& line); // parse each line from file

	vector<vector<double>> createCoordinateGroups(string& filename); // create a vector which contatains the coordinates + label as individual groupings

	bool saveResultsToFile(PLINENODE head);

};