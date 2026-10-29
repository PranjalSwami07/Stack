/* Write a program to convert a given postfix mathematical expression into its
equivalent Infix expression using a stack.*/

#include <iostream>
#include <string>
using namespace std;

struct node {
  string data;
  node *next;
};

class Stack {
  node *top;

public:
  Stack();
  void push(string str);
  void pop();
  string peek();
  bool isEmpty();
};

bool isOperand(char ch);
bool isOperator(char ch);
string postfixToInfix(string postfix);
