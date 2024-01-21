// Specification file for the IntegerList class
#ifndef INTEGERLIST_H
#define INTEGERLIST_H

class IntegerList {
private:
   int* list;
   int numElements;
   bool isValid(int) const;
public:
   IntegerList(int);
   ~IntegerList();
   void setElement(int, int);
   void getElement(int, int&) const;
   int getElement(int) const;
};

#endif