/* Name: Paul Blair
 * Net ID: VBQ669
 * Description: This program takes in a value from the command line arguments 
 *              and will print out all the prime numbers from 0 - n to the console.
*/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void isPrime(int n) {
  vector<int> primes;
     
  for (int i = 2; i <= n; i++) {
    int j = 1;
    int divisorCount = 0;
    while (j <= n) {
      if (i % j == 0) {
        divisorCount += 1;
      }
      //if the number is divisible by more than 1 or itself it isnt prime.
      if (divisorCount > 2) {
        break;
      }
      j++;
    }
    if (divisorCount == 2) {
      primes.push_back(i);
    }
  }

  //Used for printing all the prime values.
  for (int i = 0; i < primes.size(); i++) {
    cout << primes[i];
    if (i != (primes.size() - 1)) {
      cout << ", ";
    }
    if (i % 19 == 0 && i != 0) {
      cout << endl;
    }
    
  }
  cout << endl; 
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
