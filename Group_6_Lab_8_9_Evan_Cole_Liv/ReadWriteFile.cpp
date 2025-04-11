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

bool ReadWriteFile::saveResultsToFile(vector<vector<double>>& results) {
    string labels[6] = { "Face up", "Face down", "Portrait", "Portrait upside down", "Landscape left", "Landscape right" };
    string filename = "results.txt";
    ofstream fout(filename);

    if (!fout.is_open()) {
        cout << "Data could not be saved - results.txt could not be opened" << endl;
        Sleep(1000);
        return false;
    }

    for (vector<double>& row : results) {
        for (size_t i = 0; i < row.size(); ++i) {
            fout << row[i];
            if (i < row.size() - 1)
                fout << ",";
        }

        int i = (row[3]) - 1; // add the labels name
        if (i >= 0 && i < 6)
            fout << "," << labels[i];
        else
            fout << ", Not known";

        fout << endl;
    }

    fout.close();
    return true;
}

