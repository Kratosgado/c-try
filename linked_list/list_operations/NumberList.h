// specification file for the NumberList class
#if !defined(NUMBERLIST_H)
#define NUMBERLIST_H

class NumberList {
private:
   struct ListNode {
      double value;              // the value in this node
      struct ListNode* next;     // to point to the next node
   };
   ListNode* head;               // List head pointer

public:
   // constructor
   NumberList(/* args */) { head == nullptr; }
   // destructor
   ~NumberList();

   // linked list operations
   void appendNode(double);
   void insertNode(double);
   void deleteNode(double);
   void displayList() const;
};

void NumberList::appendNode(double num) {
   ListNode* newNode; // to point to a new node
   ListNode* nodePtr;   // to move through the list

   // allocate a new node and store num there
   newNode = new ListNode;
   newNode->value = num;
   newNode->next = nullptr;

   // if there are no nodes in the list, make newNode the firstNode
   if (!head) head = newNode;
   else {
      // initialize nodePtr to head of list.
      nodePtr = head;

      // find the last node in the list
      while (nodePtr->next) nodePtr = nodePtr->next;

      // insert newNode as the last node
      nodePtr->next = newNode;

   }
}

#endif // NUMBERLIST_H
