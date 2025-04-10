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

	void getParsedData(string values, double* xyzlabel);

	bool saveResultsToFile(PLINENODE head);

};