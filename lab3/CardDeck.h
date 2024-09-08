#include <vector>
#include <stdlib.h>
using namespace std;

class CardDeck {
	
	public:
		CardDeck(int n = 52);
		int getSize();
		void shuffle();
		int deal();
		vector<int> deck;
		void printDeck();
		void printShuffledDeck();
		void swap(int *a,int *b);
    int scoreHand(vector<int> &a);
		int cardPointValue(int carNumber);
		void printPlayerHand(vector<int> &a);
    void printDealerHand(vector<int> &a);
    string cardFaceValue(int card);   
	

	private:
		int n = 52;

};
