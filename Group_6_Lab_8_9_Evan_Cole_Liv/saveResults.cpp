#include "saveResults.h"

LINE createLine(double x, double y, double z, int label, string labelName) {
	LINE l;
	l.x = x;
	l.y = y;
	l.z = z;
	l.label = label;
	l.labelName = labelName;
	return l;
}

void addNode(PLINENODE* list, LINE l) {
	PLINENODE newNode = (PLINENODE)malloc(sizeof(LINENODE)); // dynamically allocate memory

	if (!newNode) {
		fprintf(stderr, "Error creating line node");
		exit(EXIT_FAILURE);
	}

	else {
		newNode->data = copyLine(l);
		newNode->next = *list;
		*list = newNode;
	}
}

LINE copyLine(LINE l) {
	return createLine(l.x, l.y, l.z, l.label, l.labelName);
}

void freeLines(PLINENODE line) {
	PLINENODE temp;

	while (line != NULL) {    // until all line nodes are gone
		temp = line;	     // temp is line
		line = line->next;  // move line to the next line
		free(temp);        // free the temp
	}
}

void saveResultsToArray(double x, double y, double z, int label, int line) {
	string labelNames[6] = { "Face up", "Face down", "Portrait", "Portrait upside down", "Landscape left", "Landscape right" }; // create an array of the lael names 
	

}

bool saveResultsToFile(string* array) {
	string filename = "results.txt";
	ofstream fout;

	fout.open(filename);

	if (fout.is_open()) {
		for (int i = 0; i < sizeof(array); i++) {
			fout << array << endl; // save each line to file
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