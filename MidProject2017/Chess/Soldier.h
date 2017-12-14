//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include <string>
#include <iostream>
#include "Board.h"
#include <algorithm>

using std::min;
using std::max;
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
	int checkChess();
	bool currPlayer(string instruction);
	virtual bool notBlocked(string instruction) = 0;
	virtual bool canMove(string instruction) = 0;
};