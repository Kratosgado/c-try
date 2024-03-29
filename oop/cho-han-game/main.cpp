// this program simulates the game of cho-han
#include <iostream>
#include "Dealer.h"
#include "Player.h"
using namespace std;

// function prototypes
void roundResults(Dealer&, Player&, Player&);
void checkGuess(Player&, Dealer&);
void displayGrandWinner(Player, Player);

int main() {
   const int MAX_ROUNDS = 5;
   string player1Name;
   string player2Name;

   cout << "Enter the first player's name: ";
   cin >> player1Name;
   cout << "Enter the second player's name: ";
   cin >> player2Name;

   Dealer dealer;

   Player player1(player1Name);
   Player player2(player2Name);

   // play the rounds
   for (int round = 0; round < MAX_ROUNDS; round++) {
      cout << "----------------------------\n"
         << "Now playing round " << (round + 1) << endl;

      dealer.rollDice();

      // the players make their guesses
      player1.makeGuess();
      player2.makeGuess();

      // Determine the winner of this round.
      roundResults(dealer, player1, player2);
   }
   // display the grand winner
   displayGrandWinner(player1, player2);
   return 0;

}

void roundResults(Dealer& dealer, Player& player1, Player& player2) {
   // show the dice values.
   cout << "The dealer rolled " << dealer.getDie1Value() << "and" << dealer.getDie2Value() << endl;

   // show the result (Cho or Han)
   cout << "Result: " << dealer.getChoOrHan() << endl;

   // check each player's guess and award points
   checkGuess(player1, dealer);
   checkGuess(player2, dealer);
}

void checkGuess(Player& player, Dealer& dealer) {
   const int POINTS_TO_ADD = 1;

   string guess = player.getGuess();

   // get the result (Cho or Han)
   string choHanResult = dealer.getChoOrHan();

   // display the player's guess
   cout << "The player " << player.getName() << " guessed " << player.getGuess() << endl;

   // award points if the player guessed correctly
   if (guess == choHanResult) {
      player.addPoints(POINTS_TO_ADD);
      cout << "Awarding " << POINTS_TO_ADD << " point(s) to " << player.getName() << endl;
   }
}

void displayGrandWinner(Player player1, Player player2) {
   cout << "----------------------------\n"
      << "Game over. Here are the results:\n"
      << player1.getName() << ": " << player1.getPoints() << " points\n"
      << player2.getName() << ": " << player2.getPoints() << " points\n";

   if (player1.getPoints() > player2.getPoints()) cout << player1.getName() << " is the grand winner!\n";
   else if (player2.getPoints() > player1.getPoints())  cout << player2.getName() << " is the grand winner!\n";
   else cout << "Both players are tied!\n";
}