#include "card.h"
#include <iostream>

using namespace std;

int main() {
  string suit = "hearts";
  Card card1(suit);

  cout << "test card: ";
  card1.print_card();
  cout << endl;
}
