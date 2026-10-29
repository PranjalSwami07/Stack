#include <climits>
#include <iostream>
#include <string>
using namespace std;

struct node {
  int data;
  node *next;
};

class Stack {
  node *top;

public:
  Stack();
  void push(int value);
  void pop();
  int peek();
  bool isEmpty();
  void display();
};