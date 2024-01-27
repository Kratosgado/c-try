// spec file for the InsStack class
#if !defined(INTSTACK_H)
#define INTSTACK_H

class IntStack {
private:
   int* stackArray;
   int stackSize;
   int top;
public:
   // constructor
   IntStack(int);
   // copy constructor
   IntStack(const IntStack&);
   // destructor
   ~IntStack();

   // stack operations
   void push(int);
   void pop(int&);
   bool isFull() const;
   bool isEmpty() const;

};

#endif // INTSTACK_H
