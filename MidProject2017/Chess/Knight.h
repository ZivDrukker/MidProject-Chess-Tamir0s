//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include "Soldier.h"

class Knight : public Soldier
{
public:
	Knight(int color, Board* board);
	~Knight() = default;
	virtual string move(string instruction);
	virtual bool notBlocked(string instruction);
	virtual bool canEat(string instruction);
};
