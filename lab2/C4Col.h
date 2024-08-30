#pragma once	
#include <iostream>
using namespace std;

class C4Col {
	public:
		C4Col();
		char column[6] = {' ', ' ', ' ', ' ', ' ', ' '};
		char getDisk(int i);
		void placeDisk(int i, char player);

};
