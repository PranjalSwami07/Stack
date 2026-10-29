#include "plate.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  FunctionStack callStack;
  int choice, memory;
  string funcName;

  do {
    cout << "\n=== FUNCTION CALL MANAGEMENT SYSTEM ===" << endl;
    cout << "1. Push Function Call" << endl;
    cout << "2. Peek Top Function" << endl;
    cout << "3. Pop Completed Function" << endl;
    cout << "4. Search Active Function Call" << endl;
    cout << "5. Display Call Stack" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter function name: ";
      cin.ignore();
      getline(cin, funcName);
      cout << "Enter memory usage (in KB): ";
      cin >> memory;
      callStack.push(funcName, memory);
      break;

    case 2:
      callStack.peek();
      break;

    case 3:
      callStack.pop();
      break;

    case 4:
      cout << "Enter function name to search: ";
      cin.ignore();
      getline(cin, funcName);
      callStack.search(funcName);
      break;

    case 5:
      callStack.display();
      break;

    case 6:
      cout << "Exiting system..." << endl;
      break;

    default:
      cout << "Invalid choice! Please try again." << endl;
    }
  } while (choice != 6);

  return 0;
}