#ifdef LIST_H
#include <iostream>

class Node {

  public:
    Node (const int &info);
    int getData(const int&);

  private:
    int data;
    Node *next;

};


class LinkedList {

  public:
    LinkedList();
    void insertAtBegin(int data);
    void insertAtEnd(int data);

  private:
    Node * head;
};

#endif // LIST_H
