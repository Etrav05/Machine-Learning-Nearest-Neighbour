#pragma once
#include "Classifier.h"

using namespace std;

class AnotherClassifer : public Classifier {
public:
	void notImplemented();

	void performClassification_SampleData(double x, double y, double z);

	int performClassification_File(string testingfile, string trainingfile, double* trn, double* tst);
};