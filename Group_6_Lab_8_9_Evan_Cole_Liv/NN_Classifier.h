#pragma once
#include <iostream>
#include <string>

using namespace std;

class NNClassifer {
public:
	NNClassifer();

	void sampleDataOrientation(double x, double y, double z);

	int sampleData(int& selected, double& x, double& y, double& z, int& xEntered, int& yEntered, int& zEntered); // output will be orientation 
	
	void userDataFile(string filename); // output will be another file named result.txt which includes your data (presuming this means the users data file) and the corresponding phone orientation (0.2872,0.8627,-0.9832,1,Face up)

	friend void orientation(int xEntered, int yEntered, int zEntered, double x, double y, double z);
};

double difference(double i);