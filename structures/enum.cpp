// This program demonstrates an enumerated data type.
#include <iostream>
#include <iomanip>
using namespace std;

enum  Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };

// prototype function
void displayDayName(Day);


int main() {
   const int NUM_DAYS = 5;
   double sales[NUM_DAYS];
   double total = 0.0;
   Day workDay;

   // Get the sales for each day
   for (workDay = MONDAY; workDay <= FRIDAY; workDay = static_cast<Day> (workDay + 1)) {
      cout << "Enter the sales for day ";
      displayDayName(workDay);
      cout << ": ";
      cin >> sales[workDay];
   }
   // Calculate the total sales.
   for (workDay = MONDAY; workDay <= FRIDAY;
      workDay = static_cast<Day>(workDay + 1))
      total += sales[workDay];
   // Display the total.
   cout << "The total sales are $" << setprecision(2)
      << fixed << total << endl;
   return 0;
}

//**********************************************************
// Definition of the displayDayName function               *
// This function accepts an argument of the Day type and   *
// displays the corresponding name of the day.             *
//**********************************************************

void displayDayName(Day d) {
   switch (d) {
   case MONDAY: cout << "Monday";
      break;
      case TUESDAY
      : cout << "Tuesday";
         break;
      case WEDNESDAY: cout << "Wednesday";
         break;
      case THURSDAY: cout << "Thursday";
         break;
         case FRIDAY
         : cout << "Friday";
         default:
            break;
   }
}