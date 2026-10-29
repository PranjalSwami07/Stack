/* Write a program to check whether a given string is a palindrome using a
stack. Implement functions to insert characters, remove the top character, and
access the top character. Perform the following operations:
1. 2. 3. 4. Push each character of the string onto the stack.
Pop characters from the stack and compare them with the original string.
Use the peek() function to view the top element of the stack.
Display whether the given string is a Palindrome or Not a Palindrome.*/

#include <iostream>
#include <string>

using namespace std;

// Structure to represent a single character node in SLL
struct Node {
  char data;
  Node *next;
};

// Class to implement Stack for character data
class CharStack {
private:
  Node *topNode;

public:
  CharStack();
  ~CharStack();
  void push(char ch);
  void pop();
  char peek();
  bool isEmpty();
  void display();
};

// Function declaration for Palindrome check
bool isPalindrome(string str);
