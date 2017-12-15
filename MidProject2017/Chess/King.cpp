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
	if (abs(instruction[0] - instruction[2]) == 1 || abs(instruction[3] - instruction[1]) == 1)
	{

		if (!this->currPlayer(instruction))
		{
			string toSet = "";
			toSet += instruction[2];
			toSet += instruction[3];

			Soldier* tempCell = _board->setCell(this, toSet);

			string toSetNull = "";
			toSetNull = "";
			toSetNull += instruction[0];
			toSetNull += instruction[1];
			_board->setCell(nullptr, toSet);

			if (!this->checkSelfChess())
			{
				if (tempCell != nullptr)
				{
					delete tempCell;
				}
				this->checkEnemyChess() == true ? toReturn = "1" : toReturn = "0";;
			}
			else
			{
				_board->setCell(this, toSetNull);
				_board->setCell(tempCell, toSet);
				toReturn = "4";
			}

		}
		else
		{
			toReturn = "3";
		}
		/*
		if (!this->currPlayer(instruction))
		{
			if (checkChess() >= 0)
			{
				string toSet = "";
				toSet += instruction[2];
				toSet += instruction[3];

				Soldier* tempCell = _board->setCell(this, toSet);
				if (tempCell != nullptr)
				{
					delete tempCell;
				}

				checkChess() == 1 ? toReturn = "1" : toReturn = "0";

				toSet = "";
				toSet += instruction[0];
				toSet += instruction[1];
				_board->setCell(nullptr, toSet);
			}
			else
			{
				toReturn = "4";
			}
		}
		else
		{
			toReturn = "3";
		}
		*/
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
bool King::notBlocked(string instruction)
{
	return false;
}


/*
Input: moving instructions
Output: can the piece move or not
function to check 
*/
bool King::canMove(string instruction)
{
	if (abs(instruction[0] - instruction[2]) == 1 || abs(instruction[3] - instruction[1]) == 1)
	{
		return true;
	}

	return false;
}