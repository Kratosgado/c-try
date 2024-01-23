#ifndef FEETINCHES_H
#define FEETINCHES_H
#include <iostream>
using namespace std;

class FeetInches;

// function prototypes for overloaded stream operators
ostream& operator<< (ostream&, const FeetInches&);
istream& operator>> (istream&, FeetInches&);

class FeetInches {
private:
   int feet;
   int inches;
   void simplify();
public:
   FeetInches(int f = 0, int i = 0) {
      feet = f;
      inches = i;
      simplify();
   }
   void setFeet(int f) { feet = f; }
   void setInches(int i) {
      inches = i;
      simplify();
   }
   int getFeet() const {
      return feet;
   }
   int getInches() const {
      return inches;
   }

   // overloaded operator functions
   FeetInches operator + (const FeetInches&);
   FeetInches operator- (const FeetInches&);
   FeetInches operator ++(); // prefix
   FeetInches operator -- (int); // postfix
   bool operator > (const FeetInches&);
   bool operator < (const FeetInches&);
   bool operator == (const FeetInches&);
   int& operator[](const int&);

      // friends
      friend ostream& operator << (ostream&, const FeetInches&);
      friend istream& operator >> (istream&, FeetInches&);


   // Accessor functions
   ~FeetInches();
};



FeetInches::~FeetInches() {
}


#endif