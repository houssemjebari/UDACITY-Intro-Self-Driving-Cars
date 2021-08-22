#include "headers/print.h"
using namespace std;

void print_vector_float(vector< vector <float>> const& grid) {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_vector_char(vector<vector<char>> const& grid) {
	int rows = grid.size();
	int cols = grid[0].size();

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
