/**
*	@file Test.cpp
*	@author Emilio Miles
*	@date 2019.11.18
*/

#include "Test.h"
#include "Queue.h"
#include <iostream>
using namespace std;

Test::Test()
{

}

void Test::alltests()
{
  cout<<"Starting tests...\n";
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
}

void Test::print(bool test)
{
  if(test == true)
  {
    cout<<"PASSED\n";
  }
  else
  {
    cout<<"FAILED\n";
  }
}

void Test::test1()
{
  Queue q;
  bool test = false;
  if(q.isEmpty())
  {
    test = true;
  }
  cout<<"Test 1: Newly created queue is empty: ";
  print(test);
}

void Test::test2()
{
  Queue q;
  bool test = false;
  q.enqueue(42);
  if(!q.isEmpty())
  {
    test = true;
  }
  cout<<"Test 2: Enqueing a value makes the Queue not empty: ";
  print(test);
}

void Test::test3()
{
  Queue q;
  bool test = false;
  q.enqueue(42);
  if(q.peekFront() == 42)
  {
    test = true;
  }
  cout<<"Test 3: Enqueing 42 on an empty queue then peekFront returns 42: ";
  print(test);
}

void Test::test4()
{
  Queue q;
  bool test = false;
  q.enqueue(42);
  q.dequeue();
  if(q.isEmpty())
  {
    test = true;
  }
  cout<<"Test 4: Enqueing a value and dequeing it makes the Queue empty: ";
  print(test);
}

void Test::test5()
{
  Queue q;
  bool test = false;
  q.enqueue(42);
  q.enqueue(5);
  if(q.peekFront() == 42)
  {
    test = true;
  }
  int x = q.peekFront();
  cout<<"Test 5: Enqueing 2 values on an empty queue then peekFront returns the correct front value: ";
  print(test);
  cout<<"Value of peekFront(): "<<x<<" --- should be 42\n";
}

void Test::test6()
{
  Queue q;
  bool test = false;
  q.enqueue(42);
  q.dequeue();
  try
  {
    q.dequeue();
  }
  catch(std::runtime_error e)
  {
    test = true;
  }
  cout<<"Test 6: Enqueing one value, then dequeing twice returns an error: ";
  print(test);
}

void Test::test7()
{
  Queue q;
  bool test = false;
  q.enqueue(42);
  q.enqueue(5);
  q.enqueue(21);
  q.enqueue(23);
  q.dequeue();
  if(q.peekFront() == 5)
  {
    test = true;
  }
  int x = q.peekFront();
  cout<<"Test 7: Enqueing 4 values on an empty queue, dequeing one dequeues the front value: ";
  print(test);
  cout<<"Value of peekFront(): "<<x<<" --- should be 5\n";
}

void Test::test8()
{
  Queue q;
  bool test = false;
  if(q.isEmpty())
  {
    test = true;
  }
  cout<<"Test 8: Newly created queue is empty, peekFront returns error: ";
  print(test);
}

void Test::test9()
{
  Queue q;
  bool test = false;
  q.enqueue(42);
  q.enqueue(5);
  q.enqueue(21);
  q.enqueue(23);
  q.~Queue();
  if(q.isEmpty())
  {
    test = true;
  }
  cout<<"Test 9: Calling destructor deletes all entries in queue: ";
  print(test);
}
