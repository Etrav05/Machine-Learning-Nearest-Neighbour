#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

typedef struct line {
	double x;
	double y;
	double z;
	int label;
	string labelName;
} LINE;

typedef struct lineNode {
	LINE data;
	struct lineNode* next;
} LINENODE, *PLINENODE;

LINE createLine(int x, int y);

void addNode(PLINENODE* list, LINE l);

LINE copyLine(LINE l);

void freeLines(PLINENODE head);


// functions to save linked list to file
void saveResultsToArray(double x, double y, double z, int label);

bool saveResultsToFile(string* array);