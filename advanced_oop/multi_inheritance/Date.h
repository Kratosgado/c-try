// spec file for Date class
#if !defined(DATE_H)
#define DATE_H

class Date {
protected:
   int day;
   int month;
   int year;
public:
   // default constructor
   Date() {
      day = 1; month = 1; year = 1900;
   }
   // constructor
   Date(int d, int m, int y) {
      day = d; month = m; year = y;
   }

   // accessors
   int getDay() const { return day; }
   int getMonth() const { return month; }
   int getYear() const { return year; }
};

#endif // DATE_H
