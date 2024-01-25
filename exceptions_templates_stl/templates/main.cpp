// This program demonstrates the SimpleVector template.
#include <iostream>
#include "SimpleVector.h"
#include "SearchableVector.h"
using namespace std;

int main() {
   const int SIZE = 10;
   int count;
   int result;

   // create two searchable objects
   SearchableVector<int> intTable(SIZE);
   SearchableVector<double> doubleTable(SIZE);

   // store values in the two 
   for (count = 0; count < SIZE; count++) {
      intTable[count] = (count * 2);
      doubleTable[count] = (count * 2.14);
   }
   // Display the values in the simple vectors
   cout << "These values are in intTable:\n";
   for (count = 0; count < SIZE; count++) {
      cout << intTable[count] << " ";
   }
   cout << endl;

   // search for the value 6 in intTable
   cout << "\nSearching for 6 in intTable.\n";
   result = intTable.findItem(6);
   if (result == -1) cout << "6 was not found in intTable.\n";
   else cout << "6 was found at subscript " << result << endl;

   // Search for the value 12.84 in doubleTable.
   cout << "\nSearching for 12.84 in doubleTable.\n";
   result = doubleTable.findItem(12.84);
   if (result == -1)
      cout << "12.84 was not found in doubleTable.\n";
   else
      cout << "12.84 was found at subscript " << result << endl;
   return 0;
}