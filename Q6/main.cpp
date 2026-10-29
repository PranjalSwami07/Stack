#include "SLL.h"

int main() {
  MinStack stack;
  int choice, value;

  do {
    cout << "\n=== MIN STACK MENU ===" << endl;
    cout << "1. Push Element" << endl;
    cout << "2. Pop Element" << endl;
    cout << "3. Get Minimum Element" << endl;
    cout << "4. Display Stack" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter integer value to push: ";
      cin >> value;
      stack.push(value);
      break;

    case 2:
      stack.pop();
      break;

    case 3:
      value = stack.getMin();
      if (value != INT_MIN) {
        cout << "Current Minimum Element in Stack: " << value << endl;
      }
      break;

    case 4:
      stack.display();
      break;

    case 5:
      cout << "Exiting program." << endl;
      break;

    default:
      cout << "Invalid choice! Please choose between 1 and 5." << endl;
    }
  } while (choice != 5);

  return 0;
}