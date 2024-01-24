// impl file for DateTime class
#include <iostream>
#include "DateTime.h"

using namespace std;

// default constructor
DateTime::DateTime() : Date(), Time() {}

// constructor
DateTime::DateTime(int dy, int mon, int yr, int hr, int mt, int sc) :
   Date(dy, mon, yr), Time(hr, mt, sc) {
}

void DateTime::showDateTime() const {
   // Display the date in the form MM/DD/YYYY.
   cout << getMonth() << "/" << getDay() << "/" << getYear() << " ";
   // Display the time in the form HH:MM:SS.
   cout << getHour() << ":" << getMin() << ":" << getSec() << endl;
}