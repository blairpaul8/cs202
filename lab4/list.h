
#include <iostream>

class Node {

  public:
    Node (const int &info);
    int getData();
    Node *next;
  
  private:
    int data;

};


/*class LinkedList {

  public:
    LinkedList();
    void insertAtBegin(int data);
    void insertAtEnd(int data);

  private:
    Node * head;
};
*/

