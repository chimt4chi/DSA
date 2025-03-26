#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

bool checkWave(Node *head)
{
  Node *curr = head;
  while (curr->next != nullptr)
  {
    if (curr->data < curr->next->data && curr->next->data < curr->next->next->data)
      return false;
    else if (curr->data > curr->next->data && curr->next->data > curr->next->next->data)
      return false;
    else if (curr->data == curr->next->data || curr->next->data == curr->next->next->data)
      return false;
    curr = curr->next;
  }
  return true;
}

int main()
{
  Node *head = nullptr;
  // head = insertAtBack(head, 55);
  // head = insertAtBack(head, 25);
  return 0;
}