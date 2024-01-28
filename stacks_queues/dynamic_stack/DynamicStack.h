#if !defined(DYNAMICSTACK_H)
#define DYNAMICSTACK_H

template <class T>
class DynamicStack
{
private:
   struct StackNode
   {
      T value;
      StackNode* next;
   };
   StackNode* top;

public:
   DynamicStack() { top = nullptr; }
   ~DynamicStack();

   void push(T);
   void pop(T&);
   bool isEmpty();
};

template<class T>
DynamicStack<T>::~DynamicStack() {
   StackNode* nodePtr = nullptr, * nextNode = nullptr;

   // position nodePtr at the top of the stack
   nodePtr = top;

   // traverse the list deleteing each node.
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }
   
}

template <class T>
void DynamicStack<T>::push(T num) {
   StackNode* newNode = nullptr;

   newNode = new StackNode;
   newNode->value = num;

   if (isEmpty()) {
      top = newNode;
      newNode->next = nullptr;
   }
   else {
      newNode->next = top;
      top = newNode;
   }
}

template<class T>
void DynamicStack<T>::pop(T& num) {
   StackNode* temp = nullptr; // temporary pointer
   if (isEmpty()) std::cout << "The stack is empty.\n";
   else {
      num = top->value;
      temp = top->next;
      delete top;
      top = temp;
   }
}

template<class T>
bool DynamicStack<T>::isEmpty() {
   return (!top) ? true : false;
}

#endif // DYNAMICSTACK_H
