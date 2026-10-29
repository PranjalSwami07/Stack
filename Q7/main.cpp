
#include "infix_postfix.h"
using namespace std;

int main() {
  int choice;
  string infixExp;

  do {
    cout << "\n=== INFIX TO POSTFIX CONVERSION ===" << endl;
    cout << "1. Convert Infix to Postfix" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter infix expression (e.g., A+(B*C)): ";
      cin.ignore();
      getline(cin, infixExp);
      cout << "Infix Expression  : " << infixExp << endl;
      cout << "Postfix Expression: " << infixToPostfix(infixExp) << endl;
      break;

    case 2:
      cout << "Exiting program." << endl;
      break;

    default:
      cout << "Invalid choice! Choose 1 or 2." << endl;
    }
  } while (choice != 2);

  return 0;
}