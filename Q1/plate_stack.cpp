#include "plate_stack.h"

PlateStack ::PlateStack() { topNode = NULL; }

void PlateStack ::push(string plate) {
  node *nn = new node();
  nn->plateName = plate;
  nn->next = topNode;
  topNode = nn;
  cout << "Plate added in stack" << endl;
}

void PlateStack ::pop() {
  if (isEmpty()) {
    cout << "Underflow" << endl;
    return;
  }
  node *temp = topNode;
  cout << "Plate removed from stack" << endl;
  topNode = topNode->next;
  delete temp;
}

string PlateStack ::peek() {
  if (isEmpty()) {
    cout << "The Stack is Empty" << endl;
    return "";
  }
  return topNode->plateName;
}

void PlateStack ::display() {
  if (isEmpty()) {
    cout << "The Stack is empty" << endl;
    return;
  }
  cout << "----------Current Nodes:----------" << endl;
  node *temp = topNode;
}