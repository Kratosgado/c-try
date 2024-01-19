// This program writes data to a file
#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ofstream outputFile;
   outputFile.open("demofile.txt");

   cout << "Now writing data to the file.\n";

   // Writing four names to the file
   outputFile << "Mbeah\n";
   outputFile << "kratos\n";
   outputFile << "gado\n";

   // Close the file
   outputFile.close();
   cout << "Done." << endl;
   return 0;
}