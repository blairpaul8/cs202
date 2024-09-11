// Lab 04: Adding List-Based Integers
#include "list.h"
#include <iostream>
#include <string>
using namespace std;


void parseInput(string input, string &value1, string &value2) {
  char space = '\0';
  for (int i = 0; i < input.size(); i++) {
    if (input[i] = ' ') {
      space = ' ';
      continue;
    }
    else  if (space != ' ') {
      value1.push_back(input[i]);
    }
    else if (space = ' '){ 
      value2.push_back(input[i]);
    }
  }
}

LinkedList sumNodes(LinkedList num1, LinkedList num2, LinkedList sum, string &value1, string &value2) {
  int carry = 0;
  int sum = 0;
  LinkedList
  
  for (temp = head; temp != nullptr; temp = temp -> next) {
         
  }
  
  
}

int main() {
  string input;
  string value1;
  string value2;
  int temp = 0;
  LinkedList num1;
  LinkedList num2;
  LinkedList sum;

  while (getline(cin, input)) {
    
  }



  return 0;
}


