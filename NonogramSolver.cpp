#include "NonogramSolver.h"


NonogramSolver::NonogramSolver(Nonogrammap* puzzleToSolve)
{
	puzzle = puzzleToSolve;
	unSolved = puzzle->getCount();
	
	for (int x = 0; x < puzzle->getWidth(); x++)
	{
		std::vector<state> tempRow;
		for (int y = 0; y < puzzle->getHeight(); x++)
		{
			tempRow.push_back(UNKNOWN);
		}
		column.push_back(tempRow);
	}
}

void NonogramSolver::solvePuzzle()
{
	//laske varmat
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