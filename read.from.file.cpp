# include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream inputFile;
   string name;

   inputFile.open("demofile.txt");
   cout << "Reading data from the file." << endl;

   inputFile >> name;  // read name 1 from the file
   cout << name << endl; // display it

   inputFile >> name;
   cout << name << endl;

   inputFile.close();
   return 0;
}