#pragma once
#include "C4Col.h"
#include <iostream>
#include <vector>
using namespace std;

class C4Board {

	public:
		void play();
		void printBoard();
		void addDisk(int column, char player);
	
	private:
		bool isFull(int playerMove);
		bool checkRow();
		bool checkColumn();
		bool checkDiagonal();
		int numCol = 7;
		C4Col board[7];
		
};
