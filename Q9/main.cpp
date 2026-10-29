#include "undo.h"

int main() {
  TextUndoStack undoStack;
  int choice;
  string action;

  do {
    cout << "\n=== TEXT EDITOR UNDO SYSTEM ===" << endl;
    cout << "1. Perform Action (Push)" << endl;
    cout << "2. Undo Last Action (Pop)" << endl;
    cout << "3. View Last Action (Peek)" << endl;
    cout << "4. Show Action History (Display)" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter action description (e.g., Typed 'Hello', Deleted "
              "paragraph): ";
      cin.ignore();
      getline(cin, action);
      undoStack.push(action);
      break;

    case 2:
      undoStack.pop();
      break;

    case 3:
      action = undoStack.peek();
      if (action != "") {
        cout << "Most Recent Action: \"" << action << "\"" << endl;
      }
      break;

    case 4:
      undoStack.display();
      break;

    case 5:
      cout << "Exiting program." << endl;
      break;

    default:
      cout << "Invalid choice! Please select between 1 and 5." << endl;
    }
  } while (choice != 5);

  return 0;
}