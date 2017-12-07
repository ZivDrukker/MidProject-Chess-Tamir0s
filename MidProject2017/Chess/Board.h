//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include <string>
#include <iostream>
#include "Soldier.h"

#define SIZE 8
#define A_ASCII 97
#define ONE_ASCII 49

#define NULL_PIECE '#'
#define KING_BLACK 'k'
#define QUEEN_BLACK 'q'
#define BISHOP_BLACK 'b'
#define ROOK_BLACK 'r'
#define KNIGHT_BLACK 'n'
#define PAWN_BLACK 'p'
#define KING_WHITE 'K'
#define QUEEN_WHITE 'Q'
#define BISHOP_WHITE 'B'
#define ROOK_WHITE 'R'
#define KNIGHT_WHITE 'N'
#define PAWN_WHITE 'P'

using std::string;
using std::cout;
using std::cin;

class Soldier;

class Board
{
private:
	void setBoard(string str);

public:
	Soldier*** _gameBoard;

	Board(string str);
	~Board();
	Soldier* getCell(string cell);
	void setCell(Soldier* piece, string cell);
	Soldier* operator()(int x, int y);
};
