#include "headers/blur.h"

using namespace std;

vector<vector<float>>& blur(vector<vector<float>> const& grid, float blurring) {

    // calculate blur factors
    static float center = 1.0 - blurring;
    static float corner = blurring / 12.0;
    static float adjacent = blurring / 6.0;

    //create the blur window
    static vector< vector<float> > window = {
        {corner, adjacent, corner},
        {adjacent, center, adjacent},
        {corner, adjacent, corner}};
    window.reserve(3);

	// variables for blur calculations
	static vector <int> DX{-1,0,1};
	DX.reserve(3);

	static vector <int> DY{-1,0,1};
	DY.reserve(3);
    // Instantiate the newGrid
	static vector<vector<float>> newGrid(grid.size(),vector<float> (grid[0].size(),0));
	newGrid.reserve(grid.size());

	// blur the grid and store in a new 2D vector
	for (int i=0; i< grid.size(); i++ ) {
		for (int j=0; j<grid[0].size(); j++ ) {
			for (int ii=0; ii<3; ii++) {
				for (int jj=0; jj<3; jj++) {
					newGrid[(i + DY[ii] + grid.size()) % grid.size()][(j + DX[jj] + grid[0].size()) % grid[0].size()] += grid[i][j] * window[ii][jj];
				}
			}
		}
	}

	return newGrid;
}
