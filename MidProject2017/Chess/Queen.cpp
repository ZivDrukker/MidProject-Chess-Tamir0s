//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Queen.h"


/*
Input: color to set user color and board
Output: NONE
c'tor function for King object
*/
Queen::Queen(int color, Board* board) : Soldier("Queen", color, board)
{
}

/*
Input: instruction to move the piece
Output: NONE
function for moving the piece
*/
string Queen::move(string instruction)
{
	string toReturn = "";
	if (((abs(instruction[LETTER_1] - instruction[LETTER_2]) == abs(instruction[NUM_2] - instruction[NUM_1])) || (instruction[LETTER_1] == instruction[LETTER_2] || instruction[NUM_1] == instruction[NUM_2])) && notBlocked(instruction))
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
bool Queen::notBlocked(string instruction)
{
	bool toReturn = true;
	int staticColOrRow = 0;
	int i = 0, j = 0;

	int iCol = ((int)instruction[LETTER_1] - A_ASCII), iRow = SIZE - 1 - ((int)instruction[NUM_1] - ZERO_ASCII - 1);
	int jCol = ((int)instruction[LETTER_2] - A_ASCII), jRow = SIZE - 1 - ((int)instruction[NUM_2] - ZERO_ASCII - 1);

	//rook like check
	if (instruction[LETTER_1] == instruction[LETTER_2] || instruction[NUM_1] == instruction[NUM_2])
	{
		if (instruction[LETTER_1] == instruction[LETTER_2])
		{
			staticColOrRow = iCol;

			string toGet2 = "";
			toGet2 += instruction[LETTER_2];
			toGet2 += instruction[NUM_2];

			for (i = min(iRow, jRow); i < max(iRow, jRow) && toReturn; i++)
			{
				(*this->_board)(i, staticColOrRow) != nullptr && this != (*this->_board)(i, staticColOrRow) && (*this->_board)(i, staticColOrRow) != _board->getCell(toGet2) ? toReturn = false : toReturn = true;
			}
		}
		else
		{
			staticColOrRow = iRow;
			
			string toGet2 = "";
			toGet2 += instruction[LETTER_2];
			toGet2 += instruction[NUM_2];

			for (i = min(iCol, jCol); i < max(iCol, jCol) && toReturn; i++)
			{
				(*this->_board)(staticColOrRow, i) != nullptr && this != (*this->_board)(staticColOrRow, i) && (*this->_board)(i, staticColOrRow) != _board->getCell(toGet2) ? toReturn = false : toReturn = true;
			}
		}
	}
	else
	{
		//bishop like check
		i = min(instruction[LETTER_1], instruction[LETTER_2]);
		j = 0;
		i == instruction[LETTER_1] ? j = instruction[NUM_1] : j = instruction[NUM_2];
		if (j != min(instruction[NUM_1], instruction[NUM_2]))
		{
			for (i = i; i < max(instruction[LETTER_1], instruction[LETTER_2]) && toReturn; i++, j--)
			{
				string toGet = "";
				toGet += i;
				toGet += j;

				string toGet2 = "";
				toGet2 += instruction[LETTER_2];
				toGet2 += instruction[NUM_2];

				(_board->getCell(toGet) != nullptr && this != _board->getCell(toGet) && _board->getCell(toGet) != _board->getCell(toGet2)) ? toReturn = false : toReturn = true;
			}
		}
		else
		{
			for (i = i; i < max(instruction[LETTER_1], instruction[LETTER_2]) && toReturn; i++, j++)
			{
				string toGet = "";
				toGet += i;
				toGet += j;

				string toGet2 = "";
				toGet2 += instruction[LETTER_2];
				toGet2 += instruction[NUM_2];

				(_board->getCell(toGet) != nullptr && this != _board->getCell(toGet) && _board->getCell(toGet) != _board->getCell(toGet2)) ? toReturn = false : toReturn = true;
			}
		}
	}

	return toReturn;
}


/*
Input: moving instructions
Output: can the piece move or not
function to check 
*/
bool Queen::canEat(string instruction)
{
	if (((abs(instruction[LETTER_1] - instruction[LETTER_2]) == abs(instruction[NUM_2] - instruction[NUM_1])) || (instruction[LETTER_1] == instruction[LETTER_2] || instruction[NUM_1] == instruction[NUM_2])) && notBlocked(instruction))
	{
		return true;
	}

	return false;
}