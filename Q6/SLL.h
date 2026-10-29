/* Write a program to implement a stack using a linked list that supports
retrieving the minimum element from SLL. Perform the following operations:
1. 2. 3. 4. Push: Insert a new element at the top of the stack.
Pop: Remove the top element from the stack.
Get Minimum: Retrieve the minimum element.
Display: Display all elements in the stack.*/

#include <iostream>
#include <string>

using namespace std;

// Node structure storing data, minimum up to this node, and next pointer
struct Node {
  int data;
  int minData;
  Node *next;
};

// Stack implementation supporting O(1) Get Minimum
class MinStack {
private:
  Node *topNode;

public:
  MinStack();
  ~MinStack();
  void push(int value);
  void pop();
  int getMin();
  bool isEmpty();
  void display();
};
