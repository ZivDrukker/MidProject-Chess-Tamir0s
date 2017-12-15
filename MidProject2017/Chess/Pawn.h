//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include "Soldier.h"

class Pawn : public Soldier
{
private:
	bool alreadyMoved;

public:
	Pawn(int color, Board* board);
	~Pawn() = default;
	virtual string move(string instruction);
	virtual bool notBlocked(string instruction);
	virtual bool canEat(string instruction);
};
