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
	if ((instruction[0] == instruction[2] || instruction[1] == instruction[3]) && notBlocked(instruction)) // && notBlocked(instruction)
	{
		if (!this->currPlayer(instruction))
		{
			string toSet = "";
			toSet += instruction[2];
			toSet += instruction[3];

			Soldier* tempCell = _board->setCell(this, toSet);
			if (tempCell != nullptr)
			{
				delete tempCell;
			}
			toSet = "";
			toSet += instruction[0];
			toSet += instruction[1];
			_board->setCell(nullptr, toSet);

			this->checkChess(instruction) ? toReturn = "1" : toReturn = "0";
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
Output: -1 if move will make chess on you, 0 if no chess, 1 if move will make chess on enemy
function for checking if there is chess
*/
int Rook::checkChess(string instruction)
{
	Soldier* temp = nullptr;
	Soldier* current = nullptr;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			current = _board->getCell(instruction);
			temp = (*this->_board)(i, j);
			if (current && temp)
			{
				if (temp->getType() == string("King") && temp->getColor() != current->getColor())
				{
					if (instruction[0] == instruction[2] || instruction[1] == instruction[3])
					{
						return true;
					}
				}
			}
		}
	}
	return false;
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
	int iCol = ((int)instruction[0] - A_ASCII), iRow = abs((int)instruction[1] - ZERO_ASCII - 1);
	int jCol = ((int)instruction[2] - A_ASCII), jRow = abs((int)instruction[3] - ZERO_ASCII - 1);

	if (instruction[0] == instruction[2])
	{
		staticColOrRow = iCol;
		for (i = min(iRow, jRow) + 1; i < max(iRow, jRow) && toReturn; i++)//normal min didn't work
		{
			(*this->_board)(i, staticColOrRow) ? toReturn = false : toReturn = true;
		}
	}
	else
	{
		staticColOrRow = iRow;
		for (i = min(iCol, jCol) + 1; i < max(iCol, jCol) && toReturn; i++)//normal min didn't work
		{
			(*this->_board)(staticColOrRow, i) ? toReturn = false : toReturn = true;
		}
	}

	return toReturn;
}