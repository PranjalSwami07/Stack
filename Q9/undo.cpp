#include "undo.h"

// Constructor
TextUndoStack::TextUndoStack() { topNode = nullptr; }

// Destructor
TextUndoStack::~TextUndoStack() {
  while (!isEmpty()) {
    pop();
  }
}

// Check if stack is empty
bool TextUndoStack::isEmpty() { return topNode == nullptr; }

// 1. Push: Store a new action in the stack
void TextUndoStack::push(string action) {
  Node *newNode = new Node();
  newNode->actionText = action;
  newNode->next = topNode;
  topNode = newNode;
  cout << "Action stored: \"" << action << "\"" << endl;
}

// 2. Pop: Remove the most recent action to perform undo
void TextUndoStack::pop() {
  if (isEmpty()) {
    cout << "Nothing to undo! History stack is empty." << endl;
    return;
  }
  Node *temp = topNode;
  cout << "Undo performed: Removed action \"" << temp->actionText << "\""
       << endl;
  topNode = topNode->next;
  delete temp;
}

// 3. Peek: Display the most recent action without removing it
string TextUndoStack::peek() {
  if (isEmpty()) {
    cout << "History stack is empty! No recent action." << endl;
    return "";
  }
  return topNode->actionText;
}

// 4. Display: Show the current action history
void TextUndoStack::display() {
  if (isEmpty()) {
    cout << "Action history is empty." << endl;
    return;
  }
  cout << "\n--- CURRENT ACTION HISTORY (Most Recent First) ---" << endl;
  Node *temp = topNode;
  int step = 1;
  while (temp != nullptr) {
    cout << step << ". " << temp->actionText << endl;
    temp = temp->next;
    step++;
  }
  cout << "---------------------------------------------------" << endl;
}