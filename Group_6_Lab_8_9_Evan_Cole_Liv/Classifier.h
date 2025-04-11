#pragma once
#include <iostream>
#include <string>
#include <vector>

// TODO: Make this an overall abstract classifier 
using namespace std;

class Classifier {
protected:
    vector<vector<double>> trainingData; // this is to be populated by the training function

public:
    virtual void training(vector<vector<double>>& data) = 0;

    virtual vector<double> performClassification(vector<double>& testPoint, vector<vector<double>>& trainingGroup) = 0;
};