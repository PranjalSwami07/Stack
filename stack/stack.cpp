#include "stack.h"

Stack ::Stack() { top = NULL; }

bool Stack ::isEmpty() { return top == NULL; }

void Stack ::push(int value) {
  node *nn = new node;
  nn->data = value;
  nn->next = top;
  top = nn;
}

void Stack ::pop() {
  if (isEmpty()) {
    cout << "Stack is empty" << endl;
    return;
  }
  node *temp = top;
  top = top->next;
  delete temp;
}

int Stack ::peek() {
  if (isEmpty()) {
    cout << "Stack is empty";
    return INT_MIN;
  }
  return top->data;
}

void Stack ::display() {
  if (isEmpty()) {
    cout << "Stack is empty";
    return;
  }
  node *temp = top;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}