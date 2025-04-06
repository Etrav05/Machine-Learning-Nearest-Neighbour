#include "DataPoint.h"

DataPoint::DataPoint() {
	cout << "Data data data" << endl;
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

	return sqrt(pow(trn[0] - tst[0], 2) + pow(trn[1] - tst[1], 2) + pow(trn[2] - tst[2], 2));
}

void DataPoint::accessDataPoint(string testingfile, string trainingfile, double* trn, double* tst) { // access file and specifically parse data (trainingData.txt --- testingData.txt)
	ifstream fin;			 // in read mode
	double min = 10;        // used to find the minimum (set to 10 so all values will be less than)
	int i = 0;
	fin.open(testingfile); // open file

	if (fin.is_open()) { // make sure the file was openned
		if (i < 28) {
			string line;
			getline(fin, line);
			getParsedData(line, tst); // get the data of the ith line line { x, y, z, label }
		}
	}
	else { cout << "File could not be found" << endl; }

	fin.close();             // close testing file
	fin.open(trainingfile); // and open training file (we have a line of the testing file)

	if (fin.is_open()) {  // make sure the file was openned

		while (!fin.eof()) {
			string line;
			while (getline(fin, line)) {        // while we parse data
				getParsedData(line, trn); // get the data of each line from the training file { x, y, z, label }
				double distance = calculateDistance(trn, tst);

				if (distance < min) { min = distance; } // keep track of the shortest distance
			}
		}
	} 
	else { cout << "File could not be found" << endl; }
	fin.close();

	cout << "min: " << min << " --> therefore label equals: " << "TODO" << endl;
}

// For each test point, calculate its distance to all training points

// Keep track of the closest training point

// Return the label of that closest point
