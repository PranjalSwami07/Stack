#include "infix_postfix.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  int choice;
  string infixExp;

  do {
    cout << "\n=== INFIX TO POSTFIX CONVERTER ===" << endl;
    cout << "1. Convert Infix to Postfix" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter infix expression (e.g., A+B*(C-D)): ";
      cin.ignore();
      getline(cin, infixExp);
      cout << "Infix Expression  : " << infixExp << endl;
      cout << "Postfix Expression: " << infixToPostfix(infixExp) << endl;
      break;

    case 2:
      cout << "Exiting program." << endl;
      break;

    default:
      cout << "Invalid choice! Please choose 1 or 2." << endl;
    }
  } while (choice != 2);

  return 0;
}