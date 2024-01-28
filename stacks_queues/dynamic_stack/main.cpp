// This program demonstrates the dynamic stack.
// class DynIntClass.
#include <iostream>
#include "DynamicStack.h"
using namespace std;



// Constants for the menu choices
const int PUSH_CHOICE = 1,
POP_CHOICE = 2,
QUIT_CHOICE = 3;

// function prototypes
void menu(int&);
void getStackSize(int&);
void pushItem(DynamicStack<string>&);
void popItem(DynamicStack<string>&);

int main() {
   int choice;
   DynamicStack<string> stack;

   do {
      menu(choice);
      if (choice != QUIT_CHOICE) {
         switch (choice) {
         case PUSH_CHOICE:
            pushItem(stack);
            break;
         case POP_CHOICE:
            popItem(stack);
         default:
            cout << "incorrect choice " << endl;
            break;
         }
      }
   } while (choice != QUIT_CHOICE);

   return 0;
}

//************************************************
 // The menu function displays the menu and gets  *
 // the user's choice, which is assigned to the   *
 // reference parameter.                          *
 //************************************************
void menu(int& choice) {
   // Display the menu and get the user's choice.
   cout << "What do you want to do?\n"
      << PUSH_CHOICE
      << " - Push an item onto the stack\n"
      << POP_CHOICE

      << " - Pop an item off the stack\n"

      << QUIT_CHOICE

      << " - Quit the program\n"

      << "Enter your choice: ";
   cin >> choice;
   // Validate the choice
   while (choice < PUSH_CHOICE || choice > QUIT_CHOICE)

   {

      cout << "Enter a valid choice: ";

      cin >> choice;

   }
}

void pushItem(DynamicStack<string>& stack) {
   string item;

   // get an item to push onto the stack
   cin.ignore();
   cout << "\nEnter an item: ";
   getline(cin, item);
   stack.push(item);
}

void popItem(DynamicStack<string>& stack) {
   string item = "";
   stack.pop(item);

   if(item != "") cout << item << " was popped.\n";
}