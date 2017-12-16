//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Queen.h"


/*
Input: color to set user color and board
Output: NONE
c'tor function for King object
*/
Queen::Queen(int color, Board* board) : Soldier("Queen", color, board)
{
}

/*
Input: instruction to move the piece
Output: NONE
function for moving the piece
*/
string Queen::move(string instruction)
{
	string toReturn = "";
	if ((abs(instruction[0] - instruction[2]) == abs(instruction[3] - instruction[1])) || (instruction[0] == instruction[2] || instruction[1] == instruction[3]))
	{
		toReturn = moveAll(instruction);
	}
	else
	{
		toReturn = "6";
	}

	return toReturn;
}


/*
Input: instruction for the piece movement
Output: True if the piece is not blocked, else False
function to check if a piece's movement os blocked by a diffrent player
*/
bool Queen::notBlocked(string instruction)
{
	return false;
}


/*
Input: moving instructions
Output: can the piece move or not
function to check 
*/
bool Queen::canEat(string instruction)
{
	if (abs(instruction[0] - instruction[2]) == abs(instruction[3] - instruction[1]))
	{
		return true;
	}

	return false;
}