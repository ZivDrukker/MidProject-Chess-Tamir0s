//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include "Soldier.h"

class Rook : Soldier
{
private:
	bool checkChess(string instruction);

public:
	Rook(int color, Board* board);
	~Rook() = default;
	string move(string instruction);
};
