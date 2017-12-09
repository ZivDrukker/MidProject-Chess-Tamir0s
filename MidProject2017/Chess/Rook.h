//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include "Soldier.h"

class Rook : Soldier
{
	Rook(int color, Board* board);
	~Rook() = default;
	string move(string instruction);
};
