#include "postfix_infix.h"

Stack ::Stack() { top = NULL; }

bool Stack ::isEmpty() { return top == NULL; }

void Stack ::push(string str) {
  node *nn = new node;
  nn->data = str;
  nn->next = top;
  top = nn;
}

void Stack ::pop() {
  if (isEmpty()) {
    cout << "Satck is Empty" << endl;
  }
  node *temp = top;
  top = top->next;
  delete temp;
}
string Stack ::peek() {
  if (isEmpty()) {
    cout << "Stack is Empty." << endl;
  }
  return top->data;
}

bool isOperand(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9')) {
    return true;
  }
  return false;
}

bool isOperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
    return true;
  }
  return false;
}

// Main logic: Convert Postfix to Infix
string postfixToInfix(string postfix) {
  Stack stack;

  for (int i = 0; i < postfix.length(); i++) {
    char current = postfix[i];

    // Ignore spaces
    if (current == ' ') {
      continue;
    }

    // If character is operand, push it as a single-character string onto stack
    if (isOperand(current)) {
      string op(1, current);
      stack.push(op);
    }
    // If character is an operator, pop two operands and construct infix
    // expression
    else if (isOperator(current)) {
      if (stack.isEmpty()) {
        return "Invalid Postfix Expression!";
      }
      string op2 = stack.peek(); // Second operand
      stack.pop();

      if (stack.isEmpty()) {
        return "Invalid Postfix Expression!";
      }
      string op1 = stack.peek(); // First operand
      stack.pop();

      // Form parenthesized infix expression: (op1 operator op2)
      string exp = "(" + op1 + current + op2 + ")";
      stack.push(exp);
    }
  }

  // Final result will be at the top of the stack
  string result = stack.peek();
  stack.pop();

  if (!stack.isEmpty()) {
    return "Invalid Postfix Expression!";
  }

  return result;
}