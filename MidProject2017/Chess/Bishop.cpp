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

	if (abs(instruction[LETTER_1] - instruction[LETTER_2]) == abs(instruction[NUM_2] - instruction[NUM_1]) && notBlocked(instruction))
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
	int i = min(instruction[LETTER_1], instruction[LETTER_2]);
	int j = 0;
	i == instruction[LETTER_1] ? j = instruction[NUM_1] : j = instruction[NUM_2];
	if (j != min(instruction[NUM_1], instruction[NUM_2]))
	{
		for (i = i; i <= max(instruction[LETTER_1], instruction[LETTER_2]); i++, j--)
		{
			string toGet = "";
			toGet += i;
			toGet += j;

			string toGet2 = "";
			toGet2 += instruction[LETTER_2];
			toGet2 += instruction[NUM_2];

			if (_board->getCell(toGet) != nullptr && this != _board->getCell(toGet) && _board->getCell(toGet) != _board->getCell(toGet2))
			{
				return false;
			}
		}
	}
	else
	{
		for (i = i; i <= max(instruction[LETTER_1], instruction[LETTER_2]); i++, j++)
		{
			string toGet = "";
			toGet += i;
			toGet += j;

			string toGet2 = "";
			toGet2 += instruction[LETTER_2];
			toGet2 += instruction[NUM_2];

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
	if (abs(instruction[LETTER_1] - instruction[LETTER_2]) == abs(instruction[NUM_2] - instruction[NUM_1]) && notBlocked(instruction))
	{
		return true;
	}

	return false;
}