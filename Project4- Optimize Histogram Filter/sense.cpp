#include "headers/sense.h"

using namespace std;

vector<vector<float>>& sense(char color, vector<vector<char>> const& grid, vector<vector<float>> const& beliefs,  float p_hit, float p_miss)
{
	vector< vector <float>> newGrid;
	newGrid.reserve(grid.size());
	vector<float> newRow;
	newRow.reserve(grid[0].size());
	for (int i=0; i<grid.size(); i++) {
		newRow.clear();
		for (int j=0; j<grid[0].size(); j++) {
			if (grid[i][j] == color) {
				newRow.push_back(beliefs[i][j] * p_hit);
			}
			else {
				newRow.push_back(beliefs[i][j] * p_miss);
			}
		}
		newGrid.push_back(newRow);
	}
	return newGrid;
}
