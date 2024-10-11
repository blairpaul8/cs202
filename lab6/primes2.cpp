/* Lab 6: Is it prime?
 * Name: Paul Blair
 * Net ID: VBQ669
 * Description: This program will take in user input if the number is the biggest number 
 * so far then the program will fill a vector with all the prime numbers from 0 to this
 * number. With all of the following values given by the user the program will return
 * whether the value is prime or not. If a new biggest number is given then the vector
 * will be reset with all prime numbers for 0 - the new max value.
 *
 * NOTE: All commented out code was used for the tests in the report or calulating the load
 * factor.
*/ 
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

int main(int argc, char *argv[]) {
  int temp;
  int currentMax = 0;
  //int loadCount = 0;
  vector<int> currentPrimes;
  vector<int> zeroOrOne(currentMax, 0);
  map<int, bool> primesMap;
  cin.clear();
  while (cin >> temp) {

    //Changes the current max if a new max value is given by the user
    if (temp > currentMax || currentMax == 0) {
      //loadCount = 0;
      currentMax = temp;
      //zeroOrOne = vector<int> (currentMax + 1, 0);

      for (int i = 0; i <= currentMax; i++) {
        if (isPrime(i)) {
          // primesMap[i] = true;
          currentPrimes.push_back(i);
          //zeroOrOne[i] = 1;
          //loadCount += 1;
          //cout << "Load Count: " << loadCount << endl;
        }
        //else {
        //primesMap[i] = false;
        //}
      }
    }


    // Using find 
    if (find(currentPrimes.begin(), currentPrimes.end(), temp) != currentPrimes.end()) {
      cout << "prime" << endl;
    }
    else {
      cout << "not prime" << endl;
    }
    /* The code inside this comment was used for the different tests in the report 
    // Using Binary Serach
    if (binary_search(currentPrimes.begin(), currentPrimes.end(), temp)) {

    //using the user input as the index to find the value and wether it is 
    //prime or not.
    if (zeroOrOne[temp] == 1) { 
    if (primesMap[temp] == true) {
    cout << "prime" << endl;
    }
    else {
    cout << "not prime" << endl;
    }*/
  }
  //Calculate load factor.
  //double load = ((double)loadCount / (double)currentMax) * 100;
  //cout << "Load factor: " << load <<  "%" << endl;

  return 0;
  }

