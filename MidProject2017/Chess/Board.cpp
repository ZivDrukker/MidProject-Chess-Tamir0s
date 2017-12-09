//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Board.h"


/*
Input: string to set board by
Output: NONE
c'tor function for Board object
*/
Board::Board(string str)
{
	int i = 0;
	_gameBoard = new Soldier**[SIZE];

	for (i = 0; i < SIZE; i++)
	{
		_gameBoard[i] = new Soldier*[SIZE];
	}

	setBoard(str);
}


/*
Input:
Output:
d'tor function for Board object
*/
Board::~Board()
{
	int i = 0, j = 0;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (_gameBoard[i][j])
			{
				delete _gameBoard[i][j];
			}
		}
	}

	delete _gameBoard;
}


/*
Input: string to search by
Output: the soldier found in the place, nullptr if no soldier found
function to get the soldier in a specific place by a given string
*/
Soldier* Board::getCell(string cell)
{
	int row = ((int)cell[0] - A_ASCII), col = ((int)cell[1] - ONE_ASCII);

	return _gameBoard[row][col];
}


/*
Input: soldier to insert and cell to insert to
Output: NONE
function to set a soldier to a cell
*/
void Board::setCell(Soldier* piece, string cell)
{
	int row = ((int)cell[0] - A_ASCII - 1), col = ((int)cell[1] - ONE_ASCII - 1);

	if (_gameBoard[row][col])
	{
		delete _gameBoard[row][col];
	}
	_gameBoard[row][col] = piece;
}


/*
Input: the indexs to access
Output: the Soldier in the given x and y
operator overriding for the () operator in Board object
*/
Soldier* Board::operator()(int x, int y)
{
	return _gameBoard[x][y];
}


/*
Input:
Output:
function to set the board
*/
void Board::setBoard(string str)
{
	int i = 0, j = 0;

	for (i = 1; i <= SIZE; i++)
	{
		for (j = 1; j <= SIZE; j++)
		{
			switch (str[i * j])
			{
			case KING_BLACK:
				//TODO: add all classes and fill out switch case
			default:
				break;
			}
		}
	}
}


string Board::getXandY(Soldier* piece)
{
	bool found = false;
	string place = "";
	for (int i = 0; i < SIZE && !found; i++)
	{
		for (int j = 0; j < SIZE && !found; j++)
		{
			if (piece == _gameBoard[i][j])
			{
				place += (i + A_ASCII);
				place += (j + ONE_ASCII);
				found = true;
			}
		}
	}
	return place;
}