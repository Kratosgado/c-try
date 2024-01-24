// spec file for CsStudent class
#if !defined(CSSTUDENT_H)
#define CSSTUDENT_H

#include "Student.h"

// constants for required hours
const int MATH_HOURS = 20;
const int CS_HOURS = 40;
const int GEN_ED_HOURS = 60;

class CsStudent : public Student
{
private:
   int mathHours;
   int csHours;
   int genEdHours;

public:
   CsStudent() : Student() {
      mathHours = 0;
      csHours = 0;
      genEdHours = 0;
   }

   // constructor
   CsStudent(string n, string id, int year) : Student(n, id, year) {
      mathHours = 0;
      csHours = 0;
      genEdHours = 0;
   }

   // mutator functions
   void setMathHours(int mh) { mathHours = mh; }
   void setCsHours(int csh) { csHours = csh; }
   void setGenEdHours(int geh) { genEdHours = geh; }

   // overrides getRemainingHours function in base class
   virtual int getRemainingHours() const;
};


#endif // CSSTUDENT_H
