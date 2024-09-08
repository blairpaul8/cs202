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
  CardDeck deck = CardDeck(52);
  deck.shuffle();


  //int numOfHands = 0;
  //int numPlayerWins = 0;
  //int numDealerWins = 0;
  int playerTotalScore = 0;
  int dealerTotalScore = 0;
  char playerMove;
  //int playerCount = 0;
  //int dealerCount = 0;
  vector<int> playerHand;
  vector<int> dealerHand;


  cout << "Welcome to Blackjack!" << endl;
  cout << "To play enter h to hit and s to stand. To quit enter q." 
    << endl << endl;

  //	while (playerMove != 'q') {
  int card= 0;
  card = deck.deal();
  playerHand.push_back(card);
  card = deck.deal();
  dealerHand.push_back(card);
  card = deck.deal();
  playerHand.push_back(card);
  card = deck.deal();
  dealerHand.push_back(card);
  //cout << "Your cards are " << playerHand[0] << " and " << playerHand[1] << endl;
  //cout << "Dealers cards are " << dealerHand[0] << " and " << dealerHand[1] << endl;
  //cout << "Your first card is: " << playerHand[0] << endl; 	
  playerTotalScore = deck.scoreHand(playerHand);
  cout << "Your cards are: " << endl;
  deck.printPlayerHand(playerHand);
  cout << "Total: " << playerTotalScore << endl;
  cout << endl << "Dealer is showing: " << endl;
  deck.printDealerHand(dealerHand);
  cout << endl << endl;


  while (playerMove != 's') {
    cout << "HIT or STAND: ";
    cin >> playerMove;
    if (playerMove == 's') {
      break;
    }
    card = deck.deal();
    playerHand.push_back(card);
    playerTotalScore = deck.scoreHand(playerHand);
    deck.printPlayerHand(playerHand);
    cout << "Total: " << playerTotalScore << endl;
    if (playerTotalScore > 21) {
      cout << "Bust! Dealer Wins." << endl;
      break;
    }

    cout << endl;

  }

  //printDealerHand(dealerHand);
  cout << endl;
  cout << "Dealers cards: " << endl;
  dealerTotalScore = deck.scoreHand(dealerHand);
  deck.printPlayerHand(dealerHand);
  cout << "Total: " << dealerTotalScore << endl;

  while (dealerTotalScore < 17 && dealerTotalScore < 21) {
    card = deck.deal();
    dealerHand.push_back(card);
    dealerTotalScore = deck.scoreHand(dealerHand);
    deck.printPlayerHand(dealerHand);
    cout << "Total: " << dealerTotalScore << endl;
  }

  if (dealerTotalScore > 21) {
    cout << endl << "Dealer Bust! You Win!" << endl;
  }
  else if (dealerTotalScore > playerTotalScore) {
    cout << endl << "Dealer Wins" << endl;
  }
  else if (playerTotalScore > dealerTotalScore) {
    cout << endl << "You Win!" << endl;
  }
  else {
    cout << endl << "Push" << endl;
  }







}
