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
	bool toReturn = true;
	int staticColOrRow = 0;
	int i = 0, j = 0;

	int iCol = ((int)instruction[0] - A_ASCII), iRow = SIZE - 1 - ((int)instruction[1] - ZERO_ASCII - 1);
	int jCol = ((int)instruction[2] - A_ASCII), jRow = SIZE - 1 - ((int)instruction[3] - ZERO_ASCII - 1);

	//rook like check
	if (instruction[0] == instruction[2])
	{
		staticColOrRow = iCol;
		for (i = min(iRow, jRow) + 1; i < max(iRow, jRow) && toReturn; i++)
		{
			(*this->_board)(i, staticColOrRow) ? toReturn = false : toReturn = true;
		}
	}
	else
	{
		staticColOrRow = iRow;
		for (i = min(iCol, jCol) + 1; i < max(iCol, jCol) && toReturn; i++)
		{
			(*this->_board)(staticColOrRow, i) ? toReturn = false : toReturn = true;
		}
	}

	//bishop like check
	for (i = min(jRow, iRow), j = min(iCol, jCol); i < max(jRow, iRow) && j < max(jCol, iCol) && toReturn; i++, j++)
	{
		(*this->_board)(i, j) ? toReturn = false : toReturn = true;
	}

	return toReturn;
}


/*
Input: moving instructions
Output: can the piece move or not
function to check 
*/
bool Queen::canEat(string instruction)
{
	if (((abs(instruction[0] - instruction[2]) == abs(instruction[3] - instruction[1])) || (instruction[0] == instruction[2] || instruction[1] == instruction[3])) && notBlocked(instruction))
	{
		return true;
	}

	return false;
}