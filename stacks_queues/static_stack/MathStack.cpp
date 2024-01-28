// impl file for MathStack class
#include "MathStack.h"

void MathStack::add() {
   int num, sum;

   // pop the first two values off the stack
   pop(sum);
   pop(num);

   sum += num;
   push(sum);
}

//***********************************************
// Member function sub. sub pops the            *
// first two values off the stack. The          *
// second value is subtracted from the          *
// first value. The difference is pushed        *
// onto the stack.                              *
//***********************************************
void MathStack::sub() {
   int num, diff;
   // Pop the first two values off the stack.
   pop(diff);
   pop(num);
   // Subtract num from diff.
   diff -= num;
   // Push diff back onto the stack.
   push(diff);
}