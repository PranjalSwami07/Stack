/* Implement a function call management system using a stack to track active
function calls and their memory usage.Perform the following operations:
1. 2. 3. Push a function call onto the stack.
Display the function at the top of the stack.
Remove the completed function call from the stack.
4. Search active function call*/

#include <climits>
#include <iostream>
#include <string>
using namespace std;

struct node {
  string functionName;
  int memoryUsage;
  node *next;
};

class FunctionStack {
  node *top;

public:
  FunctionStack();

  void push(string f, int memory);
  void pop();
  void peek();
  bool isEmpty();
  void search(string f);
  void display();
};