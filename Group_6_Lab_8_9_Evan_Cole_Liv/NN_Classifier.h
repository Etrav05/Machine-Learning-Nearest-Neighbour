#pragma once
#include "ReadWriteFile.h"
#include "Classifier.h"
#include "Position.h"

/// @file NN_Classifier.h
/// 
/// @brief Header file defining the NNClassifier interface
/// 
/// Defines the behaviours of NNClassifier

using namespace std;

class NNClassifer : protected Classifier {
public:

	/// @brief Function to store parsed training data to the objects trainingData member 
	/// 
	/// This function set this objects traingingData to be equal to the passed vector group
	void training(vector<vector<double>>& data);

	/// @brief Function to perform lable classification based on a passed point and against parsed training data in the trainingData member
	/// 
	/// This function creates a result vector group which contatins the test points coordinates and the nearest training data coordinate's label (Neareast Neighbour) 
	vector<double> performClassification(vector<double>& testPoint);
};
