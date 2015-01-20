#include "Nonogrammap.h"


Nonogrammap::Nonogrammap(int mapHeight, int mapWidth)
{
	height = mapHeight;
	width = mapWidth;
	coordinateCount = height * width;

	column.resize(width);
	
	for (int i = 0; i < width; i++)
	{
		std::vector<state> tempRow;
		tempRow.resize(height);

		for (int j = 0; j < height; j++)
		{
			int tempMember = rand() % 2;
			tempRow.at(j) = (state)tempMember;
		}
		
		column.at(i) = tempRow;
	}

	borderHeight = 0;
	borderWidth = 0;

	for (int i = 0; i < height; i++)
	{
		std::vector<int> tempRow;

		int tempXCount = 0;

		for (int j = 0; j < width; j++)
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
		}
		
		if (tempXCount != 0)
		{
			tempRow.push_back(tempXCount);
			tempXCount = 0;
		}

		if (tempRow.size() > borderWidth)
			borderWidth = tempRow.size();

		leftBorder.push_back(tempRow);
	}

	for (int i = 0; i < width; i++)
	{
		std::vector<int> tempColumn;

		int tempYCount = 0;

		for (int j = 0; j < height; j++)
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

		if (tempColumn.size() > borderHeight)
			borderHeight = tempColumn.size();

		topBorder.push_back(tempColumn);
	}
	
	for (int i = 0; i < leftBorder.size(); i++)
		leftBorder.at(i).resize(borderWidth);

	for (int i = 0; i < topBorder.size(); i++)
		topBorder.at(i).resize(borderHeight);

};

void Nonogrammap::printAnswer()
{
	for (int i = 0; i < borderHeight; i++)
	{
		for (int j = 0; j < borderWidth; j++)
			printf("  ");
		printf(" ");

		for (int b = 0; b < width; b++)
		{
			if (topBorder.at(b).at(i) != 0)
				printf("%i", topBorder.at(b).at(i));
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < height; i++)
	{		
		for (int b = 0; b < borderWidth; b++)
		{
			if (leftBorder.at(i).at(b) != 0)
				printf("%i", leftBorder.at(i).at(b));
			else
				printf(" ");
			printf(" ");
		}
		
		
		printf(" ");

		for (int j = 0; j < width; j++)
		{
			char tempChar;
			state tempState = column.at(j).at(i);

			switch (tempState)
			{
				case FILLED:
					tempChar = 'O';
					break;

				case EMPTY:
					tempChar = ' ';
					break;
					
				case BLANK:
					tempChar = '.';
					break;

				default:
					break;
			}

			printf("%c", tempChar);
		}

		printf("\n");
	}
}

int Nonogrammap::getCount()
{
	return coordinateCount;
}

int Nonogrammap::getHeight()
{
	return height;
}

int Nonogrammap::getWidth()
{
	return width;
}