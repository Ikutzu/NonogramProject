#include "NonogramSolver.h"


NonogramSolver::NonogramSolver(Nonogrammap* puzzleToSolve)
{
	puzzle = puzzleToSolve;
	unsolved = 0;

	topBorder = puzzle->getTopBorder();
	leftBorder = puzzle->getLeftBorder();

	for (int i = 0; i < topBorder.size(); i++)
	{
		for (int j = 0; j < topBorder.at(i).size(); j++)
		{
			if (topBorder[i][j] == 0)
				topBorder[i].erase(topBorder[i].begin()+j, topBorder[i].end());
		}
		topBorder.at(i).shrink_to_fit();
	}

	for (int i = 0; i < leftBorder.size(); i++)
	{
		for (int j = 0; j < leftBorder.at(i).size(); j++)
		{
			if (leftBorder[i][j] == 0)
				leftBorder[i].erase(leftBorder[i].begin() + j, leftBorder[i].end());
		}
		leftBorder.at(i).shrink_to_fit();
	}

	for (int x = 0; x < puzzle->getWidth(); x++)
	{
		std::vector<state> tempRow;
		for (int y = 0; y < puzzle->getHeight(); y++)
		{
			tempRow.push_back(UNKNOWN);
		}
		column.push_back(tempRow);
	}
}

void NonogramSolver::SolvePuzzle()
{
	// 1. laske varmat
	CalculateUndisputed();

	//päivitä reunavektorit
	UpdateBorders();
	//FindEmpties();
	//while (unSolved > 0)
	//{
	//	// 2. vertaile serialien määrää
	//		// hae ensimmäinen täytetty jonka jälkeen hae ensimmäinen tyhjä ja täytä
	//		// seruaavaan täytettyyn asti
	PrintSolution();
   	FillUnknownsBetweenFilled();
	//	//päivitä reunavektorit
	UpdateBorders();

	//PrintSolution();

	//FindEmpty();
	//	
	//	// 3. vartaile omien reunavektoreiden serial arvoja mapin vastaaviin
	//		// onko määrä sama? tai onko oma serial arvo sama kuin mapin isoin serial arvo
	//		// onko samoja serialeja (samassa kohdassa)?
	//			// aseta reunat EMPTYksi (tarkista ettei mapin ulkopuolella)
	
	//	// päivitä reunavektorit

	//	// 4. jos omien ja mapin serialien määrä sama, ja omia serialeja vain yksi ratkaisematta
	//		// kokorivin UNKNOWNit -> EMPTY. 
	//		// laske mapin serial - oma serial = erotus
	//		// etsi serialia vastaava rypäs, ensimmäinen FILLED ja sen koordinaatti ( X ) minus erotus 
	//		// välinen alue asetetaan UNKNOWN, viimeinen FILLED koordinaatti ja X + map serial 
	//		// välinen alue asetetaan UNKNOWN
	//		// muista tarkistaa ettei mennä vektori rajojen ulkopuolelle

	//	// päivitä reunavektorit

	//	// 5. pitäis miettiä logiikka uusiksi ja tarkemmin niin että se toimii aina eikä tuu virheitä
	//
	//

	//}
}

