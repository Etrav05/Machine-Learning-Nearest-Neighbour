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

void NNClassifer::training(vector<vector<double>>& data) {
    this->trainingData = data;
}

vector<double> NNClassifer::performClassification(vector<double>& testPoint, vector<vector<double>>& trainingGroup) {
    vector<double> result(5);
    Position p;

    double min = 420;


    for (vector<double>& trainingPoint : trainingGroup) { // for each training point in our traing group
        double distance = p.calculateDistance(testPoint, trainingPoint);

        if (distance < min) {          // keep track of the shortest distance
            min = distance;

            result[0] = testPoint[0];     // if we have a new shortest distance, save the test features and the training label to a vector group (to compare labels) 
            result[1] = testPoint[1];
            result[2] = testPoint[2];
            result[3] = (trainingPoint.size() > 3) ? trainingPoint[3] : -1;
            result[4] = (testPoint.size() > 3) ? testPoint[3] : -1; // Only if the testpoint 3 exists (so with the training and test files) then take it, else leave it as -1
        }
    }

    return result;
}
