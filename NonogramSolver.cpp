#include "NonogramSolver.h"


NonogramSolver::NonogramSolver(Nonogrammap* puzzleToSolve)
{
	puzzle = puzzleToSolve;
	unSolved = puzzle->getCount();
}

void NonogramSolver::solvePuzzle()
{
	std::vector<std::vector<int>> leftBorder = puzzle->getLeftBorder();
	std::vector<std::vector<int>> topBorder = puzzle->getTopBorder();
	
	column.resize(puzzle->getWidth());
	for (int x = 0; x < puzzle->getWidth(); x++)
	{
		column.at(x).resize(puzzle->getHeight());
	}
	
	
	while (unSolved > 0)
	{

	}
}

// private

void NonogramSolver::CalculateBetween(std::vector<int> unsolvedSeries, int between)
{
	for (int i = 0; i < unsolvedSeries.size(); i++)
	{
		int tempOverflow = AddUpSeries(unsolvedSeries, unsolvedSeries[i]);
		if (tempOverflow > between)
		{

		}

	}


}

int NonogramSolver::AddUpSeries(std::vector<int> series, int currentSerial)
{
	int tempAddedSeries = 0;

	for (int i = 0; i < series.size(); i++)
	{
		tempAddedSeries += series[i];
	}

	tempAddedSeries += series.size() - 1;
	tempAddedSeries += series.at(currentSerial);

	return tempAddedSeries;
}