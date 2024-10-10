// Lab 6: Is it prime?
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
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
  cin.clear();
  while (cin >> temp) {

    if (temp > currentMax || currentMax == 0) {
      currentMax = temp;

      for (int i = 0; i <= currentMax; i++) {
        if (isPrime(i)) {
          currentPrimes.push_back(i);
        }
      }
      //printPrimes(currentPrimes);
    }
    if (find(currentPrimes.begin(), currentPrimes.end(), temp) != currentPrimes.end()) {
      cout << "prime" << endl;
    }

    else {
      cout << "not prime" << endl;
    }


  }


return 0;

}

