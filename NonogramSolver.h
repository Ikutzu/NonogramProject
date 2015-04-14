#ifndef NONOGRAMSOLVER_H
#define NONOGRAMSOLVER_H

#include "Nonogrammap.h"
#include <vector>



class NonogramSolver
{
public:
	NonogramSolver(Nonogrammap* puzzleToSolve);
	void SolvePuzzle();
	void PrintSolution();
	
private:
	
	void CalculateUndisputed();
	void FillUnknownsBetweenFilled();
	int AddUpSeries(std::vector<int> series, int currentSerial);
	void UpdateBorders();
	void FindEmpty();


	std::vector<std::vector<int>> leftBorder;
	std::vector<std::vector<int>> topBorder;

	Nonogrammap* puzzle;
	int unsolved;
	std::vector<std::vector<int>> solvedLeftBorder;
	std::vector<std::vector<int>> solvedTopBorder;
	std::vector<std::vector<state>> column;

};


#endif //NONOGRAMSOLVER_H