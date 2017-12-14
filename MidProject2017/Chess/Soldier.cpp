//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Soldier.h"


/*
Input:NONE
Output: NONE
c'tor function for Soldier object
*/
Soldier::Soldier(string type, int color, Board* board) : _type(type), _color(color), _board(board)
{
}



/*
Input: NONE
Output: string _type
getter function for _type value
*/
string Soldier::getType()
{
	return _type;
}


/*
Input: NONE
Output: int _color
getter function for _color value
*/
int Soldier::getColor()
{
	return _color;
}


/*
Input: the moving instruction
Output: is it the same color in the destination and source
function to check if both cells are populated by the same player
*/
bool Soldier::currPlayer(string instruction)
{
	string toGet1 = "";
	toGet1 += instruction[0];
	toGet1 += instruction[1];

	string toGet2 = "";
	toGet2 += instruction[2];
	toGet2 += instruction[3];

	if (_board->getCell(toGet2))
	{
		return _board->getCell(toGet2)->getColor() == _board->getCell(toGet1)->getColor();
	}

	return false;
}


/*
Input: the moving instruction for the piece
Output: 0 if no chess, 1 if chess on enemy, -1 if self chess
function to check the board for a chess
*/
int Soldier::checkChess()
{
	Soldier* kingB = nullptr;
	Soldier* kingW = nullptr;

	//find two kings
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((*this->_board)(i, j))
			{
				if ((*this->_board)(i, j)->getType() == "King")
				{
					(*this->_board)(i, j)->getColor() == 0 ? kingW = (*this->_board)(i, j) : kingB = (*this->_board)(i, j);
				}
			}
		}
	}

	//check if self chess
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((*this->_board)(i, j))
			{
				if ((*this->_board)(i, j)->getColor())
				{
					if ((*this->_board)(i, j)->canMove(string(_board->getXandY((*this->_board)(i, j)) + _board->getXandY(kingW) + "")))
					{
						return -1;
					}
				}
				else
				{
					if ((*this->_board)(i, j)->canMove(string(_board->getXandY((*this->_board)(i, j)) + _board->getXandY(kingB) + "")))
					{
						return -1;
					}
				}
			}
		}
	}

	//check normal chess
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((*this->_board)(i, j))
			{
				if ((*this->_board)(i, j)->getColor())
				{
					if ((*this->_board)(i, j)->canMove(string(_board->getXandY((*this->_board)(i, j)) + _board->getXandY(kingB) + "")))
					{
						return 1;
					}
				}
				else
				{
					if ((*this->_board)(i, j)->canMove(string(_board->getXandY((*this->_board)(i, j)) + _board->getXandY(kingW) + "")))
					{
						return 1;
					}
				}
			}
		}
	}

	return 0;
}