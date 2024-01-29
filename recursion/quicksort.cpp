// this program demonstrates the quick sort algorithm
#include <iostream>
using namespace std;

// function prototypes
void quickSort(int[], int, int);
int partition(int[], int, int);
void swap(int&, int&);

int main() {
   const int SIZE = 10; // Array size
   int count;
   // Loop counter
   int array[SIZE] = { 7, 3, 9, 2, 0, 1, 8, 4, 6, 5 };
   // Display the array contents.
   for (count = 0; count < SIZE; count++)
      cout << array[count] << " ";
   cout << endl;
   // Sort the array.
   quickSort(array, 0, SIZE - 1);
   // Display the array contents.
   for (count = 0; count < SIZE; count++)
      cout << array[count] << " ";
   cout << endl;
   return 0;
}

void quickSort(int set[], int start, int end) {
   int pivotPoint;
   if(start < end) {
      // get the pivot point
      pivotPoint = partition(set, start, end);
      // sort the first sublist
      quickSort(set, start, pivotPoint - 1);
      // sort the second sublist
      quickSort(set, pivotPoint + 1, end);
   }
}

int partition(int set[], int start, int end) {
   int pivotValue, pivotIndex, mid;
   mid = (start + end) / 2;
   swap(set[start], set[mid]);
   pivotIndex = start;
   pivotValue = set[start];
   for (int scan = start + 1; scan <= end; scan++)
   {
      if (set[scan] < pivotValue) {
         pivotIndex++;
         swap(set[pivotIndex], set[scan]);
      }
   }
   swap(set[start], set[pivotIndex]);
   return pivotIndex;
}

void swap(int& value1, int& value2) {
   int temp = value1;
   value1 = value2;
   value2 = temp;
}