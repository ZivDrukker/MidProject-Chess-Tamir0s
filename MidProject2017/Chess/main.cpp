//Tam!r0s & Z!v0s @ Chess-MidProject

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Board.h"

#define INIT_COLOR_INDEX 64
#define SLEEP_TIME 1000
#define BUFFER 1024
#define IS_EVEN 2

using namespace std;

void main()
{
	srand(time_t(NULL));
	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(SLEEP_TIME);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[BUFFER];
	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");
	
	Board* board = new Board("rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	int counter = (int)msgToGraphics[INIT_COLOR_INDEX] - ZERO_ASCII;
	counter >= 1 ? counter = BLACK_COLOR : counter = WHITE_COLOR;

	while (msgFromGraphics != "quit")
	{
		board->printBoard();

		string toGet = "";
		toGet += msgFromGraphics[LETTER_1];
		toGet += msgFromGraphics[NUM_1];
		Soldier* cell = board->getCell(toGet);
		string strToSend = "";

		if (cell != nullptr)
		{
			if (cell->getColor() % IS_EVEN == counter % IS_EVEN)
			{
				strToSend = cell->move(msgFromGraphics);
			}
			else
			{
				strToSend = "2";
			}
		}
		else
		{
			strToSend = "2";
		}

		if (strToSend == "0" || strToSend == "1")
		{
			counter++;
		}

		strcpy_s(msgToGraphics, strToSend.c_str()); // msgToGraphics should contain the result of the operation

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	delete board;

	p.close();
}