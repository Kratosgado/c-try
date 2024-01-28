// spec file for the mathStack class
#if !defined(MATHSTACK_H)
#define MATHSTACK_H

#include "IntStack.h"

class MathStack: public IntStack
{
public:
   MathStack(int s ): IntStack(s) {}

   void add();
   void sub();
};

#endif // MATHSTACK_H
