#include <iostream>
#include <thread>
#include <bits/stdc++.h>
using namespace std;

int A[1000], B[1000], C[1000];

void vectorSum(int TID)
{
  int UB, LB, sizeOfThread;
  sizeOfThread = 250;
  LB = sizeOfThread * TID; // 250 * 0 = 0, 250 * 1 = 250, 250 * 2 = 500, 250 * 3 = 750
  UB = LB + sizeOfThread;  // 0 + 250 = 250, 250 + 250 = 500, 500 + 250 = 750, 750 + 250 = 1000
  for (int j = LB; j < UB; j++)
  { // 0-250, 250-500, 500-750, 750-1000
    C[j] = A[j] + B[j];
  }
};

int main()
{
  thread T[4];
  int threadSize = sizeof(T) / sizeof(T[0]);
  for (int i = 0; i < 1000; i++)
  {
    A[i] = i;
    B[i] = i;
  }

  for (int i = 0; i < threadSize; i++)
  {
    T[i] = thread(vectorSum, i);
  }
  for (int i = 0; i < threadSize; i++)
  {
    T[i].join();
  }

  for (int i = 0; i < 1000; i++)
  {
    cout << C[i] << endl;
  }
  return 0;
}