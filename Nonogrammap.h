#ifndef NONOGRAMMAP_H
#define NONOGRAMMAP_H

#include <vector>


class Nonogrammap
{
	enum state{
		FILLED,
		EMPTY,
		BLANK
	};

	struct coordinate
	{
		state state;
		unsigned int x, y;
	};

public:
	
	Nonogrammap(unsigned int mapHeight, unsigned int mapWidth);
	~Nonogrammap();

	unsigned int getCount();
	unsigned int getHeight();
	unsigned int getWidth();

	void clearMap();
	void print();
	

private:
	Nonogrammap(){};

	unsigned int coordinateCount;
	unsigned int height, width;

	std::vector<coordinate*> coordinates;

	std::vector<std::vector<state>> column;
};
#endif