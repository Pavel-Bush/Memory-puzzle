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

	SetColor(BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	DrawPlate(_x, _y);
	SetColor();

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
	//TO DO
	//Исправить проблему перемещения указателя,
	//если в его строке и столбце не осталось закрытых плиток
	switch (dir) {
	case Direction::UP:
		for (int i = _y - 1; i >= 0; i--) {
			if (!plates[_x][i].is_open()) {
				SetColor(BACKGROUND_INTENSITY );
				if(!plates[_x][_y].is_open())//если текщая плитка открыта, то ее не закрашивать 
				DrawPlate(_x, _y);
				_y = i;
				SetColor(BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
				DrawPlate(_x, _y);
				SetColor();
				break;
			}
		}
		break;
	case Direction::DOWN:
		for (int i = _y + 1; i < height; i++) {
			if (!plates[_x][i].is_open()) {
				SetColor(BACKGROUND_INTENSITY );
				if (!plates[_x][_y].is_open())
				DrawPlate(_x, _y);
				_y = i;
				SetColor(BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
				DrawPlate(_x, _y);
				SetColor();
				break;
			}
		}
		break;
	case Direction::LEFT:
		for (int i = _x - 1; i >= 0; i--) {
			if (!plates[i][_y].is_open()) {
				SetColor(BACKGROUND_INTENSITY );
				if (!plates[_x][_y].is_open())
				DrawPlate(_x, _y);
				_x = i;
				SetColor(BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
				DrawPlate(_x, _y);
				SetColor();
				break;
			}
		}
		break;
	case Direction::RIGHT:
		for (int i = _x + 1; i < width; i++) {
			if (!plates[i][_y].is_open()) {
				SetColor(BACKGROUND_INTENSITY );
				if (!plates[_x][_y].is_open())
				DrawPlate(_x, _y);
				_x = i;
				SetColor(BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
				DrawPlate(_x, _y);
				SetColor();
				break;
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
