#include "card.h"
#include <iostream>
#include <string>

using namespace std;

string hearts = reinterpret_cast<const char*>(u8"\u2665");
string diamonds = reinterpret_cast<const char*>(u8"\u2666");
string clubs = reinterpret_cast<const char*>(u8"\u2663");
string spades = reinterpret_cast<const char*>(u8"\u2660");

Card::Card(string suit) {
  this ->suit = suit;
}



void print_card() {
  string card_suit;
  int num = 4
  if (this->suit == hearts) {
    card_suit = hearts;
  }
  else if (this->suit == diamonds) {
    card_suit = diamonds;
  }
  else if (this->suit == clubs) {
    card_suit = clubs;
  }
  else {
    card_suit = spades;
  }

  cout << " ---------- " << endl;
  cout << "| " << num << "       " << "|" << endl;
  cout << "|" << "       " << "|" << endl;
  cout << "|" << "   " << card_suit << "   " << "|" << endl;
  cout << "|" << "       " << "|" << endl;
  cout << "| " << "       "  << num << " |" << endl;
  cout << " ---------- " << endl;
  
}
