#include "list.h"

//constructor for the node
Node::Node(const int&info) {
  data = info;
  next = null;
}

//constructor for the LinkedList
LinkedList::LinkedList() {
  this -> head = nullptr;
}

void LinkedList::insertAtBegin(int data) {
  Node * newNode = new Node(data);
  if (head == nullptr) {
    head = newNode;
    head -> next = nullptr;
    return;
  }
  newNode -> = head;
  head = newNode;
}

void LinkedList::insertAtEnd(int data) {
  Node *newNode = new Node(data);
  if (head == nullptr) {
    head = newNode;
    head -> next = nullptr;
    return;
  }
  Node *temp = head;
  while (temp -> next != nullptr) {
    temp = temp -> next;
  }
  temp -> next = newNode;
  newNode -> next = nullptr;
}
