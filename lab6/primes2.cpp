// Lab 6: Is it prime?
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

vector<int> primeNums(int n) {
  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    int j = 1;
    int divisorCount = 0;
    while (j <= n) {
      if (i % j == 0) {
        divisorCount += 1;
      }
      if (divisorCount > 2) {
        break;
      }
      j++;
    }
    if (divisorCount == 2) {
      primes.push_back(i);
    }
  }

  return primes;
}
int main(int argc, char *argv[]) {
  int temp;
  int currentPrime = 0;
  vector<int> currentPrimes;
  cin.clear();
  while (cin >> temp) {
    if (temp > currentPrime || currentPrime == 0) {
      currentPrime = temp;
      currentPrimes = primeNums(temp);
      if (find(currentPrimes.begin(), currentPrimes.end(), temp) != currentPrimes.end()) {
        cout << "prime" << endl;
      }
      else {
        cout << "not prime" << endl;
      }
      
    }
    else {
      if (find(currentPrimes.begin(), currentPrimes.end(), temp) != currentPrimes.end()) {
        cout << "prime" << endl;
      }
      else {
        cout << "not prime" << endl;
      }
    }

  }
  return 0;

}

