#include "palindrome.h"

using namespace std;

// Constructor
CharStack::CharStack() { topNode = nullptr; }

// Destructor
CharStack::~CharStack() {
  while (!isEmpty()) {
    pop();
  }
}

// Check if stack is empty
bool CharStack::isEmpty() { return topNode == nullptr; }

// 1. Push: Insert character at top of stack
void CharStack::push(char ch) {
  Node *newNode = new Node();
  newNode->data = ch;
  newNode->next = topNode;
  topNode = newNode;
}

// 2. Pop: Remove top character from stack
void CharStack::pop() {
  if (isEmpty()) {
    return;
  }
  Node *temp = topNode;
  topNode = topNode->next;
  delete temp;
}

// 3. Peek: View top character of stack without removing it
char CharStack::peek() {
  if (isEmpty()) {
    return '\0';
  }
  return topNode->data;
}

// Display elements in the stack
void CharStack::display() {
  if (isEmpty()) {
    cout << "Stack is empty." << endl;
    return;
  }
  cout << "Stack contents (Top to Bottom): ";
  Node *temp = topNode;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// 4. Function to check whether string is Palindrome or Not
bool isPalindrome(string str) {
  CharStack stack;

  // Step 1: Push each character of string onto stack
  for (int i = 0; i < str.length(); i++) {
    stack.push(str[i]);
  }

  // View top element using peek before pop processing
  cout << "Top element before comparison (peek): '" << stack.peek() << "'"
       << endl;

  // Step 2: Pop characters from stack and compare with original string
  // sequentially
  for (int i = 0; i < str.length(); i++) {
    char topChar = stack.peek();
    stack.pop();

    if (str[i] != topChar) {
      return false; // Character mismatch found
    }
  }

  return true; // All characters matched
}