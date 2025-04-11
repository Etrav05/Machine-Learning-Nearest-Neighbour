#pragma once
#include "ReadWriteFile.h"
#include "Classifier.h"
#include "Position.h"

using namespace std;

class NNClassifer : protected Classifier { // TODO: Make this class only training and classifying (make this one protected)
public:
	void training(vector<vector<double>>& data);

	vector<double> performClassification(vector<double>& testPoint, vector<vector<double>>& trainingGroup);
};
