// spec file for DateTime class
#if !defined(DATETIME_H)
#define DATETIME_H

#include <string>
#include "Date.h"
#include "Time.h"
using namespace std;

class DateTime : public Date, public Time {
public:
   // default constructor
   DateTime();
   // constructor
   DateTime(int, int, int, int, int, int);

   // displayes date and time
   void showDateTime() const;
};

#endif // DATETIME_H
