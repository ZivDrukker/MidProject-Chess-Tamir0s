//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Bishop.h"


/*
Input: color to set user color and board
Output: NONE
c'tor function for King object
*/
Bishop::Bishop(int color, Board* board) : Soldier("Bishop", color, board)
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

	if (abs(instruction[0] - instruction[2]) == abs(instruction[3] - instruction[1]) && notBlocked(instruction))
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
bool Bishop::notBlocked(string instruction)
{
	int i = min(instruction[0], instruction[2]);
	int j = 0;
	i == instruction[0] ? j = instruction[1] : j = instruction[3];
	if (j != min(instruction[1], instruction[3]))
	{
		for (i = i; i < max(instruction[0], instruction[2]); i++, j--)
		{
			string toGet = "";
			toGet += i;
			toGet += j;

			string toGet2 = "";
			toGet2 += instruction[2];
			toGet2 += instruction[3];
			if (_board->getCell(toGet) != nullptr && this != _board->getCell(toGet) && _board->getCell(toGet) != _board->getCell(toGet2))
			{
				return false;
			}
		}
	}
	else
	{
		for (i = i; i < max(instruction[0], instruction[2]); i++, j++)
		{
			string toGet = "";
			toGet += i;
			toGet += j;

			string toGet2 = "";
			toGet2 += instruction[2];
			toGet2 += instruction[3];

			if (_board->getCell(toGet) != nullptr && this != _board->getCell(toGet) && _board->getCell(toGet) != _board->getCell(toGet2))
			{
				return false;
			}
		}
	}

	return true;
}


/*
Input: moving instructions
Output: can the piece move or not
function to check 
*/
bool Bishop::canEat(string instruction)
{
	if (abs(instruction[0] - instruction[2]) == abs(instruction[3] - instruction[1]) && notBlocked(instruction))
	{
		return true;
	}

	return false;
}