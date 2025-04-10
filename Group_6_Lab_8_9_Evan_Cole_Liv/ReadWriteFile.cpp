#include "ReadWriteFile.h"

void ReadWriteFile::getParsedData(string values, double* xyzlabel) {
	istringstream issValues(values);
	string value;
	int i = 0;
	while (!issValues.eof()) {       // until the end of the line, read each value
		getline(issValues, value, ',');
		xyzlabel[i] = stod(value); // stod because we are working with doubles not ints (stoi)
		i++;
	}
}

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
