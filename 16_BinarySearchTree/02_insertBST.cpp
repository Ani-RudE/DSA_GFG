#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x)
     {
          data = x;
          left = right = NULL;
     }
};

TreeNode* insert(TreeNode* root, int key) {
     TreeNode* newNode=new TreeNode(key);
     TreeNode* parent=NULL;
     TreeNode* curr=root;

     while (curr!=NULL) {
          parent=curr;
          if (curr->data>key) {
               curr=curr->left;
          } else if (curr->data<key) {
               curr=curr->right;
          } else {
               return root;
          }
     }

     if (parent==NULL) {
          return newNode;
     } else if (parent->data>key) {
          parent->left=newNode;
     } else if (parent->data>key) {
          parent->right=newNode;
     }

     return root;
}

void printInorder(TreeNode *root) {
     if (root != NULL)
     {
          printInorder(root->left);
          cout << root->data << " ";
          printInorder(root->right);
     }
}

int main()
{
     TreeNode *root = new TreeNode(15);
     root->left = new TreeNode(5);
     root->right = new TreeNode(20);
     root->left->left = new TreeNode(3);
     root->right->left = new TreeNode(18);
     root->right->left->left = new TreeNode(16);
     root->right->right = new TreeNode(80);
     
     int key=15;
     root=insert(root, key);
     printInorder(root);

     return 0;
}