//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include <string>
#include <iostream>
#include "Soldier.h"

#define SIZE 8

using std::string;
using std::cout;
using std::cin;

class Soldier;

class Board
{
private:
	void setBoard(string str);

public:
	Soldier* _board[SIZE][SIZE];

	Board(string str);
	~Board();
	Soldier* getCell(string cell);
	void setCell(Soldier*);
	Soldier* operator=(Soldier*);
	Soldier* operator[](int x);
};
