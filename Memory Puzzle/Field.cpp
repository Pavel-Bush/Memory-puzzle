#include "Field.h"

const int num_clr = 4;
Color arr_clr[num_clr] = { RED, BLUE, GREEN, MAGENTA };
const int num_shp = 4;
Shape arr_shp[num_shp] = { TRIANGLE, CIRCLE, SQUARE, CROSS};

void Field::CreateField()
{
	std::pair<int, int> coord;
	std::vector<std::pair<int, int>>::iterator it;
	for (int i = 0; i < num_clr; i++) {
		for (int j = 0; j < num_shp && free_coord.size() > 0; j++) {
			it = free_coord.begin() + Random(0, free_coord.size() - 1);
			coord = *it;
			free_coord.erase(it);
			plates[coord.second][coord.first].SetAttributes(arr_clr[i], arr_shp[j]);
			//
			it = free_coord.begin() + Random(0, free_coord.size() - 1);
			coord = *it;
			free_coord.erase(it);
			plates[coord.second][coord.first].SetAttributes(arr_clr[i], arr_shp[j]);
		}

	}

}

void Field::ShowField()
{
	for (int k = 0; k < 29; k++) {
		char ch = (k == 0 || k == 28) ? '-' : ' ';
		std::cout << ((ch == ' ') ? '|' : '@');
		
		for (int l = 0; l < 106; l++) {
			std::cout << ch;
		}
		std::cout << ((ch == ' ') ? '|' : '@');
		std::cout << std::endl;
	}
	
	SetColor(BACKGROUND_INTENSITY);
	for (int i = 0; i < width; i++) 
		for (int j = 0; j < height; j++) 
			DrawPlate(i, j);

	DrawPlate(_x, _y, BG_WHITE);

}

void Field::DrawPlate(int x, int y)
{
	gotoxy(x * 13 + 3, y * 7 + 1);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 2);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 3);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 4);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 5);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 6);
	std::cout << "           ";
}

void Field::DrawPlate(int x, int y, Color clr)
{
	SetColor(clr);
	gotoxy(x * 13 + 3, y * 7 + 1);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 2);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 3);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 4);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 5);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 6);
	std::cout << "           ";
	SetColor();
}

void Field::DrawCircle(int x, int y, Color clr)
{
	SetColor(clr);
	gotoxy(x * 13 + 3, y * 7 + 1);
	std::cout << "   OOOOO   ";
	gotoxy(x * 13 + 3, y * 7 + 2);
	std::cout << " OOOOOOOOO ";
	gotoxy(x * 13 + 3, y * 7 + 3);
	std::cout << "OOOOOOOOOOO";
	gotoxy(x * 13 + 3, y * 7 + 4);
	std::cout << "OOOOOOOOOOO";
	gotoxy(x * 13 + 3, y * 7 + 5);
	std::cout << " OOOOOOOOO ";
	gotoxy(x * 13 + 3, y * 7 + 6);
	std::cout << "   OOOOO   ";
	SetColor();
}

void Field::DrawTriangle(int x, int y, Color clr)
{
	SetColor(clr);
	gotoxy(x * 13 + 3, y * 7 + 1);
	std::cout << "     A     ";
	gotoxy(x * 13 + 3, y * 7 + 2);
	std::cout << "    AAA    ";
	gotoxy(x * 13 + 3, y * 7 + 3);
	std::cout << "   AAAAA   ";
	gotoxy(x * 13 + 3, y * 7 + 4);
	std::cout << "  AAAAAAA  ";
	gotoxy(x * 13 + 3, y * 7 + 5);
	std::cout << " AAAAAAAAA ";
	gotoxy(x * 13 + 3, y * 7 + 6);
	std::cout << "AAAAAAAAAAA";
	SetColor();
}

void Field::DrawSquare(int x, int y, Color clr)
{
	SetColor(clr);
	gotoxy(x * 13 + 3, y * 7 + 1);
	std::cout << "           ";
	gotoxy(x * 13 + 3, y * 7 + 2);
	std::cout << " ######### ";
	gotoxy(x * 13 + 3, y * 7 + 3);
	std::cout << " ######### ";
	gotoxy(x * 13 + 3, y * 7 + 4);
	std::cout << " ######### ";
	gotoxy(x * 13 + 3, y * 7 + 5);
	std::cout << " ######### ";
	gotoxy(x * 13 + 3, y * 7 + 6);
	std::cout << " ######### ";
	SetColor();
}

