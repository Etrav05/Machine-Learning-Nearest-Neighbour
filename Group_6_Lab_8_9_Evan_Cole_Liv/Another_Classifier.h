#pragma once
#include "Classifier.h"

/// @file Another_Classifier.h
/// 
/// @brief Header file defining the Another Classifier interface
/// 
/// Defines the behaviours of Another Classifier

using namespace std;

class AnotherClassifer : protected Classifier {
public:

	/// @brief Function specific to Another Classifier to show it is not implemented
 	/// 
	/// This function shows the users this classifier is not implemenetd before they can go further into its menu
	void notImplemented();

	/// @brief Function to store parsed training data to the objects trainingData member 
	/// 
	/// This function currently only prints "== Another Classifier is not implemented yet =="
	void training(vector<vector<double>>& data);

	/// @brief Function to perform lable classification based on a passed point and against parsed training data in the trainingData member
	/// 
	/// This function currently only prints "== Another Classifier is not implemented yet =="
	vector<double> performClassification(vector<double>& testPoint);
};