#include "list.h"

//constructor for the node
Node::Node(const int&info) {
  data = info;
  next = nullptr;
}

//constructor for the Nodes
int Node::getData() {
  return this->data;
}
