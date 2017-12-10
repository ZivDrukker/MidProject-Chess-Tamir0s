//Tam!r0s & Z!v0s @ Chess-MidProject
#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Board.h"


using namespace std;

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	//rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1
	strcpy_s(msgToGraphics, "rkrkrkrkrkrkrkrk################################RKRKRKRKRKRKRKRK1"); // just example...
	
	Board* board = new Board("rkrkrkrkrkrkrkrk################################RKRKRKRKRKRKRKRK1");

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		// YOUR CODE
		string toGet = "";
		toGet += msgFromGraphics[0];
		toGet += msgFromGraphics[1];

		string strToSend = board->getCell(toGet)->move(msgFromGraphics);

		strcpy_s(msgToGraphics, strToSend.c_str()); // msgToGraphics should contain the result of the operation




		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	delete board;

	p.close();
}