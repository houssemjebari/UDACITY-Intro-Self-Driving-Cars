#include "headers/zeros.h"

using namespace std;

vector <vector<float>>& zeros(int height, int width) {
	static vector <vector<float>> newGrid(height,vector <float>(width));
	newGrid.reserve(height);
	return newGrid;
}
