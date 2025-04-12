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

/// @brief Base class for Classifier functions
/// 
/// Defines the base behaviours of Classifier functions
/// @author Evan, Cole, Liv
/// @data 12/04/2025
class Classifier {
protected:
    vector<vector<double>> trainingData;

public:

    /// @brief Pure virtual function to store parsed training data to the objects trainingData member 
    /// 
    /// This function is purely virtual and is to be defined by derived classes
    /// 
    /// @param This function accepts the pasred grouping of training data
    virtual void training(vector<vector<double>>& data) = 0;

    /// @brief Pure virtual function to perform label classification based on a passed point and against parsed training data in the trainingData member
    /// 
    /// This function is purely virtual and is to be defined by derived classes
    /// 
    /// @param This function accepts a testing point
    /// @return Returns nothing as it is an virtual function
    virtual vector<double> performClassification(vector<double>& testPoint) = 0;
};