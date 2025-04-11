#include "ReadWriteFile.h"

vector<double> ReadWriteFile::getParsedData(string& line) {
	istringstream issLine(line);
	string value;
	vector<double> result;

	while (!issLine.eof()) {
		getline(issLine, value, ',');
		result.push_back(stod(value));
	}

	return result;
}

vector<vector<double>> ReadWriteFile::createCoordinateGroups(string& filename) {
	vector<vector<double>> group; // initialize group
	ifstream infile(filename);   // open file as read
	string line;                // initialize line

	while (getline(infile, line)) {  // while we can still get lines from the file
		if (!line.empty()) {        // if its not empty 
			vector<double> parsed = getParsedData(line); // pased the data
			group.push_back(parsed);                    // push it to the vector<vector> group
		}
	}

	return group;
}

// TODO: update to match above
bool ReadWriteFile::saveResultsToFile(PLINENODE head) {
	string filename = "results.txt";
	PLINENODE temp = NULL;

	ofstream fout;

	fout.open(filename);

	if (fout.is_open()) {
		while (head != NULL) {                        // until all line nodes printed
			fout << head->data.x << ","             // print each feature to file
				<< head->data.y << ","
				<< head->data.z << ","
				<< head->data.label << ","
				<< head->data.labelName << endl; // print in desired format
			temp = head;                        // temp is line
			head = head->next;                 // move line to the next line
			delete temp;                       // free memory as we go
		}

		fout.close();
	}

	else {
		cout << "results.txt could not be opened" << endl;
		Sleep(1000);
		return false;
	}

	return true;
}


/*
 if (rwf.saveResultsToFile(head)) { // save these results to a file, if this passes then print a message
		cout << "=====+===== =======+===== =====+======+=====+===== =====+======= =====+=====" << endl;
		cout << "=====+===== This information has been save to file (results.txt) =====+=====" << endl;
		cout << "=====+===== =======+===== =====+======+=====+===== =====+======= =====+=====" << endl;
	}
*/