#include "headers/normalize.h"
using namespace std;

vector<vector<float>>& normalize(vector<vector <float>> const& grid) {

 	static float total = 0.0;
	vector<float> newRow;
	newRow.reserve(grid[0].size());
    vector< vector<float> > newGrid;
    newGrid.reserve(grid.size());
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j=0; j< grid[0].size(); j++)
		{
			total += grid[i][j];
		}
	}
	for (int i = 0; i < grid.size(); i++) {
		newRow.clear();
		for (int j=0; j< grid[0].size(); j++) {
			newRow.push_back(grid[i][j]/total);
		}
		newGrid.push_back(newRow);
	}
	return newGrid;
}
