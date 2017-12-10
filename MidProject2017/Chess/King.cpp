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
	if ((instruction[0] - instruction[2] == 1 || instruction[0] - instruction[2] == -1) || (instruction[3] - instruction[1] == 1 || instruction[3] - instruction[1] == -1))
	{
		if (!this->currPlayer(instruction))
		{
			string toSet = "";
			toSet += instruction[2];
			toSet += instruction[3];

			_board->setCell(this, toSet);
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
Input: the moving instruction for the piece
Output: True if there is a chess, else False
function to check the board for a chess
*/
bool King::checkChess(string instruction)
{
	return false;//TODO: build the func
}