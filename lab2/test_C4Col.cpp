#include <iostream>
using namespace std;

class C4Col {
	public:
		C4Col();
		char column[6] = {'-', '-', '-', '-', '-', '-'};
		char getDisc(int i);

};

C4Col::C4Col() {

}


char C4Col::getDisc(int i) {
	char disc = column[i];
	return disc;
}


int main() {
	C4Col column1 = C4Col();
	
	cout << column1.getDisc(1) << endl;
	return 0;
}


