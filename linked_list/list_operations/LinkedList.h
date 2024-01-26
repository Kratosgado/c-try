// specification file for the LinkedList class
#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H
#include <iostream>

template <class T>
class LinkedList {
private:
   struct ListNode {
      T value;              // the value in this node
      struct ListNode* next;     // to point to the next node
   };
   ListNode* head;               // List head pointer

public:
   // constructor
   LinkedList(/* args */) { head == nullptr; }
   // destructor
   ~LinkedList();

   // linked list operations
   void appendNode(T);
   void insertNode(T);
   void deleteNode(T);
   void displayList() const;
};

template <class T>
void LinkedList<T>::appendNode(T newValue) {
   ListNode* newNode; // to point to a new node
   ListNode* nodePtr;   // to move through the list

   // allocate a new node and store newValue there
   newNode = new ListNode;
   newNode->value = newValue;
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

template <class T>
void LinkedList<T>::insertNode(T newValue) {
   ListNode* newNode;          // a new node
   ListNode* nodePtr;         // to traverse the list
   ListNode* previousNode; // the previous node

   // allocate a new node and store newValue there
   newNode = new ListNode;
   newNode->value = newValue;

   if (!head) {
      head = newNode;
      newNode->next = nullptr;
   }
   else {
      // position nodePtr at the head of list
      nodePtr = head;
      previousNode = nullptr; // initialize previousNode to nullptr

      // skip all nodes whose value is less than newValue
      while (nodePtr != nullptr && nodePtr->value < newValue)
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

template <class T>
void LinkedList<T>::deleteNode(T newValue) {
   ListNode* nodePtr;
   ListNode* previousNode;

   if (!head) return;
   if (head->value == newValue) {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else {
      // intiialize nodePtr to head of list
      nodePtr = head;
      while (nodePtr != nullptr && nodePtr->value != newValue)
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

template <class T>
void LinkedList<T>::displayList() const {
   ListNode* nodePtr;
   nodePtr = head;
   while (nodePtr) {
      std::cout << nodePtr->value << std::endl;
      nodePtr = nodePtr->next; // move to the next node.
   }
}

template <class T>
LinkedList<T>::~LinkedList() {
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

#endif // LINKEDLIST_H
