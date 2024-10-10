#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void isPrime(int n) {
  vector<int> primes;
  /* bool prime[n + 1];
     memset(prime, true, sizeof(prime));

     for (int i = 2; i * i <= n; i++) {
     if (prime[i] == true) {

     for (int j = i * i; j <= n; j += i) {
     prime[j] = false;

     }
     }
     }
     */
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

  for (int i = 0; i < primes.size(); i++) {
    cout << primes[i];
    if (i != (primes.size() - 1)) {
      cout << ", ";
    }
    if (i == 20) {
      cout << endl;
    }
    
  }
  cout << endl;
  /*int printCount = 0;
    for (int i = 2; i <= n; i++) {
    if (prime[i]) {
    cout << i;
    if (i != n) {
    cout << ", ";
    }
    printCount += 1;
    if (printCount % 20 == 0) {
    cout << endl;
    }
    }
    }
    cout << endl;*/
}

int main (int argc, char **argv) {
  if (argc != 2) {
    cerr << "./programName inputValue" << endl;
    return 1;
  }
  int n = atoi(argv[1]); 

  isPrime(n);

  return 0;
}
