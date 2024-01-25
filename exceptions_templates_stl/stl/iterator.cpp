// // this demonstrates iterator
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//    int count;
//    vector<int> vect;

//    // define an iterator object
//    vector<int>::iterator iter;

//    // use push_back to push values into the vector
//    for (count = 0; count < 10; count++) vect.push_back(count);

//    // step the iterator through the vector, and use it to display the vector's contents
//    cout << "Here are the values in vect: ";
//    for (iter = vect.begin(); iter < vect.end(); iter++) {
//       cout << *iter << " ";
//    }
//    // Step the iterator through the vector backwards.
//    cout << "\nand here they are backwards: ";
//    for (iter = vect.end() -1; iter >= vect.begin(); iter--) {
//       cout << *iter << " ";
//    }
//    return 0;

// }