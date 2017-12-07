//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Soldier.h"


/*
Input:NONE
Output: NONE
c'tor function for Soldier object
*/
Soldier::Soldier(string type, int color, Board* board) : _type(type), _color(color), _board(board)
{
}



/*
Input: NONE
Output: string _type
getter function for _type value
*/
string Soldier::getType()
{
	return _type;
}


/*
Input: NONE
Output: int _color
getter function for _color value
*/
int Soldier::getColor()
{
	return _color;
}