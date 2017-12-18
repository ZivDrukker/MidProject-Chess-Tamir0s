//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Knight.h"


/*
Input: color to set user color and board
Output: NONE
c'tor function for King object
*/
Knight::Knight(int color, Board* board) : Soldier("Knight", color, board)
{
}


/*
Input: instruction to move the piece
Output: NONE
function for moving the piece
*/
string Knight::move(string instruction)
{
	string toReturn = "";

	if (abs(instruction[LETTER_1] - instruction[LETTER_2]) == 2 && abs(instruction[NUM_2] - instruction[NUM_1]) == 1 || abs(instruction[LETTER_1] - instruction[LETTER_2]) == 1 && abs(instruction[NUM_2] - instruction[NUM_1]) == 2)
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
bool Knight::notBlocked(string instruction)
{
	return false;
}


/*
Input: moving instructions
Output: can the piece move or not
function to check 
*/
bool Knight::canEat(string instruction)
{
	if (abs(instruction[LETTER_1] - instruction[LETTER_2]) == 2 && abs(instruction[NUM_2] - instruction[NUM_1]) == 1 || abs(instruction[LETTER_1] - instruction[LETTER_2]) == 1 && abs(instruction[NUM_2] - instruction[NUM_1]) == 2)
	{
		return true;
	}

	return false;
}
