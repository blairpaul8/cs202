#include <iostream>
#include <string>
using namespace std; 

int main() {
  string input;
  string XOR_split;

  cout << "Enter a hex value: ";
  cin >>input;

  for (size_t i = 0; i < input.size(); i++) {
    if ((i % 7) == 0) {
      XOR_split.push_back(' ');
      XOR_split.push_back(input[i]);
    }
    else {
      XOR_split.push_back(input[i]);
    }
  }
  cout << XOR_split << endl;
}
