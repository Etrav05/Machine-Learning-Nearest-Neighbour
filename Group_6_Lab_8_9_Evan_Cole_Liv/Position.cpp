#include "Position.h"
#include "menu.h"
#include "NN_Classifier.h"

double Position::calculateDistance(double* trn, double* tst) { // calculate between given point and another point (trn = training, tst = testing)

	double distance = sqrt(pow(trn[0] - tst[0], 2) + pow(trn[1] - tst[1], 2) + pow(trn[2] - tst[2], 2));

	return distance;
}

double Position::difference(double i) {
		if (i > 0) 
			return  1 - i;

		else 
			return 1 + i;
}


void Position::orientation(int xEntered, int yEntered, int zEntered, double x, double y, double z) {
    Menu m;
    NNClassifer sample;
    m.setCursorPosition(0, 8);

    if (xEntered == 1 && yEntered == 1 && zEntered == 1) {
        sample.performClassification_SampleData(x, y, z);
    }
    else {
        cout << "Please enter value(s) for: " << (xEntered == 0 ? "x " : " ") << (yEntered == 0 ? "y " : " ") << (zEntered == 0 ? "z " : " ") << endl;
    }
    m.setCursorPosition(0, 0);
}