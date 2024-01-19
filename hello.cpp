// A simple c++ program
#include <iostream>

using namespace std;

int main() {
   const int SIZE = 5;
   int numbers[5] = { 1,1,1,1,1 };
   int anumbers = ++numbers[3];
   
   int bnumbers = numbers[4]++;
   cout << anumbers << endl;

}