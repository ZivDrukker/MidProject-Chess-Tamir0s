//Tam!r0s & Z!v0s @ Chess-MidProject

#pragma once

#include <string>
#include <iostream>
#include "Board.h"
#include <algorithm>

#define LETTER_1 0
#define NUM_1 1
#define LETTER_2 2
#define NUM_2 3

#define BLACK_COLOR 1
#define WHITE_COLOR 0

using std::min;
using std::max;
using std::string;
using std::cout;

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
	bool checkEnemyChess();
	bool checkSelfChess();
	bool currPlayer(string instruction);
	string moveAll(string instruction);
	virtual bool notBlocked(string instruction) = 0;
	virtual bool canEat(string instruction) = 0;
};