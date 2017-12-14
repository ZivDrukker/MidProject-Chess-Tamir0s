//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include "Soldier.h"

class Rook : public Soldier
{
private:
	virtual int checkChess(string instruction);

public:
	Rook(int color, Board* board);
	~Rook() = default;
	virtual string move(string instruction);
	virtual bool notBlocked(string instruction);
};
