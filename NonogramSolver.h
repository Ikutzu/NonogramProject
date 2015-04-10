#ifndef NONOGRAMSOLVER_H
#define NONOGRAMSOLVER_H

#include "Nonogrammap.h"
#include <vector>



class NonogramSolver
{
public:
	NonogramSolver(Nonogrammap* puzzleToSolve);
	void solvePuzzle();

private:

	void CalculateBetween(std::vector<int> unsolvedSeries, int between);
	int AddUpSeries(std::vector<int> series, int currentSerial);

	Nonogrammap* puzzle;
	int unSolved;
	std::vector<std::vector<int>> solvedLeftBorder;
	std::vector<std::vector<int>> solvedTopBorder;
	std::vector<std::vector<state>> column;

};


#endif //NONOGRAMSOLVER_H