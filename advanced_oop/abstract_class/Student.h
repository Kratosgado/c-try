// Specification file for Student class
#if !defined(STUDENT_H)
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
protected:
   string name;
   string idNumber;
   int yearAdmitted;
public:
   // default constructor
   Student() {
      name = "";
      idNumber = "";
      yearAdmitted = 0;
   }
   // constructor
   Student(string n, string id, int year) { set(n, id, year); }

   void set(string n, string id, int year) {
      name = n; idNumber = id, year = year;
   }

   // accessor function
   const string getName() const { return name; }
   const string getIdNum() const { return idNumber; }
   const int getYearAdmitted() const { return yearAdmitted; }

   // pure virtual function(
   virtual int getRemainingHours() const = 0;

};

#endif // STUDENT_H
