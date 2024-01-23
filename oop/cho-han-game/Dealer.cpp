// Implementation file for Dealer class
#include "Dealer.h"
#include "Die.h"
#include <string>
using namespace std;

Dealer::Dealer() {
   // set the initial dice values to 0
   die1Value = 0;
   die2Value = 0;
}

void Dealer::rollDice() {
   // roll the dice.
   die1.roll();
   die2.roll();

   // save the dice values.
   die1Value = die1.getValue();
   die2Value = die2.getValue();
}

string Dealer::getChoOrHan() {
   string result;

   int sum = die1Value + die2Value;

   if (sum % 2 == 0) result = "Cho (even)";
   else result = "Han (odd)";

   return result;
}

int Dealer::getDie1Value() { return die1Value; }
int Dealer::getDie2Value() { return die2Value; }