#include <iostream>
using namespace std;

class Stack
{
  int top;
  int arr[100];
  int capacity;

public:
  Stack(int size = 100)
  {
    capacity = size;
    top = -1;
  }

  void push(int x)
  {
    if (top >= capacity - 1)
    {
      cout << "stack overflow\n";
      return;
    }
    arr[++top] = x;
    cout << x << " pushed into the stack\n";
  }

  int pop()
  {
    if (top < 0)
    {
      cout << "stack underflow\n";
      return -1;
    }
    return arr[top--];
  }

  int peek()
  {
    if (top < 0)
    {
      cout << "stack is empty\n";
      return -1;
    }
    return arr[top];
  }

  bool isEmpty()
  {
    return top < 0;
  }

  int stackSize()
  {
    return top + 1;
  }
};

int main()
{
  Stack s(5); // 5
  s.push(5);
  s.push(6);
  s.push(7);
  s.push(8);
  s.push(9);
  s.push(10); // overflow check
  // s.pop();
  cout << "top = " << s.peek() << "\n";
  cout << "is empty? " << s.isEmpty() << "\n";
  cout << "size = " << s.stackSize();
  return 0;
}