#include <iostream>
#include "CsStudent.h"
using namespace std;

int CsStudent::getRemainingHours() const {
   int reqHours, remainingHours;
   reqHours = MATH_HOURS + CS_HOURS + GEN_ED_HOURS;
   remainingHours = reqHours - (mathHours + csHours + genEdHours);
   return remainingHours;
}