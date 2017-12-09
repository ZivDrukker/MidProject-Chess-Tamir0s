//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Rook.h"


/*
Input: color to set user color and board
Output: NONE
c'tor function for Rook object
*/
Rook::Rook(int color, Board* board) : Soldier("Rook", color, board)
{
}

/*
Input: instruction to move the piece
Output: NONE
function for moving the piece
*/
string Rook::move(string instruction)
{
	string placeInBoard = _board->getXandY(this);
	if (instruction[0] == placeInBoard[0] && instruction[1] != placeInBoard[1] || instruction[1] == placeInBoard[1] && instruction[0] != placeInBoard[0])
	{
		_board->setCell(this, instruction);
	}
}