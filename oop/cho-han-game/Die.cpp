// implementation file for the Die class
#include <cstdlib>
#include <ctime>
#include "Die.h"

Die::Die(int numSides) {
   // get the system time
   unsigned seed = time(0);

   // seed the random number generator
   srand(seed);

   // set the number of sides
   sides = numSides;
   // Perform an initial roll
   roll();
}

void Die::roll() {
   const int MIN_VALUE = 1;

   // get a random value for the die
   value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}

int Die::getSides() { return sides; }
int Die::getValue() { return value; }