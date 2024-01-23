// implementation file for the Player class
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <string>

Player::Player(string playerName) {
   // seed the random number generator
   srand(time(0));

   name = playerName;
   guess = "";
   point = 0;
}

void Player::makeGuess() {
   const int MIN_VALUE = 0;
   const int MAX_VALUE = 1;
   int guessNumber;

   // get a random number, either 0 or 1
   guessNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

   // convert the random number to Cho or Han
   if (guessNumber == 0) guess = "Cho (even)";
   else guess = "Han (odd)";
}

void Player::addPoints(int newPoints) { point += newPoints; }
string Player::getName() { return name; }
string Player::getGuess() { return guess; }
int Player::getPoints() { return point; }

