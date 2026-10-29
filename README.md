# Stack

Implementations and practical applications of the Stack data structure using Linked Lists in C++.

## Problems Directory

| Folder | Problem Description | Data Structure | Key Operations / Concepts |
| :--- | :--- | :--- | :--- |
| **stack** | Core Stack Implementation | Singly Linked List | Basic operations: Push, Pop, Peek, IsEmpty, Display |
| **Q1** | Plate Stack Simulation | Linked List | Simulating real-world stack of plates: Push, Pop, Peek top plate, Display |
| **Q2** | Function Call Management System | Linked List | Call stack tracker: Push call with memory usage, Pop completed call, Peek, Search active call |
| **Q3** | Infix to Postfix Conversion | Linked List | Infix mathematical expression to postfix conversion using operator precedence and associativity |
| **Q4** | Postfix to Infix Conversion | Linked List | Reconstructing fully parenthesized infix expression from postfix notation |
| **Q5** | Infix to Prefix Conversion | Linked List | Infix expression to prefix conversion using string reversal and stack transformation |
| **Q6** | Stack with Get Minimum Element | Singly Linked List (SLL) | Push, Pop, Get Minimum element retrieval, Display |
| **Q7** | Infix Expression Evaluation | Linked List | Infix expression evaluation using postfix conversion and arithmetic computation |
| **Q9** | Text Editor Undo Operation | Linked List | Storing user actions, Pop to perform Undo, Peek latest action, History display |
| **Q10** | Palindrome Checker | Linked List | Push characters, Pop and compare against original string, Palindrome verification |

## Build & Run

To compile and run any problem (for example, Q1):

```bash
cd Q1
g++ main.cpp plate_stack.cpp -o solution
./solution
```

For other problems, compile `main.cpp` together with the respective `.cpp` implementation file (e.g., `plate.cpp`, `infix_postfix.cpp`, `undo.cpp`, etc.).
