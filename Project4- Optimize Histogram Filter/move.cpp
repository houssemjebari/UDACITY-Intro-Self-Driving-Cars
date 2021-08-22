#include "headers/move.h"
#include "headers/zeros.h"

using namespace std;

vector<vector<float>>& move(int dy, int dx,vector <vector<float>> const& beliefs)
{
	vector<vector<float>> newGrid;
	newGrid = zeros(beliefs.size(), beliefs[0].size());
	for (int i=0; i<beliefs.size(); i++) {
		for (int j=0; j<beliefs[0].size(); j++) {
            newGrid[i + dy + beliefs.size()][j + dx + beliefs[0].size()] = beliefs[(i + dy + beliefs.size()) % beliefs.size()][(j + dx + beliefs[0].size())  % beliefs[0].size()];
		}
	}
	return newGrid;
}
