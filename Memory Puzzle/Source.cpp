#include<iostream>
#include"Field.h"
#include<Windows.h>

using namespace std;

int main() {
	srand(time(NULL));

	bool programm_run = true;
	pair<int, int> first_plate = { -1, -1 };
	pair<int, int> second_plate = { -1, -1 };
	HideCursor();
	Field f;
	f.CreateField();
	f.ShowField();
	f.OpenField();
	this_thread::sleep_for(chrono::milliseconds(5000));
	f.CloseField();

	while (programm_run) {

		switch (_getch()) {
		case 72://up
			f.MovePtr(Direction::UP);
			break;
		case 80://down
			f.MovePtr(Direction::DOWN);
			break;
		case 75://left
			f.MovePtr(Direction::LEFT);
			break;
		case 77://right
			f.MovePtr(Direction::RIGHT);
			break;
		case 27://escape
			programm_run = false;
			break;

		case 13://enter
		case 32://space 
			f.OpenPlate();
			//TO DO
			//реализовать автоматическое закрытые двух плиток
			//при их не совпадении
			break;
		}
	}
	
	system("cls");
	return 0;
}