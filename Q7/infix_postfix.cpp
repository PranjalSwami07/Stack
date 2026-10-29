#include "infix_postfix.h"

// Constructor
CharStack::CharStack() { topNode = nullptr; }

// Destructor
CharStack::~CharStack() {
  while (!isEmpty()) {
    pop();
  }
}

// Check if stack is empty
bool CharStack::isEmpty() { return topNode == nullptr; }

// Push element onto stack
void CharStack::push(char ch) {
  Node *newNode = new Node();
  newNode->data = ch;
  newNode->next = topNode;
  topNode = newNode;
}

// Pop top element from stack
void CharStack::pop() {
  if (isEmpty()) {
    return;
  }
  Node *temp = topNode;
  topNode = topNode->next;
  delete temp;
}

// Peek top element of stack
char CharStack::peek() {
  if (isEmpty()) {
    return '\0';
  }
  return topNode->data;
}

// Return operator precedence
int getPrecedence(char op) {
  if (op == '+' || op == '-') {
    return 1;
  }
  if (op == '*' || op == '/') {
    return 2;
  }
  if (op == '^') {
    return 3;
  }
  return 0;
}

// Check if character is operand (alphanumeric)
bool isOperand(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9')) {
    return true;
  }
  return false;
}

// Convert Infix to Postfix expression
string infixToPostfix(string infix) {
  CharStack opStack;
  string postfix = "";

  for (int i = 0; i < infix.length(); i++) {
    char current = infix[i];

    if (current == ' ') {
      continue;
    }

    // If operand, add directly to postfix output
    if (isOperand(current)) {
      postfix += current;
    }
    // If '(', push to stack
    else if (current == '(') {
      opStack.push(current);
    }
    // If ')', pop to postfix until '('
    else if (current == ')') {
      while (!opStack.isEmpty() && opStack.peek() != '(') {
        postfix += opStack.peek();
        opStack.pop();
      }
      if (!opStack.isEmpty() && opStack.peek() == '(') {
        opStack.pop();
      }
    }
    // If operator, handle precedence rules
    else {
      while (!opStack.isEmpty() &&
             getPrecedence(opStack.peek()) >= getPrecedence(current)) {
        postfix += opStack.peek();
        opStack.pop();
      }
      opStack.push(current);
    }
  }

  // Pop remaining operators from stack
  while (!opStack.isEmpty()) {
    postfix += opStack.peek();
    opStack.pop();
  }

  return postfix;
}