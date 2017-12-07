//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include <string>
#include <iostream>
#include "Board.h"

using std::string;
using std::cout;
using std::cin;

class Board;

class Soldier 
{
protected:
	string _type;
	int _color;
	Board* _board;

public:
	Soldier(string type, int color, Board* board);
	~Soldier() = default;
	virtual string move(string instructions) = 0;
	string getType();
	int getColor();
};