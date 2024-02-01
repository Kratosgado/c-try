// spec file for IntBinaryTree class
#if !defined(INTBINARYTREE_H)
#define INTBINARYTREE_H

   struct TreeNode
   {
      int value;
      TreeNode* left;
      TreeNode* right;
   };
   
   class IntBinaryTree
{
private:
   TreeNode* root;

   // private member functions
   void insert(TreeNode*&, TreeNode*&);
   // void destroySubTree(TreeNode*);
   void deleteNode(int, TreeNode*&);
   void makeDeletion(TreeNode*&);
   void displayInOrder(TreeNode*) const;
   void displayPreOrder(TreeNode*) const;
   void displayPostOrder(TreeNode*) const;

public:
   IntBinaryTree() { root = nullptr; }
   // ~IntBinaryTree() { destroySubTree(root); }

   // binary tree operations
   void insertNode(int);
   bool searchNode(int);
   void remove(int);
   void displayInOrder() const { displayInOrder(root); }
   void displayPreOrder() const { displayPreOrder(root); }
   void displayPostOrder() const { displayPostOrder(root); }
   };

#endif // INTBINARYTREE_H
