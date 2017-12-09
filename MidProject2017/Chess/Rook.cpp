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
	string toReturn = "";
	string placeInBoard = _board->getXandY(this);
	if (instruction[0] == placeInBoard[0] && instruction[1] != placeInBoard[1] || instruction[1] == placeInBoard[1] && instruction[0] != placeInBoard[0])
	{
		_board->setCell(this, instruction);
		if (checkChess(instruction))
		{
			toReturn = "1";
		}
		else
		{
			toReturn = "2";
		}
	}
	else
	{
		toReturn = "6";
	}

	return toReturn;
}


/*
Input: instruction to move the piece
Output: NONE
function for checking if there is chess
*/
bool Rook::checkChess(string instruction)
{
	string xAndy = "";
	string xAndyTemp = "";
	Soldier* temp = NULL;
	Soldier* current = NULL;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; i++)
		{
			current = _board->getCell(instruction);
			temp = (*this->_board)(i, j);
			if (temp->getType() == string("King") && temp->getColor() != current->getColor())
			{
				xAndyTemp = _board->getXandY(temp);
				xAndy = _board->getXandY(current);
				if (xAndy[0] == xAndyTemp[0] || xAndy[1] == xAndyTemp[1])
				{
					return true;
				}
			}
		}
	}
	return false;
}