/* Write a program to implement the undo operation in a text editor using a
stack. Perform the following operations:
1. 2. 3. 4. Push: Store a new action in the stack.
Pop: Remove the most recent action to perform undo.
Peek: Display the most recent action without removing it.
Display: Show the current history.*/

#include <iostream>
#include <string>

using namespace std;

// Structure to represent a single text editing action
struct Node {
  string actionText;
  Node *next;
};

// Class to manage editor history using a Stack
class TextUndoStack {
private:
  Node *topNode;

public:
  TextUndoStack();
  ~TextUndoStack();
  void push(string action);
  void pop();
  string peek();
  bool isEmpty();
  void display();
};
