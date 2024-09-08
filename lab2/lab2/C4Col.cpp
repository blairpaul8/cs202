#include "C4Col.h"

using namespace std;

C4Col::C4Col() {
	for (int i = 0; i < 6; i++) {
		column[i] = ' ';
	}
	maxDisk = 6;
}
//gets the disk from the index "disk" and returns the value
char C4Col::getDisk(int diskIndex) {
	char disk = column[diskIndex];
	return disk;
}

//places the disk in the column array.
void C4Col::placeDisk(int disk, char player) {
	column[disk] = player;
}
//returns the maximum number of disks
int C4Col::getMaxDisks() {
	return maxDisk;
}
