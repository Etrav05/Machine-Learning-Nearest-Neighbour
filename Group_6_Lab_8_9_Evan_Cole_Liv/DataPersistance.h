#pragma once
#include <iostream>
#include "Linked_List.h"

using namespace std;

class DataPersistance {
public:

	virtual void getParsedData(string values, double* xyzlabel) = 0;

	virtual bool saveResultsToFile(PLINENODE head) = 0;
};