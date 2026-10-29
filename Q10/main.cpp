#include "palindrome.h"

int main() {
  int choice;
  string inputStr;

  do {
    cout << "\n=== PALINDROME CHECKER USING STACK ===" << endl;
    cout << "1. Check String for Palindrome" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter a string: ";
      cin.ignore();
      getline(cin, inputStr);

      if (isPalindrome(inputStr)) {
        cout << "Result: \"" << inputStr << "\" is a Palindrome." << endl;
      } else {
        cout << "Result: \"" << inputStr << "\" is NOT a Palindrome." << endl;
      }
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