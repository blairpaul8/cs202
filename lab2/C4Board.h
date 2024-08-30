#pragma once
#include "C4Col.h"
#include <iostream>
#include <vector>
using namespace std;

class C4Board {

	public:
		C4Board();
		void play();
		void printBoard();
		void addDisk(int column, char player);
		bool checkRow();
		bool checkColumn();
		bool checkDiagonal();
	private:
		int numCol = 7;
		C4Col board[7];
		
};
