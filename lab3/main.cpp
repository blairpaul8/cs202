/*  insert comments here */
#include <ctime>
#include <iostream>
#include "CardDeck.h"   // class definition for CardDeck used below
using namespace std;


//print hand helper function
void printDealerHand(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

//print hand helper function
void printPlayerHand(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}




int main() {


  int numOfHands = 0;
  int numPlayerWins = 0;
  int numDealerWins = 0;
  int playerTotalScore = 0;
  int dealerTotalScore = 0;
  int deckSize = 0;
  int seed = 0;
  char playerMove = ' ';
  vector<int> playerHand;
  vector<int> dealerHand;

  //test printing shuffled deck
  CardDeck *testDeck = new CardDeck(10);
  testDeck->printDeck();
  testDeck->shuffle(seed);
  cout << "Test: after shuffling..." << endl;
  testDeck->printDeck();
  cout << endl;
  delete testDeck;
  

  //Start of normal blackjack game
  cout << "Welcome to Blackjack!" << endl;
  cout << "Input deck size (enter -1 for default of 52): ";
  cin >> deckSize;

  //Creating instance of the class CardDeck
  CardDeck *deck = new CardDeck(deckSize);
  deckSize = deck->getSize();
  cout << "Deck size: " << deckSize << endl;
  cout << endl;

  cout << "Random seed # (enter 0 for default of 0): ";
  cin >> seed;
  cout << "Seed: " << seed << endl;
  deck->shuffle(seed);

  while (playerMove != 'n') {
    numOfHands += 1;
    playerHand.clear();
    dealerHand.clear();
    int card = 0;
    if (deck->getSize() < 15) {
      delete deck;
      deck = new CardDeck;
      deck->shuffle(seed);
    }
    card = deck->deal();
    playerHand.push_back(card);

    //check # of cards in the deck
    if (deck->getSize() < 15) {
      delete deck;
      deck = new CardDeck;
      deck->shuffle(seed);
    }
    card = deck->deal();
    dealerHand.push_back(card);
    //check # of cards in the deck
    if (deck->getSize() < 15) {
      delete deck;
      deck = new CardDeck;
      deck->shuffle(seed);
    }
    card = deck->deal();
    playerHand.push_back(card);
    //check # of cards in the deck
    if (deck->getSize() < 15) {
      delete deck;
      deck = new CardDeck;
      deck->shuffle(seed);
    }
    card = deck->deal();
    dealerHand.push_back(card);

    cout << endl << "---------------------------" << endl;
    playerTotalScore = deck->scoreHand(playerHand);
    cout << "Player | ";
    cout << "Total hand = " << playerTotalScore << " | ";
    deck->printPlayerHand(playerHand);
    cout << endl << "Dealer | ";
    dealerTotalScore = deck->scoreHand(dealerHand);
    cout << "Total hand = " << dealerTotalScore << " | ";
    deck->printPlayerHand(dealerHand);
    cout << endl << endl;


    while (playerMove != 's') {
      cout << "Player: Hit or Stand (Type 'h' or 's')? ";
      cin >> playerMove;
      if (playerMove == 's') {
        break;
      }
      //check # of cards in the deck
      if (deck->getSize() < 15) {
        cout << "deck size" << deck->getSize() << endl;
        delete deck;
        deck = new CardDeck;
        deck->shuffle(seed);
      }
      card = deck->deal();
      playerHand.push_back(card);
      playerTotalScore = deck->scoreHand(playerHand);
      cout << endl << "Player chose to hit!" << endl;
      cout << "Player | ";
      cout << "Total hand = " << playerTotalScore << " | Cards:";
      deck->printPlayerHand (playerHand);

      if (playerTotalScore > 21) {
        cout << endl << endl << "Dealer wins!" << endl;
        numDealerWins += 1;
        break;
      }

      cout << endl;

    }


    while (dealerTotalScore < 17 && dealerTotalScore < 21) {
      //check # of cards in the deck
      if (deck->getSize() < 15) {
        delete deck;
        deck = new CardDeck;
        deck->shuffle(seed);
      }
      card = deck->deal();
      dealerHand.push_back(card);
      dealerTotalScore = deck->scoreHand(dealerHand);
      cout << endl << "Dealer chose to hit!" << endl;
      cout << "Dealer | ";
      cout << "Total hand = " << dealerTotalScore << " | Cards: ";
      deck->printPlayerHand(dealerHand);
      cout << endl;
    }

    if (dealerTotalScore > 21) {
      cout << endl << "Dealer Bust! You Win!" << endl;
      numPlayerWins += 1;
    }
    else if (dealerTotalScore > playerTotalScore) {
      cout << endl << "Dealer Wins" << endl;
      numDealerWins += 1;
    }
    else if (playerTotalScore > dealerTotalScore && playerTotalScore <= 21) {
      cout << endl << "You Win!" << endl;
      numPlayerWins += 1;
    }
    else if (playerTotalScore == dealerTotalScore){
      cout << endl << "Push" << endl;
    }
    
    cout << "Player Wins: " << numPlayerWins << "  Dealer Wins: " << numDealerWins << endl << endl;
    if (numOfHands >= 1) {
      cout << "Do you want to play another game (type 'y' or 'n')? ";
      cin >> playerMove;

    }
    
    cout << "Cards left in the deck: " << deck->getSize() << endl;
  }

  return 0;

}
