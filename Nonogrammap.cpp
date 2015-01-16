#include "Nonogrammap.h"


Nonogrammap::Nonogrammap(unsigned int mapHeight, unsigned int mapWidth)
{
	height = mapHeight;
	width = mapWidth;
	coordinateCount = height * width;

	column.resize(width);
	
	for (unsigned i = 0; i < width; i++)
	{
		std::vector<state> tempRow;
		tempRow.resize(height);

		for (unsigned j = 0; j < height; j++)
		{
			int tempMember = rand() % 2;
			tempRow.at(j) = (state)tempMember;
		}
		
		column.at(i) = tempRow;
	}

	for (unsigned int i = 0; i < height; i++)
	{
		for (unsigned int j = 0; j < width; j++)
		{
			coordinate* tempCoord = new coordinate;

			tempCoord->state = BLANK;
			tempCoord->x = j;
			tempCoord->y = i;

			coordinates.push_back(tempCoord);
		}
	}
};

Nonogrammap::~Nonogrammap()
{
	clearMap();
}

void Nonogrammap::clearMap()
{
	std::vector<coordinate*>::iterator it;

	for (it = coordinates.begin(); it != coordinates.end(); it++)
	{
		delete (*it);
	}
}

void Nonogrammap::print()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			char tempChar;
			state tempState = column.at(j).at(i);

			switch (tempState)
			{
				case BLANK:
					tempChar = ' ';
					break;

				case EMPTY:
					tempChar = 'X';
					break;

				case FILLED:
					tempChar = 'O';
					break;

				default:
					break;
			}

			printf("%c", tempChar);
		}

		printf("\n");
	}
}

unsigned int Nonogrammap::getCount()
{
	return coordinateCount;
}

unsigned int Nonogrammap::getHeight()
{
	return height;
}

unsigned int Nonogrammap::getWidth()
{
	return width;
}