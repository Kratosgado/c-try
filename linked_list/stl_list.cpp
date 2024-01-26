// This program demonstrates the STL list container
#include <iostream>
#include <list>         // include the list header
using namespace std;

int main() {
   list<int> myList;

   list<int>::iterator iter;     // iterator for the list
   for (int x = 0; x < 100; x += 10) myList.push_back(x);

   for (iter = myList.begin(); iter != myList.end(); iter++)cout << *iter << " ";
   cout << endl;

   // now reverse the order of the elements
   myList.reverse();

   for (iter = myList.begin(); iter != myList.end(); iter++)cout << *iter << " ";
   cout << endl;
   return 0;
}