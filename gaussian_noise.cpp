#include <iostream>
#include <cmath>
#include <fstream>
#include "tmwtypes.h"
#include "stdlib.h"

using namespace std;

// Genereate Gaussian R.V
// using fstream store R.V in a txt file.

int main() {
	// random seed.
	srand(2);
	
	// length of sequence.
	int n = 1000;

	double x1[n], x2[n], x3[n], x4[n], x5[n];
	double y[n];
	
	for (int i = 0; i < n; i++) {
		x1[i] = (double)rand() / (double)RAND_MAX;
		x2[i] = (double)rand() / (double)RAND_MAX;
		x3[i] = (double)rand() / (double)RAND_MAX;
		x4[i] = (double)rand() / (double)RAND_MAX;
		x5[i] = (double)rand() / (double)RAND_MAX;
	
		y[i] = (x1[i] + x2[i] + x3[i] + x4[i] + x5[i]) / n;
	}
	
	// write file.
	ofstream outfile("gnoise.txt");
	
	for (int i = 0; i < n; i++) {
		outfile << y[i] << "\n";
	}
	
	outfile.close();
	
	return 0;
}
