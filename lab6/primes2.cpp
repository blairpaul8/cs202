// Lab 6: Is it prime?
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

bool isPrime(int value) {
  if (value == 2) {
    return true;
  }
  if (value < 2 || value % 2 == 0) {
    return false;
  }
  for (int i = 3; (i * i) <= value; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;

}

void printPrimes(vector<int> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << ", ";
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  int temp;
  int currentMax = 0;
  vector<int> currentPrimes;
  vector<int> zeroOrOne(currentMax, 0);
  map<int, string> primesMap;
  cin.clear();
  while (cin >> temp) {

    if (temp > currentMax || currentMax == 0) {
      currentMax = temp;
      zeroOrOne = vector<int> (currentMax + 1, 0);

      for (int i = 0; i <= currentMax; i++) {
        if (isPrime(i)) {
          primesMap[i] = "prime";
          currentPrimes.push_back(i);
          zeroOrOne[i] = 1;
        }
        else {
          primesMap[i] = "not prime";
        }
      }
      //printPrimes(currentPrimes);
    }
    // Using find 
    //if (find(currentPrimes.begin(), currentPrimes.end(), temp) != currentPrimes.end()) {
    
    // Using Binary Serach
    //if (binary_search(currentPrimes.begin(), currentPrimes.end(), temp)) {
    //
    //using the user input as the index to find the value and wether it is 
    //prime or not.
    /*if (zeroOrOne[temp] == 1) { 
      cout << "prime" << endl;
    }
    else {
      cout << "not prime" << endl;
    }*/ 
    if (primesMap.find(temp) != primesMap.end()) {
      cout << primesMap[temp] << endl; 
    }


  }
  //printPrimes(zeroOrOne);


return 0;

}

