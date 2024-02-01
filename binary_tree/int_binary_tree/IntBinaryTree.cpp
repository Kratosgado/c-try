// impl file for IntBinaryTree
#include "IntBinaryTree.h"
#include <iostream>

using namespace std;

void IntBinaryTree::insertNode(int num) {
   TreeNode* newNode = nullptr;

   // create a new node and store num in it
   newNode = new TreeNode;
   newNode->value = num;
   newNode->left = newNode->right = nullptr;

   insert(root, newNode);
}

void IntBinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode) {
   if (nodePtr == nullptr) nodePtr = newNode;
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode); // search the left branch
   else insert(nodePtr->right, newNode); // search the right branch
}

bool IntBinaryTree::searchNode(int num) {
   TreeNode* nodePtr = root;
   while (nodePtr)
   {
      if (nodePtr->value == num) return true;
      else if (num < nodePtr->value)
         nodePtr = nodePtr->left;
      else nodePtr = nodePtr->right;
   }
   return false;
}

void IntBinaryTree::remove(int num) { deleteNode(num, root); }

void IntBinaryTree::deleteNode(int num, TreeNode*& nodePtr) {
   if (num < nodePtr->value) deleteNode(num, nodePtr->left);
   else if (num > nodePtr->value) deleteNode(num, nodePtr->right);
   else makeDeletion(nodePtr);
}

void IntBinaryTree::makeDeletion(TreeNode*& nodePtr) {
   // define a temporary pointer to use in reattaching the left subtree
   TreeNode* tempNodePtr = nullptr;
   if (nodePtr == nullptr) cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == nullptr) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left; // reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right; // reattach the right child
      delete tempNodePtr;
   }
   // if the node has two children
   else {
      // move one node to the right
      tempNodePtr = nodePtr->right;
      // go to the end left node
      while (tempNodePtr->left)
      {
         tempNodePtr = tempNodePtr->left;
      }
      // reattach the left subtree
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // reattach the right subtree
      nodePtr = nodePtr->right;
      delete tempNodePtr;

   }
}

void IntBinaryTree::displayInOrder(TreeNode* nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

void IntBinaryTree::displayPreOrder(TreeNode* nodePtr) const {
   if (nodePtr) {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);
      displayPreOrder(nodePtr->right);
   }
}

void IntBinaryTree::displayPostOrder(TreeNode* nodePtr) const {
   if (nodePtr) {
      displayPostOrder(nodePtr->left);
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}