/*Write a program to Evaluate a given infix expression into its equivalent
prefix expression using a stack. */

#include <iostream>
#include <string>

using namespace std;

// Node structure for character stack
struct Node {
  char data;
  Node *next;
};

// Stack implementation for operator characters
class CharStack {
private:
  Node *topNode;

public:
  CharStack();
  ~CharStack();
  void push(char ch);
  void pop();
  char peek();
  bool isEmpty();
};

// Function declarations for infix to prefix conversion
int getPrecedence(char op);
bool isOperand(char ch);
string reverseString(string str);
string infixToPrefix(string infix);
