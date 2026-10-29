#include "infix_prefix.h"

CharStack::CharStack() { topNode = nullptr; }

// Destructor
CharStack::~CharStack() {
  while (!isEmpty()) {
    pop();
  }
}

// Check if stack is empty
bool CharStack::isEmpty() { return topNode == nullptr; }

// Push a character onto the stack
void CharStack::push(char ch) {
  Node *newNode = new Node();
  newNode->data = ch;
  newNode->next = topNode;
  topNode = newNode;
}

// Pop top character from the stack
void CharStack::pop() {
  if (isEmpty()) {
    return;
  }
  Node *temp = topNode;
  topNode = topNode->next;
  delete temp;
}

// Peek top character of the stack
char CharStack::peek() {
  if (isEmpty()) {
    return '\0';
  }
  return topNode->data;
}

// Helper function: Return precedence of operators
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

// Helper function: Check if character is operand (alphanumeric)
bool isOperand(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9')) {
    return true;
  }
  return false;
}

// Helper function: Reverse a string manually without extra headers
string reverseString(string str) {
  string rev = "";
  for (int i = str.length() - 1; i >= 0; i--) {
    rev += str[i];
  }
  return rev;
}

// Main logic: Convert Infix to Prefix
string infixToPrefix(string infix) {
  // Step 1: Reverse the infix expression and swap brackets '(' <-> ')'
  string reversedInfix = "";
  for (int i = infix.length() - 1; i >= 0; i--) {
    char current = infix[i];
    if (current == '(') {
      reversedInfix += ')';
    } else if (current == ')') {
      reversedInfix += '(';
    } else {
      reversedInfix += current;
    }
  }

  // Step 2: Convert reversed infix to modified postfix expression
  CharStack opStack;
  string output = "";

  for (int i = 0; i < reversedInfix.length(); i++) {
    char current = reversedInfix[i];

    if (current == ' ') {
      continue;
    }

    if (isOperand(current)) {
      output += current;
    } else if (current == '(') {
      opStack.push(current);
    } else if (current == ')') {
      while (!opStack.isEmpty() && opStack.peek() != '(') {
        output += opStack.peek();
        opStack.pop();
      }
      if (!opStack.isEmpty() && opStack.peek() == '(') {
        opStack.pop();
      }
    } else {
      // Operator logic (for prefix, right-associativity gets > precedence
      // handle)
      while (!opStack.isEmpty() &&
             getPrecedence(opStack.peek()) > getPrecedence(current)) {
        output += opStack.peek();
        opStack.pop();
      }
      opStack.push(current);
    }
  }

  while (!opStack.isEmpty()) {
    output += opStack.peek();
    opStack.pop();
  }

  // Step 3: Reverse the modified postfix string to get prefix
  string prefix = reverseString(output);
  return prefix;
}