// spec file for the NumberList class
#if !defined(NUMBERLIST_H)
#define NUMBERLIST_H

#include <iostream>

class NumberList {
private:
   struct ListNode {
      double value;
      struct ListNode* next;
   };
   ListNode* head;

   // private functions
   int countNodes(ListNode*) const;
   void showReverse(ListNode*) const;

public:
   NumberList(/* args */) { head = nullptr; }
   ~NumberList();

   // linked list operations
   void appendNode(double);
   void insertNode(double);
   void deleteNode(double);
   void displayList() const;
   int numbNodes() const { return countNodes(head); }
   void displayBackwards() const { showReverse(head); }
};

int NumberList::countNodes(ListNode* nodePtr) const {
   if (nodePtr != nullptr) return 1 + countNodes(nodePtr->next);
   else return 0;
}

void NumberList::showReverse(ListNode* nodePtr) const {
   if (nodePtr != nullptr) {
      showReverse(nodePtr->next);
      std::cout << nodePtr->value << " ";
   }
}


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

void NumberList::insertNode(double num) {
   ListNode* newNode;          // a new node
   ListNode* nodePtr;         // to traverse the list
   ListNode* previousNode; // the previous node

   // allocate a new node and store num there
   newNode = new ListNode;
   newNode->value = num;

   if (!head) {
      head = newNode;
      newNode->next = nullptr;
   }
   else {
      // position nodePtr at the head of list
      nodePtr = head;
      previousNode = nullptr; // initialize previousNode to nullptr

      // skip all nodes whose value is less than num
      while (nodePtr != nullptr && nodePtr->value < num)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }
      // if the new node is to be the 1st in the list, insert it before all other nodes
      if (previousNode == nullptr) {
         head = newNode;
         newNode->next = nodePtr;
      }
      else { // otherwise insert after the previous node
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }

   }
}

void NumberList::deleteNode(double num) {
   ListNode* nodePtr;
   ListNode* previousNode;

   if (!head) return;
   if (head->value == num) {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else {
      // intiialize nodePtr to head of list
      nodePtr = head;
      while (nodePtr != nullptr && nodePtr->value != num)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }
      // if nodePtr is not at the end of the list
      // link the previos node to the  node after nodePtr, then delete nodePtr
      if (nodePtr) {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }
}

void NumberList::displayList() const {
   ListNode* nodePtr;
   nodePtr = head;
   while (nodePtr) {
      std::cout << nodePtr->value << std::endl;
      nodePtr = nodePtr->next; // move to the next node.
   }
}

NumberList::~NumberList() {
   ListNode* nodePtr;   // to traverse the list
   ListNode* nextNode;  // to point to the next node

   // position nodePtr at the head of the list
   nodePtr = head;

   // while nodePtr isnot at the end of the list
   while (nodePtr != nullptr)
   {
      // save a pointer to the next node
      nextNode = nodePtr->next;
      // delete the current node
      delete nodePtr;
      // position nodePtr at the next node
      nodePtr = nextNode;
   }
   
}

#endif // NUMBERLIST_H
