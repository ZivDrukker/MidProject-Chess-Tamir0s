//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Pawn.h"


/*
Input: color to set user color and board
Output: NONE
c'tor function for King object
*/
Pawn::Pawn(int color, Board* board) : Soldier("Pawn", color, board), _alreadyMoved(false)
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
	string toGet = "";
	toGet += instruction[LETTER_2];
	toGet += instruction[NUM_2];
	if(color == WHITE_COLOR)
	{
		if (((instruction[LETTER_1] == instruction[LETTER_2]) && ((instruction[NUM_1] - instruction[NUM_2] == -1) && !_board->getCell(toGet) || ((instruction[NUM_1] - instruction[NUM_2] == -FIRST_MOVE_LEN) &&  !_alreadyMoved && !_board->getCell(toGet) && notBlocked(instruction)))) || canEat(instruction))
		{
			toReturn = moveAll(instruction);
		}
		else
		{
			toReturn = "6";
		}
	}
	else
	{
		if (((instruction[LETTER_1] == instruction[LETTER_2]) && ((instruction[NUM_1] - instruction[NUM_2] == 1) && !_board->getCell(toGet) || ((instruction[NUM_1] - instruction[NUM_2] == FIRST_MOVE_LEN) && !_alreadyMoved && !_board->getCell(toGet) && notBlocked(instruction)))) || canEat(instruction))
		{
			toReturn = moveAll(instruction);
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
	//no need to check if first move, becuase sent to func only from first move condition
	string toGet = "";
	toGet += instruction[LETTER_1];

	if (this->getColor() == BLACK_COLOR)
	{
		toGet += "6";

		return !_board->getCell(toGet);
	}

	toGet += "3";
	return !_board->getCell(toGet);
}


/*
Input: moving instructions
Output: can the piece move or not
function to check if a pawn can eat in a given spot
*/
bool Pawn::canEat(string instruction)
{
	string newInstruction = "";
	newInstruction += instruction[LETTER_2];
	newInstruction += instruction[NUM_2];

	if ((*this->_board).getCell(newInstruction))
	{
		if (abs(instruction[LETTER_1] - instruction[LETTER_2]) == 1)
		{
			if (instruction[NUM_1] - instruction[NUM_2] == 1 && this->getColor() == BLACK_COLOR)
			{
				return true;
			}
			else if (instruction[NUM_1] - instruction[NUM_2] == -1 && this->getColor() == WHITE_COLOR)
			{
				return true;
			}
		}
	}

	return false;
}