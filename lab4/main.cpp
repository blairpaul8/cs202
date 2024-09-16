// Lab 04: Adding List-Based Integers
// Name: Paul Blair
// Net Id: VBQ 669
// Description: This program will take two numbers from stdin and write them to a LinkedList for each value.
//              example 123 123 will got to a list a 3->2->1 and another list 3->2->1 and then add the value 
//              from each node together to get the sum of the two numbers from the original input. The example
//              would result in 246 and these values are written to a LinkedList aswell 2->4->6.
#include "list.h"
#include <iostream>
#include <utility>
#include <string>
using namespace std;

//Used a struct for the LinkedList instead of a class.
struct LinkedList {
  
  public:
    LinkedList();
    void insertAtBegin(int data);
    void insertAtEnd(int data);
    void clearList();
    Node *head;

};

LinkedList::LinkedList() {
  this -> head = nullptr;
}

//pushs values onto the front of the list
void LinkedList::insertAtBegin(int data) {
  Node * newNode = new Node(data);
  if (head == nullptr) {
    head = newNode;
    return;
  }
  newNode -> next = head;
  head = newNode;
}

//pushes values onto the end of the list.
void LinkedList::insertAtEnd(int data) {
  Node *newNode = new Node(data);
  if (head == nullptr) {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp -> next != nullptr) {
    temp = temp -> next;
  }
  temp -> next = newNode;
}

void LinkedList::clearList() {
  while (head != nullptr) {
    Node *temp = head;
    head = head->next;
    delete(temp);
    

  }
}

void printList(const LinkedList &a) {
  Node *temp = a.head;
  while (temp != nullptr) {
    int data = temp -> getData();
    cout << data;
    temp = temp -> next;
  }
  cout << endl;
}

//Parses the input from stdin into two separate strings. Breaks on a space " ".
pair<string, string> parseInput(string input) {
  pair <string, string> values;
  char space = '\0';
  for (size_t i = 0; i < input.size(); i++) {
    if (input[i] == ' ') {
      space = ' ';
      continue;
    }
    else  if (space != ' ') {
      values.first.push_back(input[i]);
    }
    else if (space == ' '){ 
      values.second.push_back(input[i]);
    }
  }
  return values;
}

//uses insertAtBegin to push each element of value1 and value2 onto thier respective LinkedList.
void addNodes(pair <string, string> values, LinkedList &num1, LinkedList &num2) {
  unsigned long size = max(values.first.size(), values.second.size());
  
  for (unsigned long i = 0; i < size; i++ ) {
    if (i >= values.first.size()) {
      num1.insertAtEnd(0);
    }
    else {
      char tempValue = values.first[i];
      int finalValue = tempValue - '0';
      num1.insertAtBegin(finalValue);
    }

    if (i >= values.second.size()) {
      num2.insertAtEnd(0);
    }
    else {
      char tempValue = values.second[i];
      int finalValue = tempValue - '0';
      num2.insertAtBegin(finalValue);
    }
  }

}

//Does the math operations to add the nodes together.
LinkedList sumNodes(LinkedList &num1, LinkedList &num2) {
  LinkedList addedNumbers;
  int carry = 0;
  
  Node *temp1 = num1.head;
  Node *temp2 = num2.head;
  while (temp1 != nullptr) {
    int number1 = temp1->getData();
    int number2 = temp2->getData();
    
    int sum = number1 + number2 + carry;
    int finalNumber = (sum % 10);
    carry = sum / 10;
    
    addedNumbers.insertAtBegin(finalNumber);
    
    temp2 = temp2->next;
    temp1 = temp1->next;
  }
  //If there is a carry value after the last nodes have been added together
  //that value needs to be pushed onto the final LinkedList addedNumbers.
  if (carry > 0) {
    addedNumbers.insertAtBegin(carry);
  }
  return addedNumbers;
}

int main() {
  string input;
  LinkedList num1;
  LinkedList num2;
  LinkedList addedNumbers;
  pair <string, string> values;

  while (getline(cin, input)) {
    values = parseInput(input);
    addNodes(values, num1, num2);

    addedNumbers = sumNodes(num1, num2); 
    printList(addedNumbers);
    num1.clearList();
    num2.clearList();
    addedNumbers.clearList();
  }
  return 0;
}
