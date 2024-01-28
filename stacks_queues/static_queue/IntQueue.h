// spec file for IntQue class
#if !defined(INTQUEUE_H)
#define INTQUEUE_H

class IntQueue {
private:
   int* queueArray;
   int queueSize;
   int front;
   int rear;
   int numItems;
public:
   // constructor
   IntQueue(int);
   // copy constructor
   IntQueue(const IntQueue&);
   // desctructor
   ~IntQueue();

   // queue operations
   void enqueue(int);
   void dequeue(int&);
   bool isEmpty() const;
   bool isFull() const;
   void clear();
};

#endif // INTQUEUE_H
