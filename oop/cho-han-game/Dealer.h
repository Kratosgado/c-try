// Specification file for the Dealer class
#ifndef DEALER_H
#define DEALER_H

#include <string>
#include "Die.h"
using namespace std;

class Dealer {
private:
   Die die1;
   Die die2;
   int die1Value;
   int die2Value;
public:
   Dealer();
   void rollDice();
   string getChoOrHan();
   int getDie1Value();
   int getDie2Value();
};

#endif // DEALER_H
