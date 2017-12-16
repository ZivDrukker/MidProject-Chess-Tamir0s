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
	int i = min((int)instruction[0] - A_ASCII, (int)instruction[2] - A_ASCII), j = min(SIZE - 1 - ((int)instruction[1] - ZERO_ASCII - 1), SIZE - 1 - ((int)instruction[3] - ZERO_ASCII - 1));
	int finalI = max((int)instruction[0] - A_ASCII, (int)instruction[2] - A_ASCII), finalJ = max(SIZE - 1 - ((int)instruction[1] - ZERO_ASCII - 1), SIZE - 1 - ((int)instruction[3] - ZERO_ASCII - 1));
	
	for (i = i , j = j; i < finalI && j < finalJ; i++, j++)
	{
		if ((*this->_board)(j, i))
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