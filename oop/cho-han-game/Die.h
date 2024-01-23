// specification file for the Die class
#ifndef DIE_H
#define DIE_H 

class Die {
private:
   int sides;
   int value;
public:
   Die(int = 6);
   void roll();
   int getSides();
   int getValue();
};
#endif