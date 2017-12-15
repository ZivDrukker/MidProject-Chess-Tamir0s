//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Board.h"
#include "King.h" //need for fixing the errors
#include "Rook.h"


/*
Input: string to set board by
Output: NONE
c'tor function for Board object
*/
Board::Board(string str)
{
	int i = 0;
	//_gameBoard = new Soldier**[SIZE];
	
	for (i = 0; i < SIZE; i++)
	{
		//_gameBoard[i] = new Soldier*;
		cout << "a";
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
			if (_gameBoard[i][j] != nullptr)
			{
				delete _gameBoard[i][j];
				_gameBoard[i][j] = nullptr;
			}
		}
	}

	//delete _gameBoard;
}


/*
Input: string to search by
Output: the soldier found in the place, nullptr if no soldier found
function to get the soldier in a specific place by a given string
*/
Soldier* Board::getCell(string cell)
{
	int col = ((int)cell[0] - A_ASCII), row = ((int)cell[1] - ZERO_ASCII - 1);

	return _gameBoard[row][col];
}


/*
Input: soldier to insert and cell to insert to
Output: the cell you are exchanging
function to set a soldier to a cell
*/
Soldier* Board::setCell(Soldier* piece, string cell)
{
	int col = ((int)cell[0] - A_ASCII), row = abs((int)cell[1] - ZERO_ASCII - 1);
	Soldier* temp = _gameBoard[row][col];
	_gameBoard[row][col] = piece;
	return temp;
	//_gameBoard[(int)instruction[0]][(int)instruction[1]] = _boa;
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
Input: string to set to the board
Output: NONE
function to set the board
*/
void Board::setBoard(string str)
{
	int i = 0, j = 0;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			switch (str[(i * SIZE) + j])
			{
			case KING_BLACK:
				_gameBoard[i][j] = new King(1, this);
				break;

			case KING_WHITE:
				_gameBoard[i][j] = new King(0, this);
				break;

			case ROOK_BLACK:
				_gameBoard[i][j] = new Rook(1, this);
				break;

			case ROOK_WHITE:
				_gameBoard[i][j] = new Rook(0, this);
				break;

			case EMPTY_PIECE:
				_gameBoard[i][j] = nullptr;
				break;

			default:
				break;
			}
		}
	}
}


/*
Input: Soldier piece
Output: string of where it is in x and y (int)
function for getting x and y of piece
*/
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
				place += (j + ZERO_ASCII);
				found = true;
			}
		}
	}
	return place;
}

/*
Input: NONE
Output: NONE
function for printing the board
*/
void Board::printBoard()
{
	for (int i = SIZE - 1; i >= 0; i--)
	{
		for (int j = SIZE - 1; j >= 0; j--)
		{
			if (_gameBoard[i][j])
			{
				cout << _gameBoard[i][j]->getType() << _gameBoard[i][j]->getColor() << " ";
			}
			else
			{
				cout << "# ";
			}
		}
		cout << std::endl;
	}
}