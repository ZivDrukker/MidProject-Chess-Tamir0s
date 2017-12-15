//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include "Soldier.h"

class Queen : public Soldier
{
public:
	Queen(int color, Board* board);
	~Queen() = default;
	virtual string move(string instruction);
	virtual bool notBlocked(string instruction);
	virtual bool canMove(string instruction);
};
