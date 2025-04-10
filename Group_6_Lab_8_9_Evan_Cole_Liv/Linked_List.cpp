#include "Linked_List.h"

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
