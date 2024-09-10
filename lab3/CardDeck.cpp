#include <iostream>
#include <vector>
#include "CardDeck.h"
#include <string>
#include <ctime>

//constructor with fall back value
CardDeck::CardDeck(int n) {
	this->n = n;
	deck = vector<int> (n);
	for (int i = 0; i < n; i++) {
		deck[i] = i;
	}
  //shuffle();
}

//copy constructor
CardDeck::CardDeck(const CardDeck&) {

}

//deconstructor
CardDeck::~CardDeck() {
  //delete deck;
}

int CardDeck::getSize() {
	return deck.size();
}

void CardDeck::shuffle(int seed) {
  srand(seed);
	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);

		swap(&deck[i], &deck[j]);
	}
}

int CardDeck::deal() {
	int card = deck.back();
	deck.pop_back();
	
	//int cardNumber = card % 13;

	return card;
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
	else if ((cardNumber % 13) > 0 && (cardNumber % 13) < 9) {
		return (cardNumber % 13) + 1;
	}
	else {
		return 10;
	}
}

void CardDeck::printPlayerHand(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    int card = a[i];
    int tempCard = cardValue(card);
    
    cout << tempCard << " "; 
  }
  
}

//I dont think I need this 
/*
void CardDeck::printDealerHand(vector<int> &a) {
  int card = a[1];
  int tempCard = cardValue(card);
  cout << tempCard;

}*/

int CardDeck::cardValue(int card) {
  if ((card % 13) == 0) {
    return 0;
  }
  else if ((card % 13) > 0 && (card % 13) < 10)  {
    int cardValue = (card % 13) + 1;
    
    return cardValue;
  }
  else if ((card % 13) == 10) {
    return 10;
  }
  else if ((card % 13) == 11) {
    return 11;
  }
  else {
    return 12;
  }
}



	 
