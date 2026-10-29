#include "plate.h"

FunctionStack ::FunctionStack() { top = NULL; }

bool FunctionStack ::isEmpty() { return top == NULL; }

void FunctionStack ::push(string f, int memory) {
  node *nn = new node;
  nn->functionName = f;
  nn->memoryUsage = memory;
  nn->next = top;
  top = nn;
  cout << f << "is added" << endl;
}

void FunctionStack ::pop() {
  if (isEmpty()) {
    cout << "Stack is empty" << endl;
    return;
  }
  node *temp = top;
  cout << "Function" << temp->functionName << "removed" << endl;
  top = top->next;
  delete temp;
}

void FunctionStack ::peek() {
  if (isEmpty()) {
    cout << "Stack is empty" << endl;
    return;
  }
  cout << "Top Function :" << top->functionName << endl;
}

void FunctionStack ::search(string f) {
  if (isEmpty()) {
    cout << "Stack is empty" << endl;
    return;
  }

  node *temp = top;
  int position = 1;
  bool found = false;

  while (temp != NULL) {
    if (temp->functionName == f) {
      cout << "Function found." << endl;
      found = true;
      break;
    }
    temp = temp->next;
    position++;
  }
  if (!found) {
    cout << "Function not found!" << endl;
  }
}

void FunctionStack ::display() {
  if (isEmpty()) {
    cout << "Stack is empty" << endl;
    return;
  }
  node *temp = top;
  int totalMemory = 0;
  int position = 1;
  while (temp != NULL) {
    cout << "Function:" << temp->functionName << "|Memory" << temp->memoryUsage
         << " KB" << endl;
    temp = temp->next;
  }
  cout << "Total Memory Used by Active Calls: " << totalMemory << " KB" << endl;
}