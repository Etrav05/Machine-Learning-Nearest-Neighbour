#include "UnknownLabel.h"
#include "saveResults.h"
#include "Training.h" // for the calculateDistance function as it is unchanged

UnknownLabel::UnknownLabel() {
	cout << "Unknown object default construtor" << endl;
}

void getParsedDataFromUnknown(string values, double* xyzlabel) {
	istringstream issValues(values);
	string value;
	int i = 0;

	while (!issValues.eof()) {       // since we DONT know if the data ends at 3 (UnknownData.txt) or 4 (trainingData.txt) features
		getline(issValues, value, ',');
		xyzlabel[i] = stod(value); // stod because we are working with doubles not ints (stoi)
		i++;                      // increament to next feature
	}
}

int UnknownLabel::accessFileNN_UnknownLabel(string testingfile, string trainingfile, double* trn, double* tst) { // access file and specifically parse data (trainingData.txt --- testingData.txt)
	ifstream finTst;		    // in read mode (specific to this file)
	finTst.open(testingfile);  // open file	

	if (!finTst.is_open()) { // make sure the file was opened
		cout << "Could not find testing file" << endl;
		Sleep(2000);       // give the user some time to read the error message
		system("cls");
		return 1;        // return to menu options
	}

	DataPoint point;  // use DataPoint object to calculate distances between data points
	string tstline;
	int i = 0;

	while (getline(finTst, tstline)) {
		getParsedData(tstline, tst); // get the data of the ith line line { x, y, z, label }
		double min = 420;           // used to find the minimum (set to a high number so every value will initally be smaller)
		vector<double> result(4);  // vector group (typed double) to hold result values

		ifstream finTrn;            // this is why we made a specific fin the file, so we can open out training file concurently
		finTrn.open(trainingfile);
		if (!finTrn.is_open()) {  // make sure the file was opened again
			cout << "Could not find training file" << endl;
			Sleep(2000);        // give the user some time to read the error message
			system("cls");
			return 1;
		}

		string trnline;
		while (getline(finTrn, trnline)) {
			getParsedData(trnline, trn); // get the data of each line from the training file { x, y, z, label }

			double distance = point.calculateDistance(trn, tst); // calculate the distance from the given line data to our initial test line data
			if (distance < min) {      // keep track of the shortest distance
				min = distance;
				result[0] = tst[0];  // if we have a new shortest distance, save the test features and the training label to a vector group (to compare labels) 
				result[1] = tst[1];
				result[2] = tst[2];
				result[3] = trn[3];
			}
		}
		finTrn.close(); // close the training file

		cout << "Calculating line " << setw(3) << i + 1 << ": ( "  // this block is just to make it so the prints will all be aligned (improves readability up to the hundreds)
			<< fixed << setprecision(5)                           // set the number of decimal places we will print to
			<< setw(8) << result[0] << ", "                      // setw(x) sets the width that result[0] will print within, and since result[0] was set to a max precision of 5, it will never outgrow this space
			<< setw(8) << result[1] << ", "
			<< setw(8) << result[2] << " )    "
			<< "Predicted Label: " << (int)result[3] << "\n";

		saveResultsToArray(result[0], result[1], result[2], result[3], i); // save these results to a file

		i++; // increment to the next line of the test file
	}

	// saveResultsToFile(array); // save these results to a file

	cout << "=====+===== =======+===== =====+======+=====+===== =====+======= =====+=====" << endl;
	cout << "=====+===== This information has been save to file (results.txt) =====+=====" << endl;
	cout << "=====+===== =======+===== =====+======+=====+===== =====+======= =====+=====" << endl;
	finTst.close();
	return 0;
}
