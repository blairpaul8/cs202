#include <vector>
#include <stdlib.h>
using namespace std;

class CardDeck {
	
	public:
		CardDeck(int n = 52);
    CardDeck(const CardDeck&);
    ~CardDeck();
    CardDeck& operator= (const CardDeck&);
		int getSize();
		void shuffle(int seed);
		int deal();
		void printDeck();
		void swap(int *a,int *b);
    int scoreHand(vector<int> &a);
		int cardPointValue(int carNumber);
		void printHand(vector<int> &a);
    int cardValue(int card);   
	

	private:
		int n = 52;
    vector<int> deck;

};
