#pragma once
#include "Classifier.h"

using namespace std;

class KNNClassifier : protected Classifier {
public:
	void notImplemented();

	void training(vector<vector<double>>& data);

	vector<double> performClassification(vector<double>& testPoint, vector<vector<double>>& trainingGroup);
};