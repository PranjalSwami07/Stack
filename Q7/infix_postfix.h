/* Write a program to Evaluate a given infix expression into its equivalent
postfix expression using a stack.*/

#include <iostream>
#include <string>

using namespace std;

// Structure for character stack node
struct Node {
  char data;
  Node *next;
};

// Class for dynamic character stack
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

// Function declarations for infix to postfix conversion
int getPrecedence(char op);
bool isOperand(char ch);
string infixToPostfix(string infix);
