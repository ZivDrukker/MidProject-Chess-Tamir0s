//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include "Soldier.h"

class King : Soldier
{
private:
	bool checkChess(string instruction);

public:
	King(int color, Board* board);
	~King() = default;
	string move(string instruction);
};
