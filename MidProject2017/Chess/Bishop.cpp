//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Bishop.h"


/*
Input: color to set user color and board
Output: NONE
c'tor function for King object
*/
Bishop::Bishop(int color, Board* board) : Soldier("Bishop", color, board)
{
}

/*
Input: instruction to move the piece
Output: NONE
function for moving the piece
*/
string Bishop::move(string instruction)
{
	string toReturn = "";

	if ((abs(instruction[0] - instruction[2]) == abs(instruction[3] - instruction[1]) && (instruction[0] != instruction[2] || instruction[1] != instruction[3])) && notBlocked(instruction))
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
bool Bishop::notBlocked(string instruction)
{
	for (int i = min(instruction[0], instruction[2]), j = min(instruction[1], instruction[3]); i < max(instruction[0], instruction[2]); i++, j++)
	{
		string toGet = "";
		toGet += i;
		toGet += j;
		if (_board->getCell(toGet) != nullptr)
		{
			return false;
		}
	}

	return true;
}


/*
Input: moving instructions
Output: can the piece move or not
function to check 
*/
bool Bishop::canEat(string instruction)
{
	if (abs(instruction[0] - instruction[2]) == abs(instruction[3] - instruction[1]) && (instruction[0] != instruction[2] || instruction[1] != instruction[3]))
	{
		return true;
	}

	return false;
}