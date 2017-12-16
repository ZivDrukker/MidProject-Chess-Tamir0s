//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Pawn.h"


/*
Input: color to set user color and board
Output: NONE
c'tor function for King object
*/
Pawn::Pawn(int color, Board* board) : Soldier("Pawn", color, board), alreadyMoved(false)
{
}

/*
Input: instruction to move the piece
Output: NONE
function for moving the piece
*/
string Pawn::move(string instruction)
{
	string toReturn = "";
	int color = this->getColor();
	if(color == 0)
	{
		if (((instruction[0] == instruction[2]) && ((instruction[1] - instruction[3] == -1) || ((instruction[1] - instruction[3] == -2) && !alreadyMoved))) || canEat(instruction))
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

				toReturn = "0";

				toSet = "";
				toSet += instruction[0];
				toSet += instruction[1];
				_board->setCell(nullptr, toSet);
				alreadyMoved = true;
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
	}
	else
	{
		if (((instruction[0] == instruction[2]) && ((instruction[1] - instruction[3] == 1) || ((instruction[1] - instruction[3] == 2) && !alreadyMoved))) || canEat(instruction))
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

				toReturn = "0";

				toSet = "";
				toSet += instruction[0];
				toSet += instruction[1];
				_board->setCell(nullptr, toSet);
				alreadyMoved = true;
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
	}

	return toReturn;
}


/*
Input: instruction for the piece movement
Output: True if the piece is not blocked, else False
function to check if a piece's movement os blocked by a diffrent player
*/
bool Pawn::notBlocked(string instruction)
{
	return false;
}


/*
Input: moving instructions
Output: can the piece move or not
function to check if a pawn can eat in a given spot
*/
bool Pawn::canEat(string instruction)
{
	string newInstruction = "";
	newInstruction += instruction[2];
	newInstruction += instruction[3];
	if ((*this->_board).getCell(newInstruction))
	{
		if (abs(instruction[0] - instruction[2]) == 1)
		{
			if (instruction[1] - instruction[3] == 1 && this->getColor() == 1)
			{
				return true;
			}
			else if (instruction[1] - instruction[3] == -1 && this->getColor() == 0)
			{
				return true;
			}
		}
	}

	return false;
}