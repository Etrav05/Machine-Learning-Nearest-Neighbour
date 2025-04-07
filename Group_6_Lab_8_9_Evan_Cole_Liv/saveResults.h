#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
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

LINE createLine(double x, double y, double z, int label);

void addNode(PLINENODE* list, LINE l);

LINE copyLine(LINE l);

// functions to save linked list to file
bool saveResultsToFile(PLINENODE head);