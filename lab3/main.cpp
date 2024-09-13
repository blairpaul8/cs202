/*  insert comments here */
#include <ctime>
#include <iostream>
#include "CardDeck.h"   // class definition for CardDeck used below
using namespace std;


//print hand helper function
void printDealerHand(vector<int> &a) {
  for (size_t i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

//print hand helper function
void printPlayerHand(vector<int> &a) {
  for (size_t i = 0; i < a.size(); i++) {
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
  cout << "Test: Before shuffling..." << endl;
  testDeck->printDeck();
  testDeck->shuffle(seed);
  cout << "Test: after shuffling..." << endl;
  testDeck->printDeck();
  cout << endl;
  delete testDeck;

  //Start of normal blackjack game
  cout << "Welcome to Blackjack!" << endl;

  while (deckSize != 52) {
    cout << "Input deck size (enter -1 for default of 52): ";
    cin >> deckSize;
    if (deckSize == -1) {
      deckSize = 52;
    }
    if (deckSize != 52) {
      cout << "Enter a valid deck size 52 or -1 for default. " << endl;
    }
    
  }

  //Creating instance of the class CardDeck
  CardDeck *deck;
  if (deckSize == -1) {
    deck = new CardDeck(52);
  }
  else {
    deck = new CardDeck(deckSize);
  }
  deckSize = deck->getSize();
  cout << "Deck size: " << deckSize << endl;
  cout << endl;

  cout << "Random seed # (enter 0 for default of 0): ";
  cin >> seed;
  cout << "\nSeed: " << seed << endl;
  deck->shuffle(seed);

  //this outer while loop is to continue dealing new hands of blackjack
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
    //check # of cards in the deck. If less than 15 a new instance of card deck is called.
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
    deck->printHand(playerHand);
    cout << endl << "Dealer | ";
    dealerTotalScore = deck->scoreHand(dealerHand);
    cout << "Total hand = " << dealerTotalScore << " | ";
    deck->printHand(dealerHand);
    cout << endl << endl;

    //Inner while loop for if the player chooses to stand and is dealt another card. 
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
      //deals another card to the player.
      card = deck->deal();
      playerHand.push_back(card);
      playerTotalScore = deck->scoreHand(playerHand);
      cout << endl << "Player chose to hit!" << endl;
      cout << "Player | ";
      cout << "Total hand = " << playerTotalScore << " | Cards:";
      deck->printHand (playerHand);

      //if players hand goes over 21.
      if (playerTotalScore > 21) {
        cout << endl << endl << "Dealer wins!" << endl;
        numDealerWins += 1;
        break;
      }

      cout << endl;

    }

    //Deals the dealer another card if their total score is less than 17.
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
      deck->printHand(dealerHand);
      cout << endl;
    }

    //if/if else statments to check who won the hand.
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

    cout << "\nCards left in the deck: " << deck->getSize() << endl;
  }


  //printing for who won the overall game.
  if (numDealerWins > numPlayerWins) {
    cout << "---------------------------" << endl;
    cout << "Dealer wins BlackJack!" << endl;
    cout << "---------------------------" << endl;
  }
  else if (numPlayerWins > numDealerWins) {
    cout << "---------------------------" << endl;
    cout << "Player wins BlackJack!" << endl;
    cout << "---------------------------" << endl;

  }
  return 0;

}
