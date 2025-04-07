#include "saveResults.h"

LINE createLine(double x, double y, double z, int label) {
	LINE l;
	string labelNames[6] = { "Face up", "Face down", "Portrait", "Portrait upside down", "Landscape left", "Landscape right" };
	int labelIndex = label - 1;

	l.x = x;
	l.y = y;
	l.z = z;
	l.label = label;
	l.labelName = labelNames[labelIndex];
	return l;
}

void addNode(PLINENODE* list, LINE l) {
	PLINENODE newNode = new LINENODE; // dynamically allocate memory

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
	return createLine(l.x, l.y, l.z, l.label);
}

bool saveResultsToFile(PLINENODE head) {
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