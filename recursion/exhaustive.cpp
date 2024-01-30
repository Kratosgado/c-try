// This program demonstrates a recursive function that exhaustively
// searches through all possible combinations of coin values to find
// the best way to make change for a specified amount.
#include <iostream>
using namespace std;

// constants
const int MAX_COINS_CHANGE = 100;
const int MAX_COIN_VALUES = 6;
const int NO_SOLUTION = INT8_MAX;    // indicates no solution

// function prototype
void makeChange(int, int, int[], int);

// coinValues - global array of coin values to choose from
int coinValues[MAX_COIN_VALUES] = { 100, 50, 25, 10, 5 ,1 };

// bestCoins - global array of best coins to make change with 
int bestCoins[MAX_COINS_CHANGE];

// global variables
int numBestCoins = NO_SOLUTION,
numSolutions = 0,  // number of ways 
numCoins;         // number of allowable coins

int main() {
   int coinsUsed[MAX_COINS_CHANGE],    // list of coins used
      numCoinsUsed = 0,    // the number of coins used
      amount;      // the amount to make change for

   // Display the possible coin values.
   cout << "Here are the valid coin values, in cents: ";
   for (int index = 0; index < 5; index++)
      cout << coinValues[index] << " ";
   cout << endl;
   // Get input from the user.
   cout << "Enter the amount of cents (as an integer) "
      << "to make change for: ";
   cin >> amount;
   cout << "What is the maximum number of coins to give as change? ";
   cin >> numCoins;
   // Call the recursive function.
   makeChange(numCoins, amount, coinsUsed, numCoinsUsed);
   // Display the results.
   cout << "Number of possible combinations: " << numSolutions << endl;
   cout << "Best combination of coins:\n";
   if (numBestCoins == NO_SOLUTION)
      cout << "\tNo solution\n";

   else {
      for (int count = 0; count < numBestCoins; count++)
         cout << bestCoins[count] << " ";
   }
   cout << endl;
   return 0;
}


//***********************************************************************
 // Function makeChange. This function uses the following parameters:   *
 // coinsLeft − The number of coins left to choose from.                *
 // amount − The amount to make change for.                             *
 // coinsUsed − An array that contains the coin values used so far.     *
 // numCoinsUsed − The number of values in the coinsUsed array.         *
 //                                                                     *
 // This recursive function finds all the possible ways to make change  *
 // for the value in amount. The best combination of coins is stored in *
 // the array bestCoins.                                                *
 //**********************************************************************

void makeChange(int coinsLeft, int amount, int coinsUsed[], int numCoinsUsed) {
   int coinPos, // to calculate array position of coin being used
      count; // loop counter
   if (coinsLeft == 0 || amount < 0) return;
   else if (amount == 0) { // if solution is found
      // store as best coins if best
      if (numCoinsUsed < numBestCoins) {
         for ( count = 0; count < numCoinsUsed; count++)
         {
            bestCoins[count] = coinsUsed[count];
         }
         numBestCoins = numCoinsUsed;
      }
      numSolutions++;
      return;
   }

   // find the other combinations using the coin 
   coinPos = numCoins - coinsLeft;
   coinsUsed[numCoinsUsed] = coinValues[coinPos];
   numCoinsUsed++;
   makeChange(coinsLeft, amount - coinValues[coinPos], coinsUsed, numCoinsUsed);

   // find the other combinations not using the coin
   numCoinsUsed--;
   makeChange(coinsLeft - 1, amount, coinsUsed, numCoinsUsed);
}