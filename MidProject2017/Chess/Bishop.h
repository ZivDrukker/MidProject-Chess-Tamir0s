//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include "Soldier.h"

class Bishop : public Soldier
{
public:
	Bishop(int color, Board* board);
	~Bishop() = default;
	virtual string move(string instruction);
	virtual bool notBlocked(string instruction);
	virtual bool canMove(string instruction);
};
