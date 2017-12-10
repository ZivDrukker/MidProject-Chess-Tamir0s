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
	if (instruction[0] == instruction[2] || instruction[1] == instruction[3])
	{
		if (!this->currPlayer(instruction))
		{
			string toSet = "";
			toSet += instruction[2];
			toSet += instruction[3];

			_board->setCell(this, toSet);

			this->checkChess(instruction) ? toReturn = "1" : toReturn = "0";

			toSet = "";
			toSet += instruction[0];
			toSet += instruction[1];
			_board->setCell(nullptr, toSet);
		}
		else
		{
			toReturn = "3";
		}
	}
	else
	{
		toReturn = "6";
	}

	return toReturn;
}


/*
Input: the place the piece was moved to
Output: NONE
function for checking if there is chess
*/
bool Rook::checkChess(string instruction)
{
	Soldier* temp = nullptr;
	Soldier* current = nullptr;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			current = _board->getCell(instruction);
			temp = (*this->_board)(i, j);

			if (temp->getType() == string("King") && temp->getColor() != current->getColor())
			{
				if (instruction[0] == instruction[2] || instruction[1] == instruction[3])
				{
					return true;
				}
			}
		}
	}
	return false;
}