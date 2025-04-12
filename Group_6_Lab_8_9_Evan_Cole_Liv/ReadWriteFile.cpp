#include "ReadWriteFile.h"

vector<double> ReadWriteFile::getParsedData(string& line) {
	istringstream issLine(line); // open the file as reading
	string value;               // create a value variable to look for
	vector<double> result;     // create a vector group to save this values

	while (!issLine.eof()) {              // until the end of line
		getline(issLine, value, ',');    // get each vaule beside the commas
		result.push_back(stod(value));  // push these valeus to the result vector
	}

	return result; // return teh vector group
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

	return group; // return the group
}

bool ReadWriteFile::saveResultsToFile(vector<vector<double>>& results) {
    string labels[6] = { "Face up", "Face down", "Portrait", "Portrait upside down", "Landscape left", "Landscape right" }; // create corresponding label
    string filename = "results.txt"; // define results file
    ofstream fout(filename); // open file as writing

    if (!fout.is_open()) { // if the file couldnt be opene, print error
        cout << "Data could not be saved - results.txt could not be opened" << endl;
        Sleep(1000);
        return false;
    }

    for (vector<double>& row : results) {          // for each row in results
        for (size_t i = 0; i < row.size(); ++i) { // for the size of the row
            fout << row[i];                      // print the value to file
            if (i < row.size() - 1)             // then a comma (minus at the end of the file)
                fout << ",";
        }

        int i = (row[3]) - 1;               // add the labels name  
        if (i >= 0 && i < 6)               // at the end of each line
            fout << "," << labels[i];
        else
            fout << ", Not known";      // if the label had an error, simply print not known

        fout << endl;
    }

    fout.close();  // close file
    return true;  // Return that the saving passed
}

