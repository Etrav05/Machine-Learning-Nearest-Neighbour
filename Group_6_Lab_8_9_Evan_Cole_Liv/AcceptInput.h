#pragma once
#include "NN_Classifier.h"
#include "Exception_SampleInput.h"
#include "menu.h"

/// @file AcceptInput.h
/// 
/// @brief Header file defining AcceptInput interface
/// 
/// Defines the behaviours of AcceptInput

class AcceptInput {
public:

	/// @brief Function to accept the users input
	/// 
	/// This function accepts users inputs and converts them to string to check for invalid entries, those execptions being most characters or outside the range of coordinate entries (-1 >= 1)
	void acceptSampleData(double& i);

	/// @brief Function to handle the users 3 coordinate entries and produce a classification
	/// 
	/// This function constantly handles the 3 coordinates the user can input and produces a classification as well as message which states the phones orientation
	void handleInput(double& xyz, int& xyzEntered, double& x, double& y, double& z, int xEntered, int yEntered, int zEntered, NNClassifer& data, vector<vector<double>>& trainingData, Menu& m);

	/// @brief Function to display and allow selection of the 3 cooridinate entries
	/// 
	/// This function provides the user with the options of the 3 coordinates and allows constant entry of their values
	int sampleData(int& selected, double& x, double& y, double& z, int& xEntered, int& yEntered, int& zEntered);
};

