#pragma once
#include "Classifier.h"

using namespace std;

class KNNClassifier : public Classifier {
public:
	void notImplemented();

	int performClassification(string testingfile, string trainingfile, double* trn, double* tst);
};