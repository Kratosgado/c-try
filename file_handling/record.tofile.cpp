// This program uses a structure variable to store a record to a file
#include <iostream>
#include <fstream>
using namespace std;

// array sizes
const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;

// Declare a structure for the record.
struct Info {
   char name[NAME_SIZE];
   int age;
   char address1[ADDR_SIZE];
   char address2[ADDR_SIZE];
   char phone[PHONE_SIZE];
};

int main() {
   Info person;
   char again;

   // open a file for binary output.
   fstream people("people.dat", ios::out | ios::binary);

   do {
      // get data about a person.
      cout << "Enter the following data about a person:\n";
      cout << "Name: ";
      cin.getline(person.name, NAME_SIZE);
      cout << "Age: ";
      cin >> person.age;
      cin.ignore(); // skip over the remaining newline.
      cout << "Addres line 2: ";
      cin.getline(person.address2, ADDR_SIZE);
      cout << "Phone: ";
      cin.getline(person.phone, PHONE_SIZE);

      // write the contents of the person structure to the file.
      people.write(reinterpret_cast<char*>(&person), sizeof(person));

      // determine whether the user wants to write another record.
      cout << "Do you want to  enter another record? ";
      cin >> again;
      cin.ignore(); // skip over the remaining newline.
   } while (again == 'Y' || again == 'y');

   // close the file
   people.close();
   return 0;
}