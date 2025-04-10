#pragma once
#include <iostream>
#include <string>

// TODO: Make this an overall abstract classifier 
using namespace std;

class Classifier {
public:
	virtual void performClassification_SampleData(double x, double y, double z) = 0;

	virtual int performClassification_File(string testingfile, string trainingfile, double* trn, double* tst) = 0;
};