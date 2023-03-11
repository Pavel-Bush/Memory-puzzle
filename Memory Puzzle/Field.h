#pragma once
#include "Plate.h"
#include<list>
#include<vector>
#include"func.h"

enum Direction {
	LEFT, RIGHT, UP, DOWN
};

class Field
{
private:
	static const int height = 4, width = 8;
	Plate plates[width][height];
	std::vector<std::pair<int, int>> free_coord = {
	{0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7},
	{1,0}, {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7},
	{2,0}, {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, {2,6}, {2,7},
	{3,0}, {3,1}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6}, {3,7} };
	int _x = 0, _y = 0;

	void DrawPlate(int x, int y);
	void DrawCircle(int x, int y, Color clr);
	void DrawTriangle(int x, int y, Color clr);
	void DrawSquare(int x, int y, Color clr);
	void DrawCross(int x, int y, Color clr);

public:
	void CreateField();
	void ShowField();
	void MovePtr(Direction dir);
	bool OpenPlate();
	bool ClosePlate(int x, int y);
};

