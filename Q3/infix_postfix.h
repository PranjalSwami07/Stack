/* Write a program to convert a given infix mathematical expression into its
equivalent postfix expression using a stack.*/

#include <iostream>
#include <string>

using namespace std;

struct node {
  char data;
  node *next;
};
class Stack {
  node *top;

public:
  Stack();
  void push(char ch);
  void pop();
  char peek();
  bool isEmpty();
};
int precedence(char op);
bool isOpernand(char ch);
string infixToPostfix(string infix);