// spec file for Time class
#if !defined(TIME_H)
#define TIME_H

class Time {
protected:
   int hour;
   int min;
   int sec;
public:
   // default constructor
   Time() { hour = 0;  min = 0;  sec = 0; }
   // constructor
   Time(int h, int m, int s) { hour = h, min = m, sec = s; }

   // accessors
   int getHour() const { return hour; }
   int getMin() const { return min; }
   int getSec() const { return sec; }
};

#endif // TIME_H
