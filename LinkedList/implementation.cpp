#include <bits/stdc++.h>
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

Node *insertAtBack(Node *head, int x)
{
  Node *newNode = new Node(x);
  if (head == nullptr)
    return newNode;
  Node *temp = head;

  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

Node *insertAtFront(Node *head, int x)
{
  Node *newNode = new Node(x);
  if (head == nullptr)
    return newNode;

  newNode->next = head;
  head = newNode;
  return head;
}

Node *deleteNode(Node *head, int x)
{
  if (head == nullptr)
    return nullptr; // if head is null return null

  // if head is to be deleted.
  if (head->data == x)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  // traverse if temp->next doesnt contains the value
  Node *temp = head;
  while (temp->next != nullptr && temp->next->data != x)
  {
    temp = temp->next;
  }

  // if we reached the end of list and x not found
  if (temp->next == nullptr)
    return head;

  Node *toDelete = temp->next;
  temp->next = temp->next->next;
  delete toDelete;
  return head;
}

Node *rotate(Node *head, int k)
{
  if (!head || k == 0)
    return head;

  // Step 1: Find the length and tail
  Node *tail = head;
  int len = 1;
  while (tail->next)
  {
    tail = tail->next;
    len++;
  }

  // Step 2: Make the list circular
  tail->next = head;

  // Step 3: Find the new tail: (len - k % len - 1)th node
  k = k % len;
  int stepsToNewTail = len - k;
  Node *newTail = head;
  for (int i = 1; i < stepsToNewTail; i++)
  {
    newTail = newTail->next;
  }

  // Step 4: Set new head and break the loop
  Node *newHead = newTail->next;
  newTail->next = nullptr;

  return newHead;
}

void print(Node *head)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL\n";
}

int main()
{
  Node *head = nullptr;
  head = insertAtBack(head, 55);
  head = insertAtBack(head, 25);
  head = insertAtFront(head, 55);
  print(head);
  return 0;
}