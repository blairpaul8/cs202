
#include <iostream>

class Node {

  public:
    Node (const int &info);
    int getData();
    Node *next;
  
  private:
    int data;

};
