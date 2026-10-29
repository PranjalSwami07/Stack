#include "plate_stack.h"

int main() {
  PlateStack ps;
  int choice;
  string plate;
  do {
    cout << "\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter plate name: ";
      cin >> plate;
      ps.push(plate);
      break;
    case 2:
      ps.pop();
      break;
    case 3:
      cout << "Top plate: " << ps.peek() << endl;
      break;
    case 4:
      ps.display();
      break;
    case 5:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice" << endl;
    }
  } while (choice != 5);
  return 0;
}