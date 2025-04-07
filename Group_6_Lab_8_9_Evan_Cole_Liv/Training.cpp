#include "Training.h"

// For each test point, calculate its distance to all training points

// Keep track of the closest training point

// Return the label of that closest point

DataPoint::DataPoint() {
	cout << "Data object default constructor" << endl;
}

void getParsedData(string values, double* xyzlabel) {
	istringstream issValues(values);
	string value;

	for (int i = 0; i < 4; i++) { // since we know the end of line is after 4 values
		getline(issValues, value, ',');
		xyzlabel[i] = stod(value); // stod because we are working with doubles not ints (stoi)
	}
}

double DataPoint::calculateDistance(double* trn, double* tst) { // calculate between given point and another point (trn = training, tst = testing)

	double distance = sqrt(pow(trn[0] - tst[0], 2) + pow(trn[1] - tst[1], 2) + pow(trn[2] - tst[2], 2));

	return distance;
}

void DataPoint::accessFileNN(string testingfile, string trainingfile, double* trn, double* tst) { // access file and specifically parse data (trainingData.txt --- testingData.txt)
	ifstream finTst;		   // in read mode (specific to this file)
	finTst.open(testingfile); // open file	

	if (!finTst.is_open()) { // make sure the file was opened
		cout << "Could not find testing file" << endl;
		return;
	}

	string tstline;
	int i = 0;

	while (getline(finTst, tstline)) {
		getParsedData(tstline, tst); // get the data of the ith line line { x, y, z, label }
		double min = 420;           // used to find the minimum (set to a high number so every value will initally be smaller)
		vector<double> result(5);  // vector group (typed double) to hold result values

		ifstream finTrn;        // this is why we made a specific fin the file, so we can open out training file concurently
		finTrn.open(trainingfile);
		if (!finTrn.is_open()) {  // make sure the file was opened again
			cout << "Could not find training file" << endl;
			return;
		}

		string trnline;
		while (getline(finTrn, trnline)) {
			getParsedData(trnline, trn); // get the data of each line from the training file { x, y, z, label }

			double distance = calculateDistance(trn, tst); // calculate the distance from the given line data to our initial test line data
			if (distance < min) {      // keep track of the shortest distance
				min = distance;
				result[0] = tst[0];  // if we have anew shortest distance, save the test features and the training label to a vector group (to compare labels) 
				result[1] = tst[1];
				result[2] = tst[2];
				result[3] = tst[3];
				result[4] = trn[3];
			}
		}
		finTrn.close(); // close the training file

		cout << "\nTest (" << result[0] << ", " << result[1] << ", " << result[2] << ") ";
		cout << "Actual Label: " << result[3] << ", Predicted Label: " << result[4] << "\n";

		i++; // increment to the next line of the test file
	}

	finTst.close();
}
