// impl file for the IntQueue class
#include <iostream>
#include "IntQueue.h"
using namespace std;

IntQueue::IntQueue(int s) {
   queueArray = new int[s];
   queueSize = s;
   front = -1;
   rear = -1;
   numItems = 0;
}

IntQueue::IntQueue(const IntQueue& obj) {
   queueSize = obj.queueSize;
   queueArray = new int[queueSize];
   front = obj.front;
   rear = obj.rear;
   numItems = obj.numItems;

   // copy the other object's queue array
   for (int count = 0; count < queueSize; count++)
   {
      queueArray[count] = obj.queueArray[count];
   }
}

IntQueue::~IntQueue() { delete[] queueArray; }

void IntQueue::enqueue(int num) {
   if (isFull()) cout << "The queue is full.\n";
   else {
      // calculate the new rear position
      rear = (rear + 1) % queueSize;
      // insert new item
      queueArray[rear] = num;
      numItems++;
   }
}

void IntQueue::dequeue(int& num) {
   if (isEmpty()) cout << "The queue is empty.\n";
   else {
      // move front
      front = (front + 1) % queueSize;
      // retrieve the front item
      num = queueArray[front];
      numItems--;
   }
}

bool IntQueue::isEmpty() const {
   return numItems ? false : true;
}

bool IntQueue::isFull() const {
   return (numItems < queueSize) ? false : true;
}

void IntQueue::clear() {
   front = queueSize - 1;
   rear = queueSize - 1;
   numItems = 0;
}