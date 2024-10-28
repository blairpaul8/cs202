#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
  public:
    Card(string suit);
    void print_card();
    string hearts;
    string diamonds;
    string clubs;
    string spades;

  private:
    string suit;
};

#endif  //CARD_H 