void NonogramSolver::PrintSolution()
{
	for (int i = 0; i < puzzle->getBorderHeight(); i++)
	{
		for (int j = 0; j < puzzle->getBorderWidth(); j++)
			printf("  ");
		printf(" ");

		for (int b = 0; b < puzzle->getWidth(); b++)
		{
			if (puzzle->getTopBorder().at(b).at(i) != 0)
				printf("%i", puzzle->getTopBorder().at(b).at(i));
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < puzzle->getHeight(); i++)
	{
		for (int b = 0; b < puzzle->getBorderWidth(); b++)
		{
			if (puzzle->getLeftBorder().at(i).at(b) != 0)
				printf("%i", puzzle->getLeftBorder().at(i).at(b));
			else
				printf(" ");
			if(puzzle->getLeftBorder()[i][b] < 10)
				printf(" ");
		}


		printf(" ");

		for (int j = 0; j < puzzle->getWidth(); j++)
		{
			char tempChar;
			state tempState = column.at(j).at(i);

			switch (tempState)
			{
			case FILLED:
				tempChar = '#';
				break;

			case EMPTY:
				tempChar = '+';
				break;

			case UNKNOWN:
				tempChar = '-';
				break;

			default:
				break;
			}

			printf("%c", tempChar);
		}

		printf("\n");
	}
	printf("\n");
	/*
	for (int i = 0; i < puzzle->getHeight(); i++)
	{
		for (int j = 0; j < puzzle->getWidth(); j++)
		{
			char tempChar;
			state tempState = column.at(j).at(i);

			switch (tempState)
			{
			case FILLED:
				tempChar = '0';
				break;

			case EMPTY:
				tempChar = 'X';
				break;

			case UNKNOWN:
				tempChar = '-';
				break;

			default:
				break;
			}

			printf("%c", tempChar);
		}

		printf("\n");
	}
	printf("\n");
	*/
}

// private
void NonogramSolver::CalculateUndisputed()
{
	// 1. laske varmat
	for (int w = 0; w < topBorder.size(); w++)
	{
		int serialValue;

		for (int h = 0; h < topBorder.at(w).size(); h++)
		{
			serialValue = AddUpSeries(topBorder.at(w), topBorder.at(w).at(h));

			if (serialValue > puzzle->getHeight())
			{
				int coordinate = 0;

				for (int i = 0; i < h; i++)
				{
					coordinate += topBorder.at(w).at(i);
					coordinate++;
				}

				int overFlow = serialValue - puzzle->getHeight();

				coordinate += topBorder.at(w).at(h) - overFlow;

				for (int i = coordinate; i < coordinate + overFlow; i++)
				{
					column.at(w).at(i) = FILLED;
				}
			}
		}
	}

	for (int h = 0; h < leftBorder.size(); h++)
	{
		int serialValue;

		for (int w = 0; w < leftBorder.at(h).size(); w++)
		{
			serialValue = AddUpSeries(leftBorder.at(h), leftBorder.at(h).at(w));

			if (serialValue > puzzle->getWidth())
			{
				int coordinate = 0;

				for (int i = 0; i < w; i++)
				{
					coordinate += leftBorder.at(h).at(i);
					coordinate++;
				}

				int overFlow = serialValue - puzzle->getWidth();

				coordinate += leftBorder.at(h).at(w) - overFlow;

				for (int i = coordinate; i < coordinate + overFlow; i++)
				{
					column.at(i).at(h) = FILLED;
				}
			}
		}
	}
}

void NonogramSolver::FillUnknownsBetweenFilled()
{
	//	// 2. vertaile serialien määrää
	//		// hae ensimmäinen täytetty jonka jälkeen hae ensimmäinen tyhjä ja täytä
	//		// seruaavaan täytettyyn asti

	for (int x = 0; x < topBorder.size(); x++)
	{
		int nextY = 0;
		if (topBorder[x].size() < solvedTopBorder[x].size())
		{
			for (int i = 0; i < topBorder[x].size(); i++)
			{
				int restOfSerials = 0;
				for (int j = i + 1; j < topBorder[x].size(); j++)
				{
					restOfSerials += topBorder[x][j] + 1;
				}

				bool between = false;
				bool sameSerial = false;
				bool possiblySame = false;
				bool restSerialsFit = true;
				for (int y = nextY; y < puzzle->getHeight(); y++)
				{
					if (column[x][y] == FILLED && !sameSerial)
					{
						if (restOfSerials + y >= puzzle->getHeight())
							restSerialsFit = false;

						sameSerial = true;
						switch (between)
						{
						case true:
							between = false;
							break;

						case false:
							between = true;
							bool anotherSameSerial = true;
							for (int j = 0; j < topBorder[x][i]; j++)
							{
								if (y + j + 1 < puzzle->getHeight())
								{
									if (column[x][y + j + 1] != FILLED)
										anotherSameSerial = false;
								
									if (column[x][y + j + 1] == FILLED && restSerialsFit && !anotherSameSerial)
									{
										possiblySame = true;
										j = topBorder[x][i];
									}
									else
										possiblySame = false;
								}
							}
							break;
						}
					}
					if (column[x][y] != FILLED)
					{
						sameSerial = false;
						if (!between)
							nextY = y + 1;
					}

					if (between && possiblySame)
						column[x][y] = FILLED;
				}
			}
		}
	}

	for (int y = 0; y < leftBorder.size(); y++)
	{
		int nextX = 0; 
		if (leftBorder[y].size() < solvedLeftBorder[y].size())
		{
			for (int i = 0; i < leftBorder[y].size(); i++)
			{
				int restOfSerials = 0;
				for (int j = i + 1; j < leftBorder[y].size(); j++)
				{
					restOfSerials += leftBorder[y][j] + 1;
				}

				bool between = false;
				bool sameSerial = false;
				bool possiblySame = false;
				bool restSerialsFit = true;
				for (int x = nextX; x < puzzle->getWidth(); x++)
				{
					if (column[x][y] == FILLED && !sameSerial)
					{
						if (restOfSerials + x >= puzzle->getHeight())
							restSerialsFit = false;

						sameSerial = true;
						switch (between)
						{
						case true:
							between = false;
							break;

						case false:
							between = true;
							bool anotherSameSerial = true;
							for (int j = 0; j < leftBorder[y][i]; j++)
							{
								if (x + j + 1 < puzzle->getWidth())
								{
									if (column[x + j + 1][y] != FILLED)
										anotherSameSerial = false;

									if (column[x + j + 1][y] == FILLED && restSerialsFit && !anotherSameSerial)
									{
										possiblySame = true;
										j = leftBorder[y][i];
									}
									else
										possiblySame = false;
								}
							}
							break;
						}
					}
					if (column[x][y] != FILLED)
					{
						sameSerial = false;
						if (!between)
							nextX = x + 1;
					}

					if (between && possiblySame)
						column[x][y] = FILLED;
				}
			}
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
	tempAddedSeries += currentSerial;

	return tempAddedSeries;
}

void NonogramSolver::UpdateBorders()
{
	//päivitä reunavektorit
	solvedLeftBorder.clear();
	solvedTopBorder.clear();

	unsolved = 0;
	//leftBorder
	for (int i = 0; i < puzzle->getHeight(); i++)
	{
		std::vector<int> tempRow;

		int tempXCount = 0;

		for (int j = 0; j < puzzle->getWidth(); j++)
		{
			if (column.at(j).at(i) == FILLED)
			{
				tempXCount++;
			}
			else if (tempXCount != 0)
			{
				tempRow.push_back(tempXCount);
				tempXCount = 0;
			}

			if (column[j][i] == UNKNOWN)
				unsolved++;
		}

		if (tempXCount != 0)
		{
			tempRow.push_back(tempXCount);
			tempXCount = 0;
		}
		
		solvedLeftBorder.push_back(tempRow);
	}
	//rightBorder
	for (int i = 0; i < puzzle->getWidth(); i++)
	{
		std::vector<int> tempColumn;

		int tempYCount = 0;

		for (int j = 0; j < puzzle->getHeight(); j++)
		{
			int a = 0;

			if (column.at(i).at(j) == FILLED)
			{
				tempYCount++;
			}
			else if (tempYCount != 0)
			{
				tempColumn.push_back(tempYCount);
				tempYCount = 0;
			}
		}

		if (tempYCount != 0)
		{
			tempColumn.push_back(tempYCount);
			tempYCount = 0;
		}
		
		solvedTopBorder.push_back(tempColumn);
	}
}

void NonogramSolver::FindEmpty()
{
	// doing stuff
	for (int x = 0; x < topBorder.size(); x++)
	{
		if (topBorder[x].size() == solvedTopBorder[x].size())
		{
			bool fillThis = true;
			if (topBorder[x].size() > 1)
			{
				int tempCounter = 0;
				for (int y = 0; y < leftBorder.size(); y++)
				{
					if (column[x][y] == FILLED)
					{
						tempCounter = y;
						break;
					}
				}
				if (tempCounter > topBorder[x][0])
				{
					fillThis = false;
				}
			}
			if (fillThis)
			{
				for (int y = 0; y < leftBorder.size(); y++)
				{
					if (column[x][y] != FILLED)
						column[x][y] = EMPTY;
				}
			}
		}
	}
	for (int y = 0; y < leftBorder.size(); y++)
	{
		if (leftBorder[y].size() == solvedLeftBorder[y].size())
		{
			bool fillThis = true;
			if (leftBorder[y].size() > 1)
			{
				int tempCounter = 0;
				for (int x = 0; x < topBorder.size(); x++)
				{
					if (column[x][y] == FILLED)
					{
						tempCounter = x;
						break;
					}
				}
				if (tempCounter > leftBorder[y][0])
				{
					fillThis = false;
				}
			}
			if (fillThis)
			{
				for (int x = 0; x < topBorder.size(); x++)
				{
					if (column[x][y] != FILLED)
						column[x][y] = EMPTY;
				}
			}
		}
	}
	//vertical
	for (int x = 0; x < topBorder.size(); x++)
	{
		if (topBorder[x].size() == solvedTopBorder[x].size())
		{
			bool fillThis = true;
			if (topBorder[x].size() > 1)
			{
				int tempCounter = 0;
				for (int y = 0; y < leftBorder.size(); y++)
				{
					if (column[x][y] == FILLED)
					{
						tempCounter = y;
						break;
					}
				}
				if (tempCounter > topBorder[x][0])
				{
					fillThis = false;
				}
			}
			if (fillThis)
			{
				int nextY = 0;
				for (int i = 0; i < topBorder[x].size(); i++)
				{
					int unknownArea = topBorder[x][i] - solvedTopBorder[x][i];
					bool same = false;
					for (int y = nextY; y < column[x].size(); y++)
					{
						if (column[x][y] == FILLED)
						{
							same = true;
							for (int j = unknownArea; j > 0; j--)
							{
								if (y - j >= 0)
								{
									if (column[x][y - j] != FILLED)
									{
										if (y - j - 1 >= 0)
										{
											if (column[x][y - j - 1] != FILLED)
												column[x][y - j] = UNKNOWN;
										}
										else
											column[x][y - j] = UNKNOWN;
									}
								}
								if (y + topBorder[x][i] - j < leftBorder.size())
								{
									if (column[x][y + topBorder[x][i] - j] != FILLED)
									{
										if (y + topBorder[x][i] - j + 1 < leftBorder.size())
										{
											if (column[x][y + topBorder[x][i] - j + 1] != FILLED)
												column[x][y + topBorder[x][i] - j] = UNKNOWN;
										}
										else
											column[x][y + topBorder[x][i] - j] = UNKNOWN;
									}
								}
							}
						}
						if (column[x][y] != FILLED && same)
						{
							nextY = y;
							y = column[x].size();
						}
					}
				}
			}
		}
	}
	//horizontal
	for (int y = 0; y < leftBorder.size(); y++)
	{
		if (leftBorder[y].size() == solvedLeftBorder[y].size())
		{
			bool fillThis = true;
			if (leftBorder[y].size() > 1)
			{
				int tempCounter = 0;
				for (int x = 0; x < topBorder.size(); x++)
				{
					if (column[x][y] == FILLED)
					{
						tempCounter = x;
						break;
					}
				}
				if (tempCounter > leftBorder[y][0])
				{
					fillThis = false;
				}
			}
			if (fillThis)
			{
				int nextX = 0;
				for (int i = 0; i < leftBorder[y].size(); i++)
				{
					int unknownArea = leftBorder[y][i] - solvedLeftBorder[y][i];
					bool same = false;
					for (int x = nextX; x < topBorder.size(); x++)
					{
						if (column[x][y] == FILLED)
						{
							same = true;
							for (int j = unknownArea; j > 0; j--)
							{
								if (x - j >= 0)
								{
									if (column[x - j][y] != FILLED)
									{
										if (x - j - 1 >= 0)
										{
											if (column[x - j - 1][y] != FILLED)
												column[x - j][y] = UNKNOWN;
										}
										else
											column[x - j][y] = UNKNOWN;
									}
								}
								if (x + leftBorder[y][i] - j < topBorder.size())
								{
									if (column[x + leftBorder[y][i] - j][y] != FILLED)
									{
										if (x + leftBorder[y][i] - j + 1 < topBorder.size())
										{
											if (column[x + leftBorder[y][i] - j + 1][y] != FILLED)
												column[x + leftBorder[y][i] - j][y] = UNKNOWN;
										}
										else
											column[x + leftBorder[y][i] - j][y] = UNKNOWN;
									}
								}
							}
						}
						else if (column[x][y] == UNKNOWN && same)
							same = false;
					}
				}
			}
		}
	}
}