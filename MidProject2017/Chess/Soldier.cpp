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
Input: instruction to move
Output: string if succed or not
function for checking if the soldier can move there
*/
string Soldier::moveAll(string instruction)
{
	string toReturn = "";
	if (!this->currPlayer(instruction))
	{
		string toSet = "";
		toSet += instruction[LETTER_2];
		toSet += instruction[NUM_2];

		Soldier* tempCell = _board->setCell(this, toSet);

		toSet = "";
		toSet += instruction[LETTER_1];
		toSet += instruction[NUM_1];
		_board->setCell(nullptr, toSet);

		if (!checkSelfChess())
		{
			if (tempCell != nullptr)
			{
				delete tempCell;
			}

			checkEnemyChess() ? toReturn = "1" : toReturn = "0";
		}
		else
		{
			string toSet = "";
			toSet += instruction[LETTER_2];
			toSet += instruction[NUM_2];
			_board->setCell(tempCell, toSet);

			toSet = "";
			toSet += instruction[LETTER_1];
			toSet += instruction[NUM_1];
			_board->setCell(this, toSet);

			toReturn = "4";
		}
	}
	else
	{
		toReturn = "3";
	}
	return toReturn;
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
	toGet1 += instruction[LETTER_1];
	toGet1 += instruction[NUM_1];

	string toGet2 = "";
	toGet2 += instruction[LETTER_2];
	toGet2 += instruction[NUM_2];

	if (_board->getCell(toGet2))
	{
		return _board->getCell(toGet2)->getColor() == _board->getCell(toGet1)->getColor();
	}

	return false;
}


/*
Input: NONE
Output: true if chess false if not
the function is checking if there is chess on yourself by moving the piece
*/
bool Soldier::checkSelfChess()
{
	Soldier* king = nullptr;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((*this->_board)(i, j))
			{
				if ((*this->_board)(i, j)->getType() == "King" && (*this->_board)(i, j)->getColor() == this->getColor())
				{
					king = (*this->_board)(i, j);
				}
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((*this->_board)(i, j))
			{
				if ((*this->_board)(i, j)->getColor() != king->getColor())
				{
					string toEat = _board->getXandY((*this->_board)(i, j));
					toEat +=_board->getXandY(king);

					if ((*this->_board)(i, j)->canEat(toEat))
					{
						return (*this->_board)(i, j);
					}
				}
			}
		}
	}
	return nullptr;
}


/*
Input: NONE
Output: true if chess false if not
the function is checking if there is chess on the enemy by moving the piece
*/
bool Soldier::checkEnemyChess()
{
	Soldier* king = nullptr;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((*this->_board)(i, j))
			{
				if ((*this->_board)(i, j)->getType() == "King" && (*this->_board)(i, j)->getColor() != this->getColor())
				{
					king = (*this->_board)(i, j);
				}
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((*this->_board)(i, j))
			{
				if ((*this->_board)(i, j)->getColor() != king->getColor())
				{
					string toEat = _board->getXandY((*this->_board)(i, j));
					toEat += _board->getXandY(king);

					if ((*this->_board)(i, j)->canEat(toEat))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}