// This program expolores sorting algorithms, specifically
// bubble and selection sorts

#include <iostream>

using namespace std;

void bubbleSort(int[], int);
void selection(int[], int);

int main() {
   const int SIZE = 5;
   int numbers[SIZE] = { 3 ,5,2,9,4 };

   bubbleSort(numbers, SIZE);
   for (auto num : numbers) {
      cout << num;
   }


}

// sort by comparing and swapping two adjacent values
void bubbleSort(int array[], int size) {
   bool swap;
   int temp;

   do {
      swap = false;
      for (int count = 0; count < (size - 1); count++) {
         if (array[count] > array[count + 1]) {
            temp = array[count];
            array[count] = array[count + 1];
            array[count + 1] = temp;
            swap = true;
         }
      }
   } while (swap);

}

void selection(int array[], int size) {
   int startScan;
   int minIndex;
   int minValue;
   for (startScan = 0; startScan < (size - 1); startScan++) {
      minIndex = startScan;
      minValue = array[startScan];

      for (int index = startScan + 1; index < size; index++) {
         if (array[index] < minValue) {
            minValue = array[index];
            minIndex = index;
         }
      }
      array[minIndex] = array[startScan];
      array[startScan] = minValue;
   }

}