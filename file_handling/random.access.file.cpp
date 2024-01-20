// This program randomly reads a record of data from a file.
#include <iostream>
#include <fstream>
using namespace std;

const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;
// Declare a structure for the record.
struct Info {
   char name[NAME_SIZE];
   int age;
   char address1[ADDR_SIZE];
   char address2[ADDR_SIZE];
   char phone[PHONE_SIZE];
};
// Function Prototypes
long byteNum(int);
void showRec(Info);

int main() {
   Info person;
   fstream people;
   // To hold info about a person
   // File stream object
   // Open the file for input in binary mode.
   people.open("people.dat", ios::in | ios::binary);

   // test for errors   
   if (!people) {
      cout << "Error opening file. Program aborting.\n";
      return 0;
   }

   // read and display record 1 (the second record).
   cout << "Here is record 1: \n";
   people.seekg(byteNum(1), ios::beg);
   people.read(reinterpret_cast<char*>(&person), sizeof(person));
   showRec(person);

   // read and display record 0 (the first record).
   cout << "\n Here is record 0: \n";
   people.seekg(byteNum(0), ios::beg);
   people.read(reinterpret_cast<char*>(&person), sizeof(person));
   showRec(person);

   // close the file
   people.close();
   return 0;

}

//************************************************************
// Definition of function byteNum. Accepts an integer as     *
// its argument. Returns the byte number in the file of the  *
// record whose number is passed as the argument.            *
//************************************************************

long byteNum(int recNum) {
   return sizeof(Info) * recNum;
}

//************************************************************
// Definition of function showRec. Accepts an Info structure *
// as its argument, and displays the structure's contents.   *
//************************************************************
void showRec(Info record) {
   cout << "Name: ";
   cout << record.name << endl;
   cout << "Age: ";
   cout << record.age << endl;
   cout << "Address line 1: ";
   cout << record.address1 << endl;
   cout << "Address line 2: ";
   cout << record.address2 << endl;
   cout << "Phone: ";
   cout << record.phone << endl;
}