#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;

// int count = 0;
atomic<int> count(0);

// RAII lock is also there

mutex mtx;
void aman()
{
  for (int i = 0; i < 250000; i++)
  {
    // this_thread::sleep_for(chrono::seconds(1)); // on hold
    // mtx.lock();
    count++;
    // mtx.unlock();
  }
}

int main()
{
  thread T[2];

  for (int i = 0; i < 2; i++)
  {
    T[i] = thread(aman);
  }

  for (int i = 0; i < 2; i++)
  {
    T[i].join(); // join blocks the main thread
                 // T[i].detach(); // detach executes concurrently since two threads are working on a single
                 // function this will not give an expected value.
  }

  cout << count;

  return 0;
}