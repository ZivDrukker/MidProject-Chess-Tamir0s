//Tam!r0s & Z!v0s @ Chess-MidProject

#pragma once

#include "Soldier.h"

#define FIRST_MOVE_LEN 2


class Pawn : public Soldier
{
private:
	bool _alreadyMoved;

public:
	Pawn(int color, Board* board);
	~Pawn() = default;
	virtual string move(string instruction);
	virtual bool notBlocked(string instruction);
	virtual bool canEat(string instruction);
};
