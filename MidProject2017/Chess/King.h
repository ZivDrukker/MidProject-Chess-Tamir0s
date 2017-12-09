//Tam!r0s & Z!v0s @ Chess-MidProject
#pragma once

#include "Soldier.h"

class King : Soldier
{
	King(int color);
	~King() = default;
	string move(string instruction);
};
