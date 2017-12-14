//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include "Soldier.h"

class King : public Soldier
{
public:
	King(int color, Board* board);
	~King() = default;
	virtual string move(string instruction);
	virtual bool notBlocked(string instruction);
	virtual bool canMove(string instruction);
};
