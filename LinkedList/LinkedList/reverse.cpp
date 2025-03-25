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

Node *reverse(Node *head)
{
  Node *prev = nullptr;
  Node *curr = head;
  Node *next = nullptr;
  while (curr != nullptr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
  return head;
}

int main()
{
  Node *head = nullptr;
  return 0;
}