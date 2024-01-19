// This program defines a function that finds the highest number in an array
#include <iostream>
using namespace std;

int findHighest(const int[], const  int);

int main() {
   const int ARRAY_SIZE = 8;
   int numbers[ARRAY_SIZE] = { 5, 10, 15, 20, 25, 30, 35, 40 };

   cout << "The highest of ";
   for (int number : numbers) {
      cout << " " << number << " ";
   }
   cout << "is " << findHighest(numbers, ARRAY_SIZE) << endl;

}

int findHighest(int numbers[], int size) {
   int highest = -1000000;
   for (int index = 0; index < size; index++) {
      highest = numbers[index] > highest ? numbers[index] : highest;
   }
   return highest;
}