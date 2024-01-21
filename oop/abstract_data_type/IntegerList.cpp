// implementation file for the IntergerList class
#include <iostream>
#include <cstdlib>
#include "IntegerList.h"
using namespace std;

IntegerList::IntegerList(int size) {
   list = new int[size];
   numElements = size;
   for (int ndx = 0; ndx < size; ndx++)
   {
      list[ndx] = 0;
   }  
}


bool IntegerList::isValid(int element) const {
   if (element < 0 || element >= numElements) {
      return false;
   }
   return true;
}

void IntegerList::setElement(int element, int value) {
   if (isValid(element)) list[element] = value;
   else {
      cout << "Error: Invalid subscript\n";
      exit(EXIT_FAILURE);
   }
}

int IntegerList::getElement(int element) const {
   if (isValid(element)) return list[element];
   cout << "Error: Invalid subscript\n";
   exit(EXIT_FAILURE);
}

// get element overload
void IntegerList::getElement(int element, int& value) const {
   if (isValid(element)) value = list[element];
   else {
      cout << "Error: Invalid subscript\n";
      exit(EXIT_FAILURE);
   }

}

IntegerList::~IntegerList() {
   delete[] list;
}
