// A simple c++ program
#include <iostream>

using namespace std;

int main() {
   const int SIZE = 5;
   int numbers[5];

   // get values for the array
   for (int& val : numbers) {
      cout << "enter an interger value: ";
      cin >> val;
   }

   // display the values in the array
   cout << "Here are the values you entered: " << endl;
   for (int val : numbers) {
      cout << val << endl;
   }

}