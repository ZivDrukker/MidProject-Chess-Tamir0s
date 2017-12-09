//Tam!r0s & Z!v0s @ Chess-MidProject

#include "King.h"


/*
Input: color to set user color and board
Output: NONE
c'tor function for King object
*/
King::King(int color, Board* board) : Soldier("King", color, board)
{
}

/*
Input: instruction to move the piece
Output: NONE
function for moving the piece
*/
string King::move(string instruction)
{
	string toReturn = "";
	string placeInBoard = _board->getXandY(this);
	if (instruction[0] - placeInBoard[0] <= 1 && instruction[0] - placeInBoard[0] >= -1 && instruction[1] - placeInBoard[1] <= 1 && instruction[1] - placeInBoard[1] >= -1)
	{
		_board->setCell(this, instruction);
		toReturn = "2";
	}
	else
	{
		toReturn = "6";
	}
	return toReturn;
}