void Field::DrawCross(int x, int y, Color clr)
{
	SetColor(clr);
	gotoxy(x * 13 + 3, y * 7 + 1);
	std::cout << "XX       XX";
	gotoxy(x * 13 + 3, y * 7 + 2);
	std::cout << "  XX   XX  ";
	gotoxy(x * 13 + 3, y * 7 + 3);
	std::cout << "    XXX    ";
	gotoxy(x * 13 + 3, y * 7 + 4);
	std::cout << "    XXX    ";
	gotoxy(x * 13 + 3, y * 7 + 5);
	std::cout << "  XX   XX  ";
	gotoxy(x * 13 + 3, y * 7 + 6);
	std::cout << "XX       XX";
	SetColor();
}

void Field::MovePtr(Direction dir)
{
	switch (dir) {
	case Direction::UP:
		for (int j = 0; j <= max(width - _x - 1, _x); j++) {// цикл на случай, если нету доступной плитки в данном столбце
			for (int i = _y - 1; i >= 0; i--) {
				if ((_x + j < width) && !plates[_x + j][i].is_open()) {
					if (!plates[_x][_y].is_open())//если текщая плитка открыта, то ее не закрашивать 
						DrawPlate(_x, _y, BG_GRAY);
					_y = i;
					_x = _x + j;
					DrawPlate(_x, _y, BG_WHITE);
					return;
				}
				else if ((_x - j >= 0) && !plates[_x - j][i].is_open()) {
					if (!plates[_x][_y].is_open())//если текщая плитка открыта, то ее не закрашивать 
						DrawPlate(_x, _y, BG_GRAY);
					_y = i;
					_x = _x - j;
					DrawPlate(_x, _y, BG_WHITE);
					return;
				}
			}
		}
		break;
	case Direction::DOWN:
		for (int j = 0; j <= max(width - _x - 1, _x); j++) {
			for (int i = _y + 1; i < height; i++) {

				if ((_x + j < width) && !plates[_x + j][i].is_open()) {
					if (!plates[_x][_y].is_open())
						DrawPlate(_x, _y, BG_GRAY);
					_y = i;
					_x = _x + j;
					DrawPlate(_x, _y, BG_WHITE);
					return;
				}
				else if ((_x - j >= 0) && !plates[_x - j][i].is_open()) {
					if (!plates[_x][_y].is_open())
						DrawPlate(_x, _y, BG_GRAY);
					_y = i;
					_x = _x - j;
					DrawPlate(_x, _y, BG_WHITE);
					return;
				}
			}
		}
		break;
	case Direction::LEFT:
		for (int j = 0; j <= max(height - _y - 1, _y); j++){
			for (int i = _x - 1; i >= 0; i--) {
				if ((_y + j < height) && !plates[i][_y + j].is_open()) {
					if (!plates[_x][_y].is_open())
						DrawPlate(_x, _y, BG_GRAY);
					_x = i;
					_y = _y + j;
					DrawPlate(_x, _y, BG_WHITE);
					return;
				}
				else if ((_y - j >= 0) && !plates[i][_y - j].is_open()) {
					if (!plates[_x][_y].is_open())
						DrawPlate(_x, _y, BG_GRAY);
					_x = i;
					_y = _y - j;
					DrawPlate(_x, _y, BG_WHITE);
					return;
				}
			}
		}
		break;
	case Direction::RIGHT:
		for (int j = 0; j <= max(height - _y - 1, _y); j++) {
			for (int i = _x + 1; i < width; i++) {
				if ((_y + j < height) && !plates[i][_y + j].is_open()) {
					if (!plates[_x][_y].is_open())
						DrawPlate(_x, _y, BG_GRAY);
					_x = i;
					_y = _y + j;
					DrawPlate(_x, _y, BG_WHITE);
					return;
				}
				else if ((_y - j >= 0) && !plates[i][_y - j].is_open()) {
					if (!plates[_x][_y].is_open())
						DrawPlate(_x, _y, BG_GRAY);
					_x = i;
					_y = _y - j;
					DrawPlate(_x, _y, BG_WHITE);
					return;
				}
			}
		}
		break;
	}
}

bool Field::OpenPlate()
{
	if (!plates[_x][_y].is_open()) {
		plates[_x][_y].FlipOver();
		switch (plates[_x][_y].GetShape()) {
		case CIRCLE: 
			DrawCircle(_x, _y, plates[_x][_y].GetColor());
			break;
		case SQUARE:
			DrawSquare(_x, _y, plates[_x][_y].GetColor());
			break;
		case TRIANGLE:
			DrawTriangle(_x, _y, plates[_x][_y].GetColor());
			break;
		case CROSS:
			DrawCross(_x, _y, plates[_x][_y].GetColor());
			break;
	
		}
		return true;
	}
	return false;
}
