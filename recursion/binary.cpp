// // This program demonstrates the recursive binarySearch function.
// #include <iostream>
// using namespace std;
// // Function prototype
// int binarySearch(int[], int, int, int);
// const int SIZE = 20; // Array size

// int main() {
//    // Define an array of employee ID numbers
//    int tests[SIZE] = { 101, 142, 147, 189, 199, 207, 222,
//    234, 289, 296, 310, 319, 388, 394,
//    417, 429, 447, 521, 536, 600 };
//    int empID;
//    // To hold an ID number
//    int results; // To hold the search results
//    // Get an employee ID number to search for.
//    cout << "Enter the Employee ID you wish to search for: ";
//    cin >> empID;
//    // Search for the ID number in the array.
//    results = binarySearch(tests, 0, SIZE  - 1, empID);
//    // Display the results of the search.
//    if (results == - 1)
//       cout << "That number does not exist in the array.\n";
//    else {
//       cout << "That ID is found at element " << results;
//       cout << " in the array\n";
//    }
//    return 0;
// }

// int binarySearch(int array[], int first, int last, int value) {
//    int middle;
//    if (first > last) return -1;
//    middle = (first + last) / 2;
//    if (array[middle] == value) return middle;
//    if (array[middle] < value) return binarySearch(array, middle + 1, last, value);
//    else return binarySearch(array, first, middle - 1, value);
// }

