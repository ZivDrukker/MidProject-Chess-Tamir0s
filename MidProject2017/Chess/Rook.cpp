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
	_board->printBoard();


	string toReturn = "";
	if ((instruction[0] == instruction[2] || instruction[1] == instruction[3]) && notBlocked(instruction))
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
bool Rook::notBlocked(string instruction)
{
	bool toReturn = true;
	int staticColOrRow = 0;
	int i = 0;

	int iCol = ((int)instruction[0] - A_ASCII), iRow = SIZE - 1 - ((int)instruction[1] - ZERO_ASCII - 1);
	int jCol = ((int)instruction[2] - A_ASCII), jRow = SIZE - 1 - ((int)instruction[3] - ZERO_ASCII - 1);

	if (instruction[0] == instruction[2])
	{
		staticColOrRow = iCol;
		for (i = min(iRow, jRow) + 1; i < max(iRow, jRow) && toReturn; i++)
		{
			(*this->_board)(i, staticColOrRow) != nullptr ? toReturn = false : toReturn = true;
		}
	}
	else
	{
		staticColOrRow = iRow;
		for (i = min(iCol, jCol) + 1; i < max(iCol, jCol) && toReturn; i++)
		{
			(*this->_board)(staticColOrRow, i) != nullptr ? toReturn = false : toReturn = true;
		}
	}

	return toReturn;
}


/*
Input: moving instrctions
Output: can the piece move there or not
function to check if a piece can make a certain move
*/
bool Rook::canEat(string instruction)
{
	if ((instruction[0] == instruction[2] || instruction[1] == instruction[3]) && notBlocked(instruction))
	{
		return true;
	}
	
	return false;
}