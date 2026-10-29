#include "postfix_infix.h"

using namespace std;

int main() {
  int choice;
  string postfixExp;

  do {
    cout << "\n=== POSTFIX TO INFIX CONVERTER ===" << endl;
    cout << "1. Convert Postfix to Infix" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter postfix expression (e.g., ABC*+): ";
      cin.ignore();
      getline(cin, postfixExp);
      cout << "Postfix Expression: " << postfixExp << endl;
      cout << "Infix Expression  : " << postfixToInfix(postfixExp) << endl;
      break;

    case 2:
      cout << "Exiting program." << endl;
      break;

    default:
      cout << "Invalid choice! Please enter 1 or 2." << endl;
    }
  } while (choice != 2);

  return 0;
}