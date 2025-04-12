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

/// @brief Class for NNClassifier functions 
/// 
/// Defines the behaviours of NNClassifier functions 
/// @author Evan, Cole, Liv
/// @data 12/04/2025
class NNClassifier : protected Classifier {
public:

	/// @brief Function to store parsed training data to the objects trainingData member 
	/// 
	/// This function set this objects traingingData to be equal to the passed vector group
	/// 
	/// @param This function accepts the pasred grouping of training data
	void training(vector<vector<double>>& data);

	/// @brief Function to perform lable classification based on a passed point and against parsed training data in the trainingData member
	/// 
	/// This function creates a result vector group which contatins the test points coordinates and the nearest training data coordinate's label (Neareast Neighbour) 
	/// 
	/// @param This function accepts a testing point
	/// @return Returns the classification as a vector group
	vector<double> performClassification(vector<double>& testPoint);
};
