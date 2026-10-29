#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  Stack myStack;
  int choice, value;

  do {
    cout << "\n--- STACK MENU ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek (Top Element)\n";
    cout << "4. Display\n";
    cout << "5. Check Empty\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value to push: ";
      cin >> value;
      myStack.push(value);
      break;

    case 2:
      myStack.pop();
      break;

    case 3:
      value = myStack.peek();
      if (value != INT_MIN) {
        cout << "Top element is: " << value << endl;
      }
      break;

    case 4:
      myStack.display();
      break;

    case 5:
      if (myStack.isEmpty()) {
        cout << "Stack is empty." << endl;
      } else {
        cout << "Stack is not empty." << endl;
      }
      break;

    case 6:
      cout << "Exiting program..." << endl;
      break;

    default:
      cout << "Invalid choice! Please try again." << endl;
    }
  } while (choice != 6);

  return 0;
}