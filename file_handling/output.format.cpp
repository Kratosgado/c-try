// This program uses the setprecision and fixed manipulators to format file output
#include <iostream>
#include<iomanip>
#include <fstream>
using namespace std;

int main() {
   fstream dataFile;
   double num = 17.816392;
   dataFile.open("numfile.txt", ios::out);

   dataFile << fixed << num << endl;
   dataFile << setprecision(4) << num << endl;
   dataFile << setprecision(3) << num << endl;

   cout << "Done.\n";
   dataFile.close();
   return 0;
}