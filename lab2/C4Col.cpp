#include "C4Col.h"

using namespace std;

C4Col::C4Col() {
	for (int i = 0; i < 6; i++) {
		column[i] = ' ';
	}
	maxDisk = 6;
}

char C4Col::getDisk(int i) {
	char disk = column[i];
	return disk;
}

void C4Col::placeDisk(int i, char player) {
	column[i] = player;
}

int C4Col::getMaxDisks() {
	return maxDisk;
}
