// Date: 11/11/2019

#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

void bst_insert(btNode*& bst_root, int insInt)
{
   if(bst_root == nullptr)
   {
      btNode* new_root = new btNode;
      new_root->data = insInt;
      new_root->left = new_root->right = nullptr;
      bst_root = new_root;
      return;
   }

   btNode* nodePtr = bst_root;
   while (nodePtr != nullptr)
   {
      if (nodePtr->data > insInt)
      {
         if(nodePtr->left == nullptr)
         {
            nodePtr->left = new btNode;
            nodePtr->left->data = insInt;
            nodePtr->left->left = nodePtr->left->right = nullptr;
            return;
         }
         else
            nodePtr = nodePtr->left;
      }
      else if(nodePtr->data < insInt)
      {
         if(nodePtr->right == nullptr)
         {

            nodePtr->right = new btNode;
            nodePtr->right->data = insInt;
            nodePtr->right->left = nodePtr->right->right = nullptr;
            return;
         }
         else
            nodePtr = nodePtr->right;
      }
      else
         return;
   }
}

bool bst_remove(btNode*& bst_root, int remInt)
{
   if(bst_root == nullptr)
     return false;

   if(bst_root->data > remInt)
   {
     bst_remove(bst_root->left, remInt);
   }
   else if(bst_root->data < remInt)
   {
      bst_remove(bst_root->right, remInt);
   }
   else
   {
      if(bst_root->left != nullptr && bst_root->right != nullptr)
      {
        bst_remove_max(bst_root->left, bst_root->data);
      }
      else
      {
         btNode* old_bst_root = bst_root;
         if(bst_root->left == nullptr && bst_root->right != nullptr)
         {
            bst_root = bst_root->right;
         }
         else if (bst_root-> left != nullptr && bst_root->right == nullptr)
         {
            bst_root = bst_root->left;
         }
         else
            bst_root = nullptr;

         delete old_bst_root;
      }
      return true;
   }
}

void bst_remove_max(btNode*& bst_root, int& data)
{
   if(bst_root == nullptr)
     return;

   if(bst_root->right == nullptr)
   {
      btNode* deleteNode = bst_root;
      data = bst_root->data;
      bst_root = bst_root->left;
      delete deleteNode;
   }
   else
      bst_remove_max(bst_root->right, data);
}
