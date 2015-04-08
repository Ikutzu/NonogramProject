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

		for (int x = 0; x < column.size(); x++)
		{

			int tempY = 0;

			while (tempY < column.at(x).size())
			{
				int tempBetween = 0;
				std::vector<int> tempUnsolvedSeries;

				for (int y = tempY; y < column.at(x).size(); y++)
				{
					if (column[x][y] != state::BLANK)
					{
						tempY++;
						tempBetween++;
						break;
					}
					else
					{
						tempY++;
						tempBetween++;
					}
				}

				int tempSerialSum = 0;
				for (int y = 0; y < topBorder.size(); y++)
				{
					tempSerialSum += topBorder[x][y];
					tempUnsolvedSeries.push_back(topBorder[x][y]);
					if (tempSerialSum > tempBetween)
						break;
				}

				CalculateBetween(tempUnsolvedSeries, tempBetween);

			}



		}


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