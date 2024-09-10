#include <vector>
#include <stdlib.h>
using namespace std;

class CardDeck {
	
	public:
		CardDeck(int n = 52);
    CardDeck(const CardDeck&);
    ~CardDeck();
		int getSize();
		void shuffle(int seed);
		int deal();
		void printDeck();
		void printShuffledDeck();
		void swap(int *a,int *b);
    int scoreHand(vector<int> &a);
		int cardPointValue(int carNumber);
		void printPlayerHand(vector<int> &a);
    //void printDealerHand(vector<int> &a);
    int cardValue(int card);   
	

	private:
		int n = 52;
    vector<int> deck;

};
