#include "NN_Classifier.h"
#include "ReadWriteFile.h"
#include "menu.h"

/*
-z = face up
 z = face down
-y = portrait
 y = portrait upside down
-x = landscape left
 x = landscape right
*/

void NNClassifier::training(vector<vector<double>>& data) { // assign the vector parameter to the attribute
    this->trainingData = data; 
}

vector<double> NNClassifier::performClassification(vector<double>& testPoint) {
    vector<double> result(4); // result vector
    Position p;

    double min = 420;


    for (vector<double>& trainingPoint : trainingData) { // for each training point in our traing group
        double distance = p.calculateDistance(testPoint, trainingPoint);

        if (distance < min) {          // keep track of the shortest distance
            min = distance;

            int i = trainingPoint[3];

            result[0] = testPoint[0];     // if we have a new shortest distance, save the test features and the training label to a vector group (to compare labels) 
            result[1] = testPoint[1];
            result[2] = testPoint[2];
            result[3] = trainingPoint[3]; // label will be the closest training point to the testing point
        }
    }

    return result; // return this created vector
}
