#include "infix_postfix.h"

Stack ::Stack() { top = NULL; }

bool Stack ::isEmpty() { return top == NULL; }

void Stack ::push(char ch) {
  node *nn = new node;
  nn->data = ch;
  nn->next = top;
  top = nn;
}

void Stack ::pop() {
  if (isEmpty()) {
    return;
  }
  node *temp = top;
  top = top->next;
  delete temp;
}

char Stack ::peek() {
  if (isEmpty()) {
    cout << "Stack is empty!" << endl;
  }
  return top->data;
}

int precedence(char op) {
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
bool isOperand(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0')) {
    return true;
  }
  return false;
}

string infixToPostfix(string infix) {
  Stack s;
  string postfix = "";

  for (int i = 0; i < infix.length(); i++) {
    char current = infix[i];
    if (current == ' ') {
      continue;
    }
    if (isOperand(current)) {
      postfix += current;
    } else if (current == '(') {
      s.push(current);
    } else if (current == ')') {
      while (!s.isEmpty() && s.peek() != '(') {
        postfix += s.peek();
        s.pop();
      }
      if (!s.isEmpty() && s.peek() == '(') {
        s.pop();
      }

    } else {
      while (!s.isEmpty() && precedence(s.peek()) >= precedence(current)) {
        postfix += s.peek();
        s.pop();
      }
      s.push(current);
    }
  }
  while (!s.isEmpty()) {
    postfix += s.peek();
    s.pop();
  }
  return postfix;
}