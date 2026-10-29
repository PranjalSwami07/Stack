/*Write a program to simulate a stack of plates using a stack data
structure.Perform the following operations:
1. Push: Add a plate to the top of the stack.
2. Pop: Remove the top plate from the stack.
3. Peek: Display the top plate without removing it.
4. Display: Display all plates in the stack.*/

#include <iostream>
#include <string>

using namespace std;

struct node {
  string plateName;
  node *next;
};

class PlateStack {
  node *topNode;

public:
  PlateStack();
  ~PlateStack();
  bool isEmpty();
  void push(string plate);
  void pop();
  string peek();
  void display();
};
