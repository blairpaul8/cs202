#include "C4Col.h"

using namespace std;

C4Col::C4Col() {

}

char C4Col::getDisk(int i) {
	char disk = column[i];
	return disk;
}

void C4Col::placeDisk(int i, char player) {
	column[i] = player;
}
