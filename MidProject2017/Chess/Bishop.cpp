//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Bishop.h"


/*
Input: color to set user color and board
Output: NONE
c'tor function for King object
*/
Bishop::Bishop(int color, Board* board) : Soldier("Queen", color, board)
{
}

/*
Input: instruction to move the piece
Output: NONE
function for moving the piece
*/
string Bishop::move(string instruction)
{
	string toReturn = "";

	if (abs(instruction[0] - instruction[2]) ==  abs(instruction[3] - instruction[1]) && (instruction[0] != instruction[2] || instruction[1] != instruction[3]))
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
Input: instruction for the piece movement
Output: True if the piece is not blocked, else False
function to check if a piece's movement os blocked by a diffrent player
*/
bool Bishop::notBlocked(string instruction)
{
	return false;
}


/*
Input: moving instructions
Output: can the piece move or not
function to check 
*/
bool Bishop::canMove(string instruction)
{
	if (abs(instruction[0] - instruction[2]) == abs(instruction[3] - instruction[1]) && (instruction[0] != instruction[2] || instruction[1] != instruction[3]))
	{
		return true;
	}

	return false;
}