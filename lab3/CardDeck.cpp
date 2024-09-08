#include <iostream>
#include <vector>
#include "CardDeck.h"
#include <string>
#include <ctime>

CardDeck::CardDeck(int n) {
	this->n = n;
	deck = vector<int> (n);
	for (int i = 0; i < n; i++) {
		deck[i] = i;
	}

}
		
int CardDeck::getSize() {
	return deck.size();
}

void CardDeck::shuffle() {
	srand(time(0));

	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);

		swap(&deck[i], &deck[j]);
	}
}

int CardDeck::deal() {
	int card = deck.back();
	deck.pop_back();
	
	int cardNumber = card % 13;

	return cardNumber;
}

void CardDeck::printDeck() {
	for (int i = 0; i < deck.size(); i++) {
		cout << deck[i] << ' ';
	}
	cout << endl;
}

void CardDeck::printShuffledDeck() {
	for (int i = 0; i < deck.size(); i++) {
		cout << deck[i] << ' ';
	}
	cout << endl;
}

void CardDeck::swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int CardDeck::scoreHand(vector<int> &a) {
  int totalScore = 0;
  int tempPointValue = 0;
  for (int i = 0; i < a.size(); i++) {
    tempPointValue = cardPointValue(a[i]);
    //cout << endl << "Card Point value is: " << tempPointValue << endl;
    totalScore += tempPointValue;
  }
  return totalScore;
}

//This converts the value from the deck vector int the point value
//based on the mod 13
int CardDeck::cardPointValue(int cardNumber) {
	
	if ((cardNumber % 13) == 0) {
		return 11;
	}
	else if ((cardNumber % 13) > 0 && (cardNumber % 13) < 10) {
		return (cardNumber % 13);
	}
	else {
		return 10;
	}
}

void CardDeck::printPlayerHand(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    int card = a[i];
    string tempCard = cardFaceValue(card);
    
    cout << "Card " << i + 1 << ": " << tempCard << "     "; 
  }
  
}

void CardDeck::printDealerHand(vector<int> &a) {
  int card = a[1];
  string tempCard = cardFaceValue(card);
  cout << tempCard;

}

string CardDeck::cardFaceValue(int card) {
  int temp = 0;
  if ((card % 13) == 0) {
    return "Ace";
  }
  else if ((card % 13) > 0 && (card % 13) < 10)  {
    temp = card % 13;
    string numberCard = to_string(temp);
    return numberCard;
  }
  else if ((card % 13) == 10) {
    string jack = "Jack";
    return jack;
  }
  else if ((card % 13) == 11) {
    string queen = "Queen";
    return queen;
  }
  else {
    string king = "King";
    return king;
  }
}



	 
