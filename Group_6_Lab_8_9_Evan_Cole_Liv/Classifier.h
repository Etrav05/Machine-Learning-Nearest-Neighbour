#pragma once
#include <iostream>
#include <string>
#include <vector>

/// @file Classifier.h
/// 
/// @brief Header file defining the interface of the abstract class Classifier
/// 
/// Defines the pure virtual functions of Classifier

using namespace std;

class Classifier {
protected:
    vector<vector<double>> trainingData;

public:

    /// @brief Pure virtual function to store parsed training data to the objects trainingData member 
    /// 
    /// This function is purely virtual and is to be defined by derived classes
    virtual void training(vector<vector<double>>& data) = 0;

    /// @brief Pure virtual function to perform label classification based on a passed point and against parsed training data in the trainingData member
    /// 
    /// This function is purely virtual and is to be defined by derived classes
    virtual vector<double> performClassification(vector<double>& testPoint) = 0;
};