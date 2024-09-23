#include "list.h"

//constructor for the node
Node::Node(const int&info) {
  data = info;
  next = nullptr;
}

//Function to access the data in the node.
int Node::getData() {
  return this->data;
}
