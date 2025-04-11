#include "menu.h"
#include "Position.h"
#include "NN_Classifier.h"

double Position::calculateDistance(vector<double>& trn, vector<double>& tst) { // calculate between given point and another point (trn = training, tst = testing)

	double distance = sqrt(pow(trn[0] - tst[0], 2) + pow(trn[1] - tst[1], 2) + pow(trn[2] - tst[2], 2));

	return distance;
}