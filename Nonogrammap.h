#ifndef NONOGRAMMAP_H
#define NONOGRAMMAP_H

#include <vector>

	enum state{
		FILLED,
		EMPTY,
		BLANK
	};

class Nonogrammap
{

public:
	
	Nonogrammap(int mapHeight, int mapWidth);

	int getCount();
	int getHeight();
	int getWidth();

	std::vector<std::vector<int>> getLeftBorder();
	std::vector<std::vector<int>> getTopBorder();

	void printAnswer();
	

private:
	Nonogrammap(){};

	int coordinateCount;
	int height, width;
	int borderHeight, borderWidth;

	std::vector<std::vector<state>> column;
	std::vector<std::vector<int>> leftBorder;
	std::vector<std::vector<int>> topBorder;
};
#endif