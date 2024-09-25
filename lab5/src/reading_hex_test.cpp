#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int last7(string key) {
 int startIndex = key.size() < 7 ? 0 : (key.size() - 7);
 
 istringstream ss;
 //string hexValue = (key.substr(0));
 int num;
  
 ss.clear();
 ss.str(key);
 if (ss >> hex >> num) {
  cout << "Last 7 is: " << num << endl;
 }

 return num;
}
  
int main() {
  string input;
  int index = 0;
  cout << "Enter a hex value: ";
  cin >> input;

  index = last7(input);

  cout << "Index is: " << index << endl;

  
}

