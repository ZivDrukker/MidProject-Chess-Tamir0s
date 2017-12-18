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
	if ((instruction[LETTER_1] == instruction[LETTER_2] || instruction[NUM_1] == instruction[NUM_2]) && notBlocked(instruction))
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

	int iCol = ((int)instruction[LETTER_1] - A_ASCII), iRow = SIZE - 1 - ((int)instruction[NUM_1] - ZERO_ASCII - 1);
	int jCol = ((int)instruction[LETTER_2] - A_ASCII), jRow = SIZE - 1 - ((int)instruction[NUM_2] - ZERO_ASCII - 1);

	if (instruction[LETTER_1] == instruction[LETTER_2])
	{
		staticColOrRow = iCol;
		for (i = min(iRow, jRow); i <= max(iRow, jRow) && toReturn; i++)
		{
			string toGet2 = "";
			toGet2 += instruction[LETTER_2];
			toGet2 += instruction[NUM_2];

			(*this->_board)(i, staticColOrRow) != nullptr && this != (*this->_board)(i, staticColOrRow) && (*this->_board)(i, staticColOrRow) != _board->getCell(toGet2) ? toReturn = false : toReturn = true;
		}
	}
	else
	{
		staticColOrRow = iRow;
		for (i = min(iCol, jCol); i <= max(iCol, jCol) && toReturn; i++)
		{
			string toGet2 = "";
			toGet2 += instruction[LETTER_2];
			toGet2 += instruction[NUM_2];

			(*this->_board)(staticColOrRow, i) != nullptr && this != (*this->_board)(staticColOrRow, i) && (*this->_board)(i, staticColOrRow) != _board->getCell(toGet2) ? toReturn = false : toReturn = true;
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
	if ((instruction[LETTER_1] == instruction[LETTER_2] || instruction[NUM_1] == instruction[NUM_2]) && notBlocked(instruction))
	{
		return true;
	}
	
	return false;
}