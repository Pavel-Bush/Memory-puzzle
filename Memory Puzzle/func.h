#pragma once

#include<ctime>
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Field.h"
#include<thread>
#include<chrono>

int Random(int min, int max);

void gotoxy(short int x, short int y);

void HideCursor();

void SetColor(WORD color = 7);