#include "SLL.h"

using namespace std;

// Constructor
MinStack::MinStack() { topNode = nullptr; }

// Destructor
MinStack::~MinStack() {
  while (!isEmpty()) {
    pop();
  }
}

// Check if stack is empty
bool MinStack::isEmpty() { return topNode == nullptr; }

// 1. Push: Insert a new element at top of stack
void MinStack::push(int value) {
  Node *newNode = new Node();
  newNode->data = value;

  // Track minimum value up to the current node
  if (isEmpty()) {
    newNode->minData = value;
  } else {
    newNode->minData = (value < topNode->minData) ? value : topNode->minData;
  }

  newNode->next = topNode;
  topNode = newNode;
  cout << value << " pushed onto stack." << endl;
}

// 2. Pop: Remove top element from stack
void MinStack::pop() {
  if (isEmpty()) {
    cout << "Stack Underflow! No elements to pop." << endl;
    return;
  }
  Node *temp = topNode;
  cout << temp->data << " popped from stack." << endl;
  topNode = topNode->next;
  delete temp;
}

// 3. Get Minimum: Retrieve current minimum element in O(1) time
int MinStack::getMin() {
  if (isEmpty()) {
    cout << "Stack is empty! No minimum element." << endl;
    return INT_MIN;
  }
  return topNode->minData;
}

// 4. Display: Display all elements in stack
void MinStack::display() {
  if (isEmpty()) {
    cout << "Stack is empty." << endl;
    return;
  }

  cout << "\n--- CURRENT STACK (Top to Bottom) ---" << endl;
  Node *temp = topNode;
  while (temp != nullptr) {
    cout << "| Data: " << temp->data
         << " | (Min at this level: " << temp->minData << ") |" << endl;
    temp = temp->next;
  }
  cout << "------------------------------------" << endl;
}