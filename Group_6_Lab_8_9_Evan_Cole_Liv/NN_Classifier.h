#pragma once
#include "ReadWriteFile.h"
#include "Classifier.h"
#include "Position.h"

using namespace std;

class NNClassifer : public Classifier { // TODO: Make this class only training and classifying (make this one protected)
public:
	void performClassification_SampleData(double x, double y, double z);

	int performClassification_File(string testingfile, string trainingfile, double* trn, double* tst);
};
