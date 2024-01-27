// impl file for the IntStack
#include <iostream>
#include "IntStack.h"
using namespace std;

IntStack::IntStack(int size) {
   stackArray = new int[size];
   stackSize = size;
   top = -1;
}

IntStack::IntStack(const IntStack& obj) {
   // create the stack array
   if (obj.stackSize > 0) stackArray = new int[obj.stackSize];
   else stackArray = nullptr;

   stackSize = obj.stackSize;

   for (int count = 0; count < stackSize; count++)
      stackArray[count] = obj.stackArray[count];

   // set the top of the stack
   top = obj.top;
}

IntStack::~IntStack() { delete[] stackArray; }

void IntStack::push(int num) {
   if (isFull()) cout << "The stack is full.\n";
   else {
      top++;
      stackArray[top] = num;
   }
}

// pops the value at the top and copies it into the variable passed as an argument
void IntStack::pop(int& num) {
   if (isEmpty()) cout << "The stack is empty.\n";
   else {
      num = stackArray[top];
      top--;
   }
}

// I said oh naa, let's try som'n else
bool IntStack::isFull() const {
   return (top == stackSize - 1) ? true : false;
}


bool IntStack::isEmpty() const {
   return (top == -1) ? true : false;
}