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
	system("mode con cols=112 lines=30");
	Field f;
	f.CreateField();
	f.ShowField();
	f.OpenField();
	this_thread::sleep_for(chrono::milliseconds(5000));
	f.CloseField();

	//TO DO
	//сделать возможность выбора плиток мышью

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
			if (first_plate.first == -1)
				first_plate = f.GetPos();
			else second_plate = f.GetPos();

			if (second_plate.first != -1) {
				if (!f.compair(first_plate, second_plate)) {
					thread th(
						[first_plate, second_plate, &f]() {
							this_thread::sleep_for(chrono::milliseconds(1000));
							f.ClosePlate(first_plate.first, first_plate.second);
							f.ClosePlate(second_plate.first, second_plate.second); });
					th.detach();
				}
				
				first_plate = { -1, -1 };
				second_plate = { -1, -1 };
			}

			break;
		}
	}
	
	std::system("cls");
	return 0;
}