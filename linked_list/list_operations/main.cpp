// this program demonstrates a simple append operation on a linked list
#include <iostream>
#include "NumberList.h"
using namespace std;

int main() {
   // Define a numberList object
   NumberList list;

   list.appendNode(2.5);
   list.appendNode(7.9);
   list.appendNode(12.6);

   list.insertNode(10.5);
   list.deleteNode(7.9);

   list.displayList();
   return 0;
}