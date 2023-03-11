#pragma once

enum Color {
	nullclr, RED = 4, BLUE = 1, GREEN = 2, MAGENTA = 5, BG_WHITE = 240, BG_GRAY = 128
};

enum Shape {
	nullshp, TRIANGLE, CIRCLE, SQUARE, CROSS
};


class Plate{
private:
	Color color;
	Shape shape;
	bool state = 0;
public: 
	Plate();
	void SetAttributes(Color clr, Shape shp);
	bool is_open();
	void FlipOver();
	Shape GetShape();
	Color GetColor();
};

