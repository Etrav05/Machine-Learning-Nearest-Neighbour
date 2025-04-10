#pragma once
#include <iostream>
#include <string>

// TODO: Make this an overall abstract classifier 
using namespace std;

class Classifier {
public:

	virtual int performClassification(string testingfile, string trainingfile, double* trn, double* tst) = 0;
};