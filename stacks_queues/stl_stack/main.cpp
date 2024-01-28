// this program demonstrates the stl stack container adapter
#include <iostream>
#include <vector>
#include <stack> // errors

int main() {
   const int MAX = 8;
   int count;

   // define an stl stack
   std::stack<int, std::vector<int>> iStack;

   // push values onto the stack
   for ( count = 2; count < MAX; count+=2)
   {
      std::cout << "Pushing " << count << std::endl;
      iStack.push(count);
   }

   std::cout << "The size of the stack is " << iStack.size() << std::endl;

   for ( count = 2; count < MAX; count+=2)
   {
      std::cout << "Popping " << iStack.top() << std::endl;
      iStack.pop();
   }
   return 0;

}