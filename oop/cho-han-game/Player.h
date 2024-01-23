// specification file for the Player class
#if !defined(PLAYER_H)
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
private:
   string name;
   string guess;
   int point;
public:
   Player(string);
   void makeGuess();
   void addPoints(int);
   string getName();
   string getGuess();
   int getPoints();
};


#endif // PLAYER_H
