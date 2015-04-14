#ifndef NONOGRAMMAP_H
#define NONOGRAMMAP_H

#include <vector>

	enum state{
		FILLED,
		EMPTY,
		UNKNOWN
	};

class Nonogrammap
{

public:
	
	Nonogrammap(int mapHeight, int mapWidth);

	int getCount();
	int getHeight();
	int getWidth();
	int getBorderWidth(){
		return borderWidth;
	}
	int getBorderHeight(){
		return borderHeight;
	}

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