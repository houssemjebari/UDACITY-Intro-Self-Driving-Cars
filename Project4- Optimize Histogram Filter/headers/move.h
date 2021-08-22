#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <iostream>

std::vector< std::vector <float> >& move(int dy, int dx,
	std::vector < std::vector <float> > const& beliefs);

#endif /* MOVE.H */
