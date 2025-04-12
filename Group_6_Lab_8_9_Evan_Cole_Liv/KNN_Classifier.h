#pragma once
#include "Classifier.h"

/// @file KNN_Classifier.h
/// 
/// @brief Header file defining the KNNClassifier interface
/// 
/// Defines the behaviours of KNNClassifier

using namespace std;

/// @brief Class for KNNClassifier functions
/// 
/// Defines the behaviours of KNNClassifier functions
/// @author Evan, Cole, Liv
/// @data 12/04/2025
class KNNClassifier : protected Classifier {
public:
	/// @brief Function specific to KNNClassifier to show it is not implemented
	/// 
	/// This function shows the users this classifier is not implemenetd before they can go further into its menu
	void notImplemented();

	/// @brief Function to store parsed training data to the objects trainingData member 
	/// 
	/// This function currently only prints "== KNNClassifier is not implemented yet =="
	/// 
	/// @param This function accepts the pasred grouping of training data
	void training(vector<vector<double>>& data);

	/// @brief Function to perform lable classification based on a passed point and against parsed training data in the trainingData member
	/// 
	/// This function currently only prints "== KNNClassifier is not implemented yet =="
	/// 
	/// @param This function accepts a testing point
	/// @return Returns nothing currently
	vector<double> performClassification(vector<double>& testPoint);
};