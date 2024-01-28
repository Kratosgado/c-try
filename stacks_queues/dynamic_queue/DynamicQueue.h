#if !defined(DYNAMICQUEUE_H)
#define DYNAMICQUEUE_H

#include <iostream>

template<class T>
class DynamicQueue
{
private:
   struct QueueNode
   {
      T value;
      QueueNode* next;
   };
   QueueNode* front;
   QueueNode* rear;
   int numItems;

public:
   DynamicQueue();
   ~DynamicQueue();

   // Queue operations
   void enqueue(T);
   void dequeue(T&);
   bool isEmpty() const;
   void clear();
};

template <class T>
DynamicQueue<T>::DynamicQueue() {
   front = rear = nullptr, numItems = 0;
}

template<class T>
DynamicQueue<T>::~DynamicQueue() { clear(); }

template<class T>
void DynamicQueue<T>::enqueue(T item) {
   QueueNode* newNode = nullptr;

   newNode = new QueueNode;
   newNode->value = item;
   newNode->next = nullptr;

   // Adjust front and rear as necessary
   if (isEmpty()) {
      front = newNode;
      rear = newNode;
   }
   else {
      rear->next = newNode;
      rear = newNode;
   }

   numItems++;
}

template <class T>
void DynamicQueue<T>::dequeue(T& item) {
   QueueNode* temp = nullptr;
   if (isEmpty()) {
      std::cout << "The queue is empty.\n";
   }
   else {
      // save the front node value in num
      item = front->value;
      // remove the front node and delete it.
      temp = front;
      front = front->next;
      delete temp;
      numItems--;
   }
}

template <class T>
bool DynamicQueue<T>::isEmpty() const {
   return (numItems > 0) ? false : true;
}

template <class T>
void DynamicQueue<T>::clear() {
   T value; // dummy variable for dequeue
   while (!isEmpty())
   {
      dequeue(value);
   }
   
}

#endif // DYNAMICQUEUE_H
