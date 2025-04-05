#pragma once
#include <iostream>

using namespace std;

class NNClassifer {
public:
	NNClassifer();

	void sampleData(double x, double y, double z, int selected); // output will be orientation 
	
	void userDataFile(string filename); // output will be another file named result.txt which includes your data (presuming this means the users data file) and the corresponding phone orientation (0.2872,0.8627,-0.9832,1,Face up)
};