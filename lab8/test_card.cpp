#include <iostream>
#include <string>
 using namespace std;
int main() {
    std::string heart = reinterpret_cast<const char*>(u8"\u2665");
    std::string diamond = reinterpret_cast<const char*>(u8"\u2666");
    std::string club = reinterpret_cast<const char*>(u8"\u2663");
    std::string spade = reinterpret_cast<const char*>(u8"\u2660");
    
    std::cout << "Heart: " << heart << "\n";
    std::cout << "Diamond: " << diamond << "\n";
    std::cout << "Club: " << club << "\n";
    std::cout << "Spade: " << spade << "\n";
    char a = (char)184;
    string line = reinterpret_cast<const char*>(u8"\u007c");
    cout << "Line: " << line << endl;
    return 0;
}

  --------
 | 4      |
 |        |
 |  heart |
 |        |
 |       4|
  --------

  cardeck vector
[1,2,3,4,5 ........ ,52]


deal() {
  random() % 52;

  return int num;
  4
}
 if (card_num < 13) {
   suit = heart;
 }

hearts 0-12
diamons 13-
